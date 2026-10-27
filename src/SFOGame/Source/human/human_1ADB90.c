/*
 * main/human: range (2 files, 001ADB90-001ADBE0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#pragma push
#pragma cplusplus on
#include "trivial_dtor.h"
#pragma pop
#include "types.h"

/* merge_units: begin func_001ADB90 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(cPointer_cSkaNode_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_001ADB90 */

/* merge_units: begin func_001ADBE0 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
#if 0 /* merge_units */
void operator_delete(void* p);
#endif /* merge_units */
#define operator_delete(a0) ((void)operator_delete((a0))) /* merge_units */

void cMessage_dtor(void* m, int f);
extern char D_004DA930[];
}
struct M_1ADBE0 { void* vt; };
struct O_1ADBE0 { char pad[0x5C]; M_1ADBE0 msg; };
static inline void MDtor_1ADBE0(M_1ADBE0* m) { if (m) { m->vt = D_004DA930; cMessage_dtor(m, 0); } }
extern "C" void* cSkaSystem_RequestTransition_dtor(O_1ADBE0* self, short deleteFlag)
{
    if (self) {
        MDtor_1ADBE0(&self->msg);
        if (deleteFlag > 0) operator_delete(self);
    }
    return self;
}
#undef operator_delete /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001ADBE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001ADBE0 */
