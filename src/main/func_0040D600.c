#include "types.h"
typedef struct { char pad[0x1C]; char item[0x1C]; } ED600;
typedef struct { ED600 e[(0x560) / 0x38]; char pad[0x560 - (0x560 / 0x38) * 0x38]; int count; } PD600;
typedef struct { PD600* p; } OD600;
typedef struct { int m0; int size; } VD600;
extern void func_00330280(VD600* v, void** item);
/* Collects pointers to every entry's item into the vector. */
void MemCardWrap_Enumerate(OD600* o, VD600* v) {
    int i;
    v->size = 0;
    for (i = 0; i < o->p->count; i++) {
        void* it = o->p->e[i].item;
        func_00330280(v, &it);
    }
}