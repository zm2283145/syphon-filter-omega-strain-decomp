#pragma cplusplus on
#pragma inline_depth(8)
extern "C" {
typedef struct RNode RNode;
typedef struct { RNode** data; int count; } RVec;
typedef struct { RNode** p; } RIt;
struct RNode { int f0; RNode* parent; RVec children; };
extern int RelNode_HasChildren(RNode* n);
extern unsigned char Relation_FindDescendant(RNode* n, RNode* t);
extern int func_001E8F60(RIt* a, RIt* b);
extern RIt* func_001E8F80(RIt* it);
extern RIt func_001E8FA0(RVec* v);
extern RIt* func_001E8FC0(RIt* dst, const RIt& src);
extern RIt func_001E8FD0(RVec* v);
extern int func_001E8FE0(RVec* v);
static inline bool NotEmpty(RVec* v) { return !func_001E8FE0(v); }
extern int func_001E8FF0(RIt* a, RIt* b);
extern RIt* func_001E9010(RIt* it);
extern RNode** func_001E9030(RIt* w);
extern void func_001E9040(RIt* out, RVec* v);
extern void func_001E9060(RIt* out, RVec* v);
unsigned char Relation_SameHierarchy(RNode* n, RNode* t);
}

static inline bool Check(RNode* n, RNode* t) {
    if (n == t) return 1;
    if (RelNode_HasChildren(n)) {
        bool found = 0;
        RIt it, end;
        func_001E9060(&it, &n->children);
        func_001E9040(&end, &n->children);
        while (func_001E8FF0(&it, &end)) {
            if (Relation_FindDescendant(*func_001E9030(&it), t)) { found = 1; break; }
            func_001E9010(&it);
        }
        return found;
    }
    return 0;
}

static inline unsigned char Up2(RNode* g, RNode* t) {
    if (g->parent) return Relation_SameHierarchy(g->parent, t);
    return Relation_FindDescendant(g, t);
}

static inline unsigned char Up1(RNode* p, RNode* t) {
    if (p->parent) return Up2(p->parent, t);
    return Check(p, t);
}

static inline void ItBegin(RIt* it, RVec* v) { func_001E8FC0(it, func_001E8FD0(v)); }
static inline void ItEnd(RIt* it, RVec* v) { func_001E8FC0(it, func_001E8FA0(v)); }
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

extern "C" unsigned char Relation_SameHierarchy(RNode* n, RNode* t) {
    if (n->parent) return Up1(n->parent, t);
    return Search(n, t);
}


