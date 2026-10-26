#pragma cplusplus on

#include "types.h"

/* Deleting destructor: destroy the member at +4, then delete. */
extern "C" void operator_delete(void* allocation);
extern "C" void* std_vector_StatType_dtor(void* self, short deleteFlag);

typedef struct { int pad0; int member; } Obj_00351FC0;

extern "C" Obj_00351FC0* MissionStats_StatsRequirement_dtor(Obj_00351FC0* self, short deleteFlag)
{
    if (self) {
        void* m = &self->member;
        if (m)
            std_vector_StatType_dtor(m, -1);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}