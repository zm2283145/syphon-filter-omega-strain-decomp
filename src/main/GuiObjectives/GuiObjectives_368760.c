/*
 * main/GuiObjectives: 3 files, 00368760-00368E10
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00368760 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad[0xD4]; float time; char padD8[0xB71 - 0xD8]; unsigned char flagB71; } AgentT;
typedef struct { char pad[0x64]; int a64; char pad68[0x70 - 0x68]; void* text; void* text2; char pad78[0x89 - 0x78]; unsigned char useTimer; } S368620;
extern AgentT* Agent_GetSelected(void* list, int idx);
extern float Hud_GetMissionTime(int id);
extern void GuiObjectives_FillList(S368620* self);
extern void GuiTextWidget_SetText(void* text, char* str, int flag);
extern void GuiTextWidget_SetColour(void* text, void* color);
extern void GuiWidget_BaseWake(S368620* self);
extern void GuiObjectives_SetTab(S368620* self, int a, int b);
extern int sprintf(char* buf, const char* fmt, ...);
extern char D_004BBC48[];
extern char g_Game[];
extern int g_Hud;
extern char D_00587D00[];
extern char D_00587D10[];

void GuiObjectives_Wake(S368620* self) {
    char buf[32];
    float f;

    GuiWidget_BaseWake(self);
    if (self->text != 0) {
        if (self->useTimer) {
            f = Hud_GetMissionTime(g_Hud);
        } else {
            f = Agent_GetSelected(g_Game, -1)->time;
            asm { .set reorder } /* scheduling barrier: keeps cvt at the join, not in the b delay slot */
        }
        { int t = f; int m = t / 60; sprintf(buf, D_004BBC48, m, t - m * 60); }
        if (!self->useTimer) {
            if (Agent_GetSelected(g_Game, -1)->flagB71) {
                GuiTextWidget_SetColour(self->text, D_00587D00);
                GuiTextWidget_SetColour(self->text2, D_00587D00);
            } else {
                GuiTextWidget_SetColour(self->text, D_00587D10);
                GuiTextWidget_SetColour(self->text2, D_00587D10);
            }
        }
        GuiTextWidget_SetText(self->text, buf, 0);
    }
    GuiObjectives_FillList(self);
    GuiObjectives_SetTab(self, 0, !self->a64);
}
#pragma pop /* merge_units */
/* merge_units: end func_00368760 */

/* merge_units: begin func_003688C0 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_3688C0;
struct W_3688C0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual int IsA(void* t);
    char pad4[0x10];
    unsigned short flags;
    char pad16[0x38 - 0x16];
    float f38;
    char pad3C[4];
    float f40;
    char pad44[0x5C - 0x44];
    int f5C;
    char pad60[0x88 - 0x60];
    W_3688C0* f88;
    char pad8C[0xB0 - 0x8C];
    V4_3688C0 cB0;
};
typedef struct {
    char pad[0x48]; W_3688C0* slots[3]; W_3688C0* f54; char pad58[8]; W_3688C0* f60; W_3688C0* f64;
    W_3688C0* f68; W_3688C0* f6C; W_3688C0* f70; W_3688C0* f74; int f78; int f7C; W_3688C0* f80; int f84;
} O_3688C0;
extern "C" {
extern char D_004BBC90[]; extern char D_004BBCB0[]; extern char D_004BBCC8[]; extern char D_004BBCD0[]; extern char D_004BBCE0[];
extern char D_004BBD00[]; extern char D_004BBD18[]; extern char D_004BBD20[]; extern char D_004BBD38[]; extern char D_004BBD48[];
extern char D_004BBD58[]; extern char D_004BBD68[]; extern char D_004BBD70[]; extern char D_004BBD80[]; extern char D_004BBD88[];
extern char D_004A9870[]; extern char D_004AA640[]; extern char D_004A7520[];
extern char g_LevelDirName[];
extern unsigned char g_IsMultiplayer;
static const unsigned int dat_00492F60[2] = { 0x3, 0x0 };
extern V4_3688C0 D_00587CE0; extern V4_3688C0 D_00587CC0;
void GuiWidget_Init(O_3688C0* o);
W_3688C0* GuiWidget_FindChildByName(void* o, char* name);
int sprintf(char* buf, const char* fmt, ...);
void GuiTextListWidget_SetFont(W_3688C0* w, char* s);
void GuiArrayWidget_RowHeight(W_3688C0* w, int v);
int Awards_GetParTime(void* p, unsigned char f);
void String_Copy(void* d, char* s);
#if 0 /* merge_units */
void GuiTextWidget_SetText(W_3688C0* w, char* s, int f);
#endif /* merge_units */
#define GuiTextWidget_SetText(a0, a1, a2) (GuiTextWidget_SetText((void *)(a0), (a1), (a2))) /* merge_units */

char* Loc_LookupText(char* k);
void GuiTextWidget_SetDisableWrap(W_3688C0* w, int v);
void GuiObjectives_Init(O_3688C0* o);
}
static inline W_3688C0* Cast_3688C0(W_3688C0* w, void* t) { return w && w->IsA(t) ? w : 0; }
static inline void SetC_3688C0(W_3688C0* w, V4_3688C0 c) { w->cB0.x = c.x; w->cB0.y = c.y; w->cB0.z = c.z; w->cB0.w = c.w; }

void GuiObjectives_Init(O_3688C0* o)
{
    int i;
    W_3688C0* t;
    GuiWidget_Init(o);
    o->f60 = GuiWidget_FindChildByName(o, D_004BBC90);
    o->f64 = GuiWidget_FindChildByName(o, D_004BBCB0);
    if (o->f64) {
        o->f68 = Cast_3688C0(GuiWidget_FindChildByName(o, D_004BBCC8), D_004A9870);
        o->f6C = Cast_3688C0(GuiWidget_FindChildByName(o, D_004BBCD0), D_004A9870);
        if (o->f68) o->f68->flags &= ~0x80;
        if (o->f6C) o->f6C->flags &= ~0x80;
    } else {
        o->f68 = 0;
        o->f6C = 0;
    }
    o->f80 = GuiWidget_FindChildByName(o, D_004BBCE0);
    for (i = 0; i < 4; i++) {
        char name[32];
        sprintf(name, D_004BBD00, i);
        o->slots[i] = Cast_3688C0(GuiWidget_FindChildByName(o, name), D_004AA640);
        if (o->slots[i]) {
            GuiTextListWidget_SetFont(o->slots[i], D_004BBD18);
            if (i == 0) {
                W_3688C0* w = GuiWidget_FindChildByName(o, D_004BBD20);
                if (w) w->flags &= ~2;
                SetC_3688C0(o->slots[i], D_00587CE0);
                o->slots[i]->f88 = w;
            } else {
                SetC_3688C0(o->slots[i], D_00587CC0);
            }
            o->slots[i]->flags &= ~0x80;
            GuiArrayWidget_RowHeight(o->slots[i], o->slots[i]->f5C - (*(int*)dat_00492F60));
        }
    }
    if (o->f54) {
        o->f78 = (int)o->f54->f38;
        o->f7C = (int)o->f54->f40;
        if (o->f80) o->f84 = (int)(o->f80->f38 - (float)o->f78);
    }
    o->f70 = Cast_3688C0(GuiWidget_FindChildByName(o, D_004BBD38), D_004A7520);
    o->f74 = Cast_3688C0(GuiWidget_FindChildByName(o, D_004BBD48), D_004A7520);
    t = Cast_3688C0(GuiWidget_FindChildByName(o, D_004BBD58), D_004A7520);
    if (t) {
        char buf[32];
        int r = Awards_GetParTime(g_LevelDirName, g_IsMultiplayer);
        if (r < 0) String_Copy(buf, D_004BBD68);
        else {
            int m = r / 60;
            r -= m * 60;
            sprintf(buf, D_004BBC48, m, r);
        }
        GuiTextWidget_SetText(t, buf, 0);
    }
    t = Cast_3688C0(GuiWidget_FindChildByName(o, D_004BBD70), D_004A7520);
    if (t) {
        char* s = Loc_LookupText(g_IsMultiplayer ? D_004BBD80 : D_004BBD88);
        if (s) {
            GuiTextWidget_SetText(t, s, 0);
            GuiTextWidget_SetDisableWrap(t, 1);
        }
    }
}
#undef GuiTextWidget_SetText /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003688C0 */

/* merge_units: begin func_00368E10 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * GuiObjectives constructor (vtable D_004DF5C0).
 */

#include "loose03_types.h"

extern char D_004DF5C0[];       /* GuiObjectives vtable */
extern void GuiWidget_ctor(GuiObjectives*);

/* GuiObjectives constructor. */
GuiObjectives* GuiObjectives_ctor(GuiObjectives* self, int a1, int a2) {
    GuiWidget_ctor(self);
    self->base.vtable = D_004DF5C0;
    self->unk5C = -1;
    self->unk58 = 0;
    self->unk78 = 0;
    self->unk7C = 0;
    self->unk84 = 0;
    self->unk88 = a1;
    self->unk89 = a2;
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_00368E10 */
