#include "types.h"

typedef union ScriptArg { int i; float f; void* p; } ScriptArg;
typedef struct { char data[0x30]; } Rank;
extern char D_00532B50[];
extern int Loc_FindKeyThunk(const char* s);           /* string hash */
extern int func_003337A0(int hash);
extern int func_0032EB80(void* registry);
extern void* func_0032EB00(Rank* r, int a, int b, int req, int index, int d);
extern void func_0032EAD0(void* registry, void* item);

/* Script native: registers a rank (args[0], args[1], requirement named args[2], args[3]); returns 0. */
int Script_cAgentData__RegisterRank_3(ScriptArg* args)
{
    Rank r;
    int p3[1];
    int p2[1];
    int p1[1];
    int p0[1];
    int a3;
    int req;
    int a0;
    int a1;
    int a2;
    p3[0] = args[3].i;
    a3 = *(int*)p3;
    p2[0] = args[2].i;
    a2 = *(int*)p2;
    p1[0] = args[1].i;
    a1 = *(int*)p1;
    p0[0] = args[0].i;
    a0 = *(int*)p0;
    req = func_003337A0(Loc_FindKeyThunk((const char*)a2));
    func_0032EAD0(D_00532B50, func_0032EB00(&r, a0, a1, req, func_0032EB80(D_00532B50), a3));
    return 0;
}
