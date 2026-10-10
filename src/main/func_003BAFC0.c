#include "types.h"
extern void* D_00539248;
extern void func_00382C30(void*, int);
typedef struct { int a; int b; } Pair;
/* Applies the global handler to the first id and, if valid, the second id. */
void func_003BAFC0(Pair* p) { func_00382C30(D_00539248, p->a); if (p->b != -1) func_00382C30(D_00539248, p->b); }
