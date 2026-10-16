#include "types.h"

extern int Time_GetMilliseconds(void);

/* Calls Time_GetMilliseconds and returns its result. */
long long Lobby_GetTime(void)
{
    return Time_GetMilliseconds();
}
