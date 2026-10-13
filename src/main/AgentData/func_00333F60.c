#include "types.h"
typedef struct { char p0[4]; unsigned char b4; } G333F60;
typedef struct { char p0[4]; int f4; char p8[0xB70 - 8]; unsigned char bB70; } A333F60;
extern G333F60 D_0055A830;
extern void AgentData_Reset(A333F60* a);
extern void awards_SetAwardsAndBonuses(A333F60* a, int b, int c);
extern int AgentData_Save(A333F60* a);
static inline int Set333F60(G333F60* g) { return g->b4 != 0; }
/* Resets the agent, re-applies awards and, unless told otherwise, starts the first mission. */
int AgentData_Create(A333F60* a, int x, int skip)
{
    G333F60* g = &D_0055A830;
A333F60* aa = a;
int xx = x;
int ss = skip;
    AgentData_Reset(aa);
    awards_SetAwardsAndBonuses(aa, 0, 1);
    aa->f4 = xx;
    aa->bB70 = 1;
    if (!ss && (Set333F60(g) ^ 1)) return AgentData_Save(aa);
    return 0;
}
