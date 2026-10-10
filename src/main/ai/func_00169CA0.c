#include "types.h"
typedef union ScriptArg { int i; float f; void* p; } ScriptArg;
typedef struct { unsigned char enemy0 : 1; unsigned char r0 : 7; unsigned char enemy1 : 1; unsigned char r1 : 7; unsigned char enemy2 : 1; unsigned char r2 : 7; unsigned char enemy3 : 1; unsigned char r3 : 7; char pad[12]; } Team;
extern Team* D_004EE620;
/* Script native: marks team args[0] as enemy of all four players; returns 0. */
int Script_TeamSetEnemyAllPlayers(ScriptArg* args)
{
    volatile int team = args[0].i;
    int t = team;
    D_004EE620[t].enemy0 = 1;
    D_004EE620[t].enemy1 = 1;
    D_004EE620[t].enemy2 = 1;
    D_004EE620[t].enemy3 = 1;
    return 0;
}
