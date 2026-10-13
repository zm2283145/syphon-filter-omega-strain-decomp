/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#include "types.h"

struct Manager {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void Method68(void* obj); /* +0x68 */
};

extern void* D_004FFC2C;
extern char D_004FFB50[];
extern "C" Manager* Gui_GetScreenStack(void);
extern "C" void Hud_ClosePauseMenu(void* p);
extern "C" void Game_SetPaused(void* p, int n);

/* Hands self to the manager (virtual +0x68), then Hud_ClosePauseMenu(D_004FFC2C) and Game_SetPaused(D_004FFB50, 0). */
extern "C" void func_00456100(void* self)
{
    Gui_GetScreenStack()->Method68(self);
    Hud_ClosePauseMenu(D_004FFC2C);
    Game_SetPaused(D_004FFB50, 0);
}
