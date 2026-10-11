#include "types.h"
typedef struct { int pad[3]; int key; } Tgt_B7A0;
typedef struct { char pad[0x40]; Tgt_B7A0* node; int key; } Ai_B7A0;
typedef struct { char pad[0x1AC]; Ai_B7A0* ai; } NPC_B7A0;
Tgt_B7A0* cNPC_v2C(NPC_B7A0* self)
{
    Ai_B7A0* o = self->ai;
    Tgt_B7A0* n = o->node;
    unsigned char ok = 1;
    int z = (n != 0) ^ 1;
    if (!z && n->key != o->key) ok = 0;
    return ok ? n : 0;
}