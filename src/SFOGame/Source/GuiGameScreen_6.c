/*
 * SFOGame/Source/GuiGameScreen: 4 files, 0045C960-0045CE10
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0045C960 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiGameScreen.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"

int cArray_int_Iterator_opNe(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

Iter* func_0045C980(Iter* it) {
    it->p++;
    return it;
}

Word* func_0045C9A0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

int func_0045C9B0(char* self) {
    return *(int*)(self + 0);
}

void cArray_int_End(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

void func_0045C9E0(Iter* out, PtrVec* v) {
    out->p = v->data;
}

Word* func_0045C9F0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_vector_int_end_void_2(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}
static inline void merge_flush_func_0045C960(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0045C960 */

/* merge_units: begin func_0045CA20 */
#pragma push /* merge_units */
/* library prototypes shared by the blocks below (C linkage) */
int sprintf(void *, const void *, ...);

typedef struct { char pad[0x14]; unsigned short flags; } W_45CA20;
typedef struct {
    char pad[0x6C]; W_45CA20* w; char pad70[0x20]; int f90; int f94; int f98; unsigned char f9C;
    char pad9D[3]; void* fA0; void* fA4; char padA8[0x28]; int fD0; int fD4; char padD8[4]; int fDC;
} S_45CA20;
typedef struct { char pad[0x6A8]; unsigned char busy; } G_45CA20;
extern G_45CA20* g_Hud;
extern int D_00497ACC[];
extern int D_00497AEC[];
void GuiGameScreen_BuildWeaponSelectList(S_45CA20* o);
long long cTimer_GetMillisecondTime(void);
void GuiGameScreen_UpdateWeaponPanels(S_45CA20* o);
void GuiWidget_SendMessage(void* a, void* b, int kind, int v, int f);
void* Gui_Canvas(void);
void GuiCanvas_SetFocus(void* mgr, void* w);
static inline float fmin_45CA20(float a, float b) { float r; asm { min.s r, a, b } return r; }

static inline unsigned char Has_45CA20(unsigned short* p, int m) { return (*p & m) != 0; }
static inline void Set_45CA20(unsigned short* p, int m) { *p |= m; }
void GuiGameScreen_ActivateWeaponSelect(S_45CA20* o, int on)
{
    W_45CA20* w = o->w;
    unsigned short* pf;
    if (w == 0) return;
    pf = &w->flags;
    if ((unsigned char)on == Has_45CA20(pf, 4)) return;
    if (on) {
        if (g_Hud->busy) return;
        Set_45CA20(pf, 2);
        o->w->flags |= 4;
        GuiGameScreen_BuildWeaponSelectList(o);
        o->f94 = o->f90;
        o->f98 = cTimer_GetMillisecondTime();
        o->f9C = 0;
        GuiGameScreen_UpdateWeaponPanels(o);
        if (o->fD4 == 0 && o->fD0 == 0) GuiWidget_SendMessage(o, o->fA4, 0xA, D_00497ACC[o->fDC], 0);
        o->fD4 = 1;
        o->fD0 = 2;
        GuiWidget_SendMessage(o, o->fA4, 0xB, D_00497AEC[o->fDC], 0);
        GuiWidget_SendMessage(o, o->fA0, 6, (int)"onWake", 0);
        o->w->flags |= 0x80;
        GuiCanvas_SetFocus(Gui_Canvas(), o->w);
        GuiWidget_SendMessage(o->w, Gui_Canvas(), 0x10, 2, 0);
    } else {
        float v;
        o->fD4 = 0;
        o->fD0 = 2;
        v = 0;
        GuiWidget_SendMessage(o, o->fA4, 9, (int)&v, 0);
        v = fmin_45CA20((float)D_00497AEC[o->fDC], v);
        GuiWidget_SendMessage(o, o->fA4, 0xC, (int)v, D_00497ACC[o->fDC]);
        o->w->flags &= ~4;
        GuiWidget_SendMessage(o, o->fA0, 6, (int)"onSleep", 0);
        o->w->flags &= ~0x80;
        GuiCanvas_SetFocus(Gui_Canvas(), o);
        GuiWidget_SendMessage(o->w, Gui_Canvas(), 0x10, 3, 0);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0045CA20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0045CA20 */

/* merge_units: begin func_0045CC90 */
#pragma push /* merge_units */
typedef struct { float x, y; } Vec2_45CC90;
typedef struct {
    char pad0[0x14];
    unsigned short flags;
    char pad16[0x34 - 0x16];
    Vec2_45CC90 pos;
    Vec2_45CC90 size;
    char pad44[0xA4 - 0x44];
    unsigned char fA4;
} W_45CC90;
typedef struct {
    char pad0[0x6C];
    W_45CC90* root;
    char pad70[0x90 - 0x70];
    int f90;
    int f94;
    int f98;
    unsigned char f9C;
    char pad9D[0xA8 - 0x9D];
    W_45CC90* items[5];
    char padBC[0xD0 - 0xBC];
    int fD0;
    int fD4;
    char fD8[4];
    int fDC;
} S_45CC90;
extern char D_004C2210[];
extern char D_004C2228[];
extern void* g_WeaponDatabase;
extern void* D_00497AC0;
extern W_45CC90* AbstractWidgetClassRep_Create(char*);
extern W_45CC90* GuiWidget_FindChild_charP(W_45CC90*, char*);
extern void GuiWidget_SetPosition(W_45CC90*, float, float);
extern void GuiWidget_AddChild(W_45CC90*, W_45CC90*);
extern void cWeaponDB_LoadGun(void* m, void* a, void* b, int c, int d, int e, int f);

static inline void SetSize(W_45CC90* w, float x, float y)
{
    w->size.x = x;
    w->size.y = y;
}

void GuiGameScreen_InitWeaponSelect(S_45CC90* self)
{
    int i;
    char buf[16];
    if (self->root == 0) {
        return;
    }
    self->f90 = -1;
    self->fDC = 0;
    self->f94 = -1;
    self->f9C = 0;
    self->f98 = 0;
    self->fD0 = 0;
    self->fD4 = 0;
    self->root->flags &= ~2;
    self->root->flags &= ~4;
    for (i = 0; i < 5; i++) {
        W_45CC90* ref;
        Vec2_45CC90 p;
        Vec2_45CC90 s;
        self->items[i] = AbstractWidgetClassRep_Create(D_004C2210);
        sprintf(buf, D_004C2228, i + 1);
        ref = GuiWidget_FindChild_charP(self->root, buf);
        p = ref->pos;
        GuiWidget_SetPosition(self->items[i], p.x, p.y);
        s = ref->size;
        SetSize(self->items[i], s.x, s.y);
        GuiWidget_AddChild(self->root, self->items[i]);
        self->items[i]->fA4 = 0;
    }
    cWeaponDB_LoadGun(g_WeaponDatabase, D_00497AC0, self->fD8, -1, 0, 0, 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0045CC90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0045CC90 */

/* merge_units: begin func_0045CE10 */
#pragma push /* merge_units */
typedef struct SoundRequest {
    char pad000[0x48];
    char partA[0x9C];   /* 0x048 */
    char partB[0xAC];   /* 0x0E4 */
} SoundRequest; /* size 0x190 */
typedef struct SoundMsg {
    void* vtbl;
    char pad004[0x1C];
    unsigned char flag; /* 0x20 */
    char pad021[0x57];
    char partA[0x9C];   /* 0x078 */
    char partB[0xAC];   /* 0x114 */
} SoundMsg; /* size 0x1C0 */
typedef struct { char pad[0x14]; unsigned short flags; char pad16[0x78 - 0x16]; int x78; } Sub_5CE10;
typedef struct { char pad[0x68]; Sub_5CE10* sub; } Scr_5CE10;
extern char g_Game[];
extern char D_004DAE10[];
extern char D_004C21F8[];
extern char* nGlobalization_GetString_charP(char* key);
extern int GuiSubTitleDisplay_AddMessage(Sub_5CE10* d, char* text);
#if 0 /* merge_units */
extern void GuiWidget_SendMessage(Scr_5CE10* w, Sub_5CE10* to, int ev, int name, int x);
#endif /* merge_units */
#define GuiWidget_SendMessage(a0, a1, a2, a3, a4) (GuiWidget_SendMessage((void *)(a0), (void *)(a1), (a2), (a3), (a4))) /* merge_units */

extern void cSndFx_ctor_int_charP_cGOBJP_int(SoundRequest* req, int kind, char* name, int a, int b);
extern void SoundMsg_WrapAction(SoundMsg* msg, SoundRequest* req);
extern void QueueMessage_cMessageR_cSystemP_int(SoundMsg* msg, void* target, int flags);
extern void cFileMan_dtor(void* part, int flags);
extern void cMessage_dtor(SoundMsg* msg, int flags);
void GuiGameScreen_AddXAAudio(Scr_5CE10* self, char* name, int unused, int sound)
{
    char* text;
    if (!name || !*name || !self->sub) {
        self->sub->flags &= ~2;
        return;
    }
    text = nGlobalization_GetString_charP(name);
    if (text && GuiSubTitleDisplay_AddMessage(self->sub, text)) {
        if (!(self->sub->flags & 2)) GuiWidget_SendMessage(self, self->sub, 6, (int)D_004C21F8, 0);
        self->sub->x78 = 4;
        self->sub->flags |= 2;
    }
    if (sound) {
        SoundMsg msg;
        SoundRequest req;
        cSndFx_ctor_int_charP_cGOBJP_int(&req, 4, name, 0, 100);
        SoundMsg_WrapAction(&msg, &req);
        cFileMan_dtor(req.partB, -1);
        cFileMan_dtor(req.partA, -1);
        msg.flag = 1;
        QueueMessage_cMessageR_cSystemP_int(&msg, g_Game, 1);
        msg.vtbl = D_004DAE10;
        cFileMan_dtor(msg.partB, -1);
        cFileMan_dtor(msg.partA, -1);
        cMessage_dtor(&msg, 0);
    }
}
#undef GuiWidget_SendMessage /* merge_units */
static inline void merge_flush_func_0045CE10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0045CE10 */
