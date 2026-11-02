/*
 * SFOGame/Source/GuiRanks: 5 files, 0034E5A0-0034E760
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin GuiRanks_34E5A0 */
#pragma push /* merge_units */
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
extern char g_Game[];
#if 0 /* merge_units */
extern A34E5* cGameSystem_GetAgentData(char*, int);
#endif /* merge_units */
void* cGameSystem_GetAgentData(void* list, int index); /* merge_units */
#define cGameSystem_GetAgentData(a0, a1) ((A34E5 *)cGameSystem_GetAgentData((void *)(a0), (a1))) /* merge_units */

extern int Gui_Canvas(void);
extern void GuiWidget_SendMessage(O34E5*, int, int, int, int);
extern int Gui_Manager(void);
extern void* GuiManager_OpenGui(int, char*, char*);
extern char* std_basic_string_char_char_traits_char_c_str(void*);
extern void GuiSlideShow_SetInfo(void*, int, char*, int);
extern void GuiSlideShow_Clear(void*);
extern int GuiTextListWidget_GetItemText(void*, int);
extern int GuiSlideShow_AddSection(void*, int);
extern int sprintf(char*, const char*, ...);
#if 0 /* merge_units */
extern T34E5* cAgentData_GetRanks(void);
#endif /* merge_units */
int cAgentData_GetRanks(void); /* merge_units */
#define cAgentData_GetRanks() ((T34E5 *)cAgentData_GetRanks()) /* merge_units */

extern G34E5* D_004FFC04;
extern void GuiSlideShow_AddSlide(void*, int, char*, int, char*);
extern void GuiCanvas_Transition(int, O34E5*, void*);
}
extern "C" void GuiRanks_ItemAction(O34E5* o, int idx) {
    char buf[0x20];
    int sel = GuiTextListWidget_GetItemId(o->f48);
    void* w;
    int x;
    if (sel == -1) return;
    if (!(cGameSystem_GetAgentData(g_Game, -1)->fb50->f4 < sel)) {
    GuiWidget_SendMessage(o, Gui_Canvas(), 0x10, 1, 0);
    w = GuiManager_OpenGui(Gui_Manager(), "GuiSlideShow", "ZEUSHELL");
    if (!w) return;
    {
        char* t = std_basic_string_char_char_traits_char_c_str(o->f4);
        GuiSlideShow_SetInfo(w, ((V34E5*)o)->v19(), t, idx);
    }
    GuiSlideShow_Clear(w);
    x = GuiSlideShow_AddSection(w, GuiTextListWidget_GetItemText(o->f48, idx));
    sprintf(buf, "0_%d_%d.tdx", o->f64, sel + 1);
    {
        T34E5* tab;
        cGameSystem_GetAgentData(g_Game, -1);
        tab = cAgentData_GetRanks();
        GuiSlideShow_AddSlide(w, x, buf, D_004FFC04->f25c, tab->f8[sel].f10);
    }
    GuiCanvas_Transition(Gui_Canvas(), o, w);
    } else {
        GuiWidget_SendMessage(o, Gui_Canvas(), 0x10, 4, 0);
    }
}
#undef cGameSystem_GetAgentData /* merge_units */
#undef cAgentData_GetRanks /* merge_units */
static inline void merge_flush_GuiRanks_34E5A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end GuiRanks_34E5A0 */

/* merge_units: begin func_0034E760 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern char g_RankRows[];

int cAgentData_GetRanks(void) {
    return (int)g_RankRows;
}
static inline void merge_flush_func_0034E760(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0034E760 */

/* merge_units: begin func_0034E770 */
#pragma push /* merge_units */
typedef struct { char pad[0xC]; int value; char pad2[0x14]; } Entry36;
typedef struct { char pad[8]; Entry36* entries; } EntryTable;
typedef struct { char pad[0x48]; void* key; } Obj48;
#if 0 /* merge_units */
extern int GuiTextListWidget_GetItemId(void* key);
#endif /* merge_units */
#define GuiTextListWidget_GetItemId(a0) (GuiTextListWidget_GetItemId((a0))) /* merge_units */

extern void* cGameSystem_GetAgentData(void* list, int index);
#if 0 /* merge_units */
extern EntryTable* cAgentData_GetRanks(void);
#endif /* merge_units */
#define cAgentData_GetRanks() ((EntryTable *)cAgentData_GetRanks()) /* merge_units */



extern void GuiPersonnelScreen_SetupPreviewWidgets(Obj48* o, int idx, int value);
/* Looks up the entry index for the key and applies its value. */
void GuiRanks_ItemGainFocus(Obj48* o)
{
    int idx = GuiTextListWidget_GetItemId(o->key);
    if (idx != -1) {
        Entry36* e;
        cGameSystem_GetAgentData(g_Game, -1);
        e = &cAgentData_GetRanks()->entries[idx];
        GuiPersonnelScreen_SetupPreviewWidgets(o, idx, e->value);
    }
}
#undef GuiTextListWidget_GetItemId /* merge_units */
#undef cAgentData_GetRanks /* merge_units */
static inline void merge_flush_func_0034E770(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0034E770 */

/* merge_units: begin func_0034E7F0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * GuiRanks constructor (vtable D_004DED50); derives from GuiPersonnelScreen.
 */

#include "loose03_types.h"

extern char D_004DED50[];       /* vtable */
extern int GuiPersonnelScreen_ctor(GuiPersonnelScreen*);

/* GuiPersonnelScreen subclass constructor (unk64 = 6). */
GuiPersonnelScreen* GuiRanks_ctor(GuiPersonnelScreen* self) {
    GuiPersonnelScreen_ctor(self);
    self->base.vtable = D_004DED50;
    self->unk64 = 6;
    return self;
}
static inline void merge_flush_func_0034E7F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0034E7F0 */

/* merge_units: begin func_0034E830 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

/* Derived destructor: restore vtable, run base destructor, optionally delete. */
DEFINE_VTABLE_BASE_DTOR(GuiPersonnelScreen_dtor_34E830, D_004DF0B0, GuiWidget_dtor)
static inline void merge_flush_func_0034E830(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0034E830 */
