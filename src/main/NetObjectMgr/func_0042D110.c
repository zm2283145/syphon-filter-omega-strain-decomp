#pragma cplusplus on

#include "net_transfer_types.h"
#include "network_admission.h"

extern "C" {
extern RbTree D_00582720;
extern char D_004BFAB0[];
extern char D_004BFAE0[];
void func_0042EF70(TransferTimerIterator* result, RbTree* tree, const GobjId* id);
void func_0042D0F0(TransferTimerIterator* result, RbTree* tree);
void func_0042D0E0(TransferTimerIterator* result, const TransferTimerIterator* source);
void func_0042F760(RbTree* tree, TransferTimerIterator* position);
void func_0042F8A0(TransferInsertResult* result, RbTree* tree, const TransferTimerValue* value);
void func_00127358(const char* format, ...);
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
    func_0042EF70(&found, &D_00582720, &key);
    TransferTimerNode* node = found.node;
    func_00127358(D_004BFAB0, id->word);
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
    func_0042EF70(&found, &D_00582720, &key);
    TransferTimerNode* node = found.node;
    func_00127358(D_004BFAE0, id->word);
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
