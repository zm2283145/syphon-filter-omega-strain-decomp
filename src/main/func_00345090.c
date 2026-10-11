#pragma cplusplus on
#include "types.h"
#include "v4_asm_copy.h"
struct V345090 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); };
union Q345090 { __int128 q; struct { float x, y, z, w; } f; };
struct Sub345090 { char pad[0x10]; Q345090 pos; };
struct T345090 { V345090 v; char pad4[0xC]; Sub345090 sub; char pad40[0x20]; unsigned char b50; };
struct A345090 { char pad[0x50]; T345090* t; char pad54[0x10]; float heading; };
extern "C" {
float Math_Atan2f(float y, float x);
void Actor_BaseLogicUpdate(A345090* a, float dt);
}
extern "C" void func_00345090(A345090* a, float dt)
{
    T345090* t = a->t;
    Q345090 p;
    if (t->b50)
        t->v.v20();
    Sub345090* s = (Sub345090*)((char*)t + 0x10);
    V4Copy(&p, &s->pos);
    a->heading = Math_Atan2f(p.f.x, *(volatile float*)&p.f.y);
    Actor_BaseLogicUpdate(a, dt);
}

