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

extern char D_004FFB50[];
extern char D_004FFC90[];
extern int D_004FFD28;
extern unsigned char D_005721C8;
extern char D_004C2698[];
extern char D_004C26B0[];
extern char D_004C26C8[];
void func_00368760(Self_4624E0* self);
Agent_4624E0* Agent_GetSelected(void* mgr, int idx);
int cAgentData_GetStat(Agent_4624E0* agent, int stat);
int sprintf(char* buf, const char* fmt, ...);
Line_4624E0* func_00462650(Line_4624E0* line, char* voice, int duration);
void func_00462620(void* vec, Line_4624E0* line);
W_4624E0* GuiWidget_FindChildByName(void* self, char* name);
int func_00330C30(void* p, unsigned char f);
void func_004624E0(Self_4624E0* self);

void func_004624E0(Self_4624E0* self)
{
    Agent_4624E0* agent;
    int n;
    char buf[32];
    W_4624E0* w;
    func_00368760(self);
    agent = Agent_GetSelected(D_004FFB50, -1);
    n = D_004FFD28;
    if (cAgentData_GetStat(agent, 0x19) > 0)
        sprintf(buf, D_004C2698, n + 1);
    {
        Line_4624E0 line;
        func_00462650(&line, buf, 0x1E);
        func_00462620(self->lines, &line);
    }
    w = GuiWidget_FindChildByName(self, D_004C26B0);
    if (agent->bB71) {
        int r;
        if (w) w->flags &= ~2;
        r = func_00330C30(D_004FFC90, D_005721C8);
        if ((int)agent->fD4 <= r) {
            Line_4624E0 line;
            func_00462650(&line, D_004C26C8, 0x1E);
            func_00462620(self->lines, &line);
        }
    } else {
        if (w) w->flags |= 2;
    }
}


