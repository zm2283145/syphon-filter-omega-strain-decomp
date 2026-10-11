#include "types.h"
extern void func_00145200(void* self);
extern void func_0036E220(void* p, int flag);
extern void func_003CC0F0(void* self, int flag);
extern void operator_delete(void* p);
void* func_00147390(char* self, short flag)
{
    if (self) {
        func_00145200(self);
        func_0036E220(self + 0x1C, -1);
        func_003CC0F0(self, 0);
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}