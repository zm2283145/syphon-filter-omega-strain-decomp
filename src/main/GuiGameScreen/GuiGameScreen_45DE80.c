/*
 * main/GuiGameScreen: range (2 files, 0045DE80-0045DFD0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop
#include "net_local_id.h"

/* library prototypes shared by the blocks below (C linkage) */
int Mem_Free();

/* merge_units: begin func_0045DE80 */
#pragma push /* merge_units */
#pragma cplusplus on
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on

#pragma opt_common_subs off

extern "C" {
int String_Dtor(int, int);                            
int func_0038CC70(int);                               
int GuiWidget_Deinit();                                  
extern unsigned char D_00533880;
}
extern "C" void func_0045DE80(char * arg0) {
    int temp_a0;
    int temp_a0_2;
    int temp_s1;
    int temp_s1_2;

    GuiWidget_Deinit();
    temp_s1 = F_(arg0, 0x48, int);
    {
        AllocGuard g;
    if (temp_s1 != 0) {
        temp_a0 = temp_s1 + 0x14;
        if (temp_a0 != 0) {
            String_Dtor(temp_a0, 0);
        }
    }
    Mem_Free(0, temp_s1, "GuiGameScreen.cc", 0x152);
    }
    temp_a0_2 = F_(arg0, 0xD8, int);
    if (temp_a0_2 != 0) {
        func_0038CC70(temp_a0_2);
        temp_s1_2 = F_(arg0, 0xD8, int);
        {
            AllocGuard g;
        Mem_Free(0, temp_s1_2, "GuiGameScreen.cc", 0x157);
        }
        F_(arg0, 0xD8, int) = 0;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0045DE80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0045DE80 */

/* merge_units: begin func_0045DFD0 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {}
#pragma inline_depth(10)
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_45DFD0;
struct W_45DFD0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual int IsA(void* t);
    char pad4[0x10];
    unsigned short flags;
    char pad16[0xB0 - 0x16];
    V4_45DFD0 cB0;
    char padC0[0x20];
    V4_45DFD0 cE0;
    unsigned char bF0;
};
typedef struct { char pad[0x10]; unsigned char b10; unsigned char b11; } T_45DFD0;
typedef struct {
    char pad[0x48]; T_45DFD0* f48; W_45DFD0* f4C; W_45DFD0* f50; char pad54[0x14]; W_45DFD0* f68; W_45DFD0* f6C;
    char pad70[0x30]; W_45DFD0* fA0; W_45DFD0* fA4; char padA8[0x38]; W_45DFD0* fE0; W_45DFD0* fE4; W_45DFD0* fE8;
    char padEC[0x28]; W_45DFD0* f114; W_45DFD0* f118; W_45DFD0* f11C; W_45DFD0* f120; W_45DFD0* f124;
} O_45DFD0;
extern "C" {
extern char D_004C2290[];extern char D_00587D80[];
extern char D_004C2268[];
extern char D_004C2430[]; extern char D_004A7520[]; extern char D_004C1D10[]; extern char D_004AA640[];
extern char D_004FFB50[];
extern V4_45DFD0 D_00587CA0; extern V4_45DFD0 D_00587CB0;
void GuiWidget_Init(O_45DFD0* o);
void* Mem_Alloc(int pool, int size, char* file, int line);
void* Gui_GetScreenList(void);
void* GuiFont_Find(void* mgr, char* name);
T_45DFD0* TextObj_Construct(void* p, int a, int b, int c, int d, void* e, char* f);
W_45DFD0* GuiWidget_FindChildByName(void* o, char* name);
void func_0041C0F0(W_45DFD0* w, int v);
char* Game_GetPlayerNameSlot(void* p, int id);
void GuiTextWidget_SetText(W_45DFD0* w, char* s, int f);
void GuiGameScreen_InitWeaponSelect(O_45DFD0* o);
void GuiGameScreen_Init(O_45DFD0* o);
}
static inline void* Alloc_45DFD0(int n, int line) { AllocGuard g; return Mem_Alloc(0, n, D_004C2290, line); }
static inline W_45DFD0* Cast_45DFD0(W_45DFD0* w, void* t) { return w && w->IsA(t) ? w : 0; }
static inline void SetB0_45DFD0(W_45DFD0* w, V4_45DFD0 c) { w->cB0.x = c.x; w->cB0.y = c.y; w->cB0.z = c.z; w->cB0.w = c.w; }
static inline void SetE0_45DFD0(W_45DFD0* w, V4_45DFD0 c) { w->cE0.x = c.x; w->cE0.y = c.y; w->cE0.z = c.z; w->cE0.w = c.w; }

void GuiGameScreen_Init(O_45DFD0* o)
{
    T_45DFD0* t;
    GuiWidget_Init(o);
    t = (T_45DFD0*)Alloc_45DFD0(0x60, 0x107);
    if (t) t = TextObj_Construct(t, 0, 0, 10, 10, GuiFont_Find(Gui_GetScreenList(), "callout"), D_00587D80);
    o->f48 = t;
    o->f48->b10 = 2;
    o->f48->b11 = 1;
    o->f4C = Cast_45DFD0(GuiWidget_FindChildByName(o, "quickchat"), D_004C2430);
    o->f50 = Cast_45DFD0(GuiWidget_FindChildByName(o, "interact"), D_004A7520);
    o->f68 = Cast_45DFD0(GuiWidget_FindChildByName(o, "subtitles"), D_004C1D10);
    o->fE0 = GuiWidget_FindChildByName(o, "choosemenu");
    if (o->fE0) {
        o->fE4 = Cast_45DFD0(GuiWidget_FindChildByName(o->fE0, "title"), D_004A7520);
        func_0041C0F0(o->fE4, 1);
        o->fE8 = Cast_45DFD0(GuiWidget_FindChildByName(o->fE0, "choices"), D_004AA640);
        SetB0_45DFD0(o->fE8, D_00587CA0);
        SetE0_45DFD0(o->fE8, D_00587CB0);
        o->fE8->bF0 = 1;
    }
    if (!o->fE0 || !o->fE4 || !o->fE8) o->fE0 = 0;
    o->f114 = Cast_45DFD0(GuiWidget_FindChildByName(o, "value_codename"), D_004A7520);
    if (o->f114) {
        if (D_005721C8) {
            char* s = Game_GetPlayerNameSlot(D_004FFB50, NetLocalId());
            GuiTextWidget_SetText(o->f114, s ? s : D_004C2268, 0);
            o->f114->flags |= 2;
        } else {
            o->f114->flags &= ~2;
        }
    }
    o->f118 = Cast_45DFD0(GuiWidget_FindChildByName(o, "value_timer_description"), D_004A7520);
    o->f11C = Cast_45DFD0(GuiWidget_FindChildByName(o, "value_timer"), D_004A7520);
    o->f118->flags &= ~2;
    o->f11C->flags &= ~2;
    o->f120 = Cast_45DFD0(GuiWidget_FindChildByName(o, "headset_playing"), D_004A7520);
    o->f124 = GuiWidget_FindChildByName(o, "label_talking");
    o->f6C = GuiWidget_FindChildByName(o, "weaponselect");
    o->fA4 = GuiWidget_FindChildByName(o, "lines_arrows");
    o->fA0 = GuiWidget_FindChildByName(o, "brackets");
    GuiGameScreen_InitWeaponSelect(o);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0045DFD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0045DFD0 */
