#pragma cplusplus on
struct O_001379A0 { void* vt; char pad[0x4C]; char m[4]; };
extern "C" {
extern "C" void GuiWidget_onInput();
extern "C" void GuiWidget_FocusPrev();
extern "C" void GuiWidget_FocusNext();
extern "C" void GuiWidget_FocusLast();
extern "C" void GuiWidget_FocusFirst();
extern "C" void GuiWidget_BubbleActivate();
extern "C" void GuiWidget_BubbleType1();
extern "C" void GuiWidget_BubbleType0();
extern "C" void GuiWidget_Update();
extern "C" void GuiWidget_OnEvent();
extern "C" void GuiWidget_ClearFlag4();
extern "C" void GuiWidget_SetFlag4();
extern "C" void GuiWidget_Init();
extern "C" void GuiWidget_Load();
extern "C" void GuiBitmapWidget_GetClassName();
extern "C" void GuiBitmapWidget_IsType();
extern "C" void GuiBitmapWidget_Draw();
extern "C" void GuiBitmapWidget_Deinit();
extern "C" void GuiBitmapWidget_Sleep();
extern "C" void GuiBitmapWidget_Wake();
extern void * const D_004E0FC0[];
void String_Dtor(void* m, short f);
void GuiWidget_Destroy(void* p, short f);
void operator_delete(void* p);
}
extern "C" O_001379A0* GuiBitmapWidget_dtor(O_001379A0* self, short del)
{
    if (self) {
        self->vt = ((char*)D_004E0FC0);
        if (self->m) String_Dtor(self->m, 0);
        GuiWidget_Destroy(self, 0);
        if (del > 0) operator_delete(self);
    }
    return self;
}
void * const D_004E0FC0[24] = { (void*)0x0, (void*)0x0, (void*)GuiBitmapWidget_dtor, (void*)GuiWidget_Init, (void*)GuiBitmapWidget_Deinit, (void*)GuiWidget_SetFlag4, (void*)GuiWidget_ClearFlag4, (void*)GuiBitmapWidget_Wake, (void*)GuiBitmapWidget_Sleep, (void*)GuiWidget_BubbleType0, (void*)GuiWidget_BubbleType1, (void*)GuiWidget_onInput, (void*)GuiBitmapWidget_Draw, (void*)GuiWidget_BubbleActivate, (void*)GuiWidget_Update, (void*)GuiWidget_OnEvent, (void*)GuiWidget_Load, (void*)GuiWidget_FocusFirst, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)GuiBitmapWidget_GetClassName, (void*)GuiBitmapWidget_IsType, (void*)0x0 };
