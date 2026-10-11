#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V_5E40;
typedef struct { V_5E40 a; V_5E40 b; float c; float d; int e; } T_5E40;
static inline V_5E40* VAsg_(V_5E40* d, const V_5E40* s) { *d = *s; return d; }
#pragma push
#pragma peephole off
#pragma opt_dead_assignments off
#pragma opt_propagation off
#pragma opt_common_subs off
T_5E40* func_003E5E40(T_5E40* d, const T_5E40* s) {
    void* r;
    r = VAsg_(&d->a, &s->a); r = VAsg_(&d->b, &s->b); d->c = s->c; d->d = s->d; d->e = s->e; r = d;
    return r;
}
#pragma pop