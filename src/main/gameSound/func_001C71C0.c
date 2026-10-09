/*
 * Matched functions (byte-identical with the retail executable).
 * Music and sound-effect script natives. The first sound argument is a
 * signed byte (group) whose meaning is not known yet.
 */

#include "types.h"
#include "gameSound_types.h"

extern int GObj_IdentityB(int handle);
extern int Global_PlayMusic(int music, int object);
extern int Global_PlaySnd(int group, int sound);
extern int Global_PlaySnd_2(int group, int sound, int object);
extern int Global_StopMusic(int music, int object);
extern int Global_StopSnd(int group, int sound);
extern int Sound_StopForObject(int group, int sound, int object);

/* StopMusic(music, object) */
int Script_StopMusic(SoundScriptArg* args) {
    volatile int arg = args[0].i; /* original stack temporary */
    int music = arg;
    Global_StopMusic(music, GObj_IdentityB(args[1].i));
    return 0;
}

/* PlayMusic(music, object) */
int Script_PlayMusic(SoundScriptArg* args) {
    volatile int arg = args[0].i; /* original stack temporary */
    int music = arg;
    Global_PlayMusic(music, GObj_IdentityB(args[1].i));
    return 0;
}

/* StopSnd(group, sound, object) */
int Script_StopSnd(SoundScriptArg* args) {
    volatile int arg = args[1].i; /* original stack temporary */
    int group = args[0].s8;
    int sound = arg;
    Sound_StopForObject(group, sound, GObj_IdentityB(args[2].i));
    return 0;
}

/* PlaySnd(group, sound, object) */
int Script_PlaySnd(SoundScriptArg* args) {
    volatile int arg = args[1].i; /* original stack temporary */
    int group = args[0].s8;
    int sound = arg;
    Global_PlaySnd_2(group, sound, GObj_IdentityB(args[2].i));
    return 0;
}

/* StopSnd(group, sound) without an object */
int Script_StopSnd_2(SoundScriptArg* args) {
    volatile int sound = args[1].i; /* original stack temporary */
    Global_StopSnd(args[0].s8, sound);
    return 0;
}

/* PlaySnd(group, sound) without an object */
int Script_PlaySnd_2(SoundScriptArg* args) {
    volatile int sound = args[1].i; /* original stack temporary */
    Global_PlaySnd(args[0].s8, sound);
    return 0;
}
