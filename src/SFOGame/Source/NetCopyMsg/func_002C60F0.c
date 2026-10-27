#include "types.h"

typedef struct V4F { float x, y, z, w; } V4F;
typedef struct Payload {
    char s000[0xF0];
    V4F v0F0;
    float f100;
    char pad104[0xC];
    char s110[0x30];
    char s140[0x70];
    char s1B0[0x20];
    float f1D0;
    char pad1D4[0xC];
    char s1E0[4][0x40];
} Payload;

typedef struct Msg {
    void* vtable;
    char pad04[0x20];
    int x24;
    char pad28[8];
    Payload p;
} Msg;

typedef struct Src {
    char pad00[8];
    int x08;
    char pad0C[4];
    Payload p;
} Src;

extern char D_0051EE58[];
extern char D_004DE110[];
extern void cMessage_ctor_cMessageNameR(Msg* m, void* type);
extern void cNpcTransfer_ctor(void*);
extern void cAiTransfer_ctor(void*);
extern void cAiTargetTransfer_ctor(void*);
extern void cPathNavigatorTransfer_ctor(void*);
extern void cPathTransfer_ctor(void*);
extern void cObjectId_ctor_uint(void*, int);
extern void cTargetAwareness_ctor(void*);
extern void cNpcTransfer_opAssign(void*, void*);
extern void cAiTargetTransfer_opAssign(void*, void*);
extern void cPathNavigatorTransfer_opAssign(void*, void*);
extern void cPathTransfer_opAssign(void*, void*);
extern void cTargetAwareness_opAssign(void*, void*);

Msg* cNetCopyMsg_ctor(Msg* m, Src* s) {
    char* p;
    char* q;
    cMessage_ctor_cMessageNameR(m, D_0051EE58);
    p = (char*)&m->p;
    m->vtable = D_004DE110;
    cNpcTransfer_ctor(p);
    cAiTransfer_ctor(p + 0xF0);
    cAiTargetTransfer_ctor(p + 0x110);
    cPathNavigatorTransfer_ctor(p + 0x140);
    cPathTransfer_ctor(p + 0x1B0);
    cObjectId_ctor_uint(p + 0x1D0, -1);
    q = p + 0x1E0;
    do {
        cTargetAwareness_ctor(q);
        q += 0x40;
    } while (q != p + 0x2E0);
    m->x24 = s->x08;
    cNpcTransfer_opAssign(m->p.s000, s->p.s000);
    m->p.v0F0 = s->p.v0F0;
    m->p.f100 = s->p.f100;
    cAiTargetTransfer_opAssign(m->p.s110, s->p.s110);
    cPathNavigatorTransfer_opAssign(m->p.s140, s->p.s140);
    cPathTransfer_opAssign(m->p.s1B0, s->p.s1B0);
    m->p.f1D0 = s->p.f1D0;
    cTargetAwareness_opAssign(m->p.s1E0[0], s->p.s1E0[0]);
    cTargetAwareness_opAssign(m->p.s1E0[1], s->p.s1E0[1]);
    cTargetAwareness_opAssign(m->p.s1E0[2], s->p.s1E0[2]);
    cTargetAwareness_opAssign(m->p.s1E0[3], s->p.s1E0[3]);
    return m;
}
