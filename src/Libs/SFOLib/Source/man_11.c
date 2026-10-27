/*
 * Libs/SFOLib/Source/man: 5 files, 0038C7D0-0038CBF0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0038C7D0 */
#pragma push /* merge_units */
#include "types.h"

typedef struct { char pad[0x40C]; unsigned char type; } EquipItem;
typedef struct { char pad[0x2410]; EquipItem* slots[8]; } EquipState;
extern void cMan_UpdateHandMorphs(EquipState* e, int slot, EquipItem* it);
void cMan_AddGun(EquipState* e, int slot, EquipItem* it) {
    if (it) {
        int t = it->type;
        if (t < 0 || t >= 8) return;
    }
    e->slots[slot] = it;
    cMan_UpdateHandMorphs(e, slot, it);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0038C7D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0038C7D0 */

/* merge_units: begin func_0038C820 */
#pragma push /* merge_units */
#pragma cplusplus on

struct Pair38C820 {
    __int128 a;
    __int128 b;
};

struct Self38C820 {
    char pad[0x80];
    Pair38C820 pairs[(0x2340 - 0x80) / 0x20];
    void* x2340[0x20];
    unsigned short x23C0;
};

extern "C" {
extern char g_AgentPartCache[];
int FindTex__7MonsterF1(char* cache, __int128 name);
void Monster_FreeTexture(char* cache, int slot);
int FindPart__7MonsterF1(char* cache, __int128 name);
void Monster_FreePart(char* cache, int slot);
void DELAY_DELETE_ARRAY(void* p);
}

extern "C" void cMan_FreeMan(Self38C820* self)
{
    int i;
    for (i = 0; i < self->x23C0; i++) {
        int s = FindPart__7MonsterF1(g_AgentPartCache, self->pairs[i].a);
        if (s != -1) {
            Monster_FreePart(g_AgentPartCache, s);
        }
        if (self->x2340[i]) {
            DELAY_DELETE_ARRAY(self->x2340[i]);
            self->x2340[i] = 0;
        }
    }
    for (i = 0; i < self->x23C0; i++) {
        int s = FindTex__7MonsterF1(g_AgentPartCache, self->pairs[i].b);
        if (s != -1) {
            Monster_FreeTexture(g_AgentPartCache, s);
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0038C820(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0038C820 */

/* merge_units: begin func_0038C920 */
#pragma push /* merge_units */
typedef struct {
    int id;
    unsigned short flags;
    unsigned char a;
    unsigned char b;
    int x;
    int y;
} PartRec;

typedef struct {
    __int128 a;
    __int128 b;
} NamePair;

typedef struct {
    char pad0[0x40];
    char appearance[0x10];
    __int128 name;                  /* 0x50 */
    char pad60[0x20];
    NamePair pairs[(0x1EC0 - 0x80) / 0x20];
    PartRec recs[2][32];            /* 0x1EC0 */
    short h22C0[0x40];              /* 0x22C0 */
    void* x2340[0x20];              /* 0x2340 */
    unsigned short nPairs;          /* 0x23C0 */
    char pad23C2[0x16];
    int x23D8;
    int x23DC;
    char pad23E0[8];
    int x23E8;
    int x23EC;
    float scale;                    /* 0x23F0 */
    char pad23F4[0x2BC0 - 0x23F4];
    unsigned char b2BC0;
    char pad2BC1;
    unsigned char shape;            /* 0x2BC2 */
    char pad2BC3[0x15];
    short h2BD8;
    unsigned char b2BDA;
    unsigned char b2BDB;
    char pad2BDC[0x30];
    unsigned char bodyKind;         /* 0x2C0C */
    char pad2C0D;
    signed char mouth;              /* 0x2C0E */
    signed char stra;               /* 0x2C0F */
} ActorModel;

typedef struct {
    char pad[0x5C10];
    PartRec recs[1][2];
} PartCache;

#if 0 /* merge_units */
extern PartCache g_AgentPartCache;
#endif /* merge_units */
#define g_AgentPartCache (*(PartCache*)&g_AgentPartCache) /* merge_units */

extern int D_005712F0[];
extern __int128* D_005712F8[];
extern char D_004BC318[], D_004BC328[], D_004BC330[];
#if 0 /* merge_units */
extern int FindPart__7MonsterF1(PartCache* cache, __int128 name);
#endif /* merge_units */
#define FindPart__7MonsterF1(a0, a1) (FindPart__7MonsterF1((char *)(a0), (a1))) /* merge_units */

extern void Parts_PartInit(PartRec* r, int a, int b, int c, int d);
extern int SKL_FindSex(void* a);
extern void cMan_ChangeGunPlacement(ActorModel* m, int a, int b);
extern int strcmp(const char* a, const char* b);
extern int SKL_FindPartIndex(void* a, const char* t);

static inline int Eq(__int128 a, __int128 b) {
    __int128 t;
    long long r;
    asm {
        pceqw t, a, b
        ppach r, t, t
    }
    return r == -1;
}

/* Model setup after the part list is filled: resolve each part pair in the agent part cache
 * (copy its two records or reset them), count pairs, body kind, equipment reset, look up
 * the shape index of the model name in the per-body-kind table, STRA_/MOUT_ pairs. */
void cMan_BuildMan(ActorModel* m)
{
    __int128* tbl;
    int n;
    int cnt;
    unsigned int k;
    m->b2BDB = 1;
    for (n = 0; m->pairs[n].a; n++) {
        int slot;
        if (m->h22C0[n] == -1) m->h22C0[n] = 0;
        slot = FindPart__7MonsterF1(&g_AgentPartCache, m->pairs[n].a);
        if (slot == -1) {
            Parts_PartInit(&m->recs[0][n], 0, 0, 0, 0);
            Parts_PartInit(&m->recs[1][n], 0, 0, 1, 0);
        } else {
            int j;
            for (j = 0; j < 2; j++) {
                m->recs[j][n].id = g_AgentPartCache.recs[slot][j].id;
                m->recs[j][n].flags = g_AgentPartCache.recs[slot][j].flags;
                m->recs[j][n].a = g_AgentPartCache.recs[slot][j].a;
                m->recs[j][n].b = g_AgentPartCache.recs[slot][j].b;
                m->recs[j][n].x = g_AgentPartCache.recs[slot][j].x;
                m->recs[j][n].y = g_AgentPartCache.recs[slot][j].y;
            }
        }
    }
    m->nPairs = n;
    m->bodyKind = SKL_FindSex(m->appearance);
    for (n = 0; n < m->nPairs; n++) m->x2340[n] = 0;
    m->x23D8 = 0;
    m->x23DC = 0;
    m->x23E8 = 0;
    m->x23EC = 0;
    cMan_ChangeGunPlacement(m, 0, 0);
    m->h2BD8 = 255;
    m->b2BDA = 2;
    m->b2BC0 = 1;
    cnt = D_005712F0[m->bodyKind];
    tbl = D_005712F8[m->bodyKind];
    for (k = 0; k < cnt; k++) {
        if (Eq(tbl[k], m->name)) break;
    }
    if (k == cnt) {
        m->b2BC0 = 0;
        k = 0;
    }
    if (strcmp((char*)&m->name, D_004BC318) == 0) m->b2BC0 = 0;
    m->shape = k;
    m->scale = 1.0f;
    m->stra = SKL_FindPartIndex(m->appearance, D_004BC328);
    m->mouth = SKL_FindPartIndex(m->appearance, D_004BC330);
    if (m->mouth != -1) {
        m->recs[1][m->mouth].id = 0;
        m->recs[1][m->mouth].flags = 0;
    }
}
#undef g_AgentPartCache /* merge_units */
#undef FindPart__7MonsterF1 /* merge_units */
static inline void merge_flush_func_0038C920(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0038C920 */

/* merge_units: begin func_0038CBF0 */
#pragma push /* merge_units */
/* library prototypes shared by the blocks below (C linkage) */
int sprintf(void *, const void *, ...);

typedef struct {
    char pad0[0x2340];
    void* items[32];
    unsigned short count;
    char pad23c2[0x2C08 - 0x23C2];
    int x2c08;
    char pad2c0c[0x2D96 - 0x2C0C];
    short x2d96;
} F38CBF0;
#if 0 /* merge_units */
extern void DELAY_DELETE_ARRAY(void*);
#endif /* merge_units */
#define DELAY_DELETE_ARRAY(a0) (DELAY_DELETE_ARRAY((a0))) /* merge_units */

void cMan_UnDead(F38CBF0* p)
{
    int i;
    p->x2c08 = 0;
    p->x2d96 = 0;
    for (i = 0; i < p->count; i++) {
        if (p->items[i]) {
            DELAY_DELETE_ARRAY(p->items[i]);
            p->items[i] = 0;
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0038CBF0(void) {}
#undef DELAY_DELETE_ARRAY /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0038CBF0 */

/* merge_units: begin func_0038CC70 */
#pragma push /* merge_units */
#include "fileman_entry.h"
extern void* cFileMan_EncodeFilename_charP_cFileIOP_bool(void* entry, const char* name, int a, int b);
extern int GetFileStreamMan(void);
extern int cFileStreamMan_StreamRequestFlush_cFileManR_eStreamMode(int mgr, void* entry, int flag);
extern void cTexMan_RemoveTexture(int mgr, int handle, int flags);
extern int g_TextureMgr;
typedef struct {
    char name[0x3C0];
    short cur[8];
    short prev[8];
    char pad3E0[0x40C - 0x3E0];
    unsigned char count;
    char pad40D[0x417 - 0x40D];
    signed char state;
    unsigned char dirty;
} Cc70Obj;
void ActorModel_Release(Cc70Obj* self)
{
    if (self->dirty) {
        FileManEntry e;
        char path[0x100];
        cFileMan_ctor_void(&e);
        sprintf(path, "%s.HOG", self);
        cFileMan_EncodeFilename_charP_cFileIOP_bool(&e, path, 0, 0);
        cFileStreamMan_StreamRequestFlush_cFileManR_eStreamMode(GetFileStreamMan(), &e, 1);
        self->dirty = 0;
        cFileMan_dtor(&e, -1);
    }
    if (self->state < 0) {
        self->state = -2;
    } else {
        int mgr = g_TextureMgr;
        int i;
        for (i = 0; i < self->count; i++) {
            if (self->cur[i] != self->prev[i]) cTexMan_RemoveTexture(mgr, self->prev[i], 0);
            cTexMan_RemoveTexture(mgr, self->cur[i], 0);
        }
        self->state = -3;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0038CC70(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0038CC70 */
