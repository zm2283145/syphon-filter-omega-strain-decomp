/*
 * lib/libkernl: 2 files, 001101F8-00110248
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001101F8 */
#include "types.h"

/* Library code: matches with EE-GCC 2.95 -O2 (check.py --gcc). */

typedef struct Item { int key; char pad[0x34]; struct Item* next; } Item;
typedef struct Group { char pad[8]; Item* items; char padC[8]; struct Group* next; } Group;
typedef struct { char pad[0x28]; Group* groups; } Owner;

/* Searches all groups of owner for the item with the given key. */
Item* _search_svdata(int key, Owner* owner)
{
    Group* g;
    Item* it;
    for (g = owner->groups; g != 0; g = g->next) {
        for (it = g->items; it != 0; it = it->next) {
            if (it->key == key)
                return it;
        }
    }
    return 0;
}
/* merge_units: end func_001101F8 */

/* merge_units: begin func_00110248 */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern int isceSifSendCmd(int, int, int, int, int, int);

int _alarm_bind(int a0, int a1, int a2, int a3) {
    int t0, t1, v0, v1;

    a1 = a3;
    a0 = 0x80000000;
    a0 = a0 | 0x8;
    a2 = 0 + 64;
    a3 = 0;
    t0 = 0;
    t1 = 0;
    v0 = isceSifSendCmd(a0, a1, a2, a3, t0, t1);
    v1 = 0 + 2048;
    if (v0 != 0) v1 = 0;
    v0 = v1;
    goto ret;
ret:
    return v0;
}
/* merge_units: end func_00110248 */
