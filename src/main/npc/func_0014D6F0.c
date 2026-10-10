#include "types.h"

typedef struct {
    char pad[0x60];
    float value;
    int level;
    char pad2[0x141 - 0x68];
    unsigned char flag0 : 1;
    unsigned char flag1 : 1;
    unsigned char flag2 : 1;
    unsigned char flag3 : 1;
    unsigned char flag4 : 1;
    unsigned char flag5 : 1;
    unsigned char flag6 : 1;
    unsigned char flag7 : 1;
} cNPC;

/* cNPC virtual slot 0x4E: when level <= 100, stores v, sets level to 100 and clears flag bit 6 at +0x141. */
void cNPC_v4E(cNPC* npc, float v)
{
    if (npc->level <= 100) {
        npc->value = v;
        npc->level = 100;
        npc->flag6 = 0;
    }
}
