#include "types.h"
typedef struct EventMsg {
    void* vtable;
    char pad04[0x74];
    char partA[0x9C];           /* 0x78 */
    char partB[0xBC];           /* 0x114 */
} EventMsg;
typedef struct { char pad[0x1C0]; char cmd[0x44]; unsigned char pending; } S;
extern int g_Game;
extern int D_004DADF0;
extern void cStopSoundMsg_ctor_cSndFxR_bool(EventMsg*, void*, int);
extern void QueueMessage_cMessageR_cSystemP_int(EventMsg*, void*, int);
extern void cFileMan_dtor(void*, int);
extern void cMessage_dtor(EventMsg*, int);
/* Clears the pending flag and broadcasts the stored command as an immediate event. */
void GuiEndGameAwards_StopPlayback(S* s)
{
    EventMsg msg;
    s->pending = 0;
    cStopSoundMsg_ctor_cSndFxR_bool(&msg, s->cmd, 0);
    QueueMessage_cMessageR_cSystemP_int(&msg, &g_Game, 1);
    msg.vtable = &D_004DADF0;
    cFileMan_dtor(msg.partB, -1);
    cFileMan_dtor(msg.partA, -1);
    cMessage_dtor(&msg, 0);
}
