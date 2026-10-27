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
char * cMemMan_Allocate(int, int, char *, int);                      
int cArrayCapacity_Int(int *);                           
int std_vector_VarDefPtr_reserve(char * , int);                       
int std_vector_VarDefPtr_ctor(char * );                            
int std_vector_FuncDefPtr_reserve(char * , int);                       
int std_vector_FuncDefPtr_ctor(char * );                            
int std_vector_EnumDefPtr_reserve(char * , int);                       
int std_vector_EnumDefPtr_ctor(char * );                            
int std_vector_ClassDefPtr_reserve(char * , int);                       
int std_vector_ClassDefPtr_ctor(char * );                            
extern char D_004BD3B0;
extern unsigned char g_ProfileLockEnabled;
extern unsigned char D_00554F10;
extern char * D_00554F18;
extern char * D_00554F20;
extern char * D_00554F28;
extern char * D_00554F30;
}
extern "C" void cScriptBase_checkInitTypes(void) {
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
        temp_s0 = cMemMan_Allocate(0, 0x10, &D_004BD3B0, 0xDE);
        }
        if (temp_s0 != NULL) {
            sp3C = 0x100;
            std_vector_ClassDefPtr_ctor(temp_s0);
            std_vector_ClassDefPtr_reserve(temp_s0, cArrayCapacity_Int(&sp3C));
            F_(temp_s0, 0xC, signed char) = 0;
        }
        D_00554F28 = temp_s0;
        {
            AllocGuard g;
        temp_s0_2 = cMemMan_Allocate(0, 0x10, &D_004BD3B0, 0xDF);
        }
        if (temp_s0_2 != NULL) {
            sp38 = 0x80;
            std_vector_EnumDefPtr_ctor(temp_s0_2);
            std_vector_EnumDefPtr_reserve(temp_s0_2, cArrayCapacity_Int(&sp38));
            F_(temp_s0_2, 0xC, signed char) = 0;
        }
        D_00554F30 = temp_s0_2;
        {
            AllocGuard g;
        temp_s0_3 = cMemMan_Allocate(0, 0x10, &D_004BD3B0, 0xE0);
        }
        if (temp_s0_3 != NULL) {
            sp34 = 0x800;
            std_vector_FuncDefPtr_ctor(temp_s0_3);
            std_vector_FuncDefPtr_reserve(temp_s0_3, cArrayCapacity_Int(&sp34));
            F_(temp_s0_3, 0xC, signed char) = 0;
        }
        D_00554F20 = temp_s0_3;
        {
            AllocGuard g;
        temp_s0_4 = cMemMan_Allocate(0, 0x10, &D_004BD3B0, 0xE1);
        }
        if (temp_s0_4 != NULL) {
            sp30 = 0x400;
            std_vector_VarDefPtr_ctor(temp_s0_4);
            std_vector_VarDefPtr_reserve(temp_s0_4, cArrayCapacity_Int(&sp30));
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
DEFINE_BUF_HOLDER_DTOR(std_vector_VarDefPtr_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_003D8160 */

/* merge_units: begin func_003D8250 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR(std_vector_FuncDefPtr_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_003D8250 */
