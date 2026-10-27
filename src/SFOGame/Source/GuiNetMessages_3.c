/*
 * SFOGame/Source/GuiNetMessages: 2 files, 00346D30-00346D60
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00346D30 */
#pragma push /* merge_units */
#include "types.h"

extern void* strcmp(void* key);

/* Returns whether the lookup of "GuiNetMessages" yields null. */
int GuiNetMessages_IsClass(void) {
    return strcmp("GuiNetMessages") == 0;
}
static inline void merge_flush_func_00346D30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00346D30 */

/* merge_units: begin func_00346D60 */
#pragma push /* merge_units */
typedef struct { char pad[0x14]; unsigned short flags; } W_46D60;
typedef struct { char pad[0x8C]; void* x8C; W_46D60* x90; void* x94; int x98; int x9C; } S_46D60;
extern char D_004BA310[];
extern char D_004BA328[];
extern char D_004BA338[];
extern void* D_004FFC04;
extern int Gui_Manager(void);
extern int Gui_Canvas(void);
extern void* GuiManager_OpenGui(int, char*, char*);
extern void* cDME_GetLobby(void);
extern int GuiLobbyScreen_GetLobbyString(S_46D60*, int, int, int, int, int);
extern int cGameFrontEnd_PushMessageBox(void* ui, int a, char* b, int c, void* d, int e);
extern void cGameFrontEnd_PopMessageBox(void* ui, int p);
extern void cGameFrontEnd_LobbyDestroy(void* ui, int a);
extern void GuiCanvas_Transition(int, S_46D60*, void*);
extern int SFOLobby_MessageGet(void* l, int id);
extern void GuiNetMessages_MessageSelected(S_46D60* s, int x);
extern void SFOLobby_MessageAck(void* l, int id, int ok);
extern void SFOLobbyList_SetUpdateFlag(void* l, int a);
extern int GuiLobbyScreen_onMessage(S_46D60* s, void* from, unsigned short ev, int kind, int data);
int GuiNetMessages_onMessage(S_46D60* self, void* from, unsigned short ev, int kind, int data)
{
    if (kind == 0x19 && ev == 0x1A) {
        void* scr = GuiManager_OpenGui(Gui_Manager(), D_004BA310, D_004BA328);
        if (cDME_GetLobby()) {
            void* ui = D_004FFC04;
            int p = cGameFrontEnd_PushMessageBox(ui, 0, D_004BA338, GuiLobbyScreen_GetLobbyString(self, 0x77, 0, 0, 0, 0), 0, 0);
            cGameFrontEnd_LobbyDestroy(D_004FFC04, 1);
            cGameFrontEnd_PopMessageBox(D_004FFC04, p);
        }
        cGameFrontEnd_PopMessageBox(D_004FFC04, self->x9C);
        GuiCanvas_Transition(Gui_Canvas(), self, scr);
        return 1;
    }
    if (ev == 0x14) {
        void* l = cDME_GetLobby();
        if (l) {
            self->x98 = data;
            GuiNetMessages_MessageSelected(self, SFOLobby_MessageGet(l, self->x98));
        }
        return 1;
    }
    if (ev == 2) {
        void* l = cDME_GetLobby();
        if (l && SFOLobby_MessageGet(l, self->x98)) {
            if (from == self->x8C || from == self->x94) {
                SFOLobby_MessageAck(l, self->x98, !(self->x90->flags & 2));
                SFOLobbyList_SetUpdateFlag((char*)l + 0x1C, 1);
                return 1;
            }
            if (from == self->x90) {
                SFOLobby_MessageAck(l, self->x98, 1);
                SFOLobbyList_SetUpdateFlag((char*)l + 0x1C, 1);
                return 1;
            }
        }
    }
    return GuiLobbyScreen_onMessage(self, from, ev, kind, data);
}
static inline void merge_flush_func_00346D60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00346D60 */
