/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "oauth.h"

AuthResponse *
auth_1_svc(AuthRequest arg1,  struct svc_req *rqstp)
{
	static AuthResponse  result;

	/*
	 * insert server code here
	 */

	return &result;
}

ApproveTokenResponse *
approve_token_1_svc(ApproveTokenRequest arg1,  struct svc_req *rqstp)
{
	static ApproveTokenResponse  result;

	/*
	 * insert server code here
	 */

	return &result;
}

OauthAccessTokenResponse *
oauth_access_token_1_svc(OauthAccessTokenRequest arg1,  struct svc_req *rqstp)
{
	static OauthAccessTokenResponse  result;

	/*
	 * insert server code here
	 */

	return &result;
}

OauthAccessTokenResponse *
oauth_refresh_token_1_svc(OauthRefreshTokenRequest arg1,  struct svc_req *rqstp)
{
	static OauthAccessTokenResponse  result;

	/*
	 * insert server code here
	 */

	return &result;
}

ExecuteActionResponse *
execute_action_1_svc(ExecuteActionRequest arg1,  struct svc_req *rqstp)
{
	static ExecuteActionResponse  result;

	/*
	 * insert server code here
	 */

	return &result;
}
