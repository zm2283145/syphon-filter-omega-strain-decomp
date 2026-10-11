#pragma cplusplus on
#include "types.h"
extern "C" void operator_delete(void* allocation);
extern "C" void func_001F3DC0(void* m, int flags);
extern "C" void func_001ADB90(void* m, int flags);
extern "C" void* func_001F3E10(void* self, short deleteFlag)
{
    if (self) {
        func_001F3DC0((char*)self + 4, -1);
        func_001ADB90(self, -1);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}