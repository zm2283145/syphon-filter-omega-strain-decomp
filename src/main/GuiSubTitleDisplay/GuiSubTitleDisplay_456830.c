/*
 * main/GuiSubTitleDisplay: 4 files, 00456830-00456AB0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00456830 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
struct VObj45 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(void*); };
struct Ev45 { char p[0x10]; int id; };
struct Mgr45 { char p[0x20]; Ev45* sel; };
struct W456830 { char p[0xB0]; int id; };
extern "C" {
extern char D_004C1C60[];
extern char D_004C1C70[];
extern char D_004C1A38[];
extern char D_004A7520[];
extern unsigned char D_004FFBA0;
extern int D_004FFC2C;
extern char D_004FFB50[];
VObj45* GuiWidget_FindChildByName(W456830*, char*);
int sprintf(char*, const char*, ...);
char* Loc_LookupText(char*);
void GuiTextWidget_SetText(VObj45*, char*, int);
Mgr45* Gui_GetScreenStack(void);
void GuiStartMenu_SelectButton(W456830*, int);
void Hud_ClosePauseMenu(int);
void Game_EndLevel(void*, int);
void Game_SetPaused(void*, int);
int GuiObjectives_HandleEvent(W456830*, Ev45*, int, int, int);
}

extern "C" int GuiStartMenu_OnEvent(W456830* self, Ev45* ev, int code, int a3, int a4)
{
    unsigned short c = code;
    if (c == 0) {
        int id = ev->id;
        if (id != -1) {
            VObj45* o;
            char buf[16];
            self->id = id;
            o = GuiWidget_FindChildByName(self, D_004C1C60);
            o = (o != 0 && o->v20(D_004A7520) != 0) ? o : 0;
            if (o) {
                char* s;
                sprintf(buf, D_004C1C70, id);
                s = Loc_LookupText(buf);
                if (s) GuiTextWidget_SetText(o, s, 0);
                else GuiTextWidget_SetText(o, D_004C1A38, 0);
            }
            return 1;
        }
    }
    if (c == 2) {
        int x; if (Gui_GetScreenStack()->sel) x = Gui_GetScreenStack()->sel->id; else {
            asm { .set reorder } /* barrier: keeps the else block out of the beqz delay slot */
            x = -1;
        }
        if (x != -1) {
            GuiStartMenu_SelectButton(self, x);
            return 1;
        }
    }
    if (c == 0x1A && a3 == 0) {
        if (D_004FFBA0 != 0x13 && D_004FFBA0 != 0x14) {
            Hud_ClosePauseMenu(D_004FFC2C);
            Game_EndLevel(D_004FFB50, 2);
            Game_SetPaused(D_004FFB50, 0);
        }
        return 1;
    }
    return GuiObjectives_HandleEvent(self, ev, code, a3, a4);
}
#pragma pop /* merge_units */
/* merge_units: end func_00456830 */

/* merge_units: begin func_00456A30 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies before GuiSubTitleDisplay.cc (starts 0x00457AA0).
 */

#include "loose05_types.h"

extern int func_0041EBF0(void* self);

/* Shutdown: base shutdown, then clears the handle at +0x10. */
int GuiStartMenu_OnSleep(GuiWidget* self) {
    int ret;

    ret = func_0041EBF0(self);
    self->unk10 = -1;
    return ret;
}
#pragma pop /* merge_units */
/* merge_units: end func_00456A30 */

/* merge_units: begin func_00456A60 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int GuiWidget_FocusFirst(void);
typedef struct { char pad[0x10]; int idx; char pad2[0x7C]; int tab[1]; } S456;
int func_00456A60(S456 *p) {
    int i = p->idx;
    if (i != -1) {
        int r = p->tab[i];
        p->idx = -1;
        return r;
    }
    return GuiWidget_FocusFirst();
}
#pragma pop /* merge_units */
/* merge_units: end func_00456A60 */

/* merge_units: begin func_00456AB0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct VObj_456AB0 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(void*); };
struct C_456AB0 { char p[0x14]; unsigned short flags; };
struct W_456AB0 { char p[0x10]; int focus; char p14[0x8C - 0x14]; C_456AB0* f8C; void* items[8]; int id; };
extern "C" {
extern unsigned char D_004FFBB7;
void GuiObjectives_Wake(W_456AB0*);
#if 0 /* merge_units */
VObj_456AB0* GuiWidget_FindChildByName(W_456AB0*, char*);
#endif /* merge_units */
#define GuiWidget_FindChildByName(a0, a1) ((VObj_456AB0 *)GuiWidget_FindChildByName((W456830 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void GuiTextWidget_SetText(VObj_456AB0*, char*, int);
#endif /* merge_units */
#define GuiTextWidget_SetText(a0, a1, a2) (GuiTextWidget_SetText((VObj45 *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
void* Gui_GetScreenStack(void);
#endif /* merge_units */
#define Gui_GetScreenStack() ((void *)Gui_GetScreenStack()) /* merge_units */

void GuiScreen_SetFocus(void*, void*);
}

extern "C" void GuiStartMenu_OnWake(W_456AB0* self)
{
    VObj_456AB0* o;
    char buf[16];
    GuiObjectives_Wake(self);
    self->id = 0;
    o = GuiWidget_FindChildByName(self, D_004C1C60);
    o = (o != 0 && o->v20(D_004A7520) != 0) ? o : 0;
    if (o) {
        char* s;
        sprintf(buf, D_004C1C70, 0);
        s = Loc_LookupText(buf);
        if (s) GuiTextWidget_SetText(o, s, 0);
        else GuiTextWidget_SetText(o, D_004C1A38, 0);
    }
    if (self->focus != -1)
        GuiScreen_SetFocus(Gui_GetScreenStack(), self->items[self->focus]);
    if (self->f8C) {
        if (D_004FFBB7) self->f8C->flags |= 2;
        else self->f8C->flags &= ~2;
    }
}
#undef GuiWidget_FindChildByName /* merge_units */
#undef GuiTextWidget_SetText /* merge_units */
#undef Gui_GetScreenStack /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00456AB0 */
