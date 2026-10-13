/*
 * main/DME: 2 files, 00429510-004295E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00429510 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
int Mem_Alloc(int, int, char *, int);                        
int func_00453E20(int);                             
extern unsigned char D_00533880;
extern int D_00572480;
extern signed char D_00572488;
}
extern "C" void func_00429510(void) {
    int var_s0;

    if (D_00572480 == 0) {
        {
            AllocGuard g;
        var_s0 = Mem_Alloc(0, 0x26B0, "DME.cc", 0x75D);
        }
        if (var_s0 != 0) {
            var_s0 = func_00453E20(var_s0);
        }
        D_00572480 = var_s0;
    }
    D_00572488 = 1;
}
#pragma pop /* merge_units */
/* merge_units: end func_00429510 */

/* merge_units: begin func_004295E0 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
void func_0010CFA0(void);
void func_0010D080(void);
void func_001161A0(void);
void func_001161F8(void);
void func_00429D30(void);
extern signed char D_00572500;
extern unsigned char D_00572530;
}
static inline int Done4295E0() { return D_00572530 != 0; }
#pragma bool off
extern "C" void func_004295E0(void) {
    while (Done4295E0() ^ 1) {
        func_00429D30();
        func_001161F8();
        func_0010D080();
        func_001161A0();
    }
    func_001161F8();
    D_00572500 = 1;
    func_0010CFA0();
}
#pragma pop /* merge_units */
/* merge_units: end func_004295E0 */
