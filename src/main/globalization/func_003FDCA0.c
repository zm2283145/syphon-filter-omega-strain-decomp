#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Alloc_Lock(int);                                    
int Alloc_Unlock(int);                                  
int Loc_ReadPoolFile(char * , char *);                    
char * Mem_Alloc(int, int, char *, int);                      
int Mem_Free(int, char * , char *, int);                      
int PtrVector_Resize(char *, int, int *);                
int String_Copy(char *, int);                            
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

void Loc_LoadMissionPool(int arg0, char *arg1) {
    int sp13C;
    int sp138;
    int sp30[66];
    int sp20[4];
    char * temp_s0;
    char * temp_s0_2;

    String_Copy(sp30, arg0);
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
        Mem_Free(0, temp_s0, &D_004BE440, 0x9B);
        if (g_ProfileLockEnabled != 0) {
            Alloc_Unlock(9);
        }
        D_0055CA50 = NULL;
        g_ProfileLockDepth -= 1;
    }
    sp138 = 0;
    PtrVector_Resize(&D_0055CA70, D_0055CA80, &sp138);
    if (D_0055CA50 == NULL) {
        if (g_ProfileLockEnabled != 0) {
            Alloc_Lock(9);
        }
        g_ProfileLockDepth += 1;
        temp_s0_2 = Mem_Alloc(0, 0x10, &D_004BE440, 0x12C);
        if (g_ProfileLockEnabled != 0) {
            Alloc_Unlock(9);
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
    Loc_ReadPoolFile(D_0055CA50, sp30);
}
