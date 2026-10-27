#pragma cplusplus on
#include "types.h"
#include "net_recv_guard.h"
typedef struct { int kind; int id; signed char b8; char p9[3]; int fC; } Pk20E350;
extern "C" {
extern unsigned char D_005721D0;
extern unsigned char g_GameState;
extern unsigned char D_005721D8;
extern unsigned char D_005723B0;
extern char D_005721E0[];
extern char D_005721F0;
extern char g_Game[];
char* strncpy(char*, const char*, unsigned int);
void cGameSystem_Restart(void*, int);
}
#pragma push
#pragma opt_propagation off
extern "C" int cEndLevelMsg_NetEndLevelCallback(int a0, int a1, int a2, Pk20E350* arg) {
    NetRecvGuard g;
    if (D_005721D0) {
        Pk20E350* p = arg;
        if (g_GameState == 0xF || g_GameState == 0x12) {
            if (p->fC == 1) {
                D_005721D8 = 1;
                D_005723B0 = 2;
                strncpy(D_005721E0, "HOST_LEFTGAME", 0x10);
                D_005721F0 = 0;
            }
            cGameSystem_Restart(g_Game, p->b8);
        }
    }
    return 0x10;
}
#pragma pop
