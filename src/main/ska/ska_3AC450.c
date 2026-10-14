/*
 * main/ska: range (4 files, 003AC450-003AC520)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "ska_types.h"

/* merge_units: begin func_003AC450 */
#pragma push /* merge_units */
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
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003AC450(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003AC450 */

/* merge_units: begin func_003AC4A0 */
#pragma push /* merge_units */
typedef struct Ring {
    unsigned int size;  /* 0x00 */
    int unk04;
    unsigned int head;  /* 0x08 */
    int* items;         /* 0x0C */
} Ring;
int* Ring_SlotAt(Ring* ring, unsigned int offset); /* gsynth: defined below */
/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */


#if 0 /* merge_units */
extern char** Ring_SlotAt(void* blocks, unsigned int block);
#endif /* merge_units */
#define Ring_SlotAt(a0, a1) ((char * *)Ring_SlotAt((void *)(a0), (a1))) /* merge_units */

extern void* func_003AC520(void* self);

/* Address of entry (first + index) in a block array of 248-byte entries, eight per block. */
char* func_003AC4A0(SkaBlockArray* self, int index) {
    int i = index + self->first;
    return *Ring_SlotAt(func_003AC520(self), (unsigned int)i >> 3) + (i & 7) * 248;
}
#undef Ring_SlotAt /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003AC4A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003AC4A0 */

/* merge_units: begin func_003AC4F0 */
#pragma push /* merge_units */
/* Returns the address of the slot `offset` past the ring head. */
int* Ring_SlotAt(Ring* ring, unsigned int offset) {
    return &ring->items[(ring->head + offset) % ring->size];
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003AC4F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003AC4F0 */

/* merge_units: begin func_003AC520 */
#pragma push /* merge_units */
void* func_003AC520(void* self) {
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003AC520(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003AC520 */
