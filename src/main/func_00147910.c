/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

extern char D_004FFD30[];
extern int Global_ReloadWeapons(void);
extern int func_00147630(int);
extern int func_0036E5D0(void*);
extern int func_003CC1D0(void*);

/* Constructor: base init, sub-object at +0x1C, then clear the fields. */
Unk00147910* func_00147910(Unk00147910* self) {
    func_003CC1D0(self);
    func_0036E5D0(&self->unk1C);
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

    db = *(int*)D_004FFD30;
    return func_00147630(db);
}

void func_001479A0(void) {
}
