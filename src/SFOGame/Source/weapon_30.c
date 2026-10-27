/*
 * SFOGame/Source/weapon: 1 file, 00147110
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00147110 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { void* x0; int x4; void* x8; } S_7110;
extern void* g_WeaponDatabase;
extern void WeaponDb_OnModelLoaded(void* db, int a, void* b, int c);
void cWeaponDB_GunStreamReturn(S_7110* self, int a, int flag)
{
    if (flag) {
        void* b = self->x8;
        int c = self->x4;
        b = b ? b : self->x0;
        WeaponDb_OnModelLoaded(g_WeaponDatabase, a, b, c);
    }
}
static inline void merge_flush_func_00147110(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00147110 */
