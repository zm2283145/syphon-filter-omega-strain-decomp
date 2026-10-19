/*
 * main/human: range (6 files, 001B5E20-001B5FE0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#pragma push
#pragma cplusplus on
#include "trivial_dtor.h"
#pragma pop
#include "types.h"
#pragma push
#pragma cplusplus on
#include "vtable_chain_dtor.h"
#pragma pop
#include "vslot_pad.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
#include "SFOLobby_helpers.h"
int sprintf(void *, const void *, ...);
int strlen(const char *);
char *strncpy(void *, const void *, int);

/* merge_units: begin func_001B5E20 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(func_001B5E20)
#pragma pop /* merge_units */
/* merge_units: end func_001B5E20 */

/* merge_units: begin func_001B5E70 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor: restore the vtable chain, optionally delete. */
extern "C" void AngleCurve_PreUpdate();
extern "C" void AngleCurve_UpdateRate();
extern "C" void func_001B87E0();
extern "C" void func_001B88A0();
extern "C" void func_001B88B0();
extern "C" void func_001B8AC0();
extern void * const D_004DA7D0[];
extern "C" char D_004DA380[];
extern "C" VtableChainObject* func_001B5E70(VtableChainObject* self,
                                   short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DA7D0);
        if (self)
            self->vtable = D_004DA380;
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DA7D0[12] = { (void*)0x0, (void*)0x0, (void*)func_001B5E70, (void*)func_001B87E0, (void*)func_001B88A0, (void*)func_001B88B0, (void*)AngleCurve_PreUpdate, (void*)func_001B8AC0, (void*)AngleCurve_UpdateRate, (void*)0x0, (void*)0x0, (void*)0x0 };
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001B5E70(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001B5E70 */

/* merge_units: begin func_001B5ED0 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
#if 0 /* merge_units */
void operator_delete(void* p);
#endif /* merge_units */
#define operator_delete(a0) ((void)operator_delete((a0))) /* merge_units */

void func_001BE690(void* p, int f);
}
static inline void D3_1B5ED0(void* p) { if (p) func_001BE690(p, 0); }
static inline void D2_1B5ED0(void* p) { if (p) D3_1B5ED0(p); }
static inline void D1_1B5ED0(void* p) { if (p) D2_1B5ED0(p); }
extern "C" void* func_001B5ED0(void* self, short deleteFlag)
{
    if (self) {
        D1_1B5ED0(self);
        if (deleteFlag > 0) operator_delete(self);
    }
    return self;
}
#undef operator_delete /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001B5ED0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001B5ED0 */

/* merge_units: begin func_001B5F40 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(func_001B5F40)
#pragma pop /* merge_units */
/* merge_units: end func_001B5F40 */

/* merge_units: begin func_001B5F90 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(func_001B5F90)
#pragma pop /* merge_units */
/* merge_units: end func_001B5F90 */

/* merge_units: begin func_001B5FE0 */
#pragma push /* merge_units */
/* Npc_Initialize (0x001B5FE0), mw38 MATCH.
 * Keys: AllocGuard (alloc_guard.h) in the Alloc inline supplies the 3 extra 4-byte stack slots;
 * the Mtx copy is an explicit lq/sq asm block (asm in the function also keeps the null-handle
 * Clear() unfolded = retail b + dead 'li 0xC'); LocalId as 'r = 0; if (net) {...; return id;} return r;';
 * opt_unroll_loops/opt_strength_reduction off. UNDEF __dl__FPv is the usual benign one. */
#pragma cplusplus on
#pragma opt_unroll_loops off
#pragma opt_strength_reduction off
typedef int Q128 __attribute__((mode(TI)));
static inline void QCopy(void* d, const void* s) { Q128 q; __asm__ volatile("lq %0, 0x0(%2)\n sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
struct Mtx { Q128 q[4]; };
struct HObj { int q[3]; int id; };
struct Hd {
    HObj* hp;
    int hid;
    void Set(HObj* o) { hp = o; int d; hid = *(o ? &o->id : (d = -1, &d)); }
    void Clear() { Set(0); }
};
class Vis {
public:
    VPAD16(a) VPAD2(b) VPAD1(c)
    virtual int IsOn();
};
struct Desc { char* name; void* skl; int x8; };
class Sub {
public:
    VPAD32(a) VPAD2(b)
    virtual void Apply(Mtx* m, int f);
};
class Act {
public:
    VPAD8(a) VPAD4(b) VPAD2(c)
    virtual void SetMtx(Mtx* m);
    virtual void SetDesc(Desc* d);
    char p4[0xC - 0x4];
    int wC;
    char p10[0x40 - 0x10];
    float x40;
    char p44[0x58 - 0x44];
    Vis* p58;
    char p5C[0x31F0 - 0x5C];
    int x31F0;
    char p31F4[0x3264 - 0x31F4];
    char* x3264;
    char p3268[0x326B - 0x3268];
    unsigned char b326B;
    char p326C[0x3318 - 0x326C];
    char x3318[0x80];
    int x3398;
    int x339C;
    int x33A0;
    char p33A4[0x33B8 - 0x33A4];
    unsigned char b33B8;
    unsigned char b33B9;
    char p33BA[0x33BC - 0x33BA];
    float x33BC;
    char p33C0[0x33E7 - 0x33C0];
    unsigned char b33E7;
    void* x33E8;
    void* x33EC;
    Sub x33F0;
    char p33F4[0x3450 - 0x33F4];
    int x3450;
    char p3454[0x3458 - 0x3454];
    int x3458;
    char p345C[0x3469 - 0x345C];
    unsigned char b3469;
    unsigned char b346A;
    unsigned char b346B;
    unsigned char b346C;
    unsigned char b346D;
    unsigned char b346E;
    unsigned char b346F;
    unsigned char b3470;
    char p3471[0x3480 - 0x3471];
    Hd h3480;
    unsigned char b3488;
    char p3489[0x34E0 - 0x3489];
    int x34E0;
    int x34E4[12];
    void* x3514[4];
    void* x3524;
    void* x3528;
    int x352C;
    char p3530[0x3538 - 0x3530];
    unsigned char b3538;
    char p3539[0x354C - 0x3539];
    Hd h354C[3];
    char p3564[0x3588 - 0x3564];
    int x3588[2];
};
struct ItemList { char p[0x10]; Act* owner; };
struct Hog { char p[0xA0]; };
struct Skl { char p[0x440]; };
extern "C" {
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
extern char D_0049D8D0[];
extern int D_00494178;
extern int D_005721A8;
extern unsigned char D_005721C0;
extern unsigned char g_IsMultiplayer;
extern Desc* D_004FFBD8;
extern char D_0049E8F0[];
extern char D_0048B2F8[];
extern char D_0049E908[];
extern char D_0049E918[];
extern char D_0049E928[];
extern char D_0049E940[];
extern char D_0055D4F8;
extern char D_004FFB8C;
extern char g_Game;
extern float D_0048A1C8;
extern float D_0048A1D0;
#if 0 /* merge_units */
void Alloc_Lock(int);
#endif /* merge_units */
#define Alloc_Lock(a0) (Alloc_Lock((a0))) /* merge_units */

#if 0 /* merge_units */
void Alloc_Unlock(int);
#endif /* merge_units */
#define Alloc_Unlock(a0) (Alloc_Unlock((a0))) /* merge_units */

void* Mem_Alloc(int, int, char*, int);
void ItemList_Init(void*);
void* Flashlight_Construct(void*, Act*);
void Resource_Construct(Hog*);
void FileMan_Release(Hog*, int);
void Actor_SetHealth(Act*, int, int);
void NetGame_InitLocalSlot(int*, int);
Skl* SklRegistry_Find(char*, char*);
int Archive_Open(char*, char*, int, int);
void Hog_Register(Hog*, char*, int, int);
int FileMan_FindMember(Hog*);
int FileMan_GetSize(Hog*);
void Skeleton_BuildInFrame(Skl*, Hog*, int);
void WeaponInv_Add(void*, int, int, int, int, int);
void WeaponInv_EquipFirst(void*);
void Actor_InitComponents(Act*, unsigned char, int, void*);
void func_00436C00(int*);
void func_00435F30(int*, int*, int);
void func_00434600(int*, int*, int);
void func_00436BA0(int*, int);
int Agent_GetSelected(char*, int);
int AgentData_HasUnlock(int, int);
}
struct HogH {
    Hog h;
    HogH() { Resource_Construct(&h); }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~HogH() { FileMan_Release(&h, -1); }
};
static inline void* Alloc(int size, int line)
{
    AllocGuard g;
    return Mem_Alloc(0, size, D_0049D8D0, line);
}
static inline int LocalId()
{
    int a = D_005721A8;
    int r = 0;
    if (g_IsMultiplayer) {
        if (D_00494178 == -1)
            NetGame_InitLocalSlot(&D_00494178, a);
        return D_00494178;
    }
    return r;
}
static inline int LocalId2()
{
    int a = D_005721A8;
    int r = 0;
    if (g_IsMultiplayer) {
        if (D_00494178 == -1)
            NetGame_InitLocalSlot(&D_00494178, a);
        r = D_00494178;
    }
    return r;
}
static inline bool On(Act* a)
{
    bool on = 0;
    if (a->p58 && a->p58->IsOn()) on = 1;
    return on;
}
extern "C" bool Npc_Initialize(Act* a, Mtx* mtx, char* name, int health, int maxh, int* weap, int s2, unsigned char type, char* label)
{
    Desc* desc = D_004FFBD8;
    char path[0x80];
    HogH hog;
    Mtx m;
    HogH hog2;
    Skl skl;
    Skl* sk;
    {
        ItemList* l = (ItemList*)Alloc(0x14, 0x31A);
        if (l) {
            ItemList_Init(l);
            l->owner = a;
        }
        a->x3528 = l;
    }
    a->b326B = 0;
    if (type == 1 || type == 3) {
        void* f = Alloc(0x1C, 0x31E);
        if (f) f = Flashlight_Construct(f, a);
        a->x33EC = f;
    } else {
        a->x33EC = 0;
    }
    {
        int i;
        for (i = 0; i < 12; i++) a->x34E4[i] = -1;
    }
    a->x34E0 = 0;
    a->b33E7 = 0;
    a->x352C = 0;
    a->b33B8 = 0;
    a->b3470 = 0;
    a->b346F = 0;
    a->b346E = 0;
    a->b3538 = 0;
    a->x33BC = -1.0f;
    a->b33B9 = 0;
    a->b3469 = 0;
    a->b346B = 0;
    a->b346A = 0;
    a->b346C = 0;
    a->h3480.Clear();
    a->b3488 = 0;
    a->b346D = 0;
    {
        int i;
        for (i = 0; i < 3; i++) a->h354C[i].Clear();
    }
    sprintf(path, D_0049E8F0, D_0048B2F8, 1);
    a->x3398 = health;
    Actor_SetHealth(a, health, 0);
    a->x339C = maxh;
    a->x33A0 = maxh;
    {
        int len = label ? strlen(label) : 0;
        if (len) {
            a->x3264 = (char*)Alloc(len + 1, 0x33F);
            String_Copy(a->x3264, label);
        } else {
            a->x3264 = 0;
        }
    }
    if (name) {
        if (g_IsMultiplayer) {
            if (type == 1 && !(g_IsMultiplayer ? D_005721C0 : (unsigned char)1)) {
                switch (LocalId()) {
                case 1: strncpy(a->x3318, D_0049E908, 0x80); break;
                case 2: strncpy(a->x3318, D_0049E918, 0x80); break;
                case 3: strncpy(a->x3318, D_0049E928, 0x80); break;
                default: strncpy(a->x3318, D_0049E918, 0x80); break;
                }
            } else {
                strncpy(a->x3318, name, 0x80);
            }
            sk = SklRegistry_Find(&D_0055D4F8, a->x3318);
            if (!sk) {
                Hog_Register(&hog.h, a->x3318, Archive_Open(&D_004FFB8C, path, 0, 0), 0);
                if ((unsigned char)FileMan_FindMember(&hog.h)) {
                    char err[0x40];
                    sprintf(err, D_0049E940, name);
                    return 0;
                }
                Skeleton_BuildInFrame(&skl, &hog.h, FileMan_GetSize(&hog.h));
                sk = &skl;
            }
        } else {
            strncpy(a->x3318, name, 0x80);
            sk = SklRegistry_Find(&D_0055D4F8, name);
            if (!sk) {
                Hog_Register(&hog.h, name, Archive_Open(&D_004FFB8C, path, 0, 0), 0);
                if ((unsigned char)FileMan_FindMember(&hog.h)) {
                    char err[0x40];
                    sprintf(err, D_0049E940, name);
                    return 0;
                }
                Skeleton_BuildInFrame(&skl, &hog.h, FileMan_GetSize(&hog.h));
                sk = &skl;
            }
        }
    } else {
        sk = 0;
    }
    desc->name = name;
    desc->skl = sk;
    desc->x8 = a->x31F0;
    { Mtx* pm = &m; Q128 a0, a1, a2, a3; __asm__ volatile("lq %0, 0x0(%4)\n lq %1, 0x10(%4)\n sq %0, 0x0(%5)\n lq %0, 0x20(%4)\n sq %1, 0x10(%5)\n lq %1, 0x30(%4)\n sq %0, 0x20(%5)\n sq %1, 0x30(%5)" : "=&r"(a0), "=&r"(a1), "=&r"(a2), "=&r"(a3) : "r"(mtx), "r"(pm) : "memory"); }
    a->SetMtx(&m);
    a->SetDesc(desc);
    {
        int i;
        for (i = 0; i < 2; i++) {
            a->x3588[i] = weap[i];
            if (weap[i] != -1) {
                if (g_IsMultiplayer) {
                    if (!s2)
                        WeaponInv_Add(a->x3524, weap[i], 1, 0, 0, 0);
                    else
                        WeaponInv_Add(a->x3524, weap[i], 1, 0, 0, 1);
                } else {
                    WeaponInv_Add(a->x3524, weap[i], 1, 0, 0, 0);
                }
            }
        }
    }
    WeaponInv_EquipFirst(a->x3524);
    if (!g_IsMultiplayer) {
        Actor_InitComponents(a, type, s2, 0);
    } else {
        if (type != 4) Actor_InitComponents(a, type, s2, 0);
        if (type != 4 && type != 3 && !s2) {
            int loc;
            func_00436C00(&loc);
            { int* w = &a->wC; func_00435F30(&loc, w, LocalId()); }
            if (type == 1) { int* w = &a->wC; func_00434600(&loc, w, LocalId()); }
            func_00436BA0(&loc, -1);
        }
    }
    if (On(a)) {
        int idx;
        int ag;
        if (g_IsMultiplayer) {
            if (On(a))
                idx = ((unsigned)(a->wC & 0x7F000000) >> 24) - 1;
            else
                idx = -1;
        } else {
            idx = 0;
        }
        {
            Vis* p = a->p58;
            int x = p != 0;
            if (x) x = (unsigned char)p->IsOn();
            x = (unsigned char)x;
            ag = x ? Agent_GetSelected(&g_Game, idx) : 0;
        }
        if (ag) {
            if (AgentData_HasUnlock(ag, 3)) {
                int v = (int)((float)a->x33A0 * D_0048A1C8);
                a->x339C = v;
                a->x33A0 = v;
            }
            if (AgentData_HasUnlock(ag, 4)) {
                int h = (int)(a->x40 * D_0048A1D0);
                a->x3398 = h;
                Actor_SetHealth(a, h, 0);
            }
        }
    }
    a->x33F0.Apply(mtx, 0);
    a->x3450 = (int)a->x40;
    a->x3458 = a->x33A0;
    return 1;
}
#undef Alloc_Lock /* merge_units */
#undef Alloc_Unlock /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001B5FE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001B5FE0 */
