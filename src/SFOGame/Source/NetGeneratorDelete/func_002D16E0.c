#include "types.h"
extern int NetRegisterMessageStart(void);
extern int cMessage_RegisterFields(void* f);
extern int NetMessageField(void* f, void* buf, int size, int count);
extern int NetRegisterMessage(void* t, int id, void* fn);
extern char D_0051F070[];
extern void cNetGeneratorDeleteMsg_GeneratorDeleteCallback(void);
unsigned char cNetGeneratorDeleteMsg_InitNet(void)
{
    struct { long long file; int a; int b; } L;
    int err;
    unsigned char ok;
    ok = 0;
    err = NetRegisterMessageStart();
    if (err == 0 && cMessage_RegisterFields(&L.file) && err == 0 &&
        NetMessageField(&L.file, &L.a, 4, 1) == 0 &&
        NetMessageField(&L.file, &L.b, 4, 1) == 0 &&
        NetRegisterMessage(D_0051F070, 2, cNetGeneratorDeleteMsg_GeneratorDeleteCallback) == 0)
        ok = 1;
    return ok;
}