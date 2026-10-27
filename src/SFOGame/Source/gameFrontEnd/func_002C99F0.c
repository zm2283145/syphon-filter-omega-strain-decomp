#include "types.h"

typedef struct FlagMsg {
    void* vtbl;
    char pad04[0x1C];
    unsigned char flag;  /* 0x20 */
    char pad21[0xF];
} FlagMsg;

extern char g_Game[];
extern char D_004D97F0[];
extern void cPauseMusicMsg_ctor(FlagMsg* msg);
extern void QueueMessage_cMessageR_cSystemP_int(FlagMsg* msg, void* target, int flags);
extern void cMessage_dtor(FlagMsg* msg, int flags);

/* Broadcasts a flagged message. */
void cGameFrontEnd_PauseMusic(void) {
    FlagMsg msg;
    cPauseMusicMsg_ctor(&msg);
    msg.flag = 1;
    QueueMessage_cMessageR_cSystemP_int(&msg, g_Game, 1);
    msg.vtbl = D_004D97F0;
    cMessage_dtor(&msg, 0);
}
