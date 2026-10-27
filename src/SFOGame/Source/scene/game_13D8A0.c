#pragma cplusplus on
#include "types.h"
typedef struct Nd_D8A0 { struct Nd_D8A0* prev; struct Nd_D8A0* next; int obj; } Nd_D8A0;
struct It_D8A0 { Nd_D8A0* n; It_D8A0() {} void operator=(const It_D8A0& o) { const float* s = (const float*)&o; float* d = (float*)this; *d = *s; } };
extern "C" {
void std_list_deleter_voidPtr_begin_void(It_D8A0*, int);
void std_list_deleter_voidPtr_end_void(It_D8A0*, int);
void std_list_cScenePtr_generic_iterator_ctor(It_D8A0*, It_D8A0*);
int cScene_UpdateActivation(int);
}
/* run cScene_UpdateActivation over every entry of the list (begin/end iterators) */
#pragma push
#pragma opt_propagation off
extern "C" void cSceneManager_UpdateActivation(int l)
{
    It_D8A0 it;
    It_D8A0 tmp;
    It_D8A0 b;
    It_D8A0 e;
    It_D8A0 t1;
    It_D8A0 t2;
    Nd_D8A0* n;
    std_list_deleter_voidPtr_begin_void(&t1, l);
    std_list_cScenePtr_generic_iterator_ctor(&b, &t1);
    n = b.n;
    std_list_deleter_voidPtr_end_void(&t2, l);
    std_list_cScenePtr_generic_iterator_ctor(&e, &t2);
    tmp.n = n;
    n = e.n;
    it = tmp;
    /* the iterator lives in memory: every access reloads it (volatile view) */
#define IT (((volatile It_D8A0*)&it)->n)
    while (IT != n) {
        cScene_UpdateActivation(IT->obj);
        IT = IT->next;
    }
#undef IT
}
#pragma pop
