#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int LobbyArray_SetDirty(char * , int);                         
char * LobbyArray_At(char * , int);                   

typedef struct { int f0; int f4; int f8; char pC[4]; int f10; char p14[4]; int f18; int f1C; char p20[4]; int f24; } PS0_0044EFF0;
void SFOLobby_RefreshGameInfo(int d0, char * arg1, PS0_0044EFF0 *arg2) {
    int temp_s1;
    int var_s0;
    char * temp_v0;

    if ((arg1 == NULL) || (temp_s1 = F_(arg1, 0x4, int), (temp_s1 == 0))) {
        return;
    }
    for (var_s0 = 0; var_s0 < temp_s1; var_s0++) {
            temp_v0 = LobbyArray_At(arg1, var_s0);
            if (F_(temp_v0, 0x48, int) == arg2->f0) {
                F_(temp_v0, 0x30, int) = arg2->f24;
                F_(temp_v0, 0x34, int) = arg2->f4;
                F_(temp_v0, 0x38, int) = arg2->f8;
                F_(temp_v0, 0x3C, int) = arg2->f1C;
                F_(temp_v0, 0x40, int) = arg2->f10;
                F_(temp_v0, 0x44, int) = arg2->f18;
                LobbyArray_SetDirty(arg1, 1);
            }
    }
}
