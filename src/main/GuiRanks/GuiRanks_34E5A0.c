#pragma cplusplus on
#include "types.h"
struct V34E5 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); };
typedef struct { char pad[0x10]; char f10[0x14]; } E34E5;
typedef struct { char pad[8]; E34E5* f8; } T34E5;
typedef struct { char pad[4]; int f4; } B34E5;
typedef struct { char pad[0xB50]; B34E5* fb50; } A34E5;
typedef struct { void* vt; char f4[0x44]; void* f48; char pad[0x18]; int f64; } O34E5;
typedef struct { char pad[0x25C]; int f25c; } G34E5;
extern "C" {
extern int GuiTextListWidget_GetItemId(void*);
extern char D_004FFB50[];
extern A34E5* Agent_GetSelected(char*, int);
extern int Gui_GetScreenStack(void);
extern void GuiWidget_SendEvent(O34E5*, int, int, int, int);
extern int Gui_GetScreenList(void);
extern void* GuiManager_FindOrLoad(int, char*, char*);
extern char* String_CStr(void*);
extern void GuiSlideShow_SetReturn(void*, int, char*, int);
extern void GuiSlideShow_Clear(void*);
extern int GuiTextListWidget_GetItemText(void*, int);
extern int GuiSlideShow_AddCategory(void*, int);
extern int sprintf(char*, const char*, ...);
extern T34E5* func_0034E760(void);
extern G34E5* D_004FFC04;
extern void GuiSlideShow_AddSlide(void*, int, char*, int, char*);
extern void GuiStack_SwapScreens(int, O34E5*, void*);
}
extern "C" void GuiRanks_Select(O34E5* o, int idx) {
    char buf[0x20];
    int sel = GuiTextListWidget_GetItemId(o->f48);
    void* w;
    int x;
    if (sel == -1) return;
    if (!(Agent_GetSelected(D_004FFB50, -1)->fb50->f4 < sel)) {
    GuiWidget_SendEvent(o, Gui_GetScreenStack(), 0x10, 1, 0);
    w = GuiManager_FindOrLoad(Gui_GetScreenList(), "GuiSlideShow", "ZEUSHELL");
    if (!w) return;
    {
        char* t = String_CStr(o->f4);
        GuiSlideShow_SetReturn(w, ((V34E5*)o)->v19(), t, idx);
    }
    GuiSlideShow_Clear(w);
    x = GuiSlideShow_AddCategory(w, GuiTextListWidget_GetItemText(o->f48, idx));
    sprintf(buf, "0_%d_%d.tdx", o->f64, sel + 1);
    {
        T34E5* tab;
        Agent_GetSelected(D_004FFB50, -1);
        tab = func_0034E760();
        GuiSlideShow_AddSlide(w, x, buf, D_004FFC04->f25c, tab->f8[sel].f10);
    }
    GuiStack_SwapScreens(Gui_GetScreenStack(), o, w);
    } else {
        GuiWidget_SendEvent(o, Gui_GetScreenStack(), 0x10, 4, 0);
    }
}
