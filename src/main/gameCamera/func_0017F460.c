#include "types.h"
typedef struct { Vec4 a; Vec4 b; } VecPair;
/* Builds a vector pair from two vectors. */
#pragma peephole off
VecPair* Placement_GetIdentity(VecPair* p, Vec4* a, Vec4* b) { p->a = *a; p->b = *b; return p; }
#pragma peephole reset
