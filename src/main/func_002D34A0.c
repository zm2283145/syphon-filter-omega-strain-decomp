#include "types.h"

extern float D_00489DD0[];

/* Looks up a float table entry by byte index. */
float func_002D34A0(int unused, unsigned char i) {
    return D_00489DD0[i];
}
