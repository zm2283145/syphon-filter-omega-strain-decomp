#include "types.h"
typedef struct { int pad[3]; int key; } Node2CD0;
typedef struct { char pad[0x34]; Node2CD0* node; int key; } Obj2CD0;
Node2CD0* func_00272CD0(Obj2CD0* o) {
    Node2CD0* n = o->node;
    unsigned char ok = 1;
    int z = (n != 0) ^ 1;
    if (!z && n->key != o->key) ok = 0;
    return ok ? n : 0;
}