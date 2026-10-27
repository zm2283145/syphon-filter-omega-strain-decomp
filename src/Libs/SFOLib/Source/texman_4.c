/*
 * Libs/SFOLib/Source/texman: 1 file, 003801A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003801A0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"

/* Erase the first list entry whose value equals v. */
typedef struct Node_3801A0 { int pad0; struct Node_3801A0* next; int value; } Node_3801A0;
typedef struct { Node_3801A0* p; } It_3801A0;
typedef struct { unsigned char pad[0x428]; int list; int header; } Obj_3801A0;

extern "C" {
Node_3801A0* details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_10(void* header);
void* std_list_deleter_int_tail(void* list);
void std_list_deleter_int_generic_iterator_ctor_nodebaseP(It_3801A0* out, void* node);
void std_list_deleter_int_erase_listdeleter(It_3801A0* result, void* list, It_3801A0* pos);
}

extern "C" void cTexMan_EraseDeletedTID(Obj_3801A0* o, int v)
{
    It_3801A0 result;
    It_3801A0 pos;
    It_3801A0 end;
    Node_3801A0* n;
    for (n = details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_10(&o->header)->next; (std_list_deleter_int_generic_iterator_ctor_nodebaseP(&end, std_list_deleter_int_tail(&o->list)), n != end.p); n = n->next) {
        if (v == n->value) {
            pos.p = n;
            std_list_deleter_int_erase_listdeleter(&result, &o->list, &pos);
            return;
        }
    }
}
static inline void merge_flush_func_003801A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003801A0 */
