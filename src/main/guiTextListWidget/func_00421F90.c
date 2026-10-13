#include "types.h"
typedef struct { char pad[0x14]; } G4_E14;
typedef struct { int x; int size; G4_E14* data; } G4_Vec;
extern void String_Dtor(G4_E14* e, int f);
static inline void destroy_(G4_E14* p) { if (p) String_Dtor(p, 0); }
void func_00421F90(G4_Vec* v)
{
    G4_E14* b = v->data;
    G4_E14* e = b + v->size;
    while (b < e) {
        G4_E14* p = --e;
        if (p) destroy_(p);
    }
    v->size = 0;
}