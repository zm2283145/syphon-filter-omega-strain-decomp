#pragma cplusplus on
#include "types.h"
typedef struct Nd_D950 { struct Nd_D950* prev; struct Nd_D950* next; int obj; } Nd_D950;
struct It_D950 { Nd_D950* n; It_D950() {} void operator=(const It_D950& o) { const float* s = (const float*)&o; float* d = (float*)this; *d = *s; } };
extern "C" {
void func_0013B180(It_D950*, int);
void func_0013B160(It_D950*, int);
void func_0013D940(It_D950*, It_D950*);
int func_0013E1B0(int);
}
/* run func_0013E1B0 over every entry of the list (begin/end iterators) */
#pragma push
#pragma opt_propagation off
extern "C" void func_0013D950(int l)
{
    It_D950 it;
    It_D950 tmp;
    It_D950 b;
    It_D950 e;
    It_D950 t1;
    It_D950 t2;
    Nd_D950* n;
    func_0013B180(&t1, l);
    func_0013D940(&b, &t1);
    n = b.n;
    func_0013B160(&t2, l);
    func_0013D940(&e, &t2);
    tmp.n = n;
    n = e.n;
    it = tmp;
    /* the iterator lives in memory: every access reloads it (volatile view) */
#define IT (((volatile It_D950*)&it)->n)
    while (IT != n) {
        func_0013E1B0(IT->obj);
        IT = IT->next;
    }
#undef IT
}
#pragma pop
