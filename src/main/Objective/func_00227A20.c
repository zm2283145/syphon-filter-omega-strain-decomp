/*
 * Matched functions (byte-identical with the retail executable).
 * Script global: sets the default objective text colour (16-byte colour record
 * at D_004F7580) through the shared colour setter func_00227A40.
 */

#include "types.h"

extern char D_004F7580[];
extern float func_00227A40(int, int, int, int, float);

float Global_SetObjectiveColor(int r, int g, int b, float a) {
    return func_00227A40((int)D_004F7580, r, g, b, a);
}
