#include "types.h"

typedef struct Ring {
    unsigned int size;  /* 0x00 */
    int unk04;
    unsigned int head;  /* 0x08 */
    int* items;         /* 0x0C */
} Ring;

/* Returns the address of the slot `offset` past the ring head. */
int* Ring_SlotAt(Ring* ring, unsigned int offset) {
    return &ring->items[(ring->head + offset) % ring->size];
}
