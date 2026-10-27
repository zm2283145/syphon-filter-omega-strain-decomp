/*
 * SFOGame/Source/ai: 1 file, 00169D40
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00169D40 */
#pragma push /* merge_units */
#include "types.h"
#pragma global_optimizer off
typedef struct { unsigned char enemy : 1; unsigned char rest : 7; } Rel_00169D40;
extern Rel_00169D40 (*D_004EE620)[16];
static inline void SetAll_00169D40(int team, unsigned char v)
{
    int j;
    for (j = 4; j < 16; j++)
        D_004EE620[team][j].enemy = v;
}
int Script_TeamDelEnemyAllNpcs(int* args)
{
    int t[1];
    t[0] = args[0];
    SetAll_00169D40(*(int*)t, 0);
    return 0;
}
static inline void merge_flush_func_00169D40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00169D40 */
