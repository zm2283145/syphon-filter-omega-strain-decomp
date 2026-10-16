/*
 * main/path: range (2 files, 001642E0-00164330)
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

/* merge_units: begin func_001642E0 */
#pragma push /* merge_units */
extern int List_Erase(int, int, int);

int NpcRouteMgr_TakeFreeRequest(int a0) {
    int loc[2];
    int a1, a2, s0, v0;
    int cond;

    v0 = *(int*)((char*)a0 + 44);
    cond = v0 <= 0;
    s0 = 0;
    if (cond) goto L00164318;
    v0 = *(int*)((char*)a0 + 52);
    a1 = a0 + 44;
    a2 = (int)loc;
    s0 = *(int*)((char*)v0 + 8);
    a0 = (int)((char*)loc + 4);
    *(int*)(char*)loc = v0;
    v0 = List_Erase(a0, a1, a2);
L00164318:;
    v0 = s0;
    goto ret;
ret:
    return v0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001642E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001642E0 */

/* merge_units: begin func_00164330 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_propagation off
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


extern "C" {
int ObjectList_EraseRange(...); 
int NpcRoute_Release(...);                                 
int func_00164850(...);                            
extern int D_0049C1B8;
extern int D_004EE118;
extern unsigned char D_00533880;
}
static inline int Identity(int p){return p;}
#define DECLS int sp48; int sp44; int sp40;
static inline void clr0(char *arg0) { int sp48; int sp44; int sp40; sp40 = (int)arg0 + 0x30; sp44 = F_(arg0, 0x34, int); ObjectList_EraseRange(&sp48, arg0 + 0x2C, &sp44, &sp40); }
static inline void fr0(int p) { AllocGuard g; Mem_Free(0, p, &D_0049C1B8, 0x41); }
extern "C" void func_00164330(char *arg0) {
    int temp_s0;
    int temp_s1;

    NpcRoute_Release(arg0, 0);
    temp_s1 = F_(arg0, 0x38, int);
    {
        AllocGuard g;
    Mem_Free(0, temp_s1, &D_0049C1B8, 0x41);
    }
    { int sp48; int sp44; int sp40; sp40 = Identity((int)(arg0 + 0x30)); sp44 = F_(arg0, 0x34, int); ObjectList_EraseRange(&sp48, arg0 + 0x2C, &sp44, &sp40); }
    temp_s0 = D_004EE118;
    if (temp_s0 != 0) {
        {
            AllocGuard g;
        if ((temp_s0 != 0) && (temp_s0 != 0) && (temp_s0 != 0)) {
            func_00164850(temp_s0, 0);
        }
        Mem_Free(0, temp_s0, &D_0049C1B8, 0xB2E);
        }
        D_004EE118 = 0;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00164330(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00164330 */
