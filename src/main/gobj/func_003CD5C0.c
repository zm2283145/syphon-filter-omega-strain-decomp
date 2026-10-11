#pragma cplusplus on

#include "types.h"
#include "vslot_classes.h"

typedef struct Node_3CD5C0 { void* vt; unsigned char pad[0xC]; unsigned char data[0x40]; unsigned char dirty; } Node_3CD5C0;
typedef struct { unsigned char pad0[0x50]; Node_3CD5C0* node; } Obj_3CD5C0;
extern "C" unsigned char D_0055C9F0[];
extern "C" void func_003CD630(Obj_3CD5C0* o, void* data);

extern "C" void func_003CD5C0(Obj_3CD5C0* o)
{
    Node_3CD5C0* n = o->node;
    void* d;
    if (n) {
        if (n->dirty)
            ((VSlots67*)n)->slot20();
        d = n->data;
    } else {
        d = D_0055C9F0;
    }
    func_003CD630(o, d);
}