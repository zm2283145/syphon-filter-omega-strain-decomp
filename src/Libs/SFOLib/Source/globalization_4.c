/*
 * Libs/SFOLib/Source/globalization: 1 file, 003FDCA0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003FDCA0 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Alloc_Lock(int);                                    
int EnableIntc(int);                                  
int LoadStrings(char * , char *);                    
char * cMemMan_Allocate(int, int, char *, int);                      
int cMemMan_Deallocate(int, char * , char *, int);                      
int std_vector_pod_int_resize(char *, int, int *);                
int Libc_Strcpy(char *, int);                            
int Libc_Strcat(char *, char *);                          
int cArrayCapacity_Int(int *);                           
int std_vector_1_reserve(char * , int);                       
int std_vector_1_ctor(char * );                            
int std_vector_deleter_1_dtor(char * , int);                         
int sprintf(char *, char *, int);                           
extern char D_00493A40;
extern char D_004BE440;
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
extern char * D_0055CA50;
extern char D_0055CA70;
extern int D_0055CA80;
extern unsigned char D_0055D470;

void nGlobalization_LoadLevelStrings(int arg0, char *arg1) {
    int sp13C;
    int sp138;
    int sp30[66];
    int sp20[4];
    char * temp_s0;
    char * temp_s0_2;

    Libc_Strcpy(sp30, arg0);
    Libc_Strcat(sp30, "\\");
    Libc_Strcat(sp30, arg1);
    sprintf(sp20, "\\STRINGS%s.DAT", F_(&D_00493A40, (D_0055D470 * 4), int));
    Libc_Strcat(sp30, sp20);
    temp_s0 = D_0055CA50;
    if (temp_s0 != NULL) {
        if (g_ProfileLockEnabled != 0) {
            Alloc_Lock(9);
        }
        g_ProfileLockDepth += 1;
        if ((temp_s0 != NULL) && (temp_s0 != NULL) && (temp_s0 != NULL)) {
            std_vector_deleter_1_dtor(temp_s0, 0);
        }
        cMemMan_Deallocate(0, temp_s0, &D_004BE440, 0x9B);
        if (g_ProfileLockEnabled != 0) {
            EnableIntc(9);
        }
        D_0055CA50 = NULL;
        g_ProfileLockDepth -= 1;
    }
    sp138 = 0;
    std_vector_pod_int_resize(&D_0055CA70, D_0055CA80, &sp138);
    if (D_0055CA50 == NULL) {
        if (g_ProfileLockEnabled != 0) {
            Alloc_Lock(9);
        }
        g_ProfileLockDepth += 1;
        temp_s0_2 = cMemMan_Allocate(0, 0x10, &D_004BE440, 0x12C);
        if (g_ProfileLockEnabled != 0) {
            EnableIntc(9);
        }
        g_ProfileLockDepth -= 1;
        if (temp_s0_2 != NULL) {
            sp13C = 0x190;
            std_vector_1_ctor(temp_s0_2);
            std_vector_1_reserve(temp_s0_2, cArrayCapacity_Int(&sp13C));
            F_(temp_s0_2, 0xC, signed char) = 1;
        }
        D_0055CA50 = temp_s0_2;
    }
    LoadStrings(D_0055CA50, sp30);
}
static inline void merge_flush_func_003FDCA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003FDCA0 */
