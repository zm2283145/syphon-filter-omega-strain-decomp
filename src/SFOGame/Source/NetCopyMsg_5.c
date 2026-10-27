/*
 * SFOGame/Source/NetCopyMsg: 2 files, 002C60F0-002C6240
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002C60F0 */
#pragma push /* merge_units */
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
static inline void merge_flush_func_002C60F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002C60F0 */

/* merge_units: begin func_002C6240 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
extern "C" {
void* cMemMan_Allocate(int pool, int size, char* file, int line);
extern char D_004DFD80[];
extern char D_004DE130[];
}
union V4_E100 { struct { float x, y, z, w; } f; struct { char c[16]; } s; };
union V2_6250 { struct { float x, y; } f; struct { char c[8]; } s; };
struct Msg2530 { void* vtable; int a, b, c, d, e, f, g; char h; char p1[3]; int i0; int i1; float x, y, z; int i2; int i3; };
extern "C" Msg2530* cNetCreateBlastMsg_Clone(Msg2530* src)
{
    Msg2530* p;
    {
        AllocGuard guard;
        p = (Msg2530*)cMemMan_Allocate(0, 0x40, "NetCreateBlastMsg.hh", 0x24);
    }
    if (p) {
        p->vtable = D_004DFD80;
        p->a = src->a;
        p->b = src->b;
        p->c = src->c;
        p->d = src->d;
        p->e = src->e;
        p->f = src->f;
        p->g = src->g;
        p->h = src->h;
        p->vtable = D_004DE130;
        p->i0 = src->i0;
        p->i1 = src->i1;
        p->x = src->x;
        p->y = src->y;
        p->z = src->z;
        p->i2 = src->i2;
        p->i3 = src->i3;
    }
    return p;
}
static inline void merge_flush_func_002C6240(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002C6240 */
