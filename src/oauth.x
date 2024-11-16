enum StatusCode {
    SUCCESS = 0,
    USER_NOT_FOUND = 1,
    REQUEST_DENIED = 2,
    PERMISSION_DENIED = 3,
    TOKEN_EXPIRED = 4,
    RESOURCE_NOT_FOUND = 5,
    OPERATION_NOT_PERMITTED = 6,
    PERMISSION_GRANTED = 7
};

struct AuthRequest {
    string user_id<>;
}

struct AuthResponse {
    string token<>;
    StatusCode status;
}

struct ApproveTokenRequest {
    string token<>;
}

struct ApproveTokenResponse {
    string token<>;
	int perms;
    StatusCode status;
}

struct OauthAccessTokenRequest {
	string client_id<>;
	string auth_token<>;
	bool is_refresh_token;
	int perms;
}


struct OauthRefreshTokenRequest {
    string token<>;
}

struct OauthAccessTokenResponse {
    string token<>;
    string refresh_token<>;
    int ttl;
    StatusCode status;
}

struct ExecuteActionRequest {
	string token<>;
	string action<>;
	string resource<>;
}

struct ExecuteActionResponse {

    StatusCode status;
}

program OAUTH_PROG {
    version OAUTH_VERS {
        AuthResponse auth(AuthRequest) = 1;
        ApproveTokenResponse approve_token(ApproveTokenRequest) = 2;
        OauthAccessTokenResponse oauth_access_token(OauthAccessTokenRequest) = 3;
        OauthAccessTokenResponse oauth_refresh_token(OauthRefreshTokenRequest) = 4;
        ExecuteActionResponse execute_action(ExecuteActionRequest) = 5;
    } = 1;
} = 0x11111111;