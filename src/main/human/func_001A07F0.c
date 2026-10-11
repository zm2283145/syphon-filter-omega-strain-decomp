#pragma opt_common_subs off
#pragma bool off
#include "types.h"
typedef struct { int pad0; int x4; } E_1A07F0;
typedef struct { E_1A07F0** p; } It_1A07F0;
typedef struct { char pad[8]; int vec; int xC; } O_1A07F0;
extern E_1A07F0** func_001A08C0(int* v);
extern E_1A07F0** func_001A0890(int* v);
extern void func_001A08B0(It_1A07F0* out, int* v, E_1A07F0*** p);
static inline int Eq_1A07F0(E_1A07F0** a, E_1A07F0** b) { return a == b; }
void func_001A07F0(O_1A07F0* self)
{
    It_1A07F0 b;
    It_1A07F0 e;
    E_1A07F0** t0;
    E_1A07F0** t1;
    E_1A07F0** it;
    E_1A07F0** end;
    t0 = func_001A08C0(&self->vec);
    func_001A08B0(&b, &self->vec, &t0);
    it = b.p;
    t1 = func_001A0890(&self->vec);
    func_001A08B0(&e, &self->vec, &t1);
    end = e.p;
    while (Eq_1A07F0(it, end) ^ 1) {
        (*it)->x4 = 0;
        it++;
    }
    self->xC = 0;
}


