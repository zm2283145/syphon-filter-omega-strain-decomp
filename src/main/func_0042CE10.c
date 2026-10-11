#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Event_Construct(char **, char *);                       
int Transport_Send(int, char **, int, int);                    
int cMessage_dtor(char **, int);                           
int func_0042D300(int *);                             
extern char D_004E1160;
extern unsigned char D_005721C0;
extern unsigned char D_005721C8;
extern char D_00583990;

void func_0042CE10(int *arg0) {
    struct { char * f20[7]; int f3C; signed char f40[4]; int f44[3]; } sl;
    int var_v0;

    if (D_005721C8 != 0) {
        var_v0 = D_005721C0;
    } else {
        var_v0 = 1;
    }
    if (var_v0 != 0) {
        func_0042D300(arg0);
        return;
    }
    Event_Construct(sl.f20, &D_00583990);
    sl.f20[0] = &D_004E1160;
    sl.f44[0] = *arg0;
    sl.f3C = 0x40;
    sl.f40[0] = 2;
    Transport_Send(0, sl.f20, 0, 0);
    sl.f20[0] = &D_004E1160;
    cMessage_dtor(sl.f20, 0);
}
