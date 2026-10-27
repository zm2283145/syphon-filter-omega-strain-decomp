/*
 * main/human: range (2 files, 001B5190-001B53D0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "vslot_pad.h"

/* library prototypes shared by the blocks below (C linkage) */
int cMemMan_Deallocate();

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
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
extern char D_0049D8D0;
extern char g_TargetVisMgr;
extern unsigned char g_IsMultiplayer;
void Alloc_Lock(int);
void EnableIntc(int);
void cMan_UnDead(void*);
void cTargetManager_RemoveGobj(void*, void*);
void cHuman_SetParticleEffect(Act*, unsigned char, int, float);
void cSKM_GOBJ_Deactivate(Act*, int);
int cNPCInfoObject_ctor(int*);
void cNPCInfoObject_Deactivate(int*, void*);
int cNPCInfoObject_dtor(int*, int);
void cNetHuman_Deactivate(void*);
void cHumanCollisionRoutine_HandleHumanDeactivation(VObj*);
}

extern "C" void cHuman_Deactivate(Act* a, int arg)
{
    int loc;
    VObj* o;
    int i;
    cMan_UnDead(a->a60);
    cTargetManager_RemoveGobj(&g_TargetVisMgr, a);
    for (i = 0; i < 3; i++) cHuman_SetParticleEffect(a, i, 0, 1.0f);
    cSKM_GOBJ_Deactivate(a, arg);
    if (g_IsMultiplayer) {
        cNPCInfoObject_ctor(&loc);
        cNPCInfoObject_Deactivate(&loc, a->a0C);
        if (a->p3584) {
            if (a->Kind() != 3 || (int)a->f40 > 0) cNetHuman_Deactivate(a->p3584);
        }
        cNPCInfoObject_dtor(&loc, -1);
    }
    if (a->w3310) cHumanCollisionRoutine_HandleHumanDeactivation(a->w3310);
    o = a->w3310;
    if (o) {
        if (g_ProfileLockEnabled) Alloc_Lock(9);
        g_ProfileLockDepth++;
        o->~VObj();
        cMemMan_Deallocate(0, o, &D_0049D8D0, 0x456);
        if (g_ProfileLockEnabled) EnableIntc(9);
        g_ProfileLockDepth--;
        a->w3310 = 0;
    }
    o = a->w3314;
    if (o) {
        if (g_ProfileLockEnabled) Alloc_Lock(9);
        g_ProfileLockDepth++;
        o->~VObj();
        cMemMan_Deallocate(0, o, &D_0049D8D0, 0x45B);
        if (g_ProfileLockEnabled) EnableIntc(9);
        g_ProfileLockDepth--;
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
int cNetObj_AddSystem(int, int, char * );
int cHuman_InitializationToDoUponActivation();
int cHuman_SetupCenterOfMassInfo(char * );
int cHuman_SetupSkelBBoxInfo(char * );
int cTargetManager_AddGobj(char *, char * );
int cNetHuman_Activate(int);
int cNetHuman_CreateNetHuman(char * , int);
int NetGetMyClientIndex(int *, int);
int cSKM_GOBJ_Activate(char * , int);
int cNetObj_SetOwner(int, int);
int cNPCInfoObject_SetActive(char *, char * );
#if 0 /* merge_units */
int cNPCInfoObject_dtor(char *, int);
#endif /* merge_units */
#define cNPCInfoObject_dtor(a0, a1) (cNPCInfoObject_dtor((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
int cNPCInfoObject_ctor(char *);
#endif /* merge_units */
#define cNPCInfoObject_ctor(a0) (cNPCInfoObject_ctor((void *)(a0))) /* merge_units */

extern int D_00494178;
extern int D_005721A8;
extern unsigned char D_005721D0;

#pragma opt_common_subs off
static inline int LocalId_53D0(void)
{
    int r;
    int a = D_005721A8; /* read before the flag test: retail loads it ahead of the branch */
    if (g_IsMultiplayer) {
        if (D_00494178 == -1) NetGetMyClientIndex(&D_00494178, a);
        r = D_00494178;
    } else r = 0;
    return r;
}
void cHuman_Activate(char * arg0, int arg1) {
    int sp3C;
    int temp_a0;
    int temp_s1;
    int temp_s1_2;
    int var_a1;
    int var_a1_2;

    cHuman_InitializationToDoUponActivation();
    cSKM_GOBJ_Activate(arg0, arg1);
    cHuman_SetupSkelBBoxInfo(arg0);
    cHuman_SetupCenterOfMassInfo(arg0);
    cTargetManager_AddGobj(&g_TargetVisMgr, arg0);
    if (g_IsMultiplayer != 0) {
        if ((F_(arg0, 0x3584, int) == 0) && (D_005721D0 != 0)) {
            cNetHuman_CreateNetHuman(arg0 + 0xC, F_(arg0, 0x10, int));
            temp_s1 = F_(arg0, 0x10, int);
            var_a1 = LocalId_53D0();
            cNetObj_AddSystem(temp_s1, var_a1, arg0);
        }
        temp_s1_2 = F_(arg0, 0x10, int);
        var_a1_2 = LocalId_53D0();
        cNetObj_SetOwner(temp_s1_2, var_a1_2);
        cNPCInfoObject_ctor(&sp3C);
        cNPCInfoObject_SetActive(&sp3C, arg0 + 0xC);
        F_(arg0, 0x14, signed char) = 1;
        temp_a0 = F_(arg0, 0x3584, int);
        if (temp_a0 != 0) {
            cNetHuman_Activate(temp_a0);
        }
        cNPCInfoObject_dtor(&sp3C, -1);
    }
    F_(arg0, 0x3268, signed char) = 1;
}
#undef cNPCInfoObject_dtor /* merge_units */
#undef cNPCInfoObject_ctor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001B53D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001B53D0 */
