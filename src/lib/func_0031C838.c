#include "types.h"
typedef struct { int a; int b; float c; } T_0031C838;
extern T_0031C838* (*D_004E1D34)(int n, int size);
int func_0031C838(T_0031C838** pp, float x) { T_0031C838* p = D_004E1D34(1, sizeof(T_0031C838)); *pp = p; if (!p) return 1; p->c = x; p->b = 0; p->a = 0; return 0; }
