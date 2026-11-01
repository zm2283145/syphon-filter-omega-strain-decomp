/*
 * Libs/SFOLib/Source/man: 3 files, 0038DF00-0038E100
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0038DF00 */
#pragma push /* merge_units */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
#include "SFOLobby_helpers.h"
int strcmp(const void *, const void *);

extern __int128* D_005712F8[];
extern unsigned int D_005712F0[];
extern char D_004BC318[];
typedef struct {
    char pad0[0x50];
    __int128 name;
    char pad60[0x23F0 - 0x60];
    float f23F0;
    char pad23F4[0x2BC0 - 0x23F4];
    unsigned char b2BC0;
    char pad2BC1;
    unsigned char idx;
} Df00Obj;
static inline __int128 df00mask(__int128 m) {
    __int128 r;
    asm { pcpyld r, zero, m }
    return r;
}
static inline int df00eqm(__int128 m, __int128 a, __int128 b) {
    __int128 y; long long x;
    asm {
        pand x, m, a
        pand y, m, b
        pceqw x, x, y
        ppach x, x, x
    }
    return x == -1;
}
unsigned int cMan_NextFaceShape(Df00Obj* self, int step, unsigned int idx, int type)
{
    __int128 mask = df00mask(0xFFFFFFFFFFFFLL);
    __int128* tbl;
    char buf[16] __attribute__((aligned(16)));
    __int128 key;
    Libc_Strcpy(buf, "SHAPE_");
    tbl = D_005712F8[type];
    key = *(__int128*)buf;
    do {
        idx += step;
        if ((int)idx < 0) idx = D_005712F0[type] - 1;
        if (idx >= D_005712F0[type]) idx = 0;
    } while (!df00eqm(mask, key, tbl[idx]));
    self->idx = idx;
    self->name = tbl[idx];
    if (strcmp((char*)&self->name, D_004BC318) == 0) {
        self->b2BC0 = 0;
    } else {
        self->b2BC0 = 1;
        self->f23F0 = 1.0f;
    }
    return idx;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0038DF00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0038DF00 */

/* merge_units: begin func_0038E030 */
#pragma push /* merge_units */
typedef union Name8E030 {
    __int128 q;
    char c[16];
} Name8E030;

typedef struct Part8E030 {
    Name8E030 name;
    char pad10[0x10];
} Part8E030;

typedef struct Obj8E030 {
    char pad0000[0x90];
    Part8E030 parts[0x111];
    char pad22B0[0x10];
    short texA[0x20];           /* 0x22C0 */
    short texB[0x20];           /* 0x2300 */
} Obj8E030;

extern int g_TextureMgr;
extern short FindTexture__7cTexManCF1(int lib, __int128 name);
extern short cTexMan_UseMrYuckTexture(int lib);

void cMan_GetTextureIDs(Obj8E030* o)
{
    int lib = g_TextureMgr;
    int i;
    for (i = 0; (long)o->parts[i].name.q != 0; i++) {
        Name8E030 n;
        n.q = o->parts[i].name.q;
        o->texA[i] = FindTexture__7cTexManCF1(lib, n.q);
        if (o->texA[i] == -1)
            o->texA[i] = cTexMan_UseMrYuckTexture(lib);
        n.c[14] = '1';
        o->texB[i] = FindTexture__7cTexManCF1(lib, n.q);
        if (o->texB[i] == -1)
            o->texB[i] = o->texA[i];
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0038E030(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0038E030 */

/* merge_units: begin func_0038E100 */
#pragma push /* merge_units */
/* 0038E100 cMan_SetGunOffsets (cMan::SetGunOffsets, man.cc); locals follow the prototype */
#pragma cplusplus on
#pragma inline_depth(8)

typedef unsigned char u8;
typedef unsigned int u_long128 __attribute__((mode(TI)));
/* lq/sq quadword copies (project convention, cf. mw38_00389FA0.c) */
struct cVector {
    float x, y, z, w;
    cVector() {}
    cVector(const cVector& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
    cVector(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    cVector& operator=(const cVector& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct cMatrix {
    __int128 r0, r1, r2, r3;
    cMatrix() {}
    cMatrix(const struct cEulerAngle_T& a);
    cMatrix& operator=(const cMatrix& o) {
        void* xx = this; __int128 qa, qb;
        __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(this), "r"(&o) : "memory");
        return *this;
    }
};
struct cEulerAngle_T {
    float x, y, z;
    unsigned int pad;
    cEulerAngle_T(float ax, float ay, float az) { x = ax; y = ay; z = az; }
};
struct hexVect { unsigned int x, y, z, w; };
struct manRefs { u8 qwc; u8 vertCount; };
struct gunOffRot { cVector offset; cMatrix rotationMat; };
struct gunPlacement { u8 place[10]; char pad[6]; gunOffRot loc[10]; };
struct BoneE { char pad[0xD0]; cMatrix m; char pad110[0x1D0 - 0x110]; };
struct cSkeleton { char pad[0x14]; u8 isActive; char pad15[3]; char boneList[8]; BoneE* bones; };
struct manAttribs { u_long128 name; char pad[0x10]; };
struct SKL { char pad0[0x20]; u_long128 gunOffsetPart; char pad30[0x10]; manAttribs manAttribsTable[32]; };
struct cMan {
    char pad0[0x40];
    SKL skl;
    char pad480[0x2450 - 0x480];
    gunPlacement gun;
    char pad2780[0x2C04 - 0x2780];
    cSkeleton* skeleton;
    char pad2C08[4];
    u8 sex;
};
struct PartE0 { u_long128* data; char pad[0x1C]; };
struct PartE7 { u8 count; char pad[0x1F]; };
struct PartE8 { manRefs* refs; char pad[0x1C]; };

extern "C" {
extern float COS(float);
extern float SIN(float);
extern void cMatrix_Set_ColumnMajorForm(cMatrix* m, float a, float b, float c, float d, float e, float f,
                                        float g, float h, float i);
extern int SKL_FindPartIndex(SKL* p, const char* name);
extern int Libc_Strncmp(const char* a, const char* b, int n);
extern int FindPart__7MonsterF1(char* cache, u_long128 name);
extern void* cArray_cBone_opIndex_int(void* v, int i);
extern cMatrix* cBone_GetScaleMatrix(void* p);
extern cMatrix* cMatrix_GetUnit(void);
extern void cMan_SetGunLoc(cMan* m, int idx, unsigned int type);
extern char g_AgentPartCache[];
extern PartE0 D_005639B0[];
extern PartE7 D_005639B7[];
extern PartE8 D_005639B8[];
extern int D_00542D40;
extern int D_00542D44;
extern int D_00542D48;
extern unsigned int D_004937C0[];
extern unsigned int D_004937D0[];
}

inline cMatrix::cMatrix(const cEulerAngle_T& a)
{
    float y = a.y;
    float x = a.x;
    float z = a.z;
    float cy = COS(y);
    float sy = SIN(y);
    float cx = COS(x);
    float sx = SIN(x);
    float cz = COS(z);
    float sz = SIN(z);
    float czcy = cz * cy;
    float czsy = cz * sy;
    float szcy = sz * cy;
    float szsy = sz * sy;
    cMatrix_Set_ColumnMajorForm(this,
                      czcy - szsy * sx, -sz * cx, czsy + szcy * sx,
                      szcy + czsy * sx, cz * cx, szsy - czcy * sx,
                      -cx * sy, sx, cx * cy);
}

static inline cVector operator*(const cVector& v, const cMatrix& m)
{
    cVector r = v;
    cVector* p = &r;
    const cMatrix* q = &m;
    /* VU0 macro-mode vector * matrix */
    asm {
        lqc2 vf8, 0x0(p)
        lqc2 vf4, 0x0(q)
        lqc2 vf5, 0x10(q)
        lqc2 vf6, 0x20(q)
        lqc2 vf7, 0x30(q)
        vmulax.xyzw ACC, vf4, vf8x
        vmadday.xyzw ACC, vf5, vf8y
        vmaddaz.xyzw ACC, vf6, vf8z
        vmaddw.xyzw vf12, vf7, vf8w
        sqc2 vf12, 0x0(p)
    }
    return *p;
}

static inline cMatrix* BoneMat(cSkeleton* s, int n)
{
    if (s->isActive)
        return cBone_GetScaleMatrix(cArray_cBone_opIndex_int(s->boneList, n));
    return cMatrix_GetUnit();
}

static inline void KickVif0(u_long128* madr, int qwc)
{
    *(volatile int*)0x10008020 = qwc;
    *(volatile int*)0x10008010 = (int)madr;
    *(volatile int*)0x10008000 = 0x101;
    __asm__ volatile("sync"); /* EE sync after DMA kick */
}

static inline void LoadMicro(int i)
{
    if (i != D_00542D48) {
        KickVif0((u_long128*)D_004937C0[i], (D_004937D0[i] - D_004937C0[i]) >> 4);
        D_00542D48 = i;
    }
}

static inline void WaitVif0(void)
{
    int a, b, c;
    while (*(volatile int*)0x10008000 & 0x100) {
        a = 7;
        b = 7;
        asm { div c, a, b } /* dead div while DMA busy (retail stall idiom, cf. l4 mw38_0038BA80.c) */
    }
    for (c = *(volatile int*)0x10003800; c & 7; c = *(volatile int*)0x10003800) {
        __asm__ volatile("vnop"); /* VU0 drain while VIF0 busy */
        __asm__ volatile("sync");
    }
    __asm__ volatile("vnop"); /* final VU0 drain */
    __asm__ volatile("sync");
}

/* angle-wrapper: nonzero Euler args become early temps (FPR numbering) */
static inline float Angle(float a) { return a; }
#define PI 3.1415927f
#define PI_2 1.5707964f
#define PI_6 0.5235988f

extern "C" void cMan_SetGunOffsets(cMan* self)
{
    int manGunOffsetPart;
    int gunOffsetPart;
    char* texName;
    int bone;
    u_long128* bonesSrc;
    cMatrix* bonesMat;
    cVector* results;
    manRefs* refData;
    int qwc;
    u_long128* part;
    int patchCount;
    int vertCount;
    hexVect* bonesTable;
    int totalVerts;
    int baseOffset;
    unsigned int k;
    int vertOffset;
    int boneVerts;

    manGunOffsetPart = SKL_FindPartIndex(&self->skl, "HARD_");
    gunOffsetPart = -1;
    if (manGunOffsetPart != gunOffsetPart) {
        gunOffsetPart = FindPart__7MonsterF1(g_AgentPartCache, self->skl.manAttribsTable[manGunOffsetPart].name);
    } else {
        texName = (char*)&self->skl.gunOffsetPart;
        if (Libc_Strncmp(texName + 1, "HARD", 4) == 0)
            gunOffsetPart = FindPart__7MonsterF1(g_AgentPartCache, self->skl.gunOffsetPart);
    }

    if (gunOffsetPart != -1) {
        bonesMat = (cMatrix*)0x11004AC0;
        for (bone = 0; bone < 21; bone++) {
            *bonesMat = self->skeleton->bones[bone].m;
            bonesMat++;
        }
        results = (cVector*)0x70000540;
        refData = D_005639B8[gunOffsetPart].refs;
        part = D_005639B0[gunOffsetPart].data;
        refData++;
        for (patchCount = 0; patchCount < D_005639B7[gunOffsetPart].count; patchCount++) {
            LoadMicro(D_00542D40);
            vertCount = refData->vertCount;
            qwc = refData->qwc;
            WaitVif0();
            KickVif0(part, qwc);
            WaitVif0();
            {
                u_long128* dst = (u_long128*)results;
                u_long128* src = (u_long128*)0x11004050;
                while (vertCount) {
                    vertCount--;
                    *dst = *src;
                    src += 2;
                    dst++;
                }
            }
            LoadMicro(D_00542D44);
            WaitVif0();
            KickVif0(part, qwc);
            refData++;
            part += qwc;
            WaitVif0();
            bonesTable = (hexVect*)0x11004670;
            totalVerts = bonesTable->x;
            bonesTable--;
            baseOffset = bonesTable->x;
            for (k = 0; k < totalVerts; bonesTable--) {
                bone = (bonesTable->z - 0x85) / 7;
                vertOffset = bonesTable->x - baseOffset;
                boneVerts = bonesTable->y;
                while (boneVerts > 0) {
                    cMan_SetGunLoc(self, vertOffset, bone);
                    vertOffset += 3;
                    k += 3;
                    boneVerts -= 3;
                }
            }
        }
        self->gun.loc[7].offset = self->gun.loc[0].offset;
        self->gun.loc[7].rotationMat = self->gun.loc[0].rotationMat;
        self->gun.place[7] = self->gun.place[0];
        return;
    }

    cEulerAngle_T fudgeRotation0(0.0f, 0.0f, 0.0f);
    self->gun.loc[0].rotationMat = cMatrix(fudgeRotation0);
    cVector offset0(0.0f, 0.0f, 0.0f, 1.0f);
    self->gun.loc[0].offset = offset0;
    cEulerAngle_T fudgeRotation1(0.0f, Angle(PI), 0.0f);
    self->gun.loc[1].rotationMat = cMatrix(fudgeRotation1);
    cVector offset1(0.0f, 0.0f, -0.15f, 1.0f);
    self->gun.loc[1].offset = offset1;
    if (self->sex == 1) {
        cEulerAngle_T fudgeRotation2(Angle(PI_6), Angle(PI_2), Angle(PI_2));
        self->gun.loc[2].rotationMat = cMatrix(fudgeRotation2);
        cVector offset2(0.5f, -0.4f, 0.6f, 1.0f);
        self->gun.loc[2].offset = offset2 * *BoneMat(self->skeleton, 5);
        cEulerAngle_T fudgeRotation3(0.0f, Angle(PI_2), 0.0f);
        self->gun.loc[3].rotationMat = cMatrix(fudgeRotation3);
        cVector offset3(0.85f, -0.13f, 0.35f, 1.0f);
        self->gun.loc[3].offset = offset3 * *BoneMat(self->skeleton, 3);
        cEulerAngle_T fudgeRotation4(0.0f, Angle(PI_2), 0.0f);
        self->gun.loc[4].rotationMat = cMatrix(fudgeRotation4);
        cVector offset4(-0.72f, -0.13f, 0.35f, 1.0f);
        self->gun.loc[4].offset = offset4 * *BoneMat(self->skeleton, 1);
        cEulerAngle_T fudgeRotation5(0.0f, Angle(PI_2), 0.0f);
        self->gun.loc[5].rotationMat = cMatrix(fudgeRotation5);
        cVector offset5(0.45f, -0.13f, -0.65f, 1.0f);
        self->gun.loc[5].offset = offset5 * *BoneMat(self->skeleton, 3);
        cEulerAngle_T fudgeRotation6(Angle(PI_2), 0.0f, 0.0f);
        self->gun.loc[6].rotationMat = cMatrix(fudgeRotation6);
        cVector offset6(0.0f, 0.0f, -0.18f, 1.0f);
        self->gun.loc[6].offset = offset6 * *BoneMat(self->skeleton, 14);
        cEulerAngle_T fudgeRotation7(Angle(PI_2), 0.0f, 0.0f);
        self->gun.loc[7].rotationMat = cMatrix(fudgeRotation7);
        cVector offset7(0.0f, 0.0f, -0.18f, 1.0f);
        self->gun.loc[7].offset = offset7 * *BoneMat(self->skeleton, 14);
    } else {
        cEulerAngle_T fudgeRotation2(Angle(PI_6), Angle(PI_2), Angle(PI_2));
        self->gun.loc[2].rotationMat = cMatrix(fudgeRotation2);
        cVector offset2(0.5f, -0.2f, 0.6f, 1.0f);
        self->gun.loc[2].offset = offset2 * *BoneMat(self->skeleton, 5);
        cEulerAngle_T fudgeRotation3(0.0f, Angle(1.3089969f), Angle(-0.2617994f));
        self->gun.loc[3].rotationMat = cMatrix(fudgeRotation3);
        cVector offset3(0.55f, -0.03f, 0.35f, 1.0f);
        self->gun.loc[3].offset = offset3 * *BoneMat(self->skeleton, 3);
        cEulerAngle_T fudgeRotation4(0.0f, Angle(1.8325957f), Angle(0.2617994f));
        self->gun.loc[4].rotationMat = cMatrix(fudgeRotation4);
        cVector offset4(-0.4f, -0.03f, 0.35f, 1.0f);
        self->gun.loc[4].offset = offset4 * *BoneMat(self->skeleton, 1);
        cEulerAngle_T fudgeRotation5(0.0f, Angle(PI_2), 0.0f);
        self->gun.loc[5].rotationMat = cMatrix(fudgeRotation5);
        cVector offset5(0.3f, -0.13f, -0.65f, 1.0f);
        self->gun.loc[5].offset = offset5 * *BoneMat(self->skeleton, 3);
        cEulerAngle_T fudgeRotation6(Angle(PI_2), 0.0f, 0.0f);
        self->gun.loc[6].rotationMat = cMatrix(fudgeRotation6);
        cVector offset6(0.0f, 0.0f, -0.18f, 1.0f);
        self->gun.loc[6].offset = offset6 * *BoneMat(self->skeleton, 14);
        cEulerAngle_T fudgeRotation7(Angle(PI_2), 0.0f, 0.0f);
        self->gun.loc[7].rotationMat = cMatrix(fudgeRotation7);
        cVector offset7(0.0f, 0.0f, -0.18f, 1.0f);
        self->gun.loc[7].offset = offset7 * *BoneMat(self->skeleton, 14);
    }
    self->gun.place[0] = 0x14;
    self->gun.place[1] = 0x13;
    self->gun.place[2] = 5;
    self->gun.place[3] = 0;
    self->gun.place[4] = 0;
    self->gun.place[5] = 5;
    self->gun.place[6] = 0xE;
    self->gun.place[7] = 5;
    self->gun.place[8] = 0;
    self->gun.place[9] = 0;
}
static inline void merge_flush_func_0038E100(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0038E100 */
