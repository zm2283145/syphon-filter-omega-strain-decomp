#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct N_09A0 { char pad[0x18]; void* val; };
struct It_09A0 { N_09A0* n; It_09A0() {} };
struct E_09A0 { int a; E_09A0() {} };
struct S_09A0 { char pad[0x70]; char map[4]; };
extern "C" {
extern char D_0049A890[];
void cMemMan_Deallocate(int pool, void* allocation, char* file, int line);
void cSkaAnimationSet_dtor(void* p, int flags);
It_09A0 std_tree_pair_cString_value_compare_begin(void* map);
void std_map_cString_cSkaAnimationSetPtr_end(E_09A0* out, void* map);
void cAssocArray_cString_cSkaAnimationSetPtr_Iterator_ctor(It_09A0* out, E_09A0* e);
void std_red_black_tree_1_increment(It_09A0* it);
void std_tree_pair_cString_value_compare_clear(void* map);
}
static inline void End_09A0(S_09A0* self, It_09A0* out) { E_09A0 e; std_map_cString_cSkaAnimationSetPtr_end(&e, self->map); cAssocArray_cString_cSkaAnimationSetPtr_Iterator_ctor(out, &e); }
static inline int Ne_09A0(It_09A0* a, It_09A0* b) { return (a->n == b->n) ^ 1; }
extern "C" void cGameSystem_DestroyAnimationSets(S_09A0* self)
{
    It_09A0 it;
    It_09A0 end;
    It_09A0 tb = std_tree_pair_cString_value_compare_begin(self->map);
    it = tb;
    while (End_09A0(self, &end), Ne_09A0(&it, &end)) {
        void* v = it.n->val;
        {
            AllocGuard g;
            cSkaAnimationSet_dtor(v, -1);
            cMemMan_Deallocate(0, v, D_0049A890, 0x962);
        }
        std_red_black_tree_1_increment(&it);
    }
    std_tree_pair_cString_value_compare_clear(self->map);
}