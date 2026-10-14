/*
 * main/NetObjectMgr: range (8 files, 004313C0-00431660)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_004313C0 */
#pragma push /* merge_units */
typedef struct { int m0; void* m4; } R1Tree_313C0;
extern void func_0042F970(R1Tree_313C0* t, void* n);
extern void operator_delete(void* p);
R1Tree_313C0* func_004313C0(R1Tree_313C0* t, short del)
{
    if (t) {
        if (t->m4)
            func_0042F970(t, t->m4);
        if (del > 0)
            operator_delete(t);
    }
    return t;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_004313C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_004313C0 */

/* merge_units: begin func_00431420 */
#pragma push /* merge_units */
typedef struct { int m0; void* m4; } R1Tree_00431420;
extern void func_0042FC50(R1Tree_00431420* t, void* n);
R1Tree_00431420* func_00431420(R1Tree_00431420* t, short del)
{
    if (t) {
        if (t->m4)
            func_0042FC50(t, t->m4);
        if (del > 0)
            operator_delete(t);
    }
    return t;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00431420(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00431420 */

/* merge_units: begin func_00431480 */
#pragma push /* merge_units */
typedef struct { int m0; void* m4; } R1Tree_00431480;
extern void func_0042FF30(R1Tree_00431480* t, void* n);
R1Tree_00431480* func_00431480(R1Tree_00431480* t, short del)
{
    if (t) {
        if (t->m4)
            func_0042FF30(t, t->m4);
        if (del > 0)
            operator_delete(t);
    }
    return t;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00431480(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00431480 */

/* merge_units: begin func_004314E0 */
#pragma push /* merge_units */
typedef struct { int m0; void* m4; } R1Tree_004314E0;
extern void func_00430210(R1Tree_004314E0* t, void* n);
R1Tree_004314E0* func_004314E0(R1Tree_004314E0* t, short del)
{
    if (t) {
        if (t->m4)
            func_00430210(t, t->m4);
        if (del > 0)
            operator_delete(t);
    }
    return t;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_004314E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_004314E0 */

/* merge_units: begin func_00431540 */
#pragma push /* merge_units */
typedef struct { int m0; void* m4; } R1Tree_00431540;
typedef struct { R1Tree_00431540 tree; } R1Own_00431540;
#if 0 /* merge_units */
extern void func_004313C0(R1Tree_00431540* t, short del);
#endif /* merge_units */
#define func_004313C0(a0, a1) ((void)func_004313C0((void *)(a0), (a1))) /* merge_units */

R1Own_00431540* func_00431540(R1Own_00431540* o, short del)
{
    if (o) {
        R1Tree_00431540* t = &o->tree;
        if (t)
            func_004313C0(t, -1);
        if (del > 0)
            operator_delete(o);
    }
    return o;
}
#undef func_004313C0 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00431540(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00431540 */

/* merge_units: begin func_004315A0 */
#pragma push /* merge_units */
typedef struct { int m0; void* m4; } R1Tree_004315A0;
typedef struct { R1Tree_004315A0 tree; } R1Own_004315A0;
#if 0 /* merge_units */
extern void func_00431420(R1Tree_004315A0* t, short del);
#endif /* merge_units */
#define func_00431420(a0, a1) ((void)func_00431420((void *)(a0), (a1))) /* merge_units */

R1Own_004315A0* func_004315A0(R1Own_004315A0* o, short del)
{
    if (o) {
        R1Tree_004315A0* t = &o->tree;
        if (t)
            func_00431420(t, -1);
        if (del > 0)
            operator_delete(o);
    }
    return o;
}
#undef func_00431420 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_004315A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_004315A0 */

/* merge_units: begin func_00431600 */
#pragma push /* merge_units */
typedef struct { int m0; void* m4; } R1Tree_00431600;
typedef struct { R1Tree_00431600 tree; } R1Own_00431600;
#if 0 /* merge_units */
extern void func_00431480(R1Tree_00431600* t, short del);
#endif /* merge_units */
#define func_00431480(a0, a1) ((void)func_00431480((void *)(a0), (a1))) /* merge_units */

R1Own_00431600* func_00431600(R1Own_00431600* o, short del)
{
    if (o) {
        R1Tree_00431600* t = &o->tree;
        if (t)
            func_00431480(t, -1);
        if (del > 0)
            operator_delete(o);
    }
    return o;
}
#undef func_00431480 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00431600(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00431600 */

/* merge_units: begin func_00431660 */
#pragma push /* merge_units */
typedef struct { void* root; } R1Tree_31660;
typedef struct { R1Tree_31660 tree; } R1Own_31660;
extern void** func_004316E0(R1Tree_31660* t);
extern void func_004307E0(R1Tree_31660* t, void* n);
static inline void R1TreeDtor_31660(R1Tree_31660* t)
{
    if (*func_004316E0(t))
        func_004307E0(t, *func_004316E0(t));
}
R1Own_31660* func_00431660(R1Own_31660* o, short del)
{
    if (o) {
        R1Tree_31660* t = &o->tree;
        if (t)
            R1TreeDtor_31660(t);
        if (del > 0)
            operator_delete(o);
    }
    return o;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00431660(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00431660 */
