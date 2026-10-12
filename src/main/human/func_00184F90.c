#include "types.h"
typedef struct { void* vt; char pad[0x20]; unsigned char on; char pad25[3]; float a; float b; } Msg_4F90;
void Event_Construct(Msg_4F90*, void*);
void Stream_ReadBool(unsigned char*);
void NetRead_Float(float*);
int func_00185080(void);
int func_00185060(void*, int);
void Global_ShockToDeath(void*, unsigned char, float, float, int);
void cMessage_dtor(Msg_4F90*, int);
extern char D_004EF078[];
extern char D_004DA9F0[];
extern char D_004DCF10[];
/* net handler: shock the target to death when it accepts the request */
void func_00184F90(void* target)
{
    Msg_4F90 m;
    Event_Construct(&m, D_004EF078);
    m.vt = D_004DA9F0;
    Stream_ReadBool(&m.on);
    NetRead_Float(&m.a);
    NetRead_Float(&m.b);
    if (target && func_00185060(target, func_00185080())) Global_ShockToDeath(target, m.on, m.a, m.b, 0);
    m.vt = D_004DCF10;
    cMessage_dtor(&m, 0);
}

