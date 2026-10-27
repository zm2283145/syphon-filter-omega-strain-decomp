/*
 * Libs/SFOLib/Source/ska: 1 file, 003B62E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003B62E0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

/* cSkaAnimationSet_dtor: skeleton-set destructor (ska.cc): delete the owned objects of the vector at
 * +0x34, free the map values at +0x44 and the buffers of the vector at +0x14, run the member
 * destructors and free the object when the delete flag is positive. */

struct Obj { virtual void Destroy(int flag); };
struct It { void* p; };
struct Raw { void* p; };
struct MapNode { char pad[0x30]; void* value; };

struct SkSet {
    int x0;
    char v4[0x10];
    char v14[0x10];
    char v24[0x10];
    char v34[0x10];
    char m44[0x10];
};

extern "C" {
extern char D_004BCD70[];
void cMemMan_Deallocate(int pool, void* p, char* file, int line);
void operator_delete(void* p);
void* std_vector_imp_cSkaNodePtr_1_begin(void* v);
void std_vector_cSkaNodePtr_pointer2iterator(It* out, void* v, void* const& r);
Raw std_vector_cSkaNodePtr_end(void* v);
void cArray_cSkaNodePtr_Iterator_ctor(It* out, const Raw& r);
void std_tree_pair_cString16N_value_compare_cAllocator_pair_begin(It* out, void* m);
void std_tree_pair_cString16N_value_compare_cAllocator_pair_end(It* out, void* m);
void std_red_black_tree_1_increment(It* it);
void* std_vector_imp_charPtr_1_begin(void* v);
void* std_vector_imp_charPtr_1_end(void* v);
void std_vector_charPtr_pointer2iterator(It* out, void* v, void* const& r);
void std_map_cString16N_2_cSkaAnimationBlendPtr_cAllocator_pair_dtor(void* p, int flag);
void std_vector_cSkaNodePtr_dtor(void* p, int flag);
void std_map_cString16N_3_int_cAllocator_pair_dtor(void* p, int flag);
void std_vector_charPtr_dtor_void(void* p, int flag);
void std_vector_deleter_cString4_dtor(void* p, int flag);
SkSet* cSkaAnimationSet_dtor(SkSet* s, short flag);
}

static inline Raw MkRaw(void* p) { Raw r; r.p = p; return r; }
static inline int Eq(void* a, void* b) { return a == b; }

#pragma bool off
SkSet* cSkaAnimationSet_dtor(SkSet* s, short flag)
{
    It itB;
    if (s) {
        {
            It e;
            It b;
            Obj* o;
            Obj** it;
            std_vector_cSkaNodePtr_pointer2iterator(&b, s->v34, std_vector_imp_cSkaNodePtr_1_begin(s->v34));
            it = (Obj**)b.p;
            while ((cArray_cSkaNodePtr_Iterator_ctor(&e, std_vector_cSkaNodePtr_end(s->v34)), Eq(it, e.p) ^ 1)) {
                o = *it;
                {
                    AllocGuard g;
                    o->Destroy(-1);
                    cMemMan_Deallocate(0, o, D_004BCD70, 0x35);
                }
                it++;
            }
        }
        {
            It b;
            It e;
            MapNode* end;
            std_tree_pair_cString16N_value_compare_cAllocator_pair_begin(&b, s->m44);
            itB = b;
            std_tree_pair_cString16N_value_compare_cAllocator_pair_end(&e, s->m44);
            end = (MapNode*)e.p;
            while (Eq(itB.p, end) ^ 1) {
                void* v = ((MapNode*)itB.p)->value;
                {
                    AllocGuard g;
                    cMemMan_Deallocate(0, v, D_004BCD70, 0x42);
                }
                std_red_black_tree_1_increment(&itB);
            }
        }
        {
            It b;
            It e;
            void** it;
            void** end;
            std_vector_charPtr_pointer2iterator(&b, s->v14, std_vector_imp_charPtr_1_begin(s->v14));
            it = (void**)b.p;
            std_vector_charPtr_pointer2iterator(&e, s->v14, std_vector_imp_charPtr_1_end(s->v14));
            end = (void**)e.p;
            /* volatile: retail re-reads e.p for the entry test (end is loaded in the delay slot) */
            if (Eq(it, *(void** volatile*)&e.p) ^ 1) {
                do {
                    void* v = *it;
                    {
                        AllocGuard g;
                        cMemMan_Deallocate(0, v, D_004BCD70, 0x4F);
                    }
                    it++;
                } while (Eq(it, end) ^ 1);
            }
        }
        if (s->m44) std_map_cString16N_2_cSkaAnimationBlendPtr_cAllocator_pair_dtor(s->m44, -1);
        if (s->v34) std_vector_cSkaNodePtr_dtor(s->v34, -1);
        if (s->v24) std_map_cString16N_3_int_cAllocator_pair_dtor(s->v24, -1);
        if (s->v14) std_vector_charPtr_dtor_void(s->v14, -1);
        { void* p = s->v4; if (p) if (p) if (p) std_vector_deleter_cString4_dtor(p, 0); }
        if (flag > 0) operator_delete(s);
    }
    return s;
}
static inline void merge_flush_func_003B62E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B62E0 */
