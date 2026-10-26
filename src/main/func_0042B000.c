#include "types.h"
int Net_ResetSession(void);
int NetRegisterMallocFreeCallbacks(void*, void*);
extern int D_00572270[4][20];
extern signed char D_00572418[4];
extern char Sfo_Malloc;
extern char sfo_malloc_2CA9B0;
unsigned char cDME_Init_PreLobby(void) {
    int i;
    int j;
    int r;
    unsigned char ok;
    for (i = 0; i < 4; i++) {
        D_00572418[i] = 0;
        { int* p = D_00572270[i]; for (j = 0; j < 20; j++) p[j] = 0; }
    }
    ok = 0;
    r = NetRegisterMallocFreeCallbacks(&Sfo_Malloc, &sfo_malloc_2CA9B0);
    Net_ResetSession();
    if (r == 0) ok = 1;
    return ok;
}