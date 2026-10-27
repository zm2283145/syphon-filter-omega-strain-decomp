/*
 * main/human: range (2 files, 001B4970-001B4B10)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
int cMemMan_Deallocate();

/* merge_units: begin func_001B4970 */
#pragma push /* merge_units */
#pragma cplusplus on
class VObj { public: virtual ~VObj(); };
extern "C" {
typedef struct {
    char pad0[0xC]; char a0C[0x60 - 0xC]; char a60[0x3310 - 0x60];
    VObj* w3310; VObj* w3314;
} Act;
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
extern char D_0049D8D0;
extern char g_TargetVisMgr;
void Alloc_Lock(int);
void EnableIntc(int);
void cMan_UnDead(void*);
void cTargetManager_RemoveGobj(void*, void*);
void cSKM_GOBJ_NetDeactivate(void*);
void cNPCInfoObject_ctor(int*);
void cNPCInfoObject_Deactivate(int*, void*);
void cNPCInfoObject_dtor(int*, int);
void cHumanCollisionRoutine_HandleHumanDeactivation(VObj*);
}

extern "C" void cHuman_NetDeactivate(Act* a)
{
    int loc;
    VObj* o;
    cMan_UnDead(a->a60);
    cTargetManager_RemoveGobj(&g_TargetVisMgr, a);
    cSKM_GOBJ_NetDeactivate(a);
    cNPCInfoObject_ctor(&loc);
    cNPCInfoObject_Deactivate(&loc, a->a0C);
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
    cNPCInfoObject_dtor(&loc, -1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001B4970(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001B4970 */

/* merge_units: begin func_001B4B10 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" { void operator_delete(void* p); void cMessage_dtor(void* m, int f); void __destroy_array(void* p, void* dtor, int size, int n);
void cIkTargetWithSplinedTransition_dtor(void); void cSkaAnimDataIterator_dtor(void); void func_001B4C70(void);
extern char D_004DACF0[];
extern char D_004DA930[];
extern char D_004DA440[];
extern char D_004DA350[];
extern "C" void cIkRoutine_dtor_void();
void * const D_004DA830[4] = { (void*)0x0, (void*)0x0, (void*)cIkRoutine_dtor_void, (void*)0x0 };
}
struct M_1B4B10 { void* vt; };
static inline void Msg_1B4B10(M_1B4B10* m) { if (m) { m->vt = D_004DA930; cMessage_dtor(m, 0); } }
static inline void B2_1B4B10(M_1B4B10* m) { if (m) m->vt = D_004DA350; }
static inline void D2_1B4B10(M_1B4B10* m) { if (m) { m->vt = D_004DA440; B2_1B4B10(m); } }
static inline void Arr_1B4B10(void* p, void* dtor, int size, int n) { if (p) __destroy_array(p, dtor, size, n); }
struct O_1B4B10 { M_1B4B10 vt; char pad4[0x10]; char a14[0xE0 - 0x14]; char aE0[0x160 - 0xE0]; M_1B4B10 m160; char pad164[0x230 - 0x164];
  M_1B4B10 m230; char pad234[0x32C - 0x234]; M_1B4B10 m32C; char pad330[0x364 - 0x330]; M_1B4B10 m364; char pad368[0x4A0 - 0x368]; char a4A0[0x380]; };
extern "C" void* cHumanIkRoutine_dtor(O_1B4B10* self, short deleteFlag)
{
    if (self) {
        self->vt.vt = D_004DACF0;
        if (self->a4A0) Arr_1B4B10(self->a4A0, (void*)cIkTargetWithSplinedTransition_dtor, 0x1C0, 2);
        Msg_1B4B10(&self->m364);
        Msg_1B4B10(&self->m32C);
        D2_1B4B10(&self->m230);
        D2_1B4B10(&self->m160);
        __destroy_array(self->aE0, (void*)cSkaAnimDataIterator_dtor, 0x30, 2);
        if (self->a14) Arr_1B4B10(self->a14, (void*)func_001B4C70, 8, 0x19);
        if (self) self->vt.vt = ((char*)D_004DA830);
        if (deleteFlag > 0) operator_delete(self);
    }
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001B4B10(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001B4B10 */
