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

extern char D_004FFB50[];
extern char D_004DADF0[];
extern char D_004DAE10[];
extern char D_004BB0E0[];
extern char D_004BB0F0[];
extern Cfg_355490* D_004FFC04;
extern void SoundEvent_Ctor(SoundEventMsg_355490* msg, void* action, int flags);
extern void Event_Send(void* msg, void* target, int flags);
extern void FileMan_Release(void* part, int flags);
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
    FileMan_Release(stop.partB, -1);
    FileMan_Release(stop.partA, -1);
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
    FileMan_Release(play.partB, -1);
    FileMan_Release(play.partA, -1);
    cMessage_dtor(&play, 0);
}

void func_00355300(Self_355490* self, char* voice)
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
