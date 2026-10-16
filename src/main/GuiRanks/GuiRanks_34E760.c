/*
 * main/GuiRanks: 3 files, 0034E760-0034E7F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0034E760 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00532B50[];

int func_0034E760(void) {
    return (int)D_00532B50;
}
#pragma pop /* merge_units */
/* merge_units: end func_0034E760 */

/* merge_units: begin func_0034E770 */
#pragma push /* merge_units */
typedef struct { char pad[0xC]; int value; char pad2[0x14]; } Entry36;
typedef struct { char pad[8]; Entry36* entries; } EntryTable;
typedef struct { char pad[0x48]; void* key; } Obj48;
extern char D_004FFB50[];
extern int GuiTextListWidget_GetItemId(void* key);
extern void* Agent_GetSelected(void* list, int index);
#if 0 /* merge_units */
extern EntryTable* func_0034E760(void);
#endif /* merge_units */
#define func_0034E760() ((EntryTable *)func_0034E760()) /* merge_units */

extern void func_00356850(Obj48* o, int idx, int value);
/* Looks up the entry index for the key and applies its value. */
void func_0034E770(Obj48* o)
{
    int idx = GuiTextListWidget_GetItemId(o->key);
    if (idx != -1) {
        Entry36* e;
        Agent_GetSelected(D_004FFB50, -1);
        e = &func_0034E760()->entries[idx];
        func_00356850(o, idx, e->value);
    }
}
#undef func_0034E760 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0034E770 */

/* merge_units: begin func_0034E7F0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * GuiRanks constructor (vtable D_004DED50); derives from GuiPersonnelScreen.
 */

#include "loose03_types.h"

extern char D_004DED50[];       /* vtable */
extern int GuiPersonnelScreen_ctor(GuiPersonnelScreen*);

/* GuiPersonnelScreen subclass constructor (unk64 = 6). */
GuiPersonnelScreen* GuiRanks_ctor(GuiPersonnelScreen* self) {
    GuiPersonnelScreen_ctor(self);
    self->base.vtable = D_004DED50;
    self->unk64 = 6;
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_0034E7F0 */
