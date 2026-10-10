#include "types.h"
typedef union ScriptArg { int i; float f; void* p; } ScriptArg;
typedef struct { char pad[0x28]; } Rank;
extern char D_00532B50[];
extern void* Loc_FindKeyThunk(int);
extern int func_003337A0(void*);
extern int func_0032EB80(void*);
extern Rank* func_0032EB00(Rank* r, int name, int score, int a, int b, int c);
extern void func_0032EAD0(void* list, Rank* r);
/* Script native: registers rank args[0] with threshold args[1]; returns 0. */
int Script_cAgentData__RegisterRank(ScriptArg* args)
{
    int score[1];
    int name[1];
    int agent;
    int n;
    int s;
    Rank rank;
    score[0] = args[1].i;
    s = *(volatile int*)score;
    name[0] = args[0].i;
    n = *(volatile int*)name;
    agent = func_003337A0(Loc_FindKeyThunk(0));
    func_0032EAD0(D_00532B50, func_0032EB00(&rank, n, s, agent, func_0032EB80(D_00532B50), 0));
    return 0;
}
