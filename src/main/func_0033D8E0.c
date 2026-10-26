typedef struct {
    char pad0[0x88];
    void *ui;
    char pad8C[0xA8 - 0x8C];
    void *cur;
    char padAC[0xC8 - 0xAC];
    char a[0xE4 - 0xC8];
    char b[4];
} Obj;
extern void *DME_GetLobby(void);
extern void SFOLobby_LobbySetDisplay(void *p, int v);
extern void GuiArrayWidget_Select(void *p, int a, int b);
extern void GuiMissionList_SetDisplayMode(void *p, unsigned char mode);
extern void func_002ACC80(void *p, void *cur);

void GuiMissionLobbyScreen_SetDisplayMode(Obj *o, unsigned char mode)
{
    if (mode == 1 || mode == 3 || mode == 2) {
        if (o->cur != o->a) {
            if (DME_GetLobby()) {
                SFOLobby_LobbySetDisplay(DME_GetLobby(), 0);
            }
            o->cur = o->a;
        }
        o->cur = o->a;
    } else if (mode == 0) {
        if (o->cur != o->b) {
            if (DME_GetLobby()) {
                SFOLobby_LobbySetDisplay(DME_GetLobby(), 1);
            }
            o->cur = o->b;
        }
    }
    if (o->ui) {
        GuiArrayWidget_Select(o->ui, 0, 0);
        GuiMissionList_SetDisplayMode(o->ui, mode);
        func_002ACC80(o->ui, o->cur);
    }
}


