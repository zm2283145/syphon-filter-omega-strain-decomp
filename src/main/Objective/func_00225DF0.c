#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Event_Construct(char **, char *);                       
int Event_Send(char **, int, int);                           
int cMessage_dtor(char **, int);                           
int func_00228BE0(int, int);                            
extern char D_004DE4F0;
extern char D_0051F0B0;
extern unsigned char D_005721C8;

void cObjectiveMan_SetPartialSuccess(int d0, int arg1, int arg2) {
    struct { char * f30[7]; int f4C; signed char f50[12]; signed char f5C[4]; int f60[8]; } sl;

    if (D_005721C8 != 0) {
        Event_Construct(sl.f30, &D_0051F0B0);
        sl.f60[0] = arg2;
        sl.f30[0] = &D_004DE4F0;
        sl.f5C[0] = 3;
        sl.f4C = 0x40;
        sl.f50[0] = 4;
        sl.f4C = 0x40;
        Event_Send(sl.f30, arg1, 0);
        sl.f30[0] = &D_004DE4F0;
        cMessage_dtor(sl.f30, 0);
    }
    func_00228BE0(arg1, arg2);
}
