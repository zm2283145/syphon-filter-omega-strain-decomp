#pragma cplusplus on
#include "types.h"
#include "v4_asm_copy.h"
struct V2C2370 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); };
union Q2C2370 { __int128 q; struct { float x, y, z, w; } f; };
struct Sub2C2370 { char pad[0x10]; Q2C2370 pos; };
struct T2C2370 { V2C2370 v; char pad4[0xC]; Sub2C2370 sub; char pad40[0x20]; unsigned char b50; };
struct A2C2370 { char pad[0x50]; T2C2370* t; char pad54[0x10]; float heading; };
extern "C" {
float Math_Atan2f(float y, float x);
void Actor_BaseLogicUpdate(A2C2370* a, float dt);
}
extern "C" void func_002C2370(A2C2370* a, float dt)
{
    T2C2370* t = a->t;
    Q2C2370 p;
    if (t->b50)
        t->v.v20();
    Sub2C2370* s = (Sub2C2370*)((char*)t + 0x10);
    V4Copy(&p, &s->pos);
    a->heading = Math_Atan2f(p.f.x, *(volatile float*)&p.f.y);
    Actor_BaseLogicUpdate(a, dt);
}

