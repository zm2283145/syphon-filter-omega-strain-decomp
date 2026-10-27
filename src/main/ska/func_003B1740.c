#include "types.h"
typedef struct AC_3B1740 { int id; float weight; unsigned char active; char pad[7]; Vec4 v; } AC_3B1740;
/* Initialises an animation contribution record and returns it. */
#pragma peephole off
AC_3B1740* cSkaPlaybackItem_ctor(AC_3B1740* self, int id, float weight, Vec4* v) {
    self->id = id;
    self->weight = weight;
    self->active = 1;
    self->v = *v;
    return self;
}
#pragma peephole reset