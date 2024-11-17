/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "oauth.h"
#include "client.h"


void
oauth_prog_1(char *host)
{
	CLIENT *clnt;
	AuthResponse  *result_1;
	AuthRequest auth_1_arg1;
	ApproveTokenResponse  *result_2;
	ApproveTokenRequest approve_token_1_arg1;
	OauthAccessTokenResponse  *result_3;
	OauthAccessTokenRequest oauth_access_token_1_arg1;
	OauthAccessTokenResponse  *result_4;
	OauthRefreshTokenRequest oauth_refresh_token_1_arg1;
	ExecuteActionResponse  *result_5;
	ExecuteActionRequest execute_action_1_arg1;

#ifndef	DEBUG
	clnt = clnt_create (host, OAUTH_PROG, OAUTH_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	result_1 = auth_1(auth_1_arg1, clnt);
	if (result_1 == (AuthResponse *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_2 = approve_token_1(approve_token_1_arg1, clnt);
	if (result_2 == (ApproveTokenResponse *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_3 = oauth_access_token_1(oauth_access_token_1_arg1, clnt);
	if (result_3 == (OauthAccessTokenResponse *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_4 = oauth_refresh_token_1(oauth_refresh_token_1_arg1, clnt);
	if (result_4 == (OauthAccessTokenResponse *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_5 = execute_action_1(execute_action_1_arg1, clnt);
	if (result_5 == (ExecuteActionResponse *) NULL) {
		clnt_perror (clnt, "call failed");
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	oauth_prog_1 (host);
exit (0);
}
