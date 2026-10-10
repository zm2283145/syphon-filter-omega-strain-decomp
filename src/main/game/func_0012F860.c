#include "types.h"
#include "scriptUtils_types.h"

extern void Global_StartGlobalTimer(int unused, float time);

/* Script native: StartGlobalTimer(time = args[0]).
 * volatile mirrors the original stack temporary. */
int Script_StartGlobalTimer(ScriptArg* args) {
    volatile int bits = args[0].i;
    Global_StartGlobalTimer(0, *(float*)&bits);
    return 0;
}
