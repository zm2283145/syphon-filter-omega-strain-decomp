/*
 * Matched functions (byte-identical with the retail executable).
 * Script global: sets the current objective text colour (16-byte colour record
 * at D_004F7590) through the shared colour setter func_00227A40.
 */

#include "types.h"

extern char D_004F7590[];
extern float func_00227A40(int, int, int, int, float);

float Global_SetObjectiveCurrColor(int r, int g, int b, float a) {
    return func_00227A40((int)D_004F7590, r, g, b, a);
}
