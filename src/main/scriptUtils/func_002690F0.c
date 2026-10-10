#include "types.h"
#include "scriptUtils_types.h"

extern int Global_RoundToInt(float value);

/* Script native: RoundToInt(value = args[0]).
 * volatile mirrors the original stack temporaries. */
int Script_RoundToInt(ScriptArg* args) {
    volatile int result;
    volatile int bits = args[0].i;
    result = Global_RoundToInt(*(float*)&bits);
    return result;
}
