/*
 * main/GuiOnlineOfflineSelect: 11 files, 002A0380-002A0B00
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002A0380 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "event_sound_check.h"

/* Play a sound on a matching event. */
extern "C" { char D_004AAED8[] = "GuiTitleScreen"; }
extern "C" { char D_004AAEE8[] = "titlescr"; }
DEFINE_EVENT_SOUND_CHECK(GuiOnlineOfflineSelect_HandleInput, D_004AAED8, D_004AAEE8)
#pragma pop /* merge_units */
/* merge_units: end func_002A0380 */

/* merge_units: begin func_002A0440 */
#pragma push /* merge_units */
typedef struct { char pad[0x32]; unsigned char flag; } Game;
typedef struct { char pad[0x10]; int enabled; } Item;
extern Game* D_004FFC04;
extern char D_004AAEB0[];
extern char D_004AAEC8[];
extern void FrontEnd_SetOnlineMode(Game*, int);
extern void* Gui_GetScreenList(void);
#if 0 /* merge_units */
extern Item* GuiManager_FindOrLoad(void*, const char*, const char*);
#endif /* merge_units */
#define GuiManager_FindOrLoad(a0, a1, a2) ((Item *)GuiManager_FindOrLoad((a0), (char *)(a1), (char *)(a2))) /* merge_units */

extern void* Gui_GetScreenStack(void);
#if 0 /* merge_units */
extern void GuiStack_SwapScreens(void*, void*, Item*);
#endif /* merge_units */
#define GuiStack_SwapScreens(a0, a1, a2) (GuiStack_SwapScreens((a0), (a1), (int)(a2))) /* merge_units */

/* Resets the game flag, creates a UI item and adds it with the given argument. */
void func_002A0440(void* arg)
{
    Item* item;
    FrontEnd_SetOnlineMode(D_004FFC04, 0);
    D_004FFC04->flag = 0;
    item = GuiManager_FindOrLoad(Gui_GetScreenList(), D_004AAEB0, D_004AAEC8);
    item->enabled = 1;
    GuiStack_SwapScreens(Gui_GetScreenStack(), arg, item);
}
#undef GuiManager_FindOrLoad /* merge_units */
#undef GuiStack_SwapScreens /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A0440 */

/* merge_units: begin func_002A04C0 */
#pragma push /* merge_units */
typedef struct { char pad[0x32]; unsigned char flag; } Hud32;
extern unsigned char D_00532FE8;
#if 0 /* merge_units */
extern Hud32* D_004FFC04;
#endif /* merge_units */
#define D_004FFC04 (*(Hud32 **)&D_004FFC04) /* merge_units */

extern char D_004AAE80[];
extern char D_004AAE98[];
#if 0 /* merge_units */
extern void FrontEnd_SetOnlineMode(Hud32* hud, int a1);
#endif /* merge_units */
#define FrontEnd_SetOnlineMode(a0, a1) (FrontEnd_SetOnlineMode((Game *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void* GuiManager_FindOrLoad(void* manager, const char* a, const char* b);
#endif /* merge_units */
#define GuiManager_FindOrLoad(a0, a1, a2) ((void *)GuiManager_FindOrLoad((a0), (char *)(a1), (char *)(a2))) /* merge_units */

#if 0 /* merge_units */
extern void GuiStack_SwapScreens(void* target, void* self, void* handle);
#endif /* merge_units */
#define GuiStack_SwapScreens(a0, a1, a2) (GuiStack_SwapScreens((a0), (a1), (int)(a2))) /* merge_units */


/* Resets HUD state and registers self with a handle created from the two names. */
void func_002A04C0(void* self)
{
    void* handle;
    D_00532FE8 = 0;
    FrontEnd_SetOnlineMode(D_004FFC04, 1);
    D_004FFC04->flag = 0;
    handle = GuiManager_FindOrLoad(Gui_GetScreenList(), D_004AAE80, D_004AAE98);
    GuiStack_SwapScreens(Gui_GetScreenStack(), self, handle);
}
#undef D_004FFC04 /* merge_units */
#undef FrontEnd_SetOnlineMode /* merge_units */
#undef GuiManager_FindOrLoad /* merge_units */
#undef GuiStack_SwapScreens /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A04C0 */

/* merge_units: begin func_002A0540 */
#pragma push /* merge_units */
typedef struct { char pad[0x10]; int flag; } Widget;
#if 0 /* merge_units */
extern Widget* GuiManager_FindOrLoad(void* factory, const char* a, const char* b);
#endif /* merge_units */
#define GuiManager_FindOrLoad(a0, a1, a2) ((Widget *)GuiManager_FindOrLoad((a0), (char *)(a1), (char *)(a2))) /* merge_units */

#if 0 /* merge_units */
extern void GuiStack_SwapScreens(void* mgr, void* self, Widget* w);
#endif /* merge_units */
#define GuiStack_SwapScreens(a0, a1, a2) (GuiStack_SwapScreens((a0), (a1), (int)(a2))) /* merge_units */


/* Creates a widget from two names, flags it and registers it for self. */
void func_002A0540(void* self)
{
    Widget* w = GuiManager_FindOrLoad(Gui_GetScreenList(), D_004AAEB0, D_004AAEC8);
    w->flag = 1;
    GuiStack_SwapScreens(Gui_GetScreenStack(), self, w);
}
#undef GuiManager_FindOrLoad /* merge_units */
#undef GuiStack_SwapScreens /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A0540 */

/* merge_units: begin func_002A05B0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_pad.h"

struct Ctl_002A05B0;
struct Hnd_002A05B0 {
    VPAD16(a) VPAD1(b)
    virtual void* Make(Ctl_002A05B0* w, int a);
};
struct Ctl_002A05B0 { char pad[0x14]; unsigned short flags; char pad16[0xE]; Hnd_002A05B0* h; };
struct Self_002A05B0 { char pad[0x20]; Ctl_002A05B0* p20; };
struct Mgr_002A05B0 { char pad[0x31]; unsigned char b31; };
struct G_002A05B0 { char pad[0x59D]; unsigned char b59D; };
struct Ui_002A05B0 { char pad[0x20]; Ctl_002A05B0* p20; };

extern "C" {
extern char* D_0048BA28;
#if 0 /* merge_units */
extern Mgr_002A05B0* D_004FFC04;
#endif /* merge_units */
#define D_004FFC04 (*(Mgr_002A05B0 **)&D_004FFC04) /* merge_units */

extern unsigned char D_0051EEA0;
extern G_002A05B0* D_0055A830;
void GuiWidget_Update(Self_002A05B0* self);
Ctl_002A05B0* GuiWidget_FindChildByName(Self_002A05B0* self, char* name);
#if 0 /* merge_units */
Ui_002A05B0* Gui_GetScreenStack(void);
#endif /* merge_units */
#define Gui_GetScreenStack() ((Ui_002A05B0 *)Gui_GetScreenStack()) /* merge_units */

void GuiScreen_SetFocus(Ui_002A05B0* ui, void* w);
}

static inline void SetHidden_002A05B0(Ctl_002A05B0* w, bool h)
{
    if (h)
        w->flags |= 4;
    else
        w->flags &= ~4;
}
extern "C" void GuiOnlineOfflineSelect_Update(Self_002A05B0* self)
{
    Ctl_002A05B0* w;
    GuiWidget_Update(self);
    w = GuiWidget_FindChildByName(self, D_0048BA28);
    if (w) {
        bool hide;
        if (D_004FFC04->b31) {
            w->flags &= ~4;
            return;
        }
        hide = D_0055A830->b59D && !D_0051EEA0;
        if (!hide && Gui_GetScreenStack()->p20 == w) {
            GuiScreen_SetFocus(Gui_GetScreenStack(), w->h->Make(w, 1));
        }
        SetHidden_002A05B0(w, hide);
    }
}
#undef D_004FFC04 /* merge_units */
#undef Gui_GetScreenStack /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A05B0 */

/* merge_units: begin func_002A06C0 */
#pragma push /* merge_units */
#pragma cplusplus on

struct Ctl_002A06C0;
struct Hnd_002A06C0 {
    VPAD16(a) VPAD1(b)
    virtual void* Make(Ctl_002A06C0* w, int a);
};
struct Ctl_002A06C0 { char pad[0x14]; unsigned short flags; char pad16[0xE]; Hnd_002A06C0* h; };
struct Self_002A06C0 { char pad[0x20]; Ctl_002A06C0* p20; char pad24[0x24]; unsigned char b48; };
struct Mgr_002A06C0 { char pad[0x31]; unsigned char b31; };
struct G_002A06C0 { char pad[0x59D]; unsigned char b59D; };
struct Ui_002A06C0 { char pad[0x20]; Ctl_002A06C0* p20; };

extern "C" {
extern char* D_0048BA30;
extern char* D_0048BA38;
#if 0 /* merge_units */
extern Mgr_002A06C0* D_004FFC04;
#endif /* merge_units */
#define D_004FFC04 (*(Mgr_002A06C0 **)&D_004FFC04) /* merge_units */

extern unsigned char D_0051EEA8;
#if 0 /* merge_units */
extern G_002A06C0* D_0055A830;
#endif /* merge_units */
#define D_0055A830 (*(G_002A06C0 **)&D_0055A830) /* merge_units */

void GuiWidget_BaseWake(Self_002A06C0* self);
void func_002C9AF0(Mgr_002A06C0* m, int a);
#if 0 /* merge_units */
Ctl_002A06C0* GuiWidget_FindChildByName(Self_002A06C0* self, char* name);
#endif /* merge_units */
#define GuiWidget_FindChildByName(a0, a1) ((Ctl_002A06C0 *)GuiWidget_FindChildByName((Self_002A05B0 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
Ui_002A06C0* Gui_GetScreenStack(void);
#endif /* merge_units */
#define Gui_GetScreenStack() ((Ui_002A06C0 *)Gui_GetScreenStack()) /* merge_units */

#if 0 /* merge_units */
void GuiScreen_SetFocus(Ui_002A06C0* ui, void* w);
#endif /* merge_units */
#define GuiScreen_SetFocus(a0, a1) (GuiScreen_SetFocus((Ui_002A05B0 *)(a0), (a1))) /* merge_units */

}

static inline void SetHidden_002A06C0(Ctl_002A06C0* w, bool h)
{
    if (h)
        w->flags |= 4;
    else
        w->flags &= ~4;
}

extern "C" void GuiOnlineOfflineSelect_Wake(Self_002A06C0* self)
{
    Ctl_002A06C0* w;
    GuiWidget_BaseWake(self);
    func_002C9AF0(D_004FFC04, 0);
    self->p20 = GuiWidget_FindChildByName(self, self->b48 ? D_0048BA28 : D_0048BA30);
    w = GuiWidget_FindChildByName(self, D_0048BA38);
    if (w)
        SetHidden_002A06C0(w, !D_0051EEA8);
    w = GuiWidget_FindChildByName(self, D_0048BA28);
    if (w) {
        bool hide;
        if (D_004FFC04->b31) {
            w->flags &= ~4;
            return;
        }
        hide = D_0055A830->b59D && !D_0051EEA0;
        if (!hide && Gui_GetScreenStack()->p20 == w) {
            GuiScreen_SetFocus(Gui_GetScreenStack(), w->h->Make(w, 1));
        }
        SetHidden_002A06C0(w, hide);
    }
}
#undef D_004FFC04 /* merge_units */
#undef D_0055A830 /* merge_units */
#undef GuiWidget_FindChildByName /* merge_units */
#undef Gui_GetScreenStack /* merge_units */
#undef GuiScreen_SetFocus /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A06C0 */

/* merge_units: begin func_002A0860 */
#pragma push /* merge_units */
#pragma cplusplus on

struct Ctl_002A0860;
struct Hnd_002A0860 {
    VPAD16(a) VPAD1(b)
    virtual void* Make(Ctl_002A0860* w, int a);
};
struct Ctl_002A0860 { char pad[0x14]; unsigned short flags; char pad16[0xE]; Hnd_002A0860* h; };
struct Self_002A0860 { char pad[0x20]; Ctl_002A0860* p20; };
struct Mgr_002A0860 { char pad[0x31]; unsigned char b31; };
struct G_002A0860 { char pad[0x59D]; unsigned char b59D; };
struct Ui_002A0860 { char pad[0x20]; Ctl_002A0860* p20; };

extern "C" {
#if 0 /* merge_units */
extern Mgr_002A0860* D_004FFC04;
#endif /* merge_units */
#define D_004FFC04 (*(Mgr_002A0860 **)&D_004FFC04) /* merge_units */

#if 0 /* merge_units */
extern G_002A0860* D_0055A830;
#endif /* merge_units */
#define D_0055A830 (*(G_002A0860 **)&D_0055A830) /* merge_units */

#if 0 /* merge_units */
void GuiWidget_Update(Self_002A0860* self);
#endif /* merge_units */
#define GuiWidget_Update(a0) (GuiWidget_Update((Self_002A05B0 *)(a0))) /* merge_units */

#if 0 /* merge_units */
Ctl_002A0860* GuiWidget_FindChildByName(Self_002A0860* self, char* name);
#endif /* merge_units */
#define GuiWidget_FindChildByName(a0, a1) ((Ctl_002A0860 *)GuiWidget_FindChildByName((Self_002A05B0 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
Ui_002A0860* Gui_GetScreenStack(void);
#endif /* merge_units */
#define Gui_GetScreenStack() ((Ui_002A0860 *)Gui_GetScreenStack()) /* merge_units */

#if 0 /* merge_units */
void GuiScreen_SetFocus(Ui_002A0860* ui, void* w);
#endif /* merge_units */
#define GuiScreen_SetFocus(a0, a1) (GuiScreen_SetFocus((Ui_002A05B0 *)(a0), (a1))) /* merge_units */

}

static inline void SetHidden_002A0860(Ctl_002A0860* w, bool h)
{
    if (h)
        w->flags |= 4;
    else
        w->flags &= ~4;
}
extern "C" void GuiOnlineOfflineSelect_UpdateOnline(Self_002A0860* self)
{
    Ctl_002A0860* w;
    
    w = GuiWidget_FindChildByName(self, D_0048BA28);
    if (w) {
        bool hide;
        if (D_004FFC04->b31) {
            w->flags &= ~4;
            return;
        }
        hide = D_0055A830->b59D && !D_0051EEA0;
        if (!hide && Gui_GetScreenStack()->p20 == w) {
            GuiScreen_SetFocus(Gui_GetScreenStack(), w->h->Make(w, 1));
        }
        SetHidden_002A0860(w, hide);
    }
}
#undef D_004FFC04 /* merge_units */
#undef D_0055A830 /* merge_units */
#undef GuiWidget_Update /* merge_units */
#undef GuiWidget_FindChildByName /* merge_units */
#undef Gui_GetScreenStack /* merge_units */
#undef GuiScreen_SetFocus /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A0860 */

/* merge_units: begin func_002A0970 */
#pragma push /* merge_units */
#pragma cplusplus on
struct W2A0970 { char pad[0x14]; unsigned short flags; };
struct S2A0970 { char pad[0x48]; unsigned char b48; };
extern "C" {
extern unsigned char D_00506488;
extern unsigned char D_00506490;
#if 0 /* merge_units */
extern const char* D_0048BA38;
#endif /* merge_units */
#define D_0048BA38 (*(const char **)&D_0048BA38) /* merge_units */

#if 0 /* merge_units */
extern const char* D_0048BA30;
#endif /* merge_units */
#define D_0048BA30 (*(const char **)&D_0048BA30) /* merge_units */

void GuiWidget_Init(S2A0970* s);
#if 0 /* merge_units */
W2A0970* GuiWidget_FindChildByName(S2A0970* s, const char* name);
#endif /* merge_units */
#define GuiWidget_FindChildByName(a0, a1) ((W2A0970 *)GuiWidget_FindChildByName((Self_002A05B0 *)(a0), (char *)(a1))) /* merge_units */

}

static inline int Nz2A0970(unsigned char v) { return v != 0; }
/* Screen init: copies the global mode flag and shows/hides two widgets accordingly. */
extern "C" void GuiOnlineOfflineSelect_Init(S2A0970* s)
{
    W2A0970* w;
    GuiWidget_Init(s);
    s->b48 = D_00506488;
    w = GuiWidget_FindChildByName(s, D_0048BA38);
    if (w) {
        bool c = !s->b48 && D_00506490;
        if (c) w->flags |= 2;
        else w->flags &= ~2;
    }
    w = GuiWidget_FindChildByName(s, D_0048BA30);
    if (w) {
        if (Nz2A0970(s->b48) ^ 1) w->flags |= 4;
        else w->flags &= ~4;
    }
}
#undef D_0048BA38 /* merge_units */
#undef D_0048BA30 /* merge_units */
#undef GuiWidget_FindChildByName /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A0970 */

/* merge_units: begin func_002A0A50 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose02_types.h"

extern char D_004DD6B0[];   /* GuiOnlineOfflineSelect vtable */
extern void GuiWidget_ctor(GuiWidget* self);

/* GuiOnlineOfflineSelect constructor. */
GuiOnlineOfflineSelect* GuiOnlineOfflineSelect_ctor(GuiOnlineOfflineSelect* self) {
    GuiWidget_ctor(&self->base);
    self->base.vtable = D_004DD6B0;
    self->unk48 = 0;
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_002A0A50 */

/* merge_units: begin func_002A0A90 */
#pragma push /* merge_units */
typedef struct { unsigned char isLong : 1; unsigned char len : 7; } ShortHdr;
typedef struct { union { unsigned int word; ShortHdr s; } hdr; int longLen; char* longData; } SsoString;

extern int strlen(const char* s); /* strlen */
extern void String_Compare(SsoString* self, int pos, int n, const char* s, int len);

/* Assigns a C string to the string by replacing its whole contents. */
void func_002A0A90(SsoString* self, const char* s)
{
    int len = strlen(s);
    String_Compare(self, 0, (self->hdr.word & 1) ? self->longLen : (unsigned char)self->hdr.s.len, s, len);
}
#pragma pop /* merge_units */
/* merge_units: end func_002A0A90 */

/* merge_units: begin func_002A0B00 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "string_compare_range.h"

/* String compare of a substring against a buffer. */
extern "C" { char D_004AAF00[] = "string compare: pos > len"; }
DEFINE_STRING_COMPARE_RANGE(func_002A0B00, D_004AAF00)
#pragma pop /* merge_units */
/* merge_units: end func_002A0B00 */
