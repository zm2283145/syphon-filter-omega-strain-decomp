#include "types.h"

typedef struct { char pad[0x10]; float f10; } Src_D640;
typedef struct {
    char pad[0x1C]; float f1C; float f20; float f24; float f28; float f2C; Src_D640* p30; float f34;
} Ch_D640;

void AnimChannel_SetDuration(Ch_D640* c, float d) {
    float s;
    if (d >= 0.0f) {
        s = d * c->f2C;
        c->f1C = c->f1C * s;
        c->f24 = c->f24 * s;
        c->f28 = d;
        c->f2C = d != 0.0f ? 1.0f / d : 0.0f;
        c->f34 = c->p30->f10;
    }
}