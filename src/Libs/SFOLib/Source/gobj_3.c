/*
 * Libs/SFOLib/Source/gobj: 1 file, 003CC670
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003CC670 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { void* vt; } TC670;
extern char D_004E0EE0[];
extern void cMessage_dtor(void* self, short del);
extern void operator_delete(void* p);
TC670* cNetSetGobjMsg_dtor(TC670* self, short del)
{
    if (self) {
        self->vt = D_004E0EE0;
        cMessage_dtor(self, 0);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
static inline void merge_flush_func_003CC670(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003CC670 */
