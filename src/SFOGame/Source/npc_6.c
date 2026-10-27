/*
 * SFOGame/Source/npc: 1 file, 00148600
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00148600 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#include "vslot_pad.h"

/* Global_ResetNpc: rebuild the global's NPC in place (unless it refuses): save its name, label,
 * health, weapon pair, id, team tag and world matrix, destroy it, then run cHuman_ctor_cMatrix_int_charP_int_etc_2 on
 * the same storage with the saved values. */

struct M4u {
    __int128 r0, r1, r2, r3;
    M4u() {}
    M4u(const M4u& s)
    {
        M4u* pd = this;
        __int128 a;
        __int128 b;
        const M4u* ps = &s;
        /* 128-bit two-register lq/sq copy idiom (netCreatePlayer_HandleNetPlayerCreate.c) */
        __asm__ volatile("lq %0, 0x0(%2); lq %1, 0x10(%2); sq %0, 0x0(%3); lq %0, 0x20(%2); sq %1, 0x10(%3); lq %1, 0x30(%2); sq %0, 0x20(%3); sq %1, 0x30(%3)" : "=&r"(a), "=&r"(b) : "r"(ps), "r"(pd) : "memory");
    }
};

class XformObj {
public:
    VPAD32(a) VPAD16(b) VPAD8(c)
    virtual M4u GetMatrix();
};

struct WPair { int a, b; };

class Npc {
public:
    virtual void Destroy(int flag);
    VPAD16(a) VPAD8(b) VPAD4(c)
    virtual int IsLocked();
    char pad4[0xC - 4];
    int id;
    char pad10[0x31F0 - 0x10];
    int tag;
    char pad31F4[0x3264 - 0x31F4];
    char* label;
    char pad3268[0x3318 - 0x3268];
    char name[0x80];
    int health;
    char pad339C[0x33F0 - 0x339C];
    XformObj xform;
    char pad33F4[0x3548 - 0x33F4];
    int x3548;
    char pad354C[0x3588 - 0x354C];
    WPair weap;
};

class GlobalObj {
public:
    VPAD16(a) VPAD1(b)
    virtual void Reset();
    char pad4[0x30 - 4];
    Npc* npc;
};

extern "C" {
extern char D_0049B670[];
void Libc_Strcpy(char* d, const char* s);
int strlen(const char* s);
void* cMemMan_Allocate(int pool, int size, char* file, int line);
void cMemMan_Deallocate(int pool, void* p, char* file, int line);
void* cHuman_ctor_cMatrix_int_charP_int_etc_2(void* self, M4u m, int x, char* name, int health, WPair* weap, unsigned char type, char* label, int* idp, int flag, int tag, void* src);
void Global_ResetNpc(GlobalObj* g);
}

void Global_ResetNpc(GlobalObj* g)
{
    int id;
    WPair weap;
    char name[0x88];
    char* label;
    Npc* n;
    int health;
    int x;
    int len;
    int tag;
    if (g->npc->IsLocked()) return;
    n = g->npc;
    label = 0;
    Libc_Strcpy(name, n->name);
    health = n->health;
    id = g->npc->id;
    weap = n->weap;
    x = n->x3548;
    len = n->label ? strlen(n->label) : 0;
    if (len) {
        {
            AllocGuard ag;
            label = (char*)cMemMan_Allocate(0, len + 1, D_0049B670, 0x1F02);
        }
        Libc_Strcpy(label, n->label);
    }
    {
        XformObj* xo = &n->xform;
        M4u m = xo->GetMatrix();
        g->Reset();
        tag = n->tag;
        n->Destroy(-1);
        if (n) cHuman_ctor_cMatrix_int_charP_int_etc_2(n, m, x, name, health, &weap, 2, label, &id, 0, tag, 0);
    }
    if (label) {
        AllocGuard ag;
        cMemMan_Deallocate(0, label, D_0049B670, 0x1F13);
    }
}
static inline void merge_flush_func_00148600(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00148600 */
