/*
 * SFOGame/Source/GuiAgentCreate: 2 files, 0028C390-0028CA70
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0028C390 */
#pragma push /* merge_units */
#include "types.h"

typedef struct { __int128 a; __int128 b; } Ent_C390;
typedef struct {
    char pad0[0x40];
    char app[0x40];             /* +0x40 */
    Ent_C390 e[0xF2];           /* +0x80 */
    char x1EC0[0x500];          /* +0x1EC0 */
    unsigned short count;       /* +0x23C0 */
    char pad23C2[0x23F0 - 0x23C2];
    float f23F0;                /* +0x23F0 */
    int i23F4;                  /* +0x23F4 */
    char pad23F8[0x2C0C - 0x23F8];
    char body;                  /* +0x2C0C */
    char tone;                  /* +0x2C0D */
    char pad2C0E[2];
    signed char preset;         /* +0x2C10 */
} Skel_C390;
typedef struct { char pad[0x60]; Skel_C390 skel; } Tbl_C390;
typedef struct { char pad[0x14]; unsigned short flags; } W_C390;
typedef struct { unsigned char mode; signed char slot; short pos; } Tab_C390;
typedef union { __int128 q; char s[16]; } Key_C390;
typedef struct {
    char pad0[0x58];
    W_C390* w58;            /* +0x58 */
    W_C390* w5C;            /* +0x5C */
    Tbl_C390* tblA;         /* +0x60 */
    Tbl_C390* tblB;         /* +0x64 */
    char pad68[8];
    Tbl_C390* tbl;          /* +0x70 */
    char pad74[0xC4 - 0x74];
    int count;              /* +0xC4 */
    int pos;                /* +0xC8 */
    char padCC[8];
    int toggle;             /* +0xD4 */
    int row;                /* +0xD8 */
    int tone;               /* +0xDC */
    int vE0;                /* +0xE0 */
    int vE4;                /* +0xE4 */
    int vE8;                /* +0xE8 */
    char idx;               /* +0xEC */
    signed char slot;       /* +0xED */
    signed char mode;       /* +0xEE */
    signed char cur;        /* +0xEF */
} S_C390;

extern char g_AgentPartCache[];
extern char D_004A9A28[];
extern char D_004A9A30[];
extern char D_004A9A38[];
extern __int128* D_0048B460;
extern Tab_C390 D_0048B500[][11];
extern unsigned int D_00571300;

extern int SKL_FindSex(void* a);
extern signed char SKL_FindRace(void* a);
extern void Libc_Strcpy(char* dst, const char* src);
extern void cMan_SetBoneSet(Skel_C390* s, int preset);
extern int sprintf(char* buf, const char* fmt, ...);
extern void* Gui_Canvas(void);
extern void GuiTextWidget_SetText(W_C390* w, char* text, int flags);
extern void GuiWidget_SendMessage(S_C390* o, void* w, int kind, int v, int f);
extern void GuiAgentCreate_UpdateClones(S_C390* o, int dir, int b);
extern int Monster_FindNextPart(void* db, int dir, __int128 key, int cur, int slot, int body, int tone, void* app, void* x);
extern int Monster_FindNextSamePart(void* db, int dir, __int128 key, int cur, int slot, int body, int tone, void* app, void* x);
extern int FindNextTexture__7MonsterFi11UiUiUiUiR3SKLR8ManParts(void* db, int dir, __int128 a, __int128 b, unsigned int cur, int slot, unsigned int body, unsigned int tone, void* app, void* x);
extern int AgentPacking_StepTexture(void* db, int dir, __int128 a, __int128 b, unsigned int cur, int slot, unsigned int body, int tone, void* app, void* x);
extern int FindTextureNumber__7MonsterF1(void* db, __int128 key);
extern int FindPartNumber__7MonsterF1(void* db, __int128 key);
extern int cMan_NextFaceShape(Skel_C390* s, int dir, int idx, int body);

static inline int kc390eq(__int128 m, __int128 a, __int128 b) {
    __int128 r;
    asm {
        pand r, m, a
        pand b, m, b
        pceqw r, r, b
        ppach r, r, r
    }
    return (long)r == -1;
}
static inline __int128 kc390q(__int128 v) { __int128 r; asm { pcpyld r, $zero, v } return r; }

static inline void FindIdx_C390(S_C390* self) {
    __int128 mask = kc390q(0xFFFFFFFF00);
    Key_C390 key;
    int i;
    Libc_Strcpy(key.s, D_004A9A28);
    for (i = 0; i < self->tbl->skel.count; i++) {
        if (kc390eq(mask, key.q, self->tbl->skel.e[i].a)) {
            self->idx = i;
            return;
        }
    }
}

static inline void Slider_C390(S_C390* o, W_C390* w, int kind, int v, int f)
{
    if (w) GuiWidget_SendMessage(o, w, kind, v, f);
}

void GuiAgentCreate_UserInterface(S_C390* self, int back, int fwd)
{
    int dir = 1;
    self->row = SKL_FindSex(self->tbl->skel.app);
    self->tbl->skel.body = self->row;
    self->tone = SKL_FindRace(self->tbl->skel.app);
    self->tbl->skel.tone = self->tone;
    if ((back || fwd) && self->cur < 11 && self->count) {
        Skel_C390* s;
        int old;
        int v;
        char buf[0x10];
        if (back) dir = -1;
        if (self->mode == 0) {
            int r;
            s = &self->tbl->skel;
            r = Monster_FindNextPart(g_AgentPartCache, dir, s->e[self->slot].a, self->vE0, self->slot, self->row, self->tone, s->app, s->x1EC0);
            if (r != -1) {
                self->vE0 = r;
                self->vE4 = FindTextureNumber__7MonsterF1(g_AgentPartCache, self->tbl->skel.e[self->slot].b);
            }
        } else if (self->mode == 7) {
            Skel_C390* s = &self->tbl->skel;
            int r = Monster_FindNextSamePart(g_AgentPartCache, dir, s->e[self->slot].a, self->vE0, self->slot, self->row, self->tone, s->app, s->x1EC0);
            if (r != -1) {
                self->vE0 = r;
                self->vE4 = FindTextureNumber__7MonsterF1(g_AgentPartCache, self->tbl->skel.e[self->slot].b);
            }
        } else if (self->mode == 1 || self->mode == 2) {
            int slot = self->slot;
            int r;
            s = &self->tbl->skel;
            if (slot < self->tbl->skel.count)
                r = FindNextTexture__7MonsterFi11UiUiUiUiR3SKLR8ManParts(g_AgentPartCache, dir, s->e[slot].a, s->e[slot].b, self->vE4, slot, self->row, self->tone, s->app, s->x1EC0);
            else
                r = FindNextTexture__7MonsterFi11UiUiUiUiR3SKLR8ManParts(g_AgentPartCache, dir, *D_0048B460, s->e[slot].b, self->vE4, slot, self->row, self->tone, s->app, s->x1EC0);
            if (r != -1)
                self->vE4 = r;
        } else if (self->mode == 3) {
            GuiAgentCreate_UpdateClones(self, dir, 1);
        } else if (self->mode == 4) {
            self->toggle = ++self->toggle & 1;
            if (self->toggle == 0)
                self->tbl = self->tblA;
            else
                self->tbl = self->tblB;
            if (self->slot >= self->tbl->skel.count)
                self->slot = 0;
            self->tbl->skel.f23F0 = 1.0f;
            self->tbl->skel.i23F4 = 0;
            FindIdx_C390(self);
            cMan_SetBoneSet(&self->tbl->skel, -1);
            self->vE0 = FindPartNumber__7MonsterF1(g_AgentPartCache, self->tbl->skel.e[self->slot].a);
            self->vE4 = FindTextureNumber__7MonsterF1(g_AgentPartCache, self->tbl->skel.e[self->slot].b);
            self->tone = SKL_FindRace(self->tbl->skel.app);
            self->tbl->skel.tone = self->tone;
            self->row = SKL_FindSex(self->tbl->skel.app);
            self->tbl->skel.body = self->row;
        } else if (self->mode == 5) {
            Skel_C390* s = &self->tbl->skel;
            int p = dir + s->preset;
            if (p < 0) p = D_00571300 - 1;
            if ((unsigned int)p >= D_00571300) p = 0;
            cMan_SetBoneSet(s, p);
        } else if (self->mode == 6) {
            self->vE8 = cMan_NextFaceShape(&self->tbl->skel, dir, self->vE8, self->row);
        } else if (self->mode == 8) {
            Skel_C390* s = &self->tbl->skel;
            int r = AgentPacking_StepTexture(g_AgentPartCache, dir, s->e[self->slot].a, s->e[self->slot].b, self->vE4, self->slot, self->row, self->tone, s->app, s->x1EC0);
            if (r != -1)
                self->vE4 = r;
        }
        old = self->pos;
        self->pos += dir;
        if (self->pos < 0) self->pos = self->count - 1;
        if (self->pos >= self->count) self->pos = 0;
        D_0048B500[self->row][self->cur].pos = self->pos;
        v = (int)((100.0f / (float)(self->count - 1)) * (float)self->pos);
        if (self->pos != old)
            GuiWidget_SendMessage(self, Gui_Canvas(), 0x10, 6, 0);
        if (self->w5C) {
            if (self->count) {
                sprintf(buf, D_004A9A30, self->pos + 1, self->count);
                GuiTextWidget_SetText(self->w5C, buf, 0);
            } else {
                GuiTextWidget_SetText(self->w5C, D_004A9A38, 0);
            }
        }
        Slider_C390(self, self->w58, 10, v, 0);
    }
    self->row = SKL_FindSex(self->tbl->skel.app);
    self->tbl->skel.body = self->row;
    self->tone = SKL_FindRace(self->tbl->skel.app);
    self->tbl->skel.tone = self->tone;
}
static inline void merge_flush_func_0028C390(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0028C390 */

/* merge_units: begin func_0028CA70 */
#pragma push /* merge_units */
typedef union { __int128 q; char s[16]; } KeyCA70;
typedef struct { __int128 q; char pad[0x10]; } EntCA70;
typedef struct { char pad[0xE0]; EntCA70 e[(0x2420 - 0xE0) / 0x20]; unsigned short count; } TblCA70;
typedef struct { char pad[0x70]; TblCA70* tbl; char pad74[0xEC - 0x74]; char idx; } ObjCA70;
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
void GuiAgentCreate_findFacePart(ObjCA70* self) {
    __int128 mask = kca70q(0xFFFFFFFF00);
    KeyCA70 key;
    int i;
    Libc_Strcpy(key.s, D_004A9A28);
    
    for (i = 0; i < self->tbl->count; i++) {
        if (kca70eq(mask, key.q, self->tbl->e[i].q)) {
            self->idx = i;
            return;
        }
    }
}
static inline void merge_flush_func_0028CA70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0028CA70 */
