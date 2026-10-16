/*
 * main/scriptBase: range (5 files, 003D8E10-003D8EF0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "scriptBase_types.h"

/* merge_units: begin func_003D8E10 */
#pragma push /* merge_units */
Rel* func_003D8E60(Rel* r); /* gsynth: defined below */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern int PtrVec_Insert(PtrVec* v, int* pos, int n, int value);
#if 0 /* merge_units */
extern OwnedVec* func_003D8E60(OwnedVec* v);
#endif /* merge_units */
#define func_003D8E60(a0) ((OwnedVec *)func_003D8E60((void *)(a0))) /* merge_units */


/* push_back: inserts one value at the end. */
int func_003D8E10(PtrVec* v, int value) {
    return PtrVec_Insert(v, v->data + v->count, 1, value);
}

OwnedVec* func_003D8E30(OwnedVec* v) {
    func_003D8E60(v);
    v->unk0C = 1;
    return v;
}
#undef func_003D8E60 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003D8E10(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003D8E10 */

/* merge_units: begin func_003D8E60 */
#pragma push /* merge_units */
Rel* func_003D8E60(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003D8E60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003D8E60 */

/* merge_units: begin func_003D8E80 */
#pragma push /* merge_units */
Rel* func_003D8ED0(Rel* r); /* gsynth: defined below */
typedef struct ObjC0 {
    char pad[0xC];
    signed char flag;
} ObjC0;

#if 0 /* merge_units */
extern void func_003D8ED0(ObjC0*);
#endif /* merge_units */
#define func_003D8ED0(a0) ((void)func_003D8ED0((void *)(a0))) /* merge_units */

extern void PtrVec_Reserve(ObjC0*, int);

/* Constructor: base init, then PtrVec_Reserve(self, *src) and flag byte at +0xC. */
ObjC0* func_003D8E80(ObjC0* o, int* src, int flag) {
    func_003D8ED0(o);
    PtrVec_Reserve(o, *src);
    o->flag = flag;
    return o;
}
#undef func_003D8ED0 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003D8E80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003D8E80 */

/* merge_units: begin func_003D8ED0 */
#pragma push /* merge_units */
Rel* func_003D8ED0(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003D8ED0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003D8ED0 */

/* merge_units: begin func_003D8EF0 */
#pragma push /* merge_units */
typedef struct { char pad[0xC]; unsigned char flag; } Obj003D8EF0;
extern void func_003D8F40(Obj003D8EF0* obj, int* src, unsigned char flag);
#if 0 /* merge_units */
extern void PtrVec_Reserve(Obj003D8EF0* obj, int value);
#endif /* merge_units */
#define PtrVec_Reserve(a0, a1) (PtrVec_Reserve((void *)(a0), (a1))) /* merge_units */

/* Construct from src and flag; returns obj. */
Obj003D8EF0* func_003D8EF0(Obj003D8EF0* obj, int* src, unsigned char flag)
{
    func_003D8F40(obj, src, flag);
    PtrVec_Reserve(obj, *src);
    obj->flag = flag;
    return obj;
}
#undef PtrVec_Reserve /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003D8EF0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003D8EF0 */
