/*
 * main/GuiScoresEquip: range (2 files, 0035AEC0-0035B210)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "vslot_pad.h"

/* merge_units: begin func_0035AEC0 */
#pragma push /* merge_units */
#pragma cplusplus on
class W_35AEC0 {
public:
    VPAD16(a) VPAD4(b)
    virtual bool IsA(void* type);
    char pad[0x10]; unsigned short a14;
};
struct S_35AEC0 { char pad[0x224]; int a224; float a228; };
struct Ev_35AEC0 { unsigned short type; unsigned short b2; char pad4[2]; unsigned short b6; unsigned short btn; };
struct G_35AEC0 { char pad[0x6A8]; unsigned char b6A8; };
extern "C" {
extern char D_004BB4D8[];
extern char D_004BB530[];
extern char D_004A9870[];
extern G_35AEC0* D_004FFC2C;
W_35AEC0* GuiWidget_FindChildByName(void* self, char* name);
char* Loc_LookupText(char* key);
void GuiTextWidget_SetText(W_35AEC0* w, char* text, int flags);
void GuiStartMenu_ReturnToMenu(S_35AEC0* o);
void GuiStartMenu_CloseAll(S_35AEC0* o);
int GuiScoresEquip_HandleInput(S_35AEC0* o, Ev_35AEC0* ev);
}
static inline W_35AEC0* cast_35AEC0(W_35AEC0* w)
{
    return (w && w->IsA(D_004A9870)) ? w : 0;
}
static inline unsigned char Down_35AEC0(Ev_35AEC0* e) { unsigned char r = 0; if (e->type == 1 && e->b2 == 0) r = 1; return r; }
static inline unsigned char Btn_35AEC0(Ev_35AEC0* e, int b) { unsigned char r = 0; if (Down_35AEC0(e) && e->btn == b) r = 1; return r; }
static inline unsigned char Plain_35AEC0(Ev_35AEC0* e, int b) { unsigned char r = 0; if (Btn_35AEC0(e, b) && e->b6 == 0) r = 1; return r; }

static inline bool Down2_35AEC0(Ev_35AEC0* e) { return e->type == 1 && e->b2 == 0; }
static inline bool Btn2_35AEC0(Ev_35AEC0* e, int b) { return Down2_35AEC0(e) && e->btn == b; }
static inline bool Plain2_35AEC0(Ev_35AEC0* e, int b) { return Btn2_35AEC0(e, b) && e->b6 == 0; }
static inline bool NoMod2_35AEC0(Ev_35AEC0* e) { return Down2_35AEC0(e) && e->b6 == 0; }
int GuiScoresEquip_HandleInput(S_35AEC0* o, Ev_35AEC0* ev)
{
    if (Plain_35AEC0(ev, 0x10)) {
        W_35AEC0* a;
        W_35AEC0* b;
        W_35AEC0* c;
        if (o->a224 == 0) {
            GuiStartMenu_ReturnToMenu(o);
            return 1;
        }
        o->a224 = 0;
        a = GuiWidget_FindChildByName(o, D_004BB4D8);
        b = GuiWidget_FindChildByName(o, "equipment_grp");
        if (a) a->a14 |= 2;
        if (b) b->a14 &= ~2;
        c = cast_35AEC0(GuiWidget_FindChildByName(o, "button_equip_score"));
        if (c) {
            char* t = Loc_LookupText("ScoresEquipScr0");
            GuiTextWidget_SetText(c, t ? t : D_004BB530, 0);
        }
        return 1;
    }
    if (Plain2_35AEC0(ev, 0x800) && D_004FFC2C->b6A8) {
        GuiStartMenu_CloseAll(o);
        return 1;
    }
    if (Btn2_35AEC0(ev, 2)) {
        o->a228 += NoMod2_35AEC0(ev) ? -1.0f : 1.0f;
        return 1;
    }
    if (Btn2_35AEC0(ev, 1)) {
        o->a228 += NoMod2_35AEC0(ev) ? 1.0f : -1.0f;
        return 1;
    }
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0035AEC0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0035AEC0 */

/* merge_units: begin func_0035B210 */
#pragma push /* merge_units */
#pragma cplusplus on
struct W_0035B210 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual int IsA(char* type);
};
struct B_0035B210 { char pad0[0x14]; unsigned short flags; };
struct S_0035B210 { char pad0[0x224]; int f224; };
extern "C" {
extern char D_004BB4E8[];
extern char D_004BB500[];
extern char D_004BB520[];
extern char D_004BB540[];
#if 0 /* merge_units */
void* GuiWidget_FindChildByName(void* self, char* name);
#endif /* merge_units */
#define GuiWidget_FindChildByName(a0, a1) ((void *)GuiWidget_FindChildByName((a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void GuiTextWidget_SetText(W_0035B210* w, char* s, int a);
#endif /* merge_units */
#define GuiTextWidget_SetText(a0, a1, a2) (GuiTextWidget_SetText((W_35AEC0 *)(a0), (a1), (a2))) /* merge_units */

int GuiWidget_OnEvent(void* self, int a, unsigned short b);
}
static inline W_0035B210* FindAs_0035B210(void* self, char* name, char* type)
{
    W_0035B210* w = (W_0035B210*)GuiWidget_FindChildByName(self, name);
    return (w && w->IsA(type)) ? w : 0;
}
extern "C" int GuiScoresEquip_HandleEvent(S_0035B210* self, int a, unsigned short b)
{
    if (b == 2) {
        int on = self->f224 == 0;
        B_0035B210* b1;
        B_0035B210* b2;
        W_0035B210* w;
        self->f224 = on;
        b1 = (B_0035B210*)GuiWidget_FindChildByName(self, D_004BB4D8);
        b2 = (B_0035B210*)GuiWidget_FindChildByName(self, D_004BB4E8);
        if (b1) {
            if (!on)
                b1->flags |= 2;
            else
                b1->flags &= ~2;
        }
        if (b2) {
            if (on)
                b2->flags |= 2;
            else
                b2->flags &= ~2;
        }
        w = FindAs_0035B210(self, D_004BB500, D_004A9870);
        if (w) {
            char* t = Loc_LookupText(on == 0 ? D_004BB520 : D_004BB540);
            GuiTextWidget_SetText(w, t ? t : D_004BB530, 0);
        }
        return 1;
    }
    return GuiWidget_OnEvent(self, a, b);
}
#undef GuiWidget_FindChildByName /* merge_units */
#undef GuiTextWidget_SetText /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0035B210(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0035B210 */
