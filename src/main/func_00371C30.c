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
void LightMgr_Register(LightMgr* mgr, int key, int id, int val)
{
    LmGroup* g = 0;
    int i;
    int free;
    int j;
    for (i = 0; i < mgr->numGroups; i++) {
        if (key == mgr->groups[i].key) {
            g = &mgr->groups[i];
            break;
        }
    }
    free = -1;
    if (!g) return;
    for (j = 0; j < 16; j++) {
        if (g->slots[j].id == id) return;
        if (g->slots[j].id == 0) {
            free = j;
            break;
        }
    }
    if (free >= 0) {
        g->slots[free].id = id;
        g->slots[free].val = val;
        g->count++;
    }
}