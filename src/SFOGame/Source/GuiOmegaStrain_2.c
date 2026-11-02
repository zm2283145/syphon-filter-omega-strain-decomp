/*
 * SFOGame/Source/GuiOmegaStrain: 8 files, 0034E9C0-0034EC00
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0034E9C0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * GuiOmegaStrain class-name getter (vtable D_004DEDE0 slot 19).
 */

#include "loose03_types.h"

char D_004BAA30[] = "GuiOmegaStrain";       /* "GuiOmegaStrain" */

/* Returns the class name string "GuiOmegaStrain". */
const char* GuiOmegaStrain_GetClassName(void) {
    return D_004BAA30;
}
static inline void merge_flush_func_0034E9C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0034E9C0 */

/* merge_units: begin func_0034E9D0 */
#pragma push /* merge_units */
#include "types.h"

/* strcmp */
extern int strcmp(const char* a, const char* b);
/* "GuiOmegaStrain" */

/* GuiOmegaStrain type check: true when name equals the class name "GuiOmegaStrain". */
int GuiOmegaStrain_IsClass(void* self, const char* name) {
    return strcmp("GuiOmegaStrain", name) == 0;
}
static inline void merge_flush_func_0034E9D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0034E9D0 */

/* merge_units: begin func_0034EA00 */
#pragma push /* merge_units */
typedef struct { char pad[0x18]; int a18; } E34EA00;
typedef struct { int a0; int count; E34EA00* data; unsigned char aC; } L34EA00;
extern char g_Game[];
#if 0 /* merge_units */
extern void func_00296F20(L34EA00* l);
#endif /* merge_units */
void func_00296F20(void*); /* merge_units */
#define func_00296F20(a0) (func_00296F20((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern void std_vector_deleter_tRequirementInfo_dtor(L34EA00* l, int flags);
#endif /* merge_units */
void* std_vector_deleter_tRequirementInfo_dtor(void* self, short deleteFlag); /* merge_units */
#define std_vector_deleter_tRequirementInfo_dtor(a0, a1) ((void)std_vector_deleter_tRequirementInfo_dtor((void *)(a0), (short)(a1))) /* merge_units */

extern void* cGameSystem_GetAgentData(void* list, int idx);
#if 0 /* merge_units */
extern void cAgentData_GetRequirements(void* ag, int a, int b, L34EA00* l);
#endif /* merge_units */
void cAgentData_GetRequirements(void*, int, int, void*); /* merge_units */
#define cAgentData_GetRequirements(a0, a1, a2, a3) (cAgentData_GetRequirements((a0), (a1), (a2), (void *)(a3))) /* merge_units */

extern void GuiPersonnelScreen_SetupPreviewWidgets(void* o, int i, int v);
void GuiOmegaStrain_ItemGainFocus(void* o, int idx)
{
    L34EA00 l;
    func_00296F20(&l);
    l.aC = 1;
    cAgentData_GetRequirements(cGameSystem_GetAgentData(g_Game, -1), 4, 0, &l);
    if (idx >= 0 && idx < l.count) GuiPersonnelScreen_SetupPreviewWidgets(o, idx, ((E34EA00*)((char*)l.data + idx * 28))->a18);
    std_vector_deleter_tRequirementInfo_dtor(&l, 0);
}
#undef func_00296F20 /* merge_units */
#undef std_vector_deleter_tRequirementInfo_dtor /* merge_units */
#undef cAgentData_GetRequirements /* merge_units */
static inline void merge_flush_func_0034EA00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0034EA00 */

/* merge_units: begin func_0034EAB0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "member_dtor_chain.h"

/* Deleting destructor that runs the member destructor. */
DEFINE_MEMBER_DTOR_CHAIN(func_0034EAB0, std_vector_deleter_tRequirementInfo_dtor)
static inline void merge_flush_func_0034EAB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0034EAB0 */

/* merge_units: begin func_0034EB20 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "base_dtor_chain.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(func_0034EB20, std_vector_deleter_tRequirementInfo_dtor)
static inline void merge_flush_func_0034EB20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0034EB20 */

/* merge_units: begin func_0034EB80 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


Rel* func_0034EB80(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
static inline void merge_flush_func_0034EB80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0034EB80 */

/* merge_units: begin func_0034EBA0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "direct_base_dtor.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_DIRECT_BASE_DTOR(func_0034EBA0, std_vector_deleter_tRequirementInfo_dtor)
static inline void merge_flush_func_0034EBA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0034EBA0 */

/* merge_units: begin func_0034EC00 */
#pragma push /* merge_units */
#pragma cplusplus on
struct V4EC00 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); };
typedef struct { char pad[0x10]; char f10[0x14]; } E4EC00;
typedef struct { char pad[8]; E4EC00* f8; } T4EC00;
typedef struct { char pad[4]; int f4; } B4EC00;
typedef struct { char pad[0xB50]; B4EC00* fb50; } A4EC00;
typedef struct { void* vt; char f4[0x44]; void* f48; char pad[0x18]; int f64; } O4EC00;
typedef struct { char pad[0x25C]; int f25c; } G4EC00;
typedef struct { char pad[8]; unsigned char kind; char pad9[3]; int a; int b; int c; int d; } Item_4EC00;
struct AwardVec_4EC00;
extern "C" {
#if 0 /* merge_units */
extern void func_00296F20(AwardVec_4EC00*);
#endif /* merge_units */
#define func_00296F20(a0) (func_00296F20((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern void std_vector_deleter_tRequirementInfo_dtor(AwardVec_4EC00*, int);
#endif /* merge_units */
#define std_vector_deleter_tRequirementInfo_dtor(a0, a1) ((void)std_vector_deleter_tRequirementInfo_dtor((void *)(a0), (short)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void cAgentData_GetRequirements(A4EC00*, int, int, AwardVec_4EC00*);
#endif /* merge_units */
#define cAgentData_GetRequirements(a0, a1, a2, a3) (cAgentData_GetRequirements((void *)(a0), (a1), (a2), (void *)(a3))) /* merge_units */

extern char D_004BA9B8[];
extern char D_004BA9C8[];
extern char D_004BA9D8[];
extern int GuiTextListWidget_GetItemId(void*);
#if 0 /* merge_units */
extern A4EC00* cGameSystem_GetAgentData(char*, int);
#endif /* merge_units */
#define cGameSystem_GetAgentData(a0, a1) ((A4EC00 *)cGameSystem_GetAgentData((void *)(a0), (a1))) /* merge_units */

extern int Gui_Canvas(void);
extern void GuiWidget_SendMessage(O4EC00*, int, int, int, int);
extern int Gui_Manager(void);
extern void* GuiManager_OpenGui(int, char*, char*);
extern char* std_basic_string_char_char_traits_char_c_str(void*);
extern void GuiSlideShow_SetInfo(void*, int, char*, int);
extern void GuiSlideShow_Clear(void*);
extern int GuiTextListWidget_GetItemText(void*, int);
extern int GuiSlideShow_AddSection(void*, int);
extern int sprintf(char*, const char*, ...);
extern T4EC00* cAgentData_GetRanks(void);
extern G4EC00* D_004FFC04;
extern void GuiSlideShow_AddSlide(void*, int, char*, int, char*);
extern void GuiCanvas_Transition(int, O4EC00*, void*);
}
#pragma define_section DROPDTOR ".dtors_drop" far_absolute RX
struct AwardVec_4EC00 {
    int x0; int count; Item_4EC00* data; unsigned char owns;
    AwardVec_4EC00() { func_00296F20(this); owns = 1; }
    /* out-of-line copy is weak and dropped at link (as include/alloc_guard.h) */
    __declspec(weak) __declspec(DROPDTOR) ~AwardVec_4EC00() { std_vector_deleter_tRequirementInfo_dtor(this, 0); }
};
extern "C" void GuiOmegaStrain_ItemAction(O4EC00* o, int idx) {
    AwardVec_4EC00 v;
    char buf[0x20];
    void* w;
    int x;
    Item_4EC00** pd; int off;
    cAgentData_GetRequirements(cGameSystem_GetAgentData(g_Game, -1), 4, 0, &v);
    if (idx >= 0 && idx < v.count) {
        pd = &v.data; off = idx * (int)sizeof(Item_4EC00);
        if (((Item_4EC00*)((char*)*pd + off))->kind == 2) {
            GuiWidget_SendMessage(o, Gui_Canvas(), 0x10, 1, 0);
            w = GuiManager_OpenGui(Gui_Manager(), D_004BA9B8, D_004BA9C8);
            if (w) {
                {
                    char* t = std_basic_string_char_char_traits_char_c_str(o->f4);
                    GuiSlideShow_SetInfo(w, ((V4EC00*)o)->v19(), t, idx);
                }
                GuiSlideShow_Clear(w);
                x = GuiSlideShow_AddSection(w, GuiTextListWidget_GetItemText(o->f48, idx));
                {
                    Item_4EC00* it = (Item_4EC00*)((char*)*pd + off);
                    sprintf(buf, D_004BA9D8, it->a, it->b, it->c);
                }
                GuiSlideShow_AddSlide(w, x, buf, D_004FFC04->f25c, 0);
                GuiCanvas_Transition(Gui_Canvas(), o, w);
            }
        } else {
            GuiWidget_SendMessage(o, Gui_Canvas(), 0x10, 4, 0);
        }
    }
}
#undef func_00296F20 /* merge_units */
#undef std_vector_deleter_tRequirementInfo_dtor /* merge_units */
#undef cAgentData_GetRequirements /* merge_units */
#undef cGameSystem_GetAgentData /* merge_units */
static inline void merge_flush_func_0034EC00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0034EC00 */
