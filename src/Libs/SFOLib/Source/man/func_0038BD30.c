/* 0038BD30 cMan::BloodHitPart(bloodHitInfo&, int, int) - SFOLib man.cc */
#include "types.h"
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
    Parts bodyParts[64];
    short manTexID[32];
    short manTexID2[32];
    u_long128* bloodData[32];
    unsigned short manAttribsCount;
} ManParts;

typedef struct {
    char pad0[0x1EC0];
    ManParts parts;
} cMan;

/* fabsf: mw38 keeps the dead r = 0 init (mtc1 zero) only when asm writes r. */
static inline float AbsZ(float x) { float r = 0.0f; asm { abs.s r, x } return r; }
/* float->int: asm keeps the dead distance = 0 init (daddu zero) like retail. */
static inline int F2I(float f) { int r = 0; float t; asm { cvt.w.s t, f; mfc1 r, t } return r; }

static inline void WaitVif0(void)
{
    int a, b, c;
    while (*(volatile int*)0x10008000 & 0x100) {
        a = 7;
        b = 7;
        /* dead 7/7 delay div; every C form is DCE'd */
        asm { div c, a, b }
    }
    for (c = *(volatile int*)0x10003800; c & 7; c = *(volatile int*)0x10003800) {
        __asm__ volatile("vnop");
        __asm__ volatile("sync");
    }
    __asm__ volatile("vnop");
    __asm__ volatile("sync");
}

void cMan_BloodHitPart(cMan* self, bloodHitInfo* hitInfo, int j, int unused)
{
    cVector* results = (cVector*)0x70000540;
    manRefs* refData;
    u_long128* part;
    unsigned int patchCount;
    int qwc;
    int nextVertCount;
    int vertCount;
    u_long128* blood128;
    unsigned char* bloodChars;
    int partHitType;
    unsigned int i;
    unsigned int k;
    float dist;
    float distCalc;
    int distance;

    partHitType = self->parts.bodyParts[j].type & 0x1C;
    refData = self->parts.bodyParts[j].Refs;
    patchCount = self->parts.bodyParts[j].patchCount;
    blood128 = self->parts.bloodData[j];
    part = self->parts.bodyParts[j].part;
    refData++;
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
        vertCount = nextVertCount;
        WaitVif0();
        {
            u_long128* dst;
            u_long128* src;
            int n;
            n = vertCount;
            src = (u_long128*)0x11004050;
            dst = (u_long128*)results;
            while (n) {
                *dst = *src;
                n--;
                src += 2;
                dst++;
            }
        }
        bloodChars = (unsigned char*)blood128;
        blood128 += 2;
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
            if (dist < 0.04f) {
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
                dist = 200.0f - dist * 16000.0f;
                distance = F2I(dist);
                if (distance <= 0) distance = 1;
                distance += *bloodChars;
                if (distance > 90) distance = 90;
                *bloodChars = distance;
            }
            bloodChars++;
        }
    }
}
