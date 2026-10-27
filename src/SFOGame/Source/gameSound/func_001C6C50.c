#include "types.h"

/* Sound command payload built on the stack. */
typedef struct SndCmd {
    char pad00[0x48];
    char partA[0x9C];           /* 0x48 */
    char partB[0xAC];           /* 0xE4, size 0x190 */
} SndCmd;

/* Event message built on the stack (C++ object with inlined destructor). */
typedef struct EventMsg {
    void* vtable;
    char pad04[0x1C];
    unsigned char immediate;    /* 0x20 */
    char pad21[0x57];
    char partA[0x9C];           /* 0x78 */
    char partB[0xBC];           /* 0x114 */
} EventMsg;

extern int g_Game;
extern int D_004DADF0;
extern void cSndFx_ctor_int_charP_cGOBJP_int(SndCmd*, signed char, int, int, int);
extern void cStopSoundMsg_ctor_cSndFxR_bool(EventMsg*, void*, int);
extern void QueueMessage_cMessageR_cSystemP_int(EventMsg*, void*, int);
extern void cFileMan_dtor(void*, int);
extern void cMessage_dtor(EventMsg*, int);

/* Global: StopSnd(channel, id) - broadcasts a stop-sound event. */
void nGameSound_StopSnd_eSndBank_charP(int channel, int id) {
    SndCmd cmd;
    EventMsg msg;
    cSndFx_ctor_int_charP_cGOBJP_int(&cmd, (signed char)channel, id, 0, 0);
    cStopSoundMsg_ctor_cSndFxR_bool(&msg, &cmd, 0);
    cFileMan_dtor(cmd.partB, -1);
    cFileMan_dtor(cmd.partA, -1);
    msg.immediate = 1;
    QueueMessage_cMessageR_cSystemP_int(&msg, &g_Game, 0);
    msg.vtable = &D_004DADF0;
    cFileMan_dtor(msg.partB, -1);
    cFileMan_dtor(msg.partA, -1);
    cMessage_dtor(&msg, 0);
}
