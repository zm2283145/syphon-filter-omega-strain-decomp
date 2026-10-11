#include "types.h"
extern void func_003E2A40(void* self, short del);
extern void func_003E2B30(void* self, short del);
extern void func_003E2C20(void* self, short del);
extern void func_003E2CA0(void* self, short del);
extern void operator_delete(void* p);
void* func_003E3FF0(void* self, short del)
{
    if (self) {
        void* a = (char*)self + 0x4E4C;
        void* b;
        void* c;
        if (a)
            func_003E2A40(a, -1);
        b = (char*)self + 0x18;
        if (b)
            func_003E2B30(b, -1);
        c = (char*)self + 0xC;
        if (c)
            func_003E2C20(c, 0);
        if (self)
            func_003E2CA0(self, 0);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
