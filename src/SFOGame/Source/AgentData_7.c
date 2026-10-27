/*
 * SFOGame/Source/AgentData: 1 file, 0032EA40
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin AgentData_32EA40 */
#pragma push /* merge_units */
#include "types.h"

typedef union { int i; unsigned char b; void* p; } ScriptArg;
typedef struct { char data[0x28]; } RankReq;

extern char g_RankRows[];
extern int cArray_tRankInfo_Size(void* list);
extern void* cAgentData_tRankInfo_ctor(RankReq* req, int a, int b, int id, int index, int flag);
extern void cArray_tRankInfo_PushBackActual(void* list, void* item);

/* Script native: registers a rank requirement with the agent data. */
int Script_cAgentData__RegisterRank_4(ScriptArg* args)
{
    RankReq req;
    int bArg[1];
    int aArg[1];
    int a;
    int b;
    unsigned char rank;
    rank = args[2].b;
    bArg[0] = args[1].i;
    b = *(int*)bArg;
    aArg[0] = args[0].i;
    a = *(int*)aArg;
    cArray_tRankInfo_PushBackActual(g_RankRows, cAgentData_tRankInfo_ctor(&req, a, b, rank + 10000, cArray_tRankInfo_Size(g_RankRows), 0));
    return 0;
}
static inline void merge_flush_AgentData_32EA40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end AgentData_32EA40 */
