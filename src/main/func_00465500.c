#include "types.h"
typedef struct { char pad[0x6C]; float t; } T465500;
extern void func_00465870(T465500* p);
void func_00465500(T465500* p, float dt) {
    float v;
    func_00465870(p);
    v = p->t + 30.0f * dt;
    p->t = v;
    if (v > 300.0f) p->t = v - 300.0f;
}