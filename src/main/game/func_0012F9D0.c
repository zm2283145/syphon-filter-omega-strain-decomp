#include "types.h"
#include "scriptUtils_types.h"

extern void Global_SetScrollDelay(float delay);

/* Script native: SetScrollDelay(delay = args[0]).
 * volatile mirrors the original stack temporary. */
int Script_SetScrollDelay(ScriptArg* args) {
    volatile int bits = args[0].i;
    Global_SetScrollDelay(*(float*)&bits);
    return 0;
}
