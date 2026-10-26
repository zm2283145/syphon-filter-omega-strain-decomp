/*
 * main/human: range (2 files, 001B4C70-001B4D50)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int Mem_Free();

/* merge_units: begin func_001B4C70 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
void operator_delete(void* p);
}
struct O_1B4C70 { int vt; void* buf; };
extern "C" void* func_001B4C70(O_1B4C70* self, short deleteFlag)
{
    if (self) {
        void* b = self->buf;
        if (b) {
            {
                AllocGuard guard;
                Mem_Free(0, b, "humanIk.hh", 0x55C);
            }
            self->buf = 0;
        }
        if (deleteFlag > 0) operator_delete(self);
    }
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001B4C70(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001B4C70 */

/* merge_units: begin func_001B4D50 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
extern char D_004DA410[];
extern char D_004DA3B0[];
extern char D_004DA440[];
extern char D_004DA350[];
}
struct M_1B4D50 { void* vt; };
static inline void B1_1B4D50(M_1B4D50* m) { if (m) m->vt = D_004DA3B0; }
static inline void D1_1B4D50(M_1B4D50* m) { if (m) { m->vt = D_004DA410; B1_1B4D50(m); } }
static inline void B2_1B4D50(M_1B4D50* m) { if (m) m->vt = D_004DA350; }
static inline void D2_1B4D50(M_1B4D50* m) { if (m) { m->vt = D_004DA440; B2_1B4D50(m); } }
struct O_1B4D50 { char pad[0x30]; M_1B4D50 a; char pad34[0x100 - 0x34]; M_1B4D50 b; };
extern "C" void* cIkTargetWithSplinedTransition_dtor(O_1B4D50* self, short deleteFlag)
{
    if (self) {
        D1_1B4D50(&self->b);
        D2_1B4D50(&self->a);
        if (deleteFlag > 0) operator_delete(self);
    }
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001B4D50(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001B4D50 */
