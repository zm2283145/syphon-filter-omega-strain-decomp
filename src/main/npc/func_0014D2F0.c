#include "types.h"

typedef struct {
    char pad[0x20];
    unsigned char lo : 4;
    unsigned char flag : 1;
} NPCInfo;
typedef struct { char pad[0x1AC]; NPCInfo* info; } NPC;

/* Returns bit 4 of the NPC info flags byte. */
int cNPC_v29(NPC* self)
{
    return self->info->flag;
}
