#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
struct DbObj { VPAD16(a) VPAD4(b) virtual void Draw(); char pad[0x38]; float depth; };
typedef struct { int count; DbObj* items[1]; } DbWorld;
typedef struct { int a, b, c, d; } DbMap;
typedef struct { float f; DbObj* o; } DbPair;
typedef struct { char* p; } DbIt;
extern "C" {
extern void func_0013F800(DbMap* m, void* cmp, void* alloc);
extern void func_0013F180(DbPair* p, float* f, DbObj** o);
extern void SceneDrawMap_Insert(DbIt* out, DbMap* m, DbPair* kv);
extern void func_0013F170(DbIt* out, DbMap* m);
extern void func_0013F120(DbIt* out, DbMap* m);
extern int func_0013F100(DbIt* a, DbIt* b);
extern DbObj** func_0013F160(DbIt* it);
extern void TreeIter_Increment(DbIt* it);
extern void func_0013F090(DbMap* m, short del);
}

extern "C" void World_DrawBuckets(DbWorld* w, int sorted)
{
    if (!sorted) {
        DbObj** p;
        for (p = w->items; p != w->items + w->count; p++)
            (*p)->Draw();
    } else {
        DbMap m;
        DbPair kv;
        DbPair tmp;
        DbIt res;
        char cmp[4];
        char alloc[4];
        float f;
        DbObj* o;
        DbIt it;
        DbIt e;
        DbObj** p;
        func_0013F800(&m, cmp, alloc);
        for (p = w->items; p != w->items + w->count; p++) {
            DbObj* q = *p;
            float d = q->depth;
            o = q;
            f = d;
            func_0013F180(&tmp, &f, &o);
            kv.f = tmp.f;
            kv.o = tmp.o;
            SceneDrawMap_Insert(&res, &m, &kv);
        }
        func_0013F170(&it, &m);
        func_0013F120(&e, &m);
        while (func_0013F100(&it, &e)) {
            DbObj* d = *func_0013F160(&it);
            d->Draw();
            TreeIter_Increment(&it);
            func_0013F120(&e, &m);
        }
        func_0013F090(&m, -1);
    }
}

