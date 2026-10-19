/*
 * main/GuiSaveAgentWidget: 3 files, 00295090-00295430
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00295090 */
#pragma push /* merge_units */
typedef struct { char pad[0x14]; unsigned short flags; } E295090;
typedef struct { char pad[0x30]; unsigned char b30; } Ui295090;
typedef struct S295090 {
    char pad0[0xF8];
    unsigned char bF8[0x11];
    unsigned char b109;
    char pad10A[0x118 - 0x10A];
    E295090* items[0x18];
    unsigned char b178[0x54];
    int cur;
    E295090* focus;
} S295090;
extern Ui295090* D_004FFC04;
extern int D_005063D0[];
extern void GuiCommandCenter_OpenPanel(S295090* s, int a);
extern void GuiCommandCenter_SetTexts(S295090* s);
extern void GuiCommandCenter_ShowBonus(S295090* s, int a);
extern void GuiWidget_SendEvent(void* a, void* b, int c, int d, int e);

void GuiCommandCenter_Select(S295090* s, int i, int f)
{
    if (s->focus) {
        if (s->b178[s->cur]) {
            if ((s->cur <= 0x10 && s->bF8[s->cur]) || (s->cur == 0x14 && s->b109))
                GuiWidget_SendEvent(s, s->focus, 6, (int)"onStateOn", 0);
            else
                GuiWidget_SendEvent(s, s->focus, 6, (int)"onLoseFocus", 0);
        } else {
            GuiWidget_SendEvent(s, s->focus, 6, (int)"onStateOff", 0);
        }
        s->cur = -1;
        s->focus = 0;
    }
    if (i < 0 || i >= 0x18)
        return;
    {
        E295090* e = s->items[i];
        if (!e || !(e->flags & 4) || !(e->flags & 2))
            return;
    }
    if (f)
        GuiCommandCenter_OpenPanel(s, 0);
    s->focus = s->items[i];
    s->cur = i;
    if (s->b178[s->cur])
        GuiWidget_SendEvent(s, s->focus, 6, (int)"onGainFocus", 0);
    else
        GuiWidget_SendEvent(s, s->focus, 6, (int)"onDeactivate", 0);
    GuiCommandCenter_SetTexts(s);
    if (i > 0x10 || s->b178[s->cur] || D_004FFC04->b30)
        GuiCommandCenter_ShowBonus(s, -1);
    else
        GuiCommandCenter_ShowBonus(s, D_005063D0[i]);
}
#pragma pop /* merge_units */
/* merge_units: end func_00295090 */

/* merge_units: begin func_002952C0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad[0x14]; unsigned short flags; } Obj_52C0;
typedef struct {
    char pad0[0x118];
    Obj_52C0* objs[24];
    unsigned char avail[24];
    char pad190[0x1CC - 0x190];
    int f1CC;
} Self_52C0;
extern char g_Game;
extern char* D_0048C160[];
int Agent_GetSelected(void*, int);
int AgentData_IsLevelDone(int, __int128);
__int128 StringPool_MakeKey(char*);

int GuiCommandCenter_GetDefaultSlot(Self_52C0* self) {
    int idx;
    int k;
    int i;
    idx = -1;
    for (k = 0; k < 0x11; k++) {
        if (AgentData_IsLevelDone(Agent_GetSelected(&g_Game, -1), StringPool_MakeKey(D_0048C160[k]))) idx = k;
    }
    if (idx == 0 || self->f1CC == -1) return 0x16;
    if (idx != -1) return idx;
    if (((unsigned char*)self)[0x18F]) return 0x17;
    for (i = 0; i < 24; i++) {
        if (self->avail[i]) break;
    }
    if (i == 24) {
        for (i = 0; i < 24; i++) {
            Obj_52C0* o = self->objs[i];
            if (o && (o->flags & 4) && (o->flags & 2)) break;
        }
    }
    if (i == 24) return -1;
    return i;
}
#pragma pop /* merge_units */
/* merge_units: end func_002952C0 */

/* merge_units: begin func_00295430 */
#pragma push /* merge_units */
typedef struct { char pad[0x2E]; unsigned char b2e; char p2f; unsigned char b30; char p31; unsigned char b32; } G295;
typedef struct { char pad[0x2F4]; unsigned char b2f4; } O295;
#if 0 /* merge_units */
extern G295* D_004FFC04;
#endif /* merge_units */
#define D_004FFC04 (*(G295 **)&D_004FFC04) /* merge_units */

extern char D_004AA288[];
extern int Gui_GetScreenList(void);
extern void* GuiManager_FindOrLoad(int, char*, char*);
extern char* GuiScreen_GetLobbyString(O295*, int, int, int, int, int);
extern int FrontEnd_OpenPopup(G295*, int, char*, char*, int, int);
extern void FrontEnd_LeaveOnline(G295*, int);
extern void FrontEnd_ClosePopup(G295*, int);
extern int Gui_GetScreenStack(void);
extern void GuiStack_SwapScreens(int, O295*, void*);
extern void GuiCommandCenter_ClearState(O295*);
void GuiCommandCenter_Leave(O295* o) {
    void* w;
    G295* g;
    if (!o->b2f4) return;
    g = D_004FFC04;
    if (g->b30 && !g->b32) {
        int h;
        w = GuiManager_FindOrLoad(Gui_GetScreenList(), "GuiOnlineOfflineSelect", "ONOFFSEL");
        {
            G295* m = D_004FFC04;
            h = FrontEnd_OpenPopup(m, 0, D_004AA288, GuiScreen_GetLobbyString(o, 0x77, 0, 0, 0, 0), 0, 0);
        }
        FrontEnd_LeaveOnline(D_004FFC04, 1);
        FrontEnd_ClosePopup(D_004FFC04, h);
    } else if (g->b2e) {
        w = GuiManager_FindOrLoad(Gui_GetScreenList(), "GuiTitleScreen", "TITLESCR");
    } else {
        w = GuiManager_FindOrLoad(Gui_GetScreenList(), "GuiOnlineOfflineSelect", "ONOFFSEL");
    }
    if (w) {
        GuiStack_SwapScreens(Gui_GetScreenStack(), o, w);
        GuiCommandCenter_ClearState(o);
    }
    o->b2f4 = 0;
}
#undef D_004FFC04 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00295430 */
