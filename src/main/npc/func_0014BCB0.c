#include "types.h"
typedef struct { int a0; int a4; int id; int ac; } Slot_BCB0;
typedef struct { Slot_BCB0 s[8]; char pad[4]; unsigned char cur; } Inv_BCB0;
typedef struct { char pad[0x3524]; Inv_BCB0* inv; } Ctl_BCB0;
typedef struct { char pad[0x30]; Ctl_BCB0* ctl; } NPC_BCB0;
int cNPC_GetActiveWeapon(NPC_BCB0* self) { Inv_BCB0* inv = self->ctl->inv; if (inv->cur != 6) return inv->s[inv->cur].id; return -1; }