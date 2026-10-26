#include "types.h"
typedef struct { char p[0x255C]; int state; } S4426B0;
extern void SFOLobby_SetCallback(S4426B0* s, int f);
void SFOLobby_MissionScreenExit(S4426B0* s)
{
    int st = s->state;
    if (st != 9 && (st == 4 || st == 0)) {
        s->state = 9;
        SFOLobby_SetCallback(s, 0);
    }
}
