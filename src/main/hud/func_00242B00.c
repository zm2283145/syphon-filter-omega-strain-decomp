#include "types.h"
typedef struct { char p0[0x100]; char list[0x6E4 - 0x100]; int owner; } C1Hud_242B;
extern void Notify_Insert(void* list, void* item, int owner, int a, int b);
void Hud_PostNotification(C1Hud_242B* h, void* item)
{
    if (item)
        Notify_Insert(h->list, item, h->owner, 1, 0);
}