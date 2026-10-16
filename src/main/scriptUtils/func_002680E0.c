#include "types.h"

typedef struct CalloutOwner {
    char pad[0x30];
    char* label;
} CalloutOwner;

extern void* D_004FFC2C;
extern void Hud_SetCalloutLabel(void*, char*, int, int, int, int, int, float, float);

/* Sets a callout label on the global HUD object. */
void Global_SetCalloutLabel_2(CalloutOwner* owner, int a1, int value, int a3) {
    Hud_SetCalloutLabel(D_004FFC2C, owner->label + 0xC, a1, 0, 0, a3, 1, (float)value, 0.0f);
}
