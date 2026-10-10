#include "types.h"
typedef struct { char pad[0x78]; float t; } S293660;
extern void func_00292E80(S293660*);
extern void func_0041E3B0(S293660*, float);
void func_00293660(S293660* s, float dt) {
    s->t += dt;
    if (!(s->t <= 1.0f)) {
        func_00292E80(s);
        s->t -= 1.0f;
    }
    func_0041E3B0(s, dt);
}