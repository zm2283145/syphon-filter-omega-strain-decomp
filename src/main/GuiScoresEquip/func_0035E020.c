#pragma cplusplus on
#include "types.h"
#include "v4_asm_copy.h"
struct V35E020 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); };
union Q35E020 { __int128 q; struct { float x, y, z, w; } f; };
struct Sub35E020 { char pad[0x10]; Q35E020 pos; };
struct T35E020 { V35E020 v; char pad4[0xC]; Sub35E020 sub; char pad40[0x20]; unsigned char b50; };
struct A35E020 { char pad[0x50]; T35E020* t; char pad54[0x10]; float heading; };
extern "C" {
float Math_Atan2f(float y, float x);
void Actor_BaseLogicUpdate(A35E020* a, float dt);
}
extern "C" void func_0035E020(A35E020* a, float dt)
{
    T35E020* t = a->t;
    Q35E020 p;
    if (t->b50)
        t->v.v20();
    Sub35E020* s = (Sub35E020*)((char*)t + 0x10);
    V4Copy(&p, &s->pos);
    a->heading = Math_Atan2f(p.f.x, *(volatile float*)&p.f.y);
    Actor_BaseLogicUpdate(a, dt);
}

