#pragma cplusplus on
#include "types.h"
struct V2CCE80 { float x, y, z, w; } __attribute__((aligned(16)));
struct Sp2CCE80 { char pad[0x10]; V2CCE80 c0; V2CCE80 c1; V2CCE80 c2; };
extern "C" {
extern V2CCE80 D_00587B50;
extern V2CCE80 D_00587B60;
extern V2CCE80 D_00587B70;
}
static inline void SetA2CCE80(Sp2CCE80* p, V2CCE80 a) { p->c0 = a; }
static inline void SetB2CCE80(Sp2CCE80* p, V2CCE80 b) { p->c1 = b; }
static inline void SetC2CCE80(Sp2CCE80* p, V2CCE80 c) { p->c2 = c; }
/* Resets the sprite's three colours to the defaults. */
extern "C" void func_002CCE80(Sp2CCE80* sp)
{
    if (sp) {
        SetA2CCE80(sp, D_00587B50);
        SetB2CCE80(sp, D_00587B60);
        SetC2CCE80(sp, D_00587B70);
    }
}
