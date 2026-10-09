/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiAgentCreate.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "GuiAgentCreate_types.h"

extern char D_0055DDA0[];
extern int func_00403310(void* p);
extern void func_0040F540(void);
extern GuiManagerState* func_004147A0(void);
extern int func_0041EBF0(void* self);
extern int func_0041F090(void* self);

int func_0028EC00(void* self) {
    func_00403310(D_0055DDA0);
    func_0040F540();
    return func_0041F090(self);
}

/* Calls the base handler, then clears bits 2-3 of the gui manager flags. */
GuiManagerState* func_0028EC40(void* self) {
    GuiManagerState* gui;

    func_0041EBF0(self);
    gui = func_004147A0();
    gui->flags &= ~12;
    return gui;
}
