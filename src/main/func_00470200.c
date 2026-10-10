#include "types.h"
#include "scriptUtils_types.h"

extern void Global_cInventory__RegisterItem(int item, int count);

/* Script native: cInventory::RegisterItem(item, count). */
int Script_cInventory__RegisterItem(ScriptArg* args) {
    volatile int count = args[1].i;
    volatile int item = args[0].i;
    Global_cInventory__RegisterItem(item, count);
    return 0;
}
