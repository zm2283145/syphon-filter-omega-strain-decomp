#include "types.h"
typedef struct { int pad0; float cur; float lo_; float hi_; float vdir; unsigned char fl; } S3F4510;
void func_003F4510(S3F4510* s, float lo_, float hi_, unsigned char fl)
{
    if (hi_ < lo_) {
        float t = lo_;
        lo_ = hi_;
        hi_ = t;
    }
    s->lo_ = lo_;
    s->hi_ = hi_;
    if (s->cur < lo_) {
        s->vdir = 1.0f;
    } else if (s->cur > hi_) {
        s->vdir = -1.0f;
    } else if (s->vdir != 1.0f && s->vdir != -1.0f) {
        s->vdir = 1.0f;
    }
    s->fl = fl;
}
