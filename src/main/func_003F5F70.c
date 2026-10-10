#include "types.h"

/* One ring buffer slot (0x4CE40 bytes); the first word is its state. */
typedef struct RingSlot {
    int state;
    char data[0x4CE40 - 4];
} RingSlot;

typedef struct Ring {
    int unk0;
    RingSlot* slots;
    int head;
    int count;
    int size;
} Ring;

extern void func_001161A0(void); /* lock */
extern void func_001161F8(void); /* unlock */

/* Marks the head slot ready (state 2) and advances the ring under the lock. */
void func_003F5F70(Ring* ring) {
    func_001161A0();
    ring->slots[ring->head].state = 2;
    ring->count++;
    ring->head = (ring->head + 1) % ring->size;
    func_001161F8();
}
