/*
 * main/GuiPersonnelScreen: 8 files, 00356850-00356FF0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00356850 */
#pragma push /* merge_units */
typedef struct { char pad[0x14]; unsigned short flags; } W356850;
typedef struct { char pad[0x50]; W356850 *w50; W356850 *w54; W356850 *w58; W356850 *w5C; char pad2[4]; int x64; int x68; } S356850;
typedef struct { char pad[0x25C]; int f25C; } Cfg356850;
extern Cfg356850 *D_004FFC04;
char D_004BB2E8[] = "0_%d_%d.tdx";
char D_004BB2F8[] = "AB_SPECIAL_%d";
extern int sprintf(char *buf, const char *fmt, ...);
extern void GuiBitmapWidget_SetImage(W356850 *w, char *s, int v);
extern char *Loc_LookupText(char *key);
extern void GuiTextWidget_SetText(W356850 *w, char *s, int v);
extern void GuiWeaponDisplay_Set(W356850 *w, int n);
void GuiPersonnelScreen_ShowItem(S356850 *self, int a, int n)
{
    char buf[0x40];
    char buf2[0x40];
    if (n >= 10000) {
        if (self->w5C) self->w5C->flags &= ~2;
        if (self->w54) {
            self->w54->flags |= 2;
            sprintf(buf, D_004BB2E8, 7, n - 9999);
            GuiBitmapWidget_SetImage(self->w54, buf, D_004FFC04->f25C);
            if (self->w58) {
                char *t;
                self->w58->flags |= 2;
                sprintf(buf, D_004BB2F8, n - 10000);
                t = Loc_LookupText(buf);
                GuiTextWidget_SetText(self->w58, t ? t : "", 0);
            }
        }
    } else {
        if (self->w5C) {
            self->w5C->flags |= 2;
            GuiWeaponDisplay_Set(self->w5C, n);
        }
        if (self->w54) self->w54->flags &= ~2;
        if (self->w58) self->w58->flags &= ~2;
    }
    if (self->w50) {
        sprintf(buf2, "0_%d_%ds.tdx", self->x64, a + self->x68);
        GuiBitmapWidget_SetImage(self->w50, buf2, D_004FFC04->f25C);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00356850 */

/* merge_units: begin func_003569F0 */
#pragma push /* merge_units */
#include "types.h"
#pragma cplusplus on
#include "vslot_pad.h"
class S3569F0 {
public:
    VPAD16(a) VPAD2(b) VPAD1(c)
    virtual int f54();
    char s4[0xC];
};
extern "C" {
void* Gui_GetScreenList(void);
void* Gui_GetScreenStack(void);
int GuiManager_FindOrLoad(void* mgr, char* a, char* b);
char* String_CStr(void* str);
void GuiPersonnelMenu_Setup(int snd, int a, char* s, int b, int c, int d, int e);
void GuiStack_SwapScreens(void* mgr, void* self, int snd);
void GuiPersonnelScreen_OpenMenu(S3569F0* self, char* name, int b, int c, int d, int e);
}
void GuiPersonnelScreen_OpenMenu(S3569F0* self, char* name, int b, int c, int d, int e)
{
    int s = GuiManager_FindOrLoad(Gui_GetScreenList(), "GuiPersonnelMenu", name);
    if (s) {
        char* str = String_CStr(self->s4);
        GuiPersonnelMenu_Setup(s, self->f54(), str, b, c, d, e);
        GuiStack_SwapScreens(Gui_GetScreenStack(), self, s);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_003569F0 */

/* merge_units: begin func_00356AD0 */
#pragma push /* merge_units */
extern void* Gui_GetScreenList(void);
#if 0 /* merge_units */
extern void* GuiManager_FindOrLoad(void* manager, const char* a, const char* b);
#endif /* merge_units */
#define GuiManager_FindOrLoad(a0, a1, a2) ((void *)GuiManager_FindOrLoad((a0), (char *)(a1), (char *)(a2))) /* merge_units */

extern void* Gui_GetScreenStack(void);
#if 0 /* merge_units */
extern void GuiStack_SwapScreens(void* target, void* self, void* handle);
#endif /* merge_units */
#define GuiStack_SwapScreens(a0, a1, a2) (GuiStack_SwapScreens((a0), (a1), (int)(a2))) /* merge_units */


/* Creates a handle from the two name strings and registers it for self. */
void GuiPersonnelScreen_Back(void* self)
{
    void* handle = GuiManager_FindOrLoad(Gui_GetScreenList(), "GuiCommandCenter", "cmdcentr");
    GuiStack_SwapScreens(Gui_GetScreenStack(), self, handle);
}
#undef GuiManager_FindOrLoad /* merge_units */
#undef GuiStack_SwapScreens /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00356AD0 */

/* merge_units: begin func_00356B30 */
#pragma push /* merge_units */
#pragma cplusplus on
class Obj356B30 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void f60(int);
    virtual void f64(int);
    char pad[0x5C];
    int x60;
};
extern "C" int GuiWidget_OnEvent(Obj356B30 *self, int a1, unsigned short msg, int a3, int param);
extern "C" int GuiPersonnelScreen_HandleEvent(Obj356B30 *self, int a1, unsigned short msg, int a3, int param)
{
    if (msg == 0x14) {
        self->f60(param);
        return 1;
    }
    if (msg == 0x10 && a3 == 1)
        return 1;
    if (msg == 0x13) {
        self->f64(param);
        return 1;
    }
    if (msg == 0x3000) {
        self->x60 = a3;
        return 1;
    }
    return GuiWidget_OnEvent(self, a1, msg, a3, param);
}
#pragma pop /* merge_units */
/* merge_units: end func_00356B30 */

/* merge_units: begin func_00356BE0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct E356BE0 { unsigned short a0; unsigned short a2; short pad4; unsigned short a6; unsigned short a8; };
class S356BE0 {
public:
    VPAD16(a) VPAD8(b)
    virtual void f68();
};
extern "C" int GuiPersonnelScreen_HandleInput(S356BE0* self, E356BE0* e);
int GuiPersonnelScreen_HandleInput(S356BE0* self, E356BE0* e)
{
    bool b = e->a0 == 1 && e->a2 == 0 && e->a8 == 0x10 && e->a6 == 0;
    if (b) {
        self->f68();
        return 1;
    }
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00356BE0 */

/* merge_units: begin func_00356C70 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

struct Widget {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual void Method5C(); /* +0x5C */
    char pad04[0x48 - 4];
    void* list; /* +0x48 */
    char pad4C[0x60 - 0x4C];
    int index; /* +0x60 */
};

extern "C" void GuiWidget_BaseWake(Widget* self);
extern "C" void GuiTextListWidget_Clear(void* list);
extern "C" void GuiArrayWidget_Select(void* list, int a, unsigned int index);

/* GuiWidget_BaseWake(self); if +0x48 is set: GuiTextListWidget_Clear, virtual +0x5C, then GuiArrayWidget_Select(+0x48, 0, +0x60). */
extern "C" void GuiPersonnelScreen_Wake(Widget* self)
{
    GuiWidget_BaseWake(self);
    if (self->list) {
    GuiTextListWidget_Clear(self->list);
    self->Method5C();
    GuiArrayWidget_Select(self->list, 0, self->index);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00356C70 */

/* merge_units: begin func_00356CD0 */
#pragma push /* merge_units */
#pragma cplusplus on
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
void GuiWidget_Init(S_356CD0* o);
W_356CD0* GuiWidget_FindChildByName(void* self, char* name);
#if 0 /* merge_units */
void GuiTextWidget_SetText(W_356CD0* w, char* text, int flags);
#endif /* merge_units */
#define GuiTextWidget_SetText(a0, a1, a2) (GuiTextWidget_SetText((W356850 *)(a0), (a1), (a2))) /* merge_units */

int Agent_GetSelected(void* a, int i);
char* AgentData_GetName(int agent);
void GuiPersonnelScreen_Init(S_356CD0* o);
}
static inline W_356CD0* cast_356CD0(W_356CD0* w, char* type)
{
    return (w && w->IsA(type)) ? w : 0;
}
static inline void Put_356CD0(Col_356CD0* d, QCol_356CD0 c) { d->r = c.r; d->g = c.g; d->b = c.b; d->a = c.a; }
void GuiPersonnelScreen_Init(S_356CD0* o)
{
    W_356CD0* w;
    GuiWidget_Init(o);
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
    if (w) GuiTextWidget_SetText(w, AgentData_GetName(Agent_GetSelected(D_004FFB50, -1)), 0);
}
#undef GuiTextWidget_SetText /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00356CD0 */

/* merge_units: begin func_00356FF0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * GuiPersonnelScreen constructor (vtable D_004DF0B0).
 */

#include "loose03_types.h"

extern char D_004DF0B0[];       /* GuiPersonnelScreen vtable */
extern void GuiWidget_ctor(GuiPersonnelScreen*);

/* GuiPersonnelScreen constructor. */
GuiPersonnelScreen* GuiPersonnelScreen_ctor(GuiPersonnelScreen* self) {
    GuiWidget_ctor(self);
    self->base.vtable = D_004DF0B0;
    self->unk48 = 0;
    self->unk4C = 0;
    self->unk50 = 0;
    self->unk5C = 0;
    self->unk60 = 0;
    self->unk54 = 0;
    self->unk58 = 0;
    self->unk68 = 1;
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_00356FF0 */
