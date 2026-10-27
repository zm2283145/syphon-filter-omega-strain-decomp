/*
 * SFOGame/Source/GuiNetContacts: 1 file, 002AD920
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin GuiMissionList_2AD920 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { void* vt; char pad[0xA8]; char mAC[0x1C]; char mC8[0x1C]; char mE4[0x20]; char m104[4]; } O2AD920;
extern void GuiSaveAgentWidget_SaveDone();
extern void GuiNetContacts_GetClassName();
extern void GuiNetContacts_IsClass();
extern void GuiNetContacts_SelectAgentRemove();
extern void GuiNetContacts_onMessage();
extern void GuiNetContacts_Deactivate();
extern void GuiNetContacts_Activate();
extern void GuiNetContacts_onAdd();
extern void GuiScreen_PollLobby();
extern void GuiMissionLobbyScreen_onInput();
extern void GuiMissionLobbyScreen_onAdvanceTime();
extern void GuiMissionLobbyScreen_SelectAgentInfo();
extern void GuiMenuScreen_JoinGame();
extern void GuiMissionLobbyScreen_SelectAgentChat();
extern void GuiMissionLobbyScreen_onSleep();
extern void GuiMissionLobbyScreen_onWake();
extern void GuiWidget_FindPrevFocus();
extern void GuiWidget_FindNextFocus();
extern void GuiWidget_FindLastFocus();
extern void GuiWidget_FindFirstFocus();
extern void GuiWidget_onAction();
extern void GuiWidget_onLoseFocus();
extern void GuiWidget_onGainFocus();
extern void GuiWidget_onRender();
extern void GuiWidget_onDeactivate();
extern void GuiWidget_onActivate();
extern void GuiWidget_onRemove();
extern void GuiWidget_Load();
extern void * const D_004DDC20[];
extern char D_004DE8A0[];
extern void String_Dtor(void* p, int f);
extern void SFOLobbyList_dtor(void* p, int f);
extern void GuiLobbyScreen_dtor(void* p, int f);
extern void operator_delete(void* p);
static inline void Base2AD920(O2AD920* p)
{
    if (p) {
        p->vt = D_004DE8A0;
        if (p->m104)
            String_Dtor(p->m104, 0);
        SFOLobbyList_dtor(p->mE4, -1);
        SFOLobbyList_dtor(p->mC8, -1);
        SFOLobbyList_dtor(p->mAC, -1);
        GuiLobbyScreen_dtor(p, 0);
    }
}
O2AD920* GuiNetContacts_dtor(O2AD920* self, short del)
{
    if (self) {
        self->vt = ((char*)D_004DDC20);
        Base2AD920(self);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DDC20[32] = { (void*)0x0, (void*)0x0, (void*)GuiNetContacts_dtor, (void*)GuiNetContacts_onAdd, (void*)GuiWidget_onRemove, (void*)GuiWidget_onActivate, (void*)GuiWidget_onDeactivate, (void*)GuiMissionLobbyScreen_onWake, (void*)GuiMissionLobbyScreen_onSleep, (void*)GuiWidget_onGainFocus, (void*)GuiWidget_onLoseFocus, (void*)GuiMissionLobbyScreen_onInput, (void*)GuiWidget_onRender, (void*)GuiWidget_onAction, (void*)GuiMissionLobbyScreen_onAdvanceTime, (void*)GuiNetContacts_onMessage, (void*)GuiWidget_Load, (void*)GuiWidget_FindFirstFocus, (void*)GuiWidget_FindLastFocus, (void*)GuiWidget_FindNextFocus, (void*)GuiWidget_FindPrevFocus, (void*)GuiNetContacts_GetClassName, (void*)GuiNetContacts_IsClass, (void*)GuiSaveAgentWidget_SaveDone, (void*)GuiScreen_PollLobby, (void*)GuiNetContacts_Activate, (void*)GuiNetContacts_Deactivate, (void*)GuiMissionLobbyScreen_SelectAgentChat, (void*)GuiMissionLobbyScreen_SelectAgentInfo, (void*)GuiMenuScreen_JoinGame, (void*)GuiNetContacts_SelectAgentRemove, (void*)0x0 };
static inline void merge_flush_GuiMissionList_2AD920(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end GuiMissionList_2AD920 */
