#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Event_Construct(char **, char *);                       
int Global_SetPersonalTimer(float, int, int);           
int Loc_GetTextById(int);                           
int NetRead_Float(float *);                             
int Stream_ReadU32(int *);                            
int cMessage_dtor(char **, int);                           
extern char D_004DCB90;
extern char D_004DCF10;
extern char D_004F8580;

void func_002679F0(int arg0) {
    struct { char * f40[9]; float f64; int f68[2]; } sl;

    Event_Construct(sl.f40, &D_004F8580);
    sl.f40[0] = &D_004DCB90;
    NetRead_Float(&sl.f64);
    Stream_ReadU32(sl.f68);
    Global_SetPersonalTimer(sl.f64, arg0, Loc_GetTextById(sl.f68[0]));
    sl.f40[0] = &D_004DCF10;
    cMessage_dtor(sl.f40, 0);
}
