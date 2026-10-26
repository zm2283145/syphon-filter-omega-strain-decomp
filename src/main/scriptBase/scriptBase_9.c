/*
 * main/scriptBase: 2 files, 003D8A10-003D8A30
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003D8A10 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "scriptBase_types.h"

extern int PtrVec_Insert(PtrVec* v, int* pos, int n, int value);

/* push_back: inserts one value at the end. */
int std_vector_FieldDefPtr_push_back(PtrVec* v, int value) {
    return PtrVec_Insert(v, v->data + v->count, 1, value);
}
#pragma pop /* merge_units */
/* merge_units: end func_003D8A10 */

/* merge_units: begin func_003D8A30 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int Alloc_Lock(int);                                    
int Alloc_Unlock(int);                                  
char * Mem_Alloc(int, int, char *, int);                    
int cScriptBase_checkInitTypes();                                  
int std_vector_VarDefPtr_push_back(int, void **);                      
int memcpy(char * , char *, int);                         
int sprintf(char *, char *, char * );                        
int strlen(char *);                                    
extern char D_00499C71;
extern char D_004BD3B0;
extern char D_004BD3C8;
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
extern int D_00554F18;

#pragma push
#pragma opt_propagation off
int Script_RegisterVariable(char * arg0, int arg1, int arg2) {
    int temp_v1;
    char * temp_s2;
    int sp60[67];
    char * temp_s1;
    char * var_s0;
    char * sp16C;
    int var_v0;
    int temp_s0;

    var_s0 = arg0;
    if ((*arg0 == 0x67) && ((&D_00499C71)[var_s0[1]] & 1)) {
        var_s0 += 1;
    }
    cScriptBase_checkInitTypes();
    sprintf(sp60, &D_004BD3C8, var_s0);
    if (g_ProfileLockEnabled != 0) {
        Alloc_Lock(9);
    }
    g_ProfileLockDepth += 1;
    temp_s2 = Mem_Alloc(0, 0x20, &D_004BD3B0, 0x89);
    if (g_ProfileLockEnabled != 0) {
        Alloc_Unlock(9);
    }
    g_ProfileLockDepth -= 1;
    if (temp_s2 != NULL) {
        temp_v1 = strlen((char*)sp60) + 1; temp_s0 = (temp_v1 + 0x1F) / 32 * 32;
        if (g_ProfileLockEnabled != 0) {
            Alloc_Lock(9);
        }
        g_ProfileLockDepth += 1;
        temp_s1 = Mem_Alloc(0, temp_s0, &D_004BD3B0, 0x130);
        if (g_ProfileLockEnabled != 0) {
            Alloc_Unlock(9);
        }
        g_ProfileLockDepth -= 1;
        memcpy(temp_s1, sp60, temp_s0);
        F_(temp_s2, 0x0, int) = (int)(temp_s1);
        F_(temp_s2, 0x4, int) = arg2;
        F_(temp_s2, 0x8, signed char) = (signed char) (arg1 != 0);
        F_(temp_s2, 0xC, int) = arg1;
        F_(temp_s2, 0x10, int) = 0;
        F_(temp_s2, 0x14, int) = 0;
        F_(temp_s2, 0x18, signed char) = 0;
        F_(temp_s2, 0x19, signed char) = 0;
    }
    sp16C = temp_s2;
    std_vector_VarDefPtr_push_back(D_00554F18, &sp16C);
    return 0;
}
#pragma pop
#pragma pop /* merge_units */
/* merge_units: end func_003D8A30 */
