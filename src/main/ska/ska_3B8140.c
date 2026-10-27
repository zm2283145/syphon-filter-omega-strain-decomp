/*
 * main/ska: range (4 files, 003B8140-003B83D0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "tstr_types.h"
#pragma pop

/* merge_units: begin func_003B8140 */
#pragma push /* merge_units */
extern void cString4_opAssign(void* p, void* q);
extern void cSkaAnimAnchor_opAssign(void* p, void* q);
void std_fill_n_cSkaAnimAnchorListEntry_int_fill_n(char* p, int n, char* x)
{
    for (; n != 0; n--) {
        cString4_opAssign(p, x);
        cSkaAnimAnchor_opAssign(p + 0x10, x + 0x10);
        p += 0x180;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B8140(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003B8140 */

/* merge_units: begin func_003B81B0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* copy_backward over 0x180-byte elements (base part, then the member at +0x10). */
struct Elem_3B81B0 { unsigned char head[0x10]; unsigned char body[0x170]; };

extern "C" {
#if 0 /* merge_units */
void cString4_opAssign(Elem_3B81B0* dst, const Elem_3B81B0* src);
#endif /* merge_units */
#define cString4_opAssign(a0, a1) (cString4_opAssign((void *)(a0), (void *)(a1))) /* merge_units */

#if 0 /* merge_units */
void cSkaAnimAnchor_opAssign(void* dst, const void* src);
#endif /* merge_units */
#define cSkaAnimAnchor_opAssign(a0, a1) (cSkaAnimAnchor_opAssign((a0), (void *)(a1))) /* merge_units */

}

extern "C" Elem_3B81B0* std_copy_backward_cSkaAnimAnchorListEntry_copy_backward(Elem_3B81B0* first, Elem_3B81B0* last, Elem_3B81B0* dest)
{
    while (first < last) {
        --last;
        --dest;
        cString4_opAssign(dest, last);
        cSkaAnimAnchor_opAssign(dest->body, last->body);
    }
    return dest;
}
#undef cString4_opAssign /* merge_units */
#undef cSkaAnimAnchor_opAssign /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B81B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003B81B0 */

/* merge_units: begin func_003B8230 */
#pragma push /* merge_units */
#pragma cplusplus on

struct E003B8230 { int w[96]; };
struct V003B8230 { unsigned int cap; unsigned int count; E003B8230* data; };
extern "C" {
extern char D_004BCE80[];
extern char D_004BCFB8[];
void* opNew_uint_voidP(unsigned int size, void* p);
void cSkaAnimAnchorListEntry_ctor(void* dst, const E003B8230* src);
void std_swap_vectordeleterR_vectordeleterR_41(V003B8230* a, V003B8230* b);
void std_vector_deleter_cSkaAnimAnchorListEntry_dtor(V003B8230* a, int f);
}
extern "C" void std_vector_imp_cSkaAnimAnchorListEntry_reserve(V003B8230* v, unsigned int n)
{
    if (v->cap < n) {
        if (n > 0x40000) {
            Libc_Fprintf(D_00489738->stream, D_004BCE80);
            Libc_Abort();
        }
        V003B8230 tmp;
        tmp.cap = 0;
        tmp.count = 0;
        tmp.data = 0;
        tmp.data = (E003B8230*)TStr_Alloc(n * sizeof(E003B8230), D_004BCFB8, 0x5C);
        tmp.cap = n;
        E003B8230* d = tmp.data;
        E003B8230* s = v->data;
        E003B8230* e = s + v->count;
        for (; s < e; s++, d++) {
            void* o = opNew_uint_voidP(sizeof(E003B8230), d);
            if (o) cSkaAnimAnchorListEntry_ctor(o, s);
            tmp.count++;
        }
        std_swap_vectordeleterR_vectordeleterR_41(&tmp, v);
        std_vector_deleter_cSkaAnimAnchorListEntry_dtor(&tmp, -1);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B8230(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003B8230 */

/* merge_units: begin func_003B83D0 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct Node_3B83D0 { struct Node_3B83D0* left; struct Node_3B83D0* right; int pad[2]; char name[0x30]; } Node_3B83D0;
typedef struct { int pad; Node_3B83D0* root; } Tree_3B83D0;
typedef struct { Node_3B83D0* node; bool inserted; } Res_3B83D0;
extern "C" {
int Libc_Memcmp(const char* a, const char* b, int n);
Node_3B83D0* std_tree_pair_cString16N_value_compare_cAllocator_pair_insert_node_at_nodeP_bool_bool_pairR(Tree_3B83D0* t, Node_3B83D0* y, bool comp, bool leftmost, const char* key);
static bool D_00493518 = true;
extern const bool D_00493520;
}
static inline bool Less_3B83D0(const char* a, const char* b)
{
    return !(a[0] == 0 && b[0] == 0) && Libc_Memcmp(a, b, 0x30) < 0;
}
extern "C" void std_tree_pair_cString16N_value_compare_cAllocator_pair_insert_one_pairR(Res_3B83D0* out, Tree_3B83D0* t, const char* key)
{
    Node_3B83D0* lb = 0;
    Node_3B83D0* y = (Node_3B83D0*)&t->root;
    Node_3B83D0* x;
    bool comp = true;
    bool leftmost = comp;
    x = t->root;
    while (x != 0) {
        y = x;
        if (Less_3B83D0(key, x->name)) {
            x = x->left;
            comp = true;
        } else {
            lb = x;
            x = x->right;
            comp = false;
            leftmost = false;
        }
    }
    if (lb == 0 || Less_3B83D0(lb->name, key)) {
        out->node = std_tree_pair_cString16N_value_compare_cAllocator_pair_insert_node_at_nodeP_bool_bool_pairR(t, y, comp, leftmost, key);
        out->inserted = D_00493518;
    } else {
        out->node = lb;
        out->inserted = D_00493520;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B83D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003B83D0 */
