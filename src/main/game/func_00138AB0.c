#pragma cplusplus on
#include "types.h"
struct ANode { ANode* prev; ANode* next; int val; };
struct APred { int pad; int* p; bool operator()(const int& x) const { return x == *p; } };
struct AIter {
    ANode* n;
    AIter() {}
    AIter(ANode* q) : n(q) {}
    int& operator*() const { return n->val; }
    AIter& operator++() { n = n->next; return *this; }
    bool operator==(const AIter& o) const { return n == o.n; }
    bool operator!=(const AIter& o) const { return n != o.n; }
};
struct AList {
    int size; ANode head;
    AIter begin() { return AIter(head.next); }
    AIter end() { return AIter(&head); }
};
extern "C" void ObjectList_EraseRange(AIter*, AList*, AIter*, AIter*);

extern "C" void ActiveList_EraseMatching(AList* l, APred pred)
{
    AIter e = l->end();
    for (AIter i = l->begin(); i != e;) {
        if (pred(*i)) {
            AIter j = i;
            for (++j; j != e; ++j)
                if (!pred(*j)) break;
            {
                AIter r, a, b;
                a = i; b = j;
                ObjectList_EraseRange(&r, l, &a, &b);
                i = r;
            }
            if (i == e) break;
        }
        ++i;
    }
}


