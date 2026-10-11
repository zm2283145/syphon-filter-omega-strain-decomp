#include "types.h"
typedef struct {
    int f0;
    void* f4;
    void* f8;
    float fC;
    float f10;
    short f14;
    short f16;
    unsigned short f18;
    unsigned short f1A;
    short f1C;
    unsigned char f1E;
} S_0031E3C8;
extern float func_0031E7B8(void* p);
extern float func_0031DEC8(float x);
extern void func_0031E920(float x, void* p);
extern void func_0031E988(float a, float b, short n, void* p);
extern void func_0031EA18(float x, void* p);
extern int func_0031EBC8(float a, short n, unsigned short m, void* p);
extern int func_0031ECC0(void* p, int f, float x);
extern void func_0031E698(int n, void* p);
extern int func_0031E548(void* p, int n);
extern void func_0031E7C0(void* p);
int func_0031E3C8(S_0031E3C8* s, float a, float b)
{
    float g, r;
    int pos;
    unsigned char c;
    s->fC = a;
    s->f10 = b;
    g = func_0031E7B8(s->f8);
    pos = s->f16 >= 0;
    if (!s->f18) s->f18 = 1;
    if (!s->f1A) s->f1A = 90;
    r = func_0031DEC8(a);
    c = (unsigned int)(r + 0.5f);
    func_0031E920(a, s->f4);
    func_0031E988(r, g, s->f18, s->f4);
    func_0031EA18(a, s->f4);
    s->f1C = func_0031EBC8(r, s->f18, s->f1A, s->f4);
    if (func_0031ECC0(s->f4, pos, b)) {
        func_0031E698(c, s->f8);
        if (s->f1E) s->f14 = func_0031E548(s->f8, s->f16);
    } else {
        func_0031E7C0(s->f8);
    }
    return 0;
}