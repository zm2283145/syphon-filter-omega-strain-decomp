#include "types.h"
typedef struct { int id; int val; } LmSlot;
typedef struct {
    char pad0[8];
    int key;
    char padc[0x5C - 0xC];
    int count;
    LmSlot slots[16];
    char pade0[0xE0 - 0xE0];
} LmGroup;
typedef struct { char pad0[0xC]; LmGroup* groups; char pad10[0xC]; int numGroups; } LightMgr;
void cLightMan_RemoveSceneLightRef(LightMgr* mgr, int key, int id)
{
    LmGroup* g = 0;
    int i;
    int j;
    for (i = 0; i < mgr->numGroups; i++) {
        if (key == mgr->groups[i].key) {
            g = &mgr->groups[i];
            break;
        }
    }
    if (!g) return;
    for (j = 0; j < 16; j++) {
        if (g->slots[j].id == id) {
            /* unsigned index keeps the stores out of strength reduction */
            g->slots[(unsigned)j].id = 0;
            g->slots[(unsigned)j].val = -1;
            g->count--;
        }
    }
}
