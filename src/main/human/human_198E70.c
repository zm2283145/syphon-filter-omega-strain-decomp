/*
 * main/human: range (3 files, 00198E70-00198F20)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "human_types.h"

/* merge_units: begin func_00198E70 */
#pragma push /* merge_units */
typedef struct { unsigned int capacity; int unk4; unsigned int start; int* data; } Ring00198EF0;
int* RingBuffer_At(Ring00198EF0* ring, unsigned int index); /* gsynth: defined below */void* func_00198F20(void* self); /* gsynth: defined below */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


/* Deque of 248-byte elements, 8 per block: map at +0x00, start +0x10, size +0x14. */
#if 0 /* merge_units */
extern int** RingBuffer_At(void* map, unsigned int block);
#endif /* merge_units */
#define RingBuffer_At(a0, a1) ((int * *)RingBuffer_At((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void* func_00198F20(void*);
#endif /* merge_units */
#define func_00198F20(a0) (func_00198F20((a0))) /* merge_units */


/* Construct an iterator holding value (goes through a stack temporary). */
int func_00198E70(int a0, int a1) {
    int loc[1];
    int v0, v1;

    v0 = a0;
    *(int*)(char*)loc = a1;
    v1 = *(int*)(char*)loc;
    *(int*)(char*)a0 = v1;
    goto ret;
ret:
    return v0;
}

/* back(): address of the last element. */
char* Deque_Back(char* deque) {
    int last;
    int** slot;

    last = *(int*)(deque + 16) + *(int*)(deque + 20) - 1;
    slot = RingBuffer_At(func_00198F20(deque), (unsigned int)last >> 3);
    return (char*)*slot + (last & 7) * 248;
}
#undef RingBuffer_At /* merge_units */
#undef func_00198F20 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00198E70(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00198E70 */

/* merge_units: begin func_00198EF0 */
#pragma push /* merge_units */
/* Address of element `index` (relative to start) in a circular buffer. */
int* RingBuffer_At(Ring00198EF0* ring, unsigned int index)
{
    return &ring->data[(ring->start + index) % ring->capacity];
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00198EF0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00198EF0 */

/* merge_units: begin func_00198F20 */
#pragma push /* merge_units */
extern int func_00198D00(char*, int);
#if 0 /* merge_units */
extern char* Deque_Back(char*);
#endif /* merge_units */
#define Deque_Back(a0) (Deque_Back((a0))) /* merge_units */

extern char* func_00198F70(char*);

void* func_00198F20(void* self) {
    return self;
}

int func_00198F30(char* self, int key) {
    char* last;
    int found;

    last = func_00198F70(self);
    found = func_00198D00(last, key);
    return found != 0;
}

/* Last element of the deque at +0x3C, offset +0xE8 into it. */
char* func_00198F70(char* self) {
    char* last;

    last = Deque_Back(self + 60);
    return last + 232;
}
#undef Deque_Back /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00198F20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00198F20 */
