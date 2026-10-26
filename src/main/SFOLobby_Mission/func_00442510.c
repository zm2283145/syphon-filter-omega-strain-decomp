#include "types.h"
typedef struct { char pad[0x54]; char f54[4]; int n58; char pad2[0x1E54]; int f1eb0; char pad3[0x84]; int f1f38; char pad4[0x76C]; int f26a8; } L442;
extern int D_004976D0;
extern char D_004C0598[];
extern char D_004C05A0[];
extern int func_00452A60(L442*);
extern int LobbyArray_At(char*, int);
extern int sprintf(char*, const char*, ...);
extern int func_004526D0(L442*, char*);
extern int SFOLobby_JoinMissionChannel(L442*, char*);
extern void SFOLobby_FilterGameListByMyMission(L442*, int);
extern void SFOLobby_SetError(L442*, int, char*, int);
int SFOLobby_CheckMissionLobby(L442* l, int idx) {
    char buf[0x100];
    if (idx < 0 || !(idx < l->n58)) return 0;
    if (l->f26a8 != 2 || l->f1eb0 != idx || l->f1f38 != D_004976D0) {
        l->f26a8 = 0;
        l->f1eb0 = idx;
        if (func_00452A60(l)) {
            sprintf(buf, D_004C0598, LobbyArray_At(l->f54, idx), l->f1f38);
            if (!func_004526D0(l, buf)) return 0;
        } else {
            sprintf(buf, D_004C05A0, LobbyArray_At(l->f54, idx), l->f1f38);
            if (!SFOLobby_JoinMissionChannel(l, buf)) return 0;
        }
        SFOLobby_FilterGameListByMyMission(l, idx);
        D_004976D0 = l->f1f38;
        l->f26a8 = 2;
    }
    SFOLobby_SetError(l, 0, "SFOLobby_Mission.cc", 0x105);
    return 1;
}
