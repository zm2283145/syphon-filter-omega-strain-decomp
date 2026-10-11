#include "types.h"
extern volatile float D_004E1C5C;
typedef struct { char pad[0x14]; signed char a; signed char b; } S_0031ECC0;
int func_0031ECC0(S_0031ECC0* p, short n, float x) { int r = 0; if (p->a == 1 && n == p->a && p->b == n && D_004E1C5C <= x) r = 1; return r; }
