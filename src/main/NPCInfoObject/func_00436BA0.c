#include "types.h"

extern int D_00582A68;
extern void operator_delete(void* allocation);

/* Release a shared NPC node and optionally destroy it. */
int* func_00436BA0(int* node, short deleteFlag)
{
    if (node) {
        D_00582A68--;
        if (deleteFlag > 0)
            operator_delete(node);
    }
    return node;
}
