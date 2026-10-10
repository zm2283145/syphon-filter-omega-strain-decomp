#include "types.h"
typedef struct { int f0; float f4; float f8; float fC; float f10; char b14; } S3F44E0;
void func_003F44E0(S3F44E0* s, float x) {
    s->f8 = x;
    s->fC = x;
    if (s->f4 <= x) {
        s->f10 = 1.0f;
    } else {
        s->f10 = -1.0f;
    }
    s->b14 = 0;
}