#include "types.h"
typedef struct { char pad[0x54]; char on; } T;
typedef struct { char pad[0x6C]; T* t; } S;
extern void func_00286690(T*);
/* Clears the child's active flag and notifies it, if a child exists. */
void func_002856E0(S* s) { if (s->t) { s->t->on = 0; func_00286690(s->t); } }
