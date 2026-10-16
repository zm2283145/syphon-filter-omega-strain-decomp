#include "types.h"

typedef struct TimedObj {
    char pad[0x4C];
    float seconds;
} TimedObj;

extern void* Time_GetMilliseconds(TimedObj* self);
extern float SoftFloat_U64ToFloat(void* src);

/* Caches a millisecond value from the source as seconds at +0x4C. */
void func_00288A40(TimedObj* self) {
    self->seconds = SoftFloat_U64ToFloat(Time_GetMilliseconds(self)) / 1000.0f;
}
