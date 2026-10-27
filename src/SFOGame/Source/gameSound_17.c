/*
 * SFOGame/Source/gameSound: 5 files, 001C9430-001C9670
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001C9430 */
#pragma push /* merge_units */
#include "types.h"

typedef struct { int type; char pad[0x3C]; int owner; unsigned char state; } S1C9430;
static inline unsigned char S1C9430_busy(S1C9430* p)
{
    unsigned char r = 1;
    if (p->state != 1 && p->state != 3) r = 0;
    return r;
}
static inline void S1C9430_release(S1C9430* p)
{
    if (p->type == 5 && S1C9430_busy(p)) p->state = 2;
    else p->state = 0;
}
void SoundMgr_OnStreamReply(int owner, long long pp)
{
    S1C9430* p = (S1C9430*)(int)pp;
    if (owner == 0) { S1C9430_release(p); return; }
        if (S1C9430_busy(p)) p->state = 6;
        p->owner = owner;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C9430(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C9430 */

/* merge_units: begin func_001C94D0 */
#pragma push /* merge_units */
extern int snd_GetMasterVolume(int);
int func_001C94D0(void* self, unsigned char kind)
{
    int r = 0;
    switch (kind) {
    case 0: r = snd_GetMasterVolume(0); break;
    case 1: r = snd_GetMasterVolume(1); break;
    case 2: r = snd_GetMasterVolume(2); break;
    }
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C94D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C94D0 */

/* merge_units: begin func_001C9540 */
#pragma push /* merge_units */
extern void snd_SetMasterVolume(int, int);
void cGameSound_SetMasterVolume(void* self, unsigned char kind, int v)
{
    switch (kind) {
    case 0: snd_SetMasterVolume(0, v); snd_SetMasterVolume(3, v); break;
    case 1: snd_SetMasterVolume(1, v); break;
    case 2: snd_SetMasterVolume(2, v); snd_SetMasterVolume(14, v); break;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C9540(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C9540 */

/* merge_units: begin func_001C95D0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct E1C95D0 { int type; char pad4[0xC]; char name[0x34]; unsigned char active; char pad45[0x1B0 - 0x45]; };
struct S1C95D0 { char pad[0x50]; E1C95D0 slots[50]; };
extern "C" int String_CompareNoCase(const char* a, const char* b);
static inline bool B1C95D0_eq(unsigned char a, int b) { return a == b; }
extern "C" bool cGameSound_IsVAGPlaying(S1C95D0* s, const char* name)
{
    int i;
    for (i = 0; i < 50; i++) {
        E1C95D0* e = &s->slots[i];
        if (e->type == 4 && String_CompareNoCase(e->name, name) == 0)
            return !B1C95D0_eq(e->active, 0);
    }
    return false;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C95D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C95D0 */

/* merge_units: begin func_001C9670 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Thin wrappers around the low-level sound library.
 */

#include "gameSound_types.h"

extern void snd_StopAllStreams(void);
extern void snd_StopAllSounds(void);
extern void snd_SetPlaybackMode(int a0);
extern int snd_FlushSoundCommands(void);

void cGameSound_SetPlaybackMode(int unused, int a1) {
    snd_SetPlaybackMode(a1);
}

/* Calls two library routines, then polls snd_FlushSoundCommands until it returns 0. */
void cGameSound_StopAllSounds(void) {
    snd_StopAllSounds();
    snd_StopAllStreams();
    while (snd_FlushSoundCommands() != 0) {
    }
}
static inline void merge_flush_func_001C9670(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001C9670 */
