#include "types.h"
#pragma cplusplus on
struct M_368300 { char pad[0x20]; void* focus; };
struct S_368300 { char pad[0x58]; int page; char pad5C[4]; void* w60; void* w64; void* w68; void* w6C; };
struct Ev_368300 { unsigned short type; unsigned short b2; char pad4[2]; unsigned short b6; unsigned short btn; };
struct G_368300 { char pad[0x6A8]; unsigned char b6A8; };
extern "C" {
extern G_368300* D_004FFC2C;
void func_00367B20(S_368300* o, int page, int f);
M_368300* Gui_GetScreenStack(void);
void GuiWidget_SendEvent(void* w, void* m, int kind, int v, int f);
void GuiStartMenu_ReturnToMenu(S_368300* o);
void GuiStartMenu_CloseAll(S_368300* o);
int GuiObjectives_HandleInput(S_368300* o, Ev_368300* ev);
}
static inline unsigned char Down_368300(Ev_368300* e) { unsigned char r = 0; if (e->type == 1 && e->b2 == 0) r = 1; return r; }
static inline unsigned char Btn_368300(Ev_368300* e, int b) { unsigned char r = 0; if (Down_368300(e) && e->btn == b) r = 1; return r; }
static inline unsigned char Plain_368300(Ev_368300* e, int b) { unsigned char r = 0; if (Btn_368300(e, b) && e->b6 == 0) r = 1; return r; }
static inline bool Down2_368300(Ev_368300* e) { return e->type == 1 && e->b2 == 0; }
static inline bool Btn2_368300(Ev_368300* e, int b) { return Down2_368300(e) && e->btn == b; }
static inline bool Plain2_368300(Ev_368300* e, int b) { return Btn2_368300(e, b) && e->b6 == 0; }

int GuiObjectives_HandleInput(S_368300* o, Ev_368300* ev)
{
    if (Plain_368300(ev, 0x2000)) {
        if (o->page == 0 && o->w64) {
            func_00367B20(o, 1, 0);
            GuiWidget_SendEvent(o->w6C, Gui_GetScreenStack(), 0x10, 0, 0);
        }
        return 1;
    }
    if (Plain2_368300(ev, 0x8000)) {
        if (o->page == 1 && o->w60) {
            func_00367B20(o, 0, 0);
            GuiWidget_SendEvent(o->w68, Gui_GetScreenStack(), 0x10, 0, 0);
        }
        return 1;
    }
    if (Plain2_368300(ev, 0x10)) {
        GuiStartMenu_ReturnToMenu(o);
        return 1;
    }
    if (Plain2_368300(ev, 0x800) && D_004FFC2C->b6A8) {
        GuiStartMenu_CloseAll(o);
        return 1;
    }
    if ((Plain2_368300(ev, 0x4000) || Plain2_368300(ev, 0x1000))
        && (Gui_GetScreenStack()->focus == o->w68 || Gui_GetScreenStack()->focus == o->w6C)) return 1;
    return 0;
}