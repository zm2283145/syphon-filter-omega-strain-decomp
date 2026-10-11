#include "types.h"
extern float D_004B5EA8[];
extern float D_004B5E90[];
extern float D_004E1BC0;
extern float func_00323660(float x);
float func_00321FA0(float a, float b) { int i; for (i = 0; i < 5; i++) if (a > D_004B5EA8[i]) break; return D_004B5E90[i] + func_00323660(b) * 0.5f + D_004E1BC0; }
