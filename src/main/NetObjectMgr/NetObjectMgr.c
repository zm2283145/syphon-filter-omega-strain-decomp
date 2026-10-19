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
void func_0042D0F0(Iter* out, Tree* t) {
    out->p = &t->header;
}

/* begin(): iterator at the leftmost node. */
void func_0042D100(Iter* out, Tree* t) {
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
void func_0042D0F0(TransferTimerIterator* result, RbTree* tree);
#endif /* merge_units */
#define func_0042D0F0(a0, a1) (func_0042D0F0((Iter *)(a0), (Tree *)(a1))) /* merge_units */

#if 0 /* merge_units */
void func_0042D0E0(TransferTimerIterator* result, const TransferTimerIterator* source);
#endif /* merge_units */
#define func_0042D0E0(a0, a1) ((void)func_0042D0E0((Word *)(a0), (Word *)(a1))) /* merge_units */

void func_0042F760(RbTree* tree, TransferTimerIterator* position);
void func_0042F8A0(TransferInsertResult* result, RbTree* tree, const TransferTimerValue* value);
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
    func_0042D0F0(&rawEnd, &D_00582720);
    func_0042D0E0(&end, &rawEnd);
    if ((node == end.node) ^ 1) {
        position.node = node;
        func_0042F760(&D_00582720, &position);
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
    func_0042D0F0(&rawEnd, &D_00582720);
    func_0042D0E0(&end, &rawEnd);
    if (node == end.node) {
        value.id.word = id->word;
        value.deadline = retry_threshold() + 45000;
        func_0042F8A0(&result, &D_00582720, &value);
    } else {
        node->deadline = retry_threshold() + 45000;
    }
}
#undef func_0042D0F0 /* merge_units */
#undef func_0042D0E0 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0042D110 */
