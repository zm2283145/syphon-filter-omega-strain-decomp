/*
 * main/GuiSliderWidget: 6 files, 0043EED0-0043F200
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0043EED0 */
#pragma push /* merge_units */
#include "types.h"

extern int strcmp(const char* a, const char* b); /* strcmp */
char D_004C0220[] = "GuiSliderWidget"; /* "GuiSliderWidget" */

/* GuiSliderWidget type check: true when name equals the class name "GuiSliderWidget". */
int GuiSliderWidget_IsType(void* self, const char* name) {
    return strcmp(D_004C0220, name) == 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_0043EED0 */

/* merge_units: begin func_0043EF00 */
#pragma push /* merge_units */
typedef struct { char p[0x48]; int sel; unsigned char vis[4]; int x0[2]; int x1[2]; char p60[4]; int v; int lo; int hi; } W43EF00;
extern void GuiWidget_BroadcastEvent(W43EF00* w, int kind, int pos, int z);
#pragma push
static inline float Mul43EF00(float a, float b) { return a * b; }
static inline int Lerp43EF00(int a, int b, float t) { return a + (int)Mul43EF00(t, (float)(b - a)); }
void func_0043EF00(W43EF00* w, int sel)
{
    w->sel = sel;
    if (w->vis[w->sel]) {
        int lo = w->lo;
int x0 = w->x0[w->sel];
        GuiWidget_BroadcastEvent(w, 10, Lerp43EF00(x0, w->x1[w->sel], (float)(w->v - lo) / (float)(w->hi - lo)), 0);
    }
}
#pragma pop
#pragma pop /* merge_units */
/* merge_units: end func_0043EF00 */

/* merge_units: begin func_0043EFA0 */
#pragma push /* merge_units */
typedef struct { char p[0x48]; int sel; unsigned char vis[4]; int x0[2]; int x1[2]; char p60[4]; int v; int lo; int hi; } W43EFA0;
extern void GuiWidget_SendEventUp(void* w, int kind, int v, int z);
#if 0 /* merge_units */
extern void GuiWidget_BroadcastEvent(W43EFA0* w, int kind, int pos, int z);
#endif /* merge_units */
#define GuiWidget_BroadcastEvent(a0, a1, a2, a3) (GuiWidget_BroadcastEvent((W43EF00 *)(a0), (a1), (a2), (a3))) /* merge_units */

#pragma push
static inline float Mul43EFA0(float a, float b) { return a * b; }
static inline int Lerp43EFA0(int a, int b, float t) { return a + (int)Mul43EFA0(t, (float)(b - a)); }
void func_0043EFA0(W43EFA0* w, int notify)
{
    if (w->vis[w->sel]) {
        int lo = w->lo;
int x0 = w->x0[w->sel];
        GuiWidget_BroadcastEvent(w, 10, Lerp43EFA0(x0, w->x1[w->sel], (float)(w->v - lo) / (float)(w->hi - lo)), 0);
        if (notify) GuiWidget_SendEventUp(w, 0x1D, w->v, 0);
    }
}
#pragma pop
#undef GuiWidget_BroadcastEvent /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0043EFA0 */

/* merge_units: begin func_0043F070 */
#pragma push /* merge_units */
typedef struct { char p[0x48]; int sel; unsigned char vis[4]; int x0[2]; int x1[2]; char p60[4]; int v; int lo; int hi; } W43F070;
#if 0 /* merge_units */
extern void GuiWidget_BroadcastEvent(W43F070* w, int kind, int pos, int z);
#endif /* merge_units */
#define GuiWidget_BroadcastEvent(a0, a1, a2, a3) (GuiWidget_BroadcastEvent((W43EF00 *)(a0), (a1), (a2), (a3))) /* merge_units */

#pragma push
static inline float Mul43F070(float a, float b) { return a * b; }
static inline int Lerp43F070(int a, int b, float t) { return a + (int)Mul43F070(t, (float)(b - a)); }
void func_0043F070(W43F070* w, int v)
{
    w->v = v < w->lo ? w->lo : (w->hi < v ? w->hi : v);
    if (w->vis[w->sel]) {
        int lo = w->lo;
int x0 = w->x0[w->sel];
        GuiWidget_BroadcastEvent(w, 10, Lerp43F070(x0, w->x1[w->sel], (float)(w->v - lo) / (float)(w->hi - lo)), 0);
        GuiWidget_SendEventUp(w, 0x1D, w->v, 0);
    }
}
#pragma pop
#undef GuiWidget_BroadcastEvent /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0043F070 */

/* merge_units: begin func_0043F150 */
#pragma push /* merge_units */
typedef struct { char p[0x48]; int sel; unsigned char vis[4]; int x0[2]; int x1[2]; unsigned char b60; char p61[3]; int v; int lo; int hi; int f70; } W43F150;
#if 0 /* merge_units */
extern void GuiWidget_BroadcastEvent(W43F150* w, int kind, int pos, int z);
#endif /* merge_units */
#define GuiWidget_BroadcastEvent(a0, a1, a2, a3) (GuiWidget_BroadcastEvent((W43EF00 *)(a0), (a1), (a2), (a3))) /* merge_units */

#pragma push
static inline float Mul43F150(float a, float b) { return a * b; }
static inline int Lerp43F150(int a, int b, float t) { return a + (int)Mul43F150(t, (float)(b - a)); }
void GuiSliderWidget_Set(W43F150* w, unsigned char b, int v, int lo, int hi, int f70)
{
    w->b60 = b;
    w->v = v;
    w->lo = lo;
    w->hi = hi;
    w->f70 = f70;
    if (w->vis[w->sel]) {
        int lo2 = w->lo;
int x0 = w->x0[w->sel];
        GuiWidget_BroadcastEvent(w, 10, Lerp43F150(x0, w->x1[w->sel], (float)(w->v - lo2) / (float)(w->hi - lo2)), 0);
    }
}
#pragma pop
#undef GuiWidget_BroadcastEvent /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0043F150 */

/* merge_units: begin func_0043F200 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { char p[0x48]; int sel; unsigned char vis[4]; int x0[2]; int x1[2]; unsigned char b60; char p61[3]; int v; int lo; int hi; int f70; } W43F200;
typedef struct { unsigned short type; unsigned short dev; unsigned short b4; unsigned short action; unsigned short key; } Ev43F200;
extern "C" {
void GuiWidget_SendEventUp(void* w, int kind, int v, int z);
#if 0 /* merge_units */
void GuiWidget_BroadcastEvent(W43F200* w, int kind, int pos, int z);
#endif /* merge_units */
#define GuiWidget_BroadcastEvent(a0, a1, a2, a3) (GuiWidget_BroadcastEvent((W43EF00 *)(a0), (a1), (a2), (a3))) /* merge_units */

}
static inline float Mul43F200(float a, float b) { return a * b; }
static inline int Lerp43F200(int a, int b, float t) { return a + (int)Mul43F200(t, (float)(b - a)); }
static inline void Set43F200(W43F200* w, int v)
{
    w->v = v < w->lo ? w->lo : (w->hi < v ? w->hi : v);
    if (w->vis[w->sel]) {
        int lo = w->lo;
int x0 = w->x0[w->sel];
        GuiWidget_BroadcastEvent(w, 10, Lerp43F200(x0, w->x1[w->sel], (float)(w->v - lo) / (float)(w->hi - lo)), 0);
        GuiWidget_SendEventUp(w, 0x1D, w->v, 0);
    }
}
static inline unsigned char IsBtn43F200(Ev43F200* e)
{
    unsigned char r = 0;
    if (e->type == 1 && e->dev == 0)
        r = 1;
    return r;
}
static inline bool IsKey43F200(Ev43F200* e, unsigned short k)
{
    bool r = 0;
    if (IsBtn43F200(e) && e->key == k)
        r = 1;
    return r;
}
static inline bool Pressed43F200(Ev43F200* e, unsigned short k)
{
    bool r = 0;
    if (IsKey43F200(e, k) && e->action == 0)
        r = 1;
    return r;
}
static inline bool Pressed2_43F200(Ev43F200* e, unsigned short k)
{
    return e->type == 1 && e->dev == 0 && e->key == k && e->action == 0;
}
extern "C" int GuiSliderWidget_OnInput(W43F200* w, Ev43F200* e)
{
    if (w->b60 == 1) {
        if (Pressed43F200(e, 0x1000)) {
            Set43F200(w, w->v - w->f70);
            return 1;
        }
        if (Pressed2_43F200(e, 0x4000)) {
            Set43F200(w, w->v + w->f70);
            return 1;
        }
    } else {
        if (Pressed43F200(e, 0x8000)) {
            Set43F200(w, w->v - w->f70);
            return 1;
        }
        if (Pressed2_43F200(e, 0x2000)) {
            Set43F200(w, w->v + w->f70);
            return 1;
        }
    }
    return 0;
}
#undef GuiWidget_BroadcastEvent /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0043F200 */
