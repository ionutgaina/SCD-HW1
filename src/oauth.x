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

struct AuthRequest {
    string user_id<>;
};

struct AuthResponse {
    string token<>;
    StatusCode status;
};

struct ApproveTokenRequest {
    string token<>;
};

struct ApproveTokenResponse {
    string token<>;
	string perms;
    StatusCode status;
};

struct OauthAccessTokenRequest {
	string user_id<>;
	string token<>;
	bool is_refresh_token;
};


struct OauthRefreshTokenRequest {
    string token<>;
};

struct OauthAccessTokenResponse {
    string token<>;
    string refresh_token<>;
    int ttl;
    StatusCode status;
};

struct ExecuteActionRequest {
	string token<>;
	string action<>;
	string resource<>;
};

struct ExecuteActionResponse {
    StatusCode status;
};

program OAUTH_PROG {
    version OAUTH_VERS {
        AuthResponse auth(AuthRequest) = 1;
        ApproveTokenResponse approve_token(ApproveTokenRequest) = 2;
        OauthAccessTokenResponse oauth_access_token(OauthAccessTokenRequest) = 3;
        OauthAccessTokenResponse oauth_refresh_token(OauthRefreshTokenRequest) = 4;
        ExecuteActionResponse execute_action(ExecuteActionRequest) = 5;
    } = 1;
} = 0x11111111;