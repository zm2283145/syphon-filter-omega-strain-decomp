#include "types.h"

typedef struct { char pad[0x160]; void* target; } Obj2AF230;
extern char D_004ABCD0[];
extern void* DME_GetLobby(void);
extern char* SFOLobby_CellGetMessage(void* p);
extern void GuiTextWidget_SetText(void* target, const char* text, int zero);

/* Forwards the current text (or a default) to the object's target. */
void GuiNetAgencyCell_UpdateCellMessage(Obj2AF230* o)
{
    void* p;
    p = DME_GetLobby();
    if (p) {
        char* text = SFOLobby_CellGetMessage(p);
        if (o->target)
            GuiTextWidget_SetText(o->target, text ? text : D_004ABCD0, 0);
    }
}
