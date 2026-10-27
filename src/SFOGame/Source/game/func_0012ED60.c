#include "types.h"
unsigned char* cGameSystem_GetAgentData(int, int);
int NetGetMyClientIndex(int*, int);
int cNetObj_GetPlayer(int);
unsigned int D_00494178[2] = { 0xFFFFFFFF, 0x0 };
extern int D_005721A8;
extern unsigned char g_IsMultiplayer;
int cGameSystem_AllAgentDataReceived(int arg0)
{
    int i;
    i = 0;
    do {
        int v;
        int a = D_005721A8; /* read before the flag test: retail loads it ahead of the branch */
        if (g_IsMultiplayer) {
            if ((*(int*)D_00494178) == -1) NetGetMyClientIndex(&(*(int*)D_00494178), a);
            v = (*(int*)D_00494178);
        } else v = 0;
        if (i != v && cNetObj_GetPlayer(i)) {
            unsigned char* p = cGameSystem_GetAgentData(arg0, i);
            if (p && p[0xB70] == 0) return 0;
        }
        i++;
    } while (i < 4);
    return 1;
}