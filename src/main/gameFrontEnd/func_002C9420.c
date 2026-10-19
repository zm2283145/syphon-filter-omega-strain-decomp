#include "types.h"
typedef struct { char pad[0x39]; char names[8][32]; char pad2[0x13C - 0x139]; int count; } Menu9420;
extern char* D_0048C1A0;
extern char g_Game[];
extern int sprintf(char* buf, const char* fmt, ...);
extern void String_Copy(char* dst, const char* src);
extern void* Agent_GetSelected(char* name, int index);
extern int AgentData_HasZeus(void* agent, int a, int b, int i);
void Game_GetEolMovieName(Menu9420* m)
{
    char num[8];
    char buf[0x28];
    int n = 0;
    void* agent;
    int i;
    sprintf(buf, "%s_EOL", D_0048C1A0);
    n++;
    String_Copy(m->names[0], buf);
    agent = Agent_GetSelected(g_Game, -1);
    for (i = 0; i < 10 && n < 8; i++) {
        if (AgentData_HasZeus(agent, 0, 0x63, i)) {
            sprintf(num, "%d_%d", 0x11, i + 1);
            String_Copy(m->names[n++], num);
        }
    }
    m->count = n;
}