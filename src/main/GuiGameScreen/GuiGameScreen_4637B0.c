/*
 * main/GuiGameScreen: 4 files, 004637B0-00463940
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_004637B0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies after GuiGameScreen.cc (ends 0x0045F090).
 */

#include "types.h"

extern int PtrVec_Insert(PtrVec* v, int* pos, int n, int value);

/* Appends one value at the end of the vector. */
int func_004637B0(PtrVec* v, int value) {
    int count;
    int* data;

    count = v->count;
    data = v->data;
    return PtrVec_Insert(v, data + count, 1, value);
}
#pragma pop /* merge_units */
/* merge_units: end func_004637B0 */

/* merge_units: begin func_004637D0 */
#pragma push /* merge_units */
#include "fam5_timed_retry.h"
extern void GuiScoresEquip_Update(char*, float);
DEFINE_TIMED_RETRY(GuiEndGameStatistics_Update, 0x410, 0x260, GuiScoresEquip_Update)
#pragma pop /* merge_units */
/* merge_units: end func_004637D0 */

/* merge_units: begin func_004638A0 */
#pragma push /* merge_units */
extern char g_Game[];
extern void* Agent_GetSelected(void* registry, int agent);
extern int cAgentData_GetStat(void* data, int stat);

/* Returns stat `part` as a percentage of stat `total` for the agent (0 when total is 0). */
int Agent_GetStatPercent(int agent, int part, int total) {
    void* data = Agent_GetSelected(g_Game, agent);
    int percent = 0;
    int totalValue = cAgentData_GetStat(data, total);
    int partValue = cAgentData_GetStat(data, part);
    if (totalValue) {
        percent = partValue * 100 / totalValue;
    }
    return percent;
}
#pragma pop /* merge_units */
/* merge_units: end func_004638A0 */

/* merge_units: begin func_00463940 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies after GuiGameScreen.cc (ends 0x0045F090).
 */

#include "loose05_types.h"

extern GuiWidget* GuiWidget_FocusFirst(GuiWidget* self);

/* Hides the widget returned by GuiWidget_FocusFirst unless it is this widget. */
GuiWidget* GuiEndGameStatistics_First(GuiWidget* self) {
    GuiWidget* other;

    other = GuiWidget_FocusFirst(self);
    if (other != self) {
        other->flags &= ~0x2;
    }
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_00463940 */
