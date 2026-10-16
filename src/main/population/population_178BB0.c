/*
 * main/population: 2 files, 00178BB0-00178C50
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00178BB0 */
#pragma push /* merge_units */
#include "types.h"

typedef struct E3PopReader {
    int unk0;
    int size;      /* 0x4: buffer size in bytes */
    unsigned int base;    /* 0x8 */
    int* cur;      /* 0xC */
} E3PopReader;

/* Scans the population buffer for a tag word; leaves the cursor just after it. */
int Pop_FindTag(E3PopReader* r, int tag) {
    int off;
    int v;
    v = *r->cur;
    r->cur++;
    if (v == tag) {
        return 1;
    }
    r->cur = (int*)r->base;
    off = 0;
    v = *r->cur;
    r->cur++;
    if (v != tag) {
        do {
            r->cur = (int*)(r->base + off);
            off += 4;
            if (r->cur > (int*)(r->base + r->size)) {
                r->cur = (int*)(r->size + r->base);
                return 0;
            }
            v = *r->cur;
            r->cur++;
        } while (v != tag);
    }
    return 1;
}
#pragma pop /* merge_units */
/* merge_units: end func_00178BB0 */

/* merge_units: begin func_00178C50 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose00_types.h"

/* Subtract from the word at +0x0C. */
void func_00178C50(Unk0013BDE0* self, int amount) {
    self->unk0C = self->unk0C - amount;
}
#pragma pop /* merge_units */
/* merge_units: end func_00178C50 */
