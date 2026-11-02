/*
 * SFOGame/Source/human: 3 files, 001B4DE0-001B4EF0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001B4DE0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
extern "C" { void operator_delete(void* p); void __destroy_array(void* p, void* dtor, int size, int n); 
#if 0 /* merge_units */
void cHumanCollisionRoutine_cFinalLedgeSearchInfo_dtor(void);
#endif /* merge_units */
void* cHumanCollisionRoutine_cFinalLedgeSearchInfo_dtor(void* self, short deleteFlag); /* merge_units */

extern char D_004DAD00[];
extern "C" void cHumanCollision_DeltaPosModificationFunction_Floor_Execute();
extern "C" void cHumanCollision_DeltaPosModificationFunction_Ledge_Execute();
extern "C" void cHumanCollision_DeltaPosModificationFunction_Floor_dtor();
extern "C" void cSkaAnimAnchor_cDeltaPosModificationFunction_dtor();
extern "C" void cHumanCollision_DeltaPosModificationFunction_Ledge_dtor();
void * const D_004DA800[4] = { (void*)0x0, (void*)0x0, (void*)cHumanCollision_DeltaPosModificationFunction_Floor_dtor, (void*)cHumanCollision_DeltaPosModificationFunction_Floor_Execute };
void * const D_004DA810[4] = { (void*)0x0, (void*)0x0, (void*)cSkaAnimAnchor_cDeltaPosModificationFunction_dtor, (void*)0x0 };
void * const D_004DA820[4] = { (void*)0x0, (void*)0x0, (void*)cHumanCollision_DeltaPosModificationFunction_Ledge_dtor, (void*)cHumanCollision_DeltaPosModificationFunction_Ledge_Execute };
extern char D_004DA3E0[];
extern char D_004DA380[];
extern char D_004DA330[];
}
struct M_1B4DE0 { void* vt; };
static inline void Vt2_1B4DE0(M_1B4DE0* m, char* a, char* b) { if (m) { m->vt = a; if (m) m->vt = b; } }
struct Inner_1B4DE0 { M_1B4DE0 m; char pad[0x1C]; M_1B4DE0 n; };
static inline void InnerDtor_1B4DE0(Inner_1B4DE0* p) { if (p) { Vt2_1B4DE0(&p->n, ((char*)D_004DA820), ((char*)D_004DA810)); Vt2_1B4DE0(&p->m, ((char*)D_004DA800), ((char*)D_004DA810)); } }
struct O_1B4DE0 { M_1B4DE0 vt; char pad4[0x9C]; M_1B4DE0 mA0; char padA4[0x3E0 - 0xA4]; char arr[0x9E0 - 0x3E0]; Inner_1B4DE0 inner; };
extern "C" void* cHumanCollisionRoutine_dtor(O_1B4DE0* self, short deleteFlag)
{
    if (self) {
        self->vt.vt = D_004DAD00;
        InnerDtor_1B4DE0(&self->inner);
        if (self->arr) __destroy_array(self->arr, (void*)cHumanCollisionRoutine_cFinalLedgeSearchInfo_dtor, 0xA0, 9);
        Vt2_1B4DE0(&self->mA0, D_004DA3E0, D_004DA380);
        if (self) self->vt.vt = D_004DA330;
        if (deleteFlag > 0) operator_delete(self);
    }
    return self;
}
static inline void merge_flush_func_001B4DE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B4DE0 */

/* merge_units: begin func_001B4EF0 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "trivial_dtor.h"
#pragma pop
#include "vslot_pad.h"

#pragma cplusplus on

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(cHumanCollisionRoutine_cFinalLedgeSearchInfo_dtor)
static inline void merge_flush_func_001B4EF0(void) {} /* merge_units */
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
