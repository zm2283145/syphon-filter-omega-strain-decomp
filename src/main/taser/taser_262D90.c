#include "types.h"
typedef struct { char pad[8]; unsigned char state; } Obj262D;
extern void HeldItem_UpdateFlight(Obj262D* s);
extern void HeldItem_UpdateShocking(Obj262D* s);
extern void HeldItem_UpdateReelIn(Obj262D* s);
void HeldItem_Dispatch(Obj262D* s) {
    switch (s->state) {
    case 1: HeldItem_UpdateFlight(s); break;
    case 2: HeldItem_UpdateShocking(s); break;
    case 3: HeldItem_UpdateReelIn(s); break;
    }
}