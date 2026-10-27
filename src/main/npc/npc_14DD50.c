/*
 * main/npc: range (2 files, 0014DD50-0014DE30)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_0014DD50 */
#pragma push /* merge_units */
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
extern void cNPC_NewLookAtList(Npc_14DD50* n, int a, int b, int c);
extern void cNPC_AddLinkedNodesToLookAt(Npc_14DD50* n, int a, int b, int c, float f);

void cNPC_LookAround(Npc_14DD50* n, int a)
{
    NpcSt_14DD50* st = n->st;
    int id;
    int ok = st->b2D && st->b2C && !st->b2E;
    if (ok) {
        id = -1;
        cNPC_NewLookAtList(n, 0, 1, a);
        if (n->b13C == 1)
            id = n->ai->x54;
        if (n->ai->x4C >= 0)
            cNPC_AddLinkedNodesToLookAt(n, -1, n->ai->x4C, id, 1.0f);
        else
            cNPC_AddLinkedNodesToLookAt(n, n->ai->x5C, -1, id, 1.0f);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014DD50(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014DD50 */

/* merge_units: begin func_0014DE30 */
#pragma push /* merge_units */
typedef struct { int time; unsigned char active; char pad[0x14 - 5]; } E_DE30;
typedef struct { char pad[0x178]; E_DE30 e[3]; } S_DE30;
void cNPC_ResumeAILookAt(S_DE30* self, int t)
{
    int i = 0;
    S_DE30* p = self;
    do {
        if (p->e[0].active && p->e[0].time == t) {
            unsigned char k = i;
            E_DE30* e = &self->e[k]; S_DE30* q = (S_DE30*)((char*)self + k * 0x14); if (t >= q->e[0].time) { q->e[0].active = 0; e->time = 0;
            }
        }
        i++;
        p = (S_DE30*)((char*)p + 0x14);
    } while (i < 3);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014DE30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014DE30 */
