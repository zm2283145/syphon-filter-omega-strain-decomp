/*
 * main/scriptUtils: range (2 files, 00267690-00267740)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00267690 */
#pragma push /* merge_units */
typedef struct { int a[3]; } Str_7690;
typedef struct { Str_7690 name; int fc; int f10; Str_7690 s14; Str_7690 s20; int f2c; float f30; unsigned char b34; } Mat_7690;
extern Mat_7690* func_004095A0(Mat_7690* o, char* a, int b, char* c, char* d, float f, unsigned char g);
extern unsigned char func_004085A0(void* reg, int a, int b, Mat_7690* m);
extern int String_Dtor(Str_7690* s, int f);
extern char D_0053BB90[];
static inline void Dt_7690(Str_7690* p) { if (p) String_Dtor(p, 0); }
unsigned char Global_AddMaterialProperties(int p0, int p1, char* a, signed char b, char* c, char* d, float f, unsigned char g)
{
    Mat_7690 m;
    unsigned char r;
    func_004095A0(&m, a, b, c, d, f, g);
    r = func_004085A0(D_0053BB90, p0, p1, &m);
    Dt_7690(&m.s20);
    Dt_7690(&m.s14);
    String_Dtor(&m.name, 0);
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00267690(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00267690 */

/* merge_units: begin func_00267740 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#if 0 /* merge_units */
int String_Dtor(int, int);
#endif /* merge_units */
#define String_Dtor(a0, a1) (String_Dtor((void *)(a0), (a1))) /* merge_units */
                            
int operator_delete(int);                             

int func_00267740(int arg0, long long arg1) {
    int temp_a0;
    int temp_a0_2;

    if (arg0 != 0) {
        temp_a0 = arg0 + 0x20;
        if (temp_a0 != 0) {
            String_Dtor(temp_a0, 0);
        }
        temp_a0_2 = arg0 + 0x14;
        if (temp_a0_2 != 0) {
            String_Dtor(temp_a0_2, 0);
        }
        if (arg0 != 0) {
            String_Dtor(arg0, 0);
        }
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            operator_delete(arg0);
        }
    }
    return arg0;
}
#undef String_Dtor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00267740(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00267740 */
