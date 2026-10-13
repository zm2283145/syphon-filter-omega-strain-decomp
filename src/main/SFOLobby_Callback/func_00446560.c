#include "SFOLobby.h"

/* Reply to a pending inbox entry of type 1 (func_00450F30): accepted or denied. */
typedef struct {
    char messageId[0x18];
    int statusCode;                 /* MediusRequestAccepted or MediusRequestDenied */
    char sessionKey[0x14];
    int requestId;                  /* entry->id */
    int f34;
} Msg_00446560;
typedef struct { char pad[8]; int id; } Arg_00446560;
extern void* memset(void* p, int c, int n);
extern char* String_Copy(char* dst, const char* src);
extern char* strncpy(char* dst, const char* src, int n);
extern int func_0046A690(Msg_00446560* m);
extern void SFOLobby_SetError(SFOLobby* self, int err, const char* file, int line);

int func_00446560(SFOLobby* self, Arg_00446560* arg, int ok)
{
    Msg_00446560 m;
    memset(&m, 0, sizeof(m));
    String_Copy(m.messageId, "1");
    strncpy(m.sessionKey, self->sessionKey, 0x11);
    m.requestId = arg->id;
    m.f34 = 1;
    m.statusCode = ok ? MediusRequestAccepted : MediusRequestDenied;
    if (func_0046A690(&m)) {
        SFOLobby_SetError(self, 1, "SFOLobby_Callback.cc", 2084);
        return 0;
    }
    SFOLobby_SetError(self, 0, "SFOLobby_Callback.cc", 2088);
    return 1;
}
