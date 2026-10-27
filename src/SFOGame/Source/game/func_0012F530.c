#include "types.h"
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
void EnableIntc(int id);
void operator_delete(void* p);
void* cTimerDisable_dtor(void* self, short flags)
{
    if (self) {
        if (g_ProfileLockEnabled)
            EnableIntc(9);
        g_ProfileLockDepth--;
        if (flags > 0)
            operator_delete(self);
    }
    return self;
}