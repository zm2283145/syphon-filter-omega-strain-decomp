#pragma cplusplus on
#include "types.h"

typedef struct { void* vtbl; char pad004[0x1C]; unsigned char flag; char pad021[0x57]; char partA[0x9C]; char partB[0xAC]; } SoundMsg_4610F0;
typedef struct { void* vtbl; char pad004[0x1C]; unsigned char flag; char pad021[0x57]; char partA[0x9C]; char partB[0xAC]; char pad1C0[0x10]; } SoundEventMsg_4610F0;

typedef struct {
    char voice[8];
    int duration;
} Line_4610F0;

typedef struct {
    char pad0[4];
    int count;              /* 0x04 */
    Line_4610F0* lines;     /* 0x08 */
    char pad0C[4];
    float duration;         /* 0x10 */
    char pad14[0xC];
    char action[0x44];      /* 0x20 */
    unsigned char playing;  /* 0x64 */
    char pad65[0x1B0 - 0x65];
    int cur;                /* 0x1B0 */
} Self_4610F0;

extern "C" {
extern char D_004FFB50[];
extern char D_004DADF0[];
extern char D_004DAE10[];
extern void SoundEvent_Ctor(SoundEventMsg_4610F0* msg, void* action, int flags);
extern void Event_Send(void* msg, void* target, int flags);
extern void func_0036E220(void* part, int flags);
extern void cMessage_dtor(void* msg, int flags);
extern void SoundAction_CtorVoice(void* action, int kind, char* voice, int a, int b);
extern void SoundMsg_WrapAction(SoundMsg_4610F0* msg, void* action);
}

static inline void StopVoice_4610F0(Self_4610F0* self)
{
    SoundEventMsg_4610F0 stop;
    self->playing = 0;
    SoundEvent_Ctor(&stop, self->action, 0);
    stop.flag = 1;
    Event_Send(&stop, D_004FFB50, 1);
    stop.vtbl = D_004DADF0;
    func_0036E220(stop.partB, -1);
    func_0036E220(stop.partA, -1);
    cMessage_dtor(&stop, 0);
}

static inline void PlayVoice_4610F0(Self_4610F0* self, char* voice)
{
    SoundMsg_4610F0 play;
    StopVoice_4610F0(self);
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

extern "C" void func_004610F0(Self_4610F0* self)
{
    if (self->cur < self->count) {
        Line_4610F0* line = &self->lines[self->cur++];
        PlayVoice_4610F0(self, line->voice);
        self->duration = line->duration;
    }
}
