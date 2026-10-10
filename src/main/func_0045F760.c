#include "types.h"

typedef struct SoundMsg {
    void* vtbl;
    char pad004[0x1C];
    unsigned char flag; /* 0x020 */
    char pad021[0x57];
    char partA[0x9C];   /* 0x078 */
    char partB[0xAC];   /* 0x114 */
} SoundMsg; /* size 0x1C0 */

typedef struct SoundEventMsg {
    void* vtbl;
    char pad004[0x74];
    char partA[0x9C];   /* 0x078 */
    char partB[0xAC];   /* 0x114 */
    char pad1C0[0x10];
} SoundEventMsg; /* size 0x1D0 */

typedef struct VoiceOwner {
    char pad000[0x1C0];
    char action[0x44];      /* 0x1C0 */
    unsigned char playing;  /* 0x204 */
} VoiceOwner;

extern char D_004FFB50[];
extern char D_004DADF0[];
extern char D_004DAE10[];
extern void SoundEvent_Ctor(SoundEventMsg* msg, void* action, int flags);
extern void Event_Send(void* msg, void* target, int flags);
extern void func_0036E220(void* part, int flags);
extern void cMessage_dtor(void* msg, int flags);
extern void SoundAction_CtorVoice(void* action, int kind, int voice, int a, int b);
extern void SoundMsg_WrapAction(SoundMsg* msg, void* action);

/* Stops the current voice line and starts a new one. */
void func_0045F760(VoiceOwner* self, int voice) {
    SoundEventMsg stop;
    SoundMsg play;
    self->playing = 0;
    SoundEvent_Ctor(&stop, self->action, 0);
    Event_Send(&stop, D_004FFB50, 1);
    stop.vtbl = D_004DADF0;
    func_0036E220(stop.partB, -1);
    func_0036E220(stop.partA, -1);
    cMessage_dtor(&stop, 0);
    SoundAction_CtorVoice(self->action, 4, voice, 0, 0);
    self->playing = 0;
    SoundMsg_WrapAction(&play, self->action);
    play.flag = 1;
    Event_Send(&play, D_004FFB50, 1);
    play.vtbl = D_004DAE10;
    func_0036E220(play.partB, -1);
    func_0036E220(play.partA, -1);
    cMessage_dtor(&play, 0);
}
