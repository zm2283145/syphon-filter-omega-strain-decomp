#include "types.h"
typedef struct { float prev; float y; float coef; } g2DcState;
extern float D_004E1C78;
extern float D_004E1C7C;
void func_0031C7A8(short* in, float* out, int n, g2DcState* st) {
    float y = st->y;
    float coef = st->coef;
    float prev = st->prev;
    float x;
    if (y > 0.0f ? y < D_004E1C78 : y > D_004E1C7C) y = 0.0f;
    while (n-- > 0) {
        x = *in++;
        y = x - prev + coef * y;
        prev = x;
        *out++ = y;
    }
    st->prev = prev;
    st->y = y;
}