#pragma cplusplus on
#include "types.h"
struct R_414BE0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); };
struct W_414BE0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual W_414BE0* v15();
    char pad4[0x10]; unsigned short flags; char pad16[6]; int f1C; W_414BE0* f20; char pad24[0x20]; R_414BE0* f44;
};
struct N_414BE0 { int prev; int next; W_414BE0* obj; };
struct O_414BE0 { char pad[0x20]; W_414BE0* f20; char pad24[4]; int f28; N_414BE0* f2C; char pad30[0x24]; char l54[0xC]; unsigned char b60; };
extern "C" {
extern char D_0055A300[];
int func_00138DA0(...);
int func_0015AF40(...);
int func_002A8890(...);
int func_002A88B0(...);
int func_002CCDE0(...);
int func_002CCDF0(...);
int* func_002CCE10(...);
int func_002CCE20(...);
int func_002CCE30(...);
int func_002CCE40(...);
int func_0028C0A0(...);
int func_0028C090(...);
void func_0036A240(void* p);
void func_0041E0F0(void* a, void* b, int kind, int v, int f);
void func_00414BE0(O_414BE0* o, W_414BE0* w);
}

void func_00414BE0(O_414BE0* o, W_414BE0* w)
{
    char* r1;
    char* r2;
    int e3a;
    int e3b;
    char* t1;
    char* t2;
    int y1;
    int x1;
    int y2;
    int x2;
    int it1;
    int tmp1;
    int end1;
    int e2a;
    int it2;
    int tmp2;
    int end2;
    int e2b;
    N_414BE0** hp;
    W_414BE0* c;
    if (w == 0) return;
    if (o->b60) {
        func_002CCE40(&it1);
        func_002CCE30(&tmp1, o->l54);
        func_002CCE20(&it1, &tmp1);
        func_002A88B0(&end1, o->l54);
        if (func_002A8890(&it1, &end1) != 0) {
loop_1:
            if ((void*)*func_002CCE10(&it1) != (void*)w) {
                func_002CCDF0(&it1);
                func_002A88B0(&end1, o->l54);
                if (func_002A8890(&it1, &end1) != 0) goto loop_1;
            }
        }
        func_002CCDE0(&r1, &it1);
        func_0028C0A0(&e2a, o->l54);
        func_0028C090(&e3a, &e2a);
        if ((int)r1 != e3a) {
            t1 = r1;
            func_0015AF40(&x1, &t1);
            func_00138DA0(&y1, o->l54, &x1);
        }
    }
    func_002CCE40(&it2);
    func_002CCE30(&tmp2, &o->f28);
    func_002CCE20(&it2, &tmp2);
    func_002A88B0(&end2, &o->f28);
    if (func_002A8890(&it2, &end2) != 0) {
loop_2:
        if ((void*)*func_002CCE10(&it2) != (void*)w) {
            func_002CCDF0(&it2);
            func_002A88B0(&end2, &o->f28);
            if (func_002A8890(&it2, &end2) != 0) goto loop_2;
        }
    }
    func_002CCDE0(&r2, &it2);
    func_0028C0A0(&e2b, &o->f28);
    func_0028C090(&e3b, &e2b);
    if ((int)r2 == e3b) return;
    w->f1C = 0;
    hp = &o->f2C;
    if (o->f2C->obj == w) func_0036A240(D_0055A300);
    c = ((N_414BE0*)r2)->obj;
    if (c) {
        if (c->flags & 8) c->f44->v6();
        t2 = r2;
        func_0015AF40(&x2, &t2);
        func_00138DA0(&y2, &o->f28, &x2);
    }
    func_0041E0F0(o, w, 0x19, 0, 0);
    if (o->f20 && w->f20 == o->f20) o->f20->f44->v8();
    w->f20 = 0;
    if (o->f28) {
        o->f20 = (*hp)->obj->f20;
        if (!o->f20) o->f20 = (*hp)->obj->v15();
    } else {
        o->f20 = 0;
    }
    if (o->f20) o->f20->f44->v7();
}