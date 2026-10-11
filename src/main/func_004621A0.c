#pragma cplusplus on
#pragma opt_common_subs off
#include "types.h"
extern "C" {
extern char D_004E17C0[];
extern char D_004DF5C0[];
void operator_delete(void* allocation);
void func_0036E220(void* self, int flags);
void func_00461DC0(void* self, int flags);
void func_0041F370(void* self, int flags);
}
struct O4621A0 { void* vtable; };
extern "C" O4621A0* func_004621A0(O4621A0* self, short deleteFlag)
{
    if (self) {
        self->vtable = D_004E17C0;
        {
            char* q = (char*)self + 0x90;
            if (q) {
                char* p = (char*)self + 0xB0;
                if (p) {
                    func_0036E220((char*)self + 0x194, -1);
                    func_0036E220((char*)self + 0xF8, -1);
                }
                {
                    char* a = (char*)self + 0x90;
                    if (a) {
                        if (a) {
                            if (a)
                                func_00461DC0(a, 0);
                        }
                    }
                }
            }
        }
        if (self) {
            self->vtable = D_004DF5C0;
            func_0041F370(self, 0);
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}