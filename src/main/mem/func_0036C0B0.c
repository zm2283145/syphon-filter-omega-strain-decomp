#include "types.h"
typedef struct { unsigned int val : 28; unsigned int top : 4; } Packed28;
/* Returns the low 28-bit field of the packed word. */
unsigned int func_0036C0B0(Packed28* p) { return p->val; }
