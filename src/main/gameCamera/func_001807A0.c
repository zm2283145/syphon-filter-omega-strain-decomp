#pragma cplusplus on
#include "types.h"
#include "v4_asm_copy.h"
struct V1807A0 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); };
union Q1807A0 { __int128 q; struct { float x, y, z, w; } f; };
struct Sub1807A0 { char pad[0x10]; Q1807A0 pos; };
struct T1807A0 { V1807A0 v; char pad4[0xC]; Sub1807A0 sub; char pad40[0x20]; unsigned char b50; };
struct A1807A0 { char pad[0x50]; T1807A0* t; char pad54[0x10]; float heading; };
extern "C" {
float Math_Atan2f(float y, float x);
void Actor_BaseLogicUpdate(A1807A0* a, float dt);
}
extern "C" void func_001807A0(A1807A0* a, float dt)
{
    T1807A0* t = a->t;
    Q1807A0 p;
    if (t->b50)
        t->v.v20();
    Sub1807A0* s = (Sub1807A0*)((char*)t + 0x10);
    V4Copy(&p, &s->pos);
    a->heading = Math_Atan2f(p.f.x, *(volatile float*)&p.f.y);
    Actor_BaseLogicUpdate(a, dt);
}

