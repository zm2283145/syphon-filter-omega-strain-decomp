#include "types.h"
typedef struct { char pad[0xAC]; signed char v; } T;
typedef struct { char pad[0x88]; T* t; } S;
/* Returns the linked object's byte at +0xAC, or 1 when none. */
int func_0033D8C0(S* s) { if (s->t) return s->t->v; return 1; }
