/*
 * SFOGame/Source/GuiNetAgencyCell: 1 file, 002AEF40
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002AEF40 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { void* vt; char pad[0xA8]; char mAC[0x1C]; char mC8[0x1C]; char mE4[0x20]; char m104[0x70]; char m174[4]; } O2AEF40;
extern void GuiSaveAgentWidget_SaveDone();
extern void GuiNetAgencyCell_GetClassName();
extern void GuiNetAgencyCell_IsClass();
extern void GuiNetAgencyCell_PollLobby();
extern void GuiNetAgencyCell_SelectAgentRemove();
extern void GuiNetAgencyCell_onAdvanceTime();
extern void GuiNetAgencyCell_onMessage();
extern void GuiNetAgencyCell_Deactivate();
extern void GuiNetAgencyCell_Activate();
extern void GuiNetAgencyCell_onAdd();
extern void GuiMissionLobbyScreen_onInput();
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
extern void * const D_004DDD40[];
extern char D_004DE8A0[];
extern void String_Dtor(void* p, int f);
extern void SFOLobbyList_dtor(void* p, int f);
extern void GuiLobbyScreen_dtor(void* p, int f);
extern void operator_delete(void* p);
static inline void Base2AEF40(O2AEF40* p)
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
O2AEF40* GuiNetAgencyCell_dtor(O2AEF40* self, short del)
{
    if (self) {
        self->vt = ((char*)D_004DDD40);
        if (self->m174)
            String_Dtor(self->m174, 0);
        Base2AEF40(self);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DDD40[32] = { (void*)0x0, (void*)0x0, (void*)GuiNetAgencyCell_dtor, (void*)GuiNetAgencyCell_onAdd, (void*)GuiWidget_onRemove, (void*)GuiWidget_onActivate, (void*)GuiWidget_onDeactivate, (void*)GuiMissionLobbyScreen_onWake, (void*)GuiMissionLobbyScreen_onSleep, (void*)GuiWidget_onGainFocus, (void*)GuiWidget_onLoseFocus, (void*)GuiMissionLobbyScreen_onInput, (void*)GuiWidget_onRender, (void*)GuiWidget_onAction, (void*)GuiNetAgencyCell_onAdvanceTime, (void*)GuiNetAgencyCell_onMessage, (void*)GuiWidget_Load, (void*)GuiWidget_FindFirstFocus, (void*)GuiWidget_FindLastFocus, (void*)GuiWidget_FindNextFocus, (void*)GuiWidget_FindPrevFocus, (void*)GuiNetAgencyCell_GetClassName, (void*)GuiNetAgencyCell_IsClass, (void*)GuiSaveAgentWidget_SaveDone, (void*)GuiNetAgencyCell_PollLobby, (void*)GuiNetAgencyCell_Activate, (void*)GuiNetAgencyCell_Deactivate, (void*)GuiMissionLobbyScreen_SelectAgentChat, (void*)GuiMissionLobbyScreen_SelectAgentInfo, (void*)GuiMenuScreen_JoinGame, (void*)GuiNetAgencyCell_SelectAgentRemove, (void*)0x0 };
static inline void merge_flush_func_002AEF40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002AEF40 */
