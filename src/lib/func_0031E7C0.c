#include "types.h"
typedef struct { float* buf; int pad4; short count; } g2Scl;
extern float D_004E1C70;
void func_0031E7C0(g2Scl* s) {
    short i;
    float* p;
    if (s->count < 0x55) {
        float k = D_004E1C70;
        p = s->buf;
        for (i = 0; i < 0x21; i++) {
            *p++ *= k;
        }
    } else {
        s->count = 0x54;
    }
    s->count++;
}