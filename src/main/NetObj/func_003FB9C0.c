#include "types.h"
#include "net_local_id.h"
typedef struct { char pad[0xC]; unsigned int h; } Obj_B9C0;
typedef struct { Obj_B9C0* o; int id; } Pair_B9C0;
typedef struct { int k; Pair_B9C0 p; } Ent_B9C0;
extern char D_0055C770[];
extern unsigned char D_005724B0;
Ent_B9C0* func_003FBF40(void* map, int* key);
void func_00436C00(void* ctx);
void func_00436BA0(void* ctx, int n);
void func_00435F30(void* ctx, unsigned int* h, int owner);
void func_003FB9C0(Obj_B9C0* o)
{
    int k[1];
    char ctx[4];
    int tmp[1];
    Ent_B9C0* r;
    k[0] = ((o->h & 0x7F000000) >> 24) - 1;
    if (k[0] < 0) k[0] = 0;
    r = func_003FBF40(D_0055C770, k);
    r->p.o = o;
    {
        Pair_B9C0* pr = &r->p;
        int* p;
        if (o) p = (int*)&o->h; else { tmp[0] = -1; p = tmp; }
        pr->id = *p;
    }
    if (D_005721C8 && D_005724B0 != 7) {
        unsigned int own;
        func_00436C00(ctx);
        own = (o->h & 0x7F000000) >> 24;
        if (own - 1 == NetLocalId())
            func_00435F30(ctx, &o->h, ((o->h & 0x7F000000) >> 24) - 1);
        func_00436BA0(ctx, -1);
    }
}