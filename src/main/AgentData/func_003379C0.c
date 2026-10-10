#include "types.h"
typedef struct { int a, b, c; } G4_In;
typedef struct { char a; G4_In b; unsigned char c; } G4_E14;
extern void func_0033A9E0(G4_In* d, G4_In* s);
void func_003379C0(G4_E14* p, unsigned int n, G4_E14* v)
{
    for (; n != 0; n--, p++) {
        p->a = v->a;
        func_0033A9E0(&p->b, &v->b);
        p->c = v->c;
    }
}