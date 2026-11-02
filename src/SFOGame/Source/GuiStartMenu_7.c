/*
 * SFOGame/Source/GuiStartMenu: 9 files, 00455A20-00455C50
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00455A20 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
char *nGlobalization_GetString_charP(char *);                             
int GuiTextArrayWidget_SetText(int, int, int, char *);                  
int sprintf(char *, char *, int);                             
extern char D_004C1A38;
extern char D_004C1A40;
extern char D_004C1A50;

void GuiWeaponStats_SetItemStats(int arg0, int arg1) {
    int sp40[4];
    int var_s0;

    var_s0 = 0;
    do {
        GuiTextArrayWidget_SetText(arg0, 0, var_s0, &D_004C1A38);
        GuiTextArrayWidget_SetText(arg0, 1, var_s0, &D_004C1A38);
        var_s0 += 1;
    } while (var_s0 < 3);
    GuiTextArrayWidget_SetText(arg0, 0, 2, nGlobalization_GetString_charP(&D_004C1A40));
    sprintf(sp40, &D_004C1A50, arg1);
    GuiTextArrayWidget_SetText(arg0, 1, 2, sp40);
}
static inline void merge_flush_func_00455A20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00455A20 */

/* merge_units: begin func_00455AE0 */
#pragma push /* merge_units */
extern char D_00587D50[];
extern char D_00587D60[];
extern void GuiTextArrayWidget_SetTextColor(void* self, const char* name);
extern void GuiTextArrayWidget_onElementRender(void* self, void* data, int a, int b);
/* Sets the name (depending on whether data is given), then initialises with data. */
void GuiWeaponStats_onElementRender(void* self, void* data, int a, int b)
{
    GuiTextArrayWidget_SetTextColor(self, data == 0 ? D_00587D50 : D_00587D60);
    GuiTextArrayWidget_onElementRender(self, data, a, b);
}
static inline void merge_flush_func_00455AE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00455AE0 */

/* merge_units: begin func_00455B60 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

/* Virtual-call view of Menu: only the slots used here are named (vtable offset in comments). */
struct Menu {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual void Method5C(int a, int b); /* +0x5C */
};

extern "C" void GuiTextArrayWidget_onAdd(Menu* self);
extern "C" void GuiArrayWidget_SetColumnWidth(Menu* self, int column, int width);
extern "C" void GuiTextArrayWidget_SetFont(Menu* self, const char* name);
extern "C" void GuiTextArrayWidget_SetTextFormat(Menu* self, int value);
extern "C" void GuiWeaponStats_SetWeaponStats(Menu* self, int index);

/* Menu setup: base init, virtual +0x5C(2, 4), two column widths, the "callout" name, then GuiWeaponStats_SetWeaponStats(-1). */
extern "C" void GuiWeaponStats_onAdd(Menu* self)
{
    GuiTextArrayWidget_onAdd(self);
    self->Method5C(2, 4);
    GuiArrayWidget_SetColumnWidth(self, 0, 0x73);
    GuiArrayWidget_SetColumnWidth(self, 1, 10);
    GuiTextArrayWidget_SetFont(self, "callout");
    GuiTextArrayWidget_SetTextFormat(self, 0);
    GuiWeaponStats_SetWeaponStats(self, -1);
}
static inline void merge_flush_func_00455B60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00455B60 */

/* merge_units: begin func_00455BF0 */
#pragma push /* merge_units */
typedef struct { unsigned char flag : 1; unsigned char rest : 7; } FlagByte;
typedef struct { FlagByte b[16]; } FlagRow;
#if 0 /* merge_units */
extern FlagRow* D_004EE620;
#endif /* merge_units */
extern unsigned char* D_004EE620; /* merge_units */
#define D_004EE620 (*(FlagRow **)&D_004EE620) /* merge_units */


/* Clears flag bit 0 of byte [col] in row [row] of the global flag table. */
void TeamDelEnemy_int_int_3(int row, int col)
{
    D_004EE620[row].b[col].flag = 0;
}
#undef D_004EE620 /* merge_units */
static inline void merge_flush_func_00455BF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00455BF0 */

/* merge_units: begin func_00455C20 */
#pragma push /* merge_units */
/* Byte of per-slot flags; bit 0 is the "set" flag. */
typedef struct SlotFlags {
    unsigned char set : 1;
} SlotFlags;

#if 0 /* merge_units */
extern char* D_004EE620; /* table of 16-byte rows of flag bytes */
#endif /* merge_units */
#define D_004EE620 (*(char **)&D_004EE620) /* merge_units */



/* Sets flag bit 0 of byte `col` in row `row` of the D_004EE620 table. */
void TeamSetEnemy_int_int_3(int row, int col) {
    SlotFlags* flags = (SlotFlags*)(D_004EE620 + row * 16 + col);
    flags->set = 1;
}
#undef D_004EE620 /* merge_units */
static inline void merge_flush_func_00455C20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00455C20 */

/* merge_units: begin func_00455C50 */
#pragma push /* merge_units */
#include "grid16_flag_test.h"

DEFINE_GRID16_FLAG_TEST(TeamEnemy_int_int_3, D_004EE620)
static inline void merge_flush_func_00455C50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00455C50 */

/* merge_units: begin func_00455CB0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct V455 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(char*); };
typedef struct { char pad[0x48]; void* f48; } W455;
extern "C" {
extern void GuiWidget_onWake(W455*);
extern char* nGlobalization_GetString_charP(char*);
extern void GuiMLTextWidget_Clear(void*);
extern void GuiMLTextWidget_AddText(void*, char*);
extern V455* GuiWidget_FindChild_charP(W455*, char*);
extern char D_004A7520[];
#if 0 /* merge_units */
extern char D_004C1A38[];
#endif /* merge_units */
#define D_004C1A38 ((char*)&D_004C1A38) /* merge_units */

extern char g_LevelDirName[];
extern void GuiTextWidget_SetText(V455*, char*, int);
}
extern "C" void GuiBriefingPane_onWake(W455* w) {
    V455* p;
    GuiWidget_onWake(w);
    if (w->f48) {
        char* t = nGlobalization_GetString_charP("level_briefing");
        void* x = w->f48;
        GuiMLTextWidget_Clear(x);
        GuiMLTextWidget_AddText(x, t ? t : D_004C1A38);
    }
    p = GuiWidget_FindChild_charP(w, "label_briefingheader");
    p = (p && p->v20(D_004A7520)) ? p : 0;
    if (p) {
        char* t = nGlobalization_GetString_charP(g_LevelDirName);
        GuiTextWidget_SetText(p, t ? t : g_LevelDirName, 0);
    }
}
#undef D_004C1A38 /* merge_units */
static inline void merge_flush_func_00455CB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00455CB0 */

/* merge_units: begin func_00455DB0 */
#pragma push /* merge_units */
#pragma mpwc_relax on
int GuiWidget_onRender(char * );                            
int GuiMLTextWidget_SetTextColor(int, char *);                          
extern char D_00587D20;
extern char D_00587D30;

void GuiBriefingPane_onRender(char * arg0) {
    char *var_a1;
    int temp_a0;

    temp_a0 = F_(arg0, 0x48, int);
    if (temp_a0 != 0) {
        if (F_(arg0, 0x14, unsigned short) & 4) {
            var_a1 = &D_00587D20;
        } else {
            var_a1 = &D_00587D30;
        }
        GuiMLTextWidget_SetTextColor(temp_a0, var_a1);
    }
    GuiWidget_onRender(arg0);
}
static inline void merge_flush_func_00455DB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00455DB0 */

/* merge_units: begin func_00455E10 */
#pragma push /* merge_units */
#pragma cplusplus on
struct M_455E10 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(void* o);
};
typedef struct { unsigned short type; unsigned short b2; char pad4[2]; unsigned short b6; unsigned short btn; } Ev_455E10;
typedef struct { char pad[0x48]; void* f48; } O_455E10;
extern "C" {
extern void* g_Hud;
extern char g_Game[];
void GuiMLTextWidget_ScrollUp(void* p, int v);
void GuiMLTextWidget_ScrollDown(void* p, int v);
M_455E10* Gui_Canvas(void);
void GuiStartMenu_ReturnToMenu(O_455E10* o);
void cHud_DeactivateObjectiveMenu(void* p);
void cGameSystem_PauseGame(void* p, int v);
int GuiBriefingPane_onInput(O_455E10* o, Ev_455E10* ev);
}
static inline unsigned char Down_455E10(Ev_455E10* e) { unsigned char r = 0; if (e->type == 1 && e->b2 == 0) r = 1; return r; }
static inline unsigned char Btn_455E10(Ev_455E10* e, int b) { unsigned char r = 0; if (Down_455E10(e) && e->btn == b) r = 1; return r; }
static inline unsigned char Plain_455E10(Ev_455E10* e, int b) { unsigned char r = 0; if (Btn_455E10(e, b) && e->b6 == 0) r = 1; return r; }
static inline bool Down2_455E10(Ev_455E10* e) { return e->type == 1 && e->b2 == 0; }
static inline bool Btn2_455E10(Ev_455E10* e, int b) { return Down2_455E10(e) && e->btn == b; }
static inline bool Plain2_455E10(Ev_455E10* e, int b) { return Btn2_455E10(e, b) && e->b6 == 0; }

int GuiBriefingPane_onInput(O_455E10* o, Ev_455E10* ev)
{
    if (Plain_455E10(ev, 0x1000) && o->f48) {
        GuiMLTextWidget_ScrollUp(o->f48, 0);
        return 1;
    }
    if (Plain2_455E10(ev, 0x4000) && o->f48) {
        GuiMLTextWidget_ScrollDown(o->f48, 0);
        return 1;
    }
    if (Plain2_455E10(ev, 0x10)) {
        GuiStartMenu_ReturnToMenu(o);
        return 1;
    }
    if (Plain2_455E10(ev, 0x800)) {
        Gui_Canvas()->v24(o);
        cHud_DeactivateObjectiveMenu(g_Hud);
        cGameSystem_PauseGame(g_Game, 0);
        return 1;
    }
    return 0;
}
static inline void merge_flush_func_00455E10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00455E10 */
