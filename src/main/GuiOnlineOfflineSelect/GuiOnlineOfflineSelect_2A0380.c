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
DEFINE_EVENT_SOUND_CHECK(GuiOnlineOfflineSelect_onInput, D_004AAED8, D_004AAEE8)
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
extern void* Gui_Manager(void);
#if 0 /* merge_units */
extern Item* GuiManager_OpenGui(void*, const char*, const char*);
#endif /* merge_units */
#define GuiManager_OpenGui(a0, a1, a2) ((Item *)GuiManager_OpenGui((a0), (char *)(a1), (char *)(a2))) /* merge_units */

extern void* Gui_Canvas(void);
#if 0 /* merge_units */
extern void GuiCanvas_Transition(void*, void*, Item*);
#endif /* merge_units */
#define GuiCanvas_Transition(a0, a1, a2) (GuiCanvas_Transition((a0), (a1), (int)(a2))) /* merge_units */

/* Resets the game flag, creates a UI item and adds it with the given argument. */
void GuiOnlineOfflineSelect_LaunchOffline(void* arg)
{
    Item* item;
    FrontEnd_SetOnlineMode(D_004FFC04, 0);
    D_004FFC04->flag = 0;
    item = GuiManager_OpenGui(Gui_Manager(), D_004AAEB0, D_004AAEC8);
    item->enabled = 1;
    GuiCanvas_Transition(Gui_Canvas(), arg, item);
}
#undef GuiManager_OpenGui /* merge_units */
#undef GuiCanvas_Transition /* merge_units */
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
extern void* GuiManager_OpenGui(void* manager, const char* a, const char* b);
#endif /* merge_units */
#define GuiManager_OpenGui(a0, a1, a2) ((void *)GuiManager_OpenGui((a0), (char *)(a1), (char *)(a2))) /* merge_units */

#if 0 /* merge_units */
extern void GuiCanvas_Transition(void* target, void* self, void* handle);
#endif /* merge_units */
#define GuiCanvas_Transition(a0, a1, a2) (GuiCanvas_Transition((a0), (a1), (int)(a2))) /* merge_units */


/* Resets HUD state and registers self with a handle created from the two names. */
void GuiOnlineOfflineSelect_LaunchOnline(void* self)
{
    void* handle;
    D_00532FE8 = 0;
    FrontEnd_SetOnlineMode(D_004FFC04, 1);
    D_004FFC04->flag = 0;
    handle = GuiManager_OpenGui(Gui_Manager(), D_004AAE80, D_004AAE98);
    GuiCanvas_Transition(Gui_Canvas(), self, handle);
}
#undef D_004FFC04 /* merge_units */
#undef FrontEnd_SetOnlineMode /* merge_units */
#undef GuiManager_OpenGui /* merge_units */
#undef GuiCanvas_Transition /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A04C0 */

/* merge_units: begin func_002A0540 */
#pragma push /* merge_units */
typedef struct { char pad[0x10]; int flag; } Widget;
#if 0 /* merge_units */
extern Widget* GuiManager_OpenGui(void* factory, const char* a, const char* b);
#endif /* merge_units */
#define GuiManager_OpenGui(a0, a1, a2) ((Widget *)GuiManager_OpenGui((a0), (char *)(a1), (char *)(a2))) /* merge_units */

#if 0 /* merge_units */
extern void GuiCanvas_Transition(void* mgr, void* self, Widget* w);
#endif /* merge_units */
#define GuiCanvas_Transition(a0, a1, a2) (GuiCanvas_Transition((a0), (a1), (int)(a2))) /* merge_units */


/* Creates a widget from two names, flags it and registers it for self. */
void GuiOnlineOfflineSelect_LaunchLAN(void* self)
{
    Widget* w = GuiManager_OpenGui(Gui_Manager(), D_004AAEB0, D_004AAEC8);
    w->flag = 1;
    GuiCanvas_Transition(Gui_Canvas(), self, w);
}
#undef GuiManager_OpenGui /* merge_units */
#undef GuiCanvas_Transition /* merge_units */
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
extern G_002A05B0* g_MemCard;
void GuiWidget_onAdvanceTime(Self_002A05B0* self);
Ctl_002A05B0* GuiWidget_FindChild_charP(Self_002A05B0* self, char* name);
#if 0 /* merge_units */
Ui_002A05B0* Gui_Canvas(void);
#endif /* merge_units */
#define Gui_Canvas() ((Ui_002A05B0 *)Gui_Canvas()) /* merge_units */

void GuiCanvas_SetFocus(Ui_002A05B0* ui, void* w);
}

static inline void SetHidden_002A05B0(Ctl_002A05B0* w, bool h)
{
    if (h)
        w->flags |= 4;
    else
        w->flags &= ~4;
}
extern "C" void GuiOnlineOfflineSelect_onAdvanceTime(Self_002A05B0* self)
{
    Ctl_002A05B0* w;
    GuiWidget_onAdvanceTime(self);
    w = GuiWidget_FindChild_charP(self, D_0048BA28);
    if (w) {
        bool hide;
        if (D_004FFC04->b31) {
            w->flags &= ~4;
            return;
        }
        hide = g_MemCard->b59D && !D_0051EEA0;
        if (!hide && Gui_Canvas()->p20 == w) {
            GuiCanvas_SetFocus(Gui_Canvas(), w->h->Make(w, 1));
        }
        SetHidden_002A05B0(w, hide);
    }
}
#undef D_004FFC04 /* merge_units */
#undef Gui_Canvas /* merge_units */
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
extern G_002A06C0* g_MemCard;
#endif /* merge_units */
#define g_MemCard (*(G_002A06C0 **)&g_MemCard) /* merge_units */

void GuiWidget_onWake(Self_002A06C0* self);
void cGameFrontEnd_PlayMusic(Mgr_002A06C0* m, int a);
#if 0 /* merge_units */
Ctl_002A06C0* GuiWidget_FindChild_charP(Self_002A06C0* self, char* name);
#endif /* merge_units */
#define GuiWidget_FindChild_charP(a0, a1) ((Ctl_002A06C0 *)GuiWidget_FindChild_charP((Self_002A05B0 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
Ui_002A06C0* Gui_Canvas(void);
#endif /* merge_units */
#define Gui_Canvas() ((Ui_002A06C0 *)Gui_Canvas()) /* merge_units */

#if 0 /* merge_units */
void GuiCanvas_SetFocus(Ui_002A06C0* ui, void* w);
#endif /* merge_units */
#define GuiCanvas_SetFocus(a0, a1) (GuiCanvas_SetFocus((Ui_002A05B0 *)(a0), (a1))) /* merge_units */

}

static inline void SetHidden_002A06C0(Ctl_002A06C0* w, bool h)
{
    if (h)
        w->flags |= 4;
    else
        w->flags &= ~4;
}

extern "C" void GuiOnlineOfflineSelect_onWake(Self_002A06C0* self)
{
    Ctl_002A06C0* w;
    GuiWidget_onWake(self);
    cGameFrontEnd_PlayMusic(D_004FFC04, 0);
    self->p20 = GuiWidget_FindChild_charP(self, self->b48 ? D_0048BA28 : D_0048BA30);
    w = GuiWidget_FindChild_charP(self, D_0048BA38);
    if (w)
        SetHidden_002A06C0(w, !D_0051EEA8);
    w = GuiWidget_FindChild_charP(self, D_0048BA28);
    if (w) {
        bool hide;
        if (D_004FFC04->b31) {
            w->flags &= ~4;
            return;
        }
        hide = g_MemCard->b59D && !D_0051EEA0;
        if (!hide && Gui_Canvas()->p20 == w) {
            GuiCanvas_SetFocus(Gui_Canvas(), w->h->Make(w, 1));
        }
        SetHidden_002A06C0(w, hide);
    }
}
#undef D_004FFC04 /* merge_units */
#undef g_MemCard /* merge_units */
#undef GuiWidget_FindChild_charP /* merge_units */
#undef Gui_Canvas /* merge_units */
#undef GuiCanvas_SetFocus /* merge_units */
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
extern G_002A0860* g_MemCard;
#endif /* merge_units */
#define g_MemCard (*(G_002A0860 **)&g_MemCard) /* merge_units */

#if 0 /* merge_units */
void GuiWidget_onAdvanceTime(Self_002A0860* self);
#endif /* merge_units */
#define GuiWidget_onAdvanceTime(a0) (GuiWidget_onAdvanceTime((Self_002A05B0 *)(a0))) /* merge_units */

#if 0 /* merge_units */
Ctl_002A0860* GuiWidget_FindChild_charP(Self_002A0860* self, char* name);
#endif /* merge_units */
#define GuiWidget_FindChild_charP(a0, a1) ((Ctl_002A0860 *)GuiWidget_FindChild_charP((Self_002A05B0 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
Ui_002A0860* Gui_Canvas(void);
#endif /* merge_units */
#define Gui_Canvas() ((Ui_002A0860 *)Gui_Canvas()) /* merge_units */

#if 0 /* merge_units */
void GuiCanvas_SetFocus(Ui_002A0860* ui, void* w);
#endif /* merge_units */
#define GuiCanvas_SetFocus(a0, a1) (GuiCanvas_SetFocus((Ui_002A05B0 *)(a0), (a1))) /* merge_units */

}

static inline void SetHidden_002A0860(Ctl_002A0860* w, bool h)
{
    if (h)
        w->flags |= 4;
    else
        w->flags &= ~4;
}
extern "C" void GuiOnlineOfflineSelect_SetOnlineState(Self_002A0860* self)
{
    Ctl_002A0860* w;
    
    w = GuiWidget_FindChild_charP(self, D_0048BA28);
    if (w) {
        bool hide;
        if (D_004FFC04->b31) {
            w->flags &= ~4;
            return;
        }
        hide = g_MemCard->b59D && !D_0051EEA0;
        if (!hide && Gui_Canvas()->p20 == w) {
            GuiCanvas_SetFocus(Gui_Canvas(), w->h->Make(w, 1));
        }
        SetHidden_002A0860(w, hide);
    }
}
#undef D_004FFC04 /* merge_units */
#undef g_MemCard /* merge_units */
#undef GuiWidget_onAdvanceTime /* merge_units */
#undef GuiWidget_FindChild_charP /* merge_units */
#undef Gui_Canvas /* merge_units */
#undef GuiCanvas_SetFocus /* merge_units */
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

void GuiWidget_onAdd(S2A0970* s);
#if 0 /* merge_units */
W2A0970* GuiWidget_FindChild_charP(S2A0970* s, const char* name);
#endif /* merge_units */
#define GuiWidget_FindChild_charP(a0, a1) ((W2A0970 *)GuiWidget_FindChild_charP((Self_002A05B0 *)(a0), (char *)(a1))) /* merge_units */

}

static inline int Nz2A0970(unsigned char v) { return v != 0; }
/* Screen init: copies the global mode flag and shows/hides two widgets accordingly. */
extern "C" void GuiOnlineOfflineSelect_onAdd(S2A0970* s)
{
    W2A0970* w;
    GuiWidget_onAdd(s);
    s->b48 = D_00506488;
    w = GuiWidget_FindChild_charP(s, D_0048BA38);
    if (w) {
        bool c = !s->b48 && D_00506490;
        if (c) w->flags |= 2;
        else w->flags &= ~2;
    }
    w = GuiWidget_FindChild_charP(s, D_0048BA30);
    if (w) {
        if (Nz2A0970(s->b48) ^ 1) w->flags |= 4;
        else w->flags &= ~4;
    }
}
#undef D_0048BA38 /* merge_units */
#undef D_0048BA30 /* merge_units */
#undef GuiWidget_FindChild_charP /* merge_units */
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
extern void std_basic_string_char_char_traits_char_compare_uint_uint_charP_uint(SsoString* self, int pos, int n, const char* s, int len);

/* Assigns a C string to the string by replacing its whole contents. */
void func_002A0A90(SsoString* self, const char* s)
{
    int len = strlen(s);
    std_basic_string_char_char_traits_char_compare_uint_uint_charP_uint(self, 0, (self->hdr.word & 1) ? self->longLen : (unsigned char)self->hdr.s.len, s, len);
}
#pragma pop /* merge_units */
/* merge_units: end func_002A0A90 */

/* merge_units: begin func_002A0B00 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "string_compare_range.h"

/* String compare of a substring against a buffer. */
extern "C" { char D_004AAF00[] = "string compare: pos > len"; }
DEFINE_STRING_COMPARE_RANGE(String_Compare_2A0B00, D_004AAF00)
#pragma pop /* merge_units */
/* merge_units: end func_002A0B00 */
