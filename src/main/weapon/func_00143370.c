#include "types.h"
float Math_Tan(float);
float Math_Atan(float);
float func_00143370(float arg0, float arg1) {
    float r = Math_Tan((0.017453292f * arg1) / 2.0f);
    r = r / arg0;
    r = 2.0f * Math_Atan(r); return 57.295776f * r;
}