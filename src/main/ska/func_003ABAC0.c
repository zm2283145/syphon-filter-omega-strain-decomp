#include "types.h"

typedef struct { char data[0xF8]; } DequeItem;
typedef struct { unsigned int mapSize; int unk4; unsigned int start; DequeItem** map; unsigned int first; unsigned int count; } Deque;

/* Returns a pointer to the last element of a block-based deque (8 items per block). */
DequeItem* Array_GetLast(Deque* self)
{
    unsigned int index = self->first + self->count - 1;
    return &self->map[(self->start + (index >> 3)) % self->mapSize][index & 7];
}
