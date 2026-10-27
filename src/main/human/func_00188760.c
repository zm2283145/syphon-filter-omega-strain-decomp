#include "types.h"

extern int WoundEffectTable[];

/* Return entry `index` of a global int table. */
int cMan_GetBloodEffect(int index)
{
    return WoundEffectTable[index];
}
