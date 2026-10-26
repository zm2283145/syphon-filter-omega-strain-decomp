#include "types.h"

/* Returns whether the first word of the object is zero. */
int cLList_cEnvSettingsPtr_Empty(int* self)
{
    return self[0] == 0;
}
