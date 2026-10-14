/*
 * main/scriptBase: range (3 files, 003D7E90-003D8250)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "buf_holder_dtor.h"
#pragma pop

/* merge_units: begin func_003D7E90 */
#pragma push /* merge_units */
#pragma cplusplus on
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
char * Mem_Alloc(int, int, char *, int);                      
int func_001361D0(int *);                           
int func_003D8340(char * , int);                       
int func_003D8350(char * );                            
int func_003D8370(char * , int);                       
int func_003D8380(char * );                            
int func_003D8490(char * , int);                       
int func_003D84A0(char * );                            
int func_003D84C0(char * , int);                       
int func_003D84D0(char * );                            
extern char D_004BD3B0;
extern unsigned char D_00533880;
extern unsigned char D_00554F10;
extern char * D_00554F18;
extern char * D_00554F20;
extern char * D_00554F28;
extern char * D_00554F30;
}
extern "C" void func_003D7E90(void) {
    int sp3C;
    int sp38;
    int sp34;
    int sp30;
    char * temp_s0;
    char * temp_s0_2;
    char * temp_s0_3;
    char * temp_s0_4;

    if (D_00554F10 == 0) {
        D_00554F10 = 1;
        {
            AllocGuard g;
        temp_s0 = Mem_Alloc(0, 0x10, &D_004BD3B0, 0xDE);
        }
        if (temp_s0 != NULL) {
            sp3C = 0x100;
            func_003D84D0(temp_s0);
            func_003D84C0(temp_s0, func_001361D0(&sp3C));
            F_(temp_s0, 0xC, signed char) = 0;
        }
        D_00554F28 = temp_s0;
        {
            AllocGuard g;
        temp_s0_2 = Mem_Alloc(0, 0x10, &D_004BD3B0, 0xDF);
        }
        if (temp_s0_2 != NULL) {
            sp38 = 0x80;
            func_003D84A0(temp_s0_2);
            func_003D8490(temp_s0_2, func_001361D0(&sp38));
            F_(temp_s0_2, 0xC, signed char) = 0;
        }
        D_00554F30 = temp_s0_2;
        {
            AllocGuard g;
        temp_s0_3 = Mem_Alloc(0, 0x10, &D_004BD3B0, 0xE0);
        }
        if (temp_s0_3 != NULL) {
            sp34 = 0x800;
            func_003D8380(temp_s0_3);
            func_003D8370(temp_s0_3, func_001361D0(&sp34));
            F_(temp_s0_3, 0xC, signed char) = 0;
        }
        D_00554F20 = temp_s0_3;
        {
            AllocGuard g;
        temp_s0_4 = Mem_Alloc(0, 0x10, &D_004BD3B0, 0xE1);
        }
        if (temp_s0_4 != NULL) {
            sp30 = 0x400;
            func_003D8350(temp_s0_4);
            func_003D8340(temp_s0_4, func_001361D0(&sp30));
            F_(temp_s0_4, 0xC, signed char) = 0;
        }
        D_00554F18 = temp_s0_4;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003D7E90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003D7E90 */

/* merge_units: begin func_003D8160 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR(func_003D8160)
#pragma pop /* merge_units */
/* merge_units: end func_003D8160 */

/* merge_units: begin func_003D8250 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR(func_003D8250)
#pragma pop /* merge_units */
/* merge_units: end func_003D8250 */
