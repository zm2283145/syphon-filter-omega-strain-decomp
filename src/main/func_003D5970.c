#include "types.h"
extern void func_00383150(void* self, short del);
extern void func_003D5B40(void);
extern void func_003D5AF0(void);
extern void func_003D5A30(void);
extern void __destroy_array(void* arr, void* dtor, int size, int n);
extern void operator_delete(void* p);
void* func_003D5970(void* self, short del)
{
    if (self) {
        void* m = (char*)self + 0x1175C;
        if (m)
            func_00383150(m, 0);
        __destroy_array((char*)self + 0x10540, (void*)func_003D5B40, 0xC0, 0x18);
        __destroy_array((char*)self + 0x4D0, (void*)func_003D5AF0, 0x80, 0x200);
        __destroy_array((char*)self + 0x10, (void*)func_003D5A30, 0x130, 4);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
