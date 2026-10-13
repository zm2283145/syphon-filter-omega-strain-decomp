#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
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



