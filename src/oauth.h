/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _OAUTH_H_RPCGEN
#define _OAUTH_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


enum StatusCode {
    OK_ = 0,
    PERMISSION_GRANTED_ = 1,
    PERMISSION_DENIED_ = 2,
    USER_NOT_FOUND_ = 3,
    REQUEST_DENIED_ = 4,
    TOKEN_EXPIRED_ = 5,
    RESOURCE_NOT_FOUND_ = 6,
    OPERATION_NOT_PERMITTED_ = 7,
};
typedef enum StatusCode StatusCode;

struct AuthRequest {
	char *user_id;
};
typedef struct AuthRequest AuthRequest;

struct AuthResponse {
	char *token;
	StatusCode status;
};
typedef struct AuthResponse AuthResponse;

struct ApproveTokenRequest {
	char *token;
};
typedef struct ApproveTokenRequest ApproveTokenRequest;

struct ApproveTokenResponse {
	char *token;
	char *perms;
	StatusCode status;
};
typedef struct ApproveTokenResponse ApproveTokenResponse;

struct OauthAccessTokenRequest {
	char *user_id;
	char *token;
	bool_t is_refresh_token;
};
typedef struct OauthAccessTokenRequest OauthAccessTokenRequest;

struct OauthRefreshTokenRequest {
	char *token;
};
typedef struct OauthRefreshTokenRequest OauthRefreshTokenRequest;

struct OauthAccessTokenResponse {
	char *token;
	char *refresh_token;
	int ttl;
	StatusCode status;
};
typedef struct OauthAccessTokenResponse OauthAccessTokenResponse;

struct ExecuteActionRequest {
	char *token;
	char *action;
	char *resource;
};
typedef struct ExecuteActionRequest ExecuteActionRequest;

struct ExecuteActionResponse {
	StatusCode status;
};
typedef struct ExecuteActionResponse ExecuteActionResponse;

#define OAUTH_PROG 0x11111111
#define OAUTH_VERS 1

#if defined(__STDC__) || defined(__cplusplus)
#define auth 1
extern  AuthResponse * auth_1(AuthRequest , CLIENT *);
extern  AuthResponse * auth_1_svc(AuthRequest , struct svc_req *);
#define approve_token 2
extern  ApproveTokenResponse * approve_token_1(ApproveTokenRequest , CLIENT *);
extern  ApproveTokenResponse * approve_token_1_svc(ApproveTokenRequest , struct svc_req *);
#define oauth_access_token 3
extern  OauthAccessTokenResponse * oauth_access_token_1(OauthAccessTokenRequest , CLIENT *);
extern  OauthAccessTokenResponse * oauth_access_token_1_svc(OauthAccessTokenRequest , struct svc_req *);
#define oauth_refresh_token 4
extern  OauthAccessTokenResponse * oauth_refresh_token_1(OauthRefreshTokenRequest , CLIENT *);
extern  OauthAccessTokenResponse * oauth_refresh_token_1_svc(OauthRefreshTokenRequest , struct svc_req *);
#define execute_action 5
extern  ExecuteActionResponse * execute_action_1(ExecuteActionRequest , CLIENT *);
extern  ExecuteActionResponse * execute_action_1_svc(ExecuteActionRequest , struct svc_req *);
extern int oauth_prog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define auth 1
extern  AuthResponse * auth_1();
extern  AuthResponse * auth_1_svc();
#define approve_token 2
extern  ApproveTokenResponse * approve_token_1();
extern  ApproveTokenResponse * approve_token_1_svc();
#define oauth_access_token 3
extern  OauthAccessTokenResponse * oauth_access_token_1();
extern  OauthAccessTokenResponse * oauth_access_token_1_svc();
#define oauth_refresh_token 4
extern  OauthAccessTokenResponse * oauth_refresh_token_1();
extern  OauthAccessTokenResponse * oauth_refresh_token_1_svc();
#define execute_action 5
extern  ExecuteActionResponse * execute_action_1();
extern  ExecuteActionResponse * execute_action_1_svc();
extern int oauth_prog_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_StatusCode (XDR *, StatusCode*);
extern  bool_t xdr_AuthRequest (XDR *, AuthRequest*);
extern  bool_t xdr_AuthResponse (XDR *, AuthResponse*);
extern  bool_t xdr_ApproveTokenRequest (XDR *, ApproveTokenRequest*);
extern  bool_t xdr_ApproveTokenResponse (XDR *, ApproveTokenResponse*);
extern  bool_t xdr_OauthAccessTokenRequest (XDR *, OauthAccessTokenRequest*);
extern  bool_t xdr_OauthRefreshTokenRequest (XDR *, OauthRefreshTokenRequest*);
extern  bool_t xdr_OauthAccessTokenResponse (XDR *, OauthAccessTokenResponse*);
extern  bool_t xdr_ExecuteActionRequest (XDR *, ExecuteActionRequest*);
extern  bool_t xdr_ExecuteActionResponse (XDR *, ExecuteActionResponse*);

#else /* K&R C */
extern bool_t xdr_StatusCode ();
extern bool_t xdr_AuthRequest ();
extern bool_t xdr_AuthResponse ();
extern bool_t xdr_ApproveTokenRequest ();
extern bool_t xdr_ApproveTokenResponse ();
extern bool_t xdr_OauthAccessTokenRequest ();
extern bool_t xdr_OauthRefreshTokenRequest ();
extern bool_t xdr_OauthAccessTokenResponse ();
extern bool_t xdr_ExecuteActionRequest ();
extern bool_t xdr_ExecuteActionResponse ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_OAUTH_H_RPCGEN */
