#pragma cplusplus on
#include "types.h"
struct VObj_ca0 { virtual void v0(); virtual bool v1(int m); };
typedef struct LNode_ca0 { struct LNode_ca0* prev; struct LNode_ca0* next; VObj_ca0* obj; } LNode_ca0;
typedef union { LNode_ca0* p; } LIt_ca0;
typedef struct { char pad[0x20]; int list; } Obj_ca0;
extern "C" void std_list_deleter_voidPtr_end_void(LIt_ca0* out, void* list);
extern "C" LIt_ca0* std_list_cSystemPtr_generic_iterator_ctor(LIt_ca0* dst, LIt_ca0* src);
extern "C" void std_list_cSystemPtr_begin(LIt_ca0* out, void* list);
extern "C" LIt_ca0* cLListIterator_cSystemPtr_ctor(LIt_ca0* dst, LIt_ca0* src);
extern "C" bool cSystemContainer_HandleMessage(Obj_ca0* self, int msg) {
    bool r = false;
    LIt_ca0 it;
    LIt_ca0 beg;
    LIt_ca0 end;
    LIt_ca0 e0;
    LIt_ca0 b0;
    LNode_ca0* last;
    std_list_deleter_voidPtr_end_void(&e0, &self->list);
    std_list_cSystemPtr_generic_iterator_ctor(&end, &e0);
    last = end.p;
    std_list_cSystemPtr_begin(&b0, &self->list);
    cLListIterator_cSystemPtr_ctor(&beg, &b0);
    for (it = beg; it.p != last; it.p = it.p->next) {
        VObj_ca0* o = it.p->obj;
        r |= o->v1(msg);
    }
    return r;
}