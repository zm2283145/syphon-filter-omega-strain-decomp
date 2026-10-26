#include "types.h"
typedef struct { char d[0x2E0]; } Save5AC0;
extern void cNetworkTransferNpc_ctor_void(void* buf);
extern int NetRegisterMessageStart(void);
extern int Event_UnpackHeader(void* f);
extern int NetMessageField(void* f, void* buf, int size, int count);
extern int NetMsg_RegisterType(void* t, int id, void* fn);
extern char D_0051EE50[];
extern void cNetCopyMsg_NetReceive(void);
unsigned char cNetCopyMsg_NetRegister(void)
{
    struct { long long file; long long version; Save5AC0 buf; } L;
    int err;
    unsigned char ok;
    Save5AC0* p;
    ok = 0;
    p = &L.buf;
    cNetworkTransferNpc_ctor_void(p);
    err = NetRegisterMessageStart();
    if (err == 0 && Event_UnpackHeader(&L.file) && err == 0 &&
        NetMessageField(&L.file, &L.version, 4, 1) == 0 &&
        NetMessageField(&L.file, p, 0x2E0, 1) == 0 &&
        NetMsg_RegisterType(D_0051EE50, 2, cNetCopyMsg_NetReceive) == 0)
        ok = 1;
    return ok;
}