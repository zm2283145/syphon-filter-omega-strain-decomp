/*
 * main/GuiGameOptions: range (4 files, 0029AD10-0029B1E0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "vslot_pad.h"

/* merge_units: begin func_0029AD10 */
#pragma push /* merge_units */
typedef struct { int a; unsigned char b4, b5, b6, b7; float f8, fc, f10; int f14; unsigned char b18, b19; char p1a[2]; float f1c; int f20; } C_AD10;
typedef struct { char pad[0x4C]; unsigned char b4c; char pad4d[0xB8 - 0x4D]; C_AD10 cfg; char pad3[0x401 - 0xDC]; unsigned char b401; } G_AD10;
extern C_AD10* D_004FFD2C;
extern void* D_004FFC04;
extern int GameOptions_Diff(C_AD10*, C_AD10*);
extern void GameOptions_Apply(C_AD10*, int);
extern void GuiSaveAgentWidget_HandleEvent(G_AD10*);
extern void FrontEnd_SuspendGui(void*, int);
extern void FrontEnd_ResumeGui(void*);
extern void* Gui_GetScreenStack(void);
extern void GuiWidget_SendEvent(G_AD10*, void*, int, int, int);

void GuiGameOptions_Close(G_AD10* g, int apply) {
    int diff;
    int m;
    C_AD10* c;
    diff = GameOptions_Diff(&g->cfg, D_004FFD2C);
    if (diff != 0 || !g->b401) {
        if (apply) {
            c = D_004FFD2C;
            c->a = g->cfg.a;
            c->b4 = g->cfg.b4;
            c->b5 = g->cfg.b5;
            c->b6 = g->cfg.b6;
            c->b7 = g->cfg.b7;
            c->f8 = g->cfg.f8;
            c->fc = g->cfg.fc;
            c->f10 = g->cfg.f10;
            c->f14 = g->cfg.f14;
            c->b18 = g->cfg.b18;
            c->b19 = g->cfg.b19;
            c->f1c = g->cfg.f1c;
            c->f20 = g->cfg.f20;
            g->b401 = 0;
            g->b4c = 4;
            GuiSaveAgentWidget_HandleEvent(g);
        } else {
            m = diff & 0x800;
            if (m) FrontEnd_SuspendGui(D_004FFC04, 1);
            GameOptions_Apply(D_004FFD2C, diff);
            if (m) FrontEnd_ResumeGui(D_004FFC04);
        }
    } else {
        GuiWidget_SendEvent(g, Gui_GetScreenStack(), 0x10, 4, 0);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0029AD10(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0029AD10 */

/* merge_units: begin func_0029AE60 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Ctl_29AE60 { VPAD16(a) VPAD2(b) VPAD1(c) virtual unsigned char IsLocal(); };
struct Plr_29AE60 { char pad[0xC]; unsigned int flags; char pad10[4]; unsigned char b14; char pad15[0x43]; Ctl_29AE60* ctl; };
struct Menu_29AE60 { char pad[0x54]; int sel; char pad58[0x3C]; int count; };
struct Wid_29AE60 { char pad[0x14]; unsigned short flags; };
struct Mgr_29AE60 { char pad[0x20]; Menu_29AE60* active; };
struct Self_29AE60 { char pad[0xA4]; int fA4; Wid_29AE60* fA8; char padAC[0x430 - 0xAC]; Menu_29AE60* menu; Wid_29AE60* w434; };
extern "C" {
extern unsigned char D_005721C8;
Plr_29AE60* PlayerSlots_Get(int i);
void GuiGameOptions_ShowMenu(Self_29AE60* self);
int GuiGameOptions_GetPlayers(void);
void Hud_AppendCalloutName(char* buf, Plr_29AE60* p, int idx, int x);
#if 0 /* merge_units */
Mgr_29AE60* Gui_GetScreenStack(void);
#endif /* merge_units */
#define Gui_GetScreenStack() ((Mgr_29AE60 *)Gui_GetScreenStack()) /* merge_units */

void GuiScreen_SetFocus(Mgr_29AE60* m, int x);
void GuiTextListWidget_Clear(Menu_29AE60* m);
void GuiTextListWidget_AddItem(Menu_29AE60* m, char* s, int idx, int x);
void GuiArrayWidget_Select(Menu_29AE60* m, int a, int sel);
}
static inline unsigned char IsLocal_29AE60(Plr_29AE60* p) { unsigned char r = 0; if (p->ctl && p->ctl->IsLocal()) r = 1; return r; }
static inline int LocalId_29AE60(Plr_29AE60* p) { int id; if (D_005721C8) { if (IsLocal_29AE60(p)) id = ((p->flags & 0x7F000000) >> 24) - 1; else id = -1; } else id = 0; return id; }
static inline void SetFlag_29AE60(Wid_29AE60* w, unsigned short bit, unsigned char on) { if (on) w->flags |= bit; else w->flags &= ~bit; }
extern "C" void func_0029AE60(Self_29AE60* self)
{
    int i;
    Plr_29AE60* p;
    int sel;
    if (self->menu == 0) return;
    if (GuiGameOptions_GetPlayers() < 2) {
        GuiGameOptions_ShowMenu(self);
        if (self->fA8 != 0) {
            self->fA8->flags &= ~4;
        }
        GuiScreen_SetFocus(Gui_GetScreenStack(), self->fA4);
        return;
    }
    sel = self->menu->sel;
    GuiTextListWidget_Clear(self->menu);
    for (i = 0; i < 4; i++) {
        p = PlayerSlots_Get(i);
        if (p != 0 && p->b14 == 0) {
            int id = LocalId_29AE60(p);
            if (id >= 0 && id < 4) {
                char buf[0x90];
                buf[0] = 0;
                Hud_AppendCalloutName(buf, p, id, 0);
                GuiTextListWidget_AddItem(self->menu, buf + 1, id, 0);
            }
        }
    }
    GuiArrayWidget_Select(self->menu, 0, sel < self->menu->count ? sel : 0);
    if (self->w434 != 0) {
        unsigned char on = 0;
        Mgr_29AE60* g = Gui_GetScreenStack();
        Menu_29AE60* m = self->menu;
        if (g->active == m && m->count != 0) on = 1;
        SetFlag_29AE60(self->w434, 2, on);
    }
}
#undef Gui_GetScreenStack /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0029AE60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0029AE60 */

/* merge_units: begin func_0029B070 */
#pragma push /* merge_units */
typedef struct SoundRequest {
    char pad000[0x48];
    char partA[0x9C];
    char partB[0xAC];
} SoundRequest;
typedef struct SoundEventMsg {
    void* vtbl;
    char pad004[0x1C];
    unsigned char flag;
    char pad021[0x57];
    char partA[0x9C];
    char partB[0xAC];
    char pad1C0[0x10];
} SoundEventMsg;
typedef struct { char pad[0x400]; unsigned char b400; } G_B070;
extern char* D_0048B908;
extern char D_004AA780[];
extern char D_004FFB50[];
extern char D_004DADF0[];
void GuiWidget_BaseSleep(G_B070*);
void PadRumble_Stop(void);
int Fstream_GetLoader(void);
void FStream_CancelRequests(int);
void Heap_ReleaseSlot(int);
void SoundRequest_Ctor(SoundRequest* req, int kind, void* name, int a, int b);
void SoundEvent_Ctor(SoundEventMsg* msg, void* action, int flags);
void Event_Send(void* msg, void* target, int flags);
void FileMan_Release(void* part, int flags);
void cMessage_dtor(void* msg, int flags);

void GuiGameOptions_Sleep(G_B070* self) {
    SoundEventMsg evm;
    SoundEventMsg evm2;
    SoundRequest req;
    SoundRequest req2;
    GuiWidget_BaseSleep(self);
    PadRumble_Stop();
    SoundRequest_Ctor(&req, 4, D_0048B908, 0, 0);
    SoundEvent_Ctor(&evm, &req, 0);
    FileMan_Release(req.partB, -1);
    FileMan_Release(req.partA, -1);
    evm.flag = 1;
    Event_Send(&evm, D_004FFB50, 1);
    if (!self->b400) {
        SoundRequest_Ctor(&req2, 4, D_004AA780, 0, 0);
        SoundEvent_Ctor(&evm2, &req2, 0);
        FileMan_Release(req2.partB, -1);
        FileMan_Release(req2.partA, -1);
        evm2.flag = 1;
        Event_Send(&evm2, D_004FFB50, 1);
        FStream_CancelRequests(Fstream_GetLoader());
        Heap_ReleaseSlot(1);
        evm2.vtbl = D_004DADF0;
        FileMan_Release(evm2.partB, -1);
        FileMan_Release(evm2.partA, -1);
        cMessage_dtor(&evm2, 0);
    }
    evm.vtbl = D_004DADF0;
    FileMan_Release(evm.partB, -1);
    FileMan_Release(evm.partA, -1);
    cMessage_dtor(&evm, 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0029B070(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0029B070 */

/* merge_units: begin func_0029B1E0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct V29B { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual char* v19(); };
typedef struct { int a; unsigned char b4, b5, b6, b7; float f8, fc, f10; int f14; unsigned char b18, b19; char p1a[2]; float f1c; int f20; } C29B;
typedef struct { char pad[0x14]; unsigned short flags; } W29B;
typedef struct { char pad[0xA8]; W29B* fa8; char pad2[0xC]; C29B cfg; char pad3[0x324]; unsigned char b400; char pad4[0x2B]; W29B* f42c; } G29B;
extern "C" {
extern void GuiWidget_BaseWake(G29B*);
#if 0 /* merge_units */
extern C29B* D_004FFD2C;
#endif /* merge_units */
#define D_004FFD2C (*(C29B **)&D_004FFD2C) /* merge_units */

extern void GuiGameOptions_Refresh(G29B*, int);
#if 0 /* merge_units */
extern V29B* Gui_GetScreenStack(void);
#endif /* merge_units */
#define Gui_GetScreenStack() ((V29B *)Gui_GetScreenStack()) /* merge_units */

extern int String_CompareNoCase(char*, char*);
extern unsigned char D_005721C0;
extern int GuiGameOptions_GetPlayers(void);
extern void Heap_ReleaseSlot(int);
extern void Heap_AllocSlot(int, int, int);
}
static inline int ok29B(void) { return D_005721C8 ? D_005721C0 : 1; }
extern "C" void GuiGameOptions_Wake(G29B* g) {
    C29B* c;
    GuiWidget_BaseWake(g);
    c = D_004FFD2C;
    g->cfg.a = c->a;
    g->cfg.b4 = c->b4;
    g->cfg.b5 = c->b5;
    g->cfg.b6 = c->b6;
    g->cfg.b7 = c->b7;
    g->cfg.f8 = c->f8;
    g->cfg.fc = c->fc;
    g->cfg.f10 = c->f10;
    g->cfg.f14 = c->f14;
    g->cfg.b18 = c->b18;
    g->cfg.b19 = c->b19;
    g->cfg.f1c = c->f1c;
    g->cfg.f20 = c->f20;
    GuiGameOptions_Refresh(g, -1);
    g->b400 = String_CompareNoCase(Gui_GetScreenStack()->v19(), "GuiGameCanvas") == 0;
    if (g->b400) {
        if (g->f42c) g->f42c->flags &= ~4;
        if (!D_005721C8 || !ok29B() || GuiGameOptions_GetPlayers() < 2) {
            if (g->fa8) g->fa8->flags &= ~4;
        }
    } else {
        Heap_ReleaseSlot(1);
        Heap_AllocSlot(1, 0x100000, 0x800);
    }
}
#undef D_004FFD2C /* merge_units */
#undef Gui_GetScreenStack /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0029B1E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0029B1E0 */
