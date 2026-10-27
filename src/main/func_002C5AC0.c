#include "types.h"
typedef struct { char d[0x2E0]; } Save5AC0;
extern void cNetworkTransferNpc_ctor_void(void* buf);
extern int NetRegisterMessageStart(void);
extern int cMessage_RegisterFields(void* f);
extern int NetMessageField(void* f, void* buf, int size, int count);
extern int NetRegisterMessage(void* t, int id, void* fn);
extern char D_0051EE50[];
extern void cNetCopyMsg_CopyMsgCallback(void);
unsigned char cNetCopyMsg_InitNet(void)
{
    struct { long long file; long long version; Save5AC0 buf; } L;
    int err;
    unsigned char ok;
    Save5AC0* p;
    ok = 0;
    p = &L.buf;
    cNetworkTransferNpc_ctor_void(p);
    err = NetRegisterMessageStart();
    if (err == 0 && cMessage_RegisterFields(&L.file) && err == 0 &&
        NetMessageField(&L.file, &L.version, 4, 1) == 0 &&
        NetMessageField(&L.file, p, 0x2E0, 1) == 0 &&
        NetRegisterMessage(D_0051EE50, 2, cNetCopyMsg_CopyMsgCallback) == 0)
        ok = 1;
    return ok;
}