#include "types.h"
typedef struct { float a, b, c, d; } AnimRate;
static inline float b4inv(float r) { return (r != 0.0f) ? 1.0f / r : 3.4028235e38f; }
AnimRate* AnimRate_Init(AnimRate* p, float r) {
    p->a = r;
    p->b = r;
    p->c = b4inv(r);
    p->d = b4inv(r);
    return p;
}