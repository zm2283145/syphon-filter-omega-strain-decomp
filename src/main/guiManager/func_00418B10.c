#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
#include "alloc_guard.h"

struct PStr_418B10 {
    signed char len;
    char text[0x80];
};
static inline void Set_418B10(PStr_418B10* p, const char* s)
{
    char* d = (char*)p + 1;
    int n = 0;
    while ((*d++ = *s++) != 0) {
        if (++n < 0x7E) continue;
        n++;
        d[0] = '\n';
        d[1] = 0;
        break;
    }
    p->len = n;
}
static inline const char* ReadStr_418B10(char** cur)
{
    const char* s = *cur;
    while (*(*cur)++) {
    }
    return s;
}
struct W_418B10 {
    VPAD8(p) VPAD4(q) VPAD2(r)
    virtual void Load(char** cur);
    char pad4[0x20];
    W_418B10* f24;
};
extern "C" {
void* cMemMan_Allocate(int pool, unsigned int size, char* file, int line);
int strcmp(const char* a, const char* b);
W_418B10* AbstractWidgetClassRep_Create(char* name);
W_418B10* GuiInterfaceDecorator_ctor(void* p);
void GuiDecorator_Decorate(W_418B10* x, W_418B10* w);
void GuiWidget_AddChild(W_418B10* w, W_418B10* c);
extern char D_004BF110[];
extern char D_004BF120[];
extern char D_004BF138[];
}

extern "C" W_418B10* GuiManager_LoadWidget(void* ctx, char** cur, W_418B10* parent)
{
    PStr_418B10 type;
    PStr_418B10 extra;
    W_418B10* w;
    W_418B10* x;
    int i;
    int n;
    Set_418B10(&type, ReadStr_418B10(cur));
    Set_418B10(&extra, ReadStr_418B10(cur));
    w = 0;
    if (parent) {
        if (strcmp(type.text, D_004BF110) == 0) w = parent;
    } else {
        w = AbstractWidgetClassRep_Create(type.text);
    }
    if (!w) return 0;
    w->f24 = w;
    w->Load(cur);
    if (strcmp(extra.text, D_004BF120) == 0) {
        void* p;
        {
            AllocGuard g;
            p = cMemMan_Allocate(0, 0x90, D_004BF138, 0x100);
        }
        if (p) p = GuiInterfaceDecorator_ctor(p);
        x = (W_418B10*)p;
    } else {
        x = 0;
    }
    if (x) {
        GuiDecorator_Decorate(x, w);
        x->Load(cur);
    }
    n = *(unsigned short*)*cur;
    *cur += 2;
    for (i = 0; i < n; i++) {
        W_418B10* c = GuiManager_LoadWidget(ctx, cur, 0);
        if (c) {
            c->f24 = w;
            GuiWidget_AddChild(w, c);
        }
    }
    return w;
}





