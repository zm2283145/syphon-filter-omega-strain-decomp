/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern int String_CtorCStr_13B480(int, int);
extern float CLAMP_LOW(float, float);

int cString_ctor_charP(int a0, int a1) {
    String_CtorCStr_13B480(a0, a1);
    return a0;
}

/* Sets a range with x = f(x, 0) and y = f(y, x). */
Vec2f* cSkaAnimPlaybackRange_ctor(Vec2f* self, float x, float y) {
    self->x = x;
    self->y = y;
    self->x = CLAMP_LOW(self->x, 0.0f);
    self->y = CLAMP_LOW(self->y, self->x);
    return self;
}
