/*
 * SFOGame/Source/GuiAgentInfo: 5 files, 00361000-00361730
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00361000 */
#pragma push /* merge_units */
/* GuiAgentInfo_SetupWidgets: fill the agent score sheet (name, team, rank, ratings and award columns, stats
 * table, rank badge, online buttons). */
#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"

struct W_1000 { char p0[0x14]; unsigned short flags; };
class Wid_1000 {
public:
    VPAD16(a) VPAD4(b) virtual int IsA(void* type); virtual void SetCols(int n, int h);
};
struct Rec_1000 { int x0; int key; char p8[0xC]; };
struct Vec_1000 { int x0; int count; Rec_1000* data; unsigned char own; char pD[3]; };
struct Fe_1000 { char p0[0x25C]; int img; };
struct Self_1000 {
    char p0[0x88];
    int vals[12];               /* +0x88 */
    char strB8[0xC];            /* +0xB8 */
    char strC4[0xC];            /* +0xC4 */
    int rank;                   /* +0xD0 */
    unsigned char flags[6][4];  /* +0xD4 */
    unsigned char award[8];     /* +0xEC */
    unsigned char bF4;          /* +0xF4 */
    char pF5[3];
    int xF8;                    /* +0xF8 */
    int team;                   /* +0xFC */
    W_1000* w100;               /* +0x100 */
    W_1000* w104;               /* +0x104 */
    W_1000* w108;               /* +0x108 */
    Wid_1000* w10C;             /* +0x10C */
    Wid_1000* w110;             /* +0x110 */
    W_1000* w114;               /* +0x114 */
    W_1000* w118;               /* +0x118 */
    void* w11C;                 /* +0x11C */
};

extern "C" {
extern char g_Game[];
extern Fe_1000* D_004FFC04;
extern char D_004BB868[], D_004BB8B0[], D_004BB8C0[], D_004BB8D0[], D_004BB8E0[], D_004BB8F0[], D_004BB8F8[];
extern char D_004BB908[], D_004BB910[], D_004BB920[], D_004BB928[], D_004BB930[], D_004BB940[], D_004BB948[];
extern char D_004A7520[];
extern char D_00587BE0[], D_00587BD0[];
void* cGameSystem_GetAgentData(void* a, int b);
char* std_basic_string_char_char_traits_char_c_str(void* str);
void GuiTextWidget_SetText(void* w, char* text, int flags);
char* nGlobalization_GetString_charP(char* key);
char* nGlobalization_GetStringTag(int key);
int sprintf(char* buf, const char* fmt, ...);
Wid_1000* GuiWidget_FindChild_charP(void* self, char* name);
void GuiTextArrayWidget_SetTextFormat(Wid_1000* w, int a);
void GuiArrayWidget_SetColumnWidth(Wid_1000* w, int col, int width);
void GuiTextArrayWidget_SetText(Wid_1000* w, int col, int row, char* text);
void GuiTextArrayWidget_SetElementTextColor(Wid_1000* w, int col, int row, char* colour);
void GuiTextArrayWidget_SetElementTextFormat(Wid_1000* w, int col, int row, int align);
void func_00296FA0(Vec_1000* v);
void func_00299360(Vec_1000* v, int f);
void cAgentData_GetRatings(void* ag, Vec_1000* v);
void cAgentData_GetAchievements(void* ag, int a, Vec_1000* v);
void GuiBitmapWidget_SetBitmap(void* w, char* name, int img);
void* cDME_GetLobby(void);
int SFOLobby_CellContainsAgent(void* lb, int id, int f);
int SFOLobby_ContactListContainsAgent(void* lb, int id, int f);
void GuiAgentInfo_SetupWidgets(Self_1000* self);
}

extern "C" void GuiAgentInfo_SetupWidgets(Self_1000* self)
{
    void* ag = cGameSystem_GetAgentData(g_Game, -1);
    char buf[0x10];
    char* t;
    GuiTextWidget_SetText(self->w100, std_basic_string_char_char_traits_char_c_str(self->strB8), 0);
    t = std_basic_string_char_char_traits_char_c_str(self->strC4);
    if (!t || !*t)
        t = nGlobalization_GetString_charP(D_004BB8B0);
    GuiTextWidget_SetText(self->w108, t ? t : D_004BB868, 0);
    sprintf(buf, D_004BB8C0, self->rank + 1);
    t = nGlobalization_GetString_charP(buf);
    GuiTextWidget_SetText(self->w104, t ? t : D_004BB868, 0);
    {
        Wid_1000* c = GuiWidget_FindChild_charP(self, D_004BB8D0);
        c = (c && c->IsA(D_004A7520)) ? c : 0;
        if (c)
            GuiTextWidget_SetText(c, nGlobalization_GetString_charP(self->team == 1 ? D_004BB8E0 : D_004BB8F0), 0);
    }
    self->w10C->SetCols(2, 8);
    GuiTextArrayWidget_SetTextFormat(self->w10C, 2);
    GuiArrayWidget_SetColumnWidth(self->w10C, 0, 0x70);
    GuiArrayWidget_SetColumnWidth(self->w10C, 1, 10);
    {
        Vec_1000 r;
        int j;
        int i;
        func_00296FA0(&r);
        r.own = 1;
        cAgentData_GetRatings(cGameSystem_GetAgentData(g_Game, -1), &r);
        j = 0;
        for (i = 0; i < 6; i++) {
            char line[0x20];
            int idx = -1;
            int k;
            char* s;
            for (k = 0; k < 4; k++, j++) {
                if (self->flags[i][k]) idx = j;
            }
            if (idx == -1) {
                s = nGlobalization_GetString_charP(D_004BB8F8);
            } else {
                sprintf(line, D_004BB908, nGlobalization_GetStringTag(r.data[idx].key));
                s = nGlobalization_GetString_charP(line);
            }
            GuiTextArrayWidget_SetText(self->w10C, 0, i, s);
        }
        {
            Vec_1000 a;
            func_00296FA0(&a);
            a.own = 1;
            cAgentData_GetAchievements(ag, 0, &a);
            int n;
            for (n = 0; n < a.count && n < 8; n++) {
                if (self->award[n]) {
                    char line[0x20];
                    sprintf(line, D_004BB908, nGlobalization_GetStringTag(((Rec_1000*)((char*)a.data + n * sizeof(Rec_1000)))->key));
                    GuiTextArrayWidget_SetText(self->w10C, 1, n, nGlobalization_GetString_charP(line));
                }
            }
            func_00299360(&a, 0);
        }
        func_00299360(&r, 0);
    }
    self->w110->SetCols(2, 0xC);
    GuiArrayWidget_SetColumnWidth(self->w110, 0, 0xA0);
    GuiArrayWidget_SetColumnWidth(self->w110, 1, 10);
    {
        int i;
        for (i = 0; i < 12; i++) {
            char line[0x20];
            sprintf(line, D_004BB910, i);
            GuiTextArrayWidget_SetText(self->w110, 0, i, nGlobalization_GetString_charP(line));
            if (i == 6 || i == 7)
                sprintf(line, D_004BB920, self->vals[i]);
            else
                sprintf(line, D_004BB928, self->vals[i]);
            GuiTextArrayWidget_SetText(self->w110, 1, i, line);
            GuiTextArrayWidget_SetElementTextColor(self->w110, 0, i, D_00587BE0);
            GuiTextArrayWidget_SetElementTextFormat(self->w110, 0, i, 2);
            GuiTextArrayWidget_SetElementTextColor(self->w110, 1, i, D_00587BD0);
            GuiTextArrayWidget_SetElementTextFormat(self->w110, 1, i, 1);
        }
    }
    {
        char line[0x20];
        W_1000* b1;
        W_1000* b2;
        sprintf(line, D_004BB930, self->rank + 1);
        GuiBitmapWidget_SetBitmap(self->w11C, line, D_004FFC04->img);
        b1 = (W_1000*)GuiWidget_FindChild_charP(self, D_004BB940);
        b2 = (W_1000*)GuiWidget_FindChild_charP(self, D_004BB948);
        if (b1) {
            if (self->team == 1) b1->flags |= 2;
            else b1->flags &= ~2;
        }
        if (b2) {
            if (self->team == 1) b2->flags |= 2;
            else b2->flags &= ~2;
        }
    }
    if (self->team == 1) {
        void* lb;
        self->w114->flags |= 2;
        self->w118->flags |= 2;
        lb = cDME_GetLobby();
        if (!lb || self->xF8 == -1) {
            self->w118->flags &= ~4;
            self->w114->flags &= ~4;
        } else {
            unsigned char ok;
            if (self->bF4) {
                ok = !SFOLobby_CellContainsAgent(lb, self->xF8, 1);
                {
                    W_1000* w = self->w118;
                    if (ok) w->flags |= 4;
                    else w->flags &= ~4;
                }
            } else {
                self->w118->flags &= ~4;
            }
            ok = !SFOLobby_ContactListContainsAgent(lb, self->xF8, 1);
            {
                W_1000* w = self->w114;
                if (ok) w->flags |= 4;
                else w->flags &= ~4;
            }
        }
    } else {
        self->w114->flags &= ~2;
        self->w118->flags &= ~2;
    }
}
static inline void merge_flush_func_00361000(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00361000 */

/* merge_units: begin func_003616E0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * GuiAgentInfo virtual (vtable GuiAgentInfo_vtable slot 12); extends the base handler
 * GuiLobbyScreen_onAdvanceTime.
 */

#include "loose03_types.h"

extern void GuiLobbyScreen_onAdvanceTime(GuiAgentInfo*);
extern Obj4147A0* Gui_Canvas(void);

/* Calls the base handler, then clears target->unk4E0 unless this screen is the current one. */
void GuiAgentInfo_Update(GuiAgentInfo* self) {
    GuiLobbyScreen_onAdvanceTime(self);
    if (self->unk120 != 0 && Gui_Canvas()->unk2C->unk08 != self) {
        self->unk120->unk4E0 = 0;
    }
}
static inline void merge_flush_func_003616E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003616E0 */

/* merge_units: begin func_00361730 */
#pragma push /* merge_units */
typedef struct { char pad[0xB8]; char sB8[0x40]; int aF8; char padFC[0x18]; int a114; int a118; } S361730;
#if 0 /* merge_units */
extern int std_basic_string_char_char_traits_char_c_str(void* p);
#endif /* merge_units */
#define std_basic_string_char_char_traits_char_c_str(a0) ((int)std_basic_string_char_char_traits_char_c_str((a0))) /* merge_units */

extern void GuiLobbyScreen_CellInviteAgent(S361730* o, int a, int b);
extern void GuiLobbyScreen_ContactInviteAgent(S361730* o, int a, int b);
extern int GuiLobbyScreen_onMessage(S361730* o);
int GuiAgentInfo_onMessage(S361730* o, int id, unsigned short type)
{
    if (type == 2) {
        if (id == o->a118) {
            GuiLobbyScreen_CellInviteAgent(o, o->aF8, std_basic_string_char_char_traits_char_c_str(o->sB8));
            return 1;
        }
        if (id == o->a114) {
            GuiLobbyScreen_ContactInviteAgent(o, o->aF8, std_basic_string_char_char_traits_char_c_str(o->sB8));
            return 1;
        }
    }
    return GuiLobbyScreen_onMessage(o);
}
#undef std_basic_string_char_char_traits_char_c_str /* merge_units */
static inline void merge_flush_func_00361730(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00361730 */

/* merge_units: begin func_003617C0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct W_3617C0 { char pad[0x14]; unsigned short flags; };
class M_3617C0 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void Close(void* w);
};
struct L_3617C0 { char pad[0x14]; char list[0xC]; };
struct P_3617C0 { char pad[0x4E0]; float zoom; };
struct S_3617C0 { char pad[0x10]; W_3617C0* w10; char pad14[0xE8]; int fFC; char pad100[0x20]; P_3617C0* p120; };
struct Ev_3617C0 { unsigned short type; unsigned short b2; char pad4[2]; unsigned short b6; unsigned short btn; };
typedef struct { void* n; } It_3617C0;
extern "C" {
L_3617C0* Gui_Manager(void);
#if 0 /* merge_units */
M_3617C0* Gui_Canvas(void);
#endif /* merge_units */
#define Gui_Canvas() ((M_3617C0 *)Gui_Canvas()) /* merge_units */

void* GuiManager_OpenGui(void* mgr, char* a, char* b);
void GuiCanvas_Transition(void* mgr, S_3617C0* o, void* w);
void cLList_GuiWidgetPtr_Find(It_3617C0* out, void* list, W_3617C0** val);
void cLList_GuiWidgetPtr_End(It_3617C0* out, void* list);
int opNe_cLListIteratorR_cLListIteratorR_6(It_3617C0* a, It_3617C0* b);
int GuiLobbyScreen_onInput(S_3617C0* o);
int GuiAgentInfo_onInput(S_3617C0* o, Ev_3617C0* ev);
}
static inline unsigned char Down_3617C0(Ev_3617C0* e) { unsigned char r = 0; if (e->type == 1 && e->b2 == 0) r = 1; return r; }
static inline unsigned char Btn_3617C0(Ev_3617C0* e, int b) { unsigned char r = 0; if (Down_3617C0(e) && e->btn == b) r = 1; return r; }
static inline unsigned char Plain_3617C0(Ev_3617C0* e, int b) { unsigned char r = 0; if (Btn_3617C0(e, b) && e->b6 == 0) r = 1; return r; }
static inline bool Down2_3617C0(Ev_3617C0* e) { return e->type == 1 && e->b2 == 0; }
static inline bool Btn2_3617C0(Ev_3617C0* e, int b) { return Down2_3617C0(e) && e->btn == b; }
static inline bool NoMod2_3617C0(Ev_3617C0* e) { return Down2_3617C0(e) && e->b6 == 0; }

int GuiAgentInfo_onInput(S_3617C0* o, Ev_3617C0* ev)
{
    if (Plain_3617C0(ev, 0x10)) {
        if (o->fFC == 0) {
            void* w = GuiManager_OpenGui(Gui_Manager(), "GuiDossiers", "DOSSIERS");
            GuiCanvas_Transition(Gui_Canvas(), o, w);
        } else {
            W_3617C0* w = o->w10;
            if (w) {
                W_3617C0* val = w;
                It_3617C0 res;
                It_3617C0 end;
                L_3617C0* l = Gui_Manager();
                cLList_GuiWidgetPtr_Find(&res, l->list, &val);
                cLList_GuiWidgetPtr_End(&end, l->list);
                if (opNe_cLListIteratorR_cLListIteratorR_6(&res, &end)) w->flags |= 2;
            }
            Gui_Canvas()->Close(o);
        }
        return 1;
    }
    if (Btn2_3617C0(ev, 2)) {
        o->p120->zoom += NoMod2_3617C0(ev) ? -1.0f : 1.0f;
        return 1;
    }
    if (Btn2_3617C0(ev, 1)) {
        o->p120->zoom += NoMod2_3617C0(ev) ? 1.0f : -1.0f;
        return 1;
    }
    return GuiLobbyScreen_onInput(o);
}
#undef Gui_Canvas /* merge_units */
static inline void merge_flush_func_003617C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003617C0 */

/* merge_units: begin func_00361A70 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * GuiAgentInfo virtual (vtable GuiAgentInfo_vtable slot 2); calls the GuiWidget
 * implementation GuiWidget_onRemove, then cGameFrontEnd_CloseCharacter(D_004FFC04, 0).
 */


#if 0 /* merge_units */
extern int D_004FFC04;
#endif /* merge_units */
#define D_004FFC04 (*(int*)&D_004FFC04) /* merge_units */

extern int cGameFrontEnd_CloseCharacter(int, int);
extern int GuiWidget_onRemove(GuiAgentInfo*);

int GuiMissionLobbyScreen_onRemove(GuiAgentInfo* self) {
    GuiWidget_onRemove(self);
    return cGameFrontEnd_CloseCharacter(D_004FFC04, 0);
}
#undef D_004FFC04 /* merge_units */
static inline void merge_flush_func_00361A70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00361A70 */
