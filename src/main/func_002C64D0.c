#include "types.h"
extern int NetRegisterMessageStart(void);
extern int Event_UnpackHeader(void* f);
extern int NetMessageField(void* f, void* buf, int size, int count);
extern int NetMsg_RegisterType(void* t, int id, void* fn);
extern char D_0051EE60[];
extern void cNetCreateBlastMsg_NetReceive(void);
unsigned char cNetCreateBlastMsg_NetRegister(void)
{
    struct { long long file; int v[7]; } L;
    unsigned char ok = 0;
    if (NetRegisterMessageStart() == 0 && Event_UnpackHeader(&L.file) &&
        NetMessageField(&L.file, &L.v[0], 4, 1) == 0 &&
        NetMessageField(&L.file, &L.v[1], 4, 1) == 0 &&
        NetMessageField(&L.file, &L.v[2], 4, 1) == 0 &&
        NetMessageField(&L.file, &L.v[3], 4, 1) == 0 &&
        NetMessageField(&L.file, &L.v[4], 4, 1) == 0 &&
        NetMessageField(&L.file, &L.v[5], 4, 1) == 0 &&
        NetMessageField(&L.file, &L.v[6], 4, 1) == 0 &&
        NetMsg_RegisterType(D_0051EE60, 2, cNetCreateBlastMsg_NetReceive) == 0)
        ok = 1;
    return ok;
}