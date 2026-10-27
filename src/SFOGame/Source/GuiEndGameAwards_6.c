/*
 * SFOGame/Source/GuiEndGameAwards: 2 files, 0045F4D0-0045F6F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0045F4D0 */
#pragma push /* merge_units */
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
extern char g_Game[];
extern char D_004DADF0[];
extern char D_004DAE10[];
extern void cStopSoundMsg_ctor_cSndFxR_bool(SoundEventMsg_45F4D0* msg, void* action, int flags);
extern void QueueMessage_cMessageR_cSystemP_int(void* msg, void* target, int flags);
extern void cFileMan_dtor(void* part, int flags);
extern void cMessage_dtor(void* msg, int flags);
extern void cSndFx_SetSndFx(void* action, int kind, char* voice, int a, int b);
extern void SoundMsg_WrapAction(SoundMsg_45F4D0* msg, void* action);
extern void GuiWidget_SendMessage(void* a, void* b, int c, int d, int e);
extern Obj_45F4D0* GuiWidget_FindChild_charP(void* self, char* name);
extern void GuiTextWidget_SetText(Obj_45F4D0* obj, int arg, int c);
}

static inline void StopVoice_45F4D0(Self_45F4D0* self)
{
    SoundEventMsg_45F4D0 stop;
    self->playing = 0;
    cStopSoundMsg_ctor_cSndFxR_bool(&stop, self->action, 0);
    QueueMessage_cMessageR_cSystemP_int(&stop, g_Game, 1);
    stop.vtbl = D_004DADF0;
    cFileMan_dtor(stop.partB, -1);
    cFileMan_dtor(stop.partA, -1);
    cMessage_dtor(&stop, 0);
}

static inline void PlayVoice_45F4D0(Self_45F4D0* self, char* voice)
{
    SoundMsg_45F4D0 play;
    StopVoice_45F4D0(self);
    cSndFx_SetSndFx(self->action, 4, voice, 0, 0);
    self->playing = 0;
    SoundMsg_WrapAction(&play, self->action);
    play.flag = 1;
    QueueMessage_cMessageR_cSystemP_int(&play, g_Game, 1);
    play.vtbl = D_004DAE10;
    cFileMan_dtor(play.partB, -1);
    cFileMan_dtor(play.partA, -1);
    cMessage_dtor(&play, 0);
}

extern "C" int GuiEndGameAwards_ActivateNextAward(Self_45F4D0* self)
{
    Entry_45F4D0* e;
    Obj_45F4D0* obj;
    if (self->count == 0 || self->cur >= self->count - 1) {
        return 0;
    }
    if (self->cur >= 0) {
        GuiWidget_SendMessage(self, self->ent[self->cur].obj, 6, (int)"onDeactivate", 0);
    }
    self->cur++;
    obj = GuiWidget_FindChild_charP(self, "value_awardstring");
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
        GuiWidget_SendMessage(self, e->obj, 6, (int)"onActivate", 0);
    }
    return 1;
}
static inline void merge_flush_func_0045F4D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0045F4D0 */

/* merge_units: begin func_0045F6F0 */
#pragma push /* merge_units */
typedef struct EventMsg {
    void* vtable;
    char pad04[0x74];
    char partA[0x9C];           /* 0x78 */
    char partB[0xBC];           /* 0x114 */
} EventMsg;
typedef struct { char pad[0x1C0]; char cmd[0x44]; unsigned char pending; } S;
#if 0 /* merge_units */
extern int g_Game;
#endif /* merge_units */
#define g_Game (*(int*)&g_Game) /* merge_units */

#if 0 /* merge_units */
extern int D_004DADF0;
#endif /* merge_units */
#define D_004DADF0 (*(int*)&D_004DADF0) /* merge_units */

#if 0 /* merge_units */
extern void cStopSoundMsg_ctor_cSndFxR_bool(EventMsg*, void*, int);
#endif /* merge_units */
#define cStopSoundMsg_ctor_cSndFxR_bool(a0, a1, a2) (cStopSoundMsg_ctor_cSndFxR_bool((SoundEventMsg_45F4D0 *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern void QueueMessage_cMessageR_cSystemP_int(EventMsg*, void*, int);
#endif /* merge_units */
#define QueueMessage_cMessageR_cSystemP_int(a0, a1, a2) (QueueMessage_cMessageR_cSystemP_int((void *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern void cFileMan_dtor(void*, int);
#endif /* merge_units */
#define cFileMan_dtor(a0, a1) (cFileMan_dtor((a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void cMessage_dtor(EventMsg*, int);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */

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
#undef g_Game /* merge_units */
#undef D_004DADF0 /* merge_units */
#undef cStopSoundMsg_ctor_cSndFxR_bool /* merge_units */
#undef QueueMessage_cMessageR_cSystemP_int /* merge_units */
#undef cFileMan_dtor /* merge_units */
#undef cMessage_dtor /* merge_units */
static inline void merge_flush_func_0045F6F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0045F6F0 */
