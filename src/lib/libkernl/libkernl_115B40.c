#include "types.h"
extern int _SetTLBEntry(int n);
/* Calls _SetTLBEntry for n in 13..47, else returns -1. */
int SetTLBEntry(int n) { if ((unsigned)(n - 13) < 35) return _SetTLBEntry(n); return -1; }
