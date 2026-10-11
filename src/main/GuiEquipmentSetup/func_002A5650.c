#pragma cplusplus on
#include "types.h"
#include "v4_asm_copy.h"
struct V2A5650 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); };
union Q2A5650 { __int128 q; struct { float x, y, z, w; } f; };
struct Sub2A5650 { char pad[0x10]; Q2A5650 pos; };
struct T2A5650 { V2A5650 v; char pad4[0xC]; Sub2A5650 sub; char pad40[0x20]; unsigned char b50; };
struct A2A5650 { char pad[0x50]; T2A5650* t; char pad54[0x10]; float heading; };
extern "C" {
float Math_Atan2f(float y, float x);
void Actor_BaseLogicUpdate(A2A5650* a, float dt);
}
extern "C" void func_002A5650(A2A5650* a, float dt)
{
    T2A5650* t = a->t;
    Q2A5650 p;
    if (t->b50)
        t->v.v20();
    Sub2A5650* s = (Sub2A5650*)((char*)t + 0x10);
    V4Copy(&p, &s->pos);
    a->heading = Math_Atan2f(p.f.x, *(volatile float*)&p.f.y);
    Actor_BaseLogicUpdate(a, dt);
}

