#pragma cplusplus on
#include "types.h"
extern "C" {
extern char* D_005061D0;
extern int g_HotboxTracker;
extern void Object_Register(void* o);
extern void* Hotbox_CreateRuntime(int a, void* o, int b, int c);
extern void Backpack_UpdateBoxPriority(void* o);
}
struct VC_002536D0 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual void v21(int a); };
static inline int R8_002536D0(void) { return (char)*D_005061D0++; }
static inline unsigned char RU8_002536D0(void) { return *D_005061D0++; }
static inline short R16_002536D0(void) { unsigned char lo = *D_005061D0++; unsigned char hi = *D_005061D0++; return lo + (hi << 8); }
typedef struct { int a[4]; int b[4]; int x; int n; } Sub_002536D0;
typedef struct { char id; char pad[3]; Sub_002536D0 s[5]; int count; unsigned char flag; char pad2[3]; } Ent_002536D0;
typedef struct { char pad[0x94]; int v; } Obj_002536D0;
struct S_002536D0;
typedef struct { char pad[0x5C]; void (*f)(struct S_002536D0* p, int a); } VT_002536D0;
typedef struct S_002536D0 { VT_002536D0* vt; char pad4[8]; int id; char pad10[0x54]; Ent_002536D0 e[3]; int count; int b; int c; int d; char pad2f0; unsigned char f; char pad2f2[10]; Obj_002536D0* obj; } S_002536D0;
extern "C" void func_002536D0(S_002536D0* p) {
    int i; Ent_002536D0* e; int j; Sub_002536D0* s; int k;
    p->count = R8_002536D0();
    p->b = R8_002536D0();
    p->c = R16_002536D0();
    p->d = R16_002536D0();
    p->f = R8_002536D0() != 0;
    for (i = 0; i < p->count; i++) {
        e = &p->e[i];
        e->id = R8_002536D0();
        e->count = R8_002536D0();
        e->flag = R8_002536D0() != 0;
        for (j = 0; j < e->count; j++) {
            s = &e->s[j];
            s->x = RU8_002536D0();
            s->n = R8_002536D0();
            for (k = 0; k < s->n; k++) {
                s->a[k] = R16_002536D0();
                s->b[k] = RU8_002536D0();
            }
        }
    }
    if (p->obj == 0) {
        ((VC_002536D0*)p)->v21(1);
        Object_Register(p);
        if (p->obj == 0) {
            p->obj = (Obj_002536D0*)Hotbox_CreateRuntime(g_HotboxTracker, p, 0, 1);
            p->obj->v = p->id;
        }
    }
    Backpack_UpdateBoxPriority(p);
}