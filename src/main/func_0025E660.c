#include "types.h"
typedef struct { float a; float b; float c; unsigned char fl; } S25E660;
static inline int isActive_b6(S25E660* s) { return !s->fl && s->b > 0.0f; }
void func_0025E660(S25E660* s, float dt)
{
    if (isActive_b6(s)) {
        s->a += s->c * dt;
        if (s->a < 0.0f || s->a > s->b) {
            *(int*)&s->a = 0;
            *(int*)&s->b = 0;
        }
    }
}
