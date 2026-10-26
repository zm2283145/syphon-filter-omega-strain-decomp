#include "types.h"
typedef struct { unsigned char flag; char p1[3]; int vals[4]; } Row2B1970;
typedef struct { char p0[0x48]; int sel; void* labels[4]; } S2B1970;
extern Row2B1970 D_0048BD10[];
extern char D_004ABEE8[];
extern char D_004ABEF8[];
extern int sprintf(char* buf, const char* fmt, ...);
extern char* Loc_LookupText(char* key);
extern void GuiTextWidget_SetText(void* w, char* text, int flags);
/* Resets the selection and relabels the four value buttons from the table row. */
void GuiQuickChat_Reset(S2B1970* s)
{
    int i;
    s->sel = 0;
    for (i = 0; i < 4; i++) {
        if (s->labels[i]) {
            char buf[0x20];
            Row2B1970* r = &D_0048BD10[s->sel];
            if (r->flag) sprintf(buf, D_004ABEE8, r->vals[i]);
            else sprintf(buf, D_004ABEF8, r->vals[i]);
            GuiTextWidget_SetText(s->labels[i], Loc_LookupText(buf), 0);
        }
    }
}
