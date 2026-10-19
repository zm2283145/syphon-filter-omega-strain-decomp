#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"
#include "alloc_guard.h"
/* Global_RemoveArray: unlink a script array from the global array list and free it */
struct It_68740 { void* n; };
extern "C" {
void Mem_Free(int pool, void* p, char* file, int line);
extern char D_004A82B8[];
}
/* script array: frees its data buffer */
struct Arr_68740 {
    void* data;
    void Destroy() { void* d = data; AllocGuard g2; Mem_Free(0, d, D_004A82B8, 0x12D); }
};
extern "C" {
extern char D_004F83E0[];
void func_002689E0(It_68740* it);
void func_002689D0(It_68740* out, void* l);
void func_002689C0(It_68740* d, It_68740* s);
void func_00268980(It_68740* out, void* l);
int func_00268960(It_68740* a, It_68740* b);
Arr_68740** func_002689B0(It_68740* it);
void func_00268990(It_68740* it);
void func_00268950(It_68740* d, It_68740* s);
void func_00268690(It_68740* out, void* l);
void func_00268680(It_68740* d, It_68740* s);
void func_0015AF40(It_68740* out, It_68740* in);
void List_Erase(It_68740* out, void* l, It_68740* pos);
}
static inline void Find(It_68740* out, void* l, Arr_68740* a)
{
    It_68740 it;
    It_68740 t;
    It_68740 e;
    func_002689E0(&it);
    func_002689D0(&t, l);
    func_002689C0(&it, &t);
    while (func_00268980(&e, l), func_00268960(&it, &e)) {
        if (*func_002689B0(&it) == a) break;
        func_00268990(&it);
    }
    func_00268950(out, &it);
}
static inline void EndL(It_68740* out, void* l) { It_68740 e2; func_00268690(&e2, l); func_00268680(out, &e2); }
static inline void EraseAt(void* l, It_68740* c) { It_68740 o; It_68740 p; func_0015AF40(&p, c); List_Erase(&o, l, &p); }
/* pass-through layers: keep the find/end iterators below the erase temporaries (slot order) */
static inline void Find2(It_68740* out, void* l, Arr_68740* a) { Find(out, l, a); }
static inline void EndL2(It_68740* out, void* l) { EndL(out, l); }
extern "C" void Global_RemoveArray(Arr_68740* a)
{
    if (a) {
        It_68740 r;
        It_68740 e3;
        Find2(&r, D_004F83E0, a);
        EndL2(&e3, D_004F83E0);
        if (r.n != e3.n) {
            It_68740 c;
            c.n = r.n;
            EraseAt(D_004F83E0, &c);
        }
        {
            AllocGuard g;
            if (a) a->Destroy();
            Mem_Free(0, a, D_004A82B8, 0x1AD);
        }
    }
}
