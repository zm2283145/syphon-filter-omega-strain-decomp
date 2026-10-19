/*
 * main/scriptManager: range (3 files, 003E00E0-003E02F0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int Mem_Free();

/* merge_units: begin func_003E00E0 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { void* buf; } S3E00;
typedef struct { char pad[0x18]; char vec[4]; int n; S3E00** items; } M3E00;
extern "C" {
extern void PtrVector_Resize(char*, int, int*);
extern char D_004BD4C0[];
}
#pragma opt_strength_reduction off
extern "C" void ScriptStr_Release(M3E00* m, S3E00* s) {
    int z[1];
    void* buf = s->buf;
    int i, n;
    if (buf) {
        AllocGuard g;
        Mem_Free(0, buf, "scriptManager.hh", 0x90);
    }
    n = m->n - 1;
    for (i = 0; n >= i; i++) {
        if (m->items[i] == s) {
            m->items[i] = m->items[n];
            n--;
        }
    }
    z[0] = 0;
    PtrVector_Resize(m->vec, n + 1, z);
    {
        AllocGuard g;
        Mem_Free(0, s, D_004BD4C0, 0x683);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003E00E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003E00E0 */

/* merge_units: begin func_003E0270 */
#pragma push /* merge_units */
typedef struct { void* key; } E0270;
typedef struct { char pad[0x1C]; int count; E0270** items; } T0270;
static inline int IsZ_0270(int v) { return (v != 0) ^ 1; }
#pragma opt_rotateloops off
#pragma opt_strength_reduction off
E0270* func_003E0270(T0270* t, void* key)
{
    int i;
    int n = t->count;
    E0270** items = t->items;
    for (i = 0; !IsZ_0270(((int*)items)[i]) && i < n; i++) {
        if (items[i]->key != key) continue;
        return ((volatile T0270*)t)->items[i];
    }
    return 0;
}
#pragma opt_rotateloops reset
#pragma opt_strength_reduction reset
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003E0270(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003E0270 */

/* merge_units: begin func_003E02F0 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
#if 0 /* merge_units */
int Alloc_Lock(int);
#endif /* merge_units */
#define Alloc_Lock(a0) (Alloc_Lock((a0))) /* merge_units */
                                    
#if 0 /* merge_units */
int Alloc_Unlock(int);
#endif /* merge_units */
#define Alloc_Unlock(a0) (Alloc_Unlock((a0))) /* merge_units */
                                  
int *Mem_Alloc(int, int, char *, int);                       
int ScriptStr_AppendTracking(char * , int **);         
int Str_Duplicate(int);                               
#if 0 /* merge_units */
extern char D_004BD4C0;
#endif /* merge_units */
#define D_004BD4C0 (*(char*)&D_004BD4C0) /* merge_units */

extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;

int ScriptStr_CopyTracked(char * arg0, int arg1) {
    int temp_s0;
    int *sp4C;
    int *temp_s2;

    if (g_ProfileLockEnabled != 0) {
        Alloc_Lock(9);
    }
    g_ProfileLockDepth += 1;
    temp_s2 = Mem_Alloc(0, 0xC, &D_004BD4C0, 0x66E);
    if (g_ProfileLockEnabled != 0) {
        Alloc_Unlock(9);
    }
    g_ProfileLockDepth -= 1;
    if (temp_s2 != NULL) {
        temp_s0 = F_(arg0, 0x4E7C, int);
        F_(temp_s2, 0x0, int) = Str_Duplicate(arg1);
        F_(temp_s2, 0x4, int) = 0;
        F_(temp_s2, 0x8, int) = temp_s0;
    }
    sp4C = temp_s2;
    ScriptStr_AppendTracking(arg0 + 0x18, &sp4C);
    return *sp4C;
}
#undef Alloc_Lock /* merge_units */
#undef Alloc_Unlock /* merge_units */
#undef D_004BD4C0 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003E02F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003E02F0 */
