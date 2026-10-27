/*
 * SFOGame/Source/human: 1 file, 001B4DE0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001B4DE0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
extern "C" { void operator_delete(void* p); void __destroy_array(void* p, void* dtor, int size, int n); void cHumanCollisionRoutine_cFinalLedgeSearchInfo_dtor(void);
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
