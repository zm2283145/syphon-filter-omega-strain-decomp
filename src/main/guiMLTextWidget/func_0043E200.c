#include "types.h"
typedef struct { char p0[0x20]; int f20; } C43E200;
typedef struct { char p0[0x40]; float f40; char p44[4]; C43E200* child; int value; char p50[0x10]; int f60; int f64; } W43E200;
extern int func_0036A2F0(int);
extern int func_00414790(void);
extern int func_00418420(int, int);
#pragma push
#pragma opt_common_subs off
void func_0043E200(W43E200* w, int arg1)
{
    C43E200* c;
    w->value = func_00418420(func_00414790(), arg1);
    c = w->child;
    if (c != 0) c->f20 = w->value;
    w->f60 = (int)w->f40 / func_0036A2F0(w->value);
    w->f64 = w->f60;
}
#pragma pop
