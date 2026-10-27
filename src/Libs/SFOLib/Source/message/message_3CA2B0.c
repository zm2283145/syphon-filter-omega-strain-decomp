/*
 * main/message: 3 files, 003CA2B0-003CA360
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003CA2B0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* details_compressed_pair_imp_cAllocator_node_compressed_pair_number_second_void_9(char* self) {
    return self + 4;
}

Map* std_tree_pair_int_value_compare_cAllocator_pair_ctor_valuecompareR_cAllocatorR(Map* m, unsigned char* cmp) {
    m->count = 0;
    m->head = 0;
    m->cmp = *cmp;
    m->hp = &m->head;
    return m;
}

List* std_list_deleter_tQueuedMessage_ctor(List* l) {
    l->count = 0;
    l->first = l->last = &l->first;
    return l;
}
#pragma pop /* merge_units */
/* merge_units: end func_003CA2B0 */

/* merge_units: begin func_003CA300 */
#pragma push /* merge_units */
extern void std_list_deleter_tQueuedMessage_dtor(void* self, short del);
extern void operator_delete(void* p);
void* std_list_tQueuedMessage_dtor(void* self, short del)
{
    if (self) {
        if (self)
            std_list_deleter_tQueuedMessage_dtor(self, 0);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_003CA300 */

/* merge_units: begin func_003CA360 */
#pragma push /* merge_units */
extern void std_list_deleter_tQueuedMessage_begin(int* out, void* self);
extern void std_list_deleter_tQueuedMessage_end(int* out, void* self);
extern void std_list_deleter_tQueuedMessage_erase(int* out, void* self, int* first, int* last);
void* std_list_imp_tQueuedMessage_dtor(void* self, short del)
{
    if (self) {
        if (self) {
            int r;
            int first;
            int last;
            std_list_deleter_tQueuedMessage_begin(&first, self);
            std_list_deleter_tQueuedMessage_end(&last, self);
            std_list_deleter_tQueuedMessage_erase(&r, self, &first, &last);
        }
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_003CA360 */
