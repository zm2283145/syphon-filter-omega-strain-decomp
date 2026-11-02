/*
 * SFOGame/Source/GuiAgentModify: 9 files, 0033FA00-00340700
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0033FA00 */
#pragma push /* merge_units */
#include "types.h"

extern int g_AgentPartCache;
extern void Monster_RestoreLockedPartsTex(void*);
extern void cMotionManager_FlushUpdateList(void);
extern void* Gui_Manager(void);
extern void* GuiManager_OpenGui(void*, void*, void*);
extern void* Gui_Canvas(void);
extern void GuiCanvas_Transition(void*, int, void*);

/* Resets state, looks up a named entry and hands it to GuiCanvas_Transition with the argument. */
void GuiAgentModify_SaveDone(int arg) {
    void* entry;
    Monster_RestoreLockedPartsTex(&g_AgentPartCache);
    cMotionManager_FlushUpdateList();
    entry = GuiManager_OpenGui(Gui_Manager(), ((int*)"GuiCommandCenter"), ((int*)"CMDCENTR"));
    GuiCanvas_Transition(Gui_Canvas(), arg, entry);
}
static inline void merge_flush_func_0033FA00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0033FA00 */

/* merge_units: begin func_0033FA80 */
#pragma push /* merge_units */
/* GuiAgentModify_onInput: agent-modify screen input (save, back, part groups, part stepping);
 * same shape as GuiAgentCreate_onInput. */
#pragma cplusplus on
#include "vslot_pad.h"
/* volatile type: retail re-reads ev->type in every check (no CSE across checks) */
struct Ev_0033FA80 { volatile unsigned short type; unsigned short b2; char pad4[2]; unsigned short b6; unsigned short btn; };
struct W_0033FA80 { char pad[0x14]; unsigned short flags; };
struct Pair_0033FA80 { __int128 a; __int128 b; };
struct App_0033FA80 { char pad0[0x20]; __int128 q20; char pad30[0x10]; Pair_0033FA80 pairs[1]; };
struct Act_0033FA80 { char pad[0x40]; App_0033FA80 app; };
struct Npc_0033FA80 { char pad[0x60]; char sub60[0x40]; App_0033FA80 app; };
struct Blk_0033FA80 { char d[0x440]; };
struct Info_0033FA80 { int w[63]; };
struct Self_0033FA80 {
    VPAD8(a) VPAD4(b) VPAD2(c) virtual void v14();
    virtual void* GetFocus();
    char pad4[0x48]; unsigned char b4C; char pad4D[0x88 - 0x4D];
    W_0033FA80* f88; Npc_0033FA80* f8C; char pad90[0xEC - 0x90];
    int fEC; int fF0; char padF4[4]; int fF8; char padFC[0x144 - 0xFC];
    void* g144; void* g148; void* g14C; void* g150; void* g154; unsigned char b158;
};
extern "C" {
extern signed char D_00493A60;
extern Blk_0033FA80 D_0055D510[];
extern __int128 D_0055DE10;
#if 0 /* merge_units */
extern char g_AgentPartCache[];
#endif /* merge_units */
#define g_AgentPartCache ((char*)&g_AgentPartCache) /* merge_units */


extern char g_Game[];
extern void* D_004FFC04;
extern char D_00585E90[];
extern char D_004B9EF8[];
extern char D_004B9F00[];
extern char D_004B9F10[];
extern char D_004B9ED0[];
extern char D_004B9EE8[];
int SKL_FindPartIndex(App_0033FA80* app, char* type);
void SKL_RemoveBlanks(Blk_0033FA80* b);
#if 0 /* merge_units */
void Monster_RestoreLockedPartsTex(char* c);
#endif /* merge_units */
#define Monster_RestoreLockedPartsTex(a0) (Monster_RestoreLockedPartsTex((void *)(a0))) /* merge_units */


void* cGameSystem_GetAgentData(void* a, int b);
void cAgentData_SetSkl(void* ag, Blk_0033FA80* b);
void* cDME_GetLobby(void);
void cGameFrontEnd_LobbySetAgentStats(void* a, Info_0033FA80* i);
void SFOLobby_UpdateStats(void* a, Info_0033FA80* i);
void GuiSaveAgentWidget_HandleEvent(Self_0033FA80* self);
char* nGlobalization_GetString_charP(char* key);
void cGameFrontEnd_PushMessageBox(void* fe, int kind, char* a, char* b, Self_0033FA80* self, int c);
void cMotionManager_FlushUpdateList(void);
void* Gui_Manager(void);
#if 0 /* merge_units */
void* GuiManager_OpenGui(void* a, char* b, char* c);
#endif /* merge_units */
#define GuiManager_OpenGui(a0, a1, a2) (GuiManager_OpenGui((a0), (void *)(a1), (void *)(a2))) /* merge_units */


void* Gui_Canvas(void);
#if 0 /* merge_units */
void GuiCanvas_Transition(void* a, void* b, void* c);
#endif /* merge_units */
#define GuiCanvas_Transition(a0, a1, a2) (GuiCanvas_Transition((a0), (int)(a1), (a2))) /* merge_units */


void GuiWidget_SendMessage(void* a, void* b, int kind, int v, int f);
void GuiCanvas_SetFocus(void* ui, void* w);
void GuiAgentModify_MakeChildrenFocusable(Self_0033FA80* self, void* g);
void GuiAgentModify_MakeChildrenNotFocusable(Self_0033FA80* self, void* g);
#if 0 /* merge_units */
void GuiAgentModify_TattooPatchesLockout(Self_0033FA80* self);
#endif /* merge_units */
struct Self; /* merge_units */
void GuiAgentModify_TattooPatchesLockout(Self* self); /* merge_units */
#define GuiAgentModify_TattooPatchesLockout(a0) (GuiAgentModify_TattooPatchesLockout((Self *)(a0))) /* merge_units */

void GuiAgentModify_UserInterface(Self_0033FA80* self, int a, int b);
#if 0 /* merge_units */
void GuiAgentModify_SetBigPatch(Self_0033FA80* self);
#endif /* merge_units */
struct Self_0320; /* merge_units */
void GuiAgentModify_SetBigPatch(Self_0320* self); /* merge_units */
#define GuiAgentModify_SetBigPatch(a0) (GuiAgentModify_SetBigPatch((Self_0320 *)(a0))) /* merge_units */

int GuiAgentModify_onInput(Self_0033FA80* self, Ev_0033FA80* ev);
}

static inline void QCopy_0033FA80(void* d0, void* s0, int n0) { int n = n0; void* d = d0; void* s = s0;
    asm {
        .set noreorder
    loop:
        lq $v0, 0(s)
        addiu d, d, 0x10
        addi n, n, -1
        addiu s, s, 0x10
        bgtz n, loop
        sq $v0, -0x10(d)
        .set reorder
    }
}
static inline __int128 And_0033FA80(__int128 a, __int128 b) { __int128 r; asm { pand r, a, b } return r; }
static inline __int128 Or_0033FA80(__int128 a, __int128 b) { asm { por a, a, b } return a; }
static inline __int128 Not_0033FA80(__int128 a) { __int128 r; asm { pnor r, a, a } return r; }
static inline App_0033FA80* App_0033FA80_(char* s) { return (App_0033FA80*)(s + 0x40); }
static inline unsigned char Down_0033FA80(Ev_0033FA80* e) { unsigned char r = 0; if (e->type == 1 && !e->b2) r = 1; return r; }
static inline unsigned char Btn_0033FA80(Ev_0033FA80* e, int b) { unsigned char r = 0; if (Down_0033FA80(e) != 0 && e->btn == b) r = 1; return r; }
static inline unsigned char Plain_0033FA80(Ev_0033FA80* e, int b) { unsigned char r = 0; if (Btn_0033FA80(e, b) != 0 && e->b6 == 0) r = 1; return r; }

extern "C" int GuiAgentModify_onInput(Self_0033FA80* self, Ev_0033FA80* ev)
{
    if (Plain_0033FA80(ev, 0x40)) {
    }
    if (Plain_0033FA80(ev, 0x80)) {
        int k = SKL_FindPartIndex(App_0033FA80_(self->f8C->sub60), D_004B9EF8);
        if (k != -1) {
            __int128 q;
            Act_0033FA80* a;
            __int128 pa;
            Npc_0033FA80* n;
            __int128 m;
            n = self->f8C;
            a = (Act_0033FA80*)n->sub60;
            m = D_0055DE10;
            q = a->app.q20;
            pa = a->app.pairs[k].a;
            a->app.q20 = Or_0033FA80(And_0033FA80(q, Not_0033FA80(m)), And_0033FA80(pa, m));
        }
        if (D_00493A60 == -1)
            D_00493A60 = 0;
        QCopy_0033FA80(&D_0055D510[D_00493A60], App_0033FA80_(self->f8C->sub60), 0x44);
        SKL_RemoveBlanks(&D_0055D510[D_00493A60]);
        Monster_RestoreLockedPartsTex(g_AgentPartCache);
        cAgentData_SetSkl(cGameSystem_GetAgentData(g_Game, -1), &D_0055D510[D_00493A60]);
        if (cDME_GetLobby()) {
            cDME_GetLobby();
            Info_0033FA80 info = *(Info_0033FA80*)D_00585E90;
            cGameFrontEnd_LobbySetAgentStats(D_004FFC04, &info);
            SFOLobby_UpdateStats(cDME_GetLobby(), &info);
        }
        self->b4C = 1;
        GuiSaveAgentWidget_HandleEvent(self);
        return 1;
    }
    if (Plain_0033FA80(ev, 0x10)) {
        if (self->b158) {
            void* fe = D_004FFC04;
            char* a = nGlobalization_GetString_charP(D_004B9F00);
            char* b = nGlobalization_GetString_charP(D_004B9F10);
            cGameFrontEnd_PushMessageBox(fe, 5, a, b, self, 0xC);
        } else {
            Monster_RestoreLockedPartsTex(g_AgentPartCache);
            cMotionManager_FlushUpdateList();
            void* pg = GuiManager_OpenGui(Gui_Manager(), D_004B9ED0, D_004B9EE8);
            GuiCanvas_Transition(Gui_Canvas(), self, pg);
        }
        return 1;
    }
    if (Plain_0033FA80(ev, 0x2000) && self->fF0) {
        GuiWidget_SendMessage(self, Gui_Canvas(), 0x10, 0, 0);
        if (self->fEC == 2) {
            GuiAgentModify_MakeChildrenFocusable(self, self->g144);
            GuiAgentModify_MakeChildrenNotFocusable(self, self->g154);
            GuiCanvas_SetFocus(Gui_Canvas(), self->GetFocus());
        } else if (self->fEC == 3) {
            GuiAgentModify_MakeChildrenFocusable(self, self->g148);
            GuiAgentModify_MakeChildrenNotFocusable(self, self->g154);
            if (!self->fF8 && self->f88)
                self->f88->flags &= ~2;
            GuiCanvas_SetFocus(Gui_Canvas(), self->GetFocus());
        } else if (self->fEC == 0) {
            GuiAgentModify_MakeChildrenFocusable(self, self->g14C);
            GuiAgentModify_MakeChildrenNotFocusable(self, self->g154);
            GuiAgentModify_TattooPatchesLockout(self);
            GuiCanvas_SetFocus(Gui_Canvas(), self->GetFocus());
        } else if (self->fEC == 1) {
            GuiAgentModify_MakeChildrenFocusable(self, self->g150);
            GuiAgentModify_MakeChildrenNotFocusable(self, self->g154);
            GuiAgentModify_TattooPatchesLockout(self);
            GuiCanvas_SetFocus(Gui_Canvas(), self->GetFocus());
        }
    }
    if (Plain_0033FA80(ev, 0x8000) && !self->fF0) {
        GuiWidget_SendMessage(self, Gui_Canvas(), 0x10, 0, 0);
        GuiAgentModify_MakeChildrenFocusable(self, self->g154);
        if (self->fEC == 2) {
            GuiAgentModify_MakeChildrenNotFocusable(self, self->g144);
            GuiCanvas_SetFocus(Gui_Canvas(), self->g144);
        } else if (self->fEC == 3) {
            GuiAgentModify_MakeChildrenNotFocusable(self, self->g148);
            GuiCanvas_SetFocus(Gui_Canvas(), self->g148);
        } else if (self->fEC == 0) {
            GuiAgentModify_MakeChildrenNotFocusable(self, self->g14C);
            GuiCanvas_SetFocus(Gui_Canvas(), self->g14C);
        } else if (self->fEC == 1) {
            GuiAgentModify_MakeChildrenNotFocusable(self, self->g150);
            GuiCanvas_SetFocus(Gui_Canvas(), self->g150);
        }
        GuiAgentModify_TattooPatchesLockout(self);
    }
    if (Plain_0033FA80(ev, 4)) {
        GuiAgentModify_UserInterface(self, 1, 0);
        if (!self->fF0 && self->fEC == 1)
            GuiAgentModify_SetBigPatch(self);
    }
    if (Plain_0033FA80(ev, 8)) {
        GuiAgentModify_UserInterface(self, 0, 1);
        if (!self->fF0 && self->fEC == 1)
            GuiAgentModify_SetBigPatch(self);
    }
    return 0;
}
#undef g_AgentPartCache /* merge_units */
#undef Monster_RestoreLockedPartsTex /* merge_units */
#undef GuiManager_OpenGui /* merge_units */
#undef GuiCanvas_Transition /* merge_units */
#undef GuiAgentModify_TattooPatchesLockout /* merge_units */
#undef GuiAgentModify_SetBigPatch /* merge_units */
static inline void merge_flush_func_0033FA80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0033FA80 */

/* merge_units: begin func_00340320 */
#pragma push /* merge_units */
#pragma cplusplus on
struct W_0320 { char pad[0x14]; unsigned short flags; };
struct Npc_0320 { char pad[0xF0]; char names[1][0x20]; };
struct Ent_0320 { char* str; char pad[0x10]; };
struct Rel_0320 { int a0; int count; Ent_0320* data; unsigned char own; char pad[3]; };
struct Opts_0320 { char pad[0x25C]; int x25C; };
struct Self_0320 {
    char pad0[0x80];
    W_0320* f80;
    W_0320* f84;
    char pad88[4];
    Npc_0320* f8C;
    char pad90[0xF0 - 0x90];
    int fF0;
    char padF4[0x10D - 0xF4];
    signed char b10D;
};
extern "C" {
extern char D_004B9F20[];
extern char D_004B9F28[];
extern char D_004B9F30[];
extern char D_004B9F38[];
extern char D_004B9F40[];
#if 0 /* merge_units */
extern Opts_0320* D_004FFC04;
#endif /* merge_units */
#define D_004FFC04 (*(Opts_0320 **)&D_004FFC04) /* merge_units */

void GuiBitmapWidget_ClearBitmap(W_0320* w);
void GuiBitmapWidget_SetBitmap(W_0320* w, char* name, int x);
void GuiTextWidget_SetText(W_0320* w, char* s, int x);
char* Libc_Strcpy(char* d, const char* s);
int Libc_Strncmp(const char* a, const char* b, int n);
char* Libc_Strcat(char* d, const char* s);
void cAgentData_GetAchievements(void* ag, unsigned char k, Rel_0320* r);
void cAgentData_GetRatings(void* ag, Rel_0320* r);
void func_00296FA0(Rel_0320* r);
#if 0 /* merge_units */
void func_00299360(Rel_0320* r, int f);
#endif /* merge_units */
void* func_00299360(void* self, short deleteFlag); /* merge_units */
#define func_00299360(a0, a1) ((void)func_00299360((void *)(a0), (short)(a1))) /* merge_units */

int nGlobalization_GetStringIndex(char* k);
char* nGlobalization_GetString_int(int id);
void GuiAgentModify_SetBigPatch(Self_0320* self);
}

extern "C" void GuiAgentModify_SetBigPatch(Self_0320* self)
{
    char buf[0x20];
    char name[0x20];
    int a;
    int b;
    int c;
    if (self->fF0) {
        if (self->f80) {
            GuiBitmapWidget_ClearBitmap(self->f80);
            self->f80->flags &= ~2;
        }
        if (self->f84) {
            GuiTextWidget_SetText(self->f84, D_004B9F20, 0);
            self->f84->flags &= ~2;
        }
    } else {
        if (self->f80)
            GuiBitmapWidget_ClearBitmap(self->f80);
        a = -1;
        b = a;
        c = a;
        Libc_Strcpy(buf, ((char(*)[0x20])((char*)self->f8C + 0xF0))[self->b10D]);
        if (!Libc_Strncmp(&buf[6], D_004B9F28, 3) && buf[10] != 'B') {
            a = buf[10] - '0';
            buf[0] = buf[10];
            buf[1] = '_';
            b = buf[11] - '0';
            buf[2] = buf[11];
            buf[3] = '_';
            buf[4] = buf[12];
            if (buf[13] >= '0' && buf[13] <= '9') {
                c = (buf[12] - '0') * 10;
                c += buf[13] - '1';
                buf[5] = buf[13];
                buf[6] = 's';
                buf[7] = 0;
            } else {
                c = buf[12] - '1';
                buf[5] = 's';
                buf[6] = 0;
            }            Libc_Strcpy(name, buf);
            Libc_Strcat(name, D_004B9F30);
            if (self->f80)
                GuiBitmapWidget_SetBitmap(self->f80, name, D_004FFC04->x25C);
        } else {
            Libc_Strcpy(name, buf);
            Libc_Strcat(name, D_004B9F30);
            if (self->f80)
                GuiBitmapWidget_SetBitmap(self->f80, name, 0);
        }
        if (self->f80)
            self->f80->flags |= 2;
        if (self->f84) {
            if (a != -1) {
                Rel_0320 r;
                char* txt;
                func_00296FA0(&r);
                r.own = 1;
                txt = 0;
                if (b == 2 || b == 4 || (b == 3 && c >= 25)) {
                    if (b == 3) {
                        b = 0;
                        c -= 25;
                    } else if (b == 4) {
                        b = 1;
                    }
                    cAgentData_GetAchievements(cGameSystem_GetAgentData(g_Game, -1), b, &r);
                    if (c < r.count)
                        txt = r.data[c].str;
                } else if (b == 3) {
                    cAgentData_GetRatings(cGameSystem_GetAgentData(g_Game, -1), &r);
                    if (c < r.count)
                        txt = r.data[c].str;
                } else if (b == 6) {
                    txt = nGlobalization_GetString_int(c + nGlobalization_GetStringIndex(D_004B9F38));
                }
                if (txt)
                    GuiTextWidget_SetText(self->f84, txt, 0);
                else
                    GuiTextWidget_SetText(self->f84, D_004B9F40, 0);
                self->f84->flags |= 2;
                func_00299360(&r, 0);
            } else {
                GuiTextWidget_SetText(self->f84, D_004B9F20, 0);
                self->f84->flags &= ~2;
            }
        }
    }
}
#undef D_004FFC04 /* merge_units */
#undef func_00299360 /* merge_units */
static inline void merge_flush_func_00340320(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00340320 */

/* merge_units: begin func_00340700 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "member_dtor_chain.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "base_dtor_chain.h"
#pragma pop

#pragma cplusplus on

/* Deleting destructor that runs the member destructor. */
DEFINE_MEMBER_DTOR_CHAIN(func_00340700, func_00299360)
static inline void merge_flush_func_00340700(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00340700 */

/* merge_units: begin func_00340770 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(func_00340770, func_00299360)
static inline void merge_flush_func_00340770(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00340770 */

/* merge_units: begin func_003407D0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiAgentModify.cc. Functions are named by address
 * until real names are known.
 */


Rel* func_003407D0(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
static inline void merge_flush_func_003407D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003407D0 */

/* merge_units: begin func_003407F0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "direct_base_dtor.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_DIRECT_BASE_DTOR(func_003407F0, func_00299360)
static inline void merge_flush_func_003407F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003407F0 */

/* merge_units: begin func_00340850 */
#pragma push /* merge_units */
#pragma cplusplus on

class Vis {
public:
    VPAD2(a) virtual void v2(); virtual void Show(); virtual void Hide();
};
struct Wid { char pad[0x44]; Vis* vis; };
typedef struct { __int128 q; char pad[0x10]; } Ent;
typedef struct { char pad[0xE0]; Ent e[1]; } Tbl;
struct Self {
    char pad0[0x8C];
    Tbl* tbl;
    char pad90[0x114 - 0x90];
    int idx[6];
    Wid* w[6];
    char pad144[0x14C - 0x144];
    Wid* grp[2];
};
extern "C" {
#if 0 /* merge_units */
extern __int128 g_AgentPartCache;
#endif /* merge_units */
#define g_AgentPartCache (*(__int128*)&g_AgentPartCache) /* merge_units */

extern __int128 D_0055DE00;
void GuiAgentModify_TattooPatchesLockout(Self* self);
}

static inline long KEq(__int128 b, __int128 a, __int128 m)
{
    __int128 t, r;
    asm {
        pand t, m, b
        pand r, m, a
        pceqw r, r, t
        ppach r, r, r
    }
    return r;
}

static inline long Match(Self* self, int k)
{
    return KEq(g_AgentPartCache, self->tbl->e[self->idx[k]].q, D_0055DE00);
}

void GuiAgentModify_TattooPatchesLockout(Self* self)
{
    int n = 0;
    if (Match(self, 0) == -1) self->w[0]->vis->Hide(); else { self->w[0]->vis->Show(); n++; }
    if (Match(self, 1) == -1) self->w[1]->vis->Hide(); else { self->w[1]->vis->Show(); n++; }
    if (Match(self, 2) == -1) self->w[2]->vis->Hide(); else { self->w[2]->vis->Show(); n++; }
    if (n) self->grp[0]->vis->Show(); else self->grp[0]->vis->Hide();
    n = 0;
    if (Match(self, 3) == -1) self->w[3]->vis->Hide(); else { self->w[3]->vis->Show(); n++; }
    if (Match(self, 4) == -1) self->w[4]->vis->Hide(); else { self->w[4]->vis->Show(); n++; }
    if (Match(self, 5) == -1) self->w[5]->vis->Hide(); else { self->w[5]->vis->Show(); n++; }
    if (n) self->grp[1]->vis->Show(); else self->grp[1]->vis->Hide();
}
#undef g_AgentPartCache /* merge_units */
static inline void merge_flush_func_00340850(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00340850 */

/* merge_units: begin func_00340C00 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern char g_AgentPartCache[];
#endif /* merge_units */
#define g_AgentPartCache ((char*)&g_AgentPartCache) /* merge_units */

#if 0 /* merge_units */
extern void Monster_RestoreLockedPartsTex(void* a);
#endif /* merge_units */
#define Monster_RestoreLockedPartsTex(a0) (Monster_RestoreLockedPartsTex((a0))) /* merge_units */

#if 0 /* merge_units */
extern int GuiManager_OpenGui(void* a, const char* b, const char* c);
#endif /* merge_units */
#define GuiManager_OpenGui(a0, a1, a2) ((int)GuiManager_OpenGui((a0), (void *)(a1), (void *)(a2))) /* merge_units */

#if 0 /* merge_units */
extern void GuiCanvas_Transition(void* a, int b, int c);
#endif /* merge_units */
#define GuiCanvas_Transition(a0, a1, a2) (GuiCanvas_Transition((a0), (a1), (void *)(a2))) /* merge_units */

/* Look up an entry and register it with `arg`. */
void GuiAgentModify_NextScreen(int arg)
{
    int entry;
    Monster_RestoreLockedPartsTex(g_AgentPartCache);
    cMotionManager_FlushUpdateList();
    entry = GuiManager_OpenGui(Gui_Manager(), D_004B9ED0, D_004B9EE8);
    GuiCanvas_Transition(Gui_Canvas(), arg, entry);
}
#undef g_AgentPartCache /* merge_units */
#undef Monster_RestoreLockedPartsTex /* merge_units */
#undef GuiManager_OpenGui /* merge_units */
#undef GuiCanvas_Transition /* merge_units */
static inline void merge_flush_func_00340C00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00340C00 */
