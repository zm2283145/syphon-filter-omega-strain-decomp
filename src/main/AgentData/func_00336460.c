#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
int Mem_Free(int, int, char *, int);                         
int __destroy_array(char * , char *, int, int);               
int std_vector_charPtr_dtor_void_2(char * , int);                         
int std_vector_eAchievementState_dtor(char * , int);                         
int std_vector_deleter_tMissionStats_dtor(char * , int);                         
int operator_delete(char * );                          
extern unsigned char g_ProfileLockEnabled;
extern char cArray_tAchievement_dtor;
}
extern "C" char * cAgentData_dtor(char * arg0, long long arg1) {
    int temp_s2;
    char * temp_a0;
    char * temp_a0_2;
    char * temp_a0_3;

    if (arg0 != NULL) {
        temp_s2 = F_(arg0, 0x9A4, int);
        {
            AllocGuard g;
        Mem_Free(0, temp_s2, "AgentData.cc", 0xE0);
        }
        temp_a0 = arg0 + 0xB58;
        if (temp_a0 != NULL) {
            std_vector_charPtr_dtor_void_2(temp_a0, -1);
        }
        temp_a0_2 = arg0 + 0xAF8;
        if (temp_a0_2 != NULL) {
            std_vector_eAchievementState_dtor(temp_a0_2, -1);
        }
        __destroy_array(arg0 + 0xAA8, &cArray_tAchievement_dtor, 0x10, 5);
        temp_a0_3 = arg0 + 0xC4;
        if ((temp_a0_3 != NULL) && (temp_a0_3 != NULL) && (temp_a0_3 != NULL)) {
            std_vector_deleter_tMissionStats_dtor(temp_a0_3, 0);
        }
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            operator_delete(arg0);
        }
    }
    return arg0;
}
