#include "types.h"
typedef struct { char pad[8]; unsigned char active; char p9[3]; unsigned char c; unsigned char d; char pe[2]; int a10; float v[4]; char p24[4]; float f28; } S_260990;
void func_00260990(S_260990* s, unsigned char active, float x, float y, float z, float w) {
    s->active = active;
    s->a10 = 0;
    s->v[3] = 0;
    s->v[2] = 0;
    s->v[1] = 0;
    s->v[0] = 0;
    s->c = 0;
    s->d = 0;
    s->v[0] = x;
    s->v[1] = y;
    s->v[2] = z;
    s->v[3] = w;
    if (!s->active) {
        s->f28 = 0.0f;
    }
}