/*
 * SFOGame/Source/ai: 1 file, 0016A020
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0016A020 */
#pragma push /* merge_units */
#include "types.h"
#pragma global_optimizer off
/* Script_TeamEnemy: true when team a treats team b as an enemy (16x16 relation table) */
typedef struct { unsigned char enemy : 1; unsigned char rest : 7; } Pt1TeRel;
extern Pt1TeRel (*D_004EE620)[16];
static inline int Pt1Te_IsEnemy(int a, int b)
{
    if (D_004EE620 && a > -1 && a < 16 && b > -1 && b < 16)
        return D_004EE620[a][b].enemy;
    return 0;
}
unsigned char Script_TeamEnemy(int* args)
{
    int a[1];
    int b[1];
    b[0] = args[1];
    a[0] = args[0];
    return Pt1Te_IsEnemy(*(int*)a, *(int*)b);
}
static inline void merge_flush_func_0016A020(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0016A020 */
