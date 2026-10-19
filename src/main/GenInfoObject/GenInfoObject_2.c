/*
 * main/GenInfoObject: 2 files, 0043AA30-0043AA40
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0043AA30 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern void func_0043A8B0(void);

void func_0043AA30(void) {
    func_0043A8B0();
}
#pragma pop /* merge_units */
/* merge_units: end func_0043AA30 */

/* merge_units: begin func_0043AA40 */
#pragma push /* merge_units */
typedef struct { int id; unsigned char flags; char pad[3]; } E43AA40;
extern E43AA40 *D_00583888;
extern int D_00494178;
extern int D_005721A8;
extern unsigned char D_005721C8;
int NetGame_InitLocalSlot(int *, int);
static inline int Get43AA40(int a) {
    if (D_005721C8 != 0) {
        if (D_00494178 == -1) {
            NetGame_InitLocalSlot(&D_00494178, a);
        }
        return D_00494178;
    }
    return 0;
}
int func_0043AA40(int d0, int *arg1) {
    E43AA40 *e;
    E43AA40 *t = D_00583888;
    int key = *arg1;
    int v;
    if (t != 0) {
        int i = 0;
        E43AA40 *p = t;
        do {
            if (key == p->id) { e = &t[i]; goto found; }
            i++;
            p++;
        } while (i != 0x37);
    }
    e = 0;
found:
    if (e != 0) {
        v = Get43AA40(D_005721A8);
        return (e->flags & 0xF) == v;
    }
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_0043AA40 */
