#include "types.h"
typedef struct { int w[3]; } Ent34F670;
typedef struct { int w[4]; } Sub34F670;
typedef struct { int base[4]; Ent34F670 ents[5]; Sub34F670 sub; } T34F670;
typedef struct { char pad[0x70]; int v70[3]; } S34F670;
extern void func_00351320(void* v);
extern void func_00298690(T34F670* t);
extern void func_0034F920(Ent34F670* e);
extern void func_0034F810(Sub34F670* s);
extern void func_00350FD0(void* v, int n, T34F670* value);
extern void func_00351070(Sub34F670* s, int flags);
extern void String_Dtor(T34F670* t, int flags);
void func_0034F670(S34F670* o)
{
    T34F670 t;
    T34F670* tp;
    Ent34F670* p;
    Sub34F670* m;
    func_00351320(o->v70);
    tp = &t;
    func_00298690(tp);
    p = tp->ents;
    do {
        func_0034F920(p);
        p++;
    } while (p != (Ent34F670*)&tp->sub);
    func_0034F810(&tp->sub);
    func_00350FD0(o->v70, 0x11, &t);
    m = &t.sub;
    if (m) {
        if (m) {
            if (m) func_00351070(m, 0);
        }
    }
    String_Dtor(&t, 0);
}

