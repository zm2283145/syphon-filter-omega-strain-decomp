/*
 * SFOGame/Source/GuiDossiers: 5 files, 00349E90-00349FD0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00349E90 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * GuiDossiers class-name getter (vtable D_004DEC30 slot 19).
 */

#include "loose03_types.h"

char D_004BA650[] = "GuiDossiers";       /* "GuiDossiers" */

/* Returns the class name string "GuiDossiers". */
const char* GuiDossiers_GetClassName(void) {
    return D_004BA650;
}
static inline void merge_flush_func_00349E90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00349E90 */

/* merge_units: begin func_00349EA0 */
#pragma push /* merge_units */
#include "types.h"
extern int strcmp(void* p);
/* Returns whether the test on the global object fails. */
int GuiDossiers_IsClass(void) { return strcmp("GuiDossiers") == 0; }
static inline void merge_flush_func_00349EA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00349EA0 */

/* merge_units: begin func_00349ED0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void GuiPersonnelScreen_ItemGainFocus(void) {
}
static inline void merge_flush_func_00349ED0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00349ED0 */

/* merge_units: begin func_00349EE0 */
#pragma push /* merge_units */
/* GuiDossiers_PopulateList: fill list widget (f48) with the selected agent's entry + D_00532B70 entries; enum-typed 4th param + ternary gives the movz. */
enum OnOff { ON0, ON1 };
#pragma opt_strength_reduction off
typedef struct { int a; int pad[8]; } Ent;
typedef struct { int unk00; int count; Ent* data; } EntVec;
typedef struct { char pad[0x48]; void* f48; } Self;
extern char g_Game[];
extern EntVec D_00532B70;
void* cGameSystem_GetAgentData(void* list, int idx);
int cAgentData_GetUserName(void* ag);
void GuiTextListWidget_AddItem(void* w, int text, int i, enum OnOff dis);
int nGlobalization_GetString_charP(int id);
int cAgentData_IsDossierUnlocked(void* self, int i);
void GuiDossiers_PopulateList(Self* self)
{
    void* ag = cGameSystem_GetAgentData(g_Game, -1);
    EntVec* v = &D_00532B70;
    int i;
    GuiTextListWidget_AddItem(self->f48, cAgentData_GetUserName(ag), 0, 0);
    for (i = 1; i < v->count; i++) {
        int text = nGlobalization_GetString_charP(v->data[i].a);
        GuiTextListWidget_AddItem(self->f48, text, i, cAgentData_IsDossierUnlocked(ag, i) ? ON0 : ON1);
    }
}
static inline void merge_flush_func_00349EE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00349EE0 */

/* merge_units: begin func_00349FD0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct V_49FD0 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); };
typedef struct { void* vt; char f4[0x44]; void* f48; } O_49FD0;
typedef struct { char pad[0x25C]; int f25c; int f260; } G_49FD0;
extern "C" {
extern G_49FD0* D_004FFC04;
extern char D_004BA5C8[];
extern char D_004BA5D0[];
extern char D_004BA5E0[];
extern char D_004BA5F0[];
extern char D_004BA600[];
extern char D_004BA610[];
extern char D_004BA620[];
extern int GuiTextListWidget_GetItemId(void*);
#if 0 /* merge_units */
extern void* cGameSystem_GetAgentData(char*, int);
#endif /* merge_units */
#define cGameSystem_GetAgentData(a0, a1) (cGameSystem_GetAgentData((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int cAgentData_IsDossierUnlocked(void*, int);
#endif /* merge_units */
#define cAgentData_IsDossierUnlocked(a0, a1) (cAgentData_IsDossierUnlocked((a0), (a1))) /* merge_units */

extern int Gui_Canvas(void);
extern void GuiWidget_SendMessage(O_49FD0*, int, int, int, int);
extern void FrontEnd_StartSplashThread(void*);
#if 0 /* merge_units */
extern char* nGlobalization_GetString_charP(char*);
#endif /* merge_units */
#define nGlobalization_GetString_charP(a0) ((char *)nGlobalization_GetString_charP((int)(a0))) /* merge_units */

extern int cGameFrontEnd_PushMessageBox(void* ui, int a, char* b, char* c, void* d, int e);
extern void cGameFrontEnd_PopMessageBox(void* ui, int p);
extern void FrontEnd_StopSplashThread(void* ui);
extern int Gui_Manager(void);
extern void* GuiManager_OpenGui(int, char*, char*);
extern void GuiAgentInfo_DisplayLocalAgent(void*);
extern void GuiCanvas_Transition(int, O_49FD0*, void*);
extern char* std_basic_string_char_char_traits_char_c_str(void*);
extern void GuiSlideShow_SetInfo(void*, int, char*, int);
extern void GuiSlideShow_Clear(void*);
extern int GuiTextListWidget_GetItemText(void*, int);
extern int GuiSlideShow_AddSection(void*, int);
extern int sprintf(char*, const char*, ...);
extern void GuiSlideShow_AddSlide(void*, int, char*, int, char*);
void GuiDossiers_ItemAction(O_49FD0* o, int idx);
}
void GuiDossiers_ItemAction(O_49FD0* o, int idx)
{
    int id = GuiTextListWidget_GetItemId(o->f48);
    if (id == -1 || !cAgentData_IsDossierUnlocked(cGameSystem_GetAgentData(g_Game, -1), id)) {
        GuiWidget_SendMessage(o, Gui_Canvas(), 0x10, 4, 0);
        return;
    }
    GuiWidget_SendMessage(o, Gui_Canvas(), 0x10, 0, 0);
    if (id == 0) {
        bool splash = !D_004FFC04->f260;
        int popup = -2;
        void* w;
        if (splash) {
            FrontEnd_StartSplashThread(D_004FFC04);
            {
                void* ui = D_004FFC04;
                popup = cGameFrontEnd_PushMessageBox(ui, 0, D_004BA5C8, nGlobalization_GetString_charP(D_004BA5D0), 0, 0);
            }
        }
        w = GuiManager_OpenGui(Gui_Manager(), D_004BA5E0, D_004BA5F0);
        if (splash) {
            cGameFrontEnd_PopMessageBox(D_004FFC04, popup);
            FrontEnd_StopSplashThread(D_004FFC04);
        }
        if (w) {
            GuiAgentInfo_DisplayLocalAgent(w);
            GuiCanvas_Transition(Gui_Canvas(), o, w);
        }
    } else {
        void* w = GuiManager_OpenGui(Gui_Manager(), D_004BA600, D_004BA610);
        if (w) {
            char buf[0x20];
            int x;
            {
                char* t = std_basic_string_char_char_traits_char_c_str(o->f4);
                GuiSlideShow_SetInfo(w, ((V_49FD0*)o)->v19(), t, idx);
            }
            GuiSlideShow_Clear(w);
            x = GuiSlideShow_AddSection(w, GuiTextListWidget_GetItemText(o->f48, idx));
            sprintf(buf, D_004BA620, 1, id);
            GuiSlideShow_AddSlide(w, x, buf, D_004FFC04->f25c, 0);
            GuiCanvas_Transition(Gui_Canvas(), o, w);
        }
    }
}
#undef cGameSystem_GetAgentData /* merge_units */
#undef cAgentData_IsDossierUnlocked /* merge_units */
#undef nGlobalization_GetString_charP /* merge_units */
static inline void merge_flush_func_00349FD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00349FD0 */
