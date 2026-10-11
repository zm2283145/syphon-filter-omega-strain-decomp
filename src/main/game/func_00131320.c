#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
class Obj_1320 {
public:
    VPAD16(a) VPAD4(b) VPAD1(c)
    virtual void Attach(int on);
    virtual void Detach(int on);
    char pad[8];
    int id;
};
struct C_1320 { int pad0; int pad4; Obj_1320* cur; };
struct S_1320 { char pad[0xC4]; int list; int pad8; C_1320* ctl; };
extern "C" {
extern Obj_1320* D_00583878;
extern int D_0058387C;
void List_PushFront(void* list, Obj_1320** o);
}
extern "C" void func_00131320(S_1320* self, Obj_1320* o)
{
    int m1;
    int* p;
    if (self->list) {
        Obj_1320* c = self->ctl->cur;
        if (c)
            c->Detach(1);
    }
    o->Attach(1);
    D_00583878 = o;
    if (o)
        p = &o->id;
    else {
        m1 = -1;
        p = &m1;
    }
    D_0058387C = *p;
    List_PushFront(&self->list, &o);
}