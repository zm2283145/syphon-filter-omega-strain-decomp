#include "NetObjectMgr_types.h"

extern volatile unsigned char D_005723C8;
extern void* D_00583870;
extern int D_00582CF0;
extern int func_002EB650(NetSessionEntry** result, void* key);

/* Cache the selected session entry's value when lookup succeeds. */
void func_00437830(void* unused, void* key)
{
    NetSessionEntry* result[2];
    if (!D_005723C8)
        D_005723C8 = 1;
    if (!func_002EB650(result, key)) {
        int value = result[0]->value;
        D_00583870 = key;
        D_00582CF0 = value;
    }
    D_005723C8 = 0;
}
