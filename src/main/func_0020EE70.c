#include "types.h"
typedef struct { int a; int b; } Desc0020EE70;
typedef struct { int a; int pad[1]; int b[4]; int c; int d; char e; } Proto0020EE70;
extern int NetRegisterMessageStart(void* reg);
extern int Event_UnpackHeader(void* d);
extern int NetMessageField(void* d, void* field, int size, int count);
extern int NetMsg_RegisterType(void* type, int version, void* factory);
extern char D_004F53D0[];
extern void cPlaySoundMsg_NetPlaySoundMsgCallback(void);
unsigned char cPlaySoundMsg_InitNet_void(void* reg)
{
    struct { long long file; Proto0020EE70 p; } L;
    unsigned char ok = 0;
    if (NetRegisterMessageStart(reg) == 0 && Event_UnpackHeader(&L.file) != 0 &&
        NetMessageField(&L.file, &L.p.a, 4, 1) == 0 &&
        NetMessageField(&L.file, &L.p.b, 0x10, 1) == 0 &&
        NetMessageField(&L.file, &L.p.c, 4, 1) == 0 &&
        NetMessageField(&L.file, &L.p.d, 4, 1) == 0 &&
        NetMessageField(&L.file, &L.p.e, 1, 1) == 0 &&
        NetMsg_RegisterType(D_004F53D0, 2, cPlaySoundMsg_NetPlaySoundMsgCallback) == 0)
        ok = 1;
    return ok;
}