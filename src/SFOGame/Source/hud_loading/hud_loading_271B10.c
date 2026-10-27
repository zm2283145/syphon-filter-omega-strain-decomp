/*
 * main/hud_loading: 6 files, 00271B10-00271D80
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00271B10 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { int a; void* snd; } B5cObj;
extern void cAnimator_AnimateTo(void* s, float v);
extern void cAnimator_NextFrame(void* s, float v);
void cHudLoading_SetProgress(B5cObj* o, float x) {
    if (x < 0.0f) x = 0.0f;
    if (x > 1.0f) x = 1.0f;
    if (o->snd) {
        cAnimator_AnimateTo(o->snd, 10.0f + 7.0f * x);
        cAnimator_NextFrame(o->snd, 7.0f);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00271B10 */

/* merge_units: begin func_00271BA0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose01_types.h"

extern char g_Video[];
extern int D_00538C60;
extern int cInterface_Render(int*);
extern int cInterface_NextFrame(int*, float);

int cHudLoading_NextFrame(HandleHolder* self, float f) {
    return cInterface_NextFrame(self->handle, f);
}

/* Resets the current slot record (index D_00538C60) and calls cInterface_Render on the handle. */
int cHudLoading_Render(HandleHolder* self) {
    Slot110View* slot = (Slot110View*)(g_Video + D_00538C60 * 272);

    slot->unk2E0 = 0;
    slot->unk2E8 = 100.0f;
    slot->unk2F6 = 1;
    slot->unk2F4 = 1;
    return cInterface_Render(self->handle);
}
#pragma pop /* merge_units */
/* merge_units: end func_00271BA0 */

/* merge_units: begin func_00271BF0 */
#pragma push /* merge_units */
typedef struct { char pad[0x24]; void* a; void* c; char pad2[0xC]; void* b; } Obj271B;
extern void cInterfaceElement_Activate(void* p, int v);
void cHudLoading_ActivatePressX(Obj271B* s, int v) {
    if (s->a) cInterfaceElement_Activate(s->a, v);
    if (s->b) cInterfaceElement_Activate(s->b, v);
    if (s->c) cInterfaceElement_Activate(s->c, 0);
}
#pragma pop /* merge_units */
/* merge_units: end func_00271BF0 */

/* merge_units: begin func_00271C60 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void cInterfaceElement_Activate(int, int);
#endif /* merge_units */
#define cInterfaceElement_Activate(a0, a1) (cInterfaceElement_Activate((void *)(a0), (a1))) /* merge_units */


void cHudLoading_ActivateHost(int a0) {
    int a1, s0;
    int cond;

    s0 = a0;
    a0 = *(int*)((char*)a0 + 40);
    cond = a0 == 0;
    if (cond) goto L00271C88;
    cInterfaceElement_Activate(a0, a1);
L00271C88:;
    a0 = *(int*)((char*)s0 + 36);
    cond = a0 == 0;
    a1 = 0;
    if (cond) goto L00271CA0;
    cInterfaceElement_Activate(a0, a1);
L00271CA0:;
    a0 = *(int*)((char*)s0 + 56);
    cond = a0 == 0;
    a1 = 0;
    if (cond) goto L00271CB8;
    cInterfaceElement_Activate(a0, a1);
L00271CB8:;
    goto ret;
ret:;
}
#undef cInterfaceElement_Activate /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00271C60 */

/* merge_units: begin func_00271CD0 */
#pragma push /* merge_units */
extern void DestroyElement(int);
extern int cInterfaceModel_Activate(int, int, int);

/* Releases all 14 slots, then calls cInterfaceModel_Activate on the owner's handle. */
int cHudLoading_Deactivate(SlotTable14* self) {
    DestroyElement(self->slots[0]);
    DestroyElement(self->slots[1]);
    DestroyElement(self->slots[2]);
    DestroyElement(self->slots[3]);
    DestroyElement(self->slots[4]);
    DestroyElement(self->slots[5]);
    DestroyElement(self->slots[6]);
    DestroyElement(self->slots[7]);
    DestroyElement(self->slots[8]);
    DestroyElement(self->slots[9]);
    DestroyElement(self->slots[10]);
    DestroyElement(self->slots[11]);
    DestroyElement(self->slots[12]);
    DestroyElement(self->slots[13]);
    return cInterfaceModel_Activate(*self->handle, 0, 1);
}
#pragma pop /* merge_units */
/* merge_units: end func_00271CD0 */

/* merge_units: begin func_00271D80 */
#pragma push /* merge_units */
typedef struct Hud271D80 {
    int* ctx;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
    int f18;
    int f1C;
    int f20;
    int f24;
    int f28;
    int f2C;
    int f30;
    int f34;
    int f38;
} Hud271D80;

#if 0 /* merge_units */
extern void cInterfaceModel_Activate(int obj, int a, int b);
#endif /* merge_units */
#define cInterfaceModel_Activate(a0, a1, a2) ((void)cInterfaceModel_Activate((a0), (a1), (a2))) /* merge_units */

extern int cInterfaceModel_GetChild(int obj, char* name);
extern int nHud_CreateHudElement(int obj, char* name);
extern void cAnimator_StartAnimation(int s, float lo, float hi, unsigned char fl);
#if 0 /* merge_units */
extern void cInterfaceElement_Activate(int o, int on);
#endif /* merge_units */
#define cInterfaceElement_Activate(a0, a1) (cInterfaceElement_Activate((void *)(a0), (a1))) /* merge_units */

extern char* nGlobalization_GetString_charP(char* key);
extern int CreateTextElement(int obj, char* name, char* text);
extern char g_LevelDirName[];

void cHudLoading_Activate(Hud271D80* self) {
    int ctx = *self->ctx;
    int panel;
    char* t;

    cInterfaceModel_Activate(ctx, 1, 1);
    panel = cInterfaceModel_GetChild(*self->ctx, "background_panels_group");
    if (panel) {
        self->fC = nHud_CreateHudElement(panel, "filmstrip");
        if (self->fC) cAnimator_StartAnimation(self->fC, 0.0f, 300.0f, 0);
        self->f14 = nHud_CreateHudElement(panel, "dotsbottom");
        if (self->f14) cAnimator_StartAnimation(self->f14, 0.0f, 60.0f, 0);
        /* retail "bar" sits 8-aligned with padding: the embedded NUL makes it a 5-byte literal */
        self->f10 = nHud_CreateHudElement(panel, "bar\0");
        if (self->f10) cAnimator_StartAnimation(self->f10, 0.0f, 60.0f, 0);
        self->f8 = nHud_CreateHudElement(panel, "background_text");
        if (self->f8) cAnimator_StartAnimation(self->f8, 0.0f, 60.0f, 0);
    }
    self->f24 = nHud_CreateHudElement(ctx, "pressx");
    if (self->f24) cInterfaceElement_Activate(self->f24, 0);
    t = nGlobalization_GetString_charP("Continue");
    if (t) self->f38 = CreateTextElement(ctx, "loading_data_text", t);
    if (self->f38) cInterfaceElement_Activate(self->f38, 0);
    self->f28 = nHud_CreateHudElement(ctx, "host");
    if (self->f28) cInterfaceElement_Activate(self->f28, 0);
    self->f18 = nHud_CreateHudElement(ctx, "whiteflash");
    if (self->f18) cAnimator_StartAnimation(self->f18, 0.0f, 17.0f, 0);
    self->f1C = nHud_CreateHudElement(ctx, "backgroundmap1");
    if (self->f1C) cAnimator_StartAnimation(self->f1C, 0.0f, 300.0f, 0);
    self->f20 = nHud_CreateHudElement(ctx, "backgroundmap2");
    if (self->f20) cAnimator_StartAnimation(self->f20, 0.0f, 300.0f, 0);
    t = nGlobalization_GetString_charP("level_techname1");
    if (!t) t = nGlobalization_GetString_charP("level_name");
    self->f30 = CreateTextElement(ctx, "levelname1", t ? t : g_LevelDirName);
    t = nGlobalization_GetString_charP("level_techname2");
    if (t) self->f34 = CreateTextElement(ctx, "levelname2", t);
    t = nGlobalization_GetString_charP("level_briefing");
    if (t) self->f2C = CreateTextElement(ctx, "briefing", t);
}
#undef cInterfaceModel_Activate /* merge_units */
#undef cInterfaceElement_Activate /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00271D80 */
