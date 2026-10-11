#include "types.h"
#pragma cplusplus on
typedef struct { unsigned short a0; unsigned short a2; short pad4; unsigned short a6; unsigned short a8; } E354A70;
typedef struct { char pad[0x94]; unsigned char a94; char pad95[0x1AB]; int a240; } S354A70;
extern "C" {
void* func_004147A0(void);
void func_0041E0F0(void* self, void* mgr, int a, int b, int c);
void func_00355490(S354A70* self, int on);
bool func_00356BE0(void* self, E354A70* e);
bool func_00354A70(S354A70* self, E354A70* e);
}
bool func_00354A70(S354A70* self, E354A70* e)
{
    bool b = e->a0 == 1 && e->a2 == 0 && e->a8 == 0x40 && e->a6 == 0;
    if (b) {
        if (self->a94) {
            func_0041E0F0(self, func_004147A0(), 0x10, 2, 0);
            if (self->a240 == 0) func_00355490(self, 1);
            else func_00355490(self, 0);
        }
        return 1;
    }
    return func_00356BE0(self, e);
}