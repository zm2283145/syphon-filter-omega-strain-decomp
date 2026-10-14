/*
 * main/ai: range (2 files, 00169C00-00169CA0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00169C00 */
#pragma push /* merge_units */
typedef union { int i; void* p; } ScriptArg;
typedef struct { unsigned char enemy : 1; unsigned char rest : 7; } TeamRel;
typedef struct { TeamRel rel[16]; } Team;

extern Team* D_004EE620;

/* Script native: clears the enemy flag of the team toward all four players. */
int Script_TeamDelEnemyAllPlayers(ScriptArg* args)
{
    int teamArg[1];
    int team;
    teamArg[0] = args[0].i;
    team = *(int*)teamArg;
    D_004EE620[team].rel[0].enemy = 0;
    D_004EE620[team].rel[1].enemy = 0;
    D_004EE620[team].rel[2].enemy = 0;
    D_004EE620[team].rel[3].enemy = 0;
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00169C00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00169C00 */

/* merge_units: begin func_00169CA0 */
#pragma push /* merge_units */
typedef union ScriptArg_00169CA0 { int i; float f; void* p; } ScriptArg_00169CA0;
typedef struct { unsigned char enemy0 : 1; unsigned char r0 : 7; unsigned char enemy1 : 1; unsigned char r1 : 7; unsigned char enemy2 : 1; unsigned char r2 : 7; unsigned char enemy3 : 1; unsigned char r3 : 7; char pad[12]; } Team_00169CA0;
#if 0 /* merge_units */
extern Team_00169CA0* D_004EE620;
#endif /* merge_units */
#define D_004EE620 (*(Team_00169CA0 **)&D_004EE620) /* merge_units */

/* Script native: marks team args[0] as enemy of all four players; returns 0. */
int Script_TeamSetEnemyAllPlayers(ScriptArg_00169CA0* args)
{
    volatile int team = args[0].i;
    int t = team;
    D_004EE620[t].enemy0 = 1;
    D_004EE620[t].enemy1 = 1;
    D_004EE620[t].enemy2 = 1;
    D_004EE620[t].enemy3 = 1;
    return 0;
}
#undef D_004EE620 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00169CA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00169CA0 */
