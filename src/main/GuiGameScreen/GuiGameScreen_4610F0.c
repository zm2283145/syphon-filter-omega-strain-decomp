/*
 * main/GuiGameScreen: 2 files, 004610F0-00461220
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_004610F0 */
#pragma push /* merge_units */
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
extern char g_Game[];
extern char D_004DADF0[];
extern char D_004DAE10[];
extern void cStopSoundMsg_ctor_cSndFxR_bool(SoundEventMsg_4610F0* msg, void* action, int flags);
extern void QueueMessage_cMessageR_cSystemP_int(void* msg, void* target, int flags);
extern void cFileMan_dtor(void* part, int flags);
extern void cMessage_dtor(void* msg, int flags);
extern void cSndFx_SetSndFx(void* action, int kind, char* voice, int a, int b);
extern void SoundMsg_WrapAction(SoundMsg_4610F0* msg, void* action);
}

static inline void StopVoice_4610F0(Self_4610F0* self)
{
    SoundEventMsg_4610F0 stop;
    self->playing = 0;
    cStopSoundMsg_ctor_cSndFxR_bool(&stop, self->action, 0);
    stop.flag = 1;
    QueueMessage_cMessageR_cSystemP_int(&stop, g_Game, 1);
    stop.vtbl = D_004DADF0;
    cFileMan_dtor(stop.partB, -1);
    cFileMan_dtor(stop.partA, -1);
    cMessage_dtor(&stop, 0);
}

static inline void PlayVoice_4610F0(Self_4610F0* self, char* voice)
{
    SoundMsg_4610F0 play;
    StopVoice_4610F0(self);
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

extern "C" void cQuipList_NextQuip(Self_4610F0* self)
{
    if (self->cur < self->count) {
        Line_4610F0* line = &self->lines[self->cur++];
        PlayVoice_4610F0(self, line->voice);
        self->duration = line->duration;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_004610F0 */

/* merge_units: begin func_00461220 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies after GuiGameScreen.cc (ends 0x0045F090).
 */

#include "loose05_types.h"

extern char D_004F2CC0[];

/* Address of 12-byte element `i`. */
char* cArray_tQuip_opIndex(Vec12* v, int i) {
    return v->data + i * 12;
}

int func_00461240(Vec12* v) {
    return v->count;
}

char* func_00461250(void) {
    return D_004F2CC0;
}

char* GuiEndGameAwards_GetClassName(void) {
    return "GuiEndGameAwards";
}
#pragma pop /* merge_units */
/* merge_units: end func_00461220 */
