#include "types.h"
extern void NpcPerception_Clear(void* self);
extern void func_0016E040(void* p, int flag);
extern void operator_delete(void* p);
void* func_0016DFD0(char* self, short flag)
{
    if (self) {
        void* m;
        NpcPerception_Clear(self);
        m = self + 0x30;
        if (m)
            func_0016E040(m, 0);
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}