#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Libc_Strcpy(char *, int);                              
int MGCLEndGameResponse(char *);                               
int memset(char *, int, int);                                
extern short D_0058438E;

void Callback_ServerEndGame(int d0, int d1, int d2, int arg3) {
    struct { int f20[5]; char pad34[1]; signed char f35[11]; } sl;

    memset(sl.f20, 0, 0x16);
    if (D_0058438E > 0) {
        sl.f35[0] = 0;
        Libc_Strcpy(sl.f20, arg3);
    } else {
        sl.f35[0] = -0xC;
        Libc_Strcpy(sl.f20, arg3);
    }
    MGCLEndGameResponse(sl.f20);
}
