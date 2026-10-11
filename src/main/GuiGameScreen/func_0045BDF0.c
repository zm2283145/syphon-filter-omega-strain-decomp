#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int Event_Construct();                       
int Event_Send();                         
int cMessage_dtor();                           
int func_0045BF80();                            
extern char D_004DC330;
extern char D_004F7E48;

#pragma push
#pragma opt_common_subs off
void func_0045BDF0(char * arg0) {
    struct { char * f40[9]; int f64; unsigned int f68[2]; } sl;
    int temp_s2;
    unsigned int temp_s0;
    char * temp_v0;

    if (F_(arg0, 0xE0, int) != 0) {
        temp_v0 = (char *)(F_(arg0, 0xE8, int));
        temp_s0 = F_(temp_v0, 0x54, int);
        if ((temp_s0 < (unsigned int) (F_(temp_v0, 0x94, int) - 1)) && (F_(arg0, 0xEC, int) != 0)) {
            temp_s2 = F_(arg0, 0xF0, int);
            Event_Construct(sl.f40, &D_004F7E48);
            sl.f64 = temp_s2;
            sl.f68[0] = temp_s0;
            sl.f40[0] = &D_004DC330;
            Event_Send(sl.f40, F_(arg0, 0xEC, int), 0);
            sl.f40[0] = &D_004DC330;
            cMessage_dtor(sl.f40, 0);
        }
        func_0045BF80(arg0);
    }
}
#pragma pop
