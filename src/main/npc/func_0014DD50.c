typedef struct { char pad[0x2C]; unsigned char b2C; unsigned char b2D; unsigned char b2E; } NpcSt_14DD50;
typedef struct { char pad[0x4C]; int x4C; char pad50[4]; int x54; char pad58[4]; int x5C; } NpcAi_14DD50;
typedef struct {
    char pad0[0x30];
    NpcSt_14DD50* st;
    char pad34[0x13C - 0x34];
    unsigned char b13C;
    char pad13D[0x1B0 - 0x13D];
    NpcAi_14DD50* ai;
} Npc_14DD50;
extern void NpcLook_Begin(Npc_14DD50* n, int a, int b, int c);
extern void NpcLook_AddNodePoints(Npc_14DD50* n, int a, int b, int c, float f);

void cNPC_v4B(Npc_14DD50* n, int a)
{
    NpcSt_14DD50* st = n->st;
    int id;
    int ok = st->b2D && st->b2C && !st->b2E;
    if (ok) {
        id = -1;
        NpcLook_Begin(n, 0, 1, a);
        if (n->b13C == 1)
            id = n->ai->x54;
        if (n->ai->x4C >= 0)
            NpcLook_AddNodePoints(n, -1, n->ai->x4C, id, 1.0f);
        else
            NpcLook_AddNodePoints(n, n->ai->x5C, -1, id, 1.0f);
    }
}


