#include "types.h"
/* Loads the saved id pair and position, then registers the net message type. */
typedef struct { float x, y, z; } Vec2D78C0;
typedef struct { int a, b; } Ids2D78C0;
extern int func_002E9A10(void);
extern int func_003C9C30(void* f);
extern int func_002E9A98(void* f, void* buf, int size, int count);
extern int NetMsg_RegisterType(void* t, int id, void* fn);
extern char D_0051F0C8[];
extern void func_002D7A80(void);
static inline void IInit2D78C0(Ids2D78C0* i) { i->a = -1; i->b = -1; }
unsigned char func_002D78C0(void)
{
    struct { long long file; Ids2D78C0 ids; int pad; Vec2D78C0 v; } L;
    int err;
    unsigned char ok;
    Vec2D78C0* p;
    ok = 0;
    p = &L.v;
    p->x = -1.0f; L.v.y = -1.0f; L.v.z = -1.0f;
    IInit2D78C0((Ids2D78C0*)((char*)&L + 8));
    err = func_002E9A10();
    if (err == 0 && func_003C9C30(&L.file) && err == 0 &&
        func_002E9A98(&L.file, p, 12, 1) == 0 &&
        func_002E9A98(&L.file, &L.ids, 4, 2) == 0 &&
        NetMsg_RegisterType(D_0051F0C8, 2, func_002D7A80) == 0)
        ok = 1;
    return ok;
}
