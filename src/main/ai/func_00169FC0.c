#include "types.h"

typedef struct TeamArgs {
    int team;
    int other;
} TeamArgs;

typedef struct TeamFlags {
    unsigned char enemy : 1;
} TeamFlags;

extern char* D_004EE620; /* 16x16 team relation table */

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
