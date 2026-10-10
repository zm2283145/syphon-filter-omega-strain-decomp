#include "GobjMan_types.h"

extern GobjEntry* D_00571770;
extern GobjId D_00571774;

/* Publish the local player and retain its ID for subsequent validity checks. */
void func_0040BED0(GobjEntry* player)
{
    GobjId missing;
    const GobjId* id;
    D_00571770 = player;
    if (player)
        id = &player->id;
    else {
        missing.word = -1;
        id = &missing;
    }
    D_00571774.word = id->word;
}
