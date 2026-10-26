/*
 * main/targetManager: targetManager.cc (2 files, 0022D4F0-0022D630)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0022D4F0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#include "targetManager_types.h"
typedef struct { void* vt; char p4[0x1C]; void* arr[29]; char p94[0x7C]; char a110[0xC]; char a11C[4]; } M22D4F0;
extern "C" {
void Receiver_Construct(M22D4F0*, void*);
void* Mem_Alloc(int pool, int size, char* file, int line);
void* func_001005E0(void* p, void* ctor, int dtor, int size, int n);
void std_list_deleter_cSafePtr_cGOBJ_ctor(void*);
void cTargetManager_Reset(M22D4F0*);
void std_list_deleter_LosReqElem_ctor(void*);
extern char D_004DB850[];
extern char D_004F77A8[];
TargetSlot* cTargetManager_LosElem_ctor(TargetSlot* self);
}
#pragma push

#pragma opt_strength_reduction off

extern "C" M22D4F0* TargetVisMgr_ctor(M22D4F0* m) {
    int i;
    int n;
    int off;
    void* p;
    Receiver_Construct(m, D_004F77A8);
    m->vt = D_004DB850;
    std_list_deleter_LosReqElem_ctor(m->a110);
    std_list_deleter_cSafePtr_cGOBJ_ctor(m->a11C);
    for (i = 0, off = 0; i < 29; i++, off += 4) {
        n = 29 - i;
        { AllocGuard g; p = Mem_Alloc(0, (n << 4) + 0x10, "targetManager.cc", 0x2B); }
        *(void**)((char*)m + off + 0x20) = func_001005E0(p, (void*)cTargetManager_LosElem_ctor, 0, 0x10, n);
    }
    cTargetManager_Reset(m);
    return m;
}
#pragma pop
#pragma pop /* merge_units */
/* merge_units: end func_0022D4F0 */

/* merge_units: begin func_0022D630 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

/* Constructor: clears the slot. */
TargetSlot* cTargetManager_LosElem_ctor(TargetSlot* self) {
    self->unk4 = 0;
    self->unk0 = 0;
    self->unkC = 0;
    self->unkD = 0;
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_0022D630 */
