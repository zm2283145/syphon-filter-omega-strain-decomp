/*
 * SFOGame/Source/GuiMapScreen: 4 files, 00464890-00464B00
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00464890 */
#pragma push /* merge_units */
#include "types.h"
extern int strcmp(void* p);
/* Returns whether the test on the global object fails. */
int GuiMapScreen_IsClass(void) { return strcmp("GuiMapScreen") == 0; }
static inline void merge_flush_func_00464890(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00464890 */

/* merge_units: begin func_004648C0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Ev48C0 { unsigned short type; unsigned short sub; unsigned short x4; unsigned short x6; unsigned short key; };
struct W48C0 { char pad[0x4C]; int m4C; };
extern int g_Hud;
extern "C" {
void cHud_ToggleMap(int a);
void cMap_ResetCamera(int a);
int cMap_PreviousObjective(int a);
int cMap_NextObjective(int a);
void cMap_StopSeekCountdown(int a);
void cMap_StartSeekCountdown(int a);
int Gui_Canvas(void);
void GuiWidget_SendMessage(W48C0* self, int a, int b, int c, int d);
}
extern "C" int GuiMapScreen_onInput(W48C0* self, Ev48C0* e)
{
    bool press = false;
    bool down = false;
    if (e->type == 1 && e->sub == 0)
        down = true;
    if (down && e->x6 == 0)
        press = true;
    if (press) {
        switch (e->key) {
        case 0x10:
            cHud_ToggleMap(g_Hud);
            break;
        case 0x100:
            cMap_ResetCamera(self->m4C);
            break;
        case 8:
            cMap_StartSeekCountdown(self->m4C);
            if (cMap_NextObjective(self->m4C))
                GuiWidget_SendMessage(self, Gui_Canvas(), 0x10, 0, 0);
            break;
        case 4:
            cMap_StartSeekCountdown(self->m4C);
            if (cMap_PreviousObjective(self->m4C))
                GuiWidget_SendMessage(self, Gui_Canvas(), 0x10, 0, 0);
            break;
        default:
            return 0;
        }
        return 1;
    }
    {
        bool r = e->type == 1 && e->sub == 0 && e->x6 == 1;
        if (r) {
            switch (e->key) {
            case 8:
            case 4:
                cMap_StopSeekCountdown(self->m4C);
                return 1;
            }
        }
    }
    return 0;
}
static inline void merge_flush_func_004648C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004648C0 */

/* merge_units: begin func_00464A90 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

struct Child {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09();
    virtual void Method30(); /* +0x30 */
};

typedef struct Holder {
    char pad[0x14];
    unsigned short flags; /* +0x14 */
    char pad16[0x44 - 0x16];
    Child* child;         /* +0x44 */
} Holder;

typedef struct Widget {
    char pad[0x48];
    Holder* holder; /* +0x48 */
    void* unk4C;    /* +0x4C */
} Widget;

extern "C" void cMap_Render(void* p);
extern "C" void GuiWidget_onRender(Widget* self);

/* Sets flag 0x2 on the +0x48 object while notifying its +0x44 child (virtual +0x30), then cMap_Render(+0x4C) and GuiWidget_onRender(self). */
extern "C" void GuiMapScreen_onRender(Widget* self)
{
    self->holder->flags |= 2;
    self->holder->child->Method30();
    self->holder->flags &= ~2;
    cMap_Render(self->unk4C);
    GuiWidget_onRender(self);
}
static inline void merge_flush_func_00464A90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00464A90 */

/* merge_units: begin func_00464B00 */
#pragma push /* merge_units */
typedef struct Obj4C {
    char pad[0x4C];
    int handle;
} Obj4C;

extern void GuiWidget_onSleep(Obj4C*);
extern void cMap_Deactivate(int);

/* Calls GuiWidget_onSleep, releases the handle at +0x4C and clears it. */
void GuiMapScreen_onSleep(Obj4C* o) {
    GuiWidget_onSleep(o);
    cMap_Deactivate(o->handle);
    o->handle = 0;
}
static inline void merge_flush_func_00464B00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00464B00 */
