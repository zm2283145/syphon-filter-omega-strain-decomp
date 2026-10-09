/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies after GuiGameScreen.cc (ends 0x0045F090).
 */

#include "loose05_types.h"

extern char D_004C2460[]; /* resource name */
extern int func_00414790(void);
extern int func_004147A0(void);
extern void func_00414AC0(int mgr, void* owner, int res);
extern int func_00419530(int a0, int res);
extern int func_0041EFA0(void* self);
extern int func_0041F960(char* name);
extern int func_00441A10(void* self);

void func_0045F300(void* self) {
    func_00414AC0(func_004147A0(), self, 0);
}

int func_0045F340(GuiWidget45F340* self) {
    func_0041EFA0(self);
    self->unk4C = 2;
    return func_00441A10(self);
}

/* Looks up the named resource and, if found, registers it for this owner. */
void func_0045F380(void* self) {
    int res;

    res = func_0041F960(D_004C2460);
    if (res != 0) {
        func_00419530(func_00414790(), res);
        func_00414AC0(func_004147A0(), self, res);
    }
}
