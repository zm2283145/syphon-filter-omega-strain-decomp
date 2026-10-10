#include "types.h"
typedef struct EventMsg {
    void* vtable;
    char pad04[0x74];
    char partA[0x9C];           /* 0x78 */
    char partB[0xBC];           /* 0x114 */
} EventMsg;
typedef struct { char pad[0x1C0]; char cmd[0x44]; unsigned char pending; } S;
extern int D_004FFB50;
extern int D_004DADF0;
extern void SoundEvent_Ctor(EventMsg*, void*, int);
extern void Event_Send(EventMsg*, void*, int);
extern void func_0036E220(void*, int);
extern void cMessage_dtor(EventMsg*, int);
/* Clears the pending flag and broadcasts the stored command as an immediate event. */
void func_0045F6F0(S* s)
{
    EventMsg msg;
    s->pending = 0;
    SoundEvent_Ctor(&msg, s->cmd, 0);
    Event_Send(&msg, &D_004FFB50, 1);
    msg.vtable = &D_004DADF0;
    func_0036E220(msg.partB, -1);
    func_0036E220(msg.partA, -1);
    cMessage_dtor(&msg, 0);
}
