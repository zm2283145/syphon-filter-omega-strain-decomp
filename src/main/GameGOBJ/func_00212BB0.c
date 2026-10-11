#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Event_Send(char **, char *, int);                         
int Object_Activate(char * , int);                       
int SoundEvent_CtorFromPreset(char **, char * , char * );  
int cMessage_dtor(char **, int);                           
int func_0036E220(char *, int);                            
extern char D_004DAE30;
extern char D_004FFB50;
extern char func_001C6700;

#pragma opt_common_subs off
void cSoundGOBJ_v15(char * arg0, int arg1) {
    struct { char * f30[8]; signed char f50[88]; int fA8[39]; int f144[43]; } sl;
    char * var_a2;

    if (F_(arg0, 0x1F1, unsigned char) != 0) {
        var_a2 = NULL;
        if (F_(arg0, 0x1F2, unsigned char) != 0) {
            var_a2 = arg0;
        }
        if (F_(arg0, 0x1F0, unsigned char) == 0) {
            F_(arg0, 0x1F0, unsigned char) = 1U;
            SoundEvent_CtorFromPreset(sl.f30, arg0 + 0x60, var_a2);
            if (&func_001C6700 == NULL) {
                sl.f50[0] = 1;
            }
            Event_Send(sl.f30, &D_004FFB50, 1);
            sl.f30[0] = &D_004DAE30;
            func_0036E220(sl.f144, -1);
            func_0036E220(sl.fA8, -1);
            cMessage_dtor(sl.f30, 0);
        }
    }
    Object_Activate(arg0, arg1);
}
