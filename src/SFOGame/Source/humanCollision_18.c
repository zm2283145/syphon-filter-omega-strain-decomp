/*
 * SFOGame/Source/humanCollision: 2 files, 001E8C90-001E8CA0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001E8C90 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* cSKM_GOBJ_GetBBox(char* self) {
    return self + 96;
}
static inline void merge_flush_func_001E8C90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E8C90 */

/* merge_units: begin func_001E8CA0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)
extern "C" {
typedef struct RNode RNode;
typedef struct { RNode** data; int count; } RVec;
typedef struct { RNode** p; } RIt;
struct RNode { int f0; RNode* parent; RVec children; };
extern int cTreeNode_cSkaSystemPtr_HasChildren(RNode* n);
extern unsigned char cTreeNode_cSkaSystemPtr_IsAttached_SearchDown(RNode* n, RNode* t);
extern int func_001E8F60(RIt* a, RIt* b);
extern RIt* func_001E8F80(RIt* it);
extern RIt std_vector_cTreeNode_cSkaSystemPtrPtr_end(RVec* v);
extern RIt* func_001E8FC0(RIt* dst, const RIt& src);
extern RIt func_001E8FD0(RVec* v);
extern int func_001E8FE0(RVec* v);
static inline bool NotEmpty(RVec* v) { return !func_001E8FE0(v); }
extern int cArray_cTreeNode_cSkaSystemPtrPtr_ConstIterator_opNe(RIt* a, RIt* b);
extern RIt* func_001E9010(RIt* it);
extern RNode** func_001E9030(RIt* w);
extern void cArray_cTreeNode_cSkaSystemPtrPtr_End_void_2(RIt* out, RVec* v);
extern void func_001E9060(RIt* out, RVec* v);
unsigned char cTreeNode_cSkaSystemPtr_IsAttached(RNode* n, RNode* t);
}

static inline bool Check(RNode* n, RNode* t) {
    if (n == t) return 1;
    if (cTreeNode_cSkaSystemPtr_HasChildren(n)) {
        bool found = 0;
        RIt it, end;
        func_001E9060(&it, &n->children);
        cArray_cTreeNode_cSkaSystemPtrPtr_End_void_2(&end, &n->children);
        while (cArray_cTreeNode_cSkaSystemPtrPtr_ConstIterator_opNe(&it, &end)) {
            if (cTreeNode_cSkaSystemPtr_IsAttached_SearchDown(*func_001E9030(&it), t)) { found = 1; break; }
            func_001E9010(&it);
        }
        return found;
    }
    return 0;
}

static inline unsigned char Up2(RNode* g, RNode* t) {
    if (g->parent) return cTreeNode_cSkaSystemPtr_IsAttached(g->parent, t);
    return cTreeNode_cSkaSystemPtr_IsAttached_SearchDown(g, t);
}

static inline unsigned char Up1(RNode* p, RNode* t) {
    if (p->parent) return Up2(p->parent, t);
    return Check(p, t);
}

static inline void ItBegin(RIt* it, RVec* v) { func_001E8FC0(it, func_001E8FD0(v)); }
static inline void ItEnd(RIt* it, RVec* v) { func_001E8FC0(it, std_vector_cTreeNode_cSkaSystemPtrPtr_end(v)); }
static inline bool Search(RNode* n, RNode* t) {
    if (n == t) return 1;
    if (NotEmpty(&n->children)) {
        bool found = 0;
        RIt it, end;
        ItBegin(&it, &n->children);
        ItEnd(&end, &n->children);
        while (!func_001E8F60(&it, &end)) {
            if (Check(*it.p, t)) { found = 1; break; }
            func_001E8F80(&it);
        }
        return found;
    }
    return 0;
}

extern "C" unsigned char cTreeNode_cSkaSystemPtr_IsAttached(RNode* n, RNode* t) {
    if (n->parent) return Up1(n->parent, t);
    return Search(n, t);
}
static inline void merge_flush_func_001E8CA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E8CA0 */
