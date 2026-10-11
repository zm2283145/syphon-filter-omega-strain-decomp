#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Event_Send(char **, char *, int);                         
int SoundEvent_CtorFromPreset(char **, char * , char * );  
int cMessage_dtor(char **, int);                           
int func_0036E220(char *, int);                            
extern char D_004DAE30;
extern char D_004FFB50;
extern char func_001C6700;

#pragma opt_common_subs off
int Script_cSoundGOBJ_Trigger(void **arg0) {
    struct { char * f10[8]; signed char f30[88]; int f88[39]; int f124[43]; } sl;
    char * temp_v1;
    char * var_a2;

    temp_v1 = *arg0;
    var_a2 = (F_(temp_v1, 0x1F2, unsigned char) != 0) ? temp_v1 : NULL;
    if (F_(temp_v1, 0x1F0, unsigned char) == 0) {
        F_(temp_v1, 0x1F0, unsigned char) = 1U;
        SoundEvent_CtorFromPreset(sl.f10, temp_v1 + 0x60, var_a2);
        if (&func_001C6700 == NULL) {
            sl.f30[0] = 1;
        }
        Event_Send(sl.f10, &D_004FFB50, 1);
        sl.f10[0] = &D_004DAE30;
        func_0036E220(sl.f124, -1);
        func_0036E220(sl.f88, -1);
        cMessage_dtor(sl.f10, 0);
    }
    return 0;
}
