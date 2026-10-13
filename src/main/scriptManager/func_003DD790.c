#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

struct Var3DD790 {
    int pad0[2];
    unsigned char active;
    int* ptr;
    int refs;
    int v14;
    unsigned char b18;
    int v1C;
};

struct Mgr3DD790 {
    char pad[0x28];
    int count;
    int arr[5000];
};

extern "C" {
void* Mem_Alloc(int, int, char*, int);
Var3DD790* func_003E10D0(Mgr3DD790*, char*, int);
void Script_PrintWarning(char*, char*);
Var3DD790* func_003D6190(void*, char*, int*, int*, int);
void func_003D8C30(int, Var3DD790**);
extern char D_004BD4C0[];
extern char D_004BD4F0[];
extern int D_00554F18;
}

extern "C" Var3DD790* func_003DD790(Mgr3DD790* m, char* name, int id, int* out, int t0, int t1, int t2)
{
    Var3DD790* r;
    Var3DD790* p;
    bool has;

    r = func_003E10D0(m, name, id);
    has = out != 0;
    if (r) {
        if (r->active && has && !t2)
            Script_PrintWarning(D_004BD4F0, name);
        if (!r->active || (t2 && has)) {
            r->b18 = has && t0 != 0;
            if (r->active && t2 && has) {
                r->b18 = 0;
                *out = *r->ptr;
            }
            r->active = has;
            r->ptr = out;
            r->v14 = t0;
        }
    } else {
        if (has)
            *out = 0;
        {
            AllocGuard g;
            p = (Var3DD790*)Mem_Alloc(0, 0x20, D_004BD4C0, 0xAB3);
        }
        if (p) {
            if ((unsigned int)m->count < 5000) {
                m->arr[m->count] = id;
                m->count++;
            }
            p = (Var3DD790*)func_003D6190(p, name, (int*)&m->count + m->count, out, 1);
        }
        r = p;
        p->v14 = t0;
        r->b18 = t0 != 0;
        func_003D8C30(D_00554F18, &r);
    }
    if (has)
        r->v1C = t1;
    r->refs++;
    return r;
}




