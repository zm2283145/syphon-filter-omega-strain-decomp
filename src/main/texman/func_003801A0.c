#pragma cplusplus on

#include "types.h"

/* Erase the first list entry whose value equals v. */
typedef struct Node_3801A0 { int pad0; struct Node_3801A0* next; int value; } Node_3801A0;
typedef struct { Node_3801A0* p; } It_3801A0;
typedef struct { unsigned char pad[0x428]; int list; int header; } Obj_3801A0;

extern "C" {
Node_3801A0* func_00380270(void* header);
void* func_00380260(void* list);
void func_00380250(It_3801A0* out, void* node);
void func_00383560(It_3801A0* result, void* list, It_3801A0* pos);
}

extern "C" void func_003801A0(Obj_3801A0* o, int v)
{
    It_3801A0 result;
    It_3801A0 pos;
    It_3801A0 end;
    Node_3801A0* n;
    for (n = func_00380270(&o->header)->next; (func_00380250(&end, func_00380260(&o->list)), n != end.p); n = n->next) {
        if (v == n->value) {
            pos.p = n;
            func_00383560(&result, &o->list, &pos);
            return;
        }
    }
}