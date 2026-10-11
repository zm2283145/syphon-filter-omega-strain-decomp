#include "types.h"
#include "vc_copy.h"
typedef struct { char pad[0xC]; int c; } C_D6D0;
typedef struct { char pad[0x30]; C_D6D0* p30; } B_D6D0;
typedef struct { char pad[0x60]; int t60; int t64; char pad68[8]; __int128 q70; __int128 q80; char pad90[4]; int x94; } A_D6D0;
extern B_D6D0* D_004FFC0C;
static inline int* ref_D6D0(C_D6D0* c) { return &c->c; }
#pragma push
#pragma peephole off
#pragma opt_propagation off
void func_0026D6D0(A_D6D0* a) {
    __int128* s; __int128* d;
    a->x94 = 0;
    d = &a->q80; s = &a->q70;
    a->t64 = a->t60;
    *d = *s;
    { int* pc = &D_004FFC0C->p30->c; a->t60 = *pc; }
}
#pragma pop