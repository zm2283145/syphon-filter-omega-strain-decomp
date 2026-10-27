/*
 * SFOGame/Source/NetGeneratorCreate: 2 files, 002D1290-002D1360
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002D1290 */
#pragma push /* merge_units */
#pragma cplusplus on
struct V4 {
    float x, y, z, w;
    V4() {}
    V4& operator=(const V4& o) { V4* d = this; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(&o) : "memory"); return *this; }
};
struct P3 : V4 { P3(float a, float b, float c) { x = a; y = b; z = c; } };
struct P4 : V4 { P4(float a, float b, float c) { x = a; y = b; z = c; w = 1.0f; } };
struct Src2D1290 { char p0[8]; int a; int b; int c; float px, py, pz; float qx, qy, qz; int d; int e; };
struct Evt2D1290 { void* vt; char p4[0x2C]; V4 v30; V4 v40; int a50, a54, a58, a5C, a60; };
extern "C" {
extern char D_0051F058[];
extern char D_004DE240[];
void cMessage_ctor_cMessageNameR(Evt2D1290* e, void* type);
Evt2D1290* cNetGeneratorCreateMsg_ctor(Evt2D1290* self, Src2D1290* s);
}
extern "C" Evt2D1290* cNetGeneratorCreateMsg_ctor(Evt2D1290* self, Src2D1290* s) {
    cMessage_ctor_cMessageNameR(self, D_0051F058);
    self->vt = D_004DE240;
    self->a50 = s->a;
    self->a54 = s->b;
    self->a58 = s->c;
    self->v40 = P3(s->px, s->py, s->pz);
    self->v30 = P4(s->qx, s->qy, s->qz);
    self->a5C = s->d;
    self->a60 = s->e;
    return self;
}
static inline void merge_flush_func_002D1290(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D1290 */

/* merge_units: begin func_002D1360 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { int key; int recv; int id; unsigned char flag; int a; int b; } C3NrPair;
typedef struct C3NrNode { struct C3NrNode* left; struct C3NrNode* right; int pad; C3NrPair v; } C3NrNode;
typedef struct { int pad; C3NrNode* root; } C3NrMap;
extern C3NrNode* std_tree_pair_int_value_compare_insert_node_at_nodeP_bool_bool_pairR(C3NrMap* m, C3NrNode* parent, unsigned char left, unsigned char leftmost, C3NrPair* v);
C3NrPair* std_tree_pair_int_value_compare_find_or_insert(C3NrMap* m, int* key)
{
    C3NrNode* cand = 0;
    C3NrNode* parent = (C3NrNode*)&m->root;
    C3NrNode* x = m->root;
    unsigned char left = 1;
    unsigned char leftmost = left;
    while (x != 0) {
        parent = x;
        if (*key < x->v.key) {
            x = x->left;
            left = 1;
        } else {
            cand = x;
            x = x->right;
            left = 0;
            leftmost = 0;
        }
    }
    if (cand == 0 || cand->v.key < *key) {
        C3NrPair p;
        p.key = *key;
        p.recv = 0;
        p.id = -1;
        p.flag = 0;
        p.a = 0;
        p.b = 0;
        return &std_tree_pair_int_value_compare_insert_node_at_nodeP_bool_bool_pairR(m, parent, left, leftmost, &p)->v;
    }
    return &cand->v;
}
static inline void merge_flush_func_002D1360(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D1360 */
