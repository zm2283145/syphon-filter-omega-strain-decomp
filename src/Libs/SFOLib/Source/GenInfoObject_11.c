/*
 * Libs/SFOLib/Source/GenInfoObject: 1 file, 00439C70
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00439C70 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { int id; unsigned char flags; char pad[3]; } E43AB20;
extern E43AB20 *D_00583888;
int cGenInfoObject_GetOwner(int d0, int *arg1) {
    E43AB20 *e;
    E43AB20 *t = D_00583888;
    int key = *arg1;
    if (t != 0) {
        int i = 0;
        E43AB20 *p = t;
        do {
            if (key == p->id) { e = &t[i]; goto found; }
            i++;
            p++;
        } while (i != 0x37);
    }
    e = 0;
found:
    if (e != 0) {
        int v = e->flags & 0xF;
        if (v != 0xF) {
            return v;
        }
    }
    return -1;
}
static inline void merge_flush_func_00439C70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00439C70 */
