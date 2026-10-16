#include "types.h"
float Math_WrapAnglePi(float a) {
    for (;;) {
        if (a > 3.1415927f) {
            a += -6.2831855f;
        } else if (a < -3.1415927f) {
            a += 6.2831855f;
        } else {
            return a;
        }
    }
}