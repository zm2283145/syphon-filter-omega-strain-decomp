#include "types.h"
#pragma cplusplus on
#pragma bool off
struct C6Ent_3AE5E0 { int key; int pad[3]; char value[0x170]; };
struct C6Coll_3AE5E0 { int pad0; int count; };
extern "C" C6Ent_3AE5E0** func_003AE740(C6Coll_3AE5E0*);
extern "C" char D_005429F0[];
static inline int C6Eq(C6Ent_3AE5E0* a, C6Ent_3AE5E0* b) { return a == b; }
extern "C" void* func_003AE690(C6Coll_3AE5E0* self, int* key) {
    C6Ent_3AE5E0* it = *func_003AE740(self);
    C6Ent_3AE5E0* end = *func_003AE740(self) + self->count;
    for (; C6Eq(it, end) ^ 1; it++) {
        if (it->key == *key) return it->value;
    }
    return D_005429F0;
}