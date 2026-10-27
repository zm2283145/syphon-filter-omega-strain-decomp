#include "types.h"
typedef struct { char pad[0x48]; char m48[0x9C]; char mE4[4]; } M326CC0;
typedef struct { void* vt; char pad[0x44]; char m48[0x24]; char m6C[0xC]; char m78[0x18]; M326CC0 m90; } O326CC0;
extern void GuiSlideShow_GetClassName();
extern void GuiSlideShow_IsClass();
extern void GuiSlideShow_onRender();
extern void GuiSlideShow_onInput();
extern void GuiSlideShow_onSleep();
extern void GuiSlideShow_onWake();
extern void GuiSlideShow_onAdd();
extern void GuiWidget_FindPrevFocus();
extern void GuiWidget_FindNextFocus();
extern void GuiWidget_FindLastFocus();
extern void GuiWidget_FindFirstFocus();
extern void GuiWidget_onAction();
extern void GuiWidget_onLoseFocus();
extern void GuiWidget_onGainFocus();
extern void GuiWidget_onAdvanceTime();
extern void GuiWidget_onMessage();
extern void GuiWidget_onDeactivate();
extern void GuiWidget_onActivate();
extern void GuiWidget_onRemove();
extern void GuiWidget_Load();
extern void * const D_004DE710[];
extern void cFileMan_dtor(void* p, int f);
extern void String_Dtor(void* p, int f);
extern void std_vector_deleter_Section_dtor(void* p, int f);
extern void GuiWidget_dtor(void* p, int f);
extern void operator_delete(void* p);
static inline void M326CC0_dtor(M326CC0* m)
{
    if (m) {
        cFileMan_dtor(m->mE4, -1);
        cFileMan_dtor(m->m48, -1);
    }
}
static inline void C326CC0(void* p) { if (p) std_vector_deleter_Section_dtor(p, 0); }
static inline void B326CC0(void* p) { if (p) C326CC0(p); }
static inline void A326CC0(void* p) { if (p) B326CC0(p); }
O326CC0* GuiSlideShow_dtor(O326CC0* self, short del)
{
    if (self) {
        self->vt = ((char*)D_004DE710);
        M326CC0_dtor(&self->m90);
        if (self->m78)
            String_Dtor(self->m78, 0);
        if (self->m6C)
            String_Dtor(self->m6C, 0);
        A326CC0(self->m48);
        GuiWidget_dtor(self, 0);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DE710[24] = { (void*)0x0, (void*)0x0, (void*)GuiSlideShow_dtor, (void*)GuiSlideShow_onAdd, (void*)GuiWidget_onRemove, (void*)GuiWidget_onActivate, (void*)GuiWidget_onDeactivate, (void*)GuiSlideShow_onWake, (void*)GuiSlideShow_onSleep, (void*)GuiWidget_onGainFocus, (void*)GuiWidget_onLoseFocus, (void*)GuiSlideShow_onInput, (void*)GuiSlideShow_onRender, (void*)GuiWidget_onAction, (void*)GuiWidget_onAdvanceTime, (void*)GuiWidget_onMessage, (void*)GuiWidget_Load, (void*)GuiWidget_FindFirstFocus, (void*)GuiWidget_FindLastFocus, (void*)GuiWidget_FindNextFocus, (void*)GuiWidget_FindPrevFocus, (void*)GuiSlideShow_GetClassName, (void*)GuiSlideShow_IsClass, (void*)0x0 };
