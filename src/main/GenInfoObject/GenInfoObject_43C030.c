#pragma cplusplus on
struct O_001379A0 { void* vt; char pad[0x4C]; char m[4]; };
extern "C" {
extern "C" void func_00293950();
extern "C" void GuiWidget_FocusPrev();
extern "C" void GuiWidget_FocusNext();
extern "C" void GuiWidget_FocusLast();
extern "C" void GuiWidget_FocusFirst();
extern "C" void func_0041E230();
extern "C" void func_0041E2B0();
extern "C" void func_0041E330();
extern "C" void GuiWidget_Update();
extern "C" void GuiWidget_OnEvent();
extern "C" void func_0041F070();
extern "C" void func_0041F080();
extern "C" void GuiWidget_Init();
extern "C" void func_0041F210();
extern "C" void func_0043C0B0();
extern "C" void func_0043C0C0();
extern "C" void func_0043C0F0();
extern "C" void func_0043CA20();
extern "C" void func_0043CAA0();
extern "C" void func_0043CAF0();
extern void * const D_004E0FC0[];
void String_Dtor(void* m, short f);
void GuiWidget_Destroy(void* p, short f);
void operator_delete(void* p);
}
extern "C" O_001379A0* func_0043C030(O_001379A0* self, short del)
{
    if (self) {
        self->vt = ((char*)D_004E0FC0);
        if (self->m) String_Dtor(self->m, 0);
        GuiWidget_Destroy(self, 0);
        if (del > 0) operator_delete(self);
    }
    return self;
}
void * const D_004E0FC0[24] = { (void*)0x0, (void*)0x0, (void*)func_0043C030, (void*)GuiWidget_Init, (void*)func_0043CA20, (void*)func_0041F080, (void*)func_0041F070, (void*)func_0043CAF0, (void*)func_0043CAA0, (void*)func_0041E330, (void*)func_0041E2B0, (void*)func_00293950, (void*)func_0043C0F0, (void*)func_0041E230, (void*)GuiWidget_Update, (void*)GuiWidget_OnEvent, (void*)func_0041F210, (void*)GuiWidget_FocusFirst, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)func_0043C0B0, (void*)func_0043C0C0, (void*)0x0 };
