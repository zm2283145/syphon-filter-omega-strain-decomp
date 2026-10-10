#include "types.h"

extern void func_0041EBF0(void* self);
extern int func_004147A0(void);
extern void func_0041E0F0(void* self, int a, int b, int c, int d);

/* Runs the base setup, then calls func_0041E0F0 with func_004147A0's result and constants 0x10, 3, 0. */
void func_002A86A0(void* self)
{
    func_0041EBF0(self);
    func_0041E0F0(self, func_004147A0(), 0x10, 3, 0);
}
