#include "types.h"
typedef struct { void* obj; int arg; } E2Slot;
typedef struct {
    char pad0[0x1C];
    unsigned char dirty;
    char pad1[0x58 - 0x1D];
    unsigned char active;
    char pad2[3];
    int count;
    E2Slot slots[16];
} E2Group;
extern void cVU1Model_UpdateLighting(void*, int, int);
extern unsigned char g_LevelLightsDirty;
void cSceneLight_Deactivate(E2Group* g) {
    int i;
    if (g->active && g->count) {
        for (i = 0; i < 16; i++) {
            E2Slot* s = &g->slots[i];
            if (s->obj) cVU1Model_UpdateLighting(s->obj, s->arg, 0);
        }
        g->active = 0;
    }
    if (g->dirty) {
        g->dirty = 0;
        g_LevelLightsDirty = 1;
    }
}