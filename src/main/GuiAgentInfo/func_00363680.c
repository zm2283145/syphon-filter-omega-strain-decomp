/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#include "types.h"

/* Virtual-call view of Curve: only the slots used here are named (vtable offset in comments). */
struct Curve {
    virtual void v00(); virtual void v01(); virtual void v02();
    virtual float Evaluate(); /* +0x14 */
    float start;   /* +0x04 */
    float current; /* +0x08 */
    float value;   /* +0x0C */
    float target;  /* +0x10 */
};

/* Sets start/current/target to v, re-evaluates the value (virtual +0x14) and returns self. */
extern "C" Curve* func_00363680(Curve* self, float v)
{
    self->target = v;
    self->current = v;
    self->start = v;
    self->value = self->Evaluate();
    return self;
}
