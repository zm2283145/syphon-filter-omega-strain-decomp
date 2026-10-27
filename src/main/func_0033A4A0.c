#pragma cplusplus on

#include "types.h"
#include "alloc_guard.h"

extern "C" {
void cMemMan_Deallocate(int pool, void* allocation, char* file, int line);
void* cArray_eRequirementState_dtor(void* self, short flags);
void opDelete_tAchievementP_int_bool_charP_etc(void* allocation, int pool, int destroy, char* file, int line);
}
void opDelete_tAchievementP_int_bool_charP_etc(void* allocation, int pool, int destroy, char* file, int line)
{
    AllocGuard guard;
    if (destroy) {
        if (allocation)
            cArray_eRequirementState_dtor((char*)allocation + 4, -1);
    }
    cMemMan_Deallocate(pool, allocation, file, line);
}