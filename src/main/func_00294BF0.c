#pragma cplusplus on
#include "types.h"
struct V294BF0 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); };
typedef struct { char pad[0x44]; V294BF0* m44; } O294BF0;
extern "C" O294BF0* GuiWidget_FindChildByName(int a, int b);
extern "C" void func_00294BF0(int a, int b, int on)
{
    O294BF0* o = GuiWidget_FindChildByName(a, b);
    if (o) {
        if (on)
            o->m44->v3();
        else
            o->m44->v4();
    }
}