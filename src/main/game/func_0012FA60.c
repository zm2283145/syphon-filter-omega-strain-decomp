#pragma cplusplus on
#include "types.h"
typedef struct {
    void* vt;
    char pad04[0x1C];
    signed char kind;
    char pad21[3];
    signed char id;
    char pad25[3];
    int f28;
} Msg_12FA60;
extern "C" char D_004F5398[];
extern "C" char D_004DADB0[];
extern "C" char g_Game[];
extern "C" unsigned char g_IsMultiplayer;
extern "C" unsigned char D_005721C0;
extern "C" void Event_Construct(Msg_12FA60* m, void* type);
extern "C" void Event_Send(Msg_12FA60* m, void* target, int c);
extern "C" void cMessage_dtor(Msg_12FA60* m, int f);
extern "C" char* Agent_GetSelected(void*, int);
extern "C" void AgentData_EndLevel(char*, bool);

#pragma opt_propagation off
extern "C" void Game_EndLevel(char* self, signed char arg1)
{
    bool end = false;
    unsigned char mode = arg1;
    Msg_12FA60 m;
    Msg_12FA60* p;
    if (mode == 2 || mode == 3) {
        self[0x1C4] = 1;
        self[0x1C5] = mode == 3;
        self[0x1C6] = 1;
        self[0x1C7] = 0;
    } else if (mode == 0) {
        self[0x1C4] = 0;
        self[0x1C5] = 0;
        if (g_IsMultiplayer) self[0x1C6] = 1;
        else self[0x1C6] = 0;
        self[0x1C7] = 0;
        end = true;
    } else if (mode == 1) {
        self[0x1C4] = 0;
        self[0x1C5] = 1;
        self[0x1C6] = 1;
        self[0x1C7] = 1;
    }
    AgentData_EndLevel(Agent_GetSelected(self, -1), end);
    p = &m;
    Event_Construct(p, D_004F5398);
    m.vt = D_004DADB0;
    m.id = arg1;
    p->f28 = mode == 2;
    if (!(g_IsMultiplayer ? D_005721C0 : 1)) m.kind = 1;
    Event_Send(&m, g_Game, 1);
    m.vt = D_004DADB0;
    cMessage_dtor(&m, 0);
}
