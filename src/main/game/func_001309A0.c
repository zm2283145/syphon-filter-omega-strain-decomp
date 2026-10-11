#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct N_09A0 { char pad[0x18]; void* val; };
struct It_09A0 { N_09A0* n; It_09A0() {} };
struct E_09A0 { int a; E_09A0() {} };
struct S_09A0 { char pad[0x70]; char map[4]; };
extern "C" {
extern char D_0049A890[];
void Mem_Free(int pool, void* allocation, char* file, int line);
void func_003B62E0(void* p, int flags);
It_09A0 func_00130B00(void* map);
void func_00130AF0(E_09A0* out, void* map);
void func_00130AE0(It_09A0* out, E_09A0* e);
void Tree_Successor(It_09A0* it);
void Map_Clear_13A420(void* map);
}
static inline void End_09A0(S_09A0* self, It_09A0* out) { E_09A0 e; func_00130AF0(&e, self->map); func_00130AE0(out, &e); }
static inline int Ne_09A0(It_09A0* a, It_09A0* b) { return (a->n == b->n) ^ 1; }
extern "C" void func_001309A0(S_09A0* self)
{
    It_09A0 it;
    It_09A0 end;
    It_09A0 tb = func_00130B00(self->map);
    it = tb;
    while (End_09A0(self, &end), Ne_09A0(&it, &end)) {
        void* v = it.n->val;
        {
            AllocGuard g;
            func_003B62E0(v, -1);
            Mem_Free(0, v, D_0049A890, 0x962);
        }
        Tree_Successor(&it);
    }
    Map_Clear_13A420(self->map);
}