/*
 * Matched functions (byte-identical with the retail executable).
 * fstream.cc
 */

#include "types.h"

extern int AsyncLoader_QueueUnload(int a0, int a1, int a2, int a3, int a4);

/* Forward to AsyncLoader_QueueUnload with the two middle arguments zero. */
int func_003EAA60(int a0, int a1, int a4) {
    return AsyncLoader_QueueUnload(a0, a1, 0, 0, a4);
}
