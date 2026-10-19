/*
 * main/human: range (2 files, 001AFA30-001AFB20)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#pragma push
#pragma cplusplus on
#include "buf_holder_dtor.h"
#pragma pop
#include "types.h"

/* merge_units: begin func_001AFA30 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR_SHALLOW(func_001AFA30)
#pragma pop /* merge_units */
/* merge_units: end func_001AFA30 */

/* merge_units: begin func_001AFB20 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
#if 0 /* merge_units */
int Alloc_Lock(int);
#endif /* merge_units */
#define Alloc_Lock(a0) (Alloc_Lock((a0))) /* merge_units */
                                    
#if 0 /* merge_units */
int Alloc_Unlock(int);
#endif /* merge_units */
#define Alloc_Unlock(a0) (Alloc_Unlock((a0))) /* merge_units */
                                  
int ColScratch_Init(int, int, int, int);                      
int HumanCol_Init();                                  
char * Mem_Alloc(int, int, char *, int);                      
int func_001360D0(int);                                 
int func_001361D0(int *);                           
int func_001AFCF0(char * , int);                       
int func_001AFD00(char * );                            
int func_001AFD20(char * , int);                       
int func_001AFD30(char * );                            
int HumanBounds_BuildTable(char * );                            
int HumanCentroid_GetTable(char * );                            
int func_001D8720();                                  
extern char D_0049D8D0;
extern char * D_004EE9D0;
extern char * D_004EE9D8;
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;

void Human_InitStatics(void) {
    int sp2C;
    char * temp_s0;
    char * temp_s0_2;

    ColScratch_Init(0, 0, 0, 0);
    func_001360D0(0x320);
    HumanCol_Init();
    func_001D8720();
    sp2C = 0x15;
    if (D_004EE9D0 == NULL) {
        if (g_ProfileLockEnabled != 0) {
            Alloc_Lock(9);
        }
        g_ProfileLockDepth += 1;
        temp_s0 = Mem_Alloc(0, 0x10, &D_0049D8D0, 0xB1A);
        if (g_ProfileLockEnabled != 0) {
            Alloc_Unlock(9);
        }
        g_ProfileLockDepth -= 1;
        if (temp_s0 != NULL) {
            func_001AFD30(temp_s0);
            func_001AFD20(temp_s0, func_001361D0(&sp2C));
            F_(temp_s0, 0xC, signed char) = 1;
        }
        D_004EE9D0 = temp_s0;
        HumanCentroid_GetTable(temp_s0);
    }
    if (D_004EE9D8 == NULL) {
        if (g_ProfileLockEnabled != 0) {
            Alloc_Lock(9);
        }
        g_ProfileLockDepth += 1;
        temp_s0_2 = Mem_Alloc(0, 0x10, &D_0049D8D0, 0xB20);
        if (g_ProfileLockEnabled != 0) {
            Alloc_Unlock(9);
        }
        g_ProfileLockDepth -= 1;
        if (temp_s0_2 != NULL) {
            func_001AFD00(temp_s0_2);
            func_001AFCF0(temp_s0_2, func_001361D0(&sp2C));
            F_(temp_s0_2, 0xC, signed char) = 1;
        }
        D_004EE9D8 = temp_s0_2;
        HumanBounds_BuildTable(temp_s0_2);
    }
}
#undef Alloc_Lock /* merge_units */
#undef Alloc_Unlock /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001AFB20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001AFB20 */
