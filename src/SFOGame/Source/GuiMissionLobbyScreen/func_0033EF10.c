typedef struct { char pad[0x110]; int busy; } UI;
typedef struct O { char pad[0x88]; UI *ui; int pad8C; int mode; } O;
extern void *D_004FFC04;
extern char D_004B9C60[];
extern void GuiMissionList_SetSelectMode(UI *ui);
extern void *Gui_Canvas(void);
extern void GuiCanvas_SetFocus(void *mgr, UI *ui);
extern char *GuiLobbyScreen_GetLobbyString(O *o, int a, char *b, char *c, int d, int e);
extern int cGameFrontEnd_PushMessageBox(void *ui, int a, char *b, char *c, void *d, int e);

int GuiMissionLobbyScreen_SelectAgent(O *o, unsigned char mode, int flag)
{
    o->mode = mode;
    if (o->ui) {
        int id;
        void *dlg;
        GuiMissionList_SetSelectMode(o->ui);
        if (o->ui->busy) {
            if (flag)
                GuiCanvas_SetFocus(Gui_Canvas(), o->ui);
            return 1;
        }
        switch (mode) {
        case 0: id = 0x11; break;
        case 1: id = 0x12; break;
        case 2: id = 0x10; break;
        case 3: id = 0x13; break;
        default: return 1;
        }        dlg = D_004FFC04;
        cGameFrontEnd_PushMessageBox(dlg, 2, D_004B9C60, GuiLobbyScreen_GetLobbyString(o, id, 0, 0, 0, 0), 0, 0);
    }
    return 0;
}


