/*
 * main/human: range (3 files, 00189E80-00189F40)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#pragma push
#pragma cplusplus on
#include "vtable_base_dtor.h"
#pragma pop
#include "types.h"

/* merge_units: begin func_00189E80 */
#pragma push /* merge_units */
#pragma cplusplus on

DEFINE_VTABLE_BASE_DTOR(cCharEventMsg_dtor, D_004DA950, cMessage_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_00189E80 */

/* merge_units: begin func_00189EE0 */
#pragma push /* merge_units */
#pragma cplusplus on

DEFINE_VTABLE_BASE_DTOR(cNotifyCheckpointMsg_dtor, D_004DB8B0, cMessage_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_00189EE0 */

/* merge_units: begin func_00189F40 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
void __destroy_array(void* p, void* dtor, int size, int n);
void func_0018A210(void);
#if 0 /* merge_units */
void operator_delete(void* p);
#endif /* merge_units */
#define operator_delete(a0) ((void)operator_delete((a0))) /* merge_units */

void func_001BE5A0(void* p, int f);
}
struct In3_189F40 { int x; };
static inline void D3_189F40(void* p) { if (p) func_001BE5A0(p, 0); }
static inline void D2_189F40(void* p) { if (p) D3_189F40(p); }
static inline void D1_189F40(void* p) { if (p) D2_189F40(p); }
struct O_189F40 { int vt; char arr[0x38]; char m[4]; };
extern "C" void* cSkaAnimCheckpoints_dtor(O_189F40* self, short deleteFlag)
{
    if (self) {
        D1_189F40(self->m);
        if (self->arr) __destroy_array(self->arr, (void*)func_0018A210, 8, 7);
        if (deleteFlag > 0) operator_delete(self);
    }
    return self;
}
#undef operator_delete /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00189F40(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00189F40 */
