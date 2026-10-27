/*
 * SFOGame/Source/GuiSaveAgentWidget: 1 file, 004415A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin GuiSaveAgentWidget_4415A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"

struct NetImpl_4415A0 { char pad[0x59F]; unsigned char f59F; char pad5A0[8]; int f5A8; };
struct Net_4415A0 { NetImpl_4415A0* impl; };

struct Obj_4415A0 {
    void* vtable;
    char pad04[0x44];
    int dlg;
    unsigned char mode;
    int f50;
    unsigned char shown;
    char name[1];
};

extern "C" {
extern char g_Game[];
extern int D_004FFC04;
extern int g_CardSlotId;
extern Net_4415A0 g_MemCard;
extern char D_004C0448[]; extern char D_004C0458[]; extern char D_004C0468[];
extern char D_004C0498[]; extern char D_004C04A8[];
int cGameSystem_GetAgentData(void*, int);
char* nGlobalization_GetString_charP(char*);
int cGameFrontEnd_PushMessageBox(int, int, char*, char*, void*, int);
void cGameFrontEnd_PopMessageBox(int, int);
int cMemCard_MakeGameDir(Net_4415A0*);
int SaveAgentWidget_FindSlotFile(int, char*, char*);
int SaveAgentWidget_SpaceCheck();
void GuiSaveAgentWidget_Write(Obj_4415A0*);
}

static inline int ShowDlg(int mgr, int type, char* t, char* m, void* cb, int x) { return cGameFrontEnd_PushMessageBox(mgr, type, nGlobalization_GetString_charP(t), nGlobalization_GetString_charP(m), cb, x); }

extern "C" void SaveAgentWidget_Prepare(Obj_4415A0* self)
{
    Net_4415A0* net = &g_MemCard;
    if (!g_MemCard.impl->f59F) {
        if (!SaveAgentWidget_SpaceCheck()) return;
        if (!self->shown) {
            self->shown = 1;
            self->dlg = ShowDlg(D_004FFC04, 0, D_004C0448, D_004C0458, self, 0);
        }
        if (!cMemCard_MakeGameDir(net)) {
            int old = self->dlg;
            self->dlg = ShowDlg(D_004FFC04, 2, D_004C0468, D_004C04A8, self, 2);
            cGameFrontEnd_PopMessageBox(D_004FFC04, old);
            return;
        }
    }
    {
        char* agent = (char*)cGameSystem_GetAgentData(g_Game, -1);
        bool other = g_MemCard.impl->f5A8 != g_CardSlotId;
        if (self->mode != 4) {
            char* name = 0;
            if (self->mode != 0 && !other) name = (self->mode == 3) ? self->name : agent + 0x8AC;
            if (SaveAgentWidget_FindSlotFile(self->f50, name, 0)) {
                self->dlg = ShowDlg(D_004FFC04, 5, D_004C0448, D_004C0498, self, 1);
                return;
            }
        }
        GuiSaveAgentWidget_Write(self);
    }
}
static inline void merge_flush_GuiSaveAgentWidget_4415A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end GuiSaveAgentWidget_4415A0 */
