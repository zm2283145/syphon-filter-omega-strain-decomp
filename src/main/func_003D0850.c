#include "types.h"
typedef struct { char pad[0x3C]; float f3C; char pad40[0xC]; float f4C; float f50; char pad54[5]; char b59; } S3D0850;
void func_003D0850(S3D0850* s, float x, float t) {
    if (t == 0.0f) {
        s->f3C = x;
        s->b59 = 0;
    } else {
        s->f50 = x;
        s->f4C = (x - s->f3C) / (1000.0f * t);
        s->b59 = 1;
    }
}