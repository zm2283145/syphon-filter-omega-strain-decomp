/*
 * Matched functions (byte-identical with the retail executable).
 * Player component (cPlayer): script natives, type registration and setup.
 */

#include "types.h"
#include "player_types.h"

extern int cPlayer_RemoveWeapon(PlayerComponent* self, int weapon);

int Script_cPlayer_RemoveWeapon(PlayerScriptArg* args) {
    int spill[1]; /* original stack temporary; the cast form keeps it in memory */
    int weapon;
    PlayerComponent* self;

    *(int*)(char*)spill = args[1].i;
    weapon = *(int*)(char*)spill;
    self = (PlayerComponent*)args[0].p;
    cPlayer_RemoveWeapon(self, weapon);
    return 0;
}
