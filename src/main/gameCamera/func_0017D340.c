#include "types.h"
typedef struct { char pad[0x40]; float f40; float f44; } A2C17D;
typedef struct { A2C17D* c; float t; } A2S17D;
extern void func_0017D380(void* a, A2C17D* c, float v);
void func_0017D340(void* a, A2S17D* s) {
    A2C17D* c = s->c;
    float d = c->f40 - s->t;
    float v;
    if (c->f40 != 0.0f) v = d * c->f44;
    else v = 1.0f;
    func_0017D380(a, c, v);
}
