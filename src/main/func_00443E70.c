#include "types.h"

extern int cTimer_GetMillisecondTime(void);

/* Calls cTimer_GetMillisecondTime and returns its result. */
long long SFOLobby_GetMillisecs(void)
{
    return cTimer_GetMillisecondTime();
}
