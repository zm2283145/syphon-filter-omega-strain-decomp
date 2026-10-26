/*
 * main/scriptBase: 4 files, 003D7590-003D76D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003D7590 */
#pragma push /* merge_units */
#include "types.h"

extern char D_00554F28[];

int ScriptType_GetRecord(int a0) {
    int v0, v1;
    int cond;

    v0 = a0 < 5100;
    cond = v0 != 0;
    if (cond) goto L003D75A0;
    a0 = a0 + -5000;
L003D75A0:;
    v0 = a0 + -100;
    v1 = v0 << 2;
    v0 = *(int*)(char*)D_00554F28;
    v0 = *(int*)((char*)v0 + 8);
    v0 = v0 + v1;
    v0 = *(int*)(char*)v0;
    goto ret;
ret:
    return v0;
}
#pragma pop /* merge_units */
/* merge_units: end func_003D7590 */

/* merge_units: begin func_003D75C0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "scriptBase_types.h"

extern PtrVec* D_00554F30;  /* global enum table, ids start at 10 */

/* Returns the global enum descriptor for enum id 'id'. */
int ScriptEnum_GetById(int id) {
    int i = id - 10;

    return D_00554F30->data[i];
}
#pragma pop /* merge_units */
/* merge_units: end func_003D75C0 */

/* merge_units: begin func_003D75E0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
extern "C" {
extern char D_004BD3B0[];
void* Mem_Alloc(int pool, int size, char* file, int line);
int strlen(const char* s);
void* memcpy(void* d, const void* s, int n);
}
static inline void* SD_Alloc(int n)
{
    AllocGuard g;
    return Mem_Alloc(0, n, D_004BD3B0, 0x130);
}
extern "C" char* Str_Duplicate(char* s)
{
    char* p = 0;
    if (s) {
        int len = strlen(s) + 1;
        int n = (len + 31) / 32 * 32;
        p = (char*)SD_Alloc(n);
        memcpy(p, s, n);
    }
    return p;
}
#pragma pop /* merge_units */
/* merge_units: end func_003D75E0 */

/* merge_units: begin func_003D76D0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(10)
extern "C" {
void PtrVector_Resize(void* v, int n, int* val);
}
typedef struct { int pad0; int count; int* data; } V76D0;
typedef struct { int pad0; int x4; V76D0 vec; char pad14[0x38 - 0x14]; int x38; } O76D0;
extern "C" {
O76D0* FuncDef_ctor_charP_intPintPint_bool(void* p, char* name, int a, signed char f);
void std_vector_FuncDefPtr_push_back(int list, O76D0** o);
extern int D_00554F20;
}
static inline int* At(V76D0* v, unsigned int i) { return &v->data[i]; }
static inline void* SD_Alloc_003D76D0(int n, int line)
{
    AllocGuard g;
    return Mem_Alloc(0, n, D_004BD3B0, line);
}
extern "C" void cScriptBase_addGameFunc(char* name, int a, int x4, int n, int* src, signed char f)
{
    O76D0* o;
    int i;
    int zero;
    void* m = SD_Alloc_003D76D0(0x44, 0x119);
    if (m) m = FuncDef_ctor_charP_intPintPint_bool(m, name, a, f);
    o = (O76D0*)m;
    ((O76D0*)m)->x4 = x4;
    o->x38 = 1;
    zero = 0;
    PtrVector_Resize(&o->vec, n, &zero);
    for (i = 0; i < n; i++) *At(&o->vec, i) = src[i];
    std_vector_FuncDefPtr_push_back(D_00554F20, &o);
}
#pragma pop /* merge_units */
/* merge_units: end func_003D76D0 */
