#include "types.h"

typedef struct RankArgs {
    int a0;
    int a1;
    int weapon;
} RankArgs;

/* Temporary rank record built on the stack. */
typedef struct RankRec {
    char data[0x20];
} RankRec;

extern char D_00532B50[]; /* rank registry */
extern int Loc_FindKeyThunk(int handle);
extern int func_003337A0(int id);
extern int func_0032EB80(void* registry);
extern int func_0032EB00(RankRec* rec, int a0, int a1, int id, int index, int flags);
extern void func_0032EAD0(void* registry, int rec);

/* Script native: cAgentData._RegisterRank(a0, a1, weapon). */
int Script_cAgentData__RegisterRank_2(RankArgs* args) {
    RankRec rec;
    int id, v0, v1, v2;
    volatile int w2, w1, w0;
    w2 = args->weapon;
    v2 = w2;
    w1 = args->a1;
    v1 = w1;
    w0 = args->a0;
    v0 = w0;
    id = func_003337A0(Loc_FindKeyThunk(v2));
    func_0032EAD0(D_00532B50, func_0032EB00(&rec, v0, v1, id, func_0032EB80(D_00532B50), 0));
    return 0;
}
