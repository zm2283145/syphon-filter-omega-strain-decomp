/*
 * SFOGame/Source/GuiWeaponDisplay: 3 files, 00440EE0-00441060
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00440EE0 */
#pragma push /* merge_units */
#include "types.h"
/* VU0 identity-matrix store (vf0/qmfc2/pexcw): no C equivalent; gcc-style asm as in GuiWeaponDisplay_ctor.c. */
static inline void VU0_UnitMatrix(void* p) { int t; __asm__ volatile("sqc2 $vf0, 0x30(%1); qmfc2.ni %0, $vf0; pcpyud %0, %0, $zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, $zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(p) : "memory"); }

typedef struct Mtx { float m[4][4]; } __attribute__((aligned(16))) Mtx;

typedef struct WeaponDisplay {
    char pad0[0x50];
    float angle;       /* +0x50 */
    char pad54[0xC];
    Mtx mtx;           /* +0x60 */
    char padA0[4];
    unsigned char active; /* +0xA4 */
} WeaponDisplay;

extern float D_004C0390;
extern float D_004C0394;
extern float D_004C0398;

void GuiWidget_onAdvanceTime(void* self, float dt);
float Libc_Fmodf(float a, float b);
void* cMatrix_ctor_void(Mtx* m);
void cMatrix_SetWithAxisAngle(Mtx* m, float x, float y, float z, float a);
void cMatrix_Rotate(Mtx* d, Mtx* s);

void GuiWeaponDisplay_onAdvanceTime(WeaponDisplay* self, float dt)
{
    Mtx rot;
    float a;
    const float kPi = 3.1415927f;
    GuiWidget_onAdvanceTime(self, dt);
    if (self->active) {
        self->active = 1;
        VU0_UnitMatrix(&self->mtx);
        self->angle += dt;
        self->angle = Libc_Fmodf(self->angle, 120.0f);
        a = 3.0f * self->angle;
        a = kPi * (a / 180.0f); /* const local for kPi gives retail constant-load order */
        { Mtx* m = &self->mtx; VU0_UnitMatrix(m); }
        cMatrix_ctor_void(&rot);
        cMatrix_SetWithAxisAngle(&rot, D_004C0390, D_004C0394, D_004C0398, a);
        cMatrix_Rotate(&self->mtx, &rot);
    }
}
static inline void merge_flush_func_00440EE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00440EE0 */

/* merge_units: begin func_00441000 */
#pragma push /* merge_units */
typedef struct { char p[0x48]; int id; int val; char p50[0x50]; void* label; } W441000;
extern void GuiTextWidget_SetText(void* label, const char* text, int f);
extern char D_004C03B8[];
void GuiWeaponDisplay_SetItem(W441000* w, int id, int val, const char* text)
{
    if (w->id != id) {
        w->id = id;
        w->val = val;
        if (w->label) {
            GuiTextWidget_SetText(w->label, text ? text : D_004C03B8, 0);
        }
    }
}
static inline void merge_flush_func_00441000(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00441000 */

/* merge_units: begin func_00441060 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_common_subs off
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))

extern "C" {
char* cWeaponDB_GetEntry(int, int);
void cWeaponDB_LoadWeapon(int, int, int);
char* nGlobalization_GetString_charP(char*);
#if 0 /* merge_units */
void GuiTextWidget_SetText(int, char*, int);
#endif /* merge_units */
#define GuiTextWidget_SetText(a0, a1, a2) (GuiTextWidget_SetText((void *)(a0), (const char *)(a1), (a2))) /* merge_units */

extern int g_WeaponDatabase;
}

static inline void SetIcon(char* self, char* w) {
    int v;
    if (F_(w, 0xF0, unsigned char) == 7 && (v = F_(w, 0x11C, int)) != 0) F_(self, 0x4C, int) = v;
    else F_(self, 0x4C, int) = F_(w, 0x13C, int);
}

extern "C" void GuiWeaponDisplay_SetWeapon(char* self, int id) {
    char* w;
    char* t;
    int cur;

    if (F_(self, 0x48, int) == id) return;
    F_(self, 0x48, int) = id;
    F_(self, 0x4C, int) = 0;
    cur = F_(self, 0x48, int);
    if (cur != -1) {
        w = cWeaponDB_GetEntry(g_WeaponDatabase, cur);
        SetIcon(self, w);
        if (F_(self, 0x4C, int) == 0) {
            cWeaponDB_LoadWeapon(g_WeaponDatabase, F_(self, 0x48, int), 0);
            SetIcon(self, w);
        }
        if (F_(self, 0xA0, int) != 0) {
            t = nGlobalization_GetString_charP(w + 0x80);
            GuiTextWidget_SetText(F_(self, 0xA0, int), t ? t : w + 0x80, 0);
        }
    } else {
        int lbl = F_(self, 0xA0, int);
        if (lbl != 0) GuiTextWidget_SetText(lbl, D_004C03B8, 0);
    }
}
#undef GuiTextWidget_SetText /* merge_units */
static inline void merge_flush_func_00441060(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00441060 */
