/*
 * SFOGame/Source/GuiAgentModify: 9 files, 00341170-00342890
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00341170 */
#pragma push /* merge_units */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "child_list_iter.h"
#pragma pop

#pragma cplusplus on

/* Clear flag 2 on every other child and hide its renderer. */
extern "C" void GuiAgentModify_MakeChildrenInvisible(void* self, ChildWidget* o);
void GuiAgentModify_MakeChildrenInvisible(void* self, ChildWidget* o)
{
    ChildIter e;
    void* l;
    ChildNode* n;
    if (o == 0) return;
    n = ChildList_Begin(CHILD_LIST(o));
    l = CHILD_LIST(o);
    for (; ChildList_End(&e, l), n != e.p; n = n->next) {
        if (n->obj != o) {
            n->obj->flags &= ~2;
            n->obj->renderer->Hide();
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00341170(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00341170 */

/* merge_units: begin func_00341240 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Set flag 2 on every other child, show its renderer, set flag 4, clear flag 0x80. */
extern "C" void GuiAgentModify_MakeChildrenVisible(void* self, ChildWidget* o);
void GuiAgentModify_MakeChildrenVisible(void* self, ChildWidget* o)
{
    ChildIter e;
    void* l;
    ChildNode* n;
    if (o == 0) return;
    n = ChildList_Begin(CHILD_LIST(o));
    l = CHILD_LIST(o);
    for (; ChildList_End(&e, l), n != e.p; n = n->next) {
        if (n->obj != o) {
            n->obj->flags |= 2;
            n->obj->renderer->Show();
            n->obj->flags |= 4;
            n->obj->flags &= ~0x80;
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00341240(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00341240 */

/* merge_units: begin func_00341330 */
#pragma push /* merge_units */
/* GuiAgentModify_UserInterface: step the selected part option (texture / mesh / colour / patch) back or
 * forward and refresh the slider and counter text; same shape as GuiAgentCreate_UserInterface. */

typedef struct { __int128 a; __int128 b; } Ent_1330;
typedef struct {
    char pad0[0x40];
    char app[0x40];             /* +0x40 */
    Ent_1330 e[0xF2];           /* +0x80 */
    char x1EC0[0x500];          /* +0x1EC0 */
    unsigned short count;       /* +0x23C0 */
    char pad23C2[0x2C0D - 0x23C2];
    signed char tone;           /* +0x2C0D */
} Skel_1330;
typedef struct { char pad[0x60]; Skel_1330 skel; } Tbl_1330;
typedef struct { char pad[0x14]; unsigned short flags; } W_1330;
typedef struct { short pos; char pad[2]; } Tab_1330;
typedef struct {
    char pad0[0x78];
    W_1330* w78;            /* +0x78 */
    W_1330* w7C;            /* +0x7C */
    char pad80[0x8C - 0x80];
    Tbl_1330* tbl;          /* +0x8C */
    char pad90[0xE4 - 0x90];
    int count;              /* +0xE4 */
    int pos;                /* +0xE8 */
    int fEC;                /* +0xEC */
    char padF0[0xF8 - 0xF0];
    int row;                /* +0xF8 */
    int tone;               /* +0xFC */
    int vE0;                /* +0x100 */
    int vE4;                /* +0x104 */
    char pad108[0x10D - 0x108];
    signed char slot;       /* +0x10D */
    signed char mode;       /* +0x10E */
    signed char cur;        /* +0x10F */
    char pad110[0x158 - 0x110];
    unsigned char b158;     /* +0x158 */
} S_1330;

extern char g_AgentPartCache[];
extern char D_004B9F70[];
extern char D_004B9F78[];
extern __int128* D_0048B460;
extern Tab_1330 D_00492A02[];

extern int sprintf(char* buf, const char* fmt, ...);
extern void* Gui_Canvas(void);
extern void GuiTextWidget_SetText(W_1330* w, char* text, int flags);
extern void GuiWidget_SendMessage(S_1330* o, void* w, int kind, int v, int f);
extern void GuiAgentModify_TattooPatchesLockout(S_1330* self);
extern int Monster_FindNextPart(void* db, int dir, __int128 key, int cur, int slot, int body, int tone, void* app, void* x);
extern int Monster_FindNextSamePart(void* db, int dir, __int128 key, int cur, int slot, int body, int tone, void* app, void* x);
extern int FindNextTexture__7MonsterFi11UiUiUiUiR3SKLR8ManParts(void* db, int dir, __int128 a, __int128 b, unsigned int cur, int slot, unsigned int body, unsigned int tone, void* app, void* x);
extern int FindNextAnyTexture__7MonsterFi11UiUiUiUiR3SKLR8ManParts(void* db, int dir, __int128 a, __int128 b, unsigned int cur, int slot, unsigned int body, unsigned int tone, void* app, void* x);
extern int AgentPacking_StepTexture(void* db, int dir, __int128 a, __int128 b, unsigned int cur, int slot, unsigned int body, int tone, void* app, void* x);
extern int FindTextureNumber__7MonsterF1(void* db, __int128 key);

static inline void Slider_1330(S_1330* o, W_1330* w, int kind, int v, int f)
{
    if (w) GuiWidget_SendMessage(o, w, kind, v, f);
}

void GuiAgentModify_UserInterface(S_1330* self, int back, int fwd)
{
    int dir = 1;
    if ((back || fwd) && self->cur < 16 && self->count) {
        int old;
        int v;
        char buf[0x10];
        self->b158 = 1;
        if (back) dir = -1;
        if (self->mode == 3) {
            Skel_1330* s = &self->tbl->skel;
            int r = AgentPacking_StepTexture(g_AgentPartCache, dir, s->e[self->slot].a, s->e[self->slot].b, self->vE4, self->slot, self->row, self->tone, s->app, s->x1EC0);
            if ((dir == 1 && !(self->vE4 < r)) || (dir == -1 && !(r < self->vE4))) {
                int m;
                s = &self->tbl->skel;
                m = Monster_FindNextPart(g_AgentPartCache, dir, s->e[self->slot].a, self->vE0, self->slot, self->row, s->tone, s->app, s->x1EC0);
                if (m != -1) {
                    self->vE0 = m;
                    self->vE4 = -1;
                    {
                        Skel_1330* t = &self->tbl->skel;
                        self->vE4 = AgentPacking_StepTexture(g_AgentPartCache, dir, t->e[self->slot].a, t->e[self->slot].b, self->vE4, self->slot, self->row, self->tone, t->app, t->x1EC0);
                    }
                }
            } else {
                self->vE4 = r;
            }
        } else if (self->mode == 0) {
            Skel_1330* s = &self->tbl->skel;
            int r = Monster_FindNextPart(g_AgentPartCache, dir, s->e[self->slot].a, self->vE0, self->slot, self->row, s->tone, s->app, s->x1EC0);
            if (r != -1) {
                self->vE0 = r;
                self->vE4 = FindTextureNumber__7MonsterF1(g_AgentPartCache, self->tbl->skel.e[self->slot].b);
            }
        } else if (self->mode == 4) {
            Skel_1330* s = &self->tbl->skel;
            int r = Monster_FindNextSamePart(g_AgentPartCache, dir, s->e[self->slot].a, self->vE0, self->slot, self->row, s->tone, s->app, s->x1EC0);
            if (r != -1) {
                self->vE0 = r;
                self->vE4 = FindTextureNumber__7MonsterF1(g_AgentPartCache, self->tbl->skel.e[self->slot].b);
            }
        } else if (self->mode == 1) {
            int slot = self->slot;
            int r;
            Skel_1330* s = &self->tbl->skel;
            if (slot < s->count) {
                if (self->count > 1)
                    r = FindNextTexture__7MonsterFi11UiUiUiUiR3SKLR8ManParts(g_AgentPartCache, dir, s->e[slot].a, s->e[slot].b, self->vE4, slot, self->row, s->tone, s->app, s->x1EC0);
                else
                    r = -1;
            } else {
                r = FindNextTexture__7MonsterFi11UiUiUiUiR3SKLR8ManParts(g_AgentPartCache, dir, *D_0048B460, s->e[slot].b, self->vE4, slot, self->row, s->tone, s->app, s->x1EC0);
            }
            if (r != -1)
                self->vE4 = r;
        } else if (self->mode == 2) {
            int slot = self->slot;
            int r;
            Skel_1330* s = &self->tbl->skel;
            if (slot < s->count) {
                if (self->count > 1)
                    r = FindNextAnyTexture__7MonsterFi11UiUiUiUiR3SKLR8ManParts(g_AgentPartCache, dir, s->e[slot].a, s->e[slot].b, self->vE4, slot, self->row, s->tone, s->app, s->x1EC0);
                else
                    r = -1;
            } else {
                r = FindNextAnyTexture__7MonsterFi11UiUiUiUiR3SKLR8ManParts(g_AgentPartCache, dir, *D_0048B460, s->e[slot].b, self->vE4, slot, self->row, s->tone, s->app, s->x1EC0);
            }
            if (r != -1)
                self->vE4 = r;
        } else if (self->mode == 5) {
            Skel_1330* s = &self->tbl->skel;
            int r = AgentPacking_StepTexture(g_AgentPartCache, dir, s->e[self->slot].a, s->e[self->slot].b, self->vE4, self->slot, self->row, self->tone, s->app, s->x1EC0);
            if (r != -1)
                self->vE4 = r;
        }
        old = self->pos;
        self->pos = old + dir;
        if (self->pos < 0) self->pos = self->count - 1;
        if (self->pos < 0) self->pos = 0;
        if (self->pos >= self->count) self->pos = 0;
        if (self->pos != old)
            GuiWidget_SendMessage(self, Gui_Canvas(), 0x10, 6, 0);
        D_00492A02[self->cur].pos = self->pos;
        v = (int)((100.0f / (float)(self->count - 1)) * (float)self->pos);
        Slider_1330(self, self->w78, 10, v, 0);
        if (self->w7C) {
            if (self->count) {
                sprintf(buf, D_004B9F70, self->pos + 1, self->count);
                GuiTextWidget_SetText(self->w7C, buf, 0);
            } else {
                GuiTextWidget_SetText(self->w7C, D_004B9F78, 0);
            }
        }
        if (self->fEC == 2)
            GuiAgentModify_TattooPatchesLockout(self);
    }
}
static inline void merge_flush_func_00341330(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00341330 */

/* merge_units: begin func_00341980 */
#pragma push /* merge_units */
/* library prototypes shared by the blocks below (C linkage) */
#include "SFOLobby_helpers.h"
void *memcpy();
int strcmp(const void *, const void *);

typedef union { __int128 q; char s[16]; } KeyCA70;
typedef struct { __int128 q; char pad[0x10]; } EntCA70;
typedef struct { char pad[0xE0]; EntCA70 e[(0x2420 - 0xE0) / 0x20]; unsigned short count; } TblCA70;
typedef struct { char pad[0x8C]; TblCA70* tbl; char pad74[0x10C - 0x90]; char idx; } ObjCA70;
extern char D_004B9F80[];
static inline int kca70eq(__int128 m, __int128 a, __int128 b) {
    __int128 r;
    asm {
        pand r, m, a
        pand b, m, b
        pceqw r, r, b
        ppach r, r, r
    }
    return (long)r == -1;
}
static inline __int128 kca70q(__int128 v) { __int128 r; asm { pcpyld r, $zero, v } return r; }
void GuiAgentModify_findFacePart(ObjCA70* self) {
    __int128 mask = kca70q(0xFFFFFFFF00);
    KeyCA70 key;
    int i;
    Libc_Strcpy(key.s, D_004B9F80);
    
    for (i = 0; i < self->tbl->count; i++) {
        if (kca70eq(mask, key.q, self->tbl->e[i].q)) {
            self->idx = i;
            return;
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00341980(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00341980 */

/* merge_units: begin func_00341A30 */
#pragma push /* merge_units */
typedef struct { char name[16]; } P_Name;
typedef struct { float x, y, z, w; } P_Sc;
typedef struct { unsigned int count; P_Name e[24]; P_Sc* sc[1]; } P_Tbl;
typedef struct { char pad0[4]; char bones[0x10]; unsigned char hasMorph; char pad15[3]; char morph[4]; } P_Skl;
typedef struct { char pad0[0xA0]; char name[0x2BC4]; P_Skl* skel; } P_App;
typedef struct { char pad0[0x8C]; P_App* app; } P_Obj;
extern P_Tbl D_00571300;
extern float* cArray_cBoneScale_opIndex(void*, int);
extern void* cArray_cBone_opIndex_int_2(void*, int);
extern void cBone_SetScaleX(void*, float);
extern void cBone_SetScaleY(void*, float);
extern void cBone_SetScaleZ(void*, float);

void GuiAgentModify_NextBoneSet(P_Obj* o) {
    unsigned int preset;
    int i;
    for (preset = 0; preset < D_00571300.count; preset++) {
        if (!strcmp(o->app->name, D_00571300.e[preset].name)) break;
    }
    preset++;
    if (preset >= D_00571300.count) preset = 0;
    memcpy(o->app->name, D_00571300.e[preset].name, 0xF);
    for (i = 0; i < 0x15; i++) {
        P_Skl* k;
        float v;
        v = D_00571300.sc[preset][i].x; k = o->app->skel;
        cArray_cBoneScale_opIndex(k->bones, i)[0] = v;
        if (k->hasMorph) cBone_SetScaleX(cArray_cBone_opIndex_int_2(k->morph, i), v);
        v = D_00571300.sc[preset][i].y; k = o->app->skel;
        cArray_cBoneScale_opIndex(k->bones, i)[1] = v;
        if (k->hasMorph) cBone_SetScaleY(cArray_cBone_opIndex_int_2(k->morph, i), v);
        v = D_00571300.sc[preset][i].z; k = o->app->skel;
        cArray_cBoneScale_opIndex(k->bones, i)[2] = v;
        if (k->hasMorph) cBone_SetScaleZ(cArray_cBone_opIndex_int_2(k->morph, i), v);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00341A30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00341A30 */

/* merge_units: begin func_00341C10 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiAgentModify.cc. Functions are named by address
 * until real names are known.
 */

#include "GuiAgentModify_types.h"

AgentCreateEntry* func_00341C10(AgentCreateEntryVec* v, int i) {
    return v->data + i;
}

Rec12* func_00341C30(Rec12Vec* v, int i) {
    return v->data + i;
}
static inline void merge_flush_func_00341C10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00341C10 */

/* merge_units: begin func_00341C50 */
#pragma push /* merge_units */
typedef struct { char pad[0x14]; unsigned short flags; } W_341C50;
typedef struct { __int128 a; __int128 b; } Ent_341C50;
typedef struct { char pad[0xE0]; Ent_341C50 e[1]; } Tbl_341C50;
typedef struct { unsigned char mode; signed char slot; short pos; } Tab_341C50;
typedef struct {
    char pad0[0x78]; W_341C50* w78; W_341C50* w7C; char pad80[0xC]; Tbl_341C50* items; char pad90[0x50];
    int dirty; int count; int pos; char padEC[0x14]; int v100; int v104; char pad108[5];
    signed char slot; unsigned char mode; signed char cur; signed char prev;
} S_341C50;

char D_00492A40[16][16] = {
    "hairstyle",
    "haircolor",
    "hat",
    "eyewear",
    "beard",
    "makeup",
    "shirt",
    "vest",
    "pants",
    "boots",
    "leftarm",
    "rightarm",
    "back",
    "leftarm2",
    "rightarm2",
    "hat2"
};
extern Tab_341C50 D_00492A00[16];
extern signed char D_00492A01[];
#if 0 /* merge_units */
extern short D_00492A02[];
#endif /* merge_units */
#define D_00492A02 ((short*)&D_00492A02) /* merge_units */

extern char D_004B9F20[];
#if 0 /* merge_units */
extern int strcmp(const char* a, const char* b);
#endif /* merge_units */
#define strcmp(a0, a1) (strcmp((const void *)(a0), (const void *)(a1))) /* merge_units */

extern int FindPartNumber__7MonsterF1(void* db, __int128 key);
extern void GuiAgentModify_CountSelections(S_341C50* o);
#if 0 /* merge_units */
extern void GuiTextWidget_SetText(W_341C50* w, char* text, int flags);
#endif /* merge_units */
#define GuiTextWidget_SetText(a0, a1, a2) (GuiTextWidget_SetText((W_1330 *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern void GuiWidget_SendMessage(S_341C50* o, W_341C50* w, int kind, int v, int f);
#endif /* merge_units */
#define GuiWidget_SendMessage(a0, a1, a2, a3, a4) (GuiWidget_SendMessage((S_1330 *)(a0), (void *)(a1), (a2), (a3), (a4))) /* merge_units */


static inline void Slider_341C50(S_341C50* o, W_341C50* w, int kind, int v, int f)
{
    if (w) GuiWidget_SendMessage(o, w, kind, v, f);
}

void GuiAgentModify_UserInterfaceNextButton(S_341C50* o, char* name)
{
    char buf[0x10];
    int i;
    for (i = 0; i < 16; i++) {
        if (!strcmp(D_00492A40[i], name)) break;
    }
    if (i != o->cur) {
        o->prev = o->cur;
        o->cur = i;
        o->dirty = 1;
        if (i < 16) {
            o->slot = D_00492A01[o->cur * 4];
            if (o->slot == -1) {
                if (o->w78) o->w78->flags &= ~2;
                o->mode = 6;
                return;
            }
            o->mode = D_00492A00[o->cur].mode;
            o->v100 = FindPartNumber__7MonsterF1(g_AgentPartCache, o->items->e[o->slot].a);
            o->v104 = FindTextureNumber__7MonsterF1(g_AgentPartCache, o->items->e[o->slot].b);
            GuiAgentModify_CountSelections(o);
            if (o->count) o->pos = o->pos % o->count;
            else o->pos = 0;
            *(short*)((char*)D_00492A02 + o->cur * 4) = o->pos;
            if (o->w78) o->w78->flags |= 2;
            Slider_341C50(o, o->w78, 10, (int)((100.0f / (float)(o->count - 1)) * (float)o->pos), 0);
            if (o->w7C) {
                if (o->count) {
                    sprintf(buf, D_004B9F70, o->pos + 1, o->count);
                    GuiTextWidget_SetText(o->w7C, buf, 0);
                } else {
                    GuiTextWidget_SetText(o->w7C, D_004B9F78, 0);
                }
            }
        } else {
            o->count = 0;
            o->pos = 0;
            if (o->w78) o->w78->flags &= ~2;
            if (o->w7C) GuiTextWidget_SetText(o->w7C, D_004B9F20, 0);
        }
    }
}
#undef D_00492A02 /* merge_units */
#undef strcmp /* merge_units */
#undef GuiTextWidget_SetText /* merge_units */
#undef GuiWidget_SendMessage /* merge_units */
static inline void merge_flush_func_00341C50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00341C50 */

/* merge_units: begin func_00341F00 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)
#include "vslot_pad.h"

struct M;
extern "C" void cMatrix_Set_ColumnMajorForm(M* m, float, float, float, float, float, float, float, float, float);
extern "C" M* cMatrix_ctor_cMatrixR(M* d, const M* s);
struct V {
    float x, y, z, w;
    V() {}
    V(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    V(const V& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
    V& operator=(const V& o) { void* d = this; __int128 q; const void* s = &o; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct M {
    float m[4][4];
    M() {}
    M(const M* p) { cMatrix_ctor_cMatrixR(this, p); void* xx = this; }
    M(float a, float b, float c, float d, float e, float f, float g, float h, float i) { cMatrix_Set_ColumnMajorForm(this, a, b, c, d, e, f, g, h, i); }
    V& r(int i) { return *(V*)m[i]; }
    M(const M& o) { void* xx = this; __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(this), "r"(&o) : "memory"); }
    M& operator=(const M& o) { void* d = this; __int128 qa; __int128 qb; const void* s = &o; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct TM { M m; };
struct VA : V { VA(float ax, float ay, float az, float aw) { void* xx = this; x = ax; y = ay; z = az; w = aw; } };
struct Place { V q; V p; Place(M& m); };

struct Cam {
    float col[4]; char pad10[0xF0 - 0x10];
    float f2E0, f2E4, f2E8, f2EC, fov;
    unsigned char b2F4, b2F5, b2F6;
};
struct Slot { char pad[0x1F0]; Cam cam; };

class Xf {
public:
    VPAD2(a) virtual void v2(); virtual void SetPos(V* p);
};
struct Obj { char pad[0x50]; Xf* xf; };
struct Coll { char pad[1]; };
struct Root { char pad[0x160]; int x160; };
struct Root2 { char pad[0xB0]; char coll[4]; };
class Mdl {
public:
    VPAD16(a) virtual void Tick(float t); VPAD2(b) virtual void v19(); virtual void Draw();
    char pad4[0x34]; float x38; char pad3c[0x2EC0-0x3C]; Root2 r2EC0;
};
struct Scr { char pad[0x64]; float t; };

struct Self {
    char pad0[0x8C];
    Mdl* mdl;
    Obj* obj;
    char pad94[0xB4 - 0x94];
    float fov;
    float ex, ey, ez;
    float rx, ry, rz;
    float f70, f74, f78;
};
struct Fog { char pad[0x150]; float fogNear, fogFar, zNear, zFar; int ci[4]; float cf[4]; };

extern "C" {
extern char g_Video[];
extern int D_00538C60;
extern int D_00538C64;
extern char D_00538C68;
extern int g_DrawMode;
extern long long D_005392D8;
extern long long D_004BC1B0;
extern float D_00539170[4];
void XLib_ClearZBuffer(char* p);
void XLib_Restore(char* p);
float COS(float);
float SIN(float);
#if 0 /* merge_units */
void cMatrix_Set_ColumnMajorForm(M* m, float, float, float, float, float, float, float, float, float);
#endif /* merge_units */
#define cMatrix_Set_ColumnMajorForm(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9) ((void)cMatrix_Set_ColumnMajorForm((a0), (a1), (a2), (a3), (a4), (a5), (a6), (a7), (a8), (a9))) /* merge_units */

#if 0 /* merge_units */
M* cMatrix_ctor_cMatrixR(M* d, const M* s);
#endif /* merge_units */
#define cMatrix_ctor_cMatrixR(a0, a1) ((M *)cMatrix_ctor_cMatrixR((a0), (a1))) /* merge_units */

M* cMatrix_InvertRotTrans(M* m);
void cMatrix_ctor_void(TM* m);
void cMatrix_SetWithAxisAngle(TM* m, float x, float y, float z, float a);
void cMatrix_Rotate(M* a, TM* b);
Root* RootCollection_FindByKey(void* c, char* key);
void cSkaAnimAnchor_TreeNode_SetTransform_WorldSpace(Root* r, Place* p);
#if 0 /* merge_units */
Scr* Gui_Canvas(void);
#endif /* merge_units */
#define Gui_Canvas() ((Scr *)Gui_Canvas()) /* merge_units */

void cMan_ManNextFrame(void* p, float t);
void cMotionManager_NextFrame(float t);
void GuiAgentModify_ManRender(Self* self); void GuiAgentModify_BlendMenOnOff(Self* self); void XLib_UpdateFogParms(char* r);
}

#define SLOT(i) ((Slot*)(g_Video + (i) * 0x110))
#define STK(i) ((M*)(g_Video + 0xA80 + (i) * 0x40))

static inline void UnitM(M* m) { M* p = m; int t; __asm__ volatile("sqc2 vf0, 0x30(%1); qmfc2.ni %0, vf0; pcpyud %0, %0, zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, zero; sq %0, 0(%1)" : "=&r"(t) : "r"(p) : "memory"); }
static inline void Apply33(V* out, const V* v, const M* m) { __asm__ volatile("lqc2 vf8, 0x0(%2); lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); vmulax.xyz ACC, vf4, vf8x; vmadday.xyz ACC, vf5, vf8y; vmaddz.xyz vf8, vf6, vf8z; sqc2 vf8, 0x0(%0)" : : "r"(out), "r"(m), "r"(v) : "memory"); }
static inline void Mul33(M* out, const M* a, const M* b) { __asm__ volatile("lqc2 vf4, 0x0(%2); lqc2 vf5, 0x10(%2); lqc2 vf6, 0x20(%2); lqc2 vf8, 0x0(%1); lqc2 vf9, 0x10(%1); lqc2 vf10, 0x20(%1); lqc2 vf11, 0x30(%1); vmulax.xyz ACC, vf4, vf8x; vmadday.xyz ACC, vf5, vf8y; vmaddz.xyz vf8, vf6, vf8z; vmulax.xyz ACC, vf4, vf9x; vmadday.xyz ACC, vf5, vf9y; vmaddz.xyz vf9, vf6, vf9z; vmulax.xyz ACC, vf4, vf10x; vmadday.xyz ACC, vf5, vf10y; vmaddz.xyz vf10, vf6, vf10z; vmulax.xyz ACC, vf4, vf11x; vmadday.xyz ACC, vf5, vf11y; vmaddz.xyz vf11, vf6, vf11z; sqc2 vf8, 0x0(%0); sqc2 vf9, 0x10(%0); sqc2 vf10, 0x20(%0); sqc2 vf11, 0x30(%0)" : : "r"(out), "r"(b), "r"(a) : "memory"); }

static inline void MtxToQuat(void* m, void* out) {
    int f;
    int t;
    asm {
        .set noreorder
        lqc2 vf1, 0x0(m)
        lqc2 vf2, 0x10(m)
        lqc2 vf3, 0x20(m)
        vmulax.w ACC, vf0, vf1x
        vmadday.w ACC, vf0, vf2y
        vmaddz.w vf4, vf0, vf3z
        lui f, 0x3F00
        qmtc2.ni f, vf5
        vnop
        vnop
        vnop
        vnop
        cfc2.ni f, vi17
        andi f, f, 0x11
        bnel f, zero, L1
        nop
        vaddw.w vf4, vf4, vf0w
        vsuby.z vf6, vf2, vf3y
        vsubz.x vf7, vf3, vf1z
        vsubx.y vf8, vf1, vf2x
        vsqrt Q, vf4w
        vaddz.x vf9, vf0, vf6z
        vaddx.y vf9, vf0, vf7x
        vaddy.z vf9, vf0, vf8y
        vwaitq
        vmulq.w vf9, vf0, Q
        vdiv Q, vf0w, vf9w
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.xyz vf9, vf9, Q
        j done
        nop
    L1:
        vsubay.x ACC, vf1, vf2y
        vsubaz.y ACC, vf2, vf3z
        vsubax.z ACC, vf3, vf1x
        vmadd.xyz vf10, vf0, vf0
        vnop
        vnop
        vnop
        vnop
        vnop
        cfc2.ni f, vi17
        andi t, f, 0x80
        bnel t, zero, L3
        nop
        andi t, f, 0x20
        bnel t, zero, L4
        nop
    L2:
        vmulaz.w ACC, vf0, vf10z
        vmsubay.w ACC, vf0, vf2y
        vmaddw.w vf4, vf0, vf0w
        vsubx.y vf6, vf1, vf2x
        vaddx.z vf7, vf1, vf3x
        vaddz.y vf8, vf3, vf2z
        vsqrt Q, vf4w
        vmuly.w vf9, vf0, vf6y
        vaddz.x vf9, vf0, vf7z
        vaddy.y vf9, vf0, vf8y
        vwaitq
        vaddq.z vf9, vf0, Q
        vdiv Q, vf0w, vf9z
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.xyw vf9, vf9, Q
        j done
        nop
    L3:
        andi t, f, 0x40
        bnel t, zero, L2
        nop
        vmulay.w ACC, vf0, vf10y
        vmsubax.w ACC, vf0, vf1x
        vmaddw.w vf4, vf0, vf0w
        vaddz.y vf6, vf3, vf2z
        vsubz.x vf7, vf3, vf1z
        vaddy.x vf8, vf2, vf1y
        vsqrt Q, vf4w
        vaddy.z vf9, vf0, vf6y
        vmulx.w vf9, vf0, vf7x
        vaddx.x vf9, vf0, vf8x
        vwaitq
        vaddq.y vf9, vf0, Q
        vdiv Q, vf0w, vf9y
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.xzw vf9, vf9, Q
        j done
        nop
        nop
    L4:
        vmulax.w ACC, vf0, vf10x
        vmsubaz.w ACC, vf0, vf3z
        vmaddw.w vf4, vf0, vf0w
        vaddy.x vf6, vf2, vf1y
        vaddx.z vf7, vf1, vf3x
        vsuby.z vf8, vf2, vf3y
        vsqrt Q, vf4w
        vaddx.y vf9, vf0, vf6x
        vaddz.z vf9, vf0, vf7z
        vmulz.w vf9, vf0, vf8z
        vwaitq
        vaddq.x vf9, vf0, Q
        vdiv Q, vf0w, vf9x
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.yzw vf9, vf9, Q
    done:
        sqc2 vf9, 0x0(out)
        .set reorder
    }
}

static inline M Euler(float ey, float ex, float ez)
{
    float cy = COS(ey);
    float sy = SIN(ey);
    float cx = COS(ex);
    float sx = SIN(ex);
    float cz = COS(ez);
    float sz = SIN(ez);
    float czcy = cz * cy;
    float czsy = cz * sy;
    float szcy = sz * cy;
    float szsy = sz * sy;
    float a1 = czcy - szsy * sx;
    float a2 = -sz * cx;
    float a3 = czsy + szcy * sx;
    float a4 = szcy + czsy * sx;
    float a5 = cz * cx;
    float a6 = szsy - czcy * sx;
    float a7 = -cx * sy;
    float a8 = sx;
    float a9 = cx * cy;
    return M(a1, a2, a3, a4, a5, a6, a7, a8, a9);
}

static inline M Inverse(const M& m) { M t; return M(cMatrix_InvertRotTrans(cMatrix_ctor_cMatrixR(&t, &m))); }

static inline void Rot2(M* m, const V& ax, float a)
{
    TM t;
    cMatrix_ctor_void(&t);
    cMatrix_SetWithAxisAngle(&t, ax.x, ax.y, ax.z, a);
    cMatrix_Rotate(m, &t);
}

inline Place::Place(M& m) { MtxToQuat(&m, &q); p = m.r(3); }
static inline void Rot(M* m, const V& ax, float a) { Rot2(m, ax, a); }
static inline void SetPl(Root* r, const Place& pl) { cSkaAnimAnchor_TreeNode_SetTransform_WorldSpace(r, (Place*)&pl); }


/* cvt.w.s+mfc1 asm: a C (int) cast compiles to a different sequence; the dead r=0 matches retail's daddu */
static inline int F2I(float f) { int r = 0; float t; asm { cvt.w.s t, f; mfc1 r, t } return r; }
static inline float FMul(float a, float b) { return a * b; }
static inline void SetCol(Fog* g, float r, float gg, float b)
{
    r = FMul(r, 256.0f); gg = FMul(gg, 256.0f); b = FMul(b, 256.0f); float a = r, c = gg, d = b;
    g->cf[0] = a;
    g->cf[1] = c;
    g->cf[2] = d;
    g->cf[3] = 256.0f;
    g->ci[0] = F2I(a);
    g->ci[1] = F2I(c);
    g->ci[2] = F2I(d);
    g->ci[3] = 0x80;
}

extern "C" void GuiAgentModify_ManRender(Self* self)
{
    M view;
    M r2;
    V p;
    M cm;
    M mm;
    int saved;
    XLib_ClearZBuffer(g_Video);
    GuiAgentModify_BlendMenOnOff(self);
    saved = g_DrawMode;
    g_DrawMode = 0x95;
    { long long t = D_004BC1B0;
    D_005392D8 = t; }
    *STK(D_00538C64 + 1) = *STK(D_00538C64);
    ((Fog*)g_Video)->fogNear = 0.0f;
    ((Fog*)g_Video)->fogFar = 1.0f;
    D_00538C64++;
    XLib_UpdateFogParms(g_Video);
    ((Fog*)g_Video)->zNear = 50.0f;
    ((Fog*)g_Video)->zFar = 80.0f;
    XLib_UpdateFogParms(g_Video);
    SetCol((Fog*)g_Video, 0.25f, 0.25f, 0.25f);
    {
        Cam* c = &SLOT(D_00538C60)->cam;
        c->fov = self->fov;
        c->f2E4 = 2.0f;
        c->f2EC = 15000.0f;
        c->b2F6 = 1;
        c->b2F4 = 0;
    }
    { float ey = self->f74; float ex = self->f70; float ez = self->f78; r2 = Euler(ey, ex, ez); }
    p = V(self->ex, -self->ey, self->ez, 1.0f);
    Apply33(&p, &p, &r2);
    cm.m[0][0] = r2.m[0][0]; cm.m[0][1] = r2.m[0][1]; cm.m[0][2] = r2.m[0][2];
    cm.m[1][0] = r2.m[1][0]; cm.m[1][1] = r2.m[1][1]; cm.m[1][2] = r2.m[1][2];
    cm.m[2][0] = r2.m[2][0]; cm.m[2][1] = r2.m[2][1]; cm.m[2][2] = r2.m[2][2];
    cm.m[0][3] = r2.m[0][3]; cm.m[1][3] = r2.m[1][3]; cm.m[2][3] = r2.m[2][3];
    cm.r(3) = p;
    view = Inverse(cm);
    *STK(D_00538C64) = view;
    D_00538C68 = 1;
    self->obj->xf->SetPos(&cm.r(3));
    V pp(0.0f, 0.0f, -3.0f, 1.0f);
    UnitM(&mm);
    Rot(&mm, VA(1.0f, 0.0f, 0.0f, 0.0f), self->rx);
    Rot(&mm, V(0.0f, 1.0f, 0.0f, 0.0f), self->ry);
    Rot(&mm, V(0.0f, 0.0f, 1.0f, 0.0f), self->rz);
    mm.r(3) = pp;
    Mul33(&mm, &cm, &mm);
    {
        char key[4];
        bool done = false;
        unsigned int k;
        for (k = 0; k < 4u; k++) {
            char c;
            if (!D_004B9F20[k]) done = true;
            if (done) c = 0; else c = D_004B9F20[k];
            key[k] = c;
        }
        Root2* rr = &self->mdl->r2EC0; Root* r = RootCollection_FindByKey(rr->coll, key);
        SetPl(r, Place(mm));
        r->x160 = 0;
    }    {
        float t = Gui_Canvas()->t;
        self->mdl->Tick(t);
        cMan_ManNextFrame((char*)self->mdl + 0x60, t);
        cMotionManager_NextFrame(t);
        { Mdl* m = self->mdl; m->x38 = 2.0f; }
        self->mdl->Draw();
    }
    XLib_Restore(g_Video);
    {
        Slot* s = SLOT(D_00538C60);
        s->cam.f2E0 = 0;
        s->cam.f2E8 = 1000.0f;
        s->cam.b2F6 = 1;
        s->cam.b2F4 = 1;
        {
            float* v = D_00539170;
            s->cam.col[0] = v[0];
            s->cam.col[1] = v[1];
            s->cam.col[2] = v[2];
            s->cam.col[3] = v[3];
        }
        s->cam.b2F5 = 1;
        s->cam.b2F6 = 1;
    }
    D_00538C68 = 1;
    g_DrawMode = saved;
    D_00538C64--;
}
#undef cMatrix_Set_ColumnMajorForm /* merge_units */
#undef cMatrix_ctor_cMatrixR /* merge_units */
#undef Gui_Canvas /* merge_units */
static inline void merge_flush_func_00341F00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00341F00 */

/* merge_units: begin func_00342890 */
#pragma push /* merge_units */
extern char g_LightMgr[];
extern int cLightMan_BuildVisibleLightSubset(void* p);
extern int GuiWidget_onRender(void* self);

int GuiAgentModify_onRender(void* self) {
    cLightMan_BuildVisibleLightSubset(g_LightMgr);
    return GuiWidget_onRender(self);
}
static inline void merge_flush_func_00342890(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00342890 */
