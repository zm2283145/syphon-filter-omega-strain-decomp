/*
 * main/NPCInfoObject: range (2 files, 00434BE0-00434D10)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00434BE0 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Alloc_Lock(int);                                    
int EnableIntc(int);                                  
char * cMemMan_Allocate(int, int, char *, int);                      
int std_tree_pair_tNPCInfoPtr_value_compare_insert_one(char *, char *, void **);                 
extern char D_004BFCA0;
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
extern char D_00582B50;

#pragma push
#pragma opt_common_subs off
void func_00434BE0(int d0, char * arg1, signed char arg2) {
    struct { char pad40[8]; char * f48; signed char f4C[4]; int f50[4]; } sl;
    char * temp_s0;

    if (g_ProfileLockEnabled != 0) {
        Alloc_Lock(9);
    }
    g_ProfileLockDepth += 1;
    temp_s0 = cMemMan_Allocate(0, 0x14, &D_004BFCA0, 0x300);
    if (g_ProfileLockEnabled != 0) {
        EnableIntc(9);
    }
    g_ProfileLockDepth -= 1;
    if (temp_s0 != NULL) {
        F_(temp_s0, 0x4, unsigned char) = F_(arg1, 0x4, unsigned char);
        F_(temp_s0, 0x0, int) = F_(arg1, 0x0, int);
        F_(temp_s0, 0x5, unsigned char) = F_(arg1, 0x5, unsigned char);
        F_(temp_s0, 0x6, unsigned char) = F_(arg1, 0x6, unsigned char);
        F_(temp_s0, 0xA, unsigned char) = F_(arg1, 0xA, unsigned char);
        F_(temp_s0, 0x7, unsigned char) = F_(arg1, 0x7, unsigned char);
        F_(temp_s0, 0xB, unsigned char) = F_(arg1, 0xB, unsigned char);
        F_(temp_s0, 0x8, unsigned char) = F_(arg1, 0x8, unsigned char);
        F_(temp_s0, 0xC, unsigned char) = F_(arg1, 0xC, unsigned char);
        F_(temp_s0, 0x9, unsigned char) = F_(arg1, 0x9, unsigned char);
        F_(temp_s0, 0xD, unsigned char) = F_(arg1, 0xD, unsigned char);
        F_(temp_s0, 0x10, int) = F_(arg1, 0x10, int);
    }
    sl.f48 = temp_s0;
    sl.f4C[0] = arg2;
    std_tree_pair_tNPCInfoPtr_value_compare_insert_one(sl.f50, &D_00582B50, &sl.f48);
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00434BE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00434BE0 */

/* merge_units: begin func_00434D10 */
#pragma push /* merge_units */
#pragma mpwc_relax on
                      
int std_list_tNPCInfoPtr_push_back(char *, void **);
extern char D_00582B10;

void func_00434D10(int d0, char * arg1) {
    char * sp3C;
    char * temp_s0;

    if (g_ProfileLockEnabled != 0) {
        Alloc_Lock(9);
    }
    g_ProfileLockDepth += 1;
    temp_s0 = cMemMan_Allocate(0, 0x14, &D_004BFCA0, 0x2F4);
    if (g_ProfileLockEnabled != 0) {
        EnableIntc(9);
    }
    g_ProfileLockDepth -= 1;
    if (temp_s0 != NULL) {
        F_(temp_s0, 0x4, unsigned char) = F_(arg1, 0x4, unsigned char);
        F_(temp_s0, 0x0, int) = F_(arg1, 0x0, int);
        F_(temp_s0, 0x5, unsigned char) = F_(arg1, 0x5, unsigned char);
        F_(temp_s0, 0x6, unsigned char) = F_(arg1, 0x6, unsigned char);
        F_(temp_s0, 0xA, unsigned char) = F_(arg1, 0xA, unsigned char);
        F_(temp_s0, 0x7, unsigned char) = F_(arg1, 0x7, unsigned char);
        F_(temp_s0, 0xB, unsigned char) = F_(arg1, 0xB, unsigned char);
        F_(temp_s0, 0x8, unsigned char) = F_(arg1, 0x8, unsigned char);
        F_(temp_s0, 0xC, unsigned char) = F_(arg1, 0xC, unsigned char);
        F_(temp_s0, 0x9, unsigned char) = F_(arg1, 0x9, unsigned char);
        F_(temp_s0, 0xD, unsigned char) = F_(arg1, 0xD, unsigned char);
        F_(temp_s0, 0x10, int) = F_(arg1, 0x10, int);
    }
    sp3C = temp_s0;
    std_list_tNPCInfoPtr_push_back(&D_00582B10, &sp3C);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00434D10(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00434D10 */
