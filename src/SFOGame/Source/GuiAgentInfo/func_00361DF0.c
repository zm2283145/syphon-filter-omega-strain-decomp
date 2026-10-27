#pragma cplusplus on

#include "types.h"

/* Deleting destructor: string members at +0x3C and +0x30. */
extern "C" {
void operator_delete(void* allocation);
void* String_Dtor(void* self, short deleteFlag);
}
extern "C" void* GuiAgentInfo_AgentInfo_dtor(void* self, short deleteFlag)
{
    if (self) {
        char* a = (char*)self + 0x3C;
        if (a)
            String_Dtor(a, 0);
        char* b = (char*)self + 0x30;
        if (b)
            String_Dtor(b, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}