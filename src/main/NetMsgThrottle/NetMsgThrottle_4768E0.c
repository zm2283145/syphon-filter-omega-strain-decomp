#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Event_Construct(char **, char *);                       
int Event_Send(char **, int, int);                         
int cMessage_dtor(char **, int);                           
extern char D_004DCF10;
extern char D_004E1AE0;
extern signed char *D_005061D0;
extern char D_00588038;

void func_004768E0(int arg0) {
    struct { char * f20[8]; signed char f40[4]; signed char f44[12]; } sl;
    signed char temp_v1;

    Event_Construct(sl.f20, &D_00588038);
    sl.f20[0] = &D_004E1AE0;
    temp_v1 = *D_005061D0;
    D_005061D0 += 1;
    sl.f44[0] = temp_v1 != 0;
    if (arg0 != 0) {
        sl.f40[0] = 1;
        Event_Send(sl.f20, arg0, 1);
    }
    sl.f20[0] = &D_004DCF10;
    cMessage_dtor(sl.f20, 0);
}
