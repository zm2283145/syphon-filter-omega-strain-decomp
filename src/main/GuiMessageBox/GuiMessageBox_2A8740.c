/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

extern char D_004AB5B0[];   /* "%s%d" */
extern char D_004DD9D0[];   /* GuiMessageBox vtable */
extern int sprintf(char* buf, const char* fmt, ...); /* sprintf */
extern void GuiWidget_ctor(GuiWidget* self);

/* Formats prefix followed by a number into buf; returns buf. */
char* func_002A8740(char* prefix, int n, char* buf) {
    sprintf(buf, D_004AB5B0, prefix, n);
    return buf;
}

/* GuiMessageBox constructor. */
GuiMessageBox* GuiMessageBox_ctor(GuiMessageBox* self) {
    GuiWidget_ctor(&self->base);
    self->base.vtable = D_004DD9D0;
    self->unk58 = 0;
    self->unk5C = 0;
    self->unk60 = 0;
    self->unk64 = 0;
    self->unk68 = 0;
    self->unk6C = 0;
    self->unk70 = 0;
    self->unk74 = 0;
    self->unk78 = 0;
    self->unk7C = 0;
    self->unk80 = 0;
    self->unk84 = 0;
    self->unk88 = 0;
    self->unk8C = 0;
    self->unk90 = 0;
    self->unk48 = 0;
    self->unk4C = 0;
    self->unk50 = 0;
    self->unk54 = 0;
    return self;
}
