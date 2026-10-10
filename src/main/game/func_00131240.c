#include "types.h"
#pragma cplusplus on
class AlObj_f3 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20();
    virtual void Activate(int on);
    virtual void Deactivate(int on);
    char pad4[8];
    int id;
};
typedef struct AlNode_f3 { struct AlNode_f3* next; struct AlNode_f3* prev; AlObj_f3* obj; } AlNode_f3;
typedef struct { char pad[0xC4]; int list; int padC8; AlNode_f3* head; } AlList_f3;
extern "C" {
extern AlObj_f3* D_00583878;
extern int D_0058387C;
extern void func_00138DA0(AlNode_f3** out, int* list, AlNode_f3** it);
AlObj_f3* ActiveList_RemoveFirst(AlList_f3* l);
}
static inline void AlSetCurrent_f3(AlObj_f3* o)
{
    int def[1];
    int* p;
    D_00583878 = o;
    if (o) {
        p = &o->id;
    } else {
        def[0] = -1;
        p = def;
    }
    D_0058387C = *p;
}
AlObj_f3* ActiveList_RemoveFirst(AlList_f3* l)
{
    AlNode_f3* ret[1];
    AlNode_f3* it[1];
    AlObj_f3* obj;
    AlObj_f3* next;
    AlNode_f3** hp;
    AlNode_f3* n;
    hp = &l->head;
    n = *hp;
    obj = n->obj;
    it[0] = n;
    func_00138DA0(ret, &l->list, it);
    obj->Deactivate(1);
    next = (*hp)->obj;
    if (next) {
        next->Activate(1);
        AlSetCurrent_f3(next);
    } else {
        AlSetCurrent_f3(0);
    }
    return obj;
}