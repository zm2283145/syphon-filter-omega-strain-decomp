/*
 * Matched functions (byte-identical with the retail executable).
 * Not inside a known source-file range: after inventory.cc (ends 0x004719B0),
 * before NetMsgThrottle.cc (starts 0x00472050).
 */

#include "types.h"

extern int std_vector_imp_tRecord_reserve(int, int);

int func_00471BF0(int a0, int a1) {
    return std_vector_imp_tRecord_reserve(a0, a1);
}

Rel* func_00471C00(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
