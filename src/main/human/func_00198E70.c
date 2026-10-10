/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "human_types.h"

/* Deque of 248-byte elements, 8 per block: map at +0x00, start +0x10, size +0x14. */
extern int** RingBuffer_At(void* map, unsigned int block);
extern void* func_00198F20(void*);

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
