/*
 * main/human: range (2 files, 001B5190-001B53D0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "vslot_pad.h"

/* library prototypes shared by the blocks below (C linkage) */
int Mem_Free();

/* merge_units: begin func_001B5190 */
#pragma push /* merge_units */
#pragma cplusplus on
class VObj { public: virtual ~VObj(); };
class Act {
public:
    VPAD32(a) VPAD32(b)
    virtual unsigned char Kind();
    char pad4[0xC - 0x4];
    char a0C[0x40 - 0xC];
    float f40;
    char pad44[0x60 - 0x44];
    char a60[0x3310 - 0x60];
    VObj* w3310;
    VObj* w3314;
    char pad3318[0x3584 - 0x3318];
    void* p3584;
};
extern "C" {
extern unsigned char D_00533880;
extern int D_00533888;
extern char D_0049D8D0;
extern char g_TargetVisMgr;
extern unsigned char D_005721C8;
void Alloc_Lock(int);
void Alloc_Unlock(int);
void func_0038CBF0(void*);
void TargetVis_Unregister(void*, void*);
void Actor_ShockReaction(Act*, unsigned char, int, float);
void func_003928D0(Act*, int);
int func_00436C00(int*);
void func_00433CE0(int*, void*);
int func_00436BA0(int*, int);
void func_002D2110(void*);
void ActorPhys_ReleaseWaterEffect(VObj*);
}

extern "C" void Npc_Deactivate(Act* a, int arg)
{
    int loc;
    VObj* o;
    int i;
    func_0038CBF0(a->a60);
    TargetVis_Unregister(&g_TargetVisMgr, a);
    for (i = 0; i < 3; i++) Actor_ShockReaction(a, i, 0, 1.0f);
    func_003928D0(a, arg);
    if (D_005721C8) {
        func_00436C00(&loc);
        func_00433CE0(&loc, a->a0C);
        if (a->p3584) {
            if (a->Kind() != 3 || (int)a->f40 > 0) func_002D2110(a->p3584);
        }
        func_00436BA0(&loc, -1);
    }
    if (a->w3310) ActorPhys_ReleaseWaterEffect(a->w3310);
    o = a->w3310;
    if (o) {
        if (D_00533880) Alloc_Lock(9);
        D_00533888++;
        o->~VObj();
        Mem_Free(0, o, &D_0049D8D0, 0x456);
        if (D_00533880) Alloc_Unlock(9);
        D_00533888--;
        a->w3310 = 0;
    }
    o = a->w3314;
    if (o) {
        if (D_00533880) Alloc_Lock(9);
        D_00533888++;
        o->~VObj();
        Mem_Free(0, o, &D_0049D8D0, 0x45B);
        if (D_00533880) Alloc_Unlock(9);
        D_00533888--;
        a->w3314 = 0;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001B5190(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001B5190 */

/* merge_units: begin func_001B53D0 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int NetMap_BindReceiver(int, int, char * );
int Npc_CreatePhysical();
int Human_ApplyCentroidWeights(char * );
int Human_ApplyBoundSpheres(char * );
int TargetVis_Register(char *, char * );
int func_002D1D80(int);
int func_002D1FF0(char * , int);
int NetGame_InitLocalSlot(int *, int);
int ActorModel_Activate(char * , int);
int func_003FB4B0(int, int);
int func_004341F0(char *, char * );
#if 0 /* merge_units */
int func_00436BA0(char *, int);
#endif /* merge_units */
#define func_00436BA0(a0, a1) (func_00436BA0((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
int func_00436C00(char *);
#endif /* merge_units */
#define func_00436C00(a0) (func_00436C00((void *)(a0))) /* merge_units */

extern int D_00494178;
extern int D_005721A8;
extern unsigned char D_005721D0;

#pragma opt_common_subs off
static inline int LocalId_53D0(void)
{
    int r;
    int a = D_005721A8; /* read before the flag test: retail loads it ahead of the branch */
    if (D_005721C8) {
        if (D_00494178 == -1) NetGame_InitLocalSlot(&D_00494178, a);
        r = D_00494178;
    } else r = 0;
    return r;
}
void Npc_Activate(char * arg0, int arg1) {
    int sp3C;
    int temp_a0;
    int temp_s1;
    int temp_s1_2;
    int var_a1;
    int var_a1_2;

    Npc_CreatePhysical();
    ActorModel_Activate(arg0, arg1);
    Human_ApplyBoundSpheres(arg0);
    Human_ApplyCentroidWeights(arg0);
    TargetVis_Register(&g_TargetVisMgr, arg0);
    if (D_005721C8 != 0) {
        if ((F_(arg0, 0x3584, int) == 0) && (D_005721D0 != 0)) {
            func_002D1FF0(arg0 + 0xC, F_(arg0, 0x10, int));
            temp_s1 = F_(arg0, 0x10, int);
            var_a1 = LocalId_53D0();
            NetMap_BindReceiver(temp_s1, var_a1, arg0);
        }
        temp_s1_2 = F_(arg0, 0x10, int);
        var_a1_2 = LocalId_53D0();
        func_003FB4B0(temp_s1_2, var_a1_2);
        func_00436C00(&sp3C);
        func_004341F0(&sp3C, arg0 + 0xC);
        F_(arg0, 0x14, signed char) = 1;
        temp_a0 = F_(arg0, 0x3584, int);
        if (temp_a0 != 0) {
            func_002D1D80(temp_a0);
        }
        func_00436BA0(&sp3C, -1);
    }
    F_(arg0, 0x3268, signed char) = 1;
}
#undef func_00436BA0 /* merge_units */
#undef func_00436C00 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001B53D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001B53D0 */
