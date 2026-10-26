#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int SFOLobby_Free(int);                               
int SFOLobby_AllocZeroed(int);                             
int memcpy(int, int, int);                            
extern int D_00585E58;

typedef struct { int f0; int f4; int f8; char pC[4]; int f10; int f14; } PS0_0044F700;
void SFOLobbyList_CompactList(PS0_0044F700 *arg0) {
    int temp_v0;
    int var_s1;
    int temp_s0;

    if (arg0->f14 != 0) {
        var_s1 = arg0->f4;
        temp_v0 = arg0->f8;
        if (var_s1 < temp_v0) {
            var_s1 = temp_v0;
        }
        if (var_s1 <= 0) {
            var_s1 = 1;
        }
        temp_s0 = SFOLobby_AllocZeroed(var_s1 * arg0->f10);
        D_00585E58 += var_s1 * arg0->f10;
        if (temp_s0 != 0) {
            memcpy(temp_s0, arg0->f14, arg0->f4 * arg0->f10);
            SFOLobby_Free(arg0->f14);
            D_00585E58 -= arg0->f0 * arg0->f10;
            arg0->f0 = var_s1;
            arg0->f14 = temp_s0;
        }
    }
}
