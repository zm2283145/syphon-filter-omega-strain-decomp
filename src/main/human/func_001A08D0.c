#pragma opt_common_subs off
#include "types.h"
typedef struct { char pad[0x10]; int set; } E_1A08D0;
typedef struct { E_1A08D0*** p; } It_1A08D0;
typedef struct { int n; } SIt_1A08D0;
typedef struct { char pad[0x108]; int vec; } O_1A08D0;
extern E_1A08D0*** func_001A08C0(int* v);
extern E_1A08D0*** func_001A0890(int* v);
extern void func_001A08B0(It_1A08D0* out, int* v, E_1A08D0**** p);
extern void* func_001A0B20(int* s);
extern void func_001A0B10(SIt_1A08D0* out, void* s);
extern void func_001A0AF0(SIt_1A08D0* out, void* s);
extern int func_001A09F0(SIt_1A08D0* a, SIt_1A08D0* b);
extern void* func_001A0AE0(SIt_1A08D0* a);
extern void* func_001A0AD0(void* p);
extern void func_001A0A30(void* p);
extern void func_001A0A10(SIt_1A08D0* a);
static inline int Eq_1A08D0(E_1A08D0*** a, E_1A08D0*** b) { return a == b; }
void MotionCtrl_DetachRoots(O_1A08D0* self)
{
    It_1A08D0 b;
    It_1A08D0 e;
    E_1A08D0*** t0;
    E_1A08D0*** t1;
    SIt_1A08D0 i;
    SIt_1A08D0 ie;
    int* v = &self->vec;
    E_1A08D0*** it;
    E_1A08D0*** end;
    t0 = func_001A08C0(v);
    func_001A08B0(&b, v, &t0);
    it = b.p;
    t1 = func_001A0890(v);
    func_001A08B0(&e, v, &t1);
    end = e.p;
    while (Eq_1A08D0(it, end) ^ 1) {
        void* s = func_001A0B20(&(**it)->set);
        func_001A0B10(&i, s);
        func_001A0AF0(&ie, s);
        while (func_001A09F0(&i, &ie)) {
            func_001A0A30(func_001A0AD0(func_001A0AE0(&i)));
            func_001A0A10(&i);
        }
        it++;
    }
}
