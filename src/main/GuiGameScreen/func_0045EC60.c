#include "GuiGameScreen_types.h"

extern GameHudOwner* D_004FFC2C;
extern void func_0045CFB0(void* hud, int enable);

/* Enable the interaction prompt when both the owner and its HUD are present. */
void func_0045EC60(void)
{
    if (D_004FFC2C && D_004FFC2C->hud)
        func_0045CFB0(D_004FFC2C->hud, 1);
}
