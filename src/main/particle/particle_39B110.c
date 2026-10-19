/*
 * main/particle: range (3 files, 0039B110-0039B2F0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* merge_units: begin func_0039B110 */
#pragma push /* merge_units */
typedef struct { int used; void* owner; float time; int val; } A1_Slot;
extern A1_Slot D_0053B560[4];
typedef struct { char pad[0x108]; A1_Slot* slot; } A1_Ent;
int func_0039B110(A1_Ent* e, int* out, float t) {
    int ret = 0;
    int val = 0;
    int i;
    A1_Slot* s = e->slot;
    if (s != 0 && s->owner == e) {
        s->time = t;
        val = e->slot->val;
        ret = 2;
    } else {
        for (i = 0; i < 4; i++) {
            if (D_0053B560[i].used) {
                if (D_0053B560[i].owner == 0 || t < D_0053B560[i].time + 5.0f) {
                    D_0053B560[i].owner = e;
                    D_0053B560[i].time = t;
                    e->slot = &D_0053B560[i];
                    val = D_0053B560[i].val;
                    ret = 1;
                    break;
                }
            }
        }
    }
    if (!ret) e->slot = 0;
    if (out) *out = val;
    return ret;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0039B110(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0039B110 */

/* merge_units: begin func_0039B210 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
int Mem_Alloc(int, int, char *, int);
extern char D_004BC5D0;
}
typedef struct { int p; int a; int b; int n; } E39B;
#if 0 /* merge_units */
extern "C" E39B D_0053B560[4];
#endif /* merge_units */
#define D_0053B560 ((E39B*)&D_0053B560) /* merge_units */

extern "C" void RainSnowPool_Create(int n) {
int i;
int p;
E39B *e;
int sz;
int m;
i = 0;
e = D_0053B560;
sz = n << 5;
m = n;
    do {
        {
            AllocGuard g;
            p = Mem_Alloc(0, sz, &D_004BC5D0, 0xD70);
        }
        
        e->p = p;
        e->n = m;
        e++;
    } while (++i < 4);
}
#undef D_0053B560 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0039B210(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0039B210 */

/* merge_units: begin func_0039B2F0 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int operator_delete(char **);                            
extern char D_004DFAD8;
extern void func_00399080();
extern void func_0039A000();
extern void func_003A23F0();
extern void func_003A6070();
extern void func_003A6080();
extern void * const D_004DFAF0[];
extern char D_004DFB50;
#if 0 /* merge_units */
extern char D_0053B560;
#endif /* merge_units */
#define D_0053B560 (*(char*)&D_0053B560) /* merge_units */

extern char D_0053B564;

char **func_0039B2F0(char **arg0, long long arg1) {
    int var_a0;
    char *var_v1;

    if (arg0 != NULL) {
        var_a0 = 0;
        *arg0 = &(*(char*)D_004DFAF0);
        var_v1 = &D_0053B560;
loop_2:
        if ((int)(F_(var_v1, 0x4, int)) == (int)(arg0)) {
            F_(&D_0053B564, (var_a0 * 0x10), int) = 0;
        } else {
            var_a0 += 1;
            var_v1 += 0x10;
            if (var_a0 < 4) {
                goto loop_2;
            }
        }
        if (arg0 != NULL) {
            *arg0 = &D_004DFB50;
            if (arg0 != NULL) {
                *arg0 = &D_004DFAD8;
            }
        }
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            operator_delete(arg0);
        }
    }
    return arg0;
}
void * const D_004DFAF0[8] = { (void*)0x0, (void*)0x0, (void*)func_0039B2F0, (void*)func_00399080, (void*)func_0039A000, (void*)func_003A6080, (void*)func_003A6070, (void*)func_003A23F0 };
#undef D_0053B560 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0039B2F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0039B2F0 */
