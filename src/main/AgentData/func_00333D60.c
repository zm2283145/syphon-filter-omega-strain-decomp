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
extern void Event_Construct(Msg* msg, void* name);
extern void Stream_ReadU32(int* out);
extern void* Agent_GetSelected(void* list, int index);
extern int Loc_GetStoredKey(int id);
extern void AgentData_SetObjectiveBit(void* agent, int bit, int value);
extern void cMessage_dtor(Msg* msg, int flags);
/* Network handler: reads an objective id and clears that bit on the selected agent. */
void func_00333D60(void)
{
    Msg msg;
    void* agent;
    Event_Construct(&msg, D_005329C0);
    msg.vtable = D_004DE810;
    Stream_ReadU32(&msg.id);
    agent = Agent_GetSelected(g_Game, -1);
    AgentData_SetObjectiveBit(agent, Loc_GetStoredKey(msg.id), 0);
    msg.vtable = D_004DCF10;
    cMessage_dtor(&msg, 0);
}
