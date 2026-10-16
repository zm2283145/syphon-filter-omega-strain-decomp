#include "types.h"
typedef struct { unsigned char flag; char p1[3]; int vals[4]; } Row2B1A50;
typedef struct { char p0[0x48]; int sel; void* labels[4]; } S2B1A50;
extern Row2B1A50 D_0048BD10[];
extern char D_004ABEE8[];
extern char D_004ABEF8[];
extern int sprintf(char* buf, const char* fmt, ...);
extern char* Loc_LookupText(char* key);
extern void GuiTextWidget_SetText(void* w, char* text, int flags);
/* Relabels the four value buttons from the table row. */
void func_002B1A50(S2B1A50* s)
{
    int i;
    for (i = 0; i < 4; i++) {
        if (s->labels[i]) {
            char buf[0x20];
            Row2B1A50* r = &D_0048BD10[s->sel];
            if (r->flag) sprintf(buf, D_004ABEE8, r->vals[i]);
            else sprintf(buf, D_004ABEF8, r->vals[i]);
            GuiTextWidget_SetText(s->labels[i], Loc_LookupText(buf), 0);
        }
    }
}
