/*
 * main/NetObjectMgr: 2 files, 0042D0E0-0042D110
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0042D0E0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

/* Iterator copy-assignment. */
Word* func_0042D0E0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

/* end(): iterator at the tree header. */
void std_map_cString_cConsCommandPtr_end_void_2(Iter* out, Tree* t) {
    out->p = &t->header;
}

/* begin(): iterator at the leftmost node. */
void std_map_cString_cConsCommandPtr_begin(Iter* out, Tree* t) {
    out->p = t->leftmost;
}
#pragma pop /* merge_units */
/* merge_units: end func_0042D0E0 */

/* merge_units: begin func_0042D110 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "net_transfer_types.h"
#include "network_admission.h"

extern "C" {
extern RbTree D_00582720;
void ObjMap_Find_42EF70(TransferTimerIterator* result, RbTree* tree, const GobjId* id);
#if 0 /* merge_units */
void std_map_cString_cConsCommandPtr_end_void_2(TransferTimerIterator* result, RbTree* tree);
#endif /* merge_units */
#define std_map_cString_cConsCommandPtr_end_void_2(a0, a1) (std_map_cString_cConsCommandPtr_end_void_2((Iter *)(a0), (Tree *)(a1))) /* merge_units */

#if 0 /* merge_units */
void func_0042D0E0(TransferTimerIterator* result, const TransferTimerIterator* source);
#endif /* merge_units */
#define func_0042D0E0(a0, a1) ((void)func_0042D0E0((Word *)(a0), (Word *)(a1))) /* merge_units */

void std_tree_pair_int_value_compare_erase_tree_5(RbTree* tree, TransferTimerIterator* position);
void std_tree_pair_int_value_compare_insert_one_pairR_4(TransferInsertResult* result, RbTree* tree, const TransferTimerValue* value);
void printf(const char* format, ...);
}

/* Remove an existing transfer timer after logging its object ID. */
extern "C" void NetObjectMgr_RemoveTransferTimer(const GobjId* id)
{
    GobjId key;
    TransferTimerIterator end;
    TransferTimerIterator found;
    TransferTimerIterator position;
    TransferTimerIterator rawEnd;
    key.word = id->word;
    ObjMap_Find_42EF70(&found, &D_00582720, &key);
    TransferTimerNode* node = found.node;
    printf("RemoveTransferTimer timer for %.8X\n", id->word);
    std_map_cString_cConsCommandPtr_end_void_2(&rawEnd, &D_00582720);
    func_0042D0E0(&end, &rawEnd);
    if ((node == end.node) ^ 1) {
        position.node = node;
        std_tree_pair_int_value_compare_erase_tree_5(&D_00582720, &position);
    }
}

/* Insert or refresh the object's timer using the same software-clock conversion. */
extern "C" void NetObjectMgr_AddTransferTimer(const GobjId* id)
{
    GobjId key;
    TransferTimerIterator end;
    TransferTimerIterator found;
    TransferTimerIterator rawEnd;
    TransferInsertResult result;
    TransferTimerValue value;
    key.word = id->word;
    ObjMap_Find_42EF70(&found, &D_00582720, &key);
    TransferTimerNode* node = found.node;
    printf("Adding transfer timer for %.8X\n", id->word);
    std_map_cString_cConsCommandPtr_end_void_2(&rawEnd, &D_00582720);
    func_0042D0E0(&end, &rawEnd);
    if (node == end.node) {
        value.id.word = id->word;
        value.deadline = retry_threshold() + 45000;
        std_tree_pair_int_value_compare_insert_one_pairR_4(&result, &D_00582720, &value);
    } else {
        node->deadline = retry_threshold() + 45000;
    }
}
#undef std_map_cString_cConsCommandPtr_end_void_2 /* merge_units */
#undef func_0042D0E0 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0042D110 */
