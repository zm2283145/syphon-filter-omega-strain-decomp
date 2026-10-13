#include "types.h"

extern void snd_ContinueAllSoundsInGroup(int);
extern void snd_PauseAllSoundsInGroup(int);

void func_001C96D0(int a0, int a1) {
    int cond;

    cond = a1 == 0;
    if (cond) goto L001C96F0;
    a0 = 0 + -1;
    snd_PauseAllSoundsInGroup(a0);
    goto L001C96F8;
L001C96F0:;
    a0 = 0 + -1;
    snd_ContinueAllSoundsInGroup(a0);
L001C96F8:;
    goto ret;
ret:;
}
