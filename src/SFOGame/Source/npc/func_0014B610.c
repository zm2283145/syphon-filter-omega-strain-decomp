#include "types.h"
typedef struct { char pad[0x2C]; unsigned char x2C; unsigned char x2D; unsigned char x2E; char pad2[0x3468 - 0x2F]; unsigned char x3468; } Ctl_B610;
typedef struct {
    char pad[0x30]; Ctl_B610* ctl;
    char pad2[0x141 - 0x34];
    unsigned char b0 : 1; unsigned char b1 : 1; unsigned char b2 : 1; unsigned char b3 : 5;
} NPC_B610;
unsigned char Npc_IsCorpseRemovable(NPC_B610* self)
{
    unsigned char r = self->b2;
    Ctl_B610* c = self->ctl;
    if (c) {
        int v = c->x2D && c->x2C && !c->x2E && c->x3468;
        if (v)
            r = 0;
    }
    return r;
}