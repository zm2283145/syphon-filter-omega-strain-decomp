#pragma cplusplus on
/* 48-byte key copies (3 qwords). The two inlines differ only in local order, which
   sets the register assignment: assignment uses the first, the copy after allocation the second. */
static inline void KeyQCopy(void* d, void* s, int n) {
    __int128 t;
    asm {
        .set noreorder
    lp:
        lq t, 0(s)
        addiu d, d, 0x10
        addi n, n, -1
        addiu s, s, 0x10
        bgtz n, lp
        sq t, -0x10(d)
        .set reorder
    }
}
static inline void KeyQCopyNew(void* dd, void* s, int nn) {
    int n = nn; __int128 t; void* d = dd;
    asm {
        .set noreorder
    lp:
        lq t, 0(s)
        addiu d, d, 0x10
        addi n, n, -1
        addiu s, s, 0x10
        bgtz n, lp
        sq t, -0x10(d)
        .set reorder
    }
}
typedef union { char s[48]; __int128 q[3]; } Name;
typedef struct { int pad; Name *p; } Slot;
typedef struct {
    char pad[0x24];
    int a;
    signed char b;
    char pad2[3];
    int c;
    unsigned char d;
    char pad3[3];
    float e;
} Params;
typedef struct {
    char pad0[0xBC];
    Slot s1;
    Slot s3;
    char pad1[0x310 - 0xCC];
    unsigned char k[3];
    char pad2[0x350 - 0x313];
    int a1; signed char b1; char q1[3]; int c1; unsigned char d1; char r1[3]; float e1;
    char pad3[0x388 - 0x364];
    int a3; signed char b3; char q3[3]; int c3; unsigned char d3; char r3[3]; float e3;
} Obj;

#include "alloc_guard.h"
extern "C" void* cMemMan_Allocate(int, int, char*, int);
extern "C" char D_004A0308[];

extern "C" int Secondary_RequestOneShot(Obj *o, Name *src, unsigned char kind, Params *p)
{
    switch (kind) {
    case 1: {
        Slot *s;
        if (o->k[0] != 0x15 && o->k[1] != 0x15 && o->k[2] != 0x15) {
        o->k[2] = 0x15;
        s = &o->s1;
        if (s->p == 0) {
            Name *t;
            {
                AllocGuard g;
                t = (Name *)cMemMan_Allocate(0, 0x30, D_004A0308, 0x569);
            }
            if (t) KeyQCopyNew(t, src, 3);
            s->p = t;
        } else if (s->p->s[0] || src->s[0]) {
            KeyQCopy(s->p, src, 3);
        }
        o->a1 = p->a; o->b1 = p->b; o->c1 = p->c; o->d1 = p->d; o->e1 = p->e;
        return 1;
        }
        return 0;
    }
    case 3: {
        Slot *s;
        if (o->k[0] != 0x16 && o->k[1] != 0x16 && o->k[2] != 0x16) {
        o->k[2] = 0x16;
        s = &o->s3;
        if (s->p == 0) {
            Name *t;
            {
                AllocGuard g;
                t = (Name *)cMemMan_Allocate(0, 0x30, D_004A0308, 0x569);
            }
            if (t) KeyQCopyNew(t, src, 3);
            s->p = t;
        } else if (s->p->s[0] || src->s[0]) {
            KeyQCopy(s->p, src, 3);
        }
        o->a3 = p->a; o->b3 = p->b; o->c3 = p->c; o->d3 = p->d; o->e3 = p->e;
        return 1;
        }
        return 0;
    }
    }
    return 0;
}