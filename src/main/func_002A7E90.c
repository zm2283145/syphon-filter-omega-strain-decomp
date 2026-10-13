#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
struct W7E { char p0[0x14]; unsigned short flags; };
struct E7E { W7E* w0; W7E* w4; W7E* w8; W7E* wC; W7E* w10; };
class S7E {
public:
    VPAD8(a) VPAD4(b) VPAD2(c) VPAD1(d) virtual W7E* DefFocus();
    char p4[0x10];
    unsigned short flags;
    char p16[0xA];
    W7E* focus;
    char p24[0x24];
    int mode;
    int x4C;
    int x50;
    int sel;
    E7E e[3];
};
class St7E;
extern "C" {
extern char* D_0048BB90;
extern char* D_0048BB98;
extern char* D_0048BBA0;
extern char* D_0048BBA8;
extern const unsigned int D_004AB580[4];
char* Loc_LookupText(char* key);
void func_0041BEB0(W7E* w, char* text, int flags);
St7E* Gui_GetScreenStack(void);
void GuiScreen_SetFocus(St7E* s, W7E* w);
void func_0041E0F0(S7E* o, St7E* s, int a, int b, int c);
}
extern "C" void func_002A7E90(S7E* self, int mode, char* t1, char* t2, int a4, int a5)
{
    E7E* e;
    W7E* w;
    self->mode = mode;
    self->x4C = a4;
    self->x50 = a5;
    if (mode == 6) {
        int i;
        for (i = 0; i < 3; i++) {
            if (self->e[i].w0) {
                w = self->e[i].w0;
                if (i == 2) w->flags |= 2; else w->flags &= (unsigned short)~2;
                w = self->e[i].w0;
                if (i == 2) w->flags |= 4; else w->flags &= ~4;
            }
        }
        self->sel = 2;
    } else if (t1 && *t1) {
        int i;
        for (i = 0; i < 3; i++) {
            if (self->e[i].w0) {
                w = self->e[i].w0;
                if (i == 1) w->flags |= 2; else w->flags &= (unsigned short)~2;
                w = self->e[i].w0;
                if (i == 1) w->flags |= 4; else w->flags &= ~4;
            }
        }
        self->sel = 1;
    } else {
        int i;
        for (i = 0; i < 3; i++) {
            if (self->e[i].w0) {
                w = self->e[i].w0;
                if (i == 0) w->flags |= 2; else w->flags &= (unsigned short)~2;
                w = self->e[i].w0;
                if (i == 0) w->flags |= 4; else w->flags &= ~4;
            }
        }
        self->sel = 0;
    }
    e = &self->e[self->sel];
    if (e->wC && e->w10) {
        switch (self->mode) {
        case 0:
        case 1:
            e->wC->flags &= ~2;
            e->w10->flags &= ~2;
            break;
        case 2:
            e->wC->flags |= 2;
            func_0041BEB0(e->wC, Loc_LookupText(D_0048BB90), 0);
            e->w10->flags &= (unsigned short)~2;
            break;
        case 4:
        case 5:
            e->wC->flags |= 2;
            func_0041BEB0(e->wC, Loc_LookupText(D_0048BB98), 0);
            e->w10->flags |= 2;
            func_0041BEB0(e->w10, Loc_LookupText(D_0048BBA0), 0);
            break;
        case 6:
            e->wC->flags |= 2;
            func_0041BEB0(e->wC, Loc_LookupText(D_0048BB90), 0);
            e->w10->flags |= 2;
            func_0041BEB0(e->w10, Loc_LookupText(D_0048BBA8), 0);
            break;
        default:
            e->wC->flags |= 2;
            func_0041BEB0(e->wC, Loc_LookupText(D_0048BB90), 0);
            e->w10->flags |= 2;
            func_0041BEB0(e->w10, Loc_LookupText(D_0048BBA8), 0);
            break;
        }
    }
    e = &self->e[self->sel];
    if (e->w4) func_0041BEB0(e->w4, t1 ? t1 : (t1 = (char*)D_004AB580), 0);
    if (e->w8) func_0041BEB0(e->w8, t2 ? t2 : (t2 = (char*)D_004AB580), 0);
    if (self->flags & 8) {
        if (self->mode == 5) self->focus = self->e[self->sel].w10;
        else self->focus = self->DefFocus();
        GuiScreen_SetFocus(Gui_GetScreenStack(), self->focus);
        func_0041E0F0(self, Gui_GetScreenStack(), 0x10, 2, 0);
    }
}
