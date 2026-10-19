/*
 * main/scriptBase: 3 files, 003D7370-003D7510
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003D7370 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int* func_003D7370(PtrVec* v, int i) {
    return v->data + i;
}
#pragma pop /* merge_units */
/* merge_units: end func_003D7370 */

/* merge_units: begin func_003D7380 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(10)
extern "C" {
void PtrVector_Resize(void* v, int n, int* val);
}
typedef struct { int pad0; int count; int* data; unsigned char owns; } V7380;
typedef struct { int x0; int x4; V7380 vec; int x18; } O7380;
extern "C" {
void func_003D6010(V7380* v);
}
static inline int* At(V7380* v, unsigned int i) { return &v->data[i]; }
extern "C" O7380* func_003D7380(O7380* o, int x0, int x4, int x18, int n, int* src)
{
    V7380* v; int i; int zero;
    v = &o->vec;
    func_003D6010(v);
    v->owns = 1;
    o->x0 = x0;
    o->x4 = x4;
    o->x18 = x18;
    zero = 0;
    PtrVector_Resize(v, n, &zero);
    for (i = 0; i < n; i++) *At(&o->vec, i) = src[i];
    return o;
}
#pragma pop /* merge_units */
/* merge_units: end func_003D7380 */

/* merge_units: begin func_003D7510 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int *ScriptEnum_GetById();                          
int *ScriptType_GetRecord(int);                            
extern char D_004BD378[];
extern char D_004BD380[];
extern char D_004BD388[];
extern char D_004BD390[];
extern char D_004BD398[];
extern char D_004BD3A0[];
extern char D_004BD3A8[];
static void * const dat_004938B0[8] = { (void*)0x0, (void*)D_004BD378, (void*)D_004BD380, (void*)D_004BD388, (void*)D_004BD390, (void*)D_004BD398, (void*)D_004BD3A0, (void*)D_004BD3A8 };

int func_003D7510(int arg0) {
    int var_a0;

    var_a0 = arg0;
    if (var_a0 < 0xA) {
        return F_(&(*(char*)dat_004938B0), (var_a0 * 4), int);
    }
    if (var_a0 < 0x64) {
        return *ScriptEnum_GetById();
    }
    if (var_a0 >= 0x13EC) {
        var_a0 -= 0x1388;
    }
    return *ScriptType_GetRecord(var_a0);
}
#pragma pop /* merge_units */
/* merge_units: end func_003D7510 */
