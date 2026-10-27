#include "types.h"
typedef struct { char pad[0x14]; unsigned short flags; } W45C;
typedef struct { char pad[0x94]; int f94; } M45C;
typedef struct { char pad[0xE0]; W45C* fe0; int fe4; M45C* fe8; int fec; int ff0; char pad2[0x1C]; unsigned char b110; } P45C;
extern void* Gui_Canvas(void);
extern void GuiCanvas_SetFocus(void*, M45C*);
extern char* nGlobalization_GetString_charP(char*);
extern void GuiTextListWidget_AddItem(M45C*, char*, int, int);
extern void GuiWidget_SendMessage(W45C*, void*, int, int, int);
extern void GuiGameScreen_CloseChooseMenu(P45C*);
void GuiGameScreen_BeginChooseMenu(P45C* p, int arg) {
    if (p->fe0) {
        if (p->fe8->f94) {
            p->fe0->flags |= 2;
            GuiCanvas_SetFocus(Gui_Canvas(), p->fe8);
            GuiTextListWidget_AddItem(p->fe8, nGlobalization_GetString_charP("Cancel"), -1, 0);
            p->ff0 = arg;
            p->b110 = 0;
            GuiWidget_SendMessage(p->fe0, Gui_Canvas(), 0x10, 2, 0);
        } else {
            GuiGameScreen_CloseChooseMenu(p);
        }
    }
}
