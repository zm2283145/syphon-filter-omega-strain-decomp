#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_D4E0;
typedef struct { char pad[0x130]; V4_D4E0 v; } O_D4E0;
#pragma push
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
void func_0028D4E0(O_D4E0* o, float z) {
    V4_D4E0 r; V4_D4E0 t;
    V4_D4E0* d2;
    V4_D4E0* d3;
    V4_D4E0* d1;
    float b; float c; float d; float a;
    d1 = &t; *d1 = o->v; d2 = &t; d2->z = z; d3 = &r; *d3 = *d2;
    d = r.w; c = r.z; b = r.y; a = r.x;
    o->v.x = a; o->v.y = b; o->v.z = c; o->v.w = d;
}
#pragma pop