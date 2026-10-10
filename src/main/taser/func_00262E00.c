#include "types.h"
#pragma cplusplus on
struct A2V262 { virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B(); virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void f64(void*, int, int); };
typedef struct { char pad[0x58]; A2V262* v; } A2P262;
typedef struct { int pad0; A2P262* p; char b8; char pad9[7]; int f10; int n14; } A2S262;
extern int D_0048B168;
extern float D_0048B140;
extern "C" void* func_00262F20(void* p);
extern "C" void func_00264720(A2S262* s, void* b);
extern "C" void func_00262F30(A2S262* s, float dt);
extern "C" void func_00264530(A2S262* s, void* b);
extern "C" void func_00265790(A2S262* s, float f, int x);
extern "C" void func_00262E00(A2S262* s, float dt) {
    int n = s->n14;
    int i = 0;
    int* po;
    int out[4];
    int buf[12];
    while (!!n && i < D_0048B168) {
        s->n14--;
        func_00262F20(&s->f10);
        i++;
        n--;
    }
    if (n > 1) {
        s->p->v->f64(buf, 0, 0);
        po = out;
        func_00264720(s, po);
        if ((float)n < D_0048B140) func_00262F30(s, dt);
        func_00264530(s, po);
    }
    func_00265790(s, 1.0f, 1);
    if (n == 0) s->b8 = 0;
}




