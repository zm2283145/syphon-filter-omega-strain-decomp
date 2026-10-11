#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Event_Construct(char **, char *);                       
int ObjMarkerMgr_Remove(int, char * , int);              
int Transport_Send(int, char **, int, int);                    
int cMessage_dtor(char **, int);                           
extern char D_004DE650;
extern int D_004FFC2C;
extern char D_0052ACF8;
extern unsigned char D_005721C8;

void func_00275030(char * arg0, int arg1) {
    struct { char * f30[8]; signed char f50[4]; int f54[3]; } sl;
    int temp_s0;

    if ((arg1 == 0) && (D_005721C8 != 0)) {
        temp_s0 = F_(arg0, 0xC, int);
        Event_Construct(sl.f30, &D_0052ACF8);
        sl.f30[0] = &D_004DE650;
        sl.f50[0] = 4;
        sl.f54[0] = temp_s0;
        Transport_Send(0, sl.f30, -1, -1);
        sl.f30[0] = &D_004DE650;
        cMessage_dtor(sl.f30, 0);
    }
    ObjMarkerMgr_Remove(D_004FFC2C + 0x90, arg0 + 0xC, 1);
}
