#include "types.h"
#pragma cplusplus on
#include "vslot_pad.h"
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
void func_0041BEB0(W_35AEC0* w, char* text, int flags);
void func_00456160(S_35AEC0* o);
void func_00456100(S_35AEC0* o);
int func_0035AEC0(S_35AEC0* o, Ev_35AEC0* ev);
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
int func_0035AEC0(S_35AEC0* o, Ev_35AEC0* ev)
{
    if (Plain_35AEC0(ev, 0x10)) {
        W_35AEC0* a;
        W_35AEC0* b;
        W_35AEC0* c;
        if (o->a224 == 0) {
            func_00456160(o);
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
            func_0041BEB0(c, t ? t : D_004BB530, 0);
        }
        return 1;
    }
    if (Plain2_35AEC0(ev, 0x800) && D_004FFC2C->b6A8) {
        func_00456100(o);
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