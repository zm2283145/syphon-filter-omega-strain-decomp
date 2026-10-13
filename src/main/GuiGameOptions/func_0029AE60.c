#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
struct Ctl_29AE60 { VPAD16(a) VPAD2(b) VPAD1(c) virtual unsigned char IsLocal(); };
struct Plr_29AE60 { char pad[0xC]; unsigned int flags; char pad10[4]; unsigned char b14; char pad15[0x43]; Ctl_29AE60* ctl; };
struct Menu_29AE60 { char pad[0x54]; int sel; char pad58[0x3C]; int count; };
struct Wid_29AE60 { char pad[0x14]; unsigned short flags; };
struct Mgr_29AE60 { char pad[0x20]; Menu_29AE60* active; };
struct Self_29AE60 { char pad[0xA4]; int fA4; Wid_29AE60* fA8; char padAC[0x430 - 0xAC]; Menu_29AE60* menu; Wid_29AE60* w434; };
extern "C" {
extern unsigned char D_005721C8;
Plr_29AE60* PlayerSlots_Get(int i);
void func_00299800(Self_29AE60* self);
int func_0029BDB0(void);
void func_002C9270(char* buf, Plr_29AE60* p, int idx, int x);
Mgr_29AE60* func_004147A0(void);
void func_00414B30(Mgr_29AE60* m, int x);
void func_00421070(Menu_29AE60* m);
void func_00421290(Menu_29AE60* m, char* s, int idx, int x);
void func_00424430(Menu_29AE60* m, int a, int sel);
}
static inline unsigned char IsLocal_29AE60(Plr_29AE60* p) { unsigned char r = 0; if (p->ctl && p->ctl->IsLocal()) r = 1; return r; }
static inline int LocalId_29AE60(Plr_29AE60* p) { int id; if (D_005721C8) { if (IsLocal_29AE60(p)) id = ((p->flags & 0x7F000000) >> 24) - 1; else id = -1; } else id = 0; return id; }
static inline void SetFlag_29AE60(Wid_29AE60* w, unsigned short bit, unsigned char on) { if (on) w->flags |= bit; else w->flags &= ~bit; }
extern "C" void func_0029AE60(Self_29AE60* self)
{
    int i;
    Plr_29AE60* p;
    int sel;
    if (self->menu == 0) return;
    if (func_0029BDB0() < 2) {
        func_00299800(self);
        if (self->fA8 != 0) {
            self->fA8->flags &= ~4;
        }
        func_00414B30(func_004147A0(), self->fA4);
        return;
    }
    sel = self->menu->sel;
    func_00421070(self->menu);
    for (i = 0; i < 4; i++) {
        p = PlayerSlots_Get(i);
        if (p != 0 && p->b14 == 0) {
            int id = LocalId_29AE60(p);
            if (id >= 0 && id < 4) {
                char buf[0x90];
                buf[0] = 0;
                func_002C9270(buf, p, id, 0);
                func_00421290(self->menu, buf + 1, id, 0);
            }
        }
    }
    func_00424430(self->menu, 0, sel < self->menu->count ? sel : 0);
    if (self->w434 != 0) {
        unsigned char on = 0;
        Mgr_29AE60* g = func_004147A0();
        Menu_29AE60* m = self->menu;
        if (g->active == m && m->count != 0) on = 1;
        SetFlag_29AE60(self->w434, 2, on);
    }
}


