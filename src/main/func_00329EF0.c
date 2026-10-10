#include "types.h"
typedef struct { int a, b, c; } G4_A;
typedef struct { int a, b, c, d; } G4_B;
typedef struct { G4_A a; G4_B b; int c; } G4_E20;
extern void func_00329930(G4_A* d, G4_A* s);
extern void func_00329F60(G4_B* d, G4_B* s);
void func_00329EF0(G4_E20* p, unsigned int n, G4_E20* v)
{
    for (; n != 0; n--, p++) {
        func_00329930(&p->a, &v->a);
        func_00329F60(&p->b, &v->b);
        p->c = v->c;
    }
}