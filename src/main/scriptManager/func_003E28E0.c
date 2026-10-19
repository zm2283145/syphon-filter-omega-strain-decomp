#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int Alloc_Lock();                                    
int Alloc_Unlock();                                  
int Mem_Alloc();                      
int ScalarCollection_Init();                       
int func_001361D0();                           
int func_003E2D20();                       
int func_003E2D30();                            
int func_003E2D50();                       
int func_003E2D60();                            
int func_003E3460();                                  
extern char D_004BD4C0;
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;

#pragma push
#pragma opt_common_subs off
char * func_003E28E0(char * arg0, int arg1) {
    struct { char pad40[8]; int f48; int f4C; } sl;
    int temp_s1_3;
    int temp_s1_4;
    char * temp_s1;
    char * temp_s1_2;

    func_003E3460();
    ScalarCollection_Init(arg0 + 0xC);
    sl.f4C = 0x12C;
    temp_s1 = arg0 + 0x18;
    func_003E2D60(temp_s1);
    func_003E2D50(temp_s1, func_001361D0(&sl.f4C));
    F_(temp_s1, 0xC, signed char) = 0;
    F_(arg0, 0x28, int) = 0;
    sl.f48 = 0x12C;
    temp_s1_2 = arg0 + 0x4E4C;
    func_003E2D30(temp_s1_2);
    func_003E2D20(temp_s1_2, func_001361D0(&sl.f48));
    F_(temp_s1_2, 0xC, signed char) = 0;
    F_(arg0, 0x4E78, int) = arg1;
    temp_s1_3 = F_(arg0, 0x4E78, int) * 4;
    if (g_ProfileLockEnabled != 0) {
        Alloc_Lock(9);
    }
    g_ProfileLockDepth += 1;
    temp_s1_4 = Mem_Alloc(0, temp_s1_3, &D_004BD4C0, 0x34);
    if (g_ProfileLockEnabled != 0) {
        Alloc_Unlock(9);
    }
    g_ProfileLockDepth -= 1;
    F_(arg0, 0x4E6C, int) = temp_s1_4;
    F_(arg0, 0x4E7C, int) = 0;
    F_(arg0, 0x4E70, int) = (int) (F_(arg0, 0x4E6C, int) + (F_(arg0, 0x4E78, int) * 4));
    F_(arg0, 0x4E90, int) = 0;
    F_(arg0, 0x4E98, int) = 0;
    F_(arg0, 0x4E94, signed char) = 0;
    F_(arg0, 0x4E9C, int) = 0;
    F_(arg0, 0x4EA0, int) = 0;
    F_(arg0, 0x4E60, int) = 0;
    F_(arg0, 0x4E64, int) = 0;
    F_(arg0, 0x4E5C, int) = 0;
    return arg0;
}
#pragma pop
