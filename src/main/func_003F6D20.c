#include "types.h"
typedef struct { int state; unsigned char mode; char p5[0xF]; int f14; int f18; char p1C[0x2C]; char* buf; int pos; char p50[0xC]; int size; } S3F6D20;
extern void func_003A6C20(char* buf, int pos, char* end, unsigned int a, int b);
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void func_003F6D20(S3F6D20* s)
{
    if (s->mode != 3) {
        char* b = s->buf;
        func_003A6C20(b, s->pos / 1024 * 1024, b + s->size, 0, 0);
    } else {
        func_003A6C20(s->buf, s->pos / 1024 * 1024, (char*)s->size, s->f14, s->f18);
    }
    s->state = 2;
}
#pragma pop
