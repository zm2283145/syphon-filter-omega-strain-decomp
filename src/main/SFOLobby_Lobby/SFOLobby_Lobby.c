/*
 * main/SFOLobby_Lobby: 2 files, 00450590-004505C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00450590 */
#pragma push /* merge_units */
#include "SFOLobby.h"
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
#pragma pop /* merge_units */
/* merge_units: end func_00450590 */

/* merge_units: begin func_004505C0 */
#pragma push /* merge_units */
extern SFOLobby* D_00585E60;
/* True when no lobby instance exists; every reply callback checks this first. */
int SFOLobby_NoInstance(void)
{
    return D_00585E60 == 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_004505C0 */
