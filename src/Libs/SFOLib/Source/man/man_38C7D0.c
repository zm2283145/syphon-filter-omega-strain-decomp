/*
 * main/man: range (2 files, 0038C7D0-0038C820)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_0038C7D0 */
#pragma push /* merge_units */
typedef struct { char pad[0x40C]; unsigned char type; } EquipItem;
typedef struct { char pad[0x2410]; EquipItem* slots[8]; } EquipState;
extern void cMan_UpdateHandMorphs(EquipState* e, int slot, EquipItem* it);
void cMan_AddGun(EquipState* e, int slot, EquipItem* it) {
    if (it) {
        int t = it->type;
        if (t < 0 || t >= 8) return;
    }
    e->slots[slot] = it;
    cMan_UpdateHandMorphs(e, slot, it);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0038C7D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0038C7D0 */

/* merge_units: begin func_0038C820 */
#pragma push /* merge_units */
#pragma cplusplus on

struct Pair38C820 {
    __int128 a;
    __int128 b;
};

struct Self38C820 {
    char pad[0x80];
    Pair38C820 pairs[(0x2340 - 0x80) / 0x20];
    void* x2340[0x20];
    unsigned short x23C0;
};

extern "C" {
extern char g_AgentPartCache[];
int FindTex__7MonsterF1(char* cache, __int128 name);
void Monster_FreeTexture(char* cache, int slot);
int FindPart__7MonsterF1(char* cache, __int128 name);
void Monster_FreePart(char* cache, int slot);
void DELAY_DELETE_ARRAY(void* p);
}

extern "C" void cMan_FreeMan(Self38C820* self)
{
    int i;
    for (i = 0; i < self->x23C0; i++) {
        int s = FindPart__7MonsterF1(g_AgentPartCache, self->pairs[i].a);
        if (s != -1) {
            Monster_FreePart(g_AgentPartCache, s);
        }
        if (self->x2340[i]) {
            DELAY_DELETE_ARRAY(self->x2340[i]);
            self->x2340[i] = 0;
        }
    }
    for (i = 0; i < self->x23C0; i++) {
        int s = FindTex__7MonsterF1(g_AgentPartCache, self->pairs[i].b);
        if (s != -1) {
            Monster_FreeTexture(g_AgentPartCache, s);
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0038C820(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0038C820 */
