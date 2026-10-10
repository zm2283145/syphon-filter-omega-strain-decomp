#include "loose05_types.h"

/* Store an ordered range with a nonnegative lower bound. */
void func_00450590(SFOLobby* lobby, int start, int end)
{
    if (start < 0)
        start = 0;
    if (end < start)
        end = start;
    lobby->rangeStart = start;
    lobby->rangeEnd = end;
}
