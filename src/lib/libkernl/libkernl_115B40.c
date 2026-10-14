#include "types.h"
extern int func_00115B30(int n);
/* Calls func_00115B30 for n in 13..47, else returns -1. */
int func_00115B40(int n) { if ((unsigned)(n - 13) < 35) return func_00115B30(n); return -1; }
