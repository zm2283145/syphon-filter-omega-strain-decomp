/*
 * main/hud: range (2 files, 00241DA0-00241E30)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
#include "SFOLobby_helpers.h"

/* merge_units: begin func_00241DA0 */
#pragma push /* merge_units */
typedef struct { char flag; char name[16]; char value[16]; } Entry21; /* size 0x21 */
typedef struct { int unk0; int count; Entry21* data; } EntryVec;
extern void* Gui_GetScreenStack(void);
extern void GuiWidget_SendEvent(void* a, void* b, int a2, int a3, int a4);
extern void func_002469F0(EntryVec* v, Entry21* pos, int n, Entry21* value);

/* Appends a (name, value) entry to the vector after notifying the UI. */
void Hud_AddPdaQuip(EntryVec* self, const char* value, const char* name)
{
    Entry21 e;
    void* ui;
    String_Copy(e.value, value);
    String_Copy(e.name, name);
    e.flag = 0;
    ui = Gui_GetScreenStack();
    GuiWidget_SendEvent(ui, Gui_GetScreenStack(), 0x10, 5, 0);
    func_002469F0(self, self->data + self->count, 1, &e);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00241DA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00241DA0 */

/* merge_units: begin func_00241E30 */
#pragma push /* merge_units */
typedef struct Color4 {
    float r, g, b, a;
} Color4;

typedef struct Obj6E4 {
    char pad[0x6E4];
    Color4* color;
} Obj6E4;

extern Color4 g_HudTextColour;
extern Color4 g_NvHudTextColour;
extern float g_TextColourBlock;
extern float D_0055A284;
extern float D_0055A288;
extern float D_0055A28C;
extern void Hud_SelectColourRamp(int);

/* Selects one of two color presets and publishes it to the global color. */
void Hud_SelectTextColorTable(Obj6E4* o, int alt) {
    Color4* c;
    Hud_SelectColourRamp(alt);
    o->color = alt ? &g_NvHudTextColour : &g_HudTextColour;
    c = o->color;
    g_TextColourBlock = c->r;
    D_0055A284 = c->g;
    D_0055A288 = c->b;
    D_0055A28C = c->a;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00241E30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00241E30 */
