/*
 * SFOGame/Source/GuiSaveAgentWidget: 1 file, 00441960
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin GuiSaveAgentWidget_441960 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad[0x59D]; unsigned char b59d; unsigned char b59e; } G441;
typedef struct { char pad[0x48]; int f48; } O441;
extern G441* g_MemCard;
extern int D_004FFC04;
extern char D_004C0448[];
extern char* nGlobalization_GetString_charP(char*);
extern void GuiSaveAgentWidget_HandleEvent(O441*);
extern void SaveAgentWidget_Prepare(O441*);
extern int cGameFrontEnd_PushMessageBox(int, int, char*, char*, O441*, int);
void GuiSaveAgentWidget_StartChecks(O441* o) {
    G441* g = g_MemCard;
    if (!g->b59d) {
        GuiSaveAgentWidget_HandleEvent(o);
    } else if (!g->b59e) {
        int m = D_004FFC04;
        char* t = nGlobalization_GetString_charP(D_004C0448);
        o->f48 = cGameFrontEnd_PushMessageBox(m, 5, t, nGlobalization_GetString_charP("MC_ASKFORMAT"), o, 0);
    } else {
        SaveAgentWidget_Prepare(o);
    }
}
static inline void merge_flush_GuiSaveAgentWidget_441960(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end GuiSaveAgentWidget_441960 */
