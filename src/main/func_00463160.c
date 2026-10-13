#pragma cplusplus on
#include "types.h"
struct Ev_463160 { unsigned short type; unsigned short f2; unsigned short f4; unsigned short f6; unsigned short btn; };
struct Ui_463160 {
    virtual void _v00(); virtual void _v01(); virtual void _v02(); virtual void _v03(); virtual void _v04();
    virtual void _v05(); virtual void _v06(); virtual void _v07(); virtual void _v08(); virtual void _v09();
    virtual void _v0A(); virtual void _v0B(); virtual void _v0C(); virtual void _v0D(); virtual void _v0E();
    virtual void _v0F(); virtual void _v10(); virtual void _v11(); virtual void _v12(); virtual void _v13();
    virtual void _v14(); virtual void _v15(); virtual void _v16(); virtual void _v17();
    virtual void Hide(void* w);
};
struct S_463160 { char pad0[0x250]; void* f250; };
extern "C" {
extern char D_004C2780[];
extern char D_004C2798[];
Ui_463160* Gui_GetScreenStack(void);
void* Gui_GetScreenList(void);
void* func_00418A80(void* a, char* b, char* c);
void GuiStack_SwapScreens(void* ui, S_463160* self, void* pg);
int func_0035AEC0(S_463160* self, Ev_463160* ev);
}
static inline unsigned char Down_463160(Ev_463160* e)
{
    unsigned char r = 0;
    if (e->type == 1 && e->f2 == 0)
        r = 1;
    return r;
}
static inline unsigned char Btn_463160(Ev_463160* e, unsigned int b)
{
    unsigned char r = 0;
    if (Down_463160(e) && e->btn == b)
        r = 1;
    return r;
}
static inline unsigned char Press_463160(Ev_463160* e, unsigned int b)
{
    unsigned char r = 0;
    if (Btn_463160(e, b) && e->f6 == 0)
        r = 1;
    return r;
}
extern "C" int func_00463160(S_463160* self, Ev_463160* ev)
{
    if (Press_463160(ev, 0x800))
        return 1;
    {
        bool b = ev->type == 1 && ev->f2 == 0 && ev->btn == 0x10 && ev->f6 == 0;
        if (b)
            return 1;
    }
    {
        bool b = ev->type == 1 && ev->f2 == 0 && ev->btn == 0x40 && ev->f6 == 0;
        if (b) {
            void* pg;
            Gui_GetScreenStack()->Hide(self->f250);
            pg = func_00418A80(Gui_GetScreenList(), D_004C2780, D_004C2798);
            GuiStack_SwapScreens(Gui_GetScreenStack(), self, pg);
            return 1;
        }
    }
    return func_0035AEC0(self, ev);
}
