/*
 * main/gameSound: range (2 files, 001C7180-001C71C0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "scriptUtils_types.h"
#include "gameSound_types.h"

/* merge_units: begin func_001C7180 */
#pragma push /* merge_units */
extern void Voice_PlayQuip(int speaker, int quip, int flags);

/* Script native: PlayQuip(speaker, quip).
 * volatile mirrors the original stack temporaries. */
int Script_PlayQuip(ScriptArg* args) {
    volatile int quipSlot;
    volatile int speakerSlot;
    int speaker;
    int quip;

    quipSlot = args[1].i;
    speaker = args[0].i;
    quip = quipSlot;
    speakerSlot = speaker;
    Voice_PlayQuip(speakerSlot, quip, 0);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C7180(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C7180 */

/* merge_units: begin func_001C71C0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Music and sound-effect script natives. The first sound argument is a
 * signed byte (group) whose meaning is not known yet.
 */


extern int cGOBJ_SOBJ_convert(int handle);
extern int nGameSound_PlayMusic(int music, int object);
extern int Global_PlaySnd(int group, int sound);
extern int Global_PlaySnd_2(int group, int sound, int object);
extern int nGameSound_StopMusic(int music, int object);
extern int nGameSound_StopSnd_eSndBank_charP(int group, int sound);
extern int nGameSound_StopSnd_eSndBank_charP_cGOBJP(int group, int sound, int object);

/* StopMusic(music, object) */
int Script_StopMusic(SoundScriptArg* args) {
    volatile int arg = args[0].i; /* original stack temporary */
    int music = arg;
    nGameSound_StopMusic(music, cGOBJ_SOBJ_convert(args[1].i));
    return 0;
}

/* PlayMusic(music, object) */
int Script_PlayMusic(SoundScriptArg* args) {
    volatile int arg = args[0].i; /* original stack temporary */
    int music = arg;
    nGameSound_PlayMusic(music, cGOBJ_SOBJ_convert(args[1].i));
    return 0;
}

/* StopSnd(group, sound, object) */
int Script_StopSnd(SoundScriptArg* args) {
    volatile int arg = args[1].i; /* original stack temporary */
    int group = args[0].s8;
    int sound = arg;
    nGameSound_StopSnd_eSndBank_charP_cGOBJP(group, sound, cGOBJ_SOBJ_convert(args[2].i));
    return 0;
}

/* PlaySnd(group, sound, object) */
int Script_PlaySnd(SoundScriptArg* args) {
    volatile int arg = args[1].i; /* original stack temporary */
    int group = args[0].s8;
    int sound = arg;
    Global_PlaySnd_2(group, sound, cGOBJ_SOBJ_convert(args[2].i));
    return 0;
}

/* StopSnd(group, sound) without an object */
int Script_StopSnd_2(SoundScriptArg* args) {
    volatile int sound = args[1].i; /* original stack temporary */
    nGameSound_StopSnd_eSndBank_charP(args[0].s8, sound);
    return 0;
}

/* PlaySnd(group, sound) without an object */
int Script_PlaySnd_2(SoundScriptArg* args) {
    volatile int sound = args[1].i; /* original stack temporary */
    Global_PlaySnd(args[0].s8, sound);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C71C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C71C0 */
