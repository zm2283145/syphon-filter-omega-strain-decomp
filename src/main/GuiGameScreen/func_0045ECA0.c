#include "types.h"
typedef struct { char pad[0x6A4]; void* hud; } Game0045ECA0;
extern Game0045ECA0* D_004FFC2C;
extern int Loc_LookupText(int id);
extern void func_0045D070(void* hud, int text, int b, int c);
/* Show a localized message on the HUD if one exists. */
void func_0045ECA0(int id, int b)
{
    void* hud;
    if (D_004FFC2C && (hud = D_004FFC2C->hud) != 0) {
        func_0045D070(hud, Loc_LookupText(id), b, 1);
    }
}
