#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int Event_Send();                         
int SoundEvent_Ctor();                    
int cMessage_dtor();                           
int func_0036E220();                            
int func_0041F070();                                  
int func_00459450();                               
extern char D_004DADF0;
extern char D_004FFB50;

void func_00454880(char * arg0) {
    struct { char * f20[8]; signed char f40[88]; int f98[39]; int f134[47]; } sl;
    int temp_a0;

    func_0041F070();
    SoundEvent_Ctor(sl.f20, arg0 + 0x50, 0);
    sl.f40[0] = 1;
    Event_Send(sl.f20, &D_004FFB50, 1);
    temp_a0 = F_(arg0, 0x4C, int);
    if (temp_a0 != 0) {
        func_00459450(temp_a0);
    }
    sl.f20[0] = &D_004DADF0;
    func_0036E220(sl.f134, -1);
    func_0036E220(sl.f98, -1);
    cMessage_dtor(sl.f20, 0);
}
