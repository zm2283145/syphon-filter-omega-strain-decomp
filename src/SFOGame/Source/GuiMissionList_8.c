/*
 * SFOGame/Source/GuiMissionList: 2 files, 002ACC80-002ACCA0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002ACC80 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiMissionList.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "GuiMissionList_types.h"

extern int GuiMissionList_UpdateLobbyList(GuiMissionList* self);

/* Stores a1 at +0x11C, resets three selection indices to -1 and refreshes. */
int func_002ACC80(GuiMissionList* self, int a1) {
    self->unk11C = a1;
    self->unkCC = -1;
    self->unkC4 = -1;
    self->unkC0 = -1;
    return GuiMissionList_UpdateLobbyList(self);
}
static inline void merge_flush_func_002ACC80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002ACC80 */

/* merge_units: begin func_002ACCA0 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern int GuiMissionList_UpdateLobbyList(int);
#endif /* merge_units */
#define GuiMissionList_UpdateLobbyList(a0) (GuiMissionList_UpdateLobbyList((GuiMissionList *)(a0))) /* merge_units */

extern int GuiWidget_onAdvanceTime(int, float);

void GuiMissionList_onAdvanceTime(int a0) {
    int s0, v0, v1;
    float f12;
    int cond;

    s0 = a0;
    v0 = GuiWidget_onAdvanceTime(a0, f12);
    v1 = *(int*)((char*)s0 + 284);
    cond = v1 == 0;
    if (cond) goto L002ACCD8;
    v1 = *(unsigned char*)((char*)v1 + 24);
    cond = v1 == 0;
    a0 = s0;
    if (cond) goto L002ACCD8;
    v0 = GuiMissionList_UpdateLobbyList(a0);
L002ACCD8:;
    goto ret;
ret:;
}
#undef GuiMissionList_UpdateLobbyList /* merge_units */
static inline void merge_flush_func_002ACCA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002ACCA0 */
