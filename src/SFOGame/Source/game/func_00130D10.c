#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int Alloc_Lock(int);                                    
int EnableIntc(int);                                  
int *cMemMan_Allocate(int, int, char *, int);                     
int Libc_Strcpy(int *, int);                          
int std_vector_tVUMNamePairPtr_push_back(int, int **);                       
int strlen(int);                                    
extern char D_0049A890;
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;

void cGameSystem_AddVUMGOBJ(int arg0, int arg1, int arg2, int arg3) {
    int temp_s4;
    int *var_s4;
    int *sp6C;
    int *temp_s3_2;
    int *temp_s2;
    int temp_s3;

    temp_s3 = strlen(arg2) + 1;
    if (g_ProfileLockEnabled != 0) {
        Alloc_Lock(9);
    }
    g_ProfileLockDepth += 1;
    temp_s3_2 = (char *)(cMemMan_Allocate(0, temp_s3, &D_0049A890, 0x92C));
    if (g_ProfileLockEnabled != 0) {
        EnableIntc(9);
    }
    var_s4 = NULL;
    g_ProfileLockDepth -= 1;
    Libc_Strcpy(temp_s3_2, arg2);
    if (arg3 != 0) {
        temp_s4 = strlen(arg3) + 1;
        if (g_ProfileLockEnabled != 0) {
            Alloc_Lock(9);
        }
        g_ProfileLockDepth += 1;
        var_s4 = (char *)(cMemMan_Allocate(0, temp_s4, &D_0049A890, 0x933));
        if (g_ProfileLockEnabled != 0) {
            EnableIntc(9);
        }
        g_ProfileLockDepth -= 1;
        Libc_Strcpy(var_s4, arg3);
    }
    if (g_ProfileLockEnabled != 0) {
        Alloc_Lock(9);
    }
    g_ProfileLockDepth += 1;
    temp_s2 = (char *)(cMemMan_Allocate(0, 0xC, &D_0049A890, 0x937));
    if (g_ProfileLockEnabled != 0) {
        EnableIntc(9);
    }
    sp6C = temp_s2;
    g_ProfileLockDepth -= 1;
    *temp_s2 = arg1;
    F_(sp6C, 0x4, int) = (int)(temp_s3_2);
    F_(sp6C, 0x8, int) = (int)(var_s4);
    std_vector_tVUMNamePairPtr_push_back(arg0 + 0x2C, &sp6C);
}
