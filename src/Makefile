# Parameters

CLIENT = oauth_client
SERVER = oauth_server

SOURCES_CLNT.cpp =
SOURCES_CLNT.h = client.h
SOURCES_SVC.cpp =
SOURCES_SVC.h = server.h
SOURCES.x = oauth.x

TARGETS_SVC.cpp = oauth_svc.cpp oauth_server.cpp oauth_xdr.cpp
TARGETS_CLNT.cpp = oauth_clnt.cpp oauth_client.cpp oauth_xdr.cpp
TARGETS = oauth.h oauth_xdr.cpp oauth_clnt.cpp oauth_svc.cpp oauth_client.cpp oauth_server.cpp

OBJECTS_CLNT = $(SOURCES_CLNT.cpp:.cpp=.o) $(TARGETS_CLNT.cpp:.cpp=.o)
OBJECTS_SVC = $(SOURCES_SVC.cpp:.cpp=.o) $(TARGETS_SVC.cpp:.cpp=.o)


# Compiler flags 

CXX = g++
CXXFLAGS += -g -I/usr/include/tirpc 
LDFLAGS += -lnsl -ltirpc

# Targets 

all: $(CLIENT) $(SERVER)

$(OBJECTS_CLNT): $(SOURCES_CLNT.cpp) $(SOURCES_CLNT.h) $(TARGETS_CLNT.cpp)

$(OBJECTS_SVC): $(SOURCES_SVC.cpp) $(SOURCES_SVC.h) $(TARGETS_SVC.cpp)

$(CLIENT): $(OBJECTS_CLNT)
	$(CXX) $(CXXFLAGS) -o $(CLIENT) $(OBJECTS_CLNT) $(LDFLAGS)

$(SERVER): $(OBJECTS_SVC)
	$(CXX) $(CXXFLAGS) -o $(SERVER) $(OBJECTS_SVC) $(LDFLAGS)

clean:
	$(RM) core *.o *.out $(CLIENT) $(SERVER)
