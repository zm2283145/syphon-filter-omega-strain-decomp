#include "types.h"
typedef struct AcNode { struct AcNode* prev; struct AcNode* next; void* obj; } AcNode;
typedef struct { AcNode* n; } AcIter;
typedef struct { void* a; AcNode* first; } AcList;
typedef struct {
    char pad0[0x30];
    char list[4];
    char x34[4];
    AcNode* x38;
    char x3c[4];
    char x40[4];
    AcNode* x44;
} AcOwner;
extern void List_Begin(AcIter*, void*);
extern void std_list_cLosRequest_cCollisionModelList_GamePtr_generic_iterator_ctor(AcIter*, AcIter*);
extern void std_list_deleter_voidPtr_end_void(AcIter*, void*);
extern void LosMgr_ExecuteEntry(void*);
extern void cLosManager_cCollisionModelList_Game_DeleteRequest(AcOwner*, void*);
extern void ObjectList_EraseRange(AcIter*, void*, AcIter*, AcIter*);
extern AcNode* details_compressed_pair_imp_cAllocator_node_node_base_1_second_void(void*);
extern void List_Erase(AcIter*, void*, AcIter*);
int LosMgr_Update(AcOwner* o)
{
    AcIter it;
    AcIter end;
    AcIter r1;
    AcIter first;
    AcIter last;
    AcIter r2;
    AcIter pos;
    AcIter t1;
    AcIter t2;
    void* obj;
    AcNode* n;
    AcNode* e;
    List_Begin(&t1, o->list);
    std_list_cLosRequest_cCollisionModelList_GamePtr_generic_iterator_ctor(&it, &t1);
    n = it.n;
    std_list_deleter_voidPtr_end_void(&t2, o->list);
    std_list_cLosRequest_cCollisionModelList_GamePtr_generic_iterator_ctor(&end, &t2);
    e = end.n;
    for (; n != e; n = n->next) {
        obj = n->obj;
        LosMgr_ExecuteEntry(obj);
        cLosManager_cCollisionModelList_Game_DeleteRequest(o, obj);
    }
    last.n = (AcNode*)o->x34;
    first.n = o->x38;
    ObjectList_EraseRange(&r1, o->list, &first, &last);
    if (*(int*)o->x3c) {
        obj = details_compressed_pair_imp_cAllocator_node_node_base_1_second_void(o->x40)->next->obj;
        LosMgr_ExecuteEntry(obj);
        cLosManager_cCollisionModelList_Game_DeleteRequest(o, obj);
        pos.n = o->x44;
        List_Erase(&r2, o->x3c, &pos);
    }
    return 1;
}