/*
 * main/GuiSubTitleDisplay: 4 files, 00455C50-00455E10
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00455C50 */
#pragma push /* merge_units */
#include "types.h"
#include "grid16_flag_test.h"

DEFINE_GRID16_FLAG_TEST(func_00455C50, D_004EE620)
#pragma pop /* merge_units */
/* merge_units: end func_00455C50 */

/* merge_units: begin func_00455CB0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct V455 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(char*); };
typedef struct { char pad[0x48]; void* f48; } W455;
extern "C" {
extern void func_0041EFA0(W455*);
extern char* Loc_LookupText(char*);
extern void MLTextWidget_Clear(void*);
extern void MLTextWidget_AddText(void*, char*);
extern V455* GuiWidget_FindChildByName(W455*, char*);
extern char D_004A7520[];
extern char D_004C1A38[];
extern char D_004FFC90[];
extern void func_0041BEB0(V455*, char*, int);
}
extern "C" void func_00455CB0(W455* w) {
    V455* p;
    func_0041EFA0(w);
    if (w->f48) {
        char* t = Loc_LookupText("level_briefing");
        void* x = w->f48;
        MLTextWidget_Clear(x);
        MLTextWidget_AddText(x, t ? t : D_004C1A38);
    }
    p = GuiWidget_FindChildByName(w, "label_briefingheader");
    p = (p && p->v20(D_004A7520)) ? p : 0;
    if (p) {
        char* t = Loc_LookupText(D_004FFC90);
        func_0041BEB0(p, t ? t : D_004FFC90, 0);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00455CB0 */

/* merge_units: begin func_00455DB0 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_0041E470(char * );                            
int MLTextWidget_SetColor(int, char *);                          
extern char D_00587D20;
extern char D_00587D30;

void func_00455DB0(char * arg0) {
    char *var_a1;
    int temp_a0;

    temp_a0 = F_(arg0, 0x48, int);
    if (temp_a0 != 0) {
        if (F_(arg0, 0x14, unsigned short) & 4) {
            var_a1 = &D_00587D20;
        } else {
            var_a1 = &D_00587D30;
        }
        MLTextWidget_SetColor(temp_a0, var_a1);
    }
    func_0041E470(arg0);
}
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
extern void* D_004FFC2C;
extern char D_004FFB50[];
void func_0043D820(void* p, int v);
void func_0043D760(void* p, int v);
M_455E10* Gui_GetScreenStack(void);
void func_00456160(O_455E10* o);
void Hud_ClosePauseMenu(void* p);
void Game_SetPaused(void* p, int v);
int func_00455E10(O_455E10* o, Ev_455E10* ev);
}
static inline unsigned char Down_455E10(Ev_455E10* e) { unsigned char r = 0; if (e->type == 1 && e->b2 == 0) r = 1; return r; }
static inline unsigned char Btn_455E10(Ev_455E10* e, int b) { unsigned char r = 0; if (Down_455E10(e) && e->btn == b) r = 1; return r; }
static inline unsigned char Plain_455E10(Ev_455E10* e, int b) { unsigned char r = 0; if (Btn_455E10(e, b) && e->b6 == 0) r = 1; return r; }
static inline bool Down2_455E10(Ev_455E10* e) { return e->type == 1 && e->b2 == 0; }
static inline bool Btn2_455E10(Ev_455E10* e, int b) { return Down2_455E10(e) && e->btn == b; }
static inline bool Plain2_455E10(Ev_455E10* e, int b) { return Btn2_455E10(e, b) && e->b6 == 0; }

int func_00455E10(O_455E10* o, Ev_455E10* ev)
{
    if (Plain_455E10(ev, 0x1000) && o->f48) {
        func_0043D820(o->f48, 0);
        return 1;
    }
    if (Plain2_455E10(ev, 0x4000) && o->f48) {
        func_0043D760(o->f48, 0);
        return 1;
    }
    if (Plain2_455E10(ev, 0x10)) {
        func_00456160(o);
        return 1;
    }
    if (Plain2_455E10(ev, 0x800)) {
        Gui_GetScreenStack()->v24(o);
        Hud_ClosePauseMenu(D_004FFC2C);
        Game_SetPaused(D_004FFB50, 0);
        return 1;
    }
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00455E10 */
