#include "types.h"

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
