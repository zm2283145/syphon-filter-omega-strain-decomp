
#include "types.h"
/* Skel_Find */
typedef struct { char* name; void* skel; } Pt2_SkelEnt;
typedef struct Pt2_SkelNode { int pad; struct Pt2_SkelNode* next; Pt2_SkelEnt* e; } Pt2_SkelNode;
extern char D_005429B0[];
extern void List_Begin_16E880(void*, void*);
extern void std_list_cSkeletonDataBankEntryPtr_generic_iterator_1_ctor(void*, void*);
extern void std_list_cSkeletonDataBankEntryPtr_end_void(void*, void*);
extern void cConstLListIterator_cSkeletonDataBankEntryPtr_ctor(void*, void*);
extern int strcmp(const char*, const char*);

void* Skel_Find(void* list, char* name) {
    Pt2_SkelNode* end[1];
    Pt2_SkelNode* it[1];
    void* b[1];
    int t[1];
    Pt2_SkelNode* n;
    List_Begin_16E880(b, list);
    std_list_cSkeletonDataBankEntryPtr_generic_iterator_1_ctor(it, b[0]);
    for (n = it[0]; std_list_cSkeletonDataBankEntryPtr_end_void(t, list), cConstLListIterator_cSkeletonDataBankEntryPtr_ctor(end, t), n != end[0]; n = n->next) {
        if (strcmp(n->e->name, name) == 0) return n->e->skel;
    }
    return D_005429B0;
}