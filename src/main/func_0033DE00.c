typedef struct { char pad[0x28]; char key[4]; char p2c[0x68 - 0x2C]; unsigned int flags; } G3DE00;
typedef struct { int id; char a[0x20]; char b[0x40]; unsigned char c; } E3DE00;
typedef struct { char d[0x4]; int count; } L3DE00;
typedef struct {
    char p0[0x8C]; void* p8C; char p90[0xAC - 0x90];
    char lAC[4]; int count;
} T3DE00;
extern void GuiLobbyScreen_onAdvanceTime(T3DE00* self);
extern G3DE00* Gui_Canvas(void);
extern T3DE00** func_0033DEF0(void* key);
extern int cDME_GetLobby(void);
extern E3DE00* SFOLobbyList_GetSlot(void* list, int i);
extern void GuiChatWindow_AddChatLine(void* p, char* a, char* b, unsigned char c);
extern void SFOLobbyList_ClearList(void* list);
void GuiMissionLobbyScreen_onAdvanceTime(T3DE00* self)
{
    G3DE00* g;
    int on;
    int i;
    GuiLobbyScreen_onAdvanceTime(self);
    on = *func_0033DEF0(Gui_Canvas()->key) == self;
    g = Gui_Canvas();
    if (on)
        g->flags |= 3;
    else
        g->flags &= ~3;
    if (cDME_GetLobby() && self->count) {
        for (i = 0; i < self->count; i++) {
            E3DE00* e = SFOLobbyList_GetSlot(self->lAC, i);
            if (e)
                GuiChatWindow_AddChatLine(self->p8C, e->a, e->b, e->c);
        }
        SFOLobbyList_ClearList(self->lAC);
    }
}