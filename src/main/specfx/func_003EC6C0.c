#include "types.h"
typedef struct { int busy; int pad4; int pad8; unsigned char done; char padD[3]; float time; } OC6C0;
extern void func_003EC710(OC6C0* a, OC6C0* b);
void func_003EC6C0(OC6C0* s, float dt) {
    s->time += dt;
    func_003EC710(s, s);
    if (s->busy == 0) s->done = 1;
}
