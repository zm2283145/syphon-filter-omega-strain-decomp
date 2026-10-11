#pragma opt_common_subs off
#pragma bool off
#include "types.h"
typedef struct { char pad0[0xB0]; int x4; } E_1A07F0;
typedef struct { E_1A07F0** p; } It_1A07F0;
typedef struct { char pad[0xB4]; int vec; int xC; } O_1A07F0;
extern E_1A07F0** func_001E5250(int* v);
extern E_1A07F0** func_001E5220(int* v);
extern void func_001E5240(It_1A07F0* out, int* v, E_1A07F0*** p);
static inline int Eq_1A07F0(E_1A07F0** a, E_1A07F0** b) { return a == b; }
void func_00397080(O_1A07F0* self)
{
    It_1A07F0 b;
    It_1A07F0 e;
    E_1A07F0** t0;
    E_1A07F0** t1;
    E_1A07F0** it;
    E_1A07F0** end;
    t0 = func_001E5250(&self->vec);
    func_001E5240(&b, &self->vec, &t0);
    it = b.p;
    t1 = func_001E5220(&self->vec);
    func_001E5240(&e, &self->vec, &t1);
    end = e.p;
    while (Eq_1A07F0(it, end) ^ 1) {
        (*it)->x4 = 0;
        it++;
    }
    self->xC = 0;
}


