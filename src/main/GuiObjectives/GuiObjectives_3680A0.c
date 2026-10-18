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
extern Hud3680A0* D_004FFC2C;
extern char D_00587C90[];
void* ObjMan_GetService(void);
T3680A0* ObjMan_GetObjective(void* mgr, int id);
void List_Begin_16E880(void* out, void* list);
void func_0026C390(void* out, void* raw);
void func_0026C320(void* out, void* list);
void func_0026C350(void* out, void* in);
void HudMarkers_SetHighlight(void* a, I3680A0* item);
void HudMap_Commit(int a);
char* HudMarker_GetTickerText(I3680A0* item, char* buf);
void Notify_Insert(void* list, char* text, void* color, int a, int b);
int GuiTextListWidget_GetItemId(void* list, int a);
int GuiWidget_OnEvent(void* self, void* sender, unsigned short msg, int a3, int a4);
}

/* Tab list message handler: on select (0x13) announce every tracked item bound to the chosen objective. */
extern "C" int GuiObjectives_HandleEvent(S3680A0* self, void* sender, unsigned short msg, int a3, int a4)
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
                T3680A0* obj = ObjMan_GetObjective(ObjMan_GetService(), idx);
                if (obj) {
                    N3680A0* end[1];
                    N3680A0* it[1];
                    void* b[1];
                    int t[1];
                    char buf[0x100];
                    char* base = (char*)D_004FFC2C + 0x90;
                    void* list = base + 0x24;
                    I3680A0* item;
                    N3680A0* n;
                    List_Begin_16E880(b, list);
                    func_0026C390(it, b[0]);
                    for (n = it[0]; func_0026C320(t, list), func_0026C350(end, t), n != end[0]; n = n->next) {
                        item = n->item;
                        if (item->h.Get() != 0 && item->h.Get() == obj) {
                            char* name;
                            HudMarkers_SetHighlight(base, item);
                            HudMap_Commit(D_004FFC2C->a6A0);
                            name = HudMarker_GetTickerText(item, buf);
                            if (name)
                                Notify_Insert((char*)D_004FFC2C + 0x100, name, D_00587C90, 2, 1);
                        }
                    }
                }
            }
            return 1;
        }
    }
    return GuiWidget_OnEvent(self, sender, msg, a3, a4);
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
extern G_368300* D_004FFC2C;
#endif /* merge_units */
#define D_004FFC2C (*(G_368300 **)&D_004FFC2C) /* merge_units */

void GuiObjectives_SetTab(S_368300* o, int page, int f);
M_368300* Gui_GetScreenStack(void);
void GuiWidget_SendEvent(void* w, void* m, int kind, int v, int f);
void GuiStartMenu_ReturnToMenu(S_368300* o);
void GuiStartMenu_CloseAll(S_368300* o);
int GuiObjectives_HandleInput(S_368300* o, Ev_368300* ev);
}
static inline unsigned char Down_368300(Ev_368300* e) { unsigned char r = 0; if (e->type == 1 && e->b2 == 0) r = 1; return r; }
static inline unsigned char Btn_368300(Ev_368300* e, int b) { unsigned char r = 0; if (Down_368300(e) && e->btn == b) r = 1; return r; }
static inline unsigned char Plain_368300(Ev_368300* e, int b) { unsigned char r = 0; if (Btn_368300(e, b) && e->b6 == 0) r = 1; return r; }
static inline bool Down2_368300(Ev_368300* e) { return e->type == 1 && e->b2 == 0; }
static inline bool Btn2_368300(Ev_368300* e, int b) { return Down2_368300(e) && e->btn == b; }
static inline bool Plain2_368300(Ev_368300* e, int b) { return Btn2_368300(e, b) && e->b6 == 0; }

int GuiObjectives_HandleInput(S_368300* o, Ev_368300* ev)
{
    if (Plain_368300(ev, 0x2000)) {
        if (o->page == 0 && o->w64) {
            GuiObjectives_SetTab(o, 1, 0);
            GuiWidget_SendEvent(o->w6C, Gui_GetScreenStack(), 0x10, 0, 0);
        }
        return 1;
    }
    if (Plain2_368300(ev, 0x8000)) {
        if (o->page == 1 && o->w60) {
            GuiObjectives_SetTab(o, 0, 0);
            GuiWidget_SendEvent(o->w68, Gui_GetScreenStack(), 0x10, 0, 0);
        }
        return 1;
    }
    if (Plain2_368300(ev, 0x10)) {
        GuiStartMenu_ReturnToMenu(o);
        return 1;
    }
    if (Plain2_368300(ev, 0x800) && D_004FFC2C->b6A8) {
        GuiStartMenu_CloseAll(o);
        return 1;
    }
    if ((Plain2_368300(ev, 0x4000) || Plain2_368300(ev, 0x1000))
        && (Gui_GetScreenStack()->focus == o->w68 || Gui_GetScreenStack()->focus == o->w6C)) return 1;
    return 0;
}
#undef D_004FFC2C /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00368300 */

/* merge_units: begin func_00368620 */
#pragma push /* merge_units */
typedef struct { char pad[0xD4]; float time; char padD8[0xB71 - 0xD8]; unsigned char flagB71; } AgentT;
typedef struct { char pad[0x70]; void* text; void* text2; char pad78[0x89 - 0x78]; unsigned char useTimer; } S368620;
extern AgentT* Agent_GetSelected(void* list, int idx);
extern float Hud_GetMissionTime(int id);
extern void GuiObjectives_FillList(S368620* self);
extern void GuiTextWidget_SetText(void* text, char* str, int flag);
extern void GuiTextWidget_SetColour(void* text, void* color);
extern void GuiWidget_Update(S368620* self, float dt);
extern int sprintf(char* buf, const char* fmt, ...);
extern char D_004BBC48[];
extern char D_004FFB50[];
#if 0 /* merge_units */
extern int D_004FFC2C;
#endif /* merge_units */
#define D_004FFC2C (*(int*)&D_004FFC2C) /* merge_units */

extern char D_00587D00[];
extern char D_00587D10[];

void GuiObjectives_Update(S368620* self, float dt) {
    char buf[32];
    float f;

    GuiWidget_Update(self, dt);
    GuiObjectives_FillList(self);
    if (self->text != 0) {
        if (self->useTimer) {
            f = Hud_GetMissionTime(D_004FFC2C);
        } else {
            f = Agent_GetSelected(D_004FFB50, -1)->time;
            asm { .set reorder } /* scheduling barrier: keeps cvt at the join, not in the b delay slot */
        }
        { int t = f; int m = t / 60; sprintf(buf, D_004BBC48, m, t - m * 60); }
        if (!self->useTimer) {
            if (Agent_GetSelected(D_004FFB50, -1)->flagB71) {
                GuiTextWidget_SetColour(self->text, D_00587D00);
                GuiTextWidget_SetColour(self->text2, D_00587D00);
            } else {
                GuiTextWidget_SetColour(self->text, D_00587D10);
                GuiTextWidget_SetColour(self->text2, D_00587D10);
            }
        }
        GuiTextWidget_SetText(self->text, buf, 0);
    }
}
#undef D_004FFC2C /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00368620 */
