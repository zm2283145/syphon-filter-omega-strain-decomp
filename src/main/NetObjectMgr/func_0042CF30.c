#pragma cplusplus on
/* Preserve the single clock sample and recomputed object-ID addresses. */
#pragma opt_common_subs off
#pragma opt_propagation off

#include "net_transfer_types.h"
#include "network_admission.h"

extern "C" {
extern RbTree D_00582720;
void func_0042D100(TransferTimerIterator* result, RbTree* tree);
TransferTimerIterator func_0042D0F0(RbTree* tree);
void func_0042D0E0(TransferTimerIterator* result, const TransferTimerIterator& source);
void Tree_Successor(TransferTimerIterator* position);
void func_00436C00(int* shared);
void func_00436BA0(int* shared, short flags);
cGOBJ* Object_LookupById(const GobjId* id);
int func_004343E0(int* shared, unsigned int id);
void func_00434600(int* shared, const GobjId* id, int peer);
void func_004344C0(int* shared, const GobjId* id, int peer);
void func_0042DA30(cGOBJ* object, int previousPeer, int nextPeer);
void func_0042F760(RbTree* tree, TransferTimerIterator* position);
}

/* Expire transfer timers and retry ownership through the saved owner. */
extern "C" void func_0042CF30(void)
{
    TransferTimerIterator position;
    int shared;
    GobjId key;
    TransferTimerIterator end;
    TransferTimerIterator begin;
    func_0042D100(&begin, &D_00582720);
    position.node = begin.node;
    unsigned int now = retry_threshold();
    func_00436C00(&shared);
    TransferTimerNode* node;
    while (func_0042D0E0(&end, func_0042D0F0(&D_00582720)),
           node = position.node, (node == end.node) ^ 1) {
        Tree_Successor(&position);
        if (node->deadline < now) {
            key.word = node->id.word;
            cGOBJ* object = Object_LookupById(&key);
            if (object) {
                int peer = func_004343E0(&shared, node->id.word);
                func_00434600(&shared, &((GobjEntry*)object)->id, -1);
                func_004344C0(&shared, &((GobjEntry*)object)->id, 0);
                if (peer >= 0)
                    func_0042DA30(object, 0, peer);
            }
            TransferTimerIterator erased;
            erased.node = node;
            func_0042F760(&D_00582720, &erased);
        }
    }
    func_00436BA0(&shared, -1);
}
