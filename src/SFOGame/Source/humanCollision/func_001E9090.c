#pragma cplusplus on
extern "C" {
typedef struct RNode RNode;
typedef struct { RNode** data; int count; } RVec;
typedef struct { RNode** p; } RIt;
struct RNode { int f0; RNode* parent; RVec children; };
extern int cTreeNode_cSkaSystemPtr_HasChildren(RNode* n);
extern int cArray_cTreeNode_cSkaSystemPtrPtr_ConstIterator_opNe(RIt* a, RIt* b);
extern RIt* func_001E9010(RIt* it);
extern RNode** func_001E9030(RIt* w);
extern void cArray_cTreeNode_cSkaSystemPtrPtr_End_void_2(RIt* out, RVec* v);
extern void func_001E9060(RIt* out, RVec* v);
extern RNode** func_001E9250(RVec* v);
extern void func_001E9270(RIt* out, RVec* self, RIt* src);
extern RNode** func_001E9280(RVec* v);
unsigned char cTreeNode_cSkaSystemPtr_IsAttached_SearchDown(RNode* n, RNode* t);
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

static inline bool HasKids(RVec* v) { return !(v->count == 0); }
static inline void Begin(RIt* it, RVec* v) { RIt t; t.p = func_001E9280(v); func_001E9270(it, v, &t); }
static inline void End(RIt* it, RVec* v) { RIt t; t.p = func_001E9250(v); func_001E9270(it, v, &t); }
static inline bool NeP(RNode** a, RNode** b) { return !(a == b); }
static inline bool Ne(RIt* a, RIt* b) { return !(a->p == b->p); }

#pragma push
#pragma opt_common_subs off
extern "C" unsigned char cTreeNode_cSkaSystemPtr_IsAttached_SearchDown(RNode* n, RNode* t) {
    if (n == t) return 1;
    if (HasKids(&n->children)) {
        bool found = 0;
        RIt it, end;
        RIt q, e;
        Begin(&it, &n->children);
        q = it;
        End(&end, &n->children);
        e = end;
        while (Ne(&q, &e)) {
            if (Check(*q.p, t)) { found = 1; break; }
            q.p++;
        }
        return found;
    }
    return 0;
}


#pragma pop

