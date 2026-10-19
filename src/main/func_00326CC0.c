#include "types.h"
typedef struct { char pad[0x48]; char m48[0x9C]; char mE4[4]; } M326CC0;
typedef struct { void* vt; char pad[0x44]; char m48[0x24]; char m6C[0xC]; char m78[0x18]; M326CC0 m90; } O326CC0;
extern void GuiSlideShow_GetClassName();
extern void GuiSlideShow_IsType();
extern void GuiSlideShow_Draw();
extern void GuiSlideShow_HandleInput();
extern void GuiSlideShow_Sleep();
extern void GuiSlideShow_Wake();
extern void GuiSlideShow_Init();
extern void GuiWidget_FocusPrev();
extern void GuiWidget_FocusNext();
extern void GuiWidget_FocusLast();
extern void GuiWidget_FocusFirst();
extern void GuiWidget_BubbleActivate();
extern void GuiWidget_BubbleType1();
extern void GuiWidget_BubbleType0();
extern void GuiWidget_Update();
extern void GuiWidget_OnEvent();
extern void GuiWidget_ClearFlag4();
extern void GuiWidget_SetFlag4();
extern void GuiWidget_Deinit();
extern void GuiWidget_Load();
extern void * const D_004DE710[];
extern void FileMan_Release(void* p, int f);
extern void String_Dtor(void* p, int f);
extern void func_0032A2F0(void* p, int f);
extern void GuiWidget_Destroy(void* p, int f);
extern void operator_delete(void* p);
static inline void M326CC0_dtor(M326CC0* m)
{
    if (m) {
        FileMan_Release(m->mE4, -1);
        FileMan_Release(m->m48, -1);
    }
}
static inline void C326CC0(void* p) { if (p) func_0032A2F0(p, 0); }
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
        GuiWidget_Destroy(self, 0);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DE710[24] = { (void*)0x0, (void*)0x0, (void*)GuiSlideShow_dtor, (void*)GuiSlideShow_Init, (void*)GuiWidget_Deinit, (void*)GuiWidget_SetFlag4, (void*)GuiWidget_ClearFlag4, (void*)GuiSlideShow_Wake, (void*)GuiSlideShow_Sleep, (void*)GuiWidget_BubbleType0, (void*)GuiWidget_BubbleType1, (void*)GuiSlideShow_HandleInput, (void*)GuiSlideShow_Draw, (void*)GuiWidget_BubbleActivate, (void*)GuiWidget_Update, (void*)GuiWidget_OnEvent, (void*)GuiWidget_Load, (void*)GuiWidget_FocusFirst, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)GuiSlideShow_GetClassName, (void*)GuiSlideShow_IsType, (void*)0x0 };
