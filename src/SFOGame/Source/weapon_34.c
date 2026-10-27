/*
 * SFOGame/Source/weapon: 3 files, 00147910-001479C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00147910 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

extern char g_WeaponDatabase[];
extern int Global_ReloadWeapons(void);
extern int cWeaponDB_Reload(int);
extern int cFileMan_ctor_void(void*);
extern int cDB_ctor(void*);

/* Constructor: base init, sub-object at +0x1C, then clear the fields. */
Unk00147910* cWeaponDB_ctor(Unk00147910* self) {
    cDB_ctor(self);
    cFileMan_ctor_void(&self->unk1C);
    self->unk14 = 0;
    self->unk18 = 0;
    self->unkD4 = 0;
    self->unk10 = 0;
    self->unkB8[0] = 0;
    self->unkB8[1] = 0;
    self->unkB8[2] = 0;
    self->unkB8[3] = 0;
    self->unkB8[4] = 0;
    self->unkB8[5] = 0;
    self->unkB8[6] = 0;
    return self;
}

int Script_ReloadWeapons(void) {
    Global_ReloadWeapons();
    return 0;
}

int Global_ReloadWeapons(void) {
    int db;

    db = *(int*)g_WeaponDatabase;
    return cWeaponDB_Reload(db);
}

void func_001479A0(void) {
}
static inline void merge_flush_func_00147910(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00147910 */

/* merge_units: begin func_001479B0 */
#pragma push /* merge_units */
/* Returns 1.0f. */
float Light_GetCoronaSize(void)
{
    return 1.0f;
}
static inline void merge_flush_func_001479B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001479B0 */

/* merge_units: begin func_001479C0 */
#pragma push /* merge_units */
int Light_GetCoronaFlag(void) {
    return 1;
}
static inline void merge_flush_func_001479C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001479C0 */
