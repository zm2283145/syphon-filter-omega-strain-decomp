#pragma cplusplus on
#include "types.h"
typedef struct { float a; float b; float c; unsigned char d; } B8S_25E5B0;
extern "C" int D_005383C4;
static inline bool b8off(B8S_25E5B0* s) { return !s->d; }
extern "C" void func_0025E5B0(B8S_25E5B0* s) {
    float v = 0.0f;
    unsigned char ok = 0;
    if (b8off(s) && s->b > 0.0f) ok = 1;
    if (ok) {
        v = 255.0f * (s->a / s->b);
    } else if (s->c == 1.0f) {
        v = 255.0f;
    }
    if (s->d) v = 0.0f;
    D_005383C4 = (unsigned char)(int)v;
}