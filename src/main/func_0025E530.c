#pragma cplusplus on
#include "types.h"
union A25E530 { int i; float f; void* p; };
struct Fx25E530 { int f0; int f4; char p8[0x28]; unsigned char b30, b31; char p32[2]; int f34; float f38, f3C, f40, f44; };
extern "C" Fx25E530* g_VisionFxMan;
#pragma push
#pragma opt_dead_assignments off
extern "C" int Script_setFxMode(A25E530* args)
{
    int mode = args[0].i;
    Fx25E530* f = g_VisionFxMan;
    if (f->f0 != mode) f->f4 = mode;
    if (f->f4 == -1 && mode) {
        f->f4 = mode;
        f->f34 = 0;
        *(int*)&f->f44 = 0;
        *(int*)&f->f40 = 0;
        *(int*)&f->f3C = 0;
        *(int*)&f->f38 = 0;
        f->b30 = 0;
        f->b31 = 0;
        f->f38 = 0.0f;
        f->f3C = 1.0f;
        f->f40 = 0.0f;
        f->f44 = 0.0f;
    }
    return 0;
}
#pragma pop
