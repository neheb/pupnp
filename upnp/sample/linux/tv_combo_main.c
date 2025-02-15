/*******************************************************************************
 *
 * Copyright (c) 2000-2003 Intel Corporation
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 * - Neither name of Intel Corporation nor the names of its contributors
 * may be used to endorse or promote products derived from this software
 * without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL INTEL OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ******************************************************************************/

#include "sample_util.h"
#include "tv_ctrlpt.h"
#include "tv_device.h"

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
        char *iface = NULL;
        int rc;
        pthread_t cmdloop_thread;
        int i = 0;
#ifdef _WIN32
#else
        int sig;
        sigset_t sigs_to_catch;
#endif
        int code;
        UpnpLib *p_ctrlpt;
        UpnpLib *p_device;

        SampleUtil_Initialize(linux_print);
        /* Parse options */
        for (i = 1; i < argc; i++) {
                if (strcmp(argv[i], "-i") == 0) {
                        iface = argv[++i];
                } else if (strcmp(argv[i], "-help") == 0) {
                        SampleUtil_Print(
                                "Usage: %s -i interface -help (this message)\n",
                                argv[0]);
                        SampleUtil_Print("\tinterface:     interface address "
                                         "of the control point\n"
                                         "\t\te.g.: eth0\n");
                        return 1;
                }
        }
        /* Start the device. */
        device_main(&p_device, argc, argv, 1);
        /* This is how it used to work before the library became reentrant,
         * so it should still work. */
        p_ctrlpt = p_device;
        /* Start the control point. */
        rc = TvCtrlPointStart(&p_ctrlpt, iface, NULL, 1);
        if (rc != TV_SUCCESS) {
                SampleUtil_Print("Error starting UPnP TV Control Point\n");
                return rc;
        }
        /* start a command loop thread */
        code = pthread_create(
                &cmdloop_thread, NULL, TvCtrlPointCommandLoop, NULL);
        if (code != 0) {
                return UPNP_E_INTERNAL_ERROR;
        }
#ifdef _WIN32
        pthread_join(cmdloop_thread, NULL);
#else
        /* Catch Ctrl-C and properly shutdown */
        sigemptyset(&sigs_to_catch);
        sigaddset(&sigs_to_catch, SIGINT);
        sigwait(&sigs_to_catch, &sig);
        SampleUtil_Print("Shutting down on signal %d...\n", sig);
#endif
        TvDeviceStop(p_device);
        rc = TvCtrlPointStop(p_ctrlpt);

        return rc;
}
