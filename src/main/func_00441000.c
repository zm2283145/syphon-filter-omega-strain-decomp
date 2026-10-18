#include "types.h"
typedef struct { char p[0x48]; int id; int val; char p50[0x50]; void* label; } W441000;
extern void GuiTextWidget_SetText(void* label, const char* text, int f);
extern char D_004C03B8[];
void GuiWeaponDisplay_SetItem(W441000* w, int id, int val, const char* text)
{
    if (w->id != id) {
        w->id = id;
        w->val = val;
        if (w->label) {
            GuiTextWidget_SetText(w->label, text ? text : D_004C03B8, 0);
        }
    }
}
