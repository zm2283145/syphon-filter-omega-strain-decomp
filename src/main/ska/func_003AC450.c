#include "types.h"

typedef struct {
    unsigned int count;  /* +0x0 number of blocks */
    int unk4;
    unsigned int first;  /* +0x8 first block index */
    char** blocks;       /* +0xC */
    unsigned int pos;    /* +0x10 element position */
} BlockRing;

/* Returns the address of element pos: 8 elements of 0xF8 bytes per block, blocks in a ring. */
char* func_003AC450(BlockRing* r)
{
    unsigned int pos = r->pos;
    unsigned int block = (r->first + (pos >> 3)) % r->count;
    return r->blocks[block] + (pos & 7) * 0xF8;
}
