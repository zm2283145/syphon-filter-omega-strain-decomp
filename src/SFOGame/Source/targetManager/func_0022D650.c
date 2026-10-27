#pragma cplusplus on
#include "types.h"

struct Node22D650 {
    Node22D650* prev;
    Node22D650* next;
    char name[16];
};

struct List22D650 {
    int size;
    Node22D650* sentinelPrev;
    Node22D650* first;
};

extern "C" {
int Libc_Memcmp(const char* a, const char* b, int n);
void std_list_deleter_LosReqElem_erase(Node22D650** result, List22D650* list, Node22D650** first, Node22D650** last);
}

struct NamePred22D650 {
    int pad;
    const char* name;
};

static inline bool NameEq22D650(Node22D650* n, const char* name) {
    bool r = !Libc_Memcmp(n->name, name, 16);
    return r;
}

#pragma push
#pragma opt_common_subs off
extern "C" void std_list_imp_LosReqElem_remove_if(List22D650* self, NamePred22D650 pred) {
    Node22D650* end = (Node22D650*)&self->sentinelPrev;
    Node22D650* i = self->first;
    const char* name = pred.name;
    while (i != end) {
        if (NameEq22D650(i, name)) {
            Node22D650* j = i->next;
            while (j != end) {
                if (!NameEq22D650(j, name)) {
                    break;
                }
                j = j->next;
            }
            {
                Node22D650* result;
                Node22D650* first;
                Node22D650* last;
                last = j;
                first = i;
                std_list_deleter_LosReqElem_erase(&result, self, &first, &last);
                i = result;
                if (result == end) {
                    break;
                }
            }
        }
        i = i->next;
    }
}
#pragma pop



