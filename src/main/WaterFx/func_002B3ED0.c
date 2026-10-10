#include "types.h"
typedef struct RippleNode_b6 { int p0; struct RippleNode_b6* next; unsigned char pad[0x60 - 8]; float timer; } RippleNode_b6;
typedef struct { int p0; int list; int sentinel; } RippleEmitter_b6;
extern RippleNode_b6* func_002B3EC0(int*);
extern int func_002B3950(int*);
extern void func_002B3FB0(RippleNode_b6**, int);
extern void func_002B49A0(RippleNode_b6**, int*, RippleNode_b6**);
static inline float fmax_b6(float a, float b) { float r; asm { max.s r, a, b } return r; }
void WaterFx_AgeRipples(RippleEmitter_b6* e, float dt)
{
    RippleNode_b6* n = func_002B3EC0(&e->sentinel)->next;
    RippleNode_b6* ret[1];
    RippleNode_b6* it[1];
    RippleNode_b6* end[1];
    while (func_002B3FB0(end, func_002B3950(&e->list)), n != end[0]) {
        n->timer = fmax_b6(0.0f, n->timer - dt);
        if (n->timer == 0.0f) {
            RippleNode_b6* cur = n;
            n = n->next;
            it[0] = cur;
            func_002B49A0(ret, &e->list, it);
        } else {
            n = n->next;
        }
    }
}