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
extern int Gui_GetScreenList(void);
extern W4561* GuiManager_FindOrLoad(int, char*, char*);
extern void* GuiManager_FindByName(int, char*);
extern W4561* GuiWidget_FindChildByName(void*, char*);
extern V4561* Gui_GetScreenStack(void);
extern char D_004C1AD8[];
extern char D_004C1B00[];
extern char D_004C1B18[];
extern char D_004C1B20[];
extern char D_004C1B28[];
extern char D_004C1B38[];
}
extern "C" void GuiStartMenu_ReturnToMenu(W4561* g) {
    W4561* w = GuiManager_FindOrLoad(Gui_GetScreenList(), D_004C1AD8, "INGAMENU");
    void* p;
    if (!w) return;
    w->f10 = g->f10;
    {
        int z = g->h16;
        Gui_GetScreenStack()->v24(g);
        Gui_GetScreenStack()->v23(w, z);
    }
    p = GuiManager_FindByName(Gui_GetScreenList(), D_004C1B00);
    if (p) {
        W4561* a = GuiWidget_FindChildByName(p, D_004C1B18);
        W4561* b = GuiWidget_FindChildByName(p, D_004C1B20);
        if (a) a->flags |= 2;
        if (b) b->flags |= 2;
    }
    p = GuiManager_FindByName(Gui_GetScreenList(), D_004C1B00);
    if (p) {
        W4561* a = GuiWidget_FindChildByName(p, D_004C1B28);
        W4561* b = GuiWidget_FindChildByName(p, D_004C1B38);
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
extern unsigned char D_004FFBA0;
extern unsigned char D_005721C8;
char* Loc_LookupText(char* key);
int FrontEnd_OpenPopup(void* ui, int a, char* b, char* c, Self_4562E0* d, int e);
#if 0 /* merge_units */
void* Gui_GetScreenList(void);
#endif /* merge_units */
#define Gui_GetScreenList() ((void *)Gui_GetScreenList()) /* merge_units */

#if 0 /* merge_units */
Pg_4562E0* GuiManager_FindOrLoad(void* a, char* b, char* c);
#endif /* merge_units */
#define GuiManager_FindOrLoad(a0, a1, a2) ((Pg_4562E0 *)GuiManager_FindOrLoad((int)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
Pg_4562E0* GuiManager_FindByName(void* a, char* b);
#endif /* merge_units */
#define GuiManager_FindByName(a0, a1) ((Pg_4562E0 *)GuiManager_FindByName((int)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
Pg_4562E0* GuiWidget_FindChildByName(Pg_4562E0* a, char* b);
#endif /* merge_units */
#define GuiWidget_FindChildByName(a0, a1) ((Pg_4562E0 *)GuiWidget_FindChildByName((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
Ui_4562E0* Gui_GetScreenStack(void);
#endif /* merge_units */
#define Gui_GetScreenStack() ((Ui_4562E0 *)Gui_GetScreenStack()) /* merge_units */

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
    Pg_4562E0* bd = GuiManager_FindByName(Gui_GetScreenList(), D_004C1B00);
    if (bd) {
        Pg_4562E0* x = GuiWidget_FindChildByName(bd, a);
        Pg_4562E0* y = GuiWidget_FindChildByName(bd, b);
        if (x) {
            x->flags &= ~2;
        }
        if (y) {
            y->flags &= ~2;
        }
    }
}

extern "C" void GuiStartMenu_SelectButton(Self_4562E0* self, int which)
{
    Pg_4562E0* pg = 0;
    switch (which) {
    case 0:
        pg = GuiManager_FindOrLoad(Gui_GetScreenList(), D_004C1B48, D_004C1B58);
        break;
    case 1:
        pg = GuiManager_FindOrLoad(Gui_GetScreenList(), D_004C1B68, D_004C1B78);
        break;
    case 2:
        pg = GuiManager_FindOrLoad(Gui_GetScreenList(), D_004C1B90, D_004C1BA0);
        ShowButtons(D_004C1B18, D_004C1B20);
        break;
    case 3:
        pg = GuiManager_FindOrLoad(Gui_GetScreenList(), D_004C1BB0, D_004C1BC8);
        break;
    case 4:
        if (D_005721C8) {
            pg = GuiManager_FindOrLoad(Gui_GetScreenList(), D_004C1BD0, D_004C1BE0);
        } else {
            pg = GuiManager_FindOrLoad(Gui_GetScreenList(), D_004C1BD0, D_004C1BE8);
        }
        ShowButtons(D_004C1B28, D_004C1B38);
        break;
    case 5:
        pg = GuiManager_FindOrLoad(Gui_GetScreenList(), D_004C1BF8, D_004C1C08);
        break;
    case 6:
        if (D_004FFBA0 != 0x13 && D_004FFBA0 != 0x14) {
            char* t = Loc_LookupText(D_004C1C18);
            char* m = Loc_LookupText(D_004C1C28);
            if (t && m) {
                FrontEnd_OpenPopup(D_004FFC04, 5, t, m, self, 0);
            }
        }
        break;
    }
    if (pg) {
        int prev;
        pg->f10 = which;
        pg->flags |= 0x80;
        prev = self->f16;
        Gui_GetScreenStack()->Hide(self);
        Gui_GetScreenStack()->Show(pg, prev);
    }
}
#undef Gui_GetScreenList /* merge_units */
#undef GuiManager_FindOrLoad /* merge_units */
#undef GuiManager_FindByName /* merge_units */
#undef GuiWidget_FindChildByName /* merge_units */
#undef Gui_GetScreenStack /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004562E0 */
