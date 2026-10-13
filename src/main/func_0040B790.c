#include "types.h"
typedef struct Obj40B790 { char pad[0xC]; int key; } Obj40B790;
typedef struct Node40B790 { struct Node40B790* parent; char list[4]; } Node40B790;
typedef struct { int key; Obj40B790* val; } Pair40B790;
typedef struct { void* it; unsigned char ok; } Res40B790;
extern void ObjRegistry_InsertOne(void* list, Obj40B790** o);
extern void ObjMap_Insert(Res40B790* out, void* map, Pair40B790* p);
extern char D_00571C10[];
#pragma push
#pragma opt_propagation off
unsigned char ObjRegistry_AppendRecursive(Node40B790* n, Obj40B790* o) {
    Res40B790 r;
Pair40B790 p;
    ObjRegistry_InsertOne(n->list, &o);
    if (n->parent) return ObjRegistry_AppendRecursive(n->parent, o);
    p.key = o->key;
    p.val = o;
    ObjMap_Insert(&r, D_00571C10, &p);
    return r.ok;
}
#pragma pop
