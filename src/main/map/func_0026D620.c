#pragma cplusplus on
#include "types.h"
struct Q_26D620 { float a, b, c, d; Q_26D620& operator=(const Q_26D620& o) { Q_26D620* pd = this; const Q_26D620* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } return *this; } } __attribute__((aligned(16)));
struct R2_26D620 { char pad[0x68]; int x68; };
struct R_26D620 { char pad[8]; R2_26D620* x8; };
struct S_26D620 {
    int x0;
    int x4;
    int x8;
    char padC[0x54];
    int x60;
    char pad64[0xC];
    Q_26D620 x70;
    Q_26D620 x80;
    float x90;
    float x94;
};
extern "C" {
R_26D620* func_00272AC0(int a);
void func_0026D040(S_26D620* s, float t);
void func_003E79C0(int h, float t);
void func_0026D620(S_26D620* s, float dt);
}
void func_0026D620(S_26D620* s, float dt)
{
    if (s->x94 > 0.0f) {
        s->x94 -= dt;
        if (s->x94 <= 0.0f) {
            R_26D620* r = func_00272AC0(s->x0);
            if (r && r->x8) {
                s->x60 = r->x8->x68;
                s->x80 = s->x70;
                s->x90 = 0.0f;
            }
            s->x94 = 0.0f;
        }
    }
    func_0026D040(s, dt);
    func_003E79C0(s->x8, dt);
}

