/*
 * main/human: range (2 files, 001B3960-001B3A60)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "vslot_pad.h"

/* merge_units: begin func_001B3960 */
#pragma push /* merge_units */
#pragma cplusplus on
struct P_1B3960 { char pad[0xC]; int h; };
class O_1B3960 { public: VPAD16(a) VPAD4(b) VPAD2(c) virtual void Kill(int f); char pad4[0x54]; void* npc; };
extern "C" {
extern unsigned char D_005721C8;
extern unsigned char D_005721C0;
P_1B3960* PlayerSlots_Get(int i);
int Player_GetIndex(int h);
void cNPC_Deactivate(void* npc, P_1B3960* p);
}
static inline int Net_1B3960(void) { return D_005721C8 ? D_005721C0 : 1; }
static inline void Deact_1B3960(void* npc, P_1B3960* f) { if (f && Net_1B3960()) cNPC_Deactivate(npc, f); }
extern "C" void func_001B3960(O_1B3960* self, int id)
{
    P_1B3960* found = 0;
    if (id >= 0) {
        if (Net_1B3960()) {
            int i;
            for (i = 0; i < 4; i++) {
                P_1B3960* p = PlayerSlots_Get(i);
                if (p && Player_GetIndex(p->h) == id) { found = p; break; }
            }
        }
        Deact_1B3960(self->npc, found);
    } else {
        self->Kill(1);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001B3960(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001B3960 */

/* merge_units: begin func_001B3A60 */
#pragma push /* merge_units */
#pragma cplusplus on
struct P_1B3A60 { char pad[0xC]; int h; };
class T_1B3A60 { public: VPAD16(a) VPAD4(b) VPAD2(c) VPAD1(d) virtual void Set(int v); };
struct N_1B3A60 { char pad[0x30]; T_1B3A60* t; };
struct O_1B3A60 { char pad[0x58]; N_1B3A60* npc; };
extern "C" {
#if 0 /* merge_units */
P_1B3A60* PlayerSlots_Get(int i);
#endif /* merge_units */
#define PlayerSlots_Get(a0) ((P_1B3A60 *)PlayerSlots_Get((a0))) /* merge_units */

void NpcAi_ActivateForPlayer(N_1B3A60* npc, P_1B3A60* p);
}
static inline int Net_1B3A60(void) { return D_005721C8 ? D_005721C0 : 1; }
static inline void Act_1B3A60(N_1B3A60* npc, P_1B3A60* f) { if (f && Net_1B3A60()) NpcAi_ActivateForPlayer(npc, f); }
extern "C" void func_001B3A60(O_1B3A60* self, int id)
{
    P_1B3A60* found = 0;
    if (id >= 0 && Net_1B3A60()) {
        int i;
        for (i = 0; i < 4; i++) {
            P_1B3A60* p = PlayerSlots_Get(i);
            if (p && Player_GetIndex(p->h) == id) { found = p; break; }
        }
    }
    self->npc->t->Set(-1);
    Act_1B3A60(self->npc, found);
}
#undef PlayerSlots_Get /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001B3A60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001B3A60 */
