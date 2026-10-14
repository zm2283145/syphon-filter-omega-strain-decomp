/*
 * main/human: range (2 files, 001A7E60-001A7F40)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_001A7E60 */
#pragma push /* merge_units */
typedef struct { char pad[0x10]; int mode; int bits[1]; } Physical;
static inline unsigned char Pcm_Test(Physical* p, int n)
{
    return ((p->bits[n / 32] >> (n & 31)) & 1) != 0;
}
void Physical_ClearModeBit(Physical* p, int bit)
{
    int i;
    p->bits[bit / 32] &= ~(1 << (bit & 31));
    for (i = 12; i >= 0 && !Pcm_Test(p, i); i--) {
    }
    if (!Pcm_Test(p, i)) {
        p->mode = -1;
    } else {
        p->mode = i;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001A7E60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001A7E60 */

/* merge_units: begin func_001A7F40 */
#pragma push /* merge_units */
typedef struct { char pad[0x24]; unsigned int type; unsigned char sub; } Ev;
typedef struct { char pad[0xA0]; unsigned char bA0; } Inv;
typedef struct { char pad[0x320C]; char anim[0x33E4 - 0x320C]; unsigned char b33E4; unsigned char b33E5; char pad33E6[2]; unsigned char b33E8;
    char pad33E9[0x3524 - 0x33E9]; Inv* inv; } Act;
extern unsigned char AnimPriority_Helper3(void*, int);
extern void AnimPriority_Helper2(void*, int, int);
extern void AnimPriority_Helper1(void*);
extern void AnimPriority_Helper0(void*, int, int);
extern void Inventory_ReleaseItem(Inv*);

int Actor_HandleEmbeddedEvent(Act* a, Ev* e)
{
    switch (e->type) {
    case -1:
        break;
    case 0:
        switch (e->sub) case 4: case 5: {
            int r;
            char* p = a->anim;
            r = AnimPriority_Helper3(p + 0xC, 3);
            AnimPriority_Helper2(p + 4, 3, 0);
            AnimPriority_Helper1(p);
            AnimPriority_Helper0(p, 3, r);
        }
        break;
    case 1:
        switch (e->sub) case 4: case 5: a->inv->bA0 = 0;
        break;
    case 2:
        switch (e->sub) case 4: case 5: {
            Inventory_ReleaseItem(a->inv);
            a->b33E4 = 0;
        }
        break;
    case 3:
        switch (e->sub) case 4: case 5: a->b33E5 = 0;
        break;
    case 4:
        switch (e->sub) case 4: case 5: a->b33E8 = 0;
        break;
    default:
        return 0;
    }
    return 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001A7F40(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001A7F40 */
