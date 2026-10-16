#pragma cplusplus on
#include "types.h"

struct Handle22D740 {
    void* obj;
    int id;
};

struct Node22D740 {
    Node22D740* prev;
    Node22D740* next;
    Handle22D740 value;
};

struct List22D740 {
    int size;
    Node22D740* sentinelPrev;
    Node22D740* first;
};

struct Pred22D740 {
    int pad;
    Handle22D740* target;
};

extern "C" {
bool WeakHandle_EqualsPred(Pred22D740* self, Handle22D740* x, Handle22D740* y);
void Player_ClearRecentTargets(Node22D740** result, List22D740* list, Node22D740** first, Node22D740** last);
}

#pragma push
#pragma opt_common_subs off
extern "C" void TargetVis_LeaveRecent(List22D740* self, Pred22D740 pred) {
    Node22D740* end = (Node22D740*)&self->sentinelPrev;
    Node22D740* i = self->first;
    Handle22D740** tp;
    if (i != end) {
    tp = &pred.target;
    do {
        if (WeakHandle_EqualsPred(&pred, &i->value, *tp)) {
            Node22D740* j = i->next;
            while (j != end) {
                if (!WeakHandle_EqualsPred(&pred, &j->value, *tp)) {
                    break;
                }
                j = j->next;
            }
            {
                Node22D740* result;
                Node22D740* first;
                Node22D740* last;
                last = j;
                first = i;
                Player_ClearRecentTargets(&result, self, &first, &last);
                i = result;
                if (result == end) {
                    break;
                }
            }
        }
        i = i->next;
    } while (i != end);
    }
}
#pragma pop

