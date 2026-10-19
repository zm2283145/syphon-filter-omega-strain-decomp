/*
 * main/hud_loading: 6 files, 00271B10-00271D80
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00271B10 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { int a; void* snd; } B5cObj;
extern void IeElement_Fade(void* s, float v);
extern void IeElement_UpdateAnimation(void* s, float v);
void LoadingScreen_SetProgress(B5cObj* o, float x) {
    if (x < 0.0f) x = 0.0f;
    if (x > 1.0f) x = 1.0f;
    if (o->snd) {
        IeElement_Fade(o->snd, 10.0f + 7.0f * x);
        IeElement_UpdateAnimation(o->snd, 7.0f);
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
extern int IeScreen_Draw(int*);
extern int IeScreen_Update(int*, float);

int HudLoading_Update(HandleHolder* self, float f) {
    return IeScreen_Update(self->handle, f);
}

/* Resets the current slot record (index D_00538C60) and calls IeScreen_Draw on the handle. */
int LoadingScreen_Draw(HandleHolder* self) {
    Slot110View* slot = (Slot110View*)(g_Video + D_00538C60 * 272);

    slot->unk2E0 = 0;
    slot->unk2E8 = 100.0f;
    slot->unk2F6 = 1;
    slot->unk2F4 = 1;
    return IeScreen_Draw(self->handle);
}
#pragma pop /* merge_units */
/* merge_units: end func_00271BA0 */

/* merge_units: begin func_00271BF0 */
#pragma push /* merge_units */
typedef struct { char pad[0x24]; void* a; void* c; char pad2[0xC]; void* b; } Obj271B;
extern void IeElement_SetShown(void* p, int v);
void LoadingScreen_DrawHostText(Obj271B* s, int v) {
    if (s->a) IeElement_SetShown(s->a, v);
    if (s->b) IeElement_SetShown(s->b, v);
    if (s->c) IeElement_SetShown(s->c, 0);
}
#pragma pop /* merge_units */
/* merge_units: end func_00271BF0 */

/* merge_units: begin func_00271C60 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void IeElement_SetShown(int, int);
#endif /* merge_units */
#define IeElement_SetShown(a0, a1) (IeElement_SetShown((void *)(a0), (a1))) /* merge_units */


void LoadingScreen_DrawPressX(int a0) {
    int a1, s0;
    int cond;

    s0 = a0;
    a0 = *(int*)((char*)a0 + 40);
    cond = a0 == 0;
    if (cond) goto L00271C88;
    IeElement_SetShown(a0, a1);
L00271C88:;
    a0 = *(int*)((char*)s0 + 36);
    cond = a0 == 0;
    a1 = 0;
    if (cond) goto L00271CA0;
    IeElement_SetShown(a0, a1);
L00271CA0:;
    a0 = *(int*)((char*)s0 + 56);
    cond = a0 == 0;
    a1 = 0;
    if (cond) goto L00271CB8;
    IeElement_SetShown(a0, a1);
L00271CB8:;
    goto ret;
ret:;
}
#undef IeElement_SetShown /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00271C60 */

/* merge_units: begin func_00271CD0 */
#pragma push /* merge_units */
extern void IeScreen_RemoveElementIfSet(int);
extern int IeNode_SetShown(int, int, int);

/* Releases all 14 slots, then calls IeNode_SetShown on the owner's handle. */
int LoadingScreen_Release(SlotTable14* self) {
    IeScreen_RemoveElementIfSet(self->slots[0]);
    IeScreen_RemoveElementIfSet(self->slots[1]);
    IeScreen_RemoveElementIfSet(self->slots[2]);
    IeScreen_RemoveElementIfSet(self->slots[3]);
    IeScreen_RemoveElementIfSet(self->slots[4]);
    IeScreen_RemoveElementIfSet(self->slots[5]);
    IeScreen_RemoveElementIfSet(self->slots[6]);
    IeScreen_RemoveElementIfSet(self->slots[7]);
    IeScreen_RemoveElementIfSet(self->slots[8]);
    IeScreen_RemoveElementIfSet(self->slots[9]);
    IeScreen_RemoveElementIfSet(self->slots[10]);
    IeScreen_RemoveElementIfSet(self->slots[11]);
    IeScreen_RemoveElementIfSet(self->slots[12]);
    IeScreen_RemoveElementIfSet(self->slots[13]);
    return IeNode_SetShown(*self->handle, 0, 1);
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
extern void IeNode_SetShown(int obj, int a, int b);
#endif /* merge_units */
#define IeNode_SetShown(a0, a1, a2) ((void)IeNode_SetShown((a0), (a1), (a2))) /* merge_units */

extern int IeNode_FindChild(int obj, char* name);
extern int Hud_FindOrCreateElement(int obj, char* name);
extern void IeElement_PlayRange(int s, float lo, float hi, unsigned char fl);
#if 0 /* merge_units */
extern void IeElement_SetShown(int o, int on);
#endif /* merge_units */
#define IeElement_SetShown(a0, a1) (IeElement_SetShown((void *)(a0), (a1))) /* merge_units */

extern char* Loc_LookupText(char* key);
extern int LoadingScreen_SetText(int obj, char* name, char* text);
extern char g_LevelDirName[];

void LoadingScreen_Setup(Hud271D80* self) {
    int ctx = *self->ctx;
    int panel;
    char* t;

    IeNode_SetShown(ctx, 1, 1);
    panel = IeNode_FindChild(*self->ctx, "background_panels_group");
    if (panel) {
        self->fC = Hud_FindOrCreateElement(panel, "filmstrip");
        if (self->fC) IeElement_PlayRange(self->fC, 0.0f, 300.0f, 0);
        self->f14 = Hud_FindOrCreateElement(panel, "dotsbottom");
        if (self->f14) IeElement_PlayRange(self->f14, 0.0f, 60.0f, 0);
        /* retail "bar" sits 8-aligned with padding: the embedded NUL makes it a 5-byte literal */
        self->f10 = Hud_FindOrCreateElement(panel, "bar\0");
        if (self->f10) IeElement_PlayRange(self->f10, 0.0f, 60.0f, 0);
        self->f8 = Hud_FindOrCreateElement(panel, "background_text");
        if (self->f8) IeElement_PlayRange(self->f8, 0.0f, 60.0f, 0);
    }
    self->f24 = Hud_FindOrCreateElement(ctx, "pressx");
    if (self->f24) IeElement_SetShown(self->f24, 0);
    t = Loc_LookupText("Continue");
    if (t) self->f38 = LoadingScreen_SetText(ctx, "loading_data_text", t);
    if (self->f38) IeElement_SetShown(self->f38, 0);
    self->f28 = Hud_FindOrCreateElement(ctx, "host");
    if (self->f28) IeElement_SetShown(self->f28, 0);
    self->f18 = Hud_FindOrCreateElement(ctx, "whiteflash");
    if (self->f18) IeElement_PlayRange(self->f18, 0.0f, 17.0f, 0);
    self->f1C = Hud_FindOrCreateElement(ctx, "backgroundmap1");
    if (self->f1C) IeElement_PlayRange(self->f1C, 0.0f, 300.0f, 0);
    self->f20 = Hud_FindOrCreateElement(ctx, "backgroundmap2");
    if (self->f20) IeElement_PlayRange(self->f20, 0.0f, 300.0f, 0);
    t = Loc_LookupText("level_techname1");
    if (!t) t = Loc_LookupText("level_name");
    self->f30 = LoadingScreen_SetText(ctx, "levelname1", t ? t : g_LevelDirName);
    t = Loc_LookupText("level_techname2");
    if (t) self->f34 = LoadingScreen_SetText(ctx, "levelname2", t);
    t = Loc_LookupText("level_briefing");
    if (t) self->f2C = LoadingScreen_SetText(ctx, "briefing", t);
}
#undef IeNode_SetShown /* merge_units */
#undef IeElement_SetShown /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00271D80 */
