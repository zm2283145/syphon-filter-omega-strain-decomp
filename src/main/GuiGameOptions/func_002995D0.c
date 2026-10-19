#include "types.h"
typedef struct { char pad[0x48]; char m48[0x9C]; char mE4[4]; } M2995D0;
typedef struct { void* vt; char pad[0xDC]; M2995D0 mE0; char pad2[0x270 - 0xE0 - sizeof(M2995D0)]; M2995D0 m270; } O2995D0;
extern void GuiGameOptions_GetClassName();
extern void GuiGameOptions_IsType();
extern void GuiGameOptions_HandleInput();
extern void GuiGameOptions_HandleEvent();
extern void GuiGameOptions_OnSaveDone();
extern void GuiGameOptions_Sleep();
extern void GuiGameOptions_Wake();
extern void GuiGameOptions_Init();
extern void GuiGameOptions_Update();
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
extern void * const D_004DD580[];
extern char D_004E1220[];
extern void FileMan_Release(void* p, int f);
extern void GuiWidget_Destroy(void* p, int f);
extern void operator_delete(void* p);
static inline void M2995D0_dtor(M2995D0* m)
{
    if (m) {
        FileMan_Release(m->mE4, -1);
        FileMan_Release(m->m48, -1);
    }
}
static inline void Base2995D0(O2995D0* p)
{
    if (p) {
        p->vt = D_004E1220;
        GuiWidget_Destroy(p, 0);
    }
}
O2995D0* GuiGameOptions_dtor(O2995D0* self, short del)
{
    if (self) {
        self->vt = ((char*)D_004DD580);
        M2995D0_dtor(&self->m270);
        M2995D0_dtor(&self->mE0);
        Base2995D0(self);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DD580[24] = { (void*)0x0, (void*)0x0, (void*)GuiGameOptions_dtor, (void*)GuiGameOptions_Init, (void*)GuiWidget_Deinit, (void*)GuiWidget_SetFlag4, (void*)GuiWidget_ClearFlag4, (void*)GuiGameOptions_Wake, (void*)GuiGameOptions_Sleep, (void*)GuiWidget_BubbleType0, (void*)GuiWidget_BubbleType1, (void*)GuiGameOptions_HandleInput, (void*)GuiWidget_Draw, (void*)GuiWidget_BubbleActivate, (void*)GuiGameOptions_Update, (void*)GuiGameOptions_HandleEvent, (void*)GuiWidget_Load, (void*)GuiWidget_FocusFirst, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)GuiGameOptions_GetClassName, (void*)GuiGameOptions_IsType, (void*)GuiGameOptions_OnSaveDone };
