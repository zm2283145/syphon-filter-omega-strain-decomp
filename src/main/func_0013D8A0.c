#pragma cplusplus on
#include "types.h"
typedef struct Nd_D8A0 { struct Nd_D8A0* prev; struct Nd_D8A0* next; int obj; } Nd_D8A0;
struct It_D8A0 { Nd_D8A0* n; It_D8A0() {} void operator=(const It_D8A0& o) { const float* s = (const float*)&o; float* d = (float*)this; *d = *s; } };
extern "C" {
void func_0013B180(It_D8A0*, int);
void func_0013B160(It_D8A0*, int);
void func_0013D940(It_D8A0*, It_D8A0*);
int Region_ProcessChange(int);
}
/* run Region_ProcessChange over every entry of the list (begin/end iterators) */
#pragma push
#pragma opt_propagation off
extern "C" void World_UpdateZoneTrackers(int l)
{
    It_D8A0 it;
    It_D8A0 tmp;
    It_D8A0 b;
    It_D8A0 e;
    It_D8A0 t1;
    It_D8A0 t2;
    Nd_D8A0* n;
    func_0013B180(&t1, l);
    func_0013D940(&b, &t1);
    n = b.n;
    func_0013B160(&t2, l);
    func_0013D940(&e, &t2);
    tmp.n = n;
    n = e.n;
    it = tmp;
    /* the iterator lives in memory: every access reloads it (volatile view) */
#define IT (((volatile It_D8A0*)&it)->n)
    while (IT != n) {
        Region_ProcessChange(IT->obj);
        IT = IT->next;
    }
#undef IT
}
#pragma pop
