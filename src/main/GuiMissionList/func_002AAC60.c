#include "types.h"
typedef struct { void* vt; char pad[0x5C]; char m60[0xAC]; char m10C[4]; } O2AAC60;
extern void GuiMissionList_GetClassName();
extern void GuiMissionList_IsType();
extern void GuiMissionList_onElementRender();
extern void GuiMissionList_onRowRender();
extern void GuiMissionList_Sleep();
extern void GuiMissionList_Wake();
extern void func_002AC300();
extern void GuiMissionList_Update();
extern void GuiMissionList_Init();
extern void GuiWidget_FocusPrev();
extern void GuiWidget_FocusNext();
extern void GuiWidget_FocusLast();
extern void GuiWidget_FocusFirst();
extern void GuiWidget_BubbleActivate();
extern void GuiWidget_OnEvent();
extern void GuiWidget_ClearFlag4();
extern void GuiWidget_SetFlag4();
extern void GuiWidget_Deinit();
extern void GuiWidget_Load();
extern void GuiArrayWidget_SendEvent21();
extern void GuiArrayWidget_onColumnRender();
extern void GuiArrayWidget_Draw();
extern void GuiArrayWidget_OnInput();
extern void GuiArrayWidget_SetDims();
extern void GuiArrayWidget_OnLoseFocus();
extern void GuiArrayWidget_OnGainFocus();
extern void * const D_004DDB80[];
extern char D_004E0D20[];
extern void std_vector_deleter_SelectElem_dtor_void_2(void* p, int f);
extern void cArray_int_dtor(void* p, int f);
extern void GuiWidget_Destroy(void* p, int f);
extern void operator_delete(void* p);
static inline void C2AAC60(void* p) { if (p) std_vector_deleter_SelectElem_dtor_void_2(p, 0); }
static inline void B2AAC60(void* p) { if (p) C2AAC60(p); }
static inline void A2AAC60(void* p) { if (p) B2AAC60(p); }
static inline void Base2AAC60(O2AAC60* p)
{
    if (p) {
        p->vt = D_004E0D20;
        cArray_int_dtor(p->m60, -1);
        GuiWidget_Destroy(p, 0);
    }
}
O2AAC60* GuiMissionList_dtor(O2AAC60* self, short del)
{
    if (self) {
        self->vt = ((char*)D_004DDB80);
        A2AAC60(self->m10C);
        Base2AAC60(self);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DDB80[30] = { (void*)0x0, (void*)0x0, (void*)GuiMissionList_dtor, (void*)GuiMissionList_Init, (void*)GuiWidget_Deinit, (void*)GuiWidget_SetFlag4, (void*)GuiWidget_ClearFlag4, (void*)GuiMissionList_Wake, (void*)GuiMissionList_Sleep, (void*)GuiArrayWidget_OnGainFocus, (void*)GuiArrayWidget_OnLoseFocus, (void*)GuiArrayWidget_OnInput, (void*)GuiArrayWidget_Draw, (void*)GuiWidget_BubbleActivate, (void*)GuiMissionList_Update, (void*)GuiWidget_OnEvent, (void*)GuiWidget_Load, (void*)GuiWidget_FocusFirst, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)GuiMissionList_GetClassName, (void*)GuiMissionList_IsType, (void*)GuiArrayWidget_SetDims, (void*)GuiArrayWidget_onColumnRender, (void*)GuiMissionList_onRowRender, (void*)GuiMissionList_onElementRender, (void*)func_002AC300, (void*)GuiArrayWidget_SendEvent21, (void*)0x0 };
