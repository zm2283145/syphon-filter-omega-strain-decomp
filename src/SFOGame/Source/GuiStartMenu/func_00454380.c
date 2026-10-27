#include "types.h"
typedef struct { char p[0x14]; unsigned short flags; } C454380;
typedef struct { char p[0x88]; C454380* c; char p8C[8]; int f94; } S454380;
typedef struct { char p[0x14]; unsigned short flags; char p16[0x32]; S454380* s; } W454380;
typedef struct { int p0; int f4; } G454380;
extern G454380* g_Hud;
extern void GuiWidget_onAdvanceTime(W454380* w);
extern void GuiRadioLog_UpdateRadioLogList(W454380* w);
void GuiRadioLog_onAdvanceTime(W454380* w)
{
    C454380* c;
    GuiWidget_onAdvanceTime(w);
    {
        G454380* g;
S454380* s;
        if ((g = g_Hud) && (s = w->s) && g->f4 != s->f94) GuiRadioLog_UpdateRadioLogList(w);
    }
    if (w->s && (c = w->s->c)) {
        int on = w->s->f94 != 0 && (w->flags & 4) != 0; if (on) c->flags |= 2; else c->flags &= ~2;
    }
}
