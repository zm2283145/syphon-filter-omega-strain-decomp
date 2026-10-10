#include "types.h"
typedef struct { char pad[0xC]; unsigned char flag; } Sub;
typedef struct { int v; int z; Sub sub; } S;
extern void func_00393A20(Sub*);
/* Constructor: copies a value, clears a field, inits the sub-object and sets its flag. */
S* func_003939D0(S* s, int* v) { Sub* sub = &s->sub; s->v = *v; s->z = 0; func_00393A20(sub); sub->flag = 1; return s; }
