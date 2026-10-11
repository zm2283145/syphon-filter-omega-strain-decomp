#include "types.h"

typedef struct { void* vtbl; char pad004[0x1C]; unsigned char flag; char pad021[0x57]; char partA[0x9C]; char partB[0xAC]; } SoundMsg_355490;
typedef struct { void* vtbl; char pad004[0x1C]; unsigned char flag; char pad021[0x57]; char partA[0x9C]; char partB[0xAC]; char pad1C0[0x10]; } SoundEventMsg_355490;
typedef struct { char pad[0x14]; unsigned short flags; } Widget_355490;
typedef struct {
    char pad0[0x8C]; int f8C; int f90; char pad94[4]; Widget_355490* w98; Widget_355490* w9C; Widget_355490* wA0;
    char padA4[0xC]; char action[0x44]; unsigned char playing; char padF5[0x240 - 0xF5]; int state;
} Self_355490;
typedef struct { char pad[0x25C]; int f25C; } Cfg_355490;

extern char D_004FFB50[];
extern char D_004DADF0[];
extern char D_004DAE10[];
extern char D_004BB0E0[];
extern char D_004BB0F0[];
extern Cfg_355490* D_004FFC04;
extern void SoundEvent_Ctor(SoundEventMsg_355490* msg, void* action, int flags);
extern void Event_Send(void* msg, void* target, int flags);
extern void func_0036E220(void* part, int flags);
extern void cMessage_dtor(void* msg, int flags);
extern void SoundAction_CtorVoice(void* action, int kind, char* voice, int a, int b);
extern void SoundMsg_WrapAction(SoundMsg_355490* msg, void* action);
extern void func_0043C890(Widget_355490* w, char* s, int v);
extern void func_0043C810(Widget_355490* w);
extern int sprintf(char* buf, const char* fmt, ...);

static inline void StopVoice_355490(Self_355490* self)
{
    SoundEventMsg_355490 stop;
    self->playing = 0;
    SoundEvent_Ctor(&stop, self->action, 0);
    stop.flag = 1;
    Event_Send(&stop, D_004FFB50, 1);
    stop.vtbl = D_004DADF0;
    func_0036E220(stop.partB, -1);
    func_0036E220(stop.partA, -1);
    cMessage_dtor(&stop, 0);
}

static inline void PlayVoice_355490(Self_355490* self, char* voice)
{
    SoundMsg_355490 play;
    StopVoice_355490(self);
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

void func_00355490(Self_355490* self, int on)
{
    char buf[0x20];
    if (on == 1) {
        if (self->wA0) self->wA0->flags |= 2;
        if (self->w9C) self->w9C->flags &= ~2;
        if (self->w98) {
            sprintf(buf, D_004BB0E0, self->f8C, self->f90);
            func_0043C890(self->w98, buf, D_004FFC04->f25C);
            self->w98->flags |= 2;
            sprintf(buf, D_004BB0F0, self->f8C, self->f90);
            PlayVoice_355490(self, buf);
        }
    } else {
        if (self->wA0) self->wA0->flags &= ~2;
        if (self->w9C) self->w9C->flags |= 2;
        if (self->w98) {
            func_0043C810(self->w98);
            self->w98->flags &= ~2;
        }
        StopVoice_355490(self);
    }
    self->state = on;
}