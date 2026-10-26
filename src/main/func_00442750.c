#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_004526D0(char * , char *);                     
int func_00452A60(char * );                          
int SFOLobby_JoinMissionChannel(char * , char *);                     
int SFOLobby_SetCallback();                                  
int sprintf(char *, char *, char * , int);                   
extern char D_004C0598;
extern char D_004C05A0;

#pragma push
#pragma opt_common_subs off
int func_00442750(char * arg0) {
    struct { int f20[64]; } sl;

    if (F_(arg0, 0x255C, int) != 9) {
        return 0;
    }
    F_(arg0, 0x255C, int) = 4;
    SFOLobby_SetCallback();
    F_(arg0, 0x2584, int) = 0;
    F_(arg0, 0x2588, int) = 0;
    if (F_(arg0, 0x26A8, int) != 1) {
        F_(arg0, 0x26A8, int) = 0;
        if (func_00452A60(arg0) != 0) {
            sprintf(sl.f20, &D_004C0598, arg0 + 0x23B5, F_(arg0, 0x1F38, int));
            if (func_004526D0(arg0, sl.f20) == 0) {
                return 0;
            }
            goto block_10;
        }
        sprintf(sl.f20, &D_004C05A0, arg0 + 0x23B5, F_(arg0, 0x1F38, int));
        if (SFOLobby_JoinMissionChannel(arg0, sl.f20) == 0) {
            return 0;
        }
block_10:
        F_(arg0, 0x26A8, int) = 1;
        goto block_11;
    }
block_11:
    return F_(arg0, 0x240C, int) = 1;
}
#pragma pop
