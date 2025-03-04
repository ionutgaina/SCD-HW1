/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "oauth.h"

bool_t
xdr_StatusCode (XDR *xdrs, StatusCode *objp)
{
	register int32_t *buf;

	 if (!xdr_enum (xdrs, (enum_t *) objp))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_AuthRequest (XDR *xdrs, AuthRequest *objp)
{
	register int32_t *buf;

	 if (!xdr_string (xdrs, &objp->user_id, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_AuthResponse (XDR *xdrs, AuthResponse *objp)
{
	register int32_t *buf;

	 if (!xdr_string (xdrs, &objp->token, ~0))
		 return FALSE;
	 if (!xdr_StatusCode (xdrs, &objp->status))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_ApproveTokenRequest (XDR *xdrs, ApproveTokenRequest *objp)
{
	register int32_t *buf;

	 if (!xdr_string (xdrs, &objp->token, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_ApproveTokenResponse (XDR *xdrs, ApproveTokenResponse *objp)
{
	register int32_t *buf;

	 if (!xdr_string (xdrs, &objp->token, ~0))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->perms, ~0))
		 return FALSE;
	 if (!xdr_StatusCode (xdrs, &objp->status))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_OauthAccessTokenRequest (XDR *xdrs, OauthAccessTokenRequest *objp)
{
	register int32_t *buf;

	 if (!xdr_string (xdrs, &objp->user_id, ~0))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->token, ~0))
		 return FALSE;
	 if (!xdr_bool (xdrs, &objp->is_refresh_token))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_OauthRefreshTokenRequest (XDR *xdrs, OauthRefreshTokenRequest *objp)
{
	register int32_t *buf;

	 if (!xdr_string (xdrs, &objp->token, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_OauthAccessTokenResponse (XDR *xdrs, OauthAccessTokenResponse *objp)
{
	register int32_t *buf;

	 if (!xdr_string (xdrs, &objp->token, ~0))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->refresh_token, ~0))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->ttl))
		 return FALSE;
	 if (!xdr_StatusCode (xdrs, &objp->status))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_ExecuteActionRequest (XDR *xdrs, ExecuteActionRequest *objp)
{
	register int32_t *buf;

	 if (!xdr_string (xdrs, &objp->token, ~0))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->action, ~0))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->resource, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_ExecuteActionResponse (XDR *xdrs, ExecuteActionResponse *objp)
{
	register int32_t *buf;

	 if (!xdr_StatusCode (xdrs, &objp->status))
		 return FALSE;
	return TRUE;
}
