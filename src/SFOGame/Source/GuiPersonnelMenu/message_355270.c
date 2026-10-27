/*
 * main/message: 3 files, 00355270-00355400
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
extern void cFileMan_dtor(void* part, int flags);
extern void cMessage_dtor(void* msg, int flags);
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
#pragma pop /* merge_units */
/* merge_units: end func_00355300 */

/* merge_units: begin func_00355400 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Message destructor: payload members, then cMessage base. */
DEFINE_MESSAGE_TWO_MEMBER_DTOR(func_00355400, D_004DAE10)
#pragma pop /* merge_units */
/* merge_units: end func_00355400 */
