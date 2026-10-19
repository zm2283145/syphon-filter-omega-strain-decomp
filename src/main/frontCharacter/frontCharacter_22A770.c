/*
 * main/frontCharacter: 2 files, 0022A770-0022A7B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0022A770 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_0022A770(PtrVec* a, PtrVec* b) {
    if (a != b) {
        int t;
        int* p;
        t = a->unk0;
        a->unk0 = b->unk0;
        b->unk0 = t;
        p = a->data;
        a->data = b->data;
        b->data = p;
        t = a->count;
        a->count = b->count;
        b->count = t;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0022A770 */

/* merge_units: begin func_0022A7B0 */
#pragma push /* merge_units */
extern void GObj_GetID();
extern void func_0012ECF0();
extern void func_0012ED00();
extern void func_0012ED10();
extern void func_0012ED20();
extern void func_0012ED30();
extern void func_0012ED40();
extern void func_0012ED50();
extern void func_001383D0();
extern void TargetVis_HandleResult();
extern void Receiver_GetScriptTypeKey();
extern void Receiver_ScriptDispatch();
extern void * const D_004DB850[];
extern void func_00177B80(void* p, int flag);
extern void func_0022A840(void* p, int flag);
extern void Receiver_Destruct(void* self, int flag);
extern void operator_delete(void* p);
typedef struct { void* vt; } S_D170;
S_D170* TargetVisMgr_dtor(S_D170* self, short flag)
{
    if (self) {
        void* m;
        self->vt = ((char*)D_004DB850);
        m = (char*)self + 0x11C;
        if (m)
            func_00177B80(m, 0);
        m = (char*)self + 0x110;
        if (m)
            func_0022A840(m, 0);
        Receiver_Destruct(self, 0);
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DB850[16] = { (void*)0x0, (void*)0x0, (void*)TargetVisMgr_dtor, (void*)TargetVis_HandleResult, (void*)GObj_GetID, (void*)func_0012ECF0, (void*)func_001383D0, (void*)func_0012ED00, (void*)func_0012ED10, (void*)func_0012ED20, (void*)func_0012ED30, (void*)func_0012ED40, (void*)func_0012ED50, (void*)Receiver_GetScriptTypeKey, (void*)Receiver_ScriptDispatch, (void*)0x0 };
#pragma pop /* merge_units */
/* merge_units: end func_0022A7B0 */
