#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Event_Construct(char **, char *);                       
int Stream_ReadU32(int *);                            
int cMessage_dtor(char **, int);                           
int Loc_GetStoredKey(int);                             
int func_0045ECA0(int, unsigned char);                           
extern char D_004DCF10;
extern char D_004E1680;
extern char D_00586158;

void func_0045EBC0(void) {
    struct { char * f30[9]; int f54; int f58[2]; } sl;
    int temp_a0;

    Event_Construct(sl.f30, &D_00586158);
    sl.f30[0] = &D_004E1680;
    Stream_ReadU32(&sl.f54);
    Stream_ReadU32(sl.f58);
    temp_a0 = sl.f54;
    if (temp_a0 != -1) {
        func_0045ECA0(Loc_GetStoredKey(temp_a0), sl.f58[0]);
    }
    sl.f30[0] = &D_004DCF10;
    cMessage_dtor(sl.f30, 0);
}
