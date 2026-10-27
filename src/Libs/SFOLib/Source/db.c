/*
 * Libs/SFOLib/Source/db: 2 files, 003CC0F0-003CC1D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003CC0F0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
void cMemMan_Deallocate(int pool, void* p, char* file, int line);
void operator_delete(void* p);
}
typedef struct { unsigned char owns; char pad[3]; int len; void* buf; } S_CC0F0;
extern "C" S_CC0F0* cDB_dtor(S_CC0F0* self, short flag)
{
    if (self) {
        if (self->owns) {
            void* b = self->buf;
            {
                AllocGuard g;
                cMemMan_Deallocate(0, b, "db.cc", 0x29);
            }
            self->buf = 0;
            self->len = 0;
        }
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}
static inline void merge_flush_func_003CC0F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003CC0F0 */

/* merge_units: begin func_003CC1D0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose04_types.h"

Unk3CC1D0* cDB_ctor(Unk3CC1D0* self) {
    self->unk08 = 0;
    self->unk04 = 0;
    self->unk00 = 0;
    return self;
}
static inline void merge_flush_func_003CC1D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003CC1D0 */
