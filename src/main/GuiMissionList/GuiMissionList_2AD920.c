#include "types.h"
typedef struct { void* vt; char pad[0xA8]; char mAC[0x1C]; char mC8[0x1C]; char mE4[0x20]; char m104[4]; } O2AD920;
extern void GuiSaveAgentWidget_SaveDone();
extern void GuiNetContacts_GetClassName();
extern void GuiNetContacts_IsType();
extern void GuiNetContacts_SelectAgentRemove();
extern void GuiNetContacts_HandleEvent();
extern void GuiNetContacts_Deactivate();
extern void GuiNetContacts_Activate();
extern void GuiNetContacts_Init();
extern void GuiScreen_PollLobby();
extern void GuiMenuScreen_HandleInput();
extern void GuiMenuScreen_Update();
extern void GuiMenuScreen_OpenAgentInfo();
extern void GuiMenuScreen_JoinGame();
extern void GuiMenuScreen_OpenKeyboard();
extern void GuiMenuScreen_Sleep();
extern void GuiMenuScreen_Wake();
extern void GuiWidget_FocusPrev();
extern void GuiWidget_FocusNext();
extern void GuiWidget_FocusLast();
extern void GuiWidget_FocusFirst();
extern void GuiWidget_BubbleActivate();
extern void GuiWidget_BubbleType1();
extern void GuiWidget_BubbleType0();
extern void GuiWidget_Draw();
extern void GuiWidget_ClearFlag4();
extern void GuiWidget_SetFlag4();
extern void GuiWidget_Deinit();
extern void GuiWidget_Load();
extern void * const D_004DDC20[];
extern char D_004DE8A0[];
extern void String_Dtor(void* p, int f);
extern void LobbyArray_dtor(void* p, int f);
extern void GuiScreen_dtor(void* p, int f);
extern void operator_delete(void* p);
static inline void Base2AD920(O2AD920* p)
{
    if (p) {
        p->vt = D_004DE8A0;
        if (p->m104)
            String_Dtor(p->m104, 0);
        LobbyArray_dtor(p->mE4, -1);
        LobbyArray_dtor(p->mC8, -1);
        LobbyArray_dtor(p->mAC, -1);
        GuiScreen_dtor(p, 0);
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
void * const D_004DDC20[32] = { (void*)0x0, (void*)0x0, (void*)GuiNetContacts_dtor, (void*)GuiNetContacts_Init, (void*)GuiWidget_Deinit, (void*)GuiWidget_SetFlag4, (void*)GuiWidget_ClearFlag4, (void*)GuiMenuScreen_Wake, (void*)GuiMenuScreen_Sleep, (void*)GuiWidget_BubbleType0, (void*)GuiWidget_BubbleType1, (void*)GuiMenuScreen_HandleInput, (void*)GuiWidget_Draw, (void*)GuiWidget_BubbleActivate, (void*)GuiMenuScreen_Update, (void*)GuiNetContacts_HandleEvent, (void*)GuiWidget_Load, (void*)GuiWidget_FocusFirst, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)GuiNetContacts_GetClassName, (void*)GuiNetContacts_IsType, (void*)GuiSaveAgentWidget_SaveDone, (void*)GuiScreen_PollLobby, (void*)GuiNetContacts_Activate, (void*)GuiNetContacts_Deactivate, (void*)GuiMenuScreen_OpenKeyboard, (void*)GuiMenuScreen_OpenAgentInfo, (void*)GuiMenuScreen_JoinGame, (void*)GuiNetContacts_SelectAgentRemove, (void*)0x0 };
