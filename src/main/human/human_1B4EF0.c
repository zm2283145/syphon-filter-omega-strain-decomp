/*
 * main/human: range (2 files, 001B4EF0-001B4F40)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#pragma push
#pragma cplusplus on
#include "trivial_dtor.h"
#pragma pop
#include "types.h"
#include "vslot_pad.h"

/* merge_units: begin func_001B4EF0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(cHumanCollisionRoutine_cFinalLedgeSearchInfo_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_001B4EF0 */

/* merge_units: begin func_001B4F40 */
#pragma push /* merge_units */
#pragma cplusplus on
class Vis {
public:
    VPAD16(a) VPAD2(b) VPAD1(c)
    virtual int IsOn();
    VPAD8(d) VPAD4(e)
    virtual unsigned char Kind();
};
struct Act {
    char pad0[0xC];
    int wC;
    int w10;
    char pad14[0x2C - 0x14];
    unsigned char b2C;
    unsigned char b2D;
    unsigned char b2E;
    char pad2F[0x58 - 0x2F];
    Vis* p58;
    char pad5C[0x3268 - 0x5C];
    unsigned char b3268;
    char pad3269[0x3584 - 0x3269];
    void* p3584;
};
extern "C" {
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
extern char D_0049D8D0[];
extern int D_00494178;
extern char g_TargetVisMgr;
extern int D_005721A8;
extern unsigned char g_IsMultiplayer;
void Alloc_Lock(int);
void EnableIntc(int);
void* cMemMan_Allocate(int, int, char*, int);
void* cNetNPC_ctor(void*, void*, Act*);
void cHuman_InitializationToDoUponActivation(Act*);
void cHuman_CreateGobjController(Act*, int, int, void*);
void cSKM_GOBJ_NetActivate(Act*);
void cHuman_SetupSkelBBoxInfo(Act*);
void cHuman_SetupCenterOfMassInfo(Act*);
void cTargetManager_AddGobj(char*, Act*);
int cNetObj_GetOwner(int);
void NetGetMyClientIndex(int*, int);
void cNetObj_AddSystem(int, int, Act*);
void cNPCInfoObject_ctor(int*);
void cNPCInfoObject_SetActive(int*, int*);
void cNPCInfoObject_dtor(int*, int);
}
static inline bool Ready(Act* a)
{
    return a->b2D && a->b2C && !a->b2E;
}
static inline int LocalId()
{
    int a = D_005721A8;
    if (g_IsMultiplayer) {
        if (D_00494178 == -1)
            NetGetMyClientIndex(&D_00494178, a);
        return D_00494178;
    }
    return 0;
}
static inline int Fix(int i)
{
    if (i == -1) return LocalId();
    return i;
}
extern "C" void cHuman_NetActivate(Act* a)
{
    int loc;
    int idx;
    if (Ready(a)) return;
    cHuman_InitializationToDoUponActivation(a);
    {
        bool on = 0;
        if (a->p58 && a->p58->IsOn()) on = 1;
        if (!on) {
            Vis* p = a->p58;
            if (!p || (p && p->Kind() != 2)) {
                void* m;
                if (g_ProfileLockEnabled) Alloc_Lock(9);
                g_ProfileLockDepth++;
                m = cMemMan_Allocate(0, 0x220, D_0049D8D0, 0x4BA);
                if (g_ProfileLockEnabled) EnableIntc(9);
                g_ProfileLockDepth--;
                if (m) m = cNetNPC_ctor(m, a->p3584 ? a->p3584 : 0, a);
                cHuman_CreateGobjController(a, 4, 0, m);
            }
        }
    }
    cSKM_GOBJ_NetActivate(a);
    cHuman_SetupSkelBBoxInfo(a);
    cHuman_SetupCenterOfMassInfo(a);
    cTargetManager_AddGobj(&g_TargetVisMgr, a);
    {
        int w;
        idx = cNetObj_GetOwner(a->wC);
        w = a->w10;
        idx = Fix(idx);
        cNetObj_AddSystem(w, idx, a);
    }
    a->b3268 = 1;
    cNPCInfoObject_ctor(&loc);
    cNPCInfoObject_SetActive(&loc, &a->wC);
    cNPCInfoObject_dtor(&loc, -1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001B4F40(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001B4F40 */
