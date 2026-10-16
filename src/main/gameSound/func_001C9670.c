/*
 * Matched functions (byte-identical with the retail executable).
 * Thin wrappers around the low-level sound library.
 */

#include "types.h"
#include "gameSound_types.h"

extern void func_003A7310(void);
extern void func_003A7FE0(void);
extern void func_003A80F0(int a0);
extern int snd_FlushSoundCommands(void);

void SoundMgr_SetOutputMode(int unused, int a1) {
    func_003A80F0(a1);
}

/* Calls two library routines, then polls snd_FlushSoundCommands until it returns 0. */
void func_001C9680(void) {
    func_003A7FE0();
    func_003A7310();
    while (snd_FlushSoundCommands() != 0) {
    }
}
