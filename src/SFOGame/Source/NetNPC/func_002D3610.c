#include "types.h"

/* Looks up the table entry for index +0x208 (0 when negative). */
typedef struct { char pad00[8]; int *entries; } Table_002D3610;
extern Table_002D3610 *D_004FFBE0;
typedef struct { char pad00[0x208]; int index; } Obj_002D3610;
int cNetNPC_GetCurrentNode(Obj_002D3610 *obj) {
    int result = 0;
    int index = obj->index;
    if (index >= 0) result = D_004FFBE0->entries[index];
    return result;
}
