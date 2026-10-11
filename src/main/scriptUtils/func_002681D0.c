#include "types.h"

typedef struct CalloutOwner {
    char pad[0x30];
    char* label;
} CalloutOwner;

extern void* D_004FFC2C;
extern void func_00242FA0(void*, char*, int, int, int, int, float, float);

/* Sets a callout label on the global HUD object. */
void Global_SetCallout_2(CalloutOwner* owner, int a1, int value, int a3) {
    func_00242FA0(D_004FFC2C, owner->label + 0xC, a1, 0, 0, a3, (float)value, 0.0f);
}
