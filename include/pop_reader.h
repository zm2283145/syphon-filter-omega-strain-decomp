#ifndef POP_READER_H
#define POP_READER_H

/*
 * PopReader: cursor over a loaded .pop population stream (Loader_Init*
 * functions, ~18 src files under Loader/ and population/). Plain C or C++.
 *   unk0, size, base (stream start), cur (read cursor)
 * Usual idiom: align cur to 4, then
 *   if ((unsigned char)cPopulation_SeekBlock(r, 'TAG:')) { n = *(int*)r->cur; r->cur += 4; ... }
 * Tags are 4-char little-endian words, e.g. 0x3A4D4143 "CAM:",
 * 0x3A505247 "GRP:". cPopulation_SeekBlock is 0x00178BB0.
 * #define POP_READER_NO_PROTOS to keep a typed local declaration.
 */
#include "layout_assert.h"

typedef struct PopReader {
    int unk0;            /* +0x0 */
    int size;            /* +0x4 */
    unsigned int base;   /* +0x8 */
    char* cur;           /* +0xC */
} PopReader; /* 0x10 */
LAYOUT_SIZE(PopReader, 0x10);

#ifndef POP_READER_NO_PROTOS
#ifdef __cplusplus
extern "C" {
#endif
int cPopulation_SeekBlock(void* reader, int tag); /* low byte nonzero when found */
#ifdef __cplusplus
}
#endif
#endif

#endif /* POP_READER_H */
