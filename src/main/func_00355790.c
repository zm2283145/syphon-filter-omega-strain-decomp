/*
 * Matched functions (byte-identical with the retail executable).
 * GuiPersonnelMenu virtual (vtable D_004DF020 slot 5).
 */

#include "loose03_types.h"

extern void func_00356C70(GuiPersonnelScreen*);   /* GuiPersonnelScreen slot 5 */
extern int func_0036B250(int);                      /* mem.cc */
extern int func_0036B3B0(int, int, int);            /* mem.cc */

/* Calls the base implementation, then two mem.cc functions. */
int func_00355790(GuiPersonnelScreen* self) {
    func_00356C70(self);
    func_0036B250(1);
    return func_0036B3B0(1, 0x100000, 2048);
}
