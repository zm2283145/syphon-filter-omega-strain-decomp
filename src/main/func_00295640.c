#pragma cplusplus on
#include "types.h"
struct Ev_00295640 { unsigned short type; unsigned short f2; unsigned short f4; unsigned short f6; unsigned short btn; };
struct Ui_00295640 { char pad[0x30]; unsigned char b30; char pad31; unsigned char b32; };
struct S_00295640 {
    char pad0[0x118]; void* p118[0x18]; unsigned char b178[0x3C]; signed char c1B4[0x18]; int f1CC; char pad1D0[4]; unsigned char b1D4;
    char pad1D5[0x2E0 - 0x1D5]; int f2E0; int f2E4; char pad2E8[0x2F8 - 0x2E8]; int f2F8;
};
extern "C" {
extern Ui_00295640* D_004FFC04;
extern char D_004AA288[];
void func_00294300(S_00295640* self, int a);
void func_00294F50(S_00295640* self, unsigned char a);
void* Gui_GetScreenStack(void);
void func_0041E0F0(void* a, void* b, int c, int d, int e);
int func_0033CE30(S_00295640* self, int a, int b, int c, int d, int e);
int FrontEnd_OpenPopup(void* ui, int a, char* b, int c, S_00295640* d, int e);
void func_002955B0(S_00295640* self);
int func_0033CEF0(S_00295640* self, Ev_00295640* ev);
}
extern "C" int func_00295640(S_00295640* self, Ev_00295640* ev)
{
    bool down = ev->type == 1 && ev->f2 == 0 && ev->f6 == 0;
    if (down) {
        unsigned short b = ev->btn;
        switch (b) {
        case 4:
        case 8:
            if (self->b1D4)
                func_00294300(self, 0);
            func_00294F50(self, ev->btn == 4 ? 4 : 8);
            return 1;
        }
        if (b == 0x40 && !self->b1D4 && self->f1CC != -1) {
            if (self->b178[self->f1CC])
                func_00294300(self, self->c1B4[self->f1CC]);
            else
                func_0041E0F0(self->p118[self->f1CC], Gui_GetScreenStack(), 0x10, 4, 0);
            return 1;
        }
        if (b == 0x10) {
            unsigned char st = self->b1D4;
            if (st == 4) {
                self->f2E0 = 0;
                if (self->f1CC == 0x14)
                    func_00294300(self, 0);
                else
                    func_00294300(self, 1);
                return 1;
            }
            if (st == 5) {
                self->f2E4 = 0;
                func_00294300(self, 4);
                return 1;
            }
            if (st == 0) {
                Ui_00295640* ui = D_004FFC04;
                if (ui->b30 && !ui->b32)
                    self->f2F8 = FrontEnd_OpenPopup(ui, 5, D_004AA288, func_0033CE30(self, 0xE, 0, 0, 0, 0), self, 0x19);
                else
                    func_002955B0(self);
            } else {
                func_00294300(self, 0);
            }
            return 1;
        }
    }
    return func_0033CEF0(self, ev);
}