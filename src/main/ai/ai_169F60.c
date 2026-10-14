/*
 * main/ai: range (2 files, 00169F60-00169FC0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00169F60 */
#pragma push /* merge_units */
typedef union ScriptArg { int i; float f; void* p; } ScriptArg;
typedef struct { unsigned char enemy : 1; unsigned char rest : 7; } TeamFlag;
typedef struct { TeamFlag other[16]; } TeamRow;
extern TeamRow* D_004EE620;

/* Script native: clears the "enemy" relation of team args[0] towards team args[1]; returns 0. */
int Script_TeamDelEnemy(ScriptArg* args)
{
    /* both arguments pass through stack temporaries */
    volatile int team;
    volatile int other;
    int col;
    other = args[1].i;
    col = other;
    team = args[0].i;
    D_004EE620[team].other[col].enemy = 0;
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00169F60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00169F60 */

/* merge_units: begin func_00169FC0 */
#pragma push /* merge_units */
typedef struct TeamArgs {
    int team;
    int other;
} TeamArgs;

typedef struct TeamFlags {
    unsigned char enemy : 1;
} TeamFlags;

#if 0 /* merge_units */
extern char* D_004EE620; /* 16x16 team relation table */
#endif /* merge_units */
#define D_004EE620 (*(char **)&D_004EE620) /* merge_units */


/* Script native: TeamSetEnemy(team, other) - sets the enemy bit in the relation table. */
int Script_TeamSetEnemy(TeamArgs* args) {
    int other, team;
    volatile int teamArg;
    volatile int otherArg;
    otherArg = args->other;
    other = otherArg;
    teamArg = args->team;
    team = teamArg;
    ((TeamFlags*)(D_004EE620 + team * 16 + other))->enemy = 1;
    return 0;
}
#undef D_004EE620 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00169FC0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00169FC0 */
