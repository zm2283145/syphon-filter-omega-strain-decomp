/*
 * SFOGame/Source/GuiCommandCenter: 1 file, 00294AB0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin GuiSaveAgentWidget_294AB0 */
#pragma push /* merge_units */
#include "types.h"

typedef struct { char pad[0x14]; unsigned short flags; } Part294;
typedef struct { char pad[0x1D4]; unsigned char unk1D4; char pad2[3]; Part294* parts[6]; } Obj294;

/* Clears flag bits 1 and 2 on all six parts, then sets them on the first part. */
void GuiCommandCenter_ResetGroups(Obj294* self)
{
    Obj294* p; /* walks self by one part slot per iteration so p->parts[0] is part i */
    int i;
    i = 0;
    p = self;
    for (; i < 6; i++, p = (Obj294*)((Part294**)p + 1)) {
        if (p->parts[0]) {
            p->parts[0]->flags &= ~4;
            p->parts[0]->flags &= ~2;
        }
    }
    if (self->parts[0]) {
        self->parts[0]->flags |= 4;
        self->parts[0]->flags |= 2;
    }
    self->unk1D4 = 0;
}
static inline void merge_flush_GuiSaveAgentWidget_294AB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end GuiSaveAgentWidget_294AB0 */
