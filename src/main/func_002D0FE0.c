#include "types.h"
/* Loads the saved settings block field by field, then registers the net message type. */
extern int NetRegisterMessageStart(void);
extern int cMessage_RegisterFields(void* f);
extern int NetMessageField(void* f, void* buf, int size, int count);
extern int NetRegisterMessage(void* t, int id, void* fn);
extern char D_0051F060[];
extern void cNetGeneratorCreateMsg_GeneratorCreateCallback(void);
unsigned char cNetGeneratorCreateMsg_InitNet(void)
{
    struct { long long file; int a, b, c; float d[3]; float e[3]; int f, g; } L;
    int err; unsigned char ok = 0; err = NetRegisterMessageStart();
    if (err == 0 && cMessage_RegisterFields(&L.file) && err == 0 &&
        NetMessageField(&L.file, &L.a, 4, 1) == 0 &&
        NetMessageField(&L.file, &L.b, 4, 1) == 0 &&
        NetMessageField(&L.file, &L.c, 4, 1) == 0 &&
        NetMessageField(&L.file, L.d, 12, 3) == 0 &&
        NetMessageField(&L.file, L.e, 12, 3) == 0 &&
        NetMessageField(&L.file, &L.f, 4, 1) == 0 &&
        NetMessageField(&L.file, &L.g, 4, 1) == 0 &&
        NetRegisterMessage(D_0051F060, 2, cNetGeneratorCreateMsg_GeneratorCreateCallback) == 0)
        ok = 1;
    return ok;
}
