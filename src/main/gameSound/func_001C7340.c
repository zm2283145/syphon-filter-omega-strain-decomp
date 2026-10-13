#include "types.h"
typedef struct { void* vt; char pad[0x20]; int id; int arg; char pad2c[4]; } Msg_7340;
int Event_Construct(Msg_7340*, void*);
int Stream_ReadU32(int*);
int cMessage_dtor(Msg_7340*, int);
void* Loc_GetStoredKey(int);
int Voice_PlayQuip(void*, int, int);
extern char D_004DCF10[];
extern char D_004DAC70[];
extern char D_004F2D00[];

/* net message handler: read quip id and argument, play the quip if it resolves */
void func_001C7340(void)
{
    Msg_7340 m;
    void* p;
    Event_Construct(&m, D_004F2D00);
    m.vt = D_004DAC70;
    Stream_ReadU32(&m.id);
    Stream_ReadU32(&m.arg);
    p = (m.id != -1) ? Loc_GetStoredKey(m.id) : 0;
    if (p) Voice_PlayQuip(p, m.arg, 1);
    m.vt = D_004DCF10;
    cMessage_dtor(&m, 0);
}

