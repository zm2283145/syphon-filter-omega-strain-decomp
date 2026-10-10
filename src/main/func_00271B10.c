#include "types.h"
typedef struct { int a; void* snd; } B5cObj;
extern void func_003F44E0(void* s, float v);
extern void func_003F43D0(void* s, float v);
void func_00271B10(B5cObj* o, float x) {
    if (x < 0.0f) x = 0.0f;
    if (x > 1.0f) x = 1.0f;
    if (o->snd) {
        func_003F44E0(o->snd, 10.0f + 7.0f * x);
        func_003F43D0(o->snd, 7.0f);
    }
}