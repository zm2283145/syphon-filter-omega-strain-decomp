#pragma cplusplus on
#include "types.h"
typedef struct { unsigned short type; unsigned short f2; short p4; unsigned short f6; unsigned short f8; } Ev420C90;
extern "C" void func_0041E0F0(void* w, void* src, int kind, int a, int b);
extern "C" int func_00420C90(void* w, Ev420C90* e)
{
    bool ok = e->type == 1 && e->f2 == 0 && e->f8 == 0x40 && e->f6 == 0;
    if (ok) {
        if (e->f6 == 0) func_0041E0F0(w, w, 0x16, 0, 0);
        else func_0041E0F0(w, w, 0x17, 0, 0);
        return 1;
    }
    return 0;
}
