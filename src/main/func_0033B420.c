#include "types.h"
typedef struct { char pad[0x14]; } G4_E14;
typedef struct { int x; int size; G4_E14* data; } G4_Vec;
extern void func_00336A30(G4_E14* e, int f);
void func_0033B420(G4_Vec* v)
{
    G4_E14* b = v->data;
    G4_E14* e = b + v->size;
    while (b < e) {
        --e;
        func_00336A30(e, -1);
    }
    v->size = 0;
}