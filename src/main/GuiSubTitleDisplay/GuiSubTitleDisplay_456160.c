/*
 * main/GuiSubTitleDisplay: 2 files, 00456160-004562E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00456160 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
struct V4561 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual int v21(); virtual int v22(); virtual void v23(void*, int); virtual void v24(void*); };
typedef struct { char pad[0x10]; int f10; unsigned short flags; short h16; } W4561;
extern "C" {
extern int Gui_Manager(void);
extern W4561* GuiManager_OpenGui(int, char*, char*);
extern void* GuiManager_FindOpenGui(int, char*);
extern W4561* GuiWidget_FindChild_charP(void*, char*);
extern V4561* Gui_Canvas(void);
extern char D_004C1AD8[];
extern char D_004C1B00[];
extern char D_004C1B18[];
extern char D_004C1B20[];
extern char D_004C1B28[];
extern char D_004C1B38[];
}
extern "C" void GuiStartMenu_ReturnToMenu(W4561* g) {
    W4561* w = GuiManager_OpenGui(Gui_Manager(), D_004C1AD8, "INGAMENU");
    void* p;
    if (!w) return;
    w->f10 = g->f10;
    {
        int z = g->h16;
        Gui_Canvas()->v24(g);
        Gui_Canvas()->v23(w, z);
    }
    p = GuiManager_FindOpenGui(Gui_Manager(), D_004C1B00);
    if (p) {
        W4561* a = GuiWidget_FindChild_charP(p, D_004C1B18);
        W4561* b = GuiWidget_FindChild_charP(p, D_004C1B20);
        if (a) a->flags |= 2;
        if (b) b->flags |= 2;
    }
    p = GuiManager_FindOpenGui(Gui_Manager(), D_004C1B00);
    if (p) {
        W4561* a = GuiWidget_FindChild_charP(p, D_004C1B28);
        W4561* b = GuiWidget_FindChild_charP(p, D_004C1B38);
        if (a) a->flags |= 2;
        if (b) b->flags |= 2;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00456160 */

/* merge_units: begin func_004562E0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Pg_4562E0 { char pad[0x10]; int f10; unsigned short flags; };
struct Self_4562E0 { char pad[0x16]; short f16; };
struct Ui_4562E0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22();
    virtual void Show(Pg_4562E0* p, int a); virtual void Hide(Self_4562E0* p);
};
extern "C" {
extern void* D_004FFC04;
extern unsigned char g_GameState;
extern unsigned char g_IsMultiplayer;
char* nGlobalization_GetString_charP(char* key);
int cGameFrontEnd_PushMessageBox(void* ui, int a, char* b, char* c, Self_4562E0* d, int e);
#if 0 /* merge_units */
void* Gui_Manager(void);
#endif /* merge_units */
#define Gui_Manager() ((void *)Gui_Manager()) /* merge_units */

#if 0 /* merge_units */
Pg_4562E0* GuiManager_OpenGui(void* a, char* b, char* c);
#endif /* merge_units */
#define GuiManager_OpenGui(a0, a1, a2) ((Pg_4562E0 *)GuiManager_OpenGui((int)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
Pg_4562E0* GuiManager_FindOpenGui(void* a, char* b);
#endif /* merge_units */
#define GuiManager_FindOpenGui(a0, a1) ((Pg_4562E0 *)GuiManager_FindOpenGui((int)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
Pg_4562E0* GuiWidget_FindChild_charP(Pg_4562E0* a, char* b);
#endif /* merge_units */
#define GuiWidget_FindChild_charP(a0, a1) ((Pg_4562E0 *)GuiWidget_FindChild_charP((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
Ui_4562E0* Gui_Canvas(void);
#endif /* merge_units */
#define Gui_Canvas() ((Ui_4562E0 *)Gui_Canvas()) /* merge_units */

}

extern "C" {
char D_004C1B00[] = "GuiStartMenuBackdrop";
char D_004C1B18[] = "buttonx";
char D_004C1B20[] = "select";
char D_004C1B28[] = "buttondpad";
char D_004C1B38[] = "navigate";
char D_004C1B48[] = "GuiObjectives";
char D_004C1B58[] = "OBJECTIV";
char D_004C1B68[] = "GuiRadioLog";
char D_004C1B78[] = "RADIOLOG";
char D_004C1B90[] = "GuiBriefingPane";
char D_004C1BA0[] = "BRIEFING";
char D_004C1BB0[] = "GuiEquipmentPane";
char D_004C1BC8[] = "EQUIPNT";
char D_004C1BD0[] = "GuiScoresEquip";
char D_004C1BE0[] = "SCORES";
char D_004C1BE8[] = "SCOREONE";
char D_004C1BF8[] = "GuiGameOptions";
char D_004C1C08[] = "GAMEOPT2";
char D_004C1C18[] = "QuitTitle";
char D_004C1C28[] = "QuitMessage";
}
static inline void ShowButtons(char* a, char* b)
{
    Pg_4562E0* bd = GuiManager_FindOpenGui(Gui_Manager(), D_004C1B00);
    if (bd) {
        Pg_4562E0* x = GuiWidget_FindChild_charP(bd, a);
        Pg_4562E0* y = GuiWidget_FindChild_charP(bd, b);
        if (x) {
            x->flags &= ~2;
        }
        if (y) {
            y->flags &= ~2;
        }
    }
}

extern "C" void GuiStartMenu_ActivateOption(Self_4562E0* self, int which)
{
    Pg_4562E0* pg = 0;
    switch (which) {
    case 0:
        pg = GuiManager_OpenGui(Gui_Manager(), D_004C1B48, D_004C1B58);
        break;
    case 1:
        pg = GuiManager_OpenGui(Gui_Manager(), D_004C1B68, D_004C1B78);
        break;
    case 2:
        pg = GuiManager_OpenGui(Gui_Manager(), D_004C1B90, D_004C1BA0);
        ShowButtons(D_004C1B18, D_004C1B20);
        break;
    case 3:
        pg = GuiManager_OpenGui(Gui_Manager(), D_004C1BB0, D_004C1BC8);
        break;
    case 4:
        if (g_IsMultiplayer) {
            pg = GuiManager_OpenGui(Gui_Manager(), D_004C1BD0, D_004C1BE0);
        } else {
            pg = GuiManager_OpenGui(Gui_Manager(), D_004C1BD0, D_004C1BE8);
        }
        ShowButtons(D_004C1B28, D_004C1B38);
        break;
    case 5:
        pg = GuiManager_OpenGui(Gui_Manager(), D_004C1BF8, D_004C1C08);
        break;
    case 6:
        if (g_GameState != 0x13 && g_GameState != 0x14) {
            char* t = nGlobalization_GetString_charP(D_004C1C18);
            char* m = nGlobalization_GetString_charP(D_004C1C28);
            if (t && m) {
                cGameFrontEnd_PushMessageBox(D_004FFC04, 5, t, m, self, 0);
            }
        }
        break;
    }
    if (pg) {
        int prev;
        pg->f10 = which;
        pg->flags |= 0x80;
        prev = self->f16;
        Gui_Canvas()->Hide(self);
        Gui_Canvas()->Show(pg, prev);
    }
}
#undef Gui_Manager /* merge_units */
#undef GuiManager_OpenGui /* merge_units */
#undef GuiManager_FindOpenGui /* merge_units */
#undef GuiWidget_FindChild_charP /* merge_units */
#undef Gui_Canvas /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004562E0 */
