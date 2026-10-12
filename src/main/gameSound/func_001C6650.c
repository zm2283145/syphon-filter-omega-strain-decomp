#include "types.h"
int Event_Send(void*, void*, int);
int SoundEvent_Ctor(void*, void*, int);
int SoundRequest_Ctor(void*, int, void*, int, int);
int cMessage_dtor(void*, int);
int func_0036E220(void*, int);
extern char D_0049F498[];
extern char D_004DADF0[];
extern char D_004FFB50[];
extern void func_001C6700(void);
typedef struct { int w[43]; } A2C4; typedef struct { int w[39]; } A228; typedef struct { int w[18]; } A1E0; typedef struct { int w[47]; } A124; typedef struct { int w[39]; } A88; typedef struct { void* vt; int w[29]; } A10;
/* stop all quips: broadcast a stop sound event; the message objects share one
 * stack block (4-byte aligned layout) */
#pragma push
#pragma opt_common_subs off
void Global_StopAllQuips(void) {
    struct { A10 sp10; A88 sp88; A124 sp124; A1E0 sp1E0; A228 sp228; A2C4 sp2C4; } L;
    if (&func_001C6700 != 0) {
        SoundRequest_Ctor(&L.sp1E0, 4, D_0049F498, 0, 0);
        SoundEvent_Ctor(&L.sp10, &L.sp1E0, 0);
        Event_Send(&L.sp10, D_004FFB50, 0);
        L.sp10.vt = D_004DADF0;
        func_0036E220(&L.sp124, -1);
        func_0036E220(&L.sp88, -1);
        cMessage_dtor(&L.sp10, 0);
        func_0036E220(&L.sp2C4, -1);
        func_0036E220(&L.sp228, -1);
    }
}
#pragma pop
