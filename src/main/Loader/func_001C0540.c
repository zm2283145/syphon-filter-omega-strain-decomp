#include "types.h"

extern void func_001C4750(void* self, int* a, int* b);

/* Calls func_001C4750 with two scratch outputs; returns self. */
void* func_001C0540(void* self)
{
    int b;
    int a;
    func_001C4750(self, &a, &b);
    return self;
}
