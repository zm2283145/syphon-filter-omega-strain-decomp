#include "types.h"
typedef struct { void* vt; char pad[0xA8]; char mAC[0x1C]; char mC8[0x1C]; char mE4[0x20]; char m104[4]; } O2A8A60;
extern void GuiNetJoinMission_IsClass();
extern void GuiSaveAgentWidget_SaveDone();
extern void GuiNetJoinMission_GetClassName();
extern void GuiMissionLobbyScreen_SelectAgentRemove();
extern void GuiNetJoinMission_onMessage();
extern void GuiNetJoinMission_Deactivate();
extern void GuiNetJoinMission_Activate();
extern void GuiNetJoinMission_Init();
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
extern void * const D_004DDA50[];
extern char D_004DE8A0[];
extern void String_Dtor(void* p, int f);
extern void SFOLobbyList_dtor(void* p, int f);
extern void GuiLobbyScreen_dtor(void* p, int f);
extern void operator_delete(void* p);
static inline void Base2A8A60(O2A8A60* p)
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
O2A8A60* GuiNetJoinMission_dtor(O2A8A60* self, short del)
{
    if (self) {
        self->vt = ((char*)D_004DDA50);
        Base2A8A60(self);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DDA50[32] = { (void*)0x0, (void*)0x0, (void*)GuiNetJoinMission_dtor, (void*)GuiNetJoinMission_Init, (void*)GuiWidget_onRemove, (void*)GuiWidget_onActivate, (void*)GuiWidget_onDeactivate, (void*)GuiMissionLobbyScreen_onWake, (void*)GuiMissionLobbyScreen_onSleep, (void*)GuiWidget_onGainFocus, (void*)GuiWidget_onLoseFocus, (void*)GuiMissionLobbyScreen_onInput, (void*)GuiWidget_onRender, (void*)GuiWidget_onAction, (void*)GuiMissionLobbyScreen_onAdvanceTime, (void*)GuiNetJoinMission_onMessage, (void*)GuiWidget_Load, (void*)GuiWidget_FindFirstFocus, (void*)GuiWidget_FindLastFocus, (void*)GuiWidget_FindNextFocus, (void*)GuiWidget_FindPrevFocus, (void*)GuiNetJoinMission_GetClassName, (void*)GuiNetJoinMission_IsClass, (void*)GuiSaveAgentWidget_SaveDone, (void*)GuiScreen_PollLobby, (void*)GuiNetJoinMission_Activate, (void*)GuiNetJoinMission_Deactivate, (void*)GuiMissionLobbyScreen_SelectAgentChat, (void*)GuiMissionLobbyScreen_SelectAgentInfo, (void*)GuiMenuScreen_JoinGame, (void*)GuiMissionLobbyScreen_SelectAgentRemove, (void*)0x0 };
