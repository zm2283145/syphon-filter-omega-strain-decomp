#include "types.h"
typedef struct { char pad[0x54]; char on; } T;
typedef struct { char pad[0x6C]; T* t; } S;
extern void cTank_Fire(T*);
/* Clears the child's active flag and notifies it, if a child exists. */
void cTank_Fire_2(S* s) { if (s->t) { s->t->on = 0; cTank_Fire(s->t); } }
