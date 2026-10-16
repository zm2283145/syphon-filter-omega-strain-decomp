#include "types.h"
typedef struct { char pad[0x14]; unsigned short flags; } W45C;
typedef struct { char pad[0x94]; int f94; } M45C;
typedef struct { char pad[0xE0]; W45C* fe0; int fe4; M45C* fe8; int fec; int ff0; char pad2[0x1C]; unsigned char b110; } P45C;
extern void* Gui_GetScreenStack(void);
extern void GuiScreen_SetFocus(void*, M45C*);
extern char* Loc_LookupText(char*);
extern void GuiTextListWidget_AddItem(M45C*, char*, int, int);
extern void GuiWidget_SendEvent(W45C*, void*, int, int, int);
extern void GuiGameScreen_CloseChooseMenu(P45C*);
void cPlayer_LaunchChooseMenu(P45C* p, int arg) {
    if (p->fe0) {
        if (p->fe8->f94) {
            p->fe0->flags |= 2;
            GuiScreen_SetFocus(Gui_GetScreenStack(), p->fe8);
            GuiTextListWidget_AddItem(p->fe8, Loc_LookupText("Cancel"), -1, 0);
            p->ff0 = arg;
            p->b110 = 0;
            GuiWidget_SendEvent(p->fe0, Gui_GetScreenStack(), 0x10, 2, 0);
        } else {
            GuiGameScreen_CloseChooseMenu(p);
        }
    }
}
