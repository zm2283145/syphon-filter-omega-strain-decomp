/*
 * Libs/SFOLib/Source/man: 7 files, 0038C7D0-0038D530
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

/* merge_units: begin func_0038CD90 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef __int128 u_long128;

struct cVector {
    float x, y, z, w;
    cVector() {}
    cVector(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
} __attribute__((aligned(16)));
static inline void QCopy1(void* d, const void* s) { u_long128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory"); }

struct cQuaternion { float x, y, z, w; } __attribute__((aligned(16)));
struct boneOffset { float x, y, z; int parent; };
struct cVector_NoInitHACK { float x, y, z, w; };
struct gunBones {
    cQuaternion orient;
    union U { boneOffset the; cVector_NoInitHACK offset; } u;
};
struct manRefs { unsigned char qwc; unsigned char vertCount; };
struct Parts {
    u_long128* part;
    unsigned short qwc;
    unsigned char type;
    unsigned char patchCount;
    manRefs* Refs;
    unsigned int* blends;
};
struct manAttribs { u_long128 partName; u_long128 texName; };
struct cBox { cVector min; cVector max; };
struct gunList {
    char gunName[32];
    manAttribs gunAttribsTable[8];
    gunBones gunBulletOffset;
    gunBones gunBonesOffsets[12];
    Parts gunParts[2][8];
    short gunTexID[8];
    short gunTexID2[8];
    cBox gunBBox;
    char* gunHog;
    u_long128* casingModelPart;
    unsigned short casingModelqwc;
    short gunWDBIndex;
    unsigned char gunPartCount;
    unsigned char gunHoldType;
    unsigned char gunHoldTypeHand2;
    unsigned char gunAnimType;
    signed char gunHolsterPart;
    signed char gunFlarePart;
    signed char gunLightPart;
    signed char gunStockPartOn;
    signed char gunStockPartOff;
    unsigned char gunGlow;
    signed char gunTransparency;
    signed char gunLoading;
    unsigned char gunMalloc;
    unsigned char gunIsBullet;
    int gunRefCount;
};
struct tHogHeader { unsigned int id; unsigned int numBlocks; unsigned int offsetListOffset; unsigned int nameListOffset; unsigned int bodyOffset; };
struct cHogFile {
    char mHogFname[128];
    char mHogFile[200];
    tHogHeader* mHogHeader;
    char pad14C[0x16C - 0x14C];
};
struct SKL {
    char rawChars[0x40];
    manAttribs manAttribsTable[32];
};
struct cFileMan { char pad[0x9C]; };
struct cTexMan;

extern "C" {
void cHogFile_ctor(cHogFile*);
void cHogFile_dtor(cHogFile*, int);
void cHogFile_Open(cHogFile*, const char*, char*, int);
char* cHogFile_GetBlockName(cHogFile*, int);
char* cHogFile_GetBlock_int(cHogFile*, int);
unsigned int cHogFile_GetBlockSize(cHogFile*, int);
char* strrchr(const char*, int);
#if 0 /* merge_units */
int strcmp(const char*, const char*);
#endif /* merge_units */
#define strcmp(a0, a1) (strcmp((a0), (a1))) /* merge_units */

int Libc_Strncmp(const char*, const char*, int);
void strCpyPad(char*, int, char*);
void SKL_ConvertSKL(SKL*, char*, int);
void Parts_SetGunData(Parts*, char*, int);
#if 0 /* merge_units */
void cFileMan_ctor_void(cFileMan*);
#endif /* merge_units */
#define cFileMan_ctor_void(a0) ((void)cFileMan_ctor_void((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
void cFileMan_dtor(cFileMan*, int);
#endif /* merge_units */
#define cFileMan_dtor(a0, a1) ((void)cFileMan_dtor((void *)(a0), (a1))) /* merge_units */

void cFileMan_EncodeFilename_charP_cHogFileR_bool(cFileMan*, const char*, cHogFile*, int);
short cTexMan_AddTextureFromFile_R_cFileMan(cTexMan*, u_long128, cFileMan*);
short cTexMan_UseMrYuckTexture(cTexMan*);
void gunList_GunCalcBBox(gunList*);
#if 0 /* merge_units */
extern cTexMan* g_TextureMgr;
#endif /* merge_units */
#define g_TextureMgr (*(cTexMan **)&g_TextureMgr) /* merge_units */

extern char D_004BC340[], D_004BC348[], D_004BC350[], D_004BC358[], D_004BC360[], D_004BC368[], D_004BC370[], D_004BC378[], D_004BC380[], D_004BC388[];
}

static inline void QZero(void* d0, int n0) { int n = n0; void* d = d0;
    asm {
        .set noreorder
    lp:
        nop
        addi n, n, -1
        sq $zero, 0(d)
        bgtz n, lp
        addiu d, d, 0x10
        .set reorder
    }
}
static inline void QMove(void* d0, void* s0, int n) { u_long128 t; void* s; void* d; s = s0; d = d0;
    asm {
        .set noreorder
    lp:
        lq t, 0(s)
        addiu d, d, 0x10
        addi n, n, -1
        addiu s, s, 0x10
        bgtz n, lp
        sq t, -0x10(d)
        .set reorder
    }
}
static inline long long QEq(u_long128 a, u_long128 b) {
    u_long128 t;
    long long r;
    asm {
        pceqw t, a, b
        ppach r, t, t
    }
    return r;
}

static inline void BoxInit(cBox* b)
{
    cVector t1(3.4028235e38f, 3.4028235e38f, 3.4028235e38f, 1.0f);
    cVector* mn = &b->min;
    QCopy1(mn, &t1);
    void* xx = &b->max;
    cVector t2(-3.4028235e38f, -3.4028235e38f, -3.4028235e38f, 1.0f);
    QCopy1(&b->max, &t2);
}

extern "C" void gunList_LoadGunHog(gunList* self, char* gunHogData)
{
    cHogFile hog_model;
    u_long128 partNames[16];
    Parts parts[16];
    int partCount;
    int sklFound;
    int bonesFound;
    int blocks;
    char* blockName;
    char* ext;
    int j;
    SKL localSKL;
    int part;
    int found;
    u_long128 fullPartName;
    char* fullPartText;
    cFileMan texFile;

    cHogFile_ctor(&hog_model);
    partCount = 0;
    sklFound = 0;
    self->gunHog = gunHogData;
    self->gunLoading = 0;
    BoxInit(&self->gunBBox);
    QZero(self->gunBonesOffsets, 24);
    cHogFile_Open(&hog_model, D_004BC340, gunHogData, 0);
    blocks = hog_model.mHogHeader->numBlocks;
    for (j = 0; j < blocks; j++) {
        blockName = cHogFile_GetBlockName(&hog_model, j);
        ext = strrchr(blockName, '.');
        if (!ext) ext = blockName;
        if (!strcmp(ext, D_004BC348)) {
            SKL_ConvertSKL(&localSKL, cHogFile_GetBlock_int(&hog_model, j), cHogFile_GetBlockSize(&hog_model, j));
            QMove(self->gunAttribsTable, localSKL.manAttribsTable, 16);
            sklFound = 1;
        }
        if (!strcmp(ext, D_004BC350)) {
            if (cHogFile_GetBlockSize(&hog_model, j) < 0x180) {
                QZero(self->gunBonesOffsets, 24);
                QMove(self->gunBonesOffsets, cHogFile_GetBlock_int(&hog_model, j), (int)cHogFile_GetBlockSize(&hog_model, j) >> 4);
            } else {
                QMove(self->gunBonesOffsets, cHogFile_GetBlock_int(&hog_model, j), 24);
            }
        }
        if (!strcmp(ext, D_004BC358)) {
            strCpyPad((char*)&partNames[partCount], 15, blockName);
            Parts_SetGunData(&parts[partCount], cHogFile_GetBlock_int(&hog_model, j), cHogFile_GetBlockSize(&hog_model, j));
            partCount++;
        }
    }
    if (!sklFound) {
        self->gunPartCount = 0;
        self->gunLoading = -2;
        cHogFile_dtor(&hog_model, -1);
        return;
    }
    for (part = 0; (long long)self->gunAttribsTable[part].partName != 0; part++);
    self->gunPartCount = part;
    fullPartText = (char*)&fullPartName;
    for (part = 0; part < self->gunPartCount; part++) {
        found = 0;
        fullPartName = self->gunAttribsTable[part].partName;
        for (j = 0; j < partCount; j++) {
            if (QEq(fullPartName, partNames[j]) == -1) {
                found = 1;
                self->gunParts[0][part] = parts[j];
            }
        }
        if (!found) {
            self->gunParts[0][part].part = 0;
            self->gunParts[0][part].qwc = 0;
        }
        found = 0;
        fullPartText[14] = '1';
        for (j = 0; j < partCount; j++) {
            if (QEq(fullPartName, partNames[j]) == -1) {
                found = 1;
                self->gunParts[1][part] = parts[j];
            }
        }
        if (!found) self->gunParts[1][part] = self->gunParts[0][part];
        if (!Libc_Strncmp(D_004BC360, fullPartText, 5)) self->gunHolsterPart = part;
        if (!Libc_Strncmp(D_004BC368, fullPartText, 5)) self->gunLightPart = part;
        if (!Libc_Strncmp(D_004BC370, fullPartText, 5)) self->gunStockPartOn = part;
        if (!Libc_Strncmp(D_004BC378, fullPartText, 5)) self->gunStockPartOff = part;
        if (!Libc_Strncmp(D_004BC380, fullPartText, 5)) {
            self->gunFlarePart = part;
            if (!Libc_Strncmp(D_004BC388, fullPartText, 14)) {
                self->gunGlow = 1;
                self->gunFlarePart = -1;
            }
        }
    }
    cFileMan_ctor_void(&texFile);
    cFileMan_EncodeFilename_charP_cHogFileR_bool(&texFile, cHogFile_GetBlockName(&hog_model, 0), &hog_model, 0);
    cTexMan& texMan = *g_TextureMgr;
    for (part = 0; part < self->gunPartCount; part++) {
        fullPartName = self->gunAttribsTable[part].texName;
        self->gunTexID[part] = cTexMan_AddTextureFromFile_R_cFileMan(&texMan, fullPartName, &texFile);
        fullPartText[14] = '1';
        self->gunTexID2[part] = cTexMan_AddTextureFromFile_R_cFileMan(&texMan, fullPartName, &texFile);
        if (self->gunTexID[part] == -1) self->gunTexID[part] = cTexMan_UseMrYuckTexture(&texMan);
        if (self->gunTexID2[part] == -1) self->gunTexID2[part] = self->gunTexID[part];
    }
    part = 3;
    { cQuaternion* o = &self->gunBulletOffset.orient; QCopy1(o, &self->gunBonesOffsets[part].orient); }
    self->gunBulletOffset.u = self->gunBonesOffsets[part].u;
    while (part) {
        part = self->gunBulletOffset.u.the.parent;
        self->gunBulletOffset.u.offset.x += self->gunBonesOffsets[part].u.offset.x;
        self->gunBulletOffset.u.offset.y += self->gunBonesOffsets[part].u.offset.y;
        self->gunBulletOffset.u.offset.z += self->gunBonesOffsets[part].u.offset.z;
        self->gunBulletOffset.u.offset.w += self->gunBonesOffsets[part].u.offset.w;
    }
    self->gunBulletOffset.u.offset.w = 1.0f;
    gunList_GunCalcBBox(self);
    cFileMan_dtor(&texFile, -1);
    cHogFile_dtor(&hog_model, -1);
}
#undef strcmp /* merge_units */
#undef cFileMan_ctor_void /* merge_units */
#undef cFileMan_dtor /* merge_units */
#undef g_TextureMgr /* merge_units */
static inline void merge_flush_func_0038CD90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0038CD90 */

/* merge_units: begin func_0038D530 */
#pragma push /* merge_units */
#pragma cplusplus on

#if 0 /* merge_units */
extern "C" void strCpyPad(char* dst, int n, char* src);
#endif /* merge_units */
#define strCpyPad(a0, a1, a2) (strCpyPad((a0), (a1), (a2))) /* merge_units */


struct V4_D530 {
 float x, y, z, w;
 V4_D530() {}
 V4_D530(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
} __attribute__((aligned(16)));
static inline void QCopy_D530(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory"); }

struct Id_D530 { int a; unsigned short b; };

struct Obj_D530 {
    char name[0x120];
    __int128 q120[2];
    __int128 q140[0x18];
    char pad2C0[0x3E0 - 0x2C0];
    V4_D530 mn;
    V4_D530 mx;
    int x400;
    int x404;
    unsigned short x408;
    short idx;
    unsigned char x40C;
    unsigned char x40D;
    unsigned char x40E;
    unsigned char x40F;
    signed char x410[5];
    unsigned char x415;
    signed char x416;
    signed char x417;
    unsigned char x418;
    unsigned char x419;
    char pad41A[2];
    int x41C;
};



static inline void QZero_D530(void* d0, int n0) { int n = n0; void* d = d0;
    asm {
        .set noreorder
    lp:
        nop
        addi n, n, -1
        sq $zero, 0(d)
        bgtz n, lp
        addiu d, d, 0x10
        .set reorder
    }
}

/* Retail evaluates (mn, mx, &z) before the second copy: the tail is an inline taking all three. */
static inline void FinJ_D530(V4_D530* a, V4_D530* pv0, V4_D530* b)
{
    V4_D530 t2(-3.4028235e38f, -3.4028235e38f, -3.4028235e38f, 1.0f);
    QCopy_D530(pv0, &t2);
    b->x = 0.0f; b->y = 0.0f; b->z = 0.0f; b->w = 0.0f;
    __asm__ volatile("lqc2 vf1, 0x0(%0); lqc2 vf2, 0x0(%1); lqc2 vf3, 0x0(%2); vmini.xyz vf1, vf1, vf3; vmax.xyz vf2, vf2, vf3; sqc2 vf1, 0x0(%0); sqc2 vf2, 0x0(%1)" : : "r"(a), "r"(pv0), "r"(b) : "memory");
}

extern "C" void gunList_LoadGunInit(Obj_D530* self, char* name, int idx, Id_D530* id,
                              int a, int b, int c, int d)
{
    strCpyPad(self->name, 0x1F, name);
    self->x400 = 0;
    self->x40D = c;
    self->x40E = d;
    self->x404 = 0;
    if (id) {
        self->x404 = id->a;
        self->x408 = id->b;
    }
    self->idx = idx;
    self->x40C = 0;
    self->x40F = 0;
    self->x410[0] = -1;
    self->x410[1] = -1;
    self->x410[2] = -1;
    self->x410[3] = -1;
    self->x410[4] = -1;
    self->x417 = -1;
    self->x415 = 0;
    self->x416 = -1;
    self->x41C = 0;
    self->x418 = b;
    self->x419 = a;
    V4_D530 z;
    V4_D530 t1(3.4028235e38f, 3.4028235e38f, 3.4028235e38f, 1.0f);
    QCopy_D530(&self->mn, &t1);
    void* xx = &self->mx;
    FinJ_D530(&self->mn, &self->mx, &z);
    QZero_D530(self->q140, 0x18);
    QZero_D530(self->q120, 2);
    ((float*)self->q140)[-1] = 1.0f;
}
#undef strCpyPad /* merge_units */
static inline void merge_flush_func_0038D530(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0038D530 */
