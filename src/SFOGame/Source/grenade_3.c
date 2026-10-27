/*
 * SFOGame/Source/grenade: 1 file, 0025A120
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0025A120 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad[0xD4]; unsigned char done; } O_A120;
O_A120 **func_0025A1C0(void *, int);
int cSystem_ActualScheduleDelete(O_A120 *, float);
int nGobjManager_RemoveGOBJ(O_A120 *);
extern char D_004F8040;
extern int D_004F8044;
void AreaEffect_FinishAll(void) {
    int i;
    for (i = 0; i < D_004F8044; i++) {
        O_A120* o = *func_0025A1C0(&D_004F8040, i);
        if (!o->done) {
            o->done = 1;
            nGobjManager_RemoveGOBJ(o);
            cSystem_ActualScheduleDelete(o, 0.1f);
        }
    }
}
static inline void merge_flush_func_0025A120(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0025A120 */
