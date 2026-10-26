#include "types.h"

typedef struct { char pad[0x160]; void* target; } Obj2AF;
extern char D_004ABCD0[];
extern void GuiMenuScreen_Update(Obj2AF* o);
extern void* DME_GetLobby(void);
extern char* SFOLobby_CellGetMessage(void* p);
extern void GuiTextWidget_SetText(void* target, const char* text, int zero);

/* Refreshes the object and forwards the current text (or a default) to its target. */
void GuiNetAgencyCell_Update(Obj2AF* o)
{
    void* p;
    GuiMenuScreen_Update(o);
    p = DME_GetLobby();
    if (p) {
        char* text = SFOLobby_CellGetMessage(p);
        if (o->target)
            GuiTextWidget_SetText(o->target, text ? text : D_004ABCD0, 0);
    }
}
