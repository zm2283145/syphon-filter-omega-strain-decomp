#include "types.h"
#include "npc_auth.h"
typedef struct { char pad[0x30]; void* net; char pad2[0xE4]; int i118; char pad3[0x22]; unsigned char b13E; } Npc34C0;
void func_002D34C0(Npc34C0* o)
{
    if (NpcAuth_IsLocal()) {
        o->b13E = 1;
        o->i118 = 0;
    }
    NetEvent_Send(o->net, 0xD, 8, 0, 0, 0, 0);
}