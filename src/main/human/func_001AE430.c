#include "types.h"
#include "v4_asm_copy.h"
typedef struct { char pad[0x187]; char c; char pad2[8]; __int128 q; float x; float y; } XE430;
void Actor_ApplyControlInput(XE430* t, __int128* q, char c, float x, float y) {
    __int128* d = &t->q; __int128 v;
    __asm__ volatile("lq %0,0(%1)" : "=r"(v) : "r"(q));
    asm { sq v, 0(d) }
    t->x = x;
    t->y = y;
    t->c = c;
}