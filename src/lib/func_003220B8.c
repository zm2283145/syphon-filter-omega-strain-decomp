#include "types.h"
typedef struct { int a; int b; float c; } T_003220B8;
extern T_003220B8* (*D_004E1D34)(int n, int size);
int func_003220B8(T_003220B8** pp) { int r = 0; T_003220B8* p; if (!pp) return 1; *pp = 0; p = D_004E1D34(1, sizeof(T_003220B8)); if (!p) r = 1; else { *pp = p; p->c = 5.0f; } return r; }
