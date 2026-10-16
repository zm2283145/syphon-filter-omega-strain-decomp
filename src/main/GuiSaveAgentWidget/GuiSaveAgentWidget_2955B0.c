/*
 * main/GuiSaveAgentWidget: 2 files, 002955B0-00295640
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002955B0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


struct VC002955B0 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual int v21(...); };
extern "C" {
char * Agent_GetSelected(...);                    
int GuiSaveAgentWidget_HandleEvent(...);                            
extern char D_004FFB50;
}
extern "C" void GuiCommandCenter_Exit(char * arg0) {
    int var_v1;
    char * temp_v0;

    F_(arg0, 0x2F4, signed char) = 1;
    temp_v0 = Agent_GetSelected(&D_004FFB50, -1);
    var_v1 = F_(temp_v0, 0xB73, unsigned char) != 0;
    if (var_v1 == 0) {
        var_v1 = F_(temp_v0, 0xB72, unsigned char) != 0;
    }
    if (var_v1 != 0) {
        F_(arg0, 0x4C, signed char) = 2;
        GuiSaveAgentWidget_HandleEvent(arg0);
        return;
    }
    ((VC002955B0 *)(arg0))->v21(1);
}
#pragma pop /* merge_units */
/* merge_units: end func_002955B0 */

/* merge_units: begin func_00295640 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Ev_00295640 { unsigned short type; unsigned short f2; unsigned short f4; unsigned short f6; unsigned short btn; };
struct Ui_00295640 { char pad[0x30]; unsigned char b30; char pad31; unsigned char b32; };
struct S_00295640 {
    char pad0[0x118]; void* p118[0x18]; unsigned char b178[0x3C]; signed char c1B4[0x18]; int f1CC; char pad1D0[4]; unsigned char b1D4;
    char pad1D5[0x2E0 - 0x1D5]; int f2E0; int f2E4; char pad2E8[0x2F8 - 0x2E8]; int f2F8;
};
extern "C" {
extern Ui_00295640* D_004FFC04;
extern char D_004AA288[];
void GuiCommandCenter_OpenPanel(S_00295640* self, int a);
void GuiCommandCenter_MoveSelection(S_00295640* self, unsigned char a);
void* Gui_GetScreenStack(void);
void func_0041E0F0(void* a, void* b, int c, int d, int e);
int func_0033CE30(S_00295640* self, int a, int b, int c, int d, int e);
int FrontEnd_OpenPopup(void* ui, int a, char* b, int c, S_00295640* d, int e);
#if 0 /* merge_units */
void GuiCommandCenter_Exit(S_00295640* self);
#endif /* merge_units */
#define GuiCommandCenter_Exit(a0) ((void)GuiCommandCenter_Exit((char *)(a0))) /* merge_units */

int GuiScreen_HandleInput(S_00295640* self, Ev_00295640* ev);
}
extern "C" int GuiCommandCenter_HandleInput(S_00295640* self, Ev_00295640* ev)
{
    bool down = ev->type == 1 && ev->f2 == 0 && ev->f6 == 0;
    if (down) {
        unsigned short b = ev->btn;
        switch (b) {
        case 4:
        case 8:
            if (self->b1D4)
                GuiCommandCenter_OpenPanel(self, 0);
            GuiCommandCenter_MoveSelection(self, ev->btn == 4 ? 4 : 8);
            return 1;
        }
        if (b == 0x40 && !self->b1D4 && self->f1CC != -1) {
            if (self->b178[self->f1CC])
                GuiCommandCenter_OpenPanel(self, self->c1B4[self->f1CC]);
            else
                func_0041E0F0(self->p118[self->f1CC], Gui_GetScreenStack(), 0x10, 4, 0);
            return 1;
        }
        if (b == 0x10) {
            unsigned char st = self->b1D4;
            if (st == 4) {
                self->f2E0 = 0;
                if (self->f1CC == 0x14)
                    GuiCommandCenter_OpenPanel(self, 0);
                else
                    GuiCommandCenter_OpenPanel(self, 1);
                return 1;
            }
            if (st == 5) {
                self->f2E4 = 0;
                GuiCommandCenter_OpenPanel(self, 4);
                return 1;
            }
            if (st == 0) {
                Ui_00295640* ui = D_004FFC04;
                if (ui->b30 && !ui->b32)
                    self->f2F8 = FrontEnd_OpenPopup(ui, 5, D_004AA288, func_0033CE30(self, 0xE, 0, 0, 0, 0), self, 0x19);
                else
                    GuiCommandCenter_Exit(self);
            } else {
                GuiCommandCenter_OpenPanel(self, 0);
            }
            return 1;
        }
    }
    return GuiScreen_HandleInput(self, ev);
}
#undef GuiCommandCenter_Exit /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00295640 */
