#include "types.h"
typedef struct { float a; float b; float ia; float ib; } S1AD750;
static inline float fmin_(float a, float b) { float r; asm { min.s r, a, b } return r; }
S1AD750* func_001AD750(S1AD750* s, float a, float b) {
    s->a = a;
    s->b = fmin_(b, a);
    s->ia = s->a != 0.0f ? 1.0f / s->a : 3.4028235e38f;
    s->ib = s->b != 0.0f ? 1.0f / s->b : 3.4028235e38f;
    return s;
}