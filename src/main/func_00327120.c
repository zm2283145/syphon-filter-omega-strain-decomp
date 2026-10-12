#include "types.h"
/* Stops the current voice line and plays a new one. */

typedef struct { void* vtbl; char pad004[0x1C]; unsigned char flag; char pad021[0x57]; char partA[0x9C]; char partB[0xAC]; } SoundMsg_327120;
typedef struct { void* vtbl; char pad004[0x1C]; unsigned char flag; char pad021[0x57]; char partA[0x9C]; char partB[0xAC]; char pad1C0[0x10]; } SoundEventMsg_327120;
typedef struct {
    char pad0[0x90]; char action[0x44]; unsigned char playing;
} Self_327120;

extern char D_004FFB50[];
extern char D_004DADF0[];
extern char D_004DAE10[];
extern void SoundEvent_Ctor(SoundEventMsg_327120* msg, void* action, int flags);
extern void Event_Send(void* msg, void* target, int flags);
extern void func_0036E220(void* part, int flags);
extern void cMessage_dtor(void* msg, int flags);
extern void SoundAction_CtorVoice(void* action, int kind, char* voice, int a, int b);
extern void SoundMsg_WrapAction(SoundMsg_327120* msg, void* action);

static inline void StopVoice_327120(Self_327120* self)
{
    SoundEventMsg_327120 stop;
    self->playing = 0;
    SoundEvent_Ctor(&stop, self->action, 0);
    stop.flag = 1;
    Event_Send(&stop, D_004FFB50, 1);
    stop.vtbl = D_004DADF0;
    func_0036E220(stop.partB, -1);
    func_0036E220(stop.partA, -1);
    cMessage_dtor(&stop, 0);
}

static inline void PlayVoice_327120(Self_327120* self, char* voice)
{
    SoundMsg_327120 play;
    StopVoice_327120(self);
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

void func_00327120(Self_327120* self, char* voice)
{
    PlayVoice_327120(self, voice);
}
