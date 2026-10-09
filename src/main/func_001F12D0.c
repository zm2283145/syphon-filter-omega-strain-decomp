/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern int func_0013B480(int, int);
extern float func_001D10A0(float, float);

int func_001F12D0(int a0, int a1) {
    func_0013B480(a0, a1);
    return a0;
}

/* Sets a range with x = f(x, 0) and y = f(y, x). */
Vec2f* func_001F1300(Vec2f* self, float x, float y) {
    self->x = x;
    self->y = y;
    self->x = func_001D10A0(self->x, 0.0f);
    self->y = func_001D10A0(self->y, self->x);
    return self;
}
