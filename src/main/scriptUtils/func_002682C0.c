#include "types.h"
typedef struct { char pad[0xC]; char label[1]; } Callout002682C0;
extern void* D_004FFC2C;
extern void func_00242E40(void* hud, char* label, int a, int b, int c, int d, int e, float x, float y);
/* Set a callout label on the HUD. */
void Global_SetCalloutLabel(Callout002682C0* callout, int a, int x, int d)
{
    func_00242E40(D_004FFC2C, callout->label, a, 0, 0, d, 1, (float)x, 0.0f);
}
