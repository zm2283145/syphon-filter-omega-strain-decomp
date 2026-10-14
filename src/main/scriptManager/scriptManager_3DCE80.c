/*
 * main/scriptManager: range (3 files, 003DCE80-003DD2D0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#pragma push
#pragma cplusplus on
#include "buf_holder_dtor.h"
#pragma pop
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* merge_units: begin func_003DCE80 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR(func_003DCE80)
#pragma pop /* merge_units */
/* merge_units: end func_003DCE80 */

/* merge_units: begin func_003DCF70 */
#pragma push /* merge_units */
#pragma cplusplus on
struct E_CF70 { int a, b, c; };
struct V_CF70 {
    int x0; int x4; E_CF70* data; int xC;
    E_CF70& operator[](unsigned int i) { return data[i]; }
    void init(int n, const E_CF70& e);
    void resize(int n, const E_CF70& e);
};
struct Def_CF70 { char* name; V_CF70 v; int id; };
struct Mgr_CF70 { int pad0; int count; };
extern "C" {
extern char D_004BD4C0[];
extern Mgr_CF70* D_00554F30;
void* Mem_Alloc(int pool, int size, char* file, int line);
char* Str_Duplicate(char*);
Def_CF70* func_003E0CE0(int, char*);
void func_003D9210(V_CF70*, int, const E_CF70&);
void func_003E2F60(V_CF70*, int, const E_CF70&);
void func_003D91F0(Mgr_CF70*, Def_CF70**);
}
inline void V_CF70::init(int n, const E_CF70& e) { func_003D9210(this, n, e); }
inline void V_CF70::resize(int n, const E_CF70& e) { func_003E2F60(this, n, e); }
static inline Def_CF70* NewDef_CF70(char* name, int count, int id)
{
    Def_CF70* n;
    {
        AllocGuard g;
        n = (Def_CF70*)Mem_Alloc(0, 0x18, D_004BD4C0, 0xB12);
    }
    if (n) {
        char* nm = Str_Duplicate(name);
        n->v.init(count, E_CF70());
        n->name = nm;
        n->id = id;
    }
    return n;
}
extern "C" Def_CF70* func_003DCF70(int ctx, char* name, E_CF70* data, int count)
{
    int i;
    Def_CF70* d = func_003E0CE0(ctx, name);
    if (!d) {
        d = NewDef_CF70(name, count, D_00554F30->count + 10);
        func_003D91F0(D_00554F30, &d);
    } else if (!d->v.x4 && count) {
        d->v.resize(count, E_CF70());
    }
    for (i = 0; i < count; i++)
        d->v[i] = data[i];
    return d;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003DCF70(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003DCF70 */

/* merge_units: begin func_003DD2D0 */
#pragma push /* merge_units */
#pragma cplusplus on

struct Def_D2D0 {
    char* name; int id; int count; int xC; int pad10; int x14;
    unsigned char b18; unsigned char b19; char pad1A[2];
    int args[20]; int x6C; int x70; int x74; int x78;
};
struct PVec_D2D0 { int x0; int x4; int** data; };
struct Scr_D2D0 {
    int x0; int* idp; PVec_D2D0 vec; int pad14; int x18; int pad1C; void* ctx;
    int x24; int x28; int x2C; int x30; unsigned char b34; char pad35[3];
    int refs; int x3C; unsigned char b40; unsigned char b41;
};
struct Lst_D2D0 { char pad[0xC]; unsigned char bC; };
struct Node_D2D0 { char pad[0x10]; void* list; };
struct RIt_D2D0 { Node_D2D0* p; RIt_D2D0() {} RIt_D2D0(const RIt_D2D0& o) : p(o.p) {} };
inline void* operator new(unsigned int, void* p) { return p; }
union U4_D2D0 { int i; float f; };
struct It_D2D0 { Node_D2D0* p; It_D2D0() {} It_D2D0(const RIt_D2D0& r) : p(r.p) {} __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~It_D2D0() {} It_D2D0& operator=(const It_D2D0& o) { *(U4_D2D0*)this = *(const U4_D2D0*)&o; return *this; } It_D2D0& operator=(const RIt_D2D0& r) { p = r.p; return *this; } };
struct CIt_D2D0 { Node_D2D0* p; };
struct Map_D2D0 { int x0; int x4; int x8; int xC; };
struct Mgr_D2D0 { char pad[0x28]; int count; int arr[5000]; char pad2[0x4E5C - 0x2C - 20000]; Map_D2D0* map; };
struct Cmp_D2D0 { int x; Cmp_D2D0() {} };
struct Al_D2D0 { int x; Al_D2D0() {} };

extern "C" {
extern void* D_00554F20;
#if 0 /* merge_units */
void* Mem_Alloc(int, int, char*, int);
#endif /* merge_units */
#define Mem_Alloc(a0, a1, a2, a3) (Mem_Alloc((a0), (a1), (a2), (a3))) /* merge_units */

Scr_D2D0* ScriptDesc_Find(Mgr_D2D0*, Def_D2D0*);
Scr_D2D0* func_003D5EB0(Scr_D2D0*, char*, void*, int);
void PtrVector_Resize(PVec_D2D0*, int, int*);
void func_003D7910(void*, Scr_D2D0**);
int** func_003DD780(PVec_D2D0*, int);
void func_003E3140(Map_D2D0*, const Cmp_D2D0&, const Al_D2D0&);
RIt_D2D0 func_003E2E60(Map_D2D0*, int*);
RIt_D2D0 func_003DD770(Map_D2D0*);
void func_003DD760(CIt_D2D0*, RIt_D2D0*);
char* func_003E2DA0(Map_D2D0*, int*);
void func_003D8380(Lst_D2D0*);
}

static inline void End_D2D0(CIt_D2D0* e, Map_D2D0* m) { func_003DD760(e, &func_003DD770(m)); }
static inline int* Tab_Push(Mgr_D2D0* tab, int v)
{
    if ((unsigned int)tab->count < 5000) {
        tab->arr[tab->count] = v;
        tab->count++;
    }
    return (int*)&tab->count + tab->count;
}

extern "C" Scr_D2D0* Script_LinkDefinition(Mgr_D2D0* tab, Def_D2D0* def, void* ctx)
{
    Scr_D2D0* s;
    int key;
    It_D2D0 it;
    int z;
    CIt_D2D0 e;
    It_D2D0 t2;
    s = ScriptDesc_Find(tab, def);
    if (s) {
        if (!s->ctx && ctx) {
            s->ctx = ctx;
            s->b34 = 1;
            s->x18 = def->x78;
            s->x24 = def->x6C;
            s->x28 = def->xC;
            s->x2C = def->x70;
            s->x30 = def->x74;
            s->x3C = def->x14;
            s->b40 = def->b18;
            s->b41 = def->b19;
        }
    } else {
        Scr_D2D0* n;
        int i;
        {
            AllocGuard g;
            n = (Scr_D2D0*)Mem_Alloc(0, 0x44, D_004BD4C0, 0xAE4);
        }
        if (n)
            n = func_003D5EB0(n, def->name, ctx, def->x78);
        s = n;
        n->x24 = def->x6C;
        s->x28 = def->xC;
        s->x2C = def->x70;
        s->x30 = def->x74;
        s->idp = Tab_Push(tab, def->id);
        s->x3C = def->x14;
        s->b40 = def->b18;
        s->b41 = def->b19;
        z = 0;
        PtrVector_Resize(&s->vec, def->count, &z);
        for (i = 0; i < def->count; i++) {
            int** p = &s->vec.data[(unsigned int)i];
            *p = Tab_Push(tab, def->args[i]);
        }
        func_003D7910(D_00554F20, &s);
        if (s->b41) {
            key = **func_003DD780(&s->vec, 1);
            if (!tab->map) {
                Map_D2D0* m;
                {
                    AllocGuard g;
                    m = (Map_D2D0*)Mem_Alloc(0, 0x10, D_004BD4C0, 0xAF9);
                }
                if (m) {
                    func_003E3140(m, Cmp_D2D0(), Al_D2D0());
                }
                tab->map = m;
            }
            {
                RIt_D2D0 r1 = func_003E2E60(tab->map, &key);
                it = r1;
                End_D2D0(&e, tab->map);
                if (it.p == e.p) {
                    Lst_D2D0* l;
                    Lst_D2D0** slot = (Lst_D2D0**)(func_003E2DA0(tab->map, &key) + 4);
                    {
                        AllocGuard g;
                        l = (Lst_D2D0*)Mem_Alloc(0, 0x10, D_004BD4C0, 0xAFF);
                    }
                    if (l) {
                        func_003D8380(l);
                        l->bC = 1;
                    }
                    *slot = l;
                    t2 = func_003E2E60(tab->map, &key);
                    it = t2;
                }
                func_003D7910(it.p->list, &s);
            }
        }
    }
    s->refs++;
    return s;
}
#undef Mem_Alloc /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003DD2D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003DD2D0 */
