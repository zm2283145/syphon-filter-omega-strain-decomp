/*
 * SFOGame/Source/hud: 4 files, 00241C70-00241EC0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00241C70 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int Alloc_Lock();                                    
int EnableIntc();                                  
int cHogList_Open();                     
int cFileMan_EncodeFilename_charP_cHogFileR_bool();                   
int cMemMan_Allocate();                        
int cFileMan_dtor();                            
int cFileMan_ctor_void();                               
int cInterface_ctor();                        
int sprintf();                      
extern char D_0048B2F8;
extern char D_004A7208;
extern char D_004A7210;
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;

int LoadInterface_charP_cHogListR(char *arg0, int arg1) {
    int spF0[36];
    int spD0[8];
    int sp30[40];
    int var_s0;

    cFileMan_ctor_void(sp30);
    sprintf(spF0, "%s\\COMMON\\%s.HOG", &D_0048B2F8, arg0);
    sprintf(spD0, &D_004A7208, arg0);
    cFileMan_EncodeFilename_charP_cHogFileR_bool(sp30, spD0, cHogList_Open(arg1, spF0, 0, 0), 0);
    if (g_ProfileLockEnabled != 0) {
        Alloc_Lock(9);
    }
    g_ProfileLockDepth += 1;
    var_s0 = cMemMan_Allocate(0, 8, &D_004A7210, 0x6F1);
    if (g_ProfileLockEnabled != 0) {
        EnableIntc(9);
    }
    g_ProfileLockDepth -= 1;
    if (var_s0 != 0) {
        var_s0 = cInterface_ctor(var_s0, sp30);
    }
    cFileMan_dtor(sp30, -1);
    return var_s0;
}
static inline void merge_flush_func_00241C70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00241C70 */

/* merge_units: begin func_00241DA0 */
#pragma push /* merge_units */
/* library prototypes shared by the blocks below (C linkage) */
#include "SFOLobby_helpers.h"

typedef struct { char flag; char name[16]; char value[16]; } Entry21; /* size 0x21 */
typedef struct { int unk0; int count; Entry21* data; } EntryVec;
extern void* Gui_Canvas(void);
extern void GuiWidget_SendMessage(void* a, void* b, int a2, int a3, int a4);
extern void std_vector_imp_PDAQuip_insert(EntryVec* v, Entry21* pos, int n, Entry21* value);

/* Appends a (name, value) entry to the vector after notifying the UI. */
void cHud_AddPDAQuip(EntryVec* self, const char* value, const char* name)
{
    Entry21 e;
    void* ui;
    Libc_Strcpy(e.value, value);
    Libc_Strcpy(e.name, name);
    e.flag = 0;
    ui = Gui_Canvas();
    GuiWidget_SendMessage(ui, Gui_Canvas(), 0x10, 5, 0);
    std_vector_imp_PDAQuip_insert(self, self->data + self->count, 1, &e);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00241DA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00241DA0 */

/* merge_units: begin func_00241E30 */
#pragma push /* merge_units */
typedef struct Color4 {
    float r, g, b, a;
} Color4;

typedef struct Obj6E4 {
    char pad[0x6E4];
    Color4* color;
} Obj6E4;

extern Color4 g_HudTextColour;
extern Color4 g_NvHudTextColour;
extern float g_TextColourBlock;
extern float D_0055A284;
extern float D_0055A288;
extern float D_0055A28C;
extern void nHud_UseNightVisionColors(int);

/* Selects one of two color presets and publishes it to the global color. */
void cHud_UseNightVisionColors(Obj6E4* o, int alt) {
    Color4* c;
    nHud_UseNightVisionColors(alt);
    o->color = alt ? &g_NvHudTextColour : &g_HudTextColour;
    c = o->color;
    g_TextColourBlock = c->r;
    D_0055A284 = c->g;
    D_0055A288 = c->b;
    D_0055A28C = c->a;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00241E30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00241E30 */

/* merge_units: begin func_00241EC0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Spr { int f0; float f4; };
struct SprVec { int cap; int n; Spr** data; int pad; };
struct Tgt { char pad[0x130]; int f130; };
struct Ent { char pad[0xF0]; unsigned char type; char padF1[0xF]; signed char b100; char p101[0x2F]; int f130; };
struct Hud { char pad[0x7C]; SprVec v; int cur; };
extern "C" {
extern char g_CameraObject[];
extern void* D_004FFC10;
int func_00159570(void*);
void** cLList_cCAMERA_GOBJPtr_Front(void*);
void cHud_ActivateAimCursor(Hud*);
void cHud_DeactivateAimCursor(Hud*);
void cHud_DeactivateNoFireIcon(Hud*);
Spr** std_vector_cInterfaceElementPtr_opIndex(SprVec*, int);
void cInterfaceElement_Activate(Spr*, int);
void viBufGetTs(Spr*, float);
void cAnimator_AnimateTo(Spr*, float);
}
static inline void* GetCam() { if (func_00159570(g_CameraObject)) return *cLList_cCAMERA_GOBJPtr_Front(g_CameraObject); return 0; }
static inline bool IsNoCross(Ent* e) {
    unsigned char b = 0;
    unsigned int k = e->type - 3;
    if (k < 8 && ((1 << k) & 0x83)) b = 1;
    return b;
}
static inline void Select(Hud* h, int idx) {
    if (idx >= 0) {
        if (idx == 0) cHud_ActivateAimCursor(h);
        else {
            Spr* s = h->v.data[(unsigned)(idx - 1)];
            if (s) {
                cInterfaceElement_Activate(s, 1);
                viBufGetTs(s, 1.0f);
                cAnimator_AnimateTo(s, 10.0f);
            }
            cHud_DeactivateAimCursor(h);
        }
    }
}
static inline void Unselect(Hud* h, int c) {
    if (c >= 0) {
        if (c == 0) cHud_DeactivateAimCursor(h);
        else {
            Spr* s = h->v.data[(unsigned)(c - 1)];
            if (s) cAnimator_AnimateTo(s, 0.0f);
        }
    }
}
#pragma push
#pragma opt_strength_reduction off
extern "C" int cHud_SetScope(Hud* h, int on, int a2_, Ent* e, Tgt* t)
{
    int idx = -1;
    int a2 = a2_;
    bool ok = true;
    if (on) {
        if (!a2 && t) {
            idx = t->f130 + 1;
            ok = idx < 0;
        }
        if (ok && e && !IsNoCross(e) && D_004FFC10 == GetCam()) {
            if (!a2 && e->f130 >= 0) idx = e->f130 + 1;
            else if (idx < 0 || e->type == 1) idx = 0;
        }
    }
    if (idx >= 0 && e) a2 = e->b100;
    else a2 = 0;
    if (idx != h->cur) {
        Select(h, idx);
        Unselect(h, h->cur);
    }
    if (idx < 0) cHud_DeactivateNoFireIcon(h);
    if (e && e->type == 1) cHud_DeactivateNoFireIcon(h);
    for (int i = 0; i < h->v.n; i++) {
        if (i != idx - 1 && h->v.data[i]->f4 == 0.0f)
            cInterfaceElement_Activate(*std_vector_cInterfaceElementPtr_opIndex(&h->v, i), 0);
    }
    h->cur = idx;
    return a2;
}
#pragma pop
static inline void merge_flush_func_00241EC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00241EC0 */
