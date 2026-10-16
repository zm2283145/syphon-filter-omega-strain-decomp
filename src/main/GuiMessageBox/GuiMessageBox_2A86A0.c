/*
 * main/GuiMessageBox: 4 files, 002A86A0-002A8800
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002A86A0 */
#pragma push /* merge_units */
#include "types.h"

extern void func_0041EBF0(void* self);
extern int Gui_GetScreenStack(void);
extern void GuiWidget_SendEvent(void* self, int a, int b, int c, int d);

/* Runs the base setup, then calls GuiWidget_SendEvent with Gui_GetScreenStack's result and constants 0x10, 3, 0. */
void GuiMessageBox_Sleep(void* self)
{
    func_0041EBF0(self);
    GuiWidget_SendEvent(self, Gui_GetScreenStack(), 0x10, 3, 0);
}
#pragma pop /* merge_units */
/* merge_units: end func_002A86A0 */

/* merge_units: begin func_002A86F0 */
#pragma push /* merge_units */
typedef struct Entry20 {
    int value;
    int pad[4];
} Entry20;

typedef struct Selector {
    char pad[0x20];
    int current;
    char pad2[0x48 - 0x24];
    int state;
    char pad3[0x54 - 0x4C];
    int index;
    char pad4[0x68 - 0x58];
    Entry20 entries[1];
} Selector;

extern void func_0041EFA0(Selector* self);

/* Updates the base, then in state 5 copies the selected entry's value to current. */
void GuiMessageBox_Wake(Selector* self) {
    func_0041EFA0(self);
    if (self->state == 5) {
        self->current = self->entries[self->index].value;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_002A86F0 */

/* merge_units: begin func_002A8740 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

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
#pragma pop /* merge_units */
/* merge_units: end func_002A8740 */

/* merge_units: begin func_002A8800 */
#pragma push /* merge_units */
typedef struct { char p0[0x14]; char set[1]; } Mgr2A8800;
#if 0 /* merge_units */
extern void* Gui_GetScreenStack(void);
#endif /* merge_units */
#define Gui_GetScreenStack() ((void *)Gui_GetScreenStack()) /* merge_units */

extern Mgr2A8800* Gui_GetScreenList(void);
extern void func_002A88C0(int* it, void* set, int* key);
extern void func_002A88B0(int* it, void* set);
extern int func_002A8890(int* a, int* b);
/* Returns o when it is the root widget or is registered with the manager, else 0. */
void* GuiMessageBox_ValidateTarget(void* o)
{
    Mgr2A8800* m;
int key[1];
int it[1];
int end[1];
    if (!o) return 0;
    if (o == Gui_GetScreenStack()) return o;
    key[0] = (int)o;
    m = Gui_GetScreenList();
    func_002A88C0(it, m->set, key);
    func_002A88B0(end, m->set);
    return func_002A8890(it, end) ? o : 0;
}
#undef Gui_GetScreenStack /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A8800 */
