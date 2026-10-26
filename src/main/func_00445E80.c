#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int LobbyArray_Init(int, int, int, int);                      
int SFOLobby_SetCallback();                                  

typedef struct { char p0[9208]; int f23F8; int f23FC; int f2400; char p2404[344]; int f255C; } PS0_00445E80;
int SFOLobby_AccountScreenStart(PS0_00445E80 *arg0, int arg1, int arg2, int arg3, char * arg4) {
    if (arg0->f255C != 9) {
        return 0;
    }
    arg0->f255C = 3;
    SFOLobby_SetCallback();
    arg0->f23F8 = arg2;
    LobbyArray_Init(arg0->f23F8, 2, 2, 0x100);
    arg0->f23FC = arg3;
    LobbyArray_Init(arg0->f23FC, 2, 2, 0x100);
    arg0->f2400 = (int) arg4;
    LobbyArray_Init(arg0->f2400, 4, 4, 0x3EC);
    return 1;
}
