#include "types.h"
typedef struct {
    unsigned char a, b, c;
    int d;
    int e;
    int f;
    int g;
    int h;
} Cfg5270;
extern int NetRegisterMessageStart(void);
extern int Event_UnpackHeader(void* f);
extern int NetMessageField(void* f, void* buf, int size, int count);
extern int NetMsg_RegisterType(void* t, int id, void* fn);
extern char D_0051EE40[];
extern void cNetCalloutMsg_NetReceive(void);
unsigned char cNetCalloutMsg_NetRegister(void)
{
    struct { long long file; Cfg5270 cfg; } L;
    unsigned char ok = 0;
    if (NetRegisterMessageStart() == 0 && Event_UnpackHeader(&L.file) &&
        NetMessageField(&L.file, &L.cfg.a, 1, 1) == 0 &&
        NetMessageField(&L.file, &L.cfg.e, 4, 1) == 0 &&
        NetMessageField(&L.file, &L.cfg.f, 4, 1) == 0 &&
        NetMessageField(&L.file, &L.cfg.h, 4, 1) == 0 &&
        NetMessageField(&L.file, &L.cfg.g, 4, 1) == 0 &&
        NetMessageField(&L.file, &L.cfg.b, 1, 1) == 0 &&
        NetMessageField(&L.file, &L.cfg.c, 1, 1) == 0 &&
        NetMessageField(&L.file, &L.cfg.d, 4, 1) == 0 &&
        NetMsg_RegisterType(D_0051EE40, 2, cNetCalloutMsg_NetReceive) == 0)
        ok = 1;
    return ok;
}