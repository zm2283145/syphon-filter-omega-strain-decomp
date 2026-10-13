/*
 * main/DME: 4 files, 00429380-00429500
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00429380 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_0010CF60(int *);                           
int func_0010CF80(int, int);                            
int func_0010CFF0(int, int);                            
extern char D_004E9B70;
extern signed char D_00533880;
extern int D_00572510;
extern int D_00572520;
extern unsigned char D_00572528;
extern char D_00572540;

int func_00429380(int arg0) {
    struct { int f10; int f14; char * f18; int f1C; char * f20; int f24[4]; int f34[2]; int f3C; } sl;

    if (D_00572528 == 0) {
        sl.f14 = arg0;
        sl.f10 = 0x10;
        sl.f18 = &D_00572540;
        sl.f34[0] = 0;
        sl.f1C = 0x10000;
        sl.f3C = 0;
        sl.f20 = &D_004E9B70;
        D_00572520 = D_00572510;
        sl.f24[0] = 5;
        func_0010CFF0(D_00572510, 0xA);
        D_00572510 = func_0010CF60(&sl.f10);
        func_0010CF80(D_00572510, 0);
        D_00533880 = 1;
        D_00572528 = 1;
    }
    return 1;
}
#pragma pop /* merge_units */
/* merge_units: end func_00429380 */

/* merge_units: begin func_00429430 */
#pragma push /* merge_units */
#pragma mpwc_relax on
int Alloc_Unlock(int);                                  
int func_0010CE40(int, char *, int);                       
extern int D_00572518;
extern char func_004292B0;

unsigned char func_00429430(void) {
    unsigned char var_s0 = 0;

    *(volatile int *)0x10000010 = 0xC00;
    *(volatile int *)0x10000020 = 0x24A;
    *(volatile int *)0x10000000 = 0;
    *(volatile int *)0x10000010 = 0x382;
    D_00572518 = func_0010CE40(9, &func_004292B0, 0);
    if (D_00572518 != -1) {
        Alloc_Unlock(9);
        var_s0 = 1;
    }
    return var_s0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00429430 */

/* merge_units: begin func_004294C0 */
#pragma push /* merge_units */
#pragma cplusplus on
extern int D_00572480;
extern unsigned char D_00572488;
extern "C" int func_004294C0(void)
{
    unsigned char ok = 0; if (D_00572480 && D_00572488) ok = 1; return ok ? D_00572480 : 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_004294C0 */

/* merge_units: begin func_00429500 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


#if 0 /* merge_units */
extern char D_00572488[];
#endif /* merge_units */
#define D_00572488 ((char*)&D_00572488) /* merge_units */


void func_00429500(int a0) {
    *(char*)D_00572488 = a0;
}
#undef D_00572488 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00429500 */
