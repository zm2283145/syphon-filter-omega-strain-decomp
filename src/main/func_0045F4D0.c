#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"

typedef struct { void* vtbl; char pad004[0x1C]; unsigned char flag; char pad021[0x57]; char partA[0x9C]; char partB[0xAC]; } SoundMsg_45F4D0;
typedef struct { void* vtbl; char pad004[0x1C]; unsigned char flag; char pad021[0x57]; char partA[0x9C]; char partB[0xAC]; char pad1C0[0x10]; } SoundEventMsg_45F4D0;

struct Obj_45F4D0 {
    VPAD16(a) VPAD4(b) virtual int IsA(void* type);
    char pad4[0x10];
    unsigned short flags;
};

typedef struct {
    Obj_45F4D0* obj;
    int arg;
    char voice[0x10];
} Entry_45F4D0;

typedef struct {
    char pad0[0x48];
    Entry_45F4D0 ent[15];
    char pad1B0[4];
    int count;              /* 0x1B4 */
    int cur;                /* 0x1B8 */
    char pad1BC[4];
    char action[0x44];      /* 0x1C0 */
    unsigned char playing;  /* 0x204 */
} Self_45F4D0;

extern "C" {
extern char D_004A7520[];
extern char D_004FFB50[];
extern char D_004DADF0[];
extern char D_004DAE10[];
extern void SoundEvent_Ctor(SoundEventMsg_45F4D0* msg, void* action, int flags);
extern void Event_Send(void* msg, void* target, int flags);
extern void FileMan_Release(void* part, int flags);
extern void cMessage_dtor(void* msg, int flags);
extern void SoundAction_CtorVoice(void* action, int kind, char* voice, int a, int b);
extern void SoundMsg_WrapAction(SoundMsg_45F4D0* msg, void* action);
extern void GuiWidget_SendEvent(void* a, void* b, int c, int d, int e);
extern Obj_45F4D0* GuiWidget_FindChildByName(void* self, char* name);
extern void GuiTextWidget_SetText(Obj_45F4D0* obj, int arg, int c);
}

static inline void StopVoice_45F4D0(Self_45F4D0* self)
{
    SoundEventMsg_45F4D0 stop;
    self->playing = 0;
    SoundEvent_Ctor(&stop, self->action, 0);
    Event_Send(&stop, D_004FFB50, 1);
    stop.vtbl = D_004DADF0;
    FileMan_Release(stop.partB, -1);
    FileMan_Release(stop.partA, -1);
    cMessage_dtor(&stop, 0);
}

static inline void PlayVoice_45F4D0(Self_45F4D0* self, char* voice)
{
    SoundMsg_45F4D0 play;
    StopVoice_45F4D0(self);
    SoundAction_CtorVoice(self->action, 4, voice, 0, 0);
    self->playing = 0;
    SoundMsg_WrapAction(&play, self->action);
    play.flag = 1;
    Event_Send(&play, D_004FFB50, 1);
    play.vtbl = D_004DAE10;
    FileMan_Release(play.partB, -1);
    FileMan_Release(play.partA, -1);
    cMessage_dtor(&play, 0);
}

extern "C" int GuiEndGameAwards_Next(Self_45F4D0* self)
{
    Entry_45F4D0* e;
    Obj_45F4D0* obj;
    if (self->count == 0 || self->cur >= self->count - 1) {
        return 0;
    }
    if (self->cur >= 0) {
        GuiWidget_SendEvent(self, self->ent[self->cur].obj, 6, (int)"onDeactivate", 0);
    }
    self->cur++;
    obj = GuiWidget_FindChildByName(self, "value_awardstring");
    obj = (obj && obj->IsA(D_004A7520)) ? obj : 0;
    e = &self->ent[self->cur];
    if (obj != 0) {
        GuiTextWidget_SetText(obj, e->arg, 0);
    }
    if (e->voice[0] != 0) {
        PlayVoice_45F4D0(self, e->voice);
    }
    if (e->obj != 0) {
        e->obj->flags |= 2;
        GuiWidget_SendEvent(self, e->obj, 6, (int)"onActivate", 0);
    }
    return 1;
}







