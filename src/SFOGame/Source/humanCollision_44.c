/*
 * SFOGame/Source/humanCollision: 2 files, 001EFA40-001EFB30
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001EFA40 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "clear_buffer_dtor.h"
extern "C" { char D_004A0528[] = "allocator.hh"; }
DEFINE_CLEAR_BUFFER_DTOR(std_vector_deleter_cCollisionEdge_dtor, D_004A0528)
static inline void merge_flush_func_001EFA40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001EFA40 */

/* merge_units: begin func_001EFB30 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { char pad[0x38]; float v; } EFT_Tri;
extern "C" bool cHumanCollisionEdgeCollector_ValidateEdge(void* a, void* b, EFT_Tri* t) {
    bool r = true;
    if (t->v < 0.5f) r = false;
    return r;
}
static inline void merge_flush_func_001EFB30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001EFB30 */
