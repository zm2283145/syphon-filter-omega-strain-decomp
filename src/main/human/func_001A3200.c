#include "types.h"
typedef struct { int w[16]; } Buf_1A3200;
typedef struct { char pad[0x3464]; int h; } O_1A3200;
extern void func_001A32A0(Buf_1A3200* b, O_1A3200* o);
extern void func_002561D0(int h, Buf_1A3200* b, int f);
void func_001A3200(O_1A3200* o)
{
    Buf_1A3200 b;
    if (o->h) {
        func_001A32A0(&b, o);
        func_002561D0(o->h, &b, 0);
    }
}