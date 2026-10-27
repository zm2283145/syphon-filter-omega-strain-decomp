/*
 * main/GuiObjectives: 3 files, 003680A0-00368620
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

void GuiObjectives_SetActiveTab(S_368300* o, int page, int f);
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
#pragma pop /* merge_units */
/* merge_units: end func_00368300 */

/* merge_units: begin func_00368620 */
#pragma push /* merge_units */
typedef struct { char pad[0xD4]; float time; char padD8[0xB71 - 0xD8]; unsigned char flagB71; } AgentT;
typedef struct { char pad[0x70]; void* text; void* text2; char pad78[0x89 - 0x78]; unsigned char useTimer; } S368620;
extern AgentT* cGameSystem_GetAgentData(void* list, int idx);
extern float cHud_GetMissionTime(int id);
extern void GuiObjectives_UpdateObjectives(S368620* self);
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
#undef g_Hud /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00368620 */
