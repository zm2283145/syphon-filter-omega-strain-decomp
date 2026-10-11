#ifndef NODE_WORLD_Q4_H
#define NODE_WORLD_Q4_H
/* 64-byte matrix returned by value; its copy constructor reproduces retail's
 * unfolded two-register alternating quad copy (last sq schedulable) (vc1).
 * Needs #pragma cplusplus on. */
#include "q4r.h"
struct MtxQ4 {
    __int128 r[4];
    MtxQ4() {}
    MtxQ4(const MtxQ4& s) { __int128 qa; __int128 qb; const MtxQ4* p = &s; MtxQ4* d = this; Q4COPY_R(d, p, qa, qb); }
};
/* scene node: vtable at 0, cached world matrix at 0x10, dirty flag at 0x50 */
struct NodeQ4 { void* vt; int pad[3]; MtxQ4 world; unsigned char dirty; };
struct NodeQ4V { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); };
typedef struct { char pad[0x50]; NodeQ4* node; } OwnerQ4;
/* MtxQ4 Get(OwnerQ4*): refresh the node's world matrix if dirty (vslot 20), return it or the fallback. */
#define NODE_WORLD_Q4_BODY(o, fallback) \
    NodeQ4* n = (o)->node; \
    if (n) { \
        if (n->dirty) \
            ((NodeQ4V*)n)->v20(); \
        { MtxQ4* w = &n->world; return *w; } \
    } \
    return fallback;
#endif