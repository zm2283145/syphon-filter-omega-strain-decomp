/*
 * SFOGame/Source/human: 3 files, 001A13F0-001A1500
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001A13F0 */
#pragma push /* merge_units */
typedef struct Msg {
    void* vtable;
    char base[0x20];
    int a;   /* 0x24 */
    char b;  /* 0x28 */
    int c;   /* 0x2C */
    char d;  /* 0x30 */
    int e;   /* 0x34 */
    char pad[8];
} Msg;
extern char D_00542B60[];
extern char D_004DA930[];
extern void cMessage_ctor_cMessageNameR(Msg* m, void* type);
extern void cMessage_dtor(Msg* m, int flags);
extern void cSkaRequestStream_AddRequest(void* ctl, int id, int a2, int a3, void* p, Msg* m1, Msg* m2, int a7, float f0, float f1);
/* Installs a motion on the actor's anim controller (self+0x34) with two empty stack messages. */
void cSkaSystem_PlayAnimation(char* self, int* motion, int a2, int a3, int a4)
{
    Msg m1;
    Msg m2;
    cMessage_ctor_cMessageNameR(&m1, D_00542B60);
    m1.vtable = D_004DA930;
    m1.a = 0; m1.b = 0; m1.c = 0; m1.d = 0; m1.e = 0;
    cMessage_ctor_cMessageNameR(&m2, D_00542B60);
    m2.vtable = D_004DA930;
    m2.a = 0; m2.b = 0; m2.c = 0; m2.d = 0; m2.e = 0;
    cSkaRequestStream_AddRequest(self + 0x34, motion[0], a2, a3, motion + 1, &m1, &m2, a4, -1.0f, 0.0f);
    m2.vtable = D_004DA930;
    cMessage_dtor(&m2, 0);
    m1.vtable = D_004DA930;
    cMessage_dtor(&m1, 0);
}
static inline void merge_flush_func_001A13F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001A13F0 */

/* merge_units: begin func_001A1500 */
#pragma push /* merge_units */
#include "types.h"

Rel* func_001A1570(Rel* r); /* gsynth: defined below */typedef struct { char pad[0xC]; unsigned char flag; } Sub;
typedef struct { unsigned char state; char pad[3]; char items[0x38]; Sub sub; } S;
extern void __construct_array(void* arr, void* ctor, void* dtor, int size, int count);
extern void cSkaAnimEvent_ctor_void(void);
extern void func_0018A210(void);
#if 0 /* merge_units */
extern void func_001A1570(Sub*);
#endif /* merge_units */
#define func_001A1570(a0) ((void)func_001A1570((Rel *)(a0))) /* merge_units */


/* Constructor: clears state, constructs 7 8-byte items, inits the sub-object and sets its flag. */
S* cSkaAnimCheckpoints_ctor_void(S* s) { Sub* sub; s->state = 0; __construct_array(s->items, cSkaAnimEvent_ctor_void, func_0018A210, 8, 7); sub = &s->sub; func_001A1570(sub); sub->flag = 1; return s; }
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001A1500(void) {}
#undef func_001A1570 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001A1500 */

/* merge_units: begin func_001A1570 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


Rel* func_001A1570(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001A1570(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001A1570 */
