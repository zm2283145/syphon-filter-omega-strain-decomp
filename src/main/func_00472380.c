/*
 * Matched functions (byte-identical with the retail executable).
 * Not inside a known source-file range: after NetMsgThrottle.cc (ends 0x00472370).
 */

#include "types.h"

Map* func_00472380(Map* m, unsigned char* cmp) {
    m->count = 0;
    m->head = 0;
    m->cmp = *cmp;
    m->hp = &m->head;
    return m;
}
