
#include "types.h"
/* Object_LookupById */
extern void* D_00571740;
extern void* ObjRegistry_Find(void*, int);
extern void* Object_GetScope(void*);
extern void* Scope_GetParent(void*);

void* Object_LookupById(int id) {
    void* o;
    void* s;
    void* root = D_00571740;
    o = ObjRegistry_Find(root, id);
    if (o) {
        for (s = Object_GetScope(o); s; s = Scope_GetParent(s)) {
            if (s == root) { asm { .set reorder } goto out; } /* barrier: keeps the found branch unmerged */
        }
    }
    o = 0;
out:
    return o;
}