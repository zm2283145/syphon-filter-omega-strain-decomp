/*
 * Libs/SFOLib/Source/mp_vobuf: 6 files, 003F5E80-003F6040
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003F5E80 */
#pragma push /* merge_units */
#include "types.h"
#pragma optimization_level 1

typedef struct Counter {
    char pad[0xC];
    int count;
} Counter;

/* Decrements a positive counter at +0xC. */
void voBufDecCount(Counter* c) {
    if (c->count > 0) c->count--;
}
static inline void merge_flush_func_003F5E80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F5E80 */

/* merge_units: begin func_003F5EA0 */
#pragma push /* merge_units */
typedef struct { char data[0x4CE40]; } E5EA0;
typedef struct { int m0; E5EA0* base; int head; int count; int size; } T5EA0;
#pragma bool off
#pragma opt_propagation off
static inline int empty5EA0(T5EA0* q) { return q->count == 0; }
E5EA0* voBufGetTag(T5EA0* q)
{
    int e = empty5EA0(q);
    if (e)
        return 0;
    return &q->base[(q->size + (q->head - *(volatile int*)&q->count)) % q->size];
}
#pragma opt_propagation reset
#pragma bool reset
static inline void merge_flush_func_003F5EA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F5EA0 */

/* merge_units: begin func_003F5F20 */
#pragma push /* merge_units */
typedef struct { char data[0x195000]; } E5F20;
typedef struct { E5F20* base; int m4; int head; int count; int size; } T5F20;
#pragma bool off
#pragma opt_propagation off
static inline int full5F20(T5F20* q) { return q->count == q->size; }
E5F20* voBufGetData(T5F20* q)
{
    int f = full5F20(q);
    if (f)
        return 0;
    return &q->base[q->head];
}
#pragma opt_propagation reset
#pragma bool reset
static inline void merge_flush_func_003F5F20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F5F20 */

/* merge_units: begin func_003F5F70 */
#pragma push /* merge_units */
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

extern void DIntr(void); /* lock */
extern void EIntr(void); /* unlock */

/* Marks the head slot ready (state 2) and advances the ring under the lock. */
void voBufIncCount(Ring* ring) {
    DIntr();
    ring->slots[ring->head].state = 2;
    ring->count++;
    ring->head = (ring->head + 1) % ring->size;
    EIntr();
}
static inline void merge_flush_func_003F5F70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F5F70 */

/* merge_units: begin func_003F6000 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose04_types.h"

int voBufIsFull(Unk3F6000* self) {
    return self->unk0C == self->unk10;
}

void voBufReset(Unk3F6000* self) {
    self->unk0C = 0;
    self->unk08 = 0;
}

void voBufDelete(void) {
}
static inline void merge_flush_func_003F6000(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F6000 */

/* merge_units: begin func_003F6040 */
#pragma push /* merge_units */
typedef struct { int first; char data[0x4CE3C]; } E6040;
typedef struct { int m0; E6040* base; int head; int count; int size; } T6040;
void voBufCreate(T6040* q, int m0, E6040* base, int size)
{
    int i;
    q->m0 = m0;
    q->base = base;
    q->size = size;
    q->count = 0;
    q->head = 0;
    for (i = 0; i < size; i++)
        q->base[i].first = 0;
}
static inline void merge_flush_func_003F6040(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F6040 */
