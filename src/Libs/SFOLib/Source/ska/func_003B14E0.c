#include "types.h"
typedef struct { float a; float b; unsigned char c; } S_3B14E0;
static inline float clamp_3B14E0(float x, float lo, float hi) { asm { max.s lo, x, lo
 min.s lo, lo, hi } return lo; }
S_3B14E0* cSkaPlaybackGroup_cPlaybackPosWithHistory_ctor(S_3B14E0* s, float x)
{
    float v;
    s->c = 1;
    v = clamp_3B14E0(x, 0.0f, 1.0f);
    s->b = v;
    s->a = v;
    return s;
}