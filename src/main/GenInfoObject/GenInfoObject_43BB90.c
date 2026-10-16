/*
 * main/GenInfoObject: 4 files, 0043BB90-0043BD50
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0043BB90 */
#pragma push /* merge_units */
#include "types.h"
extern int strcmp(const char*, const char*);
/* Returns whether the string equals the table name. */
int func_0043BB90(void* a0, const char* s) { return strcmp("GuiScrollBarWidget", s) == 0; }
#pragma pop /* merge_units */
/* merge_units: end func_0043BB90 */

/* merge_units: begin func_0043BBC0 */
#pragma push /* merge_units */
typedef struct { char p[0x48]; unsigned char vis; char p49[3]; int x0; int x1; char p54[4]; int v; int lo; int hi; } W43BBC0;
extern void GuiWidget_BroadcastEvent(W43BBC0* w, int kind, int pos, int z);
#pragma push
static inline float Mul43BBC0(float a, float b) { return a * b; }
static inline int Lerp43BBC0(int a, int b, float t) { return a + (int)Mul43BBC0(t, (float)(b - a)); }
void func_0043BBC0(W43BBC0* w, int v)
{
    w->v = v < w->lo ? w->lo : (w->hi < v ? w->hi : v);
    if (w->vis) {
        int lo = w->lo;
int x0 = w->x0;
        GuiWidget_BroadcastEvent(w, 11, Lerp43BBC0(x0, w->x1, (float)(w->v - lo) / (float)(w->hi - lo)), 0);
    }
}
#pragma pop
#pragma pop /* merge_units */
/* merge_units: end func_0043BBC0 */

/* merge_units: begin func_0043BC70 */
#pragma push /* merge_units */
typedef struct { char p[0x48]; unsigned char vis; char p49[3]; int x0; int x1; unsigned char b54; char p55[3]; int v; int lo; int hi; } W43BC70;
#if 0 /* merge_units */
extern void GuiWidget_BroadcastEvent(W43BC70* w, int kind, int pos, int z);
#endif /* merge_units */
#define GuiWidget_BroadcastEvent(a0, a1, a2, a3) (GuiWidget_BroadcastEvent((W43BBC0 *)(a0), (a1), (a2), (a3))) /* merge_units */

#pragma push
static inline float Mul43BC70(float a, float b) { return a * b; }
static inline int Lerp43BC70(int a, int b, float t) { return a + (int)Mul43BC70(t, (float)(b - a)); }
void func_0043BC70(W43BC70* w, unsigned char b, int v, int lo, int hi)
{
    w->b54 = b;
    w->lo = hi < lo ? hi : lo;
    w->hi = hi < lo ? lo : hi;
    w->v = v < w->lo ? w->lo : (w->hi < v ? w->hi : v);
    if (w->vis) {
        int lo = w->lo;
int x0 = w->x0;
        GuiWidget_BroadcastEvent(w, 10, Lerp43BC70(x0, w->x1, (float)(w->v - lo) / (float)(w->hi - lo)), 0);
    }
}
#pragma pop
#undef GuiWidget_BroadcastEvent /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0043BC70 */

/* merge_units: begin func_0043BD50 */
#pragma push /* merge_units */
typedef struct { char p[0x48]; unsigned char vis; char p49[3]; int x0; int x1; char p54[4]; int v; int lo; int hi; } W43BD50;
#if 0 /* merge_units */
extern void GuiWidget_BroadcastEvent(W43BD50* w, int kind, int pos, int z);
#endif /* merge_units */
#define GuiWidget_BroadcastEvent(a0, a1, a2, a3) (GuiWidget_BroadcastEvent((W43BBC0 *)(a0), (a1), (a2), (a3))) /* merge_units */

#pragma push
static inline float Mul43BD50(float a, float b) { return a * b; }
static inline int Lerp43BD50(int a, int b, float t) { return a + (int)Mul43BD50(t, (float)(b - a)); }
void func_0043BD50(W43BD50* w, int horiz)
{
    if (w->vis) {
        int lo = w->lo;
int x0 = w->x0;
        GuiWidget_BroadcastEvent(w, horiz ? 10 : 11, Lerp43BD50(x0, w->x1, (float)(w->v - lo) / (float)(w->hi - lo)), 0);
    }
}
#pragma pop
#undef GuiWidget_BroadcastEvent /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0043BD50 */
