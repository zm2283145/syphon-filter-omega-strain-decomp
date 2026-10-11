#include "types.h"
typedef struct { char pad[0xB0]; int w0; int w1; } NPC_B770;
int cNPC_GetWeapon(NPC_B770* self, int which) { if ((unsigned char)which == 0) return self->w0; else return self->w1; }