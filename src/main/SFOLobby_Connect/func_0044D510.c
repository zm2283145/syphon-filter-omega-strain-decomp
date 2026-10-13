#include "SFOLobby.h"
typedef struct { char messageId[0x15]; char sessionKey[0x13]; int f28; unsigned char passwordLen; char password[0x20]; char pad[3]; } R44D;
extern void LobbyArray_Clear(LobbyArray*);
extern int SFOLobby_ConnectAuth(SFOLobby*);
extern int func_0044CBE0(SFOLobby*);
extern int func_004688D8(char*);
extern void SFOLobby_SetError(SFOLobby*, int, char*, int);
extern char D_004C0E80[];           /* "SFOLobby_Connect.cc" */
extern char D_004C0E78[];           /* "1" */
extern void* memset(void*, int, int);
extern void String_Copy(char*, char*);
extern char* strncpy(char*, const char*, int);
extern void* memcpy(void*, const void*, int);
extern void func_004691D8(R44D*);
extern void SFOLobby_RequestMyIp(SFOLobby*);
extern int func_0044D3D0(SFOLobby*);
/* Authentication sequence: connect to the auth server, run the reply350 request,
 * send the session key, send the password (a placeholder when none is set), fetch
 * the own IP and finish with func_0044D3D0. */
int SFOLobby_Authenticate(SFOLobby* o) {
    R44D rec;
    LobbyArray_Clear(&o->accountCache);
    LobbyArray_Clear(&o->pool118);
    if (!SFOLobby_ConnectAuth(o)) return 0;
    if (!func_0044CBE0(o)) return 0;
    o->requestResult = func_004688D8(o->sessionKey);
    if (o->requestResult) {
        SFOLobby_SetError(o, 0x13, D_004C0E80, 0x25);
        return 0;
    }
    if (!o->useDnas || o->passwordLen == 0x20) {
        memset(&rec, 0, 0x50);
        String_Copy(rec.messageId, D_004C0E78);
        strncpy(rec.sessionKey, o->sessionKey, 0x11);
        rec.f28 = 0;
        if (!o->passwordLen) {
            o->passwordLen = 0x20;
            String_Copy(o->password, "*******************************");
        }
        rec.passwordLen = o->passwordLen;
        memcpy(rec.password, o->password, 0x20);
        func_004691D8(&rec);
    }
    SFOLobby_RequestMyIp(o);
    if (!func_0044D3D0(o)) return 0;
    return 1;
}
