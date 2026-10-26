#pragma cplusplus on
#include "types.h"

struct Elem3966B0;
struct It3966B0 { Elem3966B0** p; Elem3966B0** first; int pad; Elem3966B0** last; };
struct Ring3966B0 { unsigned int cap; unsigned int count; unsigned int start; Elem3966B0** buf; };

extern "C" {
extern char D_004BC4D0[];
unsigned int* _cdeque_deleter_common_int_cap(Ring3966B0* r);
void _cdeque_deleter_common_int_generic_iterator_ctor(It3966B0* out, Ring3966B0* r, Elem3966B0** p);
void opDelete_cSkaSystemRequestP_int_bool_charP_etc(Elem3966B0* e, int pool, int flag, char* file, int line);
void details_compressed_pair_imp_cAllocator_cSkaSystem_Request_1_dtor(Ring3966B0* r, short flag);
void operator_delete(void* p);
}

static inline void DestroyRange(Elem3966B0** p, Elem3966B0** last, Elem3966B0** first, Elem3966B0** end)
{
    Elem3966B0** f = first; Elem3966B0** l = last;
    while (p != end) {
        Elem3966B0* x = *p;
        if (x) {
            if (x) opDelete_cSkaSystemRequestP_int_bool_charP_etc(x, 0, 0, D_004BC4D0, 0x64);
        }
        p++;
        if (p == l) p = f;
    }
}

extern "C" Ring3966B0* std_deque_deleter_common_cSkaSystem_Request_dtor(Ring3966B0* self, short flag)
{
    if (self) {
        if (self->count) {
            unsigned int idx;
            if (*_cdeque_deleter_common_int_cap(self))
                idx = (self->start + self->count) % *_cdeque_deleter_common_int_cap(self);
            else
                idx = 0;
            It3966B0 e;
            _cdeque_deleter_common_int_generic_iterator_ctor(&e, self, self->buf + idx);
            Elem3966B0** end = e.p;
            It3966B0 b;
            _cdeque_deleter_common_int_generic_iterator_ctor(&b, self, self->buf + self->start);
            DestroyRange(b.p, b.last, b.first, end);
        }
        if (self) details_compressed_pair_imp_cAllocator_cSkaSystem_Request_1_dtor(self, 0);
        if (flag > 0) operator_delete(self);
    }
    return self;
}



