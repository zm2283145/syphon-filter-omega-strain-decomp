#include "types.h"
typedef struct { unsigned int capacity; int unk4; unsigned int start; int* data; } Ring00198EF0;
/* Address of element `index` (relative to start) in a circular buffer. */
int* RingBuffer_At(Ring00198EF0* ring, unsigned int index)
{
    return &ring->data[(ring->start + index) % ring->capacity];
}
