#pragma cplusplus on

#include "types.h"
#include "vslot_classes.h"

typedef struct { char pad[4]; VSlots67* ctl; char p1[0x1C]; void* res; } Obj_417340;
extern "C" void func_003E8DE0(void*, int);
extern "C" void func_003E8DC0(void*, int);

extern "C" void func_00417340(Obj_417340* o)
{
    if (o->res) {
        func_003E8DE0(o->res, 1);
        func_003E8DC0(o->res, 0);
        func_003E8DE0(o->res, 0);
    }
    o->ctl->slot10();
}