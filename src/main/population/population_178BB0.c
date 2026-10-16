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