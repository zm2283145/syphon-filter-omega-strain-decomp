#include "types.h"
typedef struct { char pad[0x59D]; unsigned char b59d; unsigned char b59e; } G441;
typedef struct { char pad[0x48]; int f48; } O441;
extern G441* g_MemCard;
extern int D_004FFC04;
extern char D_004C0448[];
extern char* Loc_LookupText(char*);
extern void GuiSaveAgentWidget_HandleEvent(O441*);
extern void SaveAgentWidget_Prepare(O441*);
extern int FrontEnd_OpenPopup(int, int, char*, char*, O441*, int);
void GuiSaveAgentWidget_WriteCard(O441* o) {
    G441* g = g_MemCard;
    if (!g->b59d) {
        GuiSaveAgentWidget_HandleEvent(o);
    } else if (!g->b59e) {
        int m = D_004FFC04;
        char* t = Loc_LookupText(D_004C0448);
        o->f48 = FrontEnd_OpenPopup(m, 5, t, Loc_LookupText("MC_ASKFORMAT"), o, 0);
    } else {
        SaveAgentWidget_Prepare(o);
    }
}
