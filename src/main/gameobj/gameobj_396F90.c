/*
 * main/gameobj: range (4 files, 00396F90-00397170)
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
#include "trivial_dtor.h"
#pragma pop

/* merge_units: begin func_00396F90 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR_SHALLOW(std_vector_imp_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_1_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_00396F90 */

/* merge_units: begin func_00397080 */
#pragma push /* merge_units */
#pragma opt_common_subs off
#pragma bool off
typedef struct { char pad0[0xB0]; int x4; } E_1A07F0;
typedef struct { E_1A07F0** p; } It_1A07F0;
typedef struct { char pad[0xB4]; int vec; int xC; } O_1A07F0;
extern E_1A07F0** std_vector_imp_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_1_begin(int* v);
extern E_1A07F0** std_vector_imp_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_1_end(int* v);
extern void std_vector_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_pointer2iterator(It_1A07F0* out, int* v, E_1A07F0*** p);
static inline int Eq_1A07F0(E_1A07F0** a, E_1A07F0** b) { return a == b; }
void cTreeNode_cSkaAnimAnchor_TreeNodeData_DetachChildren(O_1A07F0* self)
{
    It_1A07F0 b;
    It_1A07F0 e;
    E_1A07F0** t0;
    E_1A07F0** t1;
    E_1A07F0** it;
    E_1A07F0** end;
    t0 = std_vector_imp_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_1_begin(&self->vec);
    std_vector_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_pointer2iterator(&b, &self->vec, &t0);
    it = b.p;
    t1 = std_vector_imp_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_1_end(&self->vec);
    std_vector_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_pointer2iterator(&e, &self->vec, &t1);
    end = e.p;
    while (Eq_1A07F0(it, end) ^ 1) {
        (*it)->x4 = 0;
        it++;
    }
    self->xC = 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00397080(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00397080 */

/* merge_units: begin func_00397120 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(cArray_FixedSize_cVector_4_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_00397120 */

/* merge_units: begin func_00397170 */
#pragma push /* merge_units */
#pragma cplusplus on

typedef struct { char d[0xF8]; } T_397170;
struct MapIt_397170 {
    T_397170** node;
    T_397170** mapBegin;
    T_397170** split;
    T_397170** mapEnd;
    MapIt_397170() {}
    MapIt_397170(const MapIt_397170& o) : node(o.node), mapBegin(o.mapBegin), split(o.split), mapEnd(o.mapEnd) {}
    void inc() { if (++node == mapEnd) node = mapBegin; }
};
struct It_397170 {
    MapIt_397170 m;
    T_397170* cur;
    T_397170* end;
};

extern "C" {
extern unsigned int D_004BC478;
void func_00397400(T_397170* p, int flags);
}

static inline const int& imin_397170(const int& a, const int& b) { return b < a ? b : a; }
static inline const unsigned int& umin_397170(const unsigned int& a, const unsigned int& b) { return b < a ? b : a; }

extern "C" void std_deque_deleter_cSkaSystem_Request_destroy(void* self, It_397170* first, It_397170* last)
{
    if (first->cur != last->cur) {
        unsigned int n;

        T_397170* p;
        T_397170* e;
        T_397170** sp = last->m.split;
        int nodes = last->m.node - first->m.node;
        if (!(last->m.node < sp)) {
            if (first->m.node < sp)
                nodes -= last->m.mapEnd - last->m.mapBegin;
        } else if (!(first->m.node < sp)) {
            nodes += last->m.mapEnd - last->m.mapBegin;
        }
        n = nodes * 8 - (last->end - last->cur) + (first->end - first->cur);
        MapIt_397170 mi(first->m); T_397170*** pe = &mi.mapEnd; T_397170*** pb = &mi.mapBegin;
        p = first->cur;
        e = p + imin_397170(n, first->end - p);
        for (;;) {
            n -= e - p;
            for (; p < e; p++) func_00397400(p, -1);
            if (n == 0) break;
            if (++mi.node == *pe) mi.node = *pb;
            p = *mi.node;
            e = p + umin_397170(n, D_004BC478);
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00397170(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00397170 */
