/*
 * main/GuiSaveAgentWidget: 2 files, 00441A10-00441C10
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00441A10 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"

struct NetImpl_441A10 { char pad[0x59D]; unsigned char f59D; char pad59E[0xA]; int f5A8; };
struct Net_441A10 { NetImpl_441A10* impl; int f4; void* cb; };

struct Obj_441A10 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04();
    virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09();
    virtual void v0A(); virtual void v0B(); virtual void v0C(); virtual void v0D(); virtual void v0E();
    virtual void v0F(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
    virtual void v14();
    virtual void Close(int a); /* +0x5C */
    char pad04[0x44];
    int dlg;
    unsigned char mode;
    int f50;
    unsigned char shown;
};

extern "C" {
extern char g_Game[];
extern int D_004FFC04;
extern int g_CardSlotId;
extern unsigned char D_004FFBB8;
extern Net_441A10 g_MemCard;
extern char D_004C0448[]; extern char D_004C04F0[]; extern char D_004C0500[];
extern char D_004C0510[]; extern char D_004C0520[];
int* cGameSystem_GetAgentData(void*, int);
char* nGlobalization_GetString_charP(char*);
int cGameFrontEnd_PushMessageBox(int, int, char*, char*, void*, int);
void cMemCard_FullCheck(Net_441A10*);
void GuiSaveAgentWidget_StartChecks(Obj_441A10*);
void SaveCallback(void);
}

static inline int ShowDlg(int mgr, int type, char* t, char* m, void* cb, int x) { return cGameFrontEnd_PushMessageBox(mgr, type, nGlobalization_GetString_charP(t), nGlobalization_GetString_charP(m), cb, x); }

extern "C" void GuiSaveAgentWidget_HandleEvent(Obj_441A10* self)
{
    Net_441A10* net = &g_MemCard;
    if (self->mode != 0 && self->mode != 4) self->f50 = cGameSystem_GetAgentData(g_Game, -1)[1];
    self->shown = 0;
    net->cb = (void*)SaveCallback;
    cMemCard_FullCheck(net);
    if (!net->impl->f59D) {
        if (self->mode == 2 && !D_004FFBB8) {
            net->cb = 0;
            self->Close(0);
            return;
        }
        if (self->mode == 4) {
            self->dlg = ShowDlg(D_004FFC04, 2, D_004C0448, D_004C04F0, self, 10);
            return;
        }
        {
            char* m = self->mode ? D_004C0500 : D_004C0510;
            self->dlg = ShowDlg(D_004FFC04, 5, D_004C0448, m, self, 3);
        }
        return;
    }
    D_004FFBB8 = 1;
    if (self->mode != 0 && g_CardSlotId != net->impl->f5A8) {
        self->dlg = ShowDlg(D_004FFC04, 5, D_004C0448, D_004C0520, self, 5);
        return;
    }
    GuiSaveAgentWidget_StartChecks(self);
}
#pragma pop /* merge_units */
/* merge_units: end func_00441A10 */

/* merge_units: begin func_00441C10 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Not inside a known source-file range: after guiMLTextWidget.cc (ends 0x0043E330),
 * before SFOLobby_Mission.cc (starts 0x00442510).
 */


extern void cGameFrontEnd_LobbyCallback(int, int);

void SaveCallback(void) {
    cGameFrontEnd_LobbyCallback(0, 0);
}
#pragma pop /* merge_units */
/* merge_units: end func_00441C10 */
