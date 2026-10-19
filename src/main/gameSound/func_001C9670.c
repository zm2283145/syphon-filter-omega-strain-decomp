/*
 * Matched functions (byte-identical with the retail executable).
 * Thin wrappers around the low-level sound library.
 */

#include "types.h"
#include "gameSound_types.h"

extern void snd_FreeVAGStreamChannels(void);
extern void snd_StopAllSounds(void);
extern void snd_SetPlaybackMode(int a0);
extern int snd_FlushSoundCommands(void);

void SoundMgr_SetOutputMode(int unused, int a1) {
    snd_SetPlaybackMode(a1);
}

/* Calls two library routines, then polls snd_FlushSoundCommands until it returns 0. */
void Snd_StopAndFlushAll(void) {
    snd_StopAllSounds();
    snd_FreeVAGStreamChannels();
    while (snd_FlushSoundCommands() != 0) {
    }
}
