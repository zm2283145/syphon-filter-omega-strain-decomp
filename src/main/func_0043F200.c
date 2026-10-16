#pragma cplusplus on
#include "types.h"
typedef struct { char p[0x48]; int sel; unsigned char vis[4]; int x0[2]; int x1[2]; unsigned char b60; char p61[3]; int v; int lo; int hi; int f70; } W43F200;
typedef struct { unsigned short type; unsigned short dev; unsigned short b4; unsigned short action; unsigned short key; } Ev43F200;
extern "C" {
void GuiWidget_SendEventUp(void* w, int kind, int v, int z);
void GuiWidget_BroadcastEvent(W43F200* w, int kind, int pos, int z);
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
