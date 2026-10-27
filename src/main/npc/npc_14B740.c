/*
 * main/npc: range (3 files, 0014B740-0014B790)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_0014B740 */
#pragma push /* merge_units */
void cNPC_SetWeaponPreference(int a0, int a1, int a2) {
    int v1;
    int cond;

    v1 = a2 & 255;
    cond = v1 != 0;
    if (cond) goto L0014B758;
    *(int*)((char*)a0 + 176) = a1;
    goto L0014B760;
L0014B758:;
    *(int*)((char*)a0 + 180) = a1;
L0014B760:;
    goto ret;
ret:;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014B740(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014B740 */

/* merge_units: begin func_0014B770 */
#pragma push /* merge_units */
typedef struct { char pad[0xB0]; int w0; int w1; } NPC_B770;
int cNPC_GetWeapon(NPC_B770* self, int which) { if ((unsigned char)which == 0) return self->w0; else return self->w1; }
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014B770(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014B770 */

/* merge_units: begin func_0014B790 */
#pragma push /* merge_units */
typedef struct { char pad[0xC]; int seed; char pad2[0x3524 - 0x10]; void* inv; } Ctl_NPCW;
typedef struct { char pad[0x30]; Ctl_NPCW* ctl; char pad2[0xA4 - 0x34]; int burst; int burstCount; } NPC_W;
extern int cHuman_IsHoldingGun(Ctl_NPCW* c);
extern int Libc_Rand(void);
extern int cWeapon_GetClipSize(void* inv, int slot);
static inline void ResetBurst(NPC_W* self)
{
    Ctl_NPCW* c = self->ctl;
    if (cHuman_IsHoldingGun(c)) {
        void* inv = c->inv;
        self->burst = (self->ctl->seed & 7) + 3;
        if (Libc_Rand() & 1)
            self->burst++;
        if (self->burst > cWeapon_GetClipSize(inv, 6)) {
            int h = cWeapon_GetClipSize(inv, 6) / 2;
            if (h <= 0)
                h = 1;
            self->burst = h;
        }
    } else {
        self->burst = 0;
    }
    self->burstCount = 0;
}extern int cWeapon_GetWeaponSlot(int w);
extern void cWeapon_RemoveWeapon(void* inv, int slot, int a, int b, int c);
void cNPC_RemoveWeapon(NPC_W* self, int w)
{
    void* inv = self->ctl->inv;
    cWeapon_RemoveWeapon(inv, cWeapon_GetWeaponSlot(w), 0, 0, 0);
    ResetBurst(self);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014B790(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014B790 */
