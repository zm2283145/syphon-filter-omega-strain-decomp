/*
 * SFOGame/Source/ai: 1 file, 0016A750
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0016A750 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"

struct TeamRel {
    unsigned char hostile : 1;
};

extern "C" void cTeam_InitTeamData(TeamRel (*r)[16])
{
    int i, j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++)
            r[i][j].hostile = 0;
        for (j = 4; j < 16; j++)
            r[i][j].hostile = 1;
    }
    for (i = 4; i < 16; i++) {
        for (j = 0; j < 4; j++)
            r[i][j].hostile = 1;
        for (j = 4; j < 16; j++)
            r[i][j].hostile = 0;
    }
}
static inline void merge_flush_func_0016A750(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0016A750 */
