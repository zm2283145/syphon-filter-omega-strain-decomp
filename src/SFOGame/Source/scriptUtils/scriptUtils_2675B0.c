/*
 * main/scriptUtils: range (2 files, 002675B0-00267620)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_002675B0 */
#pragma push /* merge_units */
typedef union ScriptArg {
    int i;
    float f;
    void* p;
    unsigned char uc;
    signed char c;
} ScriptArg;

extern int Global_AddMaterialProperties(int, unsigned char, int, signed char, int, int, int, float);

/* Script: AddMaterialProperties(id, flag, a, kind, b, c, scale). */
unsigned char Script_AddMaterialProperties_2(ScriptArg* args) {
    int scale[1];
    int c[1];
    int b[1];
    int a[1];
    int id[1];
    signed char kind;
    unsigned char flag;
    scale[0] = args[6].i;
    c[0] = args[5].i;
    b[0] = args[4].i;
    kind = args[3].c;
    a[0] = args[2].i;
    flag = args[1].uc;
    id[0] = args[0].i;
    return Global_AddMaterialProperties(*(int*)id, flag, *(int*)a, kind, *(int*)b, *(int*)c, 0, *(float*)scale);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002675B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002675B0 */

/* merge_units: begin func_00267620 */
#pragma push /* merge_units */
typedef union { int i; unsigned char uc; signed char sc; } Arg00267620;
#if 0 /* merge_units */
extern unsigned char Global_AddMaterialProperties(int a, unsigned char b, int c, signed char d, int e, int f, int g, float h);
#endif /* merge_units */
#define Global_AddMaterialProperties(a0, a1, a2, a3, a4, a5, a6, a7) ((unsigned char)Global_AddMaterialProperties((a0), (a1), (a2), (a3), (a4), (a5), (a6), (a7))) /* merge_units */

/* Script: AddMaterialProperties(...). */
int Script_AddMaterialProperties(Arg00267620* args)
{
    int f[1]; /* staged through the stack */
    int e[1];
    signed char d;
    int c[1];
    unsigned char b;
    int a[1];
    f[0] = args[5].i;
    e[0] = args[4].i;
    d = args[3].sc;
    c[0] = args[2].i;
    b = args[1].uc;
    a[0] = args[0].i;
    return Global_AddMaterialProperties(*(int*)a, b, *(int*)c, d, *(int*)e, *(int*)f, 0, 0.2f);
}
#undef Global_AddMaterialProperties /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00267620(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00267620 */
