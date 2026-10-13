#pragma cplusplus on
#include "types.h"
struct VObj_ca0 { virtual void v0(); virtual bool v1(int m); };
typedef struct LNode_ca0 { struct LNode_ca0* prev; struct LNode_ca0* next; VObj_ca0* obj; } LNode_ca0;
typedef union { LNode_ca0* p; } LIt_ca0;
typedef struct { char pad[0x20]; int list; } Obj_ca0;
extern "C" void func_0013B160(LIt_ca0* out, void* list);
extern "C" LIt_ca0* func_003CAB40(LIt_ca0* dst, LIt_ca0* src);
extern "C" void func_003CAB30(LIt_ca0* out, void* list);
extern "C" LIt_ca0* func_003CAB20(LIt_ca0* dst, LIt_ca0* src);
extern "C" bool Object_BroadcastToChildren(Obj_ca0* self, int msg) {
    bool r = false;
    LIt_ca0 it;
    LIt_ca0 beg;
    LIt_ca0 end;
    LIt_ca0 e0;
    LIt_ca0 b0;
    LNode_ca0* last;
    func_0013B160(&e0, &self->list);
    func_003CAB40(&end, &e0);
    last = end.p;
    func_003CAB30(&b0, &self->list);
    func_003CAB20(&beg, &b0);
    for (it = beg; it.p != last; it.p = it.p->next) {
        VObj_ca0* o = it.p->obj;
        r |= o->v1(msg);
    }
    return r;
}