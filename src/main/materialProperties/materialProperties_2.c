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
extern void String_CopyCtor(S92Str* dst, const S92Str* src);
extern void String_Dtor(S92Str* s, int del);
extern void func_004089B0(S92Pair* out, S92Str* key, unsigned char val);
extern void func_0040A880(S92Res* out, void* map, S92Pair* p);
/* Inserts (name, value) into the map; returns whether it was inserted. */
unsigned char func_004092D0(void* map, const S92Str* name, unsigned char* val) {
    S92Res r;
    S92Str k;
    S92Pair p1;
    S92Pair p2;
    unsigned char ok;
    String_CopyCtor(&k, name);
    func_004089B0(&p1, &k, *val);
    String_CopyCtor(&p2.key, &p1.key);
    p2.val = p1.val;
    func_0040A880(&r, map, &p2);
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

extern int func_00409940(MaterialVec* v, MaterialProps* pos, int n, int value);   /* insert */

/* back() */
MaterialProps* MaterialVec_Back(MaterialVec* v) {
    return &v->data[v->count] - 1;
}

/* push_back(v, value) */
int MaterialVec_PushBack(MaterialVec* v, int value) {
    return func_00409940(v, v->data + v->count, 1, value);
}

/* size() */
int func_004093D0(MaterialVec* v) {
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
int String_AssignString();                    

int func_004093E0(int arg0, int arg1) {
    char * var_s2;
    char * var_s1;

    String_AssignString();
    var_s1 = (char *)(arg1 + 0xC);
    var_s2 = (char *)(arg0 + 0xC);
    do {
        String_AssignString(var_s2, var_s1);
        F_(var_s2, 0xC, int) = F_(var_s1, 0xC, int);
        F_(var_s2, 0x10, int) = F_(var_s1, 0x10, int);
        String_AssignString(var_s2 + 0x14, var_s1 + 0x14);
        String_AssignString(var_s2 + 0x20, var_s1 + 0x20);
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
extern void func_004097A0(MatIter* out, int a1, int a2);

/* &v->data[i] */
MaterialProps* func_00409480(MaterialVec* v, int i) {
    return &v->data[i];
}

/* Iterator dereference. */
int* func_004094A0(MatIter* it) {
    return &it->node->value;
}

int func_004094B0(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

void func_004094D0(Iter* out, Tree* t) {
    out->p = &t->header;
}

/* Forwards to func_004097A0 through a temporary iterator. */
void func_004094E0(MatIter* out, int a1, int a2) {
    MatIter tmp;

    func_004097A0(&tmp, a1, a2);
    out->node = tmp.node;
}

int* func_00409510(int* self, int value) {
    *self = value;
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_00409480 */
