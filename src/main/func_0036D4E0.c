#include "types.h"
typedef struct { char pad[0x10]; int base; } B;
typedef struct { char pad[0x148]; B* b; unsigned char on; char p2[0x158-0x14D]; int off; char p3[4]; int* tbl; } S;
/* Returns offset + base + table[i] when enabled, else 0. */
int func_0036D4E0(S* s, int i) { if (!s->on) return 0; return s->off + s->b->base + s->tbl[i]; }
