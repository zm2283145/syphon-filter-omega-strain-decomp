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

extern int D_004FFB50;
extern int D_004DADF0;
extern void SoundRequest_Ctor(SndCmd*, signed char, int, int, int);
extern void SoundEvent_Ctor(EventMsg*, void*, int);
extern void Event_Send(EventMsg*, void*, int);
extern void func_0036E220(void*, int);
extern void cMessage_dtor(EventMsg*, int);

extern unsigned char D_005721C8;
extern unsigned char D_005721C0;
static inline int Snd_Allowed(void) { return D_005721C8 ? D_005721C0 : 1; }
void Sound_StopForObject(int channel, int id, int obj) {
    EventMsg msg;
    SndCmd cmd;
    SoundRequest_Ctor(&cmd, (signed char)channel, id, obj, 0);
    SoundEvent_Ctor(&msg, &cmd, 0);
    func_0036E220(cmd.partB, -1);
    func_0036E220(cmd.partA, -1);
    if (!D_005721C8 || !Snd_Allowed()) msg.immediate = 1;
    Event_Send(&msg, &D_004FFB50, 0);
    msg.vtable = &D_004DADF0;
    func_0036E220(msg.partB, -1);
    func_0036E220(msg.partA, -1);
    cMessage_dtor(&msg, 0);
}