#include "types.h"
typedef struct { char pad[0x60]; unsigned char b0:3; unsigned char b3:1; unsigned char b4:4; } Info14D470;
typedef struct { char pad0[0x7C]; int x7C; char pad80[0x20]; int xA0; char padA4[0x98]; unsigned char x13C; char pad13D[0x73]; Info14D470* x1B0; } NPC14D470;
extern void func_0014D510(NPC14D470*, int, int);
void cNPC_v54(NPC14D470* n) {
    if (!n->x1B0->b3) {
        n->xA0 = 0;
        if (!n->x13C) func_0014D510(n, 2, 0);
        n->x7C = 0;
    }
}