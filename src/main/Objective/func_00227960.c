#include "types.h"
#include "scriptUtils_types.h"

extern void Global_SetObjectiveCurrColor(int obj, int a, int b, float c);

/* Script native: SetObjectiveCurrColor(obj, a, b, c).
 * volatile mirrors the original stack temporaries. */
int Script_SetObjectiveCurrColor(ScriptArg* args) {
    volatile int slot3;
    volatile int slot2;
    volatile int slot1;
    volatile int slot0;
    int v1;
    int v2;
    int v0;

    slot3 = args[3].i;
    slot2 = args[2].i;
    v1 = args[1].i;
    v2 = slot2;
    slot1 = v1;
    v0 = args[0].i;
    v1 = slot1;
    slot0 = v0;
    Global_SetObjectiveCurrColor(slot0, v1, v2, *(float*)&slot3);
    return 0;
}
