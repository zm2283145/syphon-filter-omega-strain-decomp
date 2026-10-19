/*
 * main/GuiRanks: 3 files, 0034E490-0034E4D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0034E490 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * GuiRanks class-name getter (vtable D_004DED50 slot 19).
 */

#include "loose03_types.h"

char D_004BA980[] = "GuiRanks";       /* "GuiRanks" */

/* Returns the class name string "GuiRanks". */
const char* GuiRanks_GetClassName(void) {
    return D_004BA980;
}
#pragma pop /* merge_units */
/* merge_units: end func_0034E490 */

/* merge_units: begin func_0034E4A0 */
#pragma push /* merge_units */
#include "types.h"

extern int strcmp(const char* a, const char* b); /* strcmp */

/* Returns 1 if name equals the string "GuiRanks". */
int GuiRanks_IsType(void* self, const char* name)
{
    return strcmp("GuiRanks", name) == 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_0034E4A0 */

/* merge_units: begin func_0034E4D0 */
#pragma push /* merge_units */
typedef struct { char* key; int id; int pad[7]; } R34E4D0;
typedef struct { int a0; int count; R34E4D0* data; } T34E4D0;
typedef struct { int pad0; int id; } C34E4D0;
typedef struct { char pad[0xB50]; C34E4D0* cur; } A34E4D0;
typedef struct { char pad[0x48]; int a48; } S34E4D0;
extern char g_Game[];
extern T34E4D0 g_RankRows;
extern A34E4D0* Agent_GetSelected(void* list, int idx);
extern char* Loc_LookupText(char* key);
extern void GuiTextListWidget_AddItem(int list, char* name, int idx, int state);
#pragma opt_strength_reduction off
void GuiRanks_Fill(S34E4D0* o)
{
    A34E4D0* ag = Agent_GetSelected(g_Game, -1);
    T34E4D0* t = &g_RankRows;
    C34E4D0* cur = ag->cur;
    int i;
    for (i = 0; i < t->count; i++) {
        R34E4D0* r = &t->data[i];
        char* txt = Loc_LookupText(r->key);
        int sel = 0;
        if (cur->id != r->id) sel = 1;
        GuiTextListWidget_AddItem(o->a48, txt, i, sel);
    }
}
#pragma opt_strength_reduction reset
#pragma pop /* merge_units */
/* merge_units: end func_0034E4D0 */
