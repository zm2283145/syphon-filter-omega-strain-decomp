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
extern void func_0013B180(AcIter*, void*);
extern void func_0013B170(AcIter*, AcIter*);
extern void func_0013B160(AcIter*, void*);
extern void func_0013AE20(void*);
extern void func_0013AE00(AcOwner*, void*);
extern void ObjectList_EraseRange(AcIter*, void*, AcIter*, AcIter*);
extern AcNode* func_0013ADF0(void*);
extern void func_00138DA0(AcIter*, void*, AcIter*);
int func_0013ACD0(AcOwner* o)
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
    func_0013B180(&t1, o->list);
    func_0013B170(&it, &t1);
    n = it.n;
    func_0013B160(&t2, o->list);
    func_0013B170(&end, &t2);
    e = end.n;
    for (; n != e; n = n->next) {
        obj = n->obj;
        func_0013AE20(obj);
        func_0013AE00(o, obj);
    }
    last.n = (AcNode*)o->x34;
    first.n = o->x38;
    ObjectList_EraseRange(&r1, o->list, &first, &last);
    if (*(int*)o->x3c) {
        obj = func_0013ADF0(o->x40)->next->obj;
        func_0013AE20(obj);
        func_0013AE00(o, obj);
        pos.n = o->x44;
        func_00138DA0(&r2, o->x3c, &pos);
    }
    return 1;
}