#pragma cplusplus on

#include "types.h"

/* For every phase overlapping the given one, run its handler. */
typedef struct { unsigned char pad[0xC]; unsigned char sub[8]; } Phase_3ACEA0;
typedef struct { int pad0; int count; } Vec_3ACEA0;
typedef struct { unsigned char enabled; unsigned char pad[0x3B]; Vec_3ACEA0 phases; } Obj_3ACEA0;

extern "C" {
Phase_3ACEA0** func_003AD1D0(Vec_3ACEA0* v);
int Phase_Overlaps(void* a, Phase_3ACEA0* b);
void func_003ACF60(void* p);
}

static inline bool Ne_3ACEA0(Phase_3ACEA0* a, Phase_3ACEA0* b) { return !(a == b); }

extern "C" void func_003ACEA0(Obj_3ACEA0* o, void* phase)
{
    if (o->enabled) {
        Phase_3ACEA0* it;
        Phase_3ACEA0* end;
        it = *func_003AD1D0(&o->phases);
        end = *func_003AD1D0(&o->phases) + o->phases.count;
        for (; Ne_3ACEA0(it, end); it++) {
            if (Phase_Overlaps(phase, it))
                func_003ACF60(it->sub);
        }
    }
}