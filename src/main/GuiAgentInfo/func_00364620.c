#pragma cplusplus on
#include "types.h"
#include "v4_asm_copy.h"
struct V364620 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); };
union Q364620 { __int128 q; struct { float x, y, z, w; } f; };
struct Sub364620 { char pad[0x10]; Q364620 pos; };
struct T364620 { V364620 v; char pad4[0xC]; Sub364620 sub; char pad40[0x20]; unsigned char b50; };
struct A364620 { char pad[0x50]; T364620* t; char pad54[0x10]; float heading; };
extern "C" {
float Libc_Atan2f(float y, float x);
void cGOBJ_NextFrame(A364620* a, float dt);
}
extern "C" void func_00364620(A364620* a, float dt)
{
    T364620* t = a->t;
    Q364620 p;
    if (t->b50)
        t->v.v20();
    Sub364620* s = (Sub364620*)((char*)t + 0x10);
    V4Copy(&p, &s->pos);
    a->heading = Libc_Atan2f(p.f.x, *(volatile float*)&p.f.y);
    cGOBJ_NextFrame(a, dt);
}

