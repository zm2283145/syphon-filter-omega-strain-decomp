/* 0038C050 cMan::BloodHit(bloodHitInfo&, int) - SFOLib man.cc */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#include "canonical_key_copy.h"
typedef unsigned int u_long128 __attribute__((mode(TI)));

typedef struct { float x, y, z, w; } cVector;
typedef struct { unsigned char qwc; unsigned char vertCount; } manRefs;

typedef struct {
    cVector vert;
    cVector normal;
    float closestDist;
    float closestY;
    int closestHitType;
    short closestVert;
    short closestPatch;
    short closestPart;
    short pad;
    float farthestDist;
    float farthestY;
    int farthestHitType;
    char bones[8];
    char boneCount;
    float hitRadius;
} bloodHitInfo;

typedef struct {
    u_long128* part;
    unsigned short qwc;
    unsigned char type;
    unsigned char patchCount;
    manRefs* Refs;
    unsigned int* blends;
} Parts;

typedef struct {
    Parts bodyParts[2][32];
    short manTexID[32];
    short manTexID2[32];
    u_long128* bloodData[32];
    unsigned short manAttribsCount;
} ManParts;

typedef struct {
    char pad0[0x1EC0];
    ManParts parts;
    char pad23C4[0x2C08 - 0x23C4];
    int bloodSpurt;
} cMan;

extern "C" {
extern int D_00542D40;
extern int D_00542D48;
extern unsigned int D_004937C0[];
extern unsigned int D_004937D0[];
extern char D_004BC310[];
void* cMemMan_Allocate(int pool, int size, char* file, int line);
void cMan_BloodHitPart(cMan* self, bloodHitInfo* hitInfo, int j, int bloodyAll);
void cMan_BloodHitVert(cMan* self, bloodHitInfo* hitInfo);
}

static inline float AbsZ(float x) { float r = 0.0f; asm { abs.s r, x } return r; }

static inline void WaitVif0(void)
{
    int a, b, c;
    while (*(volatile int*)0x10008000 & 0x100) {
        a = 7;
        b = 7;
        asm { div c, a, b }
    }
    for (c = *(volatile int*)0x10003800; c & 7; c = *(volatile int*)0x10003800) {
        __asm__ volatile("vnop");
        __asm__ volatile("sync");
    }
    __asm__ volatile("vnop");
    __asm__ volatile("sync");
}

/* VU1 output gather; a separate inline gives n/src/dst the a1..a3 coloring retail has */
static inline void CopyVerts(u_long128* dst, u_long128* src, int n)
{
    while (n) {
        *dst = *src;
        n--;
        src += 2;
        dst++;
    }
}

extern "C" unsigned int cMan_BloodHit(cMan* self, bloodHitInfo* hitInfo, int bloodyAll)
{
    int bone;
    u_long128* bonesSrc;
    u_long128* boneDest;
    cVector* results;
    manRefs* refData;
    unsigned int patchCount;
    int partHitType;
    unsigned int hit;
    int applyBlood;
    int bloodSpurt;
    float hitRadSquared;
    int j;
    int qwc;
    int vertCount;
    int nextVertCount;
    u_long128* part;
    unsigned int i;
    unsigned int blood;
    unsigned int k;
    float dist;
    float distCalc;
    int bloodQWC;

    boneDest = (u_long128*)0x11004AC0;
    bonesSrc = (u_long128*)0x70000000;
    for (bone = 0; bone < 21; bone++) {
        boneDest[0] = bonesSrc[0];
        boneDest[1] = bonesSrc[1];
        boneDest[2] = bonesSrc[2];
        boneDest[3] = bonesSrc[3];
        bonesSrc += 4;
        boneDest += 4;
    }
    {
        int idx = D_00542D40;
        if (idx != D_00542D48) {
            unsigned int end = D_004937D0[idx];
            unsigned int start = D_004937C0[idx];
            *(volatile int*)0x10008020 = (end - start) >> 4;
            *(volatile int*)0x10008010 = start;
            *(volatile int*)0x10008000 = 0x101;
            __asm__ volatile("sync");
            D_00542D48 = idx;
        }
    }
    results = (cVector*)0x70000540;
    hit = 0;
    bloodSpurt = 0;
    hitInfo->closestDist = 1e7f;
    hitInfo->farthestDist = -1e7f;
    hitRadSquared = hitInfo->hitRadius * hitInfo->hitRadius;
    for (j = self->parts.manAttribsCount - 1; j >= 0; j--) {
        refData = self->parts.bodyParts[1][j].Refs;
        partHitType = self->parts.bodyParts[1][j].type & 0x1C;
        patchCount = self->parts.bodyParts[1][j].patchCount;
        part = self->parts.bodyParts[1][j].part;
        refData++;
        applyBlood = bloodyAll == 2 || (partHitType < 12 && bloodyAll == 1);
        if (self->parts.bodyParts[0][j].type & 0x80) applyBlood = 0;
        if (part && partHitType != 0x1C) {
            qwc = refData->qwc;
            nextVertCount = refData->vertCount;
            WaitVif0();
            *(volatile int*)0x10008020 = qwc;
            *(volatile int*)0x10008010 = (int)part;
            *(volatile int*)0x10008000 = 0x101;
            __asm__ volatile("sync");
            part += qwc;
            refData++;
            for (i = 0; i < patchCount; i++) {
                WaitVif0();
                vertCount = nextVertCount;
                blood = 0;
                CopyVerts((u_long128*)results, (u_long128*)0x11004050, vertCount);
                if (i < patchCount - 1) {
                    qwc = refData->qwc;
                    nextVertCount = refData->vertCount;
                    *(volatile int*)0x10008020 = qwc;
                    *(volatile int*)0x10008010 = (int)part;
                    *(volatile int*)0x10008000 = 0x101;
                    __asm__ volatile("sync");
                    part += qwc;
                    refData++;
                }
                for (k = 0; k < vertCount; k++) {
                    {
                        float x;
                        float z;
                        z = results[k].z;
                        x = results[k].x;
                        dist = z * z + x * x;
                    }
                    if (dist < hitRadSquared) {
                        hit = 1;
                        blood = 1;
                        distCalc = 0.25f * results[k].y + AbsZ(dist);
                        if (distCalc < hitInfo->closestDist) {
                            hitInfo->closestDist = distCalc;
                            hitInfo->closestY = results[k].y;
                            hitInfo->closestHitType = partHitType;
                            hitInfo->closestVert = k;
                            hitInfo->closestPatch = i;
                            hitInfo->closestPart = j;
                        }
                        if (distCalc > hitInfo->farthestDist) {
                            hitInfo->farthestDist = distCalc;
                            hitInfo->farthestY = results[k].y;
                            hitInfo->farthestHitType = partHitType;
                        }
                        if (applyBlood) break;
                    }
                }
                if (blood && applyBlood) {
                    bloodSpurt = 1;
                    if (!self->parts.bloodData[j]) {
                        bloodQWC = self->parts.bodyParts[0][j].patchCount * 2;
                        {
                            void* p;
                            {
                                AllocGuard guard;
                                p = cMemMan_Allocate(0, bloodQWC * 16, D_004BC310, 0xB24);
                            }
                            self->parts.bloodData[j] = (u_long128*)p;
                        }
                        ckc_qzero(self->parts.bloodData[j], bloodQWC);
                    }
                    cMan_BloodHitPart(self, hitInfo, j, bloodyAll);
                    break;
                }
            }
        }
    }
    if (hit) {
        cMan_BloodHitVert(self, hitInfo);
        if (bloodSpurt) self->bloodSpurt = 1;
        return hitInfo->closestHitType;
    }
    return 0;
}
