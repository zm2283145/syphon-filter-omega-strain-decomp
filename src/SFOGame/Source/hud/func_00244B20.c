#include "types.h"
typedef struct { char pad[0x74]; void* widget; } Hud;
extern void viBufGetTs(void* w, float v);
extern void cAnimator_AnimateTo(void* w, float v);
/* Positions the widget based on the row index. */
void cHud_ChangeGadget(Hud* h, unsigned char row)
{
    if (h->widget) {
        int y = row * 30 + 200;
        viBufGetTs(h->widget, y);
        cAnimator_AnimateTo(h->widget, y + 10);
    }
}
