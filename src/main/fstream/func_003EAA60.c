/*
 * Matched functions (byte-identical with the retail executable).
 * fstream.cc
 */

#include "types.h"

extern int func_003EAA70(int a0, int a1, int a2, int a3, int a4);

/* Forward to func_003EAA70 with the two middle arguments zero. */
int func_003EAA60(int a0, int a1, int a4) {
    return func_003EAA70(a0, a1, 0, 0, a4);
}
