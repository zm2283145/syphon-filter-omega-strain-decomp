/*
 * lib/medius: 2 files, 002F3250-002F3298
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002F3250 */
#include "types.h"
typedef struct { short a; short b; unsigned short val; unsigned short id; } E2F3250;
unsigned short GetSetPreviousMessage(char* base, E2F3250* k, int v)
{
    unsigned short id = k->id;
    E2F3250* e = (E2F3250*)(base + (id & 0xFF) * 8 + 0x40);
    if (e->id == id) return e->val;
    *e = *k;
    e->val = v;
    return 0xFFFF;
}
/* merge_units: end func_002F3250 */

/* merge_units: begin func_002F3298 */
extern int rt_memory_allocate_init_zero(int** out, unsigned long n);
int* CreatePlayerSet(void)
{
    int* p = 0;
    rt_memory_allocate_init_zero(&p, 8);
    if (p) {
        p[0] = 0;
        p[1] = 0;
    }
    return p;
}
/* merge_units: end func_002F3298 */
