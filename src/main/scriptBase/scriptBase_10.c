/*
 * main/scriptBase: 2 files, 003D8C30-003D8C50
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003D8C30 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "scriptBase_types.h"

extern int std_vector_pod_int_insert(PtrVec* v, int* pos, int n, int value);

/* push_back: inserts one value at the end. */
int std_vector_VarDefPtr_push_back(PtrVec* v, int value) {
    return std_vector_pod_int_insert(v, v->data + v->count, 1, value);
}
#pragma pop /* merge_units */
/* merge_units: end func_003D8C30 */

/* merge_units: begin func_003D8C50 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int Alloc_Lock(int);                                    
int EnableIntc(int);                                  
char * cMemMan_Allocate(int, int, char *, int);                      
int cArrayCapacity_ctor(char *, int);                          
int cScriptBase_checkInitTypes();                                  
int std_vector_ClassDefPtr_push_back(char * , void **);                   
int cArray_int_ctor(char * );                            
int cArray_MemberFuncPtr_ctor(char * , int, int);                    
int cArray_FieldDefPtr_ctor(char * , int, int);                    
int strrchr(char * , int);                             
extern char D_00499C71;
extern char D_004BD3B0;
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
extern char * D_00554F28;

#pragma push
#pragma opt_common_subs off
int cScriptBase_addClass(char * arg0, int arg1, signed char arg2, signed char arg3) {
    struct { int f60; int f64[2]; char * f6C; } sl;
    int temp_v0;
    char * temp_s0;
    char * var_s4;

    var_s4 = arg0;
    cScriptBase_checkInitTypes();
    temp_v0 = strrchr(var_s4, 0x3A);
    if (temp_v0 != 0) {
        var_s4 = (char *)(temp_v0 + 1);
    }
    if ((F_(var_s4, 0x0, signed char) == 0x63) && (F_(&D_00499C71, F_(var_s4, 0x1, signed char), signed char) & 1)) {
        var_s4 += 1;
    }
    if (g_ProfileLockEnabled != 0) {
        Alloc_Lock(9);
    }
    g_ProfileLockDepth += 1;
    temp_s0 = cMemMan_Allocate(0, 0x50, &D_004BD3B0, 0x79);
    if (g_ProfileLockEnabled != 0) {
        EnableIntc(9);
    }
    g_ProfileLockDepth -= 1;
    if (temp_s0 != NULL) {
        cArray_FieldDefPtr_ctor(temp_s0 + 4, cArrayCapacity_ctor(sl.f64, 5), 1);
        cArray_MemberFuncPtr_ctor(temp_s0 + 0x14, cArrayCapacity_ctor(&sl.f60, 5), 1);
        cArray_int_ctor(temp_s0 + 0x24);
        F_(temp_s0, 0x0, int) = (int)(var_s4);
        F_(temp_s0, 0x34, int) = arg1;
        F_(temp_s0, 0x3C, signed char) = 0;
        F_(temp_s0, 0x40, int) = -1;
        F_(temp_s0, 0x44, signed char) = 0;
        F_(temp_s0, 0x45, signed char) = arg2;
        F_(temp_s0, 0x48, int) = 0;
        F_(temp_s0, 0x4C, signed char) = arg3;
    }
    sl.f6C = temp_s0;
    F_(temp_s0, 0x38, int) = (int) (F_(D_00554F28, 0x4, int) + 0x64);
    F_(sl.f6C, 0x44, signed char) = 1;
    std_vector_ClassDefPtr_push_back(D_00554F28, &sl.f6C);
    return F_(sl.f6C, 0x38, int);
}
#pragma pop
#pragma pop /* merge_units */
/* merge_units: end func_003D8C50 */
