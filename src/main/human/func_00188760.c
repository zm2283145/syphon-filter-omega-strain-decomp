#include "types.h"

extern int WoundEffectTable[];

/* Return entry `index` of a global int table. */
int WoundEffectIds_At(int index)
{
    return WoundEffectTable[index];
}
