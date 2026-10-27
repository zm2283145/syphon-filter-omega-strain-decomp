#include "types.h"

typedef struct {
    char voice[8];
    int duration;
} Line_4624E0;

typedef struct {
    char pad0[0x14];
    unsigned short flags;
} W_4624E0;

typedef struct {
    char pad0[0xD4];
    float fD4;
    char padD8[0xB71 - 0xD8];
    unsigned char bB71;
} Agent_4624E0;

typedef struct {
    char pad0[0x90];
    char lines[0xC];        /* 0x90 */
} Self_4624E0;

extern char g_Game[];
extern char g_LevelDirName[];
extern int D_004FFD28;
extern unsigned char g_IsMultiplayer;
extern char D_004C2698[];
extern char D_004C26B0[];
extern char D_004C26C8[];
void GuiObjectives_onWake(Self_4624E0* self);
Agent_4624E0* cGameSystem_GetAgentData(void* mgr, int idx);
int cAgentData_GetStat(Agent_4624E0* agent, int stat);
int sprintf(char* buf, const char* fmt, ...);
Line_4624E0* cQuipList_tQuip_ctor(Line_4624E0* line, char* voice, int duration);
void cArray_tQuip_PushBackActual(void* vec, Line_4624E0* line);
W_4624E0* GuiWidget_FindChild_charP(void* self, char* name);
int cAgentData_GetParTime(void* p, unsigned char f);
void GuiEndGameObjectives_onWake(Self_4624E0* self);

void GuiEndGameObjectives_onWake(Self_4624E0* self)
{
    Agent_4624E0* agent;
    int n;
    char buf[32];
    W_4624E0* w;
    GuiObjectives_onWake(self);
    agent = cGameSystem_GetAgentData(g_Game, -1);
    n = D_004FFD28;
    if (cAgentData_GetStat(agent, 0x19) > 0)
        sprintf(buf, D_004C2698, n + 1);
    {
        Line_4624E0 line;
        cQuipList_tQuip_ctor(&line, buf, 0x1E);
        cArray_tQuip_PushBackActual(self->lines, &line);
    }
    w = GuiWidget_FindChild_charP(self, D_004C26B0);
    if (agent->bB71) {
        int r;
        if (w) w->flags &= ~2;
        r = cAgentData_GetParTime(g_LevelDirName, g_IsMultiplayer);
        if ((int)agent->fD4 <= r) {
            Line_4624E0 line;
            cQuipList_tQuip_ctor(&line, D_004C26C8, 0x1E);
            cArray_tQuip_PushBackActual(self->lines, &line);
        }
    } else {
        if (w) w->flags |= 2;
    }
}


