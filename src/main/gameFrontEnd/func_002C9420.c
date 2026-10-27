#include "types.h"
typedef struct { char pad[0x39]; char names[8][32]; char pad2[0x13C - 0x139]; int count; } Menu9420;
extern char* D_0048C1A0;
extern char g_Game[];
extern int sprintf(char* buf, const char* fmt, ...);
extern void Libc_Strcpy(char* dst, const char* src);
extern void* cGameSystem_GetAgentData(char* name, int index);
extern int cAgentData_HasZeusItem(void* agent, int a, int b, int i);
void cGameFrontEnd_BuildFinalMovie(Menu9420* m)
{
    char num[8];
    char buf[0x28];
    int n = 0;
    void* agent;
    int i;
    sprintf(buf, "%s_EOL", D_0048C1A0);
    n++;
    Libc_Strcpy(m->names[0], buf);
    agent = cGameSystem_GetAgentData(g_Game, -1);
    for (i = 0; i < 10 && n < 8; i++) {
        if (cAgentData_HasZeusItem(agent, 0, 0x63, i)) {
            sprintf(num, "%d_%d", 0x11, i + 1);
            Libc_Strcpy(m->names[n++], num);
        }
    }
    m->count = n;
}