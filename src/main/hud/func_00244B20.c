#include "types.h"
typedef struct { char pad[0x74]; void* widget; } Hud;
extern void IeElement_EvaluateAt(void* w, float v);
extern void IeElement_Fade(void* w, float v);
/* Positions the widget based on the row index. */
void Hud_SetGoggles(Hud* h, unsigned char row)
{
    if (h->widget) {
        int y = row * 30 + 200;
        IeElement_EvaluateAt(h->widget, y);
        IeElement_Fade(h->widget, y + 10);
    }
}
