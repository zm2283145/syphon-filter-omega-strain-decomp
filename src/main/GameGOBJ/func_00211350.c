#pragma cplusplus on
#include "types.h"
struct Obj211350 { char pad0[0xC]; int id; char p10[0xD0]; int fE0; };
struct Msg211350 { void* vtable; char base[0x20]; int f24; int f28; int from; int to; char pad34[4]; };
extern "C" {
extern char D_004F5440[];
extern char D_004DAF10[];
void Event_Construct(void* m, void* type);
void Event_Send(void* m, void* target, int immediate);
void cMessage_dtor(void* m, int flags);
}
static inline int ObjId211350(Obj211350* o) { return o ? o->id : 0; }
#pragma push
#pragma opt_propagation off
extern "C" int PathObj_ScriptTrigger(Obj211350** args) {
    Msg211350 m;
    Msg211350* p = &m;
    Obj211350* self = args[0];
    self->fE0 = 0;
    Event_Construct(&m, D_004F5440);
    m.f24 = 0;
    m.f28 = 0;
    m.vtable = D_004DAF10;
    p->to = ObjId211350(0);
    p->from = ObjId211350(0);
    Event_Send(&m, self, 0);
    m.vtable = D_004DAF10;
    cMessage_dtor(&m, 0);
    return 0;
}
#pragma pop
