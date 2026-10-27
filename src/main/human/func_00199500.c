#include "types.h"
#pragma mpwc_relax on
int cMessage_ctor_cMessageNameR(char **, char *);
void cHuman_RequestEquipGoggles(int o, unsigned char on, int f);
int cMessage_dtor(char **, int);
extern char D_004DCF10;
extern char D_004DA8B0;
extern signed char *D_005061D0;
extern char D_004EEE80;

void cEquipGogglesMsg_NetReceive(int arg0) {
    struct { char * f20[8]; signed char f40[4]; signed char f44[12]; } sl;
    signed char* p;

    cMessage_ctor_cMessageNameR(sl.f20, &D_004EEE80);
    sl.f20[0] = &D_004DA8B0;
    { signed char t = *D_005061D0; D_005061D0 += 1; p = &sl.f44[0]; *p = t; }
    if (arg0 != 0) {
        cHuman_RequestEquipGoggles(arg0, *p != 0, 1);
    }
    sl.f20[0] = &D_004DCF10;
    cMessage_dtor(sl.f20, 0);
}
