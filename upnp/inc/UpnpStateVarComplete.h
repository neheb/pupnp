#ifndef UPNPSTATEVARCOMPLETE_H
#define UPNPSTATEVARCOMPLETE_H

/*!
 * \file
 *
 * \brief Header file for UpnpStateVarComplete methods.
 *
 * Do not edit this file, it is automatically generated. Please look at
 * generator.c.
 *
 * \author Marcelo Roberto Jimenez
 */
#include <stdlib.h> /* for size_t */

#include "UpnpGlobal.h" /* for UPNP_EXPORT_SPEC */

#include "UpnpString.h"
#include "ixml.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*!
 * UpnpStateVarComplete
 */
typedef struct s_UpnpStateVarComplete UpnpStateVarComplete;

/*! Constructor */
UPNP_EXPORT_SPEC UpnpStateVarComplete *UpnpStateVarComplete_new();
/*! Destructor */
UPNP_EXPORT_SPEC void UpnpStateVarComplete_delete(UpnpStateVarComplete *p);
/*! Copy Constructor */
UPNP_EXPORT_SPEC UpnpStateVarComplete *UpnpStateVarComplete_dup(
	const UpnpStateVarComplete *p);
/*! Assignment operator */
UPNP_EXPORT_SPEC int UpnpStateVarComplete_assign(
	UpnpStateVarComplete *p, const UpnpStateVarComplete *q);

/*! UpnpStateVarComplete_get_ErrCode */
UPNP_EXPORT_SPEC int UpnpStateVarComplete_get_ErrCode(const UpnpStateVarComplete *p);
/*! UpnpStateVarComplete_set_ErrCode */
UPNP_EXPORT_SPEC int UpnpStateVarComplete_set_ErrCode(
	UpnpStateVarComplete *p, int n);

/*! UpnpStateVarComplete_get_CtrlUrl */
UPNP_EXPORT_SPEC const UpnpString *UpnpStateVarComplete_get_CtrlUrl(
	const UpnpStateVarComplete *p);
/*! UpnpStateVarComplete_set_CtrlUrl */
UPNP_EXPORT_SPEC int UpnpStateVarComplete_set_CtrlUrl(
	UpnpStateVarComplete *p, const UpnpString *s);
/*! UpnpStateVarComplete_get_CtrlUrl_Length */
UPNP_EXPORT_SPEC size_t UpnpStateVarComplete_get_CtrlUrl_Length(
	const UpnpStateVarComplete *p);
/*! UpnpStateVarComplete_get_CtrlUrl_cstr */
UPNP_EXPORT_SPEC const char *UpnpStateVarComplete_get_CtrlUrl_cstr(
	const UpnpStateVarComplete *p);
/*! UpnpStateVarComplete_strcpy_CtrlUrl */
UPNP_EXPORT_SPEC int UpnpStateVarComplete_strcpy_CtrlUrl(
	UpnpStateVarComplete *p, const char *s);
/*! UpnpStateVarComplete_strncpy_CtrlUrl */
UPNP_EXPORT_SPEC int UpnpStateVarComplete_strncpy_CtrlUrl(
	UpnpStateVarComplete *p, const char *s, size_t n);
/*! UpnpStateVarComplete_clear_CtrlUrl */
UPNP_EXPORT_SPEC void UpnpStateVarComplete_clear_CtrlUrl(UpnpStateVarComplete *p);

/*! UpnpStateVarComplete_get_StateVarName */
UPNP_EXPORT_SPEC const UpnpString *UpnpStateVarComplete_get_StateVarName(
	const UpnpStateVarComplete *p);
/*! UpnpStateVarComplete_set_StateVarName */
UPNP_EXPORT_SPEC int UpnpStateVarComplete_set_StateVarName(
	UpnpStateVarComplete *p, const UpnpString *s);
/*! UpnpStateVarComplete_get_StateVarName_Length */
UPNP_EXPORT_SPEC size_t UpnpStateVarComplete_get_StateVarName_Length(
	const UpnpStateVarComplete *p);
/*! UpnpStateVarComplete_get_StateVarName_cstr */
UPNP_EXPORT_SPEC const char *UpnpStateVarComplete_get_StateVarName_cstr(
	const UpnpStateVarComplete *p);
/*! UpnpStateVarComplete_strcpy_StateVarName */
UPNP_EXPORT_SPEC int UpnpStateVarComplete_strcpy_StateVarName(
	UpnpStateVarComplete *p, const char *s);
/*! UpnpStateVarComplete_strncpy_StateVarName */
UPNP_EXPORT_SPEC int UpnpStateVarComplete_strncpy_StateVarName(
	UpnpStateVarComplete *p, const char *s, size_t n);
/*! UpnpStateVarComplete_clear_StateVarName */
UPNP_EXPORT_SPEC void UpnpStateVarComplete_clear_StateVarName(
	UpnpStateVarComplete *p);

/*! UpnpStateVarComplete_get_CurrentVal */
UPNP_EXPORT_SPEC const DOMString UpnpStateVarComplete_get_CurrentVal(
	const UpnpStateVarComplete *p);
/*! UpnpStateVarComplete_set_CurrentVal */
UPNP_EXPORT_SPEC int UpnpStateVarComplete_set_CurrentVal(
	UpnpStateVarComplete *p, const DOMString s);
/*! UpnpStateVarComplete_get_CurrentVal_cstr */
UPNP_EXPORT_SPEC const char *UpnpStateVarComplete_get_CurrentVal_cstr(
	const UpnpStateVarComplete *p);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* UPNPSTATEVARCOMPLETE_H */
