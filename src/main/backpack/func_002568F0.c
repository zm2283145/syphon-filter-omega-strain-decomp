#include "types.h"
typedef struct { char pad[0x314]; float t; } A2O256;
typedef struct { int pad0; int count; A2O256** items; } A2L256;
extern float D_004F7F70;
extern A2L256* D_004F7F30;
extern float D_0048AF18;
extern void func_00254770(A2O256* o);
void func_002568F0(float dt) {
    A2L256* l;
    int i;
    float* t;
    D_004F7F70 += dt;
    l = D_004F7F30;
    for (i = 0; i < l->count; i++) {
        t = &l->items[i]->t;
        if (!(*t < 0.0f)) {
            *t += dt;
            if (!(l->items[i]->t <= D_0048AF18)) {
                func_00254770(l->items[i--]);
            }
        }
    }
}
