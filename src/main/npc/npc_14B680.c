/*
 * main/npc: range (2 files, 0014B680-0014B700)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_0014B680 */
#pragma push /* merge_units */
typedef struct { unsigned char b0 : 1; unsigned char b1 : 1; unsigned char flag : 1; } NpcBits;
typedef struct { char pad[0x30]; void* owner; char pad2[0x10D]; NpcBits bits; } cNPC;

extern unsigned char D_005721C8; /* networked game */
extern unsigned char D_005721C0; /* is host */
extern void NetEvent_Send(void* owner, int type, int size, unsigned char a, int b, int c, int d);

static inline int IsAuthority(void)
{
    return D_005721C8 ? D_005721C0 : 1;
}

/* cNPC virtual 0x56: sets flag bit 2 and broadcasts it in network games. */
void cNPC_v56(cNPC* self, int on)
{
    self->bits.flag = on;
    if (D_005721C8 && IsAuthority())
        NetEvent_Send(self->owner, 0x18, 4, (unsigned char)on, 0, 0, 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014B680(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014B680 */

/* merge_units: begin func_0014B700 */
#pragma push /* merge_units */
typedef struct cNPC_0014B700 {
    char pad[0x70];
    float rangeMin;
    float rangeMax;
    char pad2[0xAC - 0x78];
    int rangePriority;
} cNPC_0014B700;

/* vtable slot: sets a range center +- half width when priority >= current. */
void cNPC_v55(cNPC_0014B700* self, int priority, float center, float width) {
    if (priority >= self->rangePriority) {
        float half = 0.5f * width;
        self->rangeMin = center - half;
        self->rangeMax = center + half;
        self->rangePriority = priority;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014B700(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014B700 */
