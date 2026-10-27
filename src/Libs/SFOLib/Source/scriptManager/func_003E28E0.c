#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int Alloc_Lock();                                    
int EnableIntc();                                  
int cMemMan_Allocate();                      
int std_list_deleter_voidPtr_ctor_void();                       
int cArrayCapacity_Int();                           
int std_vector_cGroupPtr_reserve();                       
int std_vector_cGroupPtr_ctor();                            
int std_vector_StringPtr_reserve();                       
int std_vector_StringPtr_ctor();                            
int std_list_deleter_PopVar_ctor();                                  
extern char D_004BD4C0;
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;

#pragma push
#pragma opt_common_subs off
char * cScriptInterpreter_ctor(char * arg0, int arg1) {
    struct { char pad40[8]; int f48; int f4C; } sl;
    int temp_s1_3;
    int temp_s1_4;
    char * temp_s1;
    char * temp_s1_2;

    std_list_deleter_PopVar_ctor();
    std_list_deleter_voidPtr_ctor_void(arg0 + 0xC);
    sl.f4C = 0x12C;
    temp_s1 = arg0 + 0x18;
    std_vector_StringPtr_ctor(temp_s1);
    std_vector_StringPtr_reserve(temp_s1, cArrayCapacity_Int(&sl.f4C));
    F_(temp_s1, 0xC, signed char) = 0;
    F_(arg0, 0x28, int) = 0;
    sl.f48 = 0x12C;
    temp_s1_2 = arg0 + 0x4E4C;
    std_vector_cGroupPtr_ctor(temp_s1_2);
    std_vector_cGroupPtr_reserve(temp_s1_2, cArrayCapacity_Int(&sl.f48));
    F_(temp_s1_2, 0xC, signed char) = 0;
    F_(arg0, 0x4E78, int) = arg1;
    temp_s1_3 = F_(arg0, 0x4E78, int) * 4;
    if (g_ProfileLockEnabled != 0) {
        Alloc_Lock(9);
    }
    g_ProfileLockDepth += 1;
    temp_s1_4 = cMemMan_Allocate(0, temp_s1_3, &D_004BD4C0, 0x34);
    if (g_ProfileLockEnabled != 0) {
        EnableIntc(9);
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
