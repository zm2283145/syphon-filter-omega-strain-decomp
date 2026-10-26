#include "types.h"
typedef struct RippleNode_b6 { int p0; struct RippleNode_b6* next; unsigned char pad[0x60 - 8]; float timer; } RippleNode_b6;
typedef struct { int p0; int list; int sentinel; } RippleEmitter_b6;
extern RippleNode_b6* details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_7(int*);
extern int std_list_deleter_tNode_tail(int*);
extern void std_list_deleter_tNode_generic_iterator_ctor_nodebaseP(RippleNode_b6**, int);
extern void std_list_deleter_tNode_erase_listdeleter(RippleNode_b6**, int*, RippleNode_b6**);
static inline float fmax_b6(float a, float b) { float r; asm { max.s r, a, b } return r; }
void WaterFx_AgeRipples(RippleEmitter_b6* e, float dt)
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