/*
 * SFOGame/Source/GuiEquipmentSetup: 3 files, 002A3B80-002A3BF0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002A3B80 */
#pragma push /* merge_units */
#include "types.h"
#include "GuiEquipmentSetup_types.h"

typedef struct { char pad[0x32]; unsigned char unk32; } Sub002A3B80;
typedef struct { char pad[0x3584]; Sub002A3B80* sub; } Obj002A3B80;
/* Return byte 0x32 of the sub-object, or 0 if none. */
int func_002A3B80(Obj002A3B80* obj)
{
    Sub002A3B80* sub = obj->sub;
    if (sub) {
        return sub->unk32;
    }
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002A3B80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002A3B80 */

/* merge_units: begin func_002A3BA0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiEquipmentSetup.cc. Functions are named by address
 * until real names are known.
 */


extern int GuiWidget_onWake(GuiEquipmentSetup* self);

int func_002A3BA0(char* self) {
    return *(int*)(self + 0);
}

/* Calls the base handler, then resets +0xDC and the view angle to pi. */
int GuiEquipmentSetup_Wake(GuiEquipmentSetup* self) {
    int result = GuiWidget_onWake(self);

    self->unkDC = 0;
    self->angle = 3.14159265f;
    return result;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002A3BA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002A3BA0 */

/* merge_units: begin func_002A3BF0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "gui_widget_vslots.h"
struct Vec2 { float x, y; Vec2() {} Vec2(float ax, float ay) { x = ax; y = ay; } };
struct V4 {
    float x, y, z, w;
    V4() {}
    V4(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
} __attribute__((aligned(16)));
struct W_002A3BF0 : GuiWidgetV { char pad4[0x10]; unsigned short flags; char pad16[0x48 - 0x16]; void* f48; };
struct St_002A3BF0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26();
    virtual void SetState(int s); virtual unsigned char GetState();
};
struct Net_002A3BF0 { char pad[0x30]; St_002A3BF0* p30; };
struct G_002A3BF0 { char pad[0x251]; unsigned char b251; char pad252[2]; int n254; };
struct S_002A3BF0 { char pad0[0x80]; V4 f80; V4 f90; V4 fA0; char padB0[0x20]; W_002A3BF0* fD0; char* fD4; };
extern "C" {
extern char D_0048BA80[];
extern char D_004AB1B0[];
extern char D_004A9BF0[];
extern char D_004AB0B0[];
extern char D_004A9870[];
extern char D_004AB1A0[];
extern char D_004AB100[];
extern char D_004AB110[];
extern char D_004AB168[];
extern char D_004AB1C0[];
extern char D_004AB1D0[];
extern char D_004AB1E0[];
extern char D_004AB1F0[];
extern char D_004A7520[];
extern char D_004AB200[];
extern char D_004AB210[];
extern char D_004AB220[];
extern char D_004AB230[];
extern char D_004AB240[];
extern char D_004AB120[];
extern char D_004AB250[];
extern unsigned char g_IsMultiplayer;
extern unsigned char D_005721C0;
extern Net_002A3BF0* g_LocalPlayer;
extern G_002A3BF0* D_004FFC04;
extern void* D_00506550;
extern int D_00506508;
void GuiWidget_onAdd(void);
char* nGlobalization_GetString_charP(char* key);
void GuiTextWidget_SetText(void* w, char* s, int a);
char* GetCodename(int n);
int ES_ManRenderWrapper(void);
void func_002A5470(W_002A3BF0* w, Vec2 off);
}
static inline W_002A3BF0* FindAs(void* self, char* n, char* t)
{
    W_002A3BF0* w = (W_002A3BF0*)GuiWidget_FindChild_charP(self, n);
    unsigned char ok = 0;
    if (w && w->IsA(t)) ok = 1;
    return ok ? w : 0;
}
#define FIND(n, t) FindAs(self, n, t)
extern "C" void GuiEquipmentSetup_Init(S_002A3BF0* self0)
{
    char* t;
    int n;
    int i;
    W_002A3BF0* w;
    S_002A3BF0* self = self0;
    GuiWidget_onAdd();
    {
    W_002A3BF0* w0 = FIND(D_004AB1B0, D_004A9BF0);
    if (w0) {
        D_00506550 = self;
        w0->f48 = (void*)ES_ManRenderWrapper;
    }
    }
    w = FIND(D_004AB0B0, D_004A9870);
    t = nGlobalization_GetString_charP(D_004AB1A0);
    if (g_IsMultiplayer) {
        unsigned char ok;
        if (g_IsMultiplayer)
            ok = D_005721C0;
        else
            ok = 1;
        if (!ok)
            t = nGlobalization_GetString_charP(D_004AB110);
        else
            t = nGlobalization_GetString_charP(D_004AB100);
    }
    if (g_LocalPlayer->p30->GetState() == 3)
        t = nGlobalization_GetString_charP(D_004AB100);
    if (t && w)
        GuiTextWidget_SetText(w, t, 0);
    t = nGlobalization_GetString_charP(D_004AB168);
    w = FIND(D_004AB1C0, D_004A7520);
    if (t && w)
        GuiTextWidget_SetText(w, t, 0);
    w = FIND(D_004AB1D0, D_004A7520);
    if (t && w)
        GuiTextWidget_SetText(w, t, 0);
    w = FIND(D_004AB1E0, D_004A7520);
    if (t && w)
        GuiTextWidget_SetText(w, t, 0);
    w = FIND(D_004AB1F0, D_004A7520);
    if (t && w)
        GuiTextWidget_SetText(w, t, 0);
    for (i = 0; i < 4; i++) {
        char buf[16] = "1value_codename";
        buf[0] = '1' + i;
        W_002A3BF0* w2 = FIND(buf, D_004A7520);
        GuiTextWidget_SetText(w2, GetCodename(i), 0);
    }
    {
    W_002A3BF0* slots[4];
    for (i = 0; i < 4; i++) {
        char buf2[18] = "1player_stats_grp";
        buf2[0] = '1' + i;
        slots[i] = (W_002A3BF0*)GuiWidget_FindChild_charP(self, buf2);
    }
    n = D_004FFC04->n254;
    {
    int j;
    for (j = n; j < 4; j++) {
        if (slots[j])
            slots[j]->flags &= ~2;
    }
    }
    switch (n) {
    case 1:
        { V4 t = V4(0.0f, 5.0f, -2.0f, 1.0f); V4* d = &self->f80; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(&t) : "memory"); }
        func_002A5470(slots[0], Vec2(244.5f, 0.0f));
        break;
    case 2:
        { V4 t = V4(-1.4f, 5.0f, -2.0f, 1.0f); V4* d = &self->f80; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(&t) : "memory"); }
        { V4 t = V4(1.4f, 5.0f, -2.0f, 1.0f); V4* d = &self->f90; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(&t) : "memory"); }
        func_002A5470(slots[0], Vec2(163.0f, 0.0f));
        func_002A5470(slots[1], Vec2(163.0f, 0.0f));
        break;
    case 3:
        { V4 t = V4(-2.8f, 5.0f, -2.0f, 1.0f); V4* d = &self->f80; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(&t) : "memory"); }
        { V4 t = V4(0.0f, 5.0f, -2.0f, 1.0f); V4* d = &self->f90; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(&t) : "memory"); }
        { V4 t = V4(2.8f, 5.0f, -2.0f, 1.0f); V4* d = &self->fA0; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(&t) : "memory"); }
        func_002A5470(slots[0], Vec2(81.5f, 0.0f));
        func_002A5470(slots[1], Vec2(81.5f, 0.0f));
        func_002A5470(slots[2], Vec2(81.5f, 0.0f));
        break;
    }
    }
    t = nGlobalization_GetString_charP(D_004AB200);
    w = FIND(D_004AB210, D_004A7520);
    if (t && w) {
        GuiTextWidget_SetText(w, t, 0);
        w->flags |= 2;
    }
    t = nGlobalization_GetString_charP(D_004AB220);
    w = FIND(D_004AB230, D_004A7520);
    if (t && w) {
        GuiTextWidget_SetText(w, t, 0);
        w->flags |= 2;
    }
    self->fD0 = FIND(D_004AB240, D_004A7520);
    if (!D_00506508)
        self->fD0->flags &= ~2;
    {
    W_002A3BF0* w2 = (W_002A3BF0*)GuiWidget_FindChild_charP(self, D_004AB120);
    if (w2) {
        unsigned char b = !D_004FFC04->b251;
        if (b)
            w2->flags |= 4;
        else
            w2->flags &= ~4;
    }
    }
    self->fD4 = nGlobalization_GetString_charP(D_004AB250);
    if (!self->fD4)
        self->fD4 = D_0048BA80;
}
static inline void merge_flush_func_002A3BF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A3BF0 */
