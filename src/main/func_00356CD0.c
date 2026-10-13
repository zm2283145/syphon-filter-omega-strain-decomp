#include "types.h"
#pragma cplusplus on
#include "vslot_pad.h"
struct Col_356CD0 { float r, g, b, a; };
struct QCol_356CD0 { float r, g, b, a; } __attribute__((aligned(16)));
struct S_356CD0;
class W_356CD0 {
public:
    VPAD16(a) VPAD4(b)
    virtual bool IsA(void* type);
    char pad[0x84]; W_356CD0* link88; W_356CD0* link8C; char pad90[0x20]; Col_356CD0 cB0; Col_356CD0 cC0; Col_356CD0 cD0;
};
struct S_356CD0 { char pad[0x48]; W_356CD0* w48; W_356CD0* w4C; W_356CD0* w50; W_356CD0* w54; W_356CD0* w58; W_356CD0* w5C; };
extern "C" {
extern char* D_00492C80;
extern char* D_00492C88;
extern char* D_00492C90;
extern char* D_00492C98;
extern char* D_00492CA0;
extern char* D_00492CA8;
extern char* D_00492CB0;
extern char D_004A7520[];
extern char D_004AA640[];
extern char D_004AAE00[];
extern char D_004B88F0[];
extern char D_004BB3D0[];
extern char D_004FFB50[];
extern QCol_356CD0 D_00587BA0;
extern QCol_356CD0 D_00587BB0;
extern QCol_356CD0 D_00587BC0;
void func_0041F150(S_356CD0* o);
W_356CD0* GuiWidget_FindChildByName(void* self, char* name);
void func_0041BEB0(W_356CD0* w, char* text, int flags);
int Agent_GetSelected(void* a, int i);
char* func_00336170(int agent);
void func_00356CD0(S_356CD0* o);
}
static inline W_356CD0* cast_356CD0(W_356CD0* w, char* type)
{
    return (w && w->IsA(type)) ? w : 0;
}
static inline void Put_356CD0(Col_356CD0* d, QCol_356CD0 c) { d->r = c.r; d->g = c.g; d->b = c.b; d->a = c.a; }
void func_00356CD0(S_356CD0* o)
{
    W_356CD0* w;
    func_0041F150(o);
    o->w48 = cast_356CD0(GuiWidget_FindChildByName(o, D_00492C88), D_004AA640);
    o->w5C = cast_356CD0(GuiWidget_FindChildByName(o, D_00492CA0), D_004BB3D0);
    o->w54 = cast_356CD0(GuiWidget_FindChildByName(o, D_00492CA8), D_004B88F0);
    o->w58 = cast_356CD0(GuiWidget_FindChildByName(o, D_00492CB0), D_004A7520);
    o->w4C = GuiWidget_FindChildByName(o, D_00492C90);
    if (o->w48) {
        o->w48->link88 = o->w4C;
        Put_356CD0(&o->w48->cB0, D_00587BA0);
        Put_356CD0(&o->w48->cC0, D_00587BB0);
        Put_356CD0(&o->w48->cD0, D_00587BC0);
        if (o->w48) o->w48->link8C = cast_356CD0(GuiWidget_FindChildByName(o, "vscrollbar"), D_004AAE00);
    }
    o->w50 = cast_356CD0(GuiWidget_FindChildByName(o, D_00492C98), D_004B88F0);
    w = cast_356CD0(GuiWidget_FindChildByName(o, D_00492C80), D_004A7520);
    if (w) func_0041BEB0(w, func_00336170(Agent_GetSelected(D_004FFB50, -1)), 0);
}