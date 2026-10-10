#include "types.h"
int Mtx_IsTranslationZero(float* m) { return m[12] == 0.0f && m[13] == 0.0f && m[14] == 0.0f; }