#pragma cplusplus on
#include "types.h"

struct Elem3966B0;
struct It3966B0 { Elem3966B0** p; Elem3966B0** first; int pad; Elem3966B0** last; };
struct Ring3966B0 { unsigned int cap; unsigned int count; unsigned int start; Elem3966B0** buf; };

extern "C" {
extern char D_004BC4D0[];
unsigned int* func_00396B60(Ring3966B0* r);
void func_00396B20(It3966B0* out, Ring3966B0* r, Elem3966B0** p);
void func_00396810(Elem3966B0* e, int pool, int flag, char* file, int line);
void func_00393D70(Ring3966B0* r, short flag);
void operator_delete(void* p);
}

static inline void DestroyRange(Elem3966B0** p, Elem3966B0** last, Elem3966B0** first, Elem3966B0** end)
{
    Elem3966B0** f = first; Elem3966B0** l = last;
    while (p != end) {
        Elem3966B0* x = *p;
        if (x) {
            if (x) func_00396810(x, 0, 0, D_004BC4D0, 0x64);
        }
        p++;
        if (p == l) p = f;
    }
}

extern "C" Ring3966B0* func_003966B0(Ring3966B0* self, short flag)
{
    if (self) {
        if (self->count) {
            unsigned int idx;
            if (*func_00396B60(self))
                idx = (self->start + self->count) % *func_00396B60(self);
            else
                idx = 0;
            It3966B0 e;
            func_00396B20(&e, self, self->buf + idx);
            Elem3966B0** end = e.p;
            It3966B0 b;
            func_00396B20(&b, self, self->buf + self->start);
            DestroyRange(b.p, b.last, b.first, end);
        }
        if (self) func_00393D70(self, 0);
        if (flag > 0) operator_delete(self);
    }
    return self;
}



