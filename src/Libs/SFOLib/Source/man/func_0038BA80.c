/* cMan::BloodHitVert(bloodHitInfo&) - man.cc (mw38) */
#include "types.h"
typedef unsigned int u_long128 __attribute__((mode(TI)));

typedef struct { float x, y, z, w; } cVector;
typedef struct { unsigned int x, y, z, w; } hexVect;
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
    u_long128* data;
    char pad4[4];
    manRefs* refs;
    char padC[4];
} manPart;

typedef struct {
    char pad0[0x1EC0];
    manPart parts[32];
} cMan;

static inline void WaitVif0(void)
{
    int a = 7;
    int b = 7;
    int c;
    while (*(volatile int*)0x10008000 & 0x100) {
        asm { div c, a, b }
    }
    for (c = *(volatile int*)0x10003800; c & 7; c = *(volatile int*)0x10003800) {
        __asm__ volatile("vnop");
        __asm__ volatile("sync");
    }
    __asm__ volatile("vnop");
    __asm__ volatile("sync");
}

void cMan_BloodHitVert(cMan* self, bloodHitInfo* hitInfo)
{
    cVector* results1 = (cVector*)0x11004050;
    hexVect* bones = (hexVect*)0x11004670;
    manRefs* refData;
    u_long128* part;
    int qwc;
    unsigned int i;
    int bonesBase;
    unsigned int j;
    int boneNumber;

    refData = self->parts[hitInfo->closestPart].refs;
    part = self->parts[hitInfo->closestPart].data;
    refData++;
    for (i = 0; i < hitInfo->closestPatch; i++) {
        part += refData->qwc;
        refData++;
    }
    qwc = refData->qwc;
    WaitVif0();
    *(volatile int*)0x10008020 = qwc;
    *(volatile int*)0x10008010 = (int)part;
    *(volatile int*)0x10008000 = 0x101;
    __asm__ volatile("sync");
    WaitVif0();
    *(u_long128*)&hitInfo->vert = *(u_long128*)&results1[hitInfo->closestVert << 1];
    hitInfo->boneCount = bones->z & 0xF;
    bones--;
    bonesBase = bones->x;
    for (j = 0; j < hitInfo->boneCount; j++) {
        boneNumber = (bones->z - 133) / 7;
        if (bones->x - bonesBase <= hitInfo->closestVert && bones->x - bonesBase + bones->y >= hitInfo->closestVert) {
            hitInfo->bones[j] = boneNumber;
            if (boneNumber == 2 || boneNumber == 5 || boneNumber == 8 || boneNumber == 10) {
                if (hitInfo->closestHitType != 20) hitInfo->closestHitType = 12;
            }
            if (boneNumber == 9 || boneNumber == 14) {
                if (hitInfo->closestHitType == 8) hitInfo->closestHitType = 4;
            }
        } else {
            hitInfo->bones[j] = -boneNumber;
        }
        bones--;
    }
}
