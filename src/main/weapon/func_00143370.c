#include "types.h"
float Math_Tan(float);
float func_001212E0(float);
float func_00143370(float arg0, float arg1) {
    float r = Math_Tan((0.017453292f * arg1) / 2.0f);
    r = r / arg0;
    r = 2.0f * func_001212E0(r); return 57.295776f * r;
}