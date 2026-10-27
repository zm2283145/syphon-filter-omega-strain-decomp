#include "types.h"

char D_004987C8[] __attribute__((aligned(8))) = "[MPEG ERROR]%s\n"; /* 8-aligned in the original data */
extern int scePrintf(int, int, int, int, int, int, int, int);

int _ErrMessage(int a0, int a1, int a2, int a3, int t0, int t1, int t2, int t3) {
    return scePrintf((int)D_004987C8, a0, a2, a3, t0, t1, t2, t3);
}
