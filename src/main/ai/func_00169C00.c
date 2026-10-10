#include "types.h"

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
