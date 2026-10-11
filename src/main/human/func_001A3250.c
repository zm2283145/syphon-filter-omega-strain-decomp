#include "types.h"
typedef struct { int w[16]; } Buf_1A3250;
typedef struct { char pad[0x3464]; int h; } O_1A3250;
extern void func_001A32A0(Buf_1A3250* b, O_1A3250* o);
extern void func_002561D0(int h, Buf_1A3250* b, int f);
extern void func_00256180(int h);
void func_001A3250(O_1A3250* o)
{
    Buf_1A3250 b;
    if (o->h) {
        func_001A32A0(&b, o);
        func_002561D0(o->h, &b, 1);
        func_00256180(o->h);
    }
}