/*
 * SFOGame/Source/taser: 2 files, 00262D60-00262D90
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00262D60 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

Word* std_list_deleter_TaserPulse_generic_iterator_ctor(Word* self, int value) {
    self->value = value;
    return self;
}

void* std_list_deleter_TaserPulse_tail(char* self) {
    return self + 4;
}

void* details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_6(void* self) {
    return self;
}
static inline void merge_flush_func_00262D60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00262D60 */

/* merge_units: begin taser_262D90 */
#pragma push /* merge_units */
typedef struct { char pad[8]; unsigned char state; } Obj262D;
extern void cAirTaser_UpdateShot(Obj262D* s);
extern void cAirTaser_UpdateShock(Obj262D* s);
extern void cAirTaser_UpdateRetract(Obj262D* s);
void cAirTaser_NextFrame(Obj262D* s) {
    switch (s->state) {
    case 1: cAirTaser_UpdateShot(s); break;
    case 2: cAirTaser_UpdateShock(s); break;
    case 3: cAirTaser_UpdateRetract(s); break;
    }
}
static inline void merge_flush_taser_262D90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end taser_262D90 */
