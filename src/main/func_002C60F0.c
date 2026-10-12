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
extern void Event_Construct(Msg* m, void* type);
extern void func_0015AD10(void*);
extern void func_0015ACD0(void*);
extern void func_0015ACC0(void*);
extern void func_0015ACB0(void*);
extern void func_0015ACA0(void*);
extern void func_0015AC90(void*, int);
extern void func_0015AC70(void*);
extern void func_002C5F20(void*, void*);
extern void func_002C5EE0(void*, void*);
extern void func_002C5E50(void*, void*);
extern void func_002C5E20(void*, void*);
extern void func_002C5D90(void*, void*);

Msg* func_002C60F0(Msg* m, Src* s) {
    char* p;
    char* q;
    Event_Construct(m, D_0051EE58);
    p = (char*)&m->p;
    m->vtable = D_004DE110;
    func_0015AD10(p);
    func_0015ACD0(p + 0xF0);
    func_0015ACC0(p + 0x110);
    func_0015ACB0(p + 0x140);
    func_0015ACA0(p + 0x1B0);
    func_0015AC90(p + 0x1D0, -1);
    q = p + 0x1E0;
    do {
        func_0015AC70(q);
        q += 0x40;
    } while (q != p + 0x2E0);
    m->x24 = s->x08;
    func_002C5F20(m->p.s000, s->p.s000);
    m->p.v0F0 = s->p.v0F0;
    m->p.f100 = s->p.f100;
    func_002C5EE0(m->p.s110, s->p.s110);
    func_002C5E50(m->p.s140, s->p.s140);
    func_002C5E20(m->p.s1B0, s->p.s1B0);
    m->p.f1D0 = s->p.f1D0;
    func_002C5D90(m->p.s1E0[0], s->p.s1E0[0]);
    func_002C5D90(m->p.s1E0[1], s->p.s1E0[1]);
    func_002C5D90(m->p.s1E0[2], s->p.s1E0[2]);
    func_002C5D90(m->p.s1E0[3], s->p.s1E0[3]);
    return m;
}
