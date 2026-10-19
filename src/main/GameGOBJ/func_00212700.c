#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int Alloc_Lock(int);                                    
int Alloc_Unlock(int);                                  
int Mem_Free(int, char * , char *, int);                      
char * Object_LookupById(int *);                     
int func_00211DA0();                                
int func_002EB650(void **, int);                    
int func_002EC2A8(int);                               
extern char D_004A4550;
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
extern unsigned char D_005723C8;

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void func_00212700(int d0, int arg1) {
    struct { char pad50[4]; int f54; char * f58[2]; } sl;
    char * temp_s1;
    char * temp_s3;
    char * temp_v0;
    char * temp_v1;

    if (D_005723C8 == 0) {
        D_005723C8 = 1;
    }
    if (func_002EB650(sl.f58, arg1) == 0) {
        temp_s1 = (char *)(F_(sl.f58[0], 0x1C, int));
        sl.f54 = F_(temp_s1, 0x10, unsigned short) | (F_(temp_s1, 0xE, unsigned short) << 0x10);
        temp_v0 = (char *)(Object_LookupById(&sl.f54));
        if (temp_v0 != NULL) {
            temp_v1 = (char *)(F_(temp_v0, 0xD0, int));
            if ((temp_v1 != NULL) && (temp_s1 != NULL)) {
                F_(temp_s1, 0x4, int) = F_(temp_v1, 0x4, int);
                F_(temp_s1, 0x0, int) = F_(F_(temp_v0, 0xD0, int), 0x0, int);
                temp_s3 = (char *)(F_(temp_v0, 0xD0, int));
                if (temp_s3 != NULL) {
                    if (F_(temp_s3, 0xC, unsigned char) != 0) {
                        func_002EC2A8(func_00211DA0());
                    } else {
                        if (g_ProfileLockEnabled != 0) {
                            Alloc_Lock(9);
                        }
                        g_ProfileLockDepth += 1;
                        Mem_Free(0, temp_s3, &D_004A4550, 0xB83);
                        if (g_ProfileLockEnabled != 0) {
                            Alloc_Unlock(9);
                        }
                        g_ProfileLockDepth -= 1;
                    }
                    F_(temp_v0, 0xD0, int) = NULL;
                }
            }
            F_(temp_v0, 0xD0, int) = (int)(temp_s1);
            { int one = 1; F_(temp_s1, 0x4, int) = one;
            F_(F_(temp_v0, 0xD0, int), 0x1C, int) = arg1;
            F_(temp_v0, 0x14, signed char) = 0;
            F_(temp_s1, 0xC, unsigned char) = one; }
        }
    }
    D_005723C8 = 0;
}
#pragma pop
