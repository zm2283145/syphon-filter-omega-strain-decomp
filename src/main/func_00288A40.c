#include "types.h"

typedef struct TimedObj {
    char pad[0x4C];
    float seconds;
} TimedObj;

extern void* func_003698B0(TimedObj* self);
extern float func_001002D0(void* src);

/* Caches a millisecond value from the source as seconds at +0x4C. */
void func_00288A40(TimedObj* self) {
    self->seconds = func_001002D0(func_003698B0(self)) / 1000.0f;
}
