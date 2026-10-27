/*
 * SFOGame/Source/WaterFx: 2 files, 002B3EC0-002B3ED0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002B3EC0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Identity cast.
 */

#include "types.h"

void* details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_7(void* self) {
    return self;
}
static inline void merge_flush_func_002B3EC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002B3EC0 */

/* merge_units: begin func_002B3ED0 */
#pragma push /* merge_units */
typedef struct RippleNode_b6 { int p0; struct RippleNode_b6* next; unsigned char pad[0x60 - 8]; float timer; } RippleNode_b6;
typedef struct { int p0; int list; int sentinel; } RippleEmitter_b6;
#if 0 /* merge_units */
extern RippleNode_b6* details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_7(int*);
#endif /* merge_units */
#define details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_7(a0) ((RippleNode_b6 *)details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_7((void *)(a0))) /* merge_units */

extern int std_list_deleter_tNode_tail(int*);
extern void std_list_deleter_tNode_generic_iterator_ctor_nodebaseP(RippleNode_b6**, int);
extern void std_list_deleter_tNode_erase_listdeleter(RippleNode_b6**, int*, RippleNode_b6**);
static inline float fmax_b6(float a, float b) { float r; asm { max.s r, a, b } return r; }
void cWake_NextFrame_float(RippleEmitter_b6* e, float dt)
{
    RippleNode_b6* n = details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_7(&e->sentinel)->next;
    RippleNode_b6* ret[1];
    RippleNode_b6* it[1];
    RippleNode_b6* end[1];
    while (std_list_deleter_tNode_generic_iterator_ctor_nodebaseP(end, std_list_deleter_tNode_tail(&e->list)), n != end[0]) {
        n->timer = fmax_b6(0.0f, n->timer - dt);
        if (n->timer == 0.0f) {
            RippleNode_b6* cur = n;
            n = n->next;
            it[0] = cur;
            std_list_deleter_tNode_erase_listdeleter(ret, &e->list, it);
        } else {
            n = n->next;
        }
    }
}
#undef details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_7 /* merge_units */
static inline void merge_flush_func_002B3ED0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002B3ED0 */
