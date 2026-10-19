/*
 * main/GuiNetJoinMission: 3 files, 002A97E0-002A98D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002A97E0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_002A96A0(int, int);

int func_002A97E0(int a0) {
    return func_002A96A0(a0, 0);
}
#pragma pop /* merge_units */
/* merge_units: end func_002A97E0 */

/* merge_units: begin func_002A97F0 */
#pragma push /* merge_units */
typedef struct { char pad[0x8C]; void* x8C; int x90; int pad94; int pad98; int x9C; } S2A97F0;
extern int GuiTextListWidget_GetItemId(int a, int b);
extern char* GuiTextListWidget_GetItemText(int a, int b);
extern void GuiTextWidget_SetText(void* w, char* text, int f);
#if 0 /* merge_units */
extern void func_002A96A0(S2A97F0* s, int f);
#endif /* merge_units */
#define func_002A96A0(a0, a1) ((void)func_002A96A0((int)(a0), (a1))) /* merge_units */

extern int GuiScreen_HandleEvent(S2A97F0* s, int a, unsigned short b, int c, int d);
int GuiOnlineOptions_HandleEvent(S2A97F0* s, int a, unsigned short b, int c, int d)
{
    if (s->x90 == a && b == 0x13) {
        s->x9C = GuiTextListWidget_GetItemId(s->x90, d);
        if (s->x8C)
            GuiTextWidget_SetText(s->x8C, GuiTextListWidget_GetItemText(s->x90, d), 0);
    }
    if (b == 0x1A && c == 0x1E) {
        func_002A96A0(s, 0);
        return 1;
    }
    return GuiScreen_HandleEvent(s, a, b, c, d);
}
#undef func_002A96A0 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A97F0 */

/* merge_units: begin func_002A98D0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Ev_002A98D0 { unsigned short type; unsigned short f2; unsigned short f4; unsigned short f6; unsigned short btn; };
struct S_002A98D0 { char pad0[0x98]; int f98; int f9C; };
extern "C" {
#if 0 /* merge_units */
void func_002A96A0(S_002A98D0* self, int a);
#endif /* merge_units */
#define func_002A96A0(a0, a1) ((void)func_002A96A0((int)(a0), (a1))) /* merge_units */

void func_002A9A20(S_002A98D0* self);
int GuiScreen_HandleInput(S_002A98D0* self, Ev_002A98D0* ev);
}
static inline unsigned char Down_002A98D0(Ev_002A98D0* e)
{
    unsigned char r = 0;
    if (e->type == 1 && e->f2 == 0)
        r = 1;
    return r;
}
static inline unsigned char Btn_002A98D0(Ev_002A98D0* e, unsigned int b)
{
    unsigned char r = 0;
    if (Down_002A98D0(e) && e->btn == b)
        r = 1;
    return r;
}
static inline unsigned char Press_002A98D0(Ev_002A98D0* e, unsigned int b)
{
    unsigned char r = 0;
    if (Btn_002A98D0(e, b) && e->f6 == 0)
        r = 1;
    return r;
}
extern "C" int GuiOnlineOptions_HandleInput(S_002A98D0* self, Ev_002A98D0* ev)
{
    if (Press_002A98D0(ev, 0x10)) {
        if (self->f98 == -1 && self->f9C != -1)
            func_002A9A20(self);
        else
            func_002A96A0(self, 1);
        return 1;
    } else {
        bool b = ev->type == 1 && ev->f2 == 0 && ev->btn == 0x80 && ev->f6 == 0;
        if (b) {
            if (self->f9C == -1 || self->f9C == self->f98)
                func_002A96A0(self, 1);
            else
                func_002A9A20(self);
            return 1;
        }
    }
    return GuiScreen_HandleInput(self, ev);
}
#undef func_002A96A0 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A98D0 */
