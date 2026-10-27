/*
 * main/materialProperties: 4 files, 004092D0-00409480
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_004092D0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { int a; int b; int c; } S92Str;
typedef struct { S92Str key; unsigned char val; } S92Pair;
typedef struct { void* it; unsigned char ok; } S92Res;
extern void std_basic_string_char_char_traits_char_ctor_basicstringR(S92Str* dst, const S92Str* src);
extern void String_Dtor(S92Str* s, int del);
extern void std_make_pair_cString_uchar(S92Pair* out, S92Str* key, unsigned char val);
extern void std_tree_pair_cString_value_compare_insert_one_pairR_3(S92Res* out, void* map, S92Pair* p);
/* Inserts (name, value) into the map; returns whether it was inserted. */
unsigned char cAssocArray_cString_char_Add(void* map, const S92Str* name, unsigned char* val) {
    S92Res r;
    S92Str k;
    S92Pair p1;
    S92Pair p2;
    unsigned char ok;
    std_basic_string_char_char_traits_char_ctor_basicstringR(&k, name);
    std_make_pair_cString_uchar(&p1, &k, *val);
    std_basic_string_char_char_traits_char_ctor_basicstringR(&p2.key, &p1.key);
    p2.val = p1.val;
    std_tree_pair_cString_value_compare_insert_one_pairR_3(&r, map, &p2);
    ok = r.ok;
    String_Dtor(&p2.key, 0);
    String_Dtor(&p1.key, 0);
    String_Dtor(&k, 0);
    return ok;
}
#pragma pop /* merge_units */
/* merge_units: end func_004092D0 */

/* merge_units: begin func_00409370 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "materialProperties_types.h"

extern int std_vector_imp_cMaterialProperties_insert(MaterialVec* v, MaterialProps* pos, int n, int value);   /* insert */

/* back() */
MaterialProps* cArray_cMaterialProperties_Back(MaterialVec* v) {
    return &v->data[v->count] - 1;
}

/* push_back(v, value) */
int cArray_cMaterialProperties_PushBackActual(MaterialVec* v, int value) {
    return std_vector_imp_cMaterialProperties_insert(v, v->data + v->count, 1, value);
}

/* size() */
int cArray_cMaterialProperties_Size(MaterialVec* v) {
    return v->count;
}
#pragma pop /* merge_units */
/* merge_units: end func_00409370 */

/* merge_units: begin func_004093E0 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int std_basic_string_char_char_traits_char_assign_basicstringR();                    

int func_004093E0(int arg0, int arg1) {
    char * var_s2;
    char * var_s1;

    std_basic_string_char_char_traits_char_assign_basicstringR();
    var_s1 = (char *)(arg1 + 0xC);
    var_s2 = (char *)(arg0 + 0xC);
    do {
        std_basic_string_char_char_traits_char_assign_basicstringR(var_s2, var_s1);
        F_(var_s2, 0xC, int) = F_(var_s1, 0xC, int);
        F_(var_s2, 0x10, int) = F_(var_s1, 0x10, int);
        std_basic_string_char_char_traits_char_assign_basicstringR(var_s2 + 0x14, var_s1 + 0x14);
        std_basic_string_char_char_traits_char_assign_basicstringR(var_s2 + 0x20, var_s1 + 0x20);
        F_(var_s2, 0x2C, int) = F_(var_s1, 0x2C, int);
        F_(var_s2, 0x30, float) = F_(var_s1, 0x30, float);
        F_(var_s2, 0x34, signed char) = F_(var_s1, 0x34, signed char);
        var_s2 += 0x38;
        var_s1 += 0x38;
    } while ((void *)(var_s2) != (void *)((arg0 + 0x124)));
    return arg0;
}
#pragma pop /* merge_units */
/* merge_units: end func_004093E0 */

/* merge_units: begin func_00409480 */
#pragma push /* merge_units */
extern void std_tree_pair_cString_value_compare_find_cStringR_3(MatIter* out, int a1, int a2);

/* &v->data[i] */
MaterialProps* cArray_cMaterialProperties_opIndex(MaterialVec* v, int i) {
    return &v->data[i];
}

/* Iterator dereference. */
int* cAssocArray_cString_char_Iterator_opMul(MatIter* it) {
    return &it->node->value;
}

int cAssocArray_cString_char_Iterator_opNe(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

void cAssocArray_cString_char_End(Iter* out, Tree* t) {
    out->p = &t->header;
}

/* Forwards to std_tree_pair_cString_value_compare_find_cStringR_3 through a temporary iterator. */
void cAssocArray_cString_char_Find(MatIter* out, int a1, int a2) {
    MatIter tmp;

    std_tree_pair_cString_value_compare_find_cStringR_3(&tmp, a1, a2);
    out->node = tmp.node;
}

int* details_compressed_pair_imp_cAllocator_cMaterialProperties_int_1_ctor(int* self, int value) {
    *self = value;
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_00409480 */
