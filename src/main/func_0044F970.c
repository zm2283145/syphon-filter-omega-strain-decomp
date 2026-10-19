#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int SFOLobby_Free(int);                               
int operator_delete(char * );                          
extern int D_00585E58;

typedef struct { int f0; int f4; char p8[8]; int f10; int f14; signed char f18; } PS0_0044F970;
char * LobbyArray_dtor(PS0_0044F970 *arg0, long long arg1) {
    int temp_a0;

    if (arg0 != NULL) {
        temp_a0 = arg0->f14;
        if (temp_a0 != 0) {
            SFOLobby_Free(temp_a0);
            D_00585E58 -= arg0->f0 * arg0->f10;
        }
        arg0->f0 = 0;
        arg0->f4 = 0;
        arg0->f14 = 0;
        arg0->f18 = 1;
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            operator_delete(arg0);
        }
    }
    return arg0;
}
