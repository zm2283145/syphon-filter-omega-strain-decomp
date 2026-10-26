/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

/* Init a cursor over a buffer: start, current and offset. */
void sceGifPkInit(BufCursor* c, int base) {
    c->cur = base;
    c->pos = 0;
    c->start = base;
}

/* Rewind a cursor to its start. */
int sceGifPkReset(BufCursor* c) {
    int start;

    start = c->start;
    c->pos = 0;
    c->cur = start;
    return start;
}
