#include "types.h"
typedef struct Msg {
    void* vtable;
    char base[0x20];
    int id;                 /* 0x24 */
    char pad[8];
} Msg;
extern char D_005329C0[];
extern char D_004DE810[];
extern char D_004DCF10[];
extern char g_Game[];
extern void cMessage_ctor_cMessageNameR(Msg* msg, void* name);
extern void cNetMsg_GetInt(int* out);
extern void* cGameSystem_GetAgentData(void* list, int index);
extern int nGlobalization_GetStringTag(int id);
extern void cAgentData_AddObjective(void* agent, int bit, int value);
extern void cMessage_dtor(Msg* msg, int flags);
/* Network handler: reads an objective id and clears that bit on the selected agent. */
void func_00333D60(void)
{
    Msg msg;
    void* agent;
    cMessage_ctor_cMessageNameR(&msg, D_005329C0);
    msg.vtable = D_004DE810;
    cNetMsg_GetInt(&msg.id);
    agent = cGameSystem_GetAgentData(g_Game, -1);
    cAgentData_AddObjective(agent, nGlobalization_GetStringTag(msg.id), 0);
    msg.vtable = D_004DCF10;
    cMessage_dtor(&msg, 0);
}
