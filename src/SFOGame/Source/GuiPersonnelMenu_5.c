/*
 * SFOGame/Source/GuiPersonnelMenu: 5 files, 00355270-003556F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00355270 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "message_two_member_dtor.h"

/* Message destructor: payload members, then cMessage base. */
DEFINE_MESSAGE_TWO_MEMBER_DTOR(func_00355270, D_004DADF0)
static inline void merge_flush_func_00355270(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00355270 */

/* merge_units: begin func_00355300 */
#pragma push /* merge_units */
typedef struct { void* vtbl; char pad004[0x1C]; unsigned char flag; char pad021[0x57]; char partA[0x9C]; char partB[0xAC]; } SoundMsg_355490;
typedef struct { void* vtbl; char pad004[0x1C]; unsigned char flag; char pad021[0x57]; char partA[0x9C]; char partB[0xAC]; char pad1C0[0x10]; } SoundEventMsg_355490;
typedef struct { char pad[0x14]; unsigned short flags; } Widget_355490;
typedef struct {
    char pad0[0x8C]; int f8C; int f90; char pad94[4]; Widget_355490* w98; Widget_355490* w9C; Widget_355490* wA0;
    char padA4[0xC]; char action[0x44]; unsigned char playing; char padF5[0x240 - 0xF5]; int state;
} Self_355490;
typedef struct { char pad[0x25C]; int f25C; } Cfg_355490;

extern char g_Game[];
extern char D_004DADF0[];
extern char D_004DAE10[];
extern char D_004BB0E0[];
extern char D_004BB0F0[];
extern Cfg_355490* D_004FFC04;
extern void cStopSoundMsg_ctor_cSndFxR_bool(SoundEventMsg_355490* msg, void* action, int flags);
extern void QueueMessage_cMessageR_cSystemP_int(void* msg, void* target, int flags);
#if 0 /* merge_units */
extern void cFileMan_dtor(void* part, int flags);
#endif /* merge_units */
#define cFileMan_dtor(a0, a1) (cFileMan_dtor((a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void cMessage_dtor(void* msg, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((a0), (a1))) /* merge_units */

extern void cSndFx_SetSndFx(void* action, int kind, char* voice, int a, int b);
extern void SoundMsg_WrapAction(SoundMsg_355490* msg, void* action);
extern void GuiBitmapWidget_SetBitmap(Widget_355490* w, char* s, int v);
extern void GuiBitmapWidget_ClearBitmap(Widget_355490* w);
extern int sprintf(char* buf, const char* fmt, ...);

static inline void StopVoice_355490(Self_355490* self)
{
    SoundEventMsg_355490 stop;
    self->playing = 0;
    cStopSoundMsg_ctor_cSndFxR_bool(&stop, self->action, 0);
    stop.flag = 1;
    QueueMessage_cMessageR_cSystemP_int(&stop, g_Game, 1);
    stop.vtbl = D_004DADF0;
    cFileMan_dtor(stop.partB, -1);
    cFileMan_dtor(stop.partA, -1);
    cMessage_dtor(&stop, 0);
}

static inline void PlayVoice_355490(Self_355490* self, char* voice)
{
    SoundMsg_355490 play;
    StopVoice_355490(self);
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

void GuiPersonnelMenu_StartPlayback(Self_355490* self, char* voice)
{
    PlayVoice_355490(self, voice);
}
#undef cFileMan_dtor /* merge_units */
#undef cMessage_dtor /* merge_units */
static inline void merge_flush_func_00355300(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00355300 */

/* merge_units: begin func_00355400 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Message destructor: payload members, then cMessage base. */
DEFINE_MESSAGE_TWO_MEMBER_DTOR(func_00355400, D_004DAE10)
static inline void merge_flush_func_00355400(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00355400 */

/* merge_units: begin func_00355490 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void cFileMan_dtor(void* part, int flags);
#endif /* merge_units */
#define cFileMan_dtor(a0, a1) (cFileMan_dtor((a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void cMessage_dtor(void* msg, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((a0), (a1))) /* merge_units */


void GuiPersonnelMenu_SetMode(Self_355490* self, int on)
{
    char buf[0x20];
    if (on == 1) {
        if (self->wA0) self->wA0->flags |= 2;
        if (self->w9C) self->w9C->flags &= ~2;
        if (self->w98) {
            sprintf(buf, "0_%d_%d.tdx", self->f8C, self->f90);
            GuiBitmapWidget_SetBitmap(self->w98, buf, D_004FFC04->f25C);
            self->w98->flags |= 2;
            sprintf(buf, "0_%d_%d", self->f8C, self->f90);
            PlayVoice_355490(self, buf);
        }
    } else {
        if (self->wA0) self->wA0->flags &= ~2;
        if (self->w9C) self->w9C->flags |= 2;
        if (self->w98) {
            GuiBitmapWidget_ClearBitmap(self->w98);
            self->w98->flags &= ~2;
        }
        StopVoice_355490(self);
    }
    self->state = on;
}
#undef cFileMan_dtor /* merge_units */
#undef cMessage_dtor /* merge_units */
static inline void merge_flush_func_00355490(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00355490 */

/* merge_units: begin func_003556F0 */
#pragma push /* merge_units */
/* Event message built on the stack (C++ object with inlined destructor). */
typedef struct EventMsg {
    void* vtable;
    char pad04[0x1C];
    unsigned char immediate;    /* 0x20 */
    char pad21[0x57];
    char partA[0x9C];           /* 0x78 */
    char partB[0xBC];           /* 0x114 */
} EventMsg;

typedef struct ObjF4 {
    char pad[0xB0];
    char target[0x44];
    unsigned char pending;      /* 0xF4 */
} ObjF4;

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
#define cStopSoundMsg_ctor_cSndFxR_bool(a0, a1, a2) (cStopSoundMsg_ctor_cSndFxR_bool((SoundEventMsg_355490 *)(a0), (a1), (a2))) /* merge_units */

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

extern void GuiWidget_onSleep(ObjF4*);
extern void* GetFileStreamMan(void);
extern void cFileStreamMan_Purge(void*);
extern void cMemMan_ReleaseBin(int);

/* Shutdown: base cleanup, sends an immediate event for the target, then notifies the singleton. */
void GuiPersonnelMenu_onSleep(ObjF4* o) {
    EventMsg msg;
    GuiWidget_onSleep(o);
    o->pending = 0;
    cStopSoundMsg_ctor_cSndFxR_bool(&msg, o->target, 0);
    msg.immediate = 1;
    QueueMessage_cMessageR_cSystemP_int(&msg, &g_Game, 1);
    msg.vtable = &D_004DADF0;
    cFileMan_dtor(msg.partB, -1);
    cFileMan_dtor(msg.partA, -1);
    cMessage_dtor(&msg, 0);
    cFileStreamMan_Purge(GetFileStreamMan());
    cMemMan_ReleaseBin(1);
}
#undef g_Game /* merge_units */
#undef D_004DADF0 /* merge_units */
#undef cStopSoundMsg_ctor_cSndFxR_bool /* merge_units */
#undef QueueMessage_cMessageR_cSystemP_int /* merge_units */
#undef cFileMan_dtor /* merge_units */
#undef cMessage_dtor /* merge_units */
static inline void merge_flush_func_003556F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003556F0 */
