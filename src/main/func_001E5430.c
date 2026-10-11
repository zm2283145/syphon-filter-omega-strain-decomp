#include "types.h"
#include "vu0_ops.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
static inline void Set4_(V4* r, float x, float y, float z, float w) { r->x = x; r->y = y; r->z = z; r->w = w; }
V4* func_001E5430(V4* r, V4* p, V4* n) {
    float d = VU0_Dot3(n, p);
    { float w = -d; float z = n->z; float y = n->y; float x = n->x; r->x = x; r->y = y; r->z = z; r->w = w; }
    return r;
}