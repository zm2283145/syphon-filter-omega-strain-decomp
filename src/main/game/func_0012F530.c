#include "types.h"
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
void Alloc_Unlock(int id);
void operator_delete(void* p);
void* func_0012F530(void* self, short flags)
{
    if (self) {
        if (g_ProfileLockEnabled)
            Alloc_Unlock(9);
        g_ProfileLockDepth--;
        if (flags > 0)
            operator_delete(self);
    }
    return self;
}