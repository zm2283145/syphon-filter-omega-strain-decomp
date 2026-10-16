/*
 * main/GuiGameOptions: range (6 files, 002998B0-0029A100)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "message_two_member_dtor.h"
#pragma pop

/* merge_units: begin func_002998B0 */
#pragma push /* merge_units */
void GuiGameOptions_UpdateHints(int arg0); /* gsynth: defined below */
#pragma cplusplus on
struct V2998B0 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); };
typedef struct { V2998B0 v; char pad[0x10]; unsigned short flags; } E2998B0;
typedef struct {
    char pad0[0x20];
    int x20;
    char pad24[0x8C - 0x24];
    E2998B0* items[4];
    void* objs[4];
    E2998B0* xAC;
    int padB0;
    int idx;
} S2998B0;
extern "C" {
void* Gui_GetScreenStack(void);
void GuiScreen_SetFocus(void* a, int b);
void GuiWidget_SendEvent(void* a, void* b, int c, int d, int e);
#if 0 /* merge_units */
void GuiGameOptions_UpdateHints(S2998B0* s);
#endif /* merge_units */
#define GuiGameOptions_UpdateHints(a0) (GuiGameOptions_UpdateHints((int)(a0))) /* merge_units */

}
extern "C" void GuiGameOptions_Enter(S2998B0* s)
{
    if (s->items[s->idx]) {
        int r;
        s->items[s->idx]->flags |= 4;
        r = s->items[s->idx]->v.v15();
        GuiScreen_SetFocus(Gui_GetScreenStack(), r);
        s->x20 = r;
    }
    if (s->xAC)
        s->xAC->flags &= ~4;
    if (s->objs[s->idx]) {
        GuiWidget_SendEvent(s, s->objs[s->idx], 10, 10, 0);
        GuiWidget_SendEvent(s->objs[s->idx], Gui_GetScreenStack(), 0x10, 0, 0);
    }
    GuiGameOptions_UpdateHints(s);
}
#undef GuiGameOptions_UpdateHints /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002998B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002998B0 */

/* merge_units: begin func_002999B0 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
int Loc_LookupText(int *, int );                    
int GuiTextWidget_SetText(int, int, int);                       

#pragma opt_common_subs off
void GuiGameOptions_UpdateHints(int arg0) {
    int *var_a0;
    int temp_a1;
    int temp_a1_2;

    if (F_(arg0, 0x400, unsigned char) != 0) {
        temp_a1 = F_(arg0, 0x80, int);
        if (temp_a1 != NULL) {
            if (F_(arg0, 0xB4, int) != 3) {
                F_(temp_a1, 0x14, unsigned short) = (unsigned short) (F_(temp_a1, 0x14, unsigned short) | 2);
            } else {
                F_(temp_a1, 0x14, unsigned short) = (unsigned short) (F_(temp_a1, 0x14, unsigned short) & 0xFFFD);
            }
        }
        temp_a1_2 = F_(arg0, 0x84, int);
        if (temp_a1_2 != NULL) {
            if (F_(arg0, 0xB4, int) == 3) {
                F_(temp_a1_2, 0x14, unsigned short) = (unsigned short) (F_(temp_a1_2, 0x14, unsigned short) | 2);
            } else {
                F_(temp_a1_2, 0x14, unsigned short) = (unsigned short) (F_(temp_a1_2, 0x14, unsigned short) & 0xFFFD);
            }
        }
        if (F_(arg0, 0x88, int) != 0) {
            if (F_(arg0, 0xB4, int) == 3) {
                var_a0 = ((int*)"ToKick");
            } else {
                var_a0 = ((int*)"ToSave");
            }
            GuiTextWidget_SetText(F_(arg0, 0x88, int), Loc_LookupText(var_a0, temp_a1_2), 0);
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002999B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002999B0 */

/* merge_units: begin func_00299AA0 */
#pragma push /* merge_units */
typedef struct { char pad0[0x14]; unsigned short flags; } W_299AA0;
typedef struct {
    char pad0[0x8C];
    W_299AA0* tabs[4];
    char* labels[4];
    char padAC[4];
    void* xB0;
    int xB4;
    char padB8[0x430 - 0xB8];
    void* x430;
    char pad434[0x448 - 0x434];
    char* names[4];
} S_299AA0;
extern char D_004AA780[];
#if 0 /* merge_units */
int GuiTextWidget_SetText(void* w, char* text, int c);
#endif /* merge_units */
#define GuiTextWidget_SetText(a0, a1, a2) (GuiTextWidget_SetText((int)(a0), (int)(a1), (a2))) /* merge_units */

void GuiArrayWidget_Select(void* w, int a, int b);
#if 0 /* merge_units */
void GuiGameOptions_UpdateHints(S_299AA0* self);
#endif /* merge_units */
#define GuiGameOptions_UpdateHints(a0) (GuiGameOptions_UpdateHints((int)(a0))) /* merge_units */


void GuiGameOptions_Show(S_299AA0* self, int idx) {
    int i;
    for (i = 0; i < 4; i++) {
        if (self->tabs[i]) {
            self->tabs[i]->flags &= ~2;
        }
    }
    if (self->xB0 && self->labels[idx]) {
        GuiTextWidget_SetText(self->xB0, self->names[idx] ? self->names[idx] : D_004AA780, 0);
    }
    self->tabs[idx]->flags |= 2;
    switch (idx) {
    case 3:
        if (self->x430) {
            GuiArrayWidget_Select(self->x430, 0, 0);
        }
        break;
    }
    self->xB4 = idx;
    GuiGameOptions_UpdateHints(self);
}
#undef GuiTextWidget_SetText /* merge_units */
#undef GuiGameOptions_UpdateHints /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00299AA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00299AA0 */

/* merge_units: begin func_00299B90 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Ev_00299B90 { unsigned short type; unsigned short f2; unsigned short f4; unsigned short f6; unsigned short btn; };
struct W_00299B90 { char pad0[0x10]; int f10; unsigned short flags; char pad16[0x4E]; int x64; };
struct Ui_00299B90 { char pad[0x20]; W_00299B90* f20; };
struct S_00299B90 {
    char pad0[0x1C]; Ui_00299B90* x1C; char pad20[0x84 - 0x20]; W_00299B90* p84;
    char pad88[0xB8 - 0x88]; char xB8[0xC]; float fC4; char padC8[0x270 - 0xC8];
    char action[0x400 - 0x270]; unsigned char b400; char pad401[0x41C - 0x401]; W_00299B90* p41C;
};
extern "C" {
typedef struct SoundRequest {
    char pad000[0x48];
    char partA[0x9C];
    char partB[0xAC];
} SoundRequest;
typedef struct SoundMsg {
    void* vtbl;
    char pad004[0x1C];
    unsigned char flag;
    char pad021[0x57];
    char partA[0x9C];
    char partB[0xAC];
} SoundMsg;
typedef struct SoundEventMsg {
    void* vtbl;
    char pad004[0x1C];
    unsigned char flag;
    char pad021[0x57];
    char partA[0x9C];
    char partB[0xAC];
    char pad1C0[0x10];
} SoundEventMsg;
extern char* D_0048B908;
extern char D_004FFB50[];
extern char D_004DADF0[];
extern char D_004DAE10[];
#if 0 /* merge_units */
Ui_00299B90* Gui_GetScreenStack(void);
#endif /* merge_units */
#define Gui_GetScreenStack() ((Ui_00299B90 *)Gui_GetScreenStack()) /* merge_units */

void GuiGameOptions_ShowMenu(S_00299B90* self);
void GuiGameOptions_Leave(S_00299B90* self);
#if 0 /* merge_units */
void GuiGameOptions_Enter(S_00299B90* self);
#endif /* merge_units */
#define GuiGameOptions_Enter(a0) (GuiGameOptions_Enter((S2998B0 *)(a0))) /* merge_units */

void GuiGameOptions_Close(S_00299B90* self, int a);
void GuiStartMenu_CloseAll(S_00299B90* self);
void GameOptions_Apply(void* p, int n);
void SoundRequest_Ctor(SoundRequest* req, int kind, void* name, int a, int b);
void SoundEvent_Ctor(SoundEventMsg* msg, void* action, int flags);
void Event_Send(void* msg, void* target, int flags);
#if 0 /* merge_units */
void FileMan_Release(void* part, int flags);
#endif /* merge_units */
#define FileMan_Release(a0, a1) (FileMan_Release((a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void cMessage_dtor(void* msg, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((a0), (a1))) /* merge_units */

void SoundAction_CtorVoice(void* action, int kind, char* voice, int a, int b);
void SoundMsg_WrapAction(SoundMsg* msg, void* action);
}
static inline unsigned char Down_00299B90(Ev_00299B90* e)
{
    unsigned char r = 0;
    if (e->type == 1 && e->f2 == 0)
        r = 1;
    return r;
}
static inline unsigned char Btn_00299B90(Ev_00299B90* e, unsigned int b)
{
    unsigned char r = 0;
    if (Down_00299B90(e) && e->btn == b)
        r = 1;
    return r;
}
static inline unsigned char Press_00299B90(Ev_00299B90* e, unsigned int b)
{
    unsigned char r = 0;
    if (Btn_00299B90(e, b) && e->f6 == 0)
        r = 1;
    return r;
}
static inline bool Held_00299B90(Ev_00299B90* e, unsigned int b)
{
    return e->type == 1 && e->f2 == 0 && e->btn == b && e->f6 == 1;
}
/* Options page input handler: back/confirm/select buttons, gamma slider sound preview, default fallback. */
extern "C" int GuiGameOptions_HandleInput(S_00299B90* self, Ev_00299B90* ev)
{
    {
        bool b = ev->type == 1 && ev->f2 == 0 && ev->btn == 0x10 && ev->f6 == 0;
        if (b) {
            if (!Gui_GetScreenStack()->f20 || Gui_GetScreenStack()->f20->f10 != -1) {
                GuiGameOptions_Close(self, 0);
                if (self->x1C == Gui_GetScreenStack()) {
                    GuiGameOptions_Leave(self);
                    return 1;
                }
            } else {
                GuiGameOptions_ShowMenu(self);
                return 1;
            }
        }
    }
    {
        bool b = ev->type == 1 && ev->f2 == 0 && ev->btn == 0x2000 && ev->f6 == 0;
        if (b && Gui_GetScreenStack()->f20->f10 != -1) {
            GuiGameOptions_Enter(self);
            return 1;
        }
    }
    if (Press_00299B90(ev, 0x80)) {
        if (self->b400 && self->p84 && (self->p84->flags & 2))
            return 1;
        GuiGameOptions_Close(self, 1);
        return 1;
    }
    {
        if (Held_00299B90(ev, 0x8000) || Held_00299B90(ev, 0x2000)) {
            W_00299B90* w;
            if (Gui_GetScreenStack()->f20 == (w = self->p41C)) {
                SoundEventMsg evm;
                SoundMsg play;
                SoundRequest req;
                self->fC4 = w->x64 / 100.0f;
                GameOptions_Apply(self->xB8, 0x20);
                SoundRequest_Ctor(&req, 4, D_0048B908, 0, 0);
                SoundEvent_Ctor(&evm, &req, 0);
                FileMan_Release(req.partB, -1);
                FileMan_Release(req.partA, -1);
                evm.flag = 1;
                Event_Send(&evm, D_004FFB50, 1);
                SoundAction_CtorVoice(self->action, 4, D_0048B908, 0, 0);
                SoundMsg_WrapAction(&play, self->action);
                play.flag = 1;
                Event_Send(&play, D_004FFB50, 1);
                play.vtbl = D_004DAE10;
                FileMan_Release(play.partB, -1);
                FileMan_Release(play.partA, -1);
                cMessage_dtor(&play, 0);
                evm.vtbl = D_004DADF0;
                FileMan_Release(evm.partB, -1);
                FileMan_Release(evm.partA, -1);
                cMessage_dtor(&evm, 0);
                return 1;
            }
        }
    }
    if (Press_00299B90(ev, 0x8000))
        return 1;
    {
        bool b = ev->type == 1 && ev->f2 == 0 && ev->btn == 0x800 && ev->f6 == 0;
        if (b && self->b400) {
            GuiStartMenu_CloseAll(self);
            return 1;
        }
    }
    return 0;
}
#undef Gui_GetScreenStack /* merge_units */
#undef GuiGameOptions_Enter /* merge_units */
#undef FileMan_Release /* merge_units */
#undef cMessage_dtor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00299B90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00299B90 */

/* merge_units: begin func_0029A070 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Message destructor: payload members, then cMessage base. */
DEFINE_MESSAGE_TWO_MEMBER_DTOR(func_0029A070, D_004DAE10)
#pragma pop /* merge_units */
/* merge_units: end func_0029A070 */

/* merge_units: begin func_0029A100 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Message destructor: payload members, then cMessage base. */
DEFINE_MESSAGE_TWO_MEMBER_DTOR(func_0029A100, D_004DADF0)
#pragma pop /* merge_units */
/* merge_units: end func_0029A100 */
