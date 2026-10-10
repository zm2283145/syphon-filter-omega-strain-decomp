#include "types.h"
#include "scriptUtils_types.h"

extern void Global_StartGlobalTimer(int timer, float time);

/* Script native: StartGlobalTimer(time = args[0], timer = args[1]).
 * volatile mirrors the original stack temporaries. */
int Script_StartGlobalTimer_2(ScriptArg* args) {
    volatile int timerSlot;
    volatile int timeSlot;
    int bits;
    int timer;

    timerSlot = args[1].i;
    bits = args[0].i;
    timer = timerSlot;
    timeSlot = bits;
    Global_StartGlobalTimer(timer, *(float*)&timeSlot);
    return 0;
}
