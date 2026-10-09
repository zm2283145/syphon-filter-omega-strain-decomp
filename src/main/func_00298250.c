/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

extern unsigned char D_0048B7A0;
extern int D_0048B7A4;
extern unsigned char D_0048B7A8;
extern unsigned char D_0048B7C8;
extern unsigned char D_0048B7E8;
extern unsigned char D_0048B808;
extern unsigned char D_0048B828;
extern unsigned char D_0048B848;
extern int func_00294300(GuiCommandCenter* self, int arg);
extern void func_00294AB0(GuiCommandCenter* self);
extern int func_00295090(GuiCommandCenter* self, int selection, int arg);
extern int func_002952C0(GuiCommandCenter* self);
extern void func_00298310(void);
extern void func_00298360(GuiCommandCenter* self);

/* Refreshes the screen, picking a default selection when none is set. */
int func_00298250(GuiCommandCenter* self) {
    func_00298360(self);
    if (self->selection == -1) {
        func_00294AB0(self);
        self->selection = func_002952C0(self);
    }
    func_00295090(self, self->selection, 0);
    return func_00294300(self, self->unk1D4);
}

/* Resets the selection state and the shared globals. */
void func_002982C0(GuiCommandCenter* self) {
    func_00298310();
    self->selection = -1;
    self->unk2D0 = 0;
    self->unk2D4 = 0;
    self->unk2D8 = 0;
    self->unk2DC = 0;
    self->unk2E0 = 0;
    self->unk2E4 = 0;
}

/* Clears the shared text buffers and index. */
void func_00298310(void) {
    D_0048B7A0 = 0;
    D_0048B7A8 = 0;
    D_0048B7A4 = -1;
    D_0048B7C8 = 0;
    D_0048B7E8 = 0;
    D_0048B808 = 0;
    D_0048B828 = 0;
    D_0048B848 = 0;
}
