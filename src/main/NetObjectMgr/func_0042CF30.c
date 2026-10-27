#pragma cplusplus on
/* Preserve the single clock sample and recomputed object-ID addresses. */
#pragma opt_common_subs off
#pragma opt_propagation off

#include "net_transfer_types.h"
#include "network_admission.h"

extern "C" {
extern RbTree D_00582720;
void std_map_cString_cConsCommandPtr_begin(TransferTimerIterator* result, RbTree* tree);
TransferTimerIterator std_map_cString_cConsCommandPtr_end_void_2(RbTree* tree);
void func_0042D0E0(TransferTimerIterator* result, const TransferTimerIterator& source);
void std_red_black_tree_1_increment(TransferTimerIterator* position);
void cNPCInfoObject_ctor(int* shared);
void cNPCInfoObject_dtor(int* shared, short flags);
cGOBJ* nGobjManager_LookupGOBJ_cObjectIdR(const GobjId* id);
int cNPCInfoObject_GetOwner_uint(int* shared, unsigned int id);
void cNPCInfoObject_SetOwner_cObjectIdR_int(int* shared, const GobjId* id, int peer);
void func_004344C0(int* shared, const GobjId* id, int peer);
void cNetObjectMgr_AddDeactivate(cGOBJ* object, int previousPeer, int nextPeer);
void std_tree_pair_int_value_compare_erase_tree_5(RbTree* tree, TransferTimerIterator* position);
}

/* Expire transfer timers and retry ownership through the saved owner. */
extern "C" void func_0042CF30(void)
{
    TransferTimerIterator position;
    int shared;
    GobjId key;
    TransferTimerIterator end;
    TransferTimerIterator begin;
    std_map_cString_cConsCommandPtr_begin(&begin, &D_00582720);
    position.node = begin.node;
    unsigned int now = retry_threshold();
    cNPCInfoObject_ctor(&shared);
    TransferTimerNode* node;
    while (func_0042D0E0(&end, std_map_cString_cConsCommandPtr_end_void_2(&D_00582720)),
           node = position.node, (node == end.node) ^ 1) {
        std_red_black_tree_1_increment(&position);
        if (node->deadline < now) {
            key.word = node->id.word;
            cGOBJ* object = nGobjManager_LookupGOBJ_cObjectIdR(&key);
            if (object) {
                int peer = cNPCInfoObject_GetOwner_uint(&shared, node->id.word);
                cNPCInfoObject_SetOwner_cObjectIdR_int(&shared, &((GobjEntry*)object)->id, -1);
                func_004344C0(&shared, &((GobjEntry*)object)->id, 0);
                if (peer >= 0)
                    cNetObjectMgr_AddDeactivate(object, 0, peer);
            }
            TransferTimerIterator erased;
            erased.node = node;
            std_tree_pair_int_value_compare_erase_tree_5(&D_00582720, &erased);
        }
    }
    cNPCInfoObject_dtor(&shared, -1);
}
