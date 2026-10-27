#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int cMessage_ctor_cMessageNameR(char **, char *);                       
int nGobjManager_LookupGOBJ_cObjectIdR(int *);                       
int cMessage_dtor(char **, int);                           
int nHudTargets_RemoveHudObjective(int, int);                            
extern char D_004DE650;
extern char D_0052ACF8;
extern unsigned char D_005721D0;
extern unsigned char D_005723C8;

#pragma push
#pragma opt_common_subs off
int cNetRemoveHudObjectiveMsg_NetRemoveHudObjectiveMsgCallback(int d0, int d1, int d2, char * arg3) {
    struct { char * f20[9]; int f44; int f48[2]; } sl;
    int temp_v0;

    if (D_005723C8 == 0) {
        D_005723C8 = 1;
    }
    if (D_005721D0 != 0) {
        cMessage_ctor_cMessageNameR(sl.f20, &D_0052ACF8);
        sl.f20[0] = &D_004DE650;
        { int *p = &sl.f44; *p = F_(arg3, 0x8, int); sl.f48[0] = *p; }
        temp_v0 = nGobjManager_LookupGOBJ_cObjectIdR(sl.f48);
        if (temp_v0 != 0) {
            nHudTargets_RemoveHudObjective(temp_v0, 1);
        }
        sl.f20[0] = &D_004DE650;
        cMessage_dtor(sl.f20, 0);
    }
    D_005723C8 = 0;
    return 0xC;
}

#pragma pop
