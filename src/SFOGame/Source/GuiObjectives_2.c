/*
 * SFOGame/Source/GuiObjectives: 6 files, 003680A0-00368760
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003680A0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"

struct T3680A0 { char pad[0xC]; int serial; };
struct H3680A0 {
    T3680A0* p;
    int serial;
    bool Valid() { return !p || p->serial == serial; }
    T3680A0* Get() { return Valid() ? p : 0; }
};
struct I3680A0 { char pad[0x14]; H3680A0 h; };
struct N3680A0 { int pad0; N3680A0* next; I3680A0* item; };
struct S3680A0 { char pad[0x48]; void* w48; char pad4C[0x5C - 0x4C]; int sel; };
struct Hud3680A0 { char pad[0x6A0]; int a6A0; };

extern "C" {
extern Hud3680A0* g_Hud;
extern char D_00587C90[];
void* ObjMan_GetService(void);
T3680A0* cObjectiveMan_GetObjective(void* mgr, int id);
void std_list_deleter_voidPtr_begin_void_2(void* out, void* list);
void std_list_cHudTargetInfoPtr_generic_iterator_1_ctor(void* out, void* raw);
void std_list_cHudTargetInfoPtr_end_void(void* out, void* list);
void cConstLListIterator_cHudTargetInfoPtr_ctor(void* out, void* in);
void cHudTargetManager_SetObjectiveTarget(void* a, I3680A0* item);
void cMap_ObjectiveSelected(int a);
char* cHudTargetInfo_GetObjectiveLocationString(I3680A0* item, char* buf);
void cInfoBar_AddMessage(void* list, char* text, void* color, int a, int b);
int GuiTextListWidget_GetItemId(void* list, int a);
int GuiWidget_onMessage(void* self, void* sender, unsigned short msg, int a3, int a4);
}

/* Tab list message handler: on select (0x13) announce every tracked item bound to the chosen objective. */
extern "C" int GuiObjectives_onMessage(S3680A0* self, void* sender, unsigned short msg, int a3, int a4)
{
    if (msg == 0x10 && a3 == 1 && sender != self->w48) return 1;
    if (sender == self->w48) {
        int idx = GuiTextListWidget_GetItemId(self->w48, a4);
        if (msg == 0x14) {
            self->sel = idx;
            return 1;
        }
        if (msg == 0x13) {
            if (idx != -1) {
                T3680A0* obj = cObjectiveMan_GetObjective(ObjMan_GetService(), idx);
                if (obj) {
                    N3680A0* end[1];
                    N3680A0* it[1];
                    void* b[1];
                    int t[1];
                    char buf[0x100];
                    char* base = (char*)g_Hud + 0x90;
                    void* list = base + 0x24;
                    I3680A0* item;
                    N3680A0* n;
                    std_list_deleter_voidPtr_begin_void_2(b, list);
                    std_list_cHudTargetInfoPtr_generic_iterator_1_ctor(it, b[0]);
                    for (n = it[0]; std_list_cHudTargetInfoPtr_end_void(t, list), cConstLListIterator_cHudTargetInfoPtr_ctor(end, t), n != end[0]; n = n->next) {
                        item = n->item;
                        if (item->h.Get() != 0 && item->h.Get() == obj) {
                            char* name;
                            cHudTargetManager_SetObjectiveTarget(base, item);
                            cMap_ObjectiveSelected(g_Hud->a6A0);
                            name = cHudTargetInfo_GetObjectiveLocationString(item, buf);
                            if (name)
                                cInfoBar_AddMessage((char*)g_Hud + 0x100, name, D_00587C90, 2, 1);
                        }
                    }
                }
            }
            return 1;
        }
    }
    return GuiWidget_onMessage(self, sender, msg, a3, a4);
}
static inline void merge_flush_func_003680A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003680A0 */

/* merge_units: begin func_00368300 */
#pragma push /* merge_units */
#pragma cplusplus on
struct M_368300 { char pad[0x20]; void* focus; };
struct S_368300 { char pad[0x58]; int page; char pad5C[4]; void* w60; void* w64; void* w68; void* w6C; };
struct Ev_368300 { unsigned short type; unsigned short b2; char pad4[2]; unsigned short b6; unsigned short btn; };
struct G_368300 { char pad[0x6A8]; unsigned char b6A8; };
extern "C" {
#if 0 /* merge_units */
extern G_368300* g_Hud;
#endif /* merge_units */
#define g_Hud (*(G_368300 **)&g_Hud) /* merge_units */


#if 0 /* merge_units */
void GuiObjectives_SetActiveTab(S_368300* o, int page, int f);
#endif /* merge_units */
void GuiObjectives_SetActiveTab(void*, int, int); /* merge_units */
#define GuiObjectives_SetActiveTab(a0, a1, a2) (GuiObjectives_SetActiveTab((void *)(a0), (a1), (a2))) /* merge_units */

M_368300* Gui_Canvas(void);
void GuiWidget_SendMessage(void* w, void* m, int kind, int v, int f);
void GuiStartMenu_ReturnToMenu(S_368300* o);
void GuiStartMenu_PopStartMenu(S_368300* o);
int GuiObjectives_onInput(S_368300* o, Ev_368300* ev);
}
static inline unsigned char Down_368300(Ev_368300* e) { unsigned char r = 0; if (e->type == 1 && e->b2 == 0) r = 1; return r; }
static inline unsigned char Btn_368300(Ev_368300* e, int b) { unsigned char r = 0; if (Down_368300(e) && e->btn == b) r = 1; return r; }
static inline unsigned char Plain_368300(Ev_368300* e, int b) { unsigned char r = 0; if (Btn_368300(e, b) && e->b6 == 0) r = 1; return r; }
static inline bool Down2_368300(Ev_368300* e) { return e->type == 1 && e->b2 == 0; }
static inline bool Btn2_368300(Ev_368300* e, int b) { return Down2_368300(e) && e->btn == b; }
static inline bool Plain2_368300(Ev_368300* e, int b) { return Btn2_368300(e, b) && e->b6 == 0; }

int GuiObjectives_onInput(S_368300* o, Ev_368300* ev)
{
    if (Plain_368300(ev, 0x2000)) {
        if (o->page == 0 && o->w64) {
            GuiObjectives_SetActiveTab(o, 1, 0);
            GuiWidget_SendMessage(o->w6C, Gui_Canvas(), 0x10, 0, 0);
        }
        return 1;
    }
    if (Plain2_368300(ev, 0x8000)) {
        if (o->page == 1 && o->w60) {
            GuiObjectives_SetActiveTab(o, 0, 0);
            GuiWidget_SendMessage(o->w68, Gui_Canvas(), 0x10, 0, 0);
        }
        return 1;
    }
    if (Plain2_368300(ev, 0x10)) {
        GuiStartMenu_ReturnToMenu(o);
        return 1;
    }
    if (Plain2_368300(ev, 0x800) && g_Hud->b6A8) {
        GuiStartMenu_PopStartMenu(o);
        return 1;
    }
    if ((Plain2_368300(ev, 0x4000) || Plain2_368300(ev, 0x1000))
        && (Gui_Canvas()->focus == o->w68 || Gui_Canvas()->focus == o->w6C)) return 1;
    return 0;
}
#undef g_Hud /* merge_units */
#undef GuiObjectives_SetActiveTab /* merge_units */
static inline void merge_flush_func_00368300(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00368300 */

/* merge_units: begin func_00368620 */
#pragma push /* merge_units */
typedef struct { char pad[0xD4]; float time; char padD8[0xB71 - 0xD8]; unsigned char flagB71; } AgentT;
typedef struct { char pad[0x70]; void* text; void* text2; char pad78[0x89 - 0x78]; unsigned char useTimer; } S368620;
extern AgentT* cGameSystem_GetAgentData(void* list, int idx);
extern float cHud_GetMissionTime(int id);
#if 0 /* merge_units */
extern void GuiObjectives_UpdateObjectives(S368620* self);
#endif /* merge_units */
void GuiObjectives_UpdateObjectives(void*); /* merge_units */
#define GuiObjectives_UpdateObjectives(a0) (GuiObjectives_UpdateObjectives((void *)(a0))) /* merge_units */

extern void GuiTextWidget_SetText(void* text, char* str, int flag);
extern void GuiTextWidget_SetTextColor(void* text, void* color);
extern void GuiWidget_onAdvanceTime(S368620* self, float dt);
extern int sprintf(char* buf, const char* fmt, ...);
extern char D_004BBC48[];
extern char g_Game[];
#if 0 /* merge_units */
extern int g_Hud;
#endif /* merge_units */
#define g_Hud (*(int*)&g_Hud) /* merge_units */


extern char D_00587D00[];
extern char D_00587D10[];

void GuiObjectives_onAdvanceTime(S368620* self, float dt) {
    char buf[32];
    float f;

    GuiWidget_onAdvanceTime(self, dt);
    GuiObjectives_UpdateObjectives(self);
    if (self->text != 0) {
        if (self->useTimer) {
            f = cHud_GetMissionTime(g_Hud);
        } else {
            f = cGameSystem_GetAgentData(g_Game, -1)->time;
            asm { .set reorder } /* scheduling barrier: keeps cvt at the join, not in the b delay slot */
        }
        { int t = f; int m = t / 60; sprintf(buf, D_004BBC48, m, t - m * 60); }
        if (!self->useTimer) {
            if (cGameSystem_GetAgentData(g_Game, -1)->flagB71) {
                GuiTextWidget_SetTextColor(self->text, D_00587D00);
                GuiTextWidget_SetTextColor(self->text2, D_00587D00);
            } else {
                GuiTextWidget_SetTextColor(self->text, D_00587D10);
                GuiTextWidget_SetTextColor(self->text2, D_00587D10);
            }
        }
        GuiTextWidget_SetText(self->text, buf, 0);
    }
}
#undef GuiObjectives_UpdateObjectives /* merge_units */
#undef g_Hud /* merge_units */
static inline void merge_flush_func_00368620(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00368620 */

/* merge_units: begin func_00368760 */
#pragma push /* merge_units */
typedef struct { char pad[0x64]; int a64; char pad68[0x70 - 0x68]; void* text; void* text2; char pad78[0x89 - 0x78]; unsigned char useTimer; } S368620_00368760;
#if 0 /* merge_units */
extern void GuiObjectives_UpdateObjectives(S368620_00368760* self);
#endif /* merge_units */
#define GuiObjectives_UpdateObjectives(a0) (GuiObjectives_UpdateObjectives((void *)(a0))) /* merge_units */

extern void GuiWidget_onWake(S368620_00368760* self);
#if 0 /* merge_units */
extern void GuiObjectives_SetActiveTab(S368620_00368760* self, int a, int b);
#endif /* merge_units */
#define GuiObjectives_SetActiveTab(a0, a1, a2) (GuiObjectives_SetActiveTab((void *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern int g_Hud;
#endif /* merge_units */
#define g_Hud (*(int*)&g_Hud) /* merge_units */


void GuiObjectives_onWake(S368620_00368760* self) {
    char buf[32];
    float f;

    GuiWidget_onWake(self);
    if (self->text != 0) {
        if (self->useTimer) {
            f = cHud_GetMissionTime(g_Hud);
        } else {
            f = cGameSystem_GetAgentData(g_Game, -1)->time;
            asm { .set reorder } /* scheduling barrier: keeps cvt at the join, not in the b delay slot */
        }
        { int t = f; int m = t / 60; sprintf(buf, D_004BBC48, m, t - m * 60); }
        if (!self->useTimer) {
            if (cGameSystem_GetAgentData(g_Game, -1)->flagB71) {
                GuiTextWidget_SetTextColor(self->text, D_00587D00);
                GuiTextWidget_SetTextColor(self->text2, D_00587D00);
            } else {
                GuiTextWidget_SetTextColor(self->text, D_00587D10);
                GuiTextWidget_SetTextColor(self->text2, D_00587D10);
            }
        }
        GuiTextWidget_SetText(self->text, buf, 0);
    }
    GuiObjectives_UpdateObjectives(self);
    GuiObjectives_SetActiveTab(self, 0, !self->a64);
}
#undef GuiObjectives_UpdateObjectives /* merge_units */
#undef GuiObjectives_SetActiveTab /* merge_units */
#undef g_Hud /* merge_units */
static inline void merge_flush_func_00368760(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00368760 */

/* merge_units: begin func_003688C0 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_3688C0;
struct W_3688C0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual int IsA(void* t);
    char pad4[0x10];
    unsigned short flags;
    char pad16[0x38 - 0x16];
    float f38;
    char pad3C[4];
    float f40;
    char pad44[0x5C - 0x44];
    int f5C;
    char pad60[0x88 - 0x60];
    W_3688C0* f88;
    char pad8C[0xB0 - 0x8C];
    V4_3688C0 cB0;
};
typedef struct {
    char pad[0x48]; W_3688C0* slots[3]; W_3688C0* f54; char pad58[8]; W_3688C0* f60; W_3688C0* f64;
    W_3688C0* f68; W_3688C0* f6C; W_3688C0* f70; W_3688C0* f74; int f78; int f7C; W_3688C0* f80; int f84;
} O_3688C0;
extern "C" {
extern char D_004BBC90[]; extern char D_004BBCB0[]; extern char D_004BBCC8[]; extern char D_004BBCD0[]; extern char D_004BBCE0[];
extern char D_004BBD00[]; extern char D_004BBD18[]; extern char D_004BBD20[]; extern char D_004BBD38[]; extern char D_004BBD48[];
extern char D_004BBD58[]; extern char D_004BBD68[]; extern char D_004BBD70[]; extern char D_004BBD80[]; extern char D_004BBD88[];
extern char D_004A9870[]; extern char D_004AA640[]; extern char D_004A7520[];
extern char g_LevelDirName[];
extern unsigned char g_IsMultiplayer;
static const unsigned int dat_00492F60[2] = { 0x3, 0x0 };
extern V4_3688C0 D_00587CE0; extern V4_3688C0 D_00587CC0;
void GuiWidget_onAdd(O_3688C0* o);
W_3688C0* GuiWidget_FindChild_charP(void* o, char* name);
int sprintf(char* buf, const char* fmt, ...);
void GuiTextListWidget_SetFont(W_3688C0* w, char* s);
void GuiArrayWidget_SetRowHeight(W_3688C0* w, int v);
int cAgentData_GetParTime(void* p, unsigned char f);
void Libc_Strcpy(void* d, char* s);
#if 0 /* merge_units */
void GuiTextWidget_SetText(W_3688C0* w, char* s, int f);
#endif /* merge_units */
#define GuiTextWidget_SetText(a0, a1, a2) (GuiTextWidget_SetText((void *)(a0), (a1), (a2))) /* merge_units */


char* nGlobalization_GetString_charP(char* k);
void GuiTextWidget_SetDisableWrap(W_3688C0* w, int v);
void GuiObjectives_onAdd(O_3688C0* o);
}
static inline W_3688C0* Cast_3688C0(W_3688C0* w, void* t) { return w && w->IsA(t) ? w : 0; }
static inline void SetC_3688C0(W_3688C0* w, V4_3688C0 c) { w->cB0.x = c.x; w->cB0.y = c.y; w->cB0.z = c.z; w->cB0.w = c.w; }

void GuiObjectives_onAdd(O_3688C0* o)
{
    int i;
    W_3688C0* t;
    GuiWidget_onAdd(o);
    o->f60 = GuiWidget_FindChild_charP(o, D_004BBC90);
    o->f64 = GuiWidget_FindChild_charP(o, D_004BBCB0);
    if (o->f64) {
        o->f68 = Cast_3688C0(GuiWidget_FindChild_charP(o, D_004BBCC8), D_004A9870);
        o->f6C = Cast_3688C0(GuiWidget_FindChild_charP(o, D_004BBCD0), D_004A9870);
        if (o->f68) o->f68->flags &= ~0x80;
        if (o->f6C) o->f6C->flags &= ~0x80;
    } else {
        o->f68 = 0;
        o->f6C = 0;
    }
    o->f80 = GuiWidget_FindChild_charP(o, D_004BBCE0);
    for (i = 0; i < 4; i++) {
        char name[32];
        sprintf(name, D_004BBD00, i);
        o->slots[i] = Cast_3688C0(GuiWidget_FindChild_charP(o, name), D_004AA640);
        if (o->slots[i]) {
            GuiTextListWidget_SetFont(o->slots[i], D_004BBD18);
            if (i == 0) {
                W_3688C0* w = GuiWidget_FindChild_charP(o, D_004BBD20);
                if (w) w->flags &= ~2;
                SetC_3688C0(o->slots[i], D_00587CE0);
                o->slots[i]->f88 = w;
            } else {
                SetC_3688C0(o->slots[i], D_00587CC0);
            }
            o->slots[i]->flags &= ~0x80;
            GuiArrayWidget_SetRowHeight(o->slots[i], o->slots[i]->f5C - (*(int*)dat_00492F60));
        }
    }
    if (o->f54) {
        o->f78 = (int)o->f54->f38;
        o->f7C = (int)o->f54->f40;
        if (o->f80) o->f84 = (int)(o->f80->f38 - (float)o->f78);
    }
    o->f70 = Cast_3688C0(GuiWidget_FindChild_charP(o, D_004BBD38), D_004A7520);
    o->f74 = Cast_3688C0(GuiWidget_FindChild_charP(o, D_004BBD48), D_004A7520);
    t = Cast_3688C0(GuiWidget_FindChild_charP(o, D_004BBD58), D_004A7520);
    if (t) {
        char buf[32];
        int r = cAgentData_GetParTime(g_LevelDirName, g_IsMultiplayer);
        if (r < 0) Libc_Strcpy(buf, D_004BBD68);
        else {
            int m = r / 60;
            r -= m * 60;
            sprintf(buf, D_004BBC48, m, r);
        }
        GuiTextWidget_SetText(t, buf, 0);
    }
    t = Cast_3688C0(GuiWidget_FindChild_charP(o, D_004BBD70), D_004A7520);
    if (t) {
        char* s = nGlobalization_GetString_charP(g_IsMultiplayer ? D_004BBD80 : D_004BBD88);
        if (s) {
            GuiTextWidget_SetText(t, s, 0);
            GuiTextWidget_SetDisableWrap(t, 1);
        }
    }
}
#undef GuiTextWidget_SetText /* merge_units */
static inline void merge_flush_func_003688C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003688C0 */

/* merge_units: begin func_00368E10 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * GuiObjectives constructor (vtable D_004DF5C0).
 */

#include "loose03_types.h"

extern char D_004DF5C0[];       /* GuiObjectives vtable */
extern void GuiWidget_ctor(GuiObjectives*);

/* GuiObjectives constructor. */
GuiObjectives* GuiObjectives_ctor(GuiObjectives* self, int a1, int a2) {
    GuiWidget_ctor(self);
    self->base.vtable = D_004DF5C0;
    self->unk5C = -1;
    self->unk58 = 0;
    self->unk78 = 0;
    self->unk7C = 0;
    self->unk84 = 0;
    self->unk88 = a1;
    self->unk89 = a2;
    return self;
}
static inline void merge_flush_func_00368E10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00368E10 */
