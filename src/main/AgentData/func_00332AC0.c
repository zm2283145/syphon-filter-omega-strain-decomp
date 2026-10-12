#pragma cplusplus on
#include "types.h"
struct E332AC0 { int f0; int id; int p8[3]; int value; };
struct V332AC0 { E332AC0* data; int count; };
struct A332AC0 { char pad[0xB08]; int bits[1]; };
extern "C" {
extern V332AC0 D_00532B10;
E332AC0** func_003305C0(V332AC0* v);
void PtrVec_PushBack_1C1080(void* vec, int* v);
}
static inline bool Neq332AC0(E332AC0* a, E332AC0* b) { return !(a == b); }
/* Collects the values of every table entry whose bit is set in the agent's flag array. */
extern "C" void func_00332AC0(A332AC0* a, void* out)
{
    E332AC0* it = *func_003305C0(&D_00532B10);
    E332AC0* end = *func_003305C0(&D_00532B10) + D_00532B10.count;
    for (; Neq332AC0(it, end); it++) {
        int id = it->id;
        if ((a->bits[id / 32] >> (id & 31)) & 1) {
            int v[1];
            v[0] = it->value;
            PtrVec_PushBack_1C1080(out, v);
        }
    }
}
