#include "types.h"

#pragma cplusplus on
typedef unsigned long long U64;
struct cMatrix { float m[4][4]; } __attribute__((aligned(16)));
struct cMatrixNxM { float m[4][3]; } __attribute__((aligned(16)));
struct Parts { __int128* part; unsigned short qwc; char pad[10]; };
struct gunList {
    char pad0[0x2C0];
    Parts gunParts[2][8];
    char pad3C0[0x40C - 0x3C0];
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
struct manRenderSPAD {
    char header[0xA50];
    U64 manTex0[32];
    U64 gunTex0[8][8];
    cMatrix gunBoneData[8][11];
    cMatrixNxM gunLightData[8];
    U64 shellTex0;
};
struct cMan {
    char pad0[0x2410];
    gunList* manGuns[10];
    char gunInvis[10];
    char gunOnOffFlag[10];
    char pad244C[0x2D90 - 0x244C];
    unsigned char triggerPulled;
    unsigned char triggerPulled2;
};

static inline void QMove(void* dd, void* ss, int nn) { int n = nn; __int128 q; void* s = ss; void* d = dd;
    __asm__ volatile(".set noreorder; 1: lq %0, 0(%2); addiu %1, %1, 0x10; addi %3, %3, -1; addiu %2, %2, 0x10; bgtz %3, 1b; sq %0, -0x10(%1); .set reorder" : "=&r"(q), "+r"(d), "+r"(s), "+r"(n) : : "memory");
}

extern "C" U64* cMan_ManDMAGuns(cMan* self, U64* dmaVif, int lod, int shadow, int transparency)
{
    manRenderSPAD* SPAD = (manRenderSPAD*)0x70000000;
    U64 backclip = 0;
    int j;
    gunList* aGun;
    U64 vifCode3;
    int k;
    int gunGlow;
    int lightPart;
    int holsterPart;
    int stockPart;
    int flarePart;
    unsigned int i;

    if (transparency != 128) backclip = 32;
    for (j = 0; j < 8; j++) {
        aGun = self->manGuns[j];
        if (aGun == 0) continue;
        if (self->gunInvis[j]) continue;
        if (aGun->gunLoading) continue;
        vifCode3 = 0x6C4D008500000000ULL | 0x15000000;
        *dmaVif++ = 0x1000004D;
        *dmaVif++ = vifCode3;
        for (k = 0; k < 11; k++) {
            QMove(dmaVif, &SPAD->gunBoneData[j][k], 4);
            QMove(dmaVif + 8, &SPAD->gunLightData[j], 3);
            dmaVif += 14;
        }
        gunGlow = aGun->gunGlow;
        lightPart = aGun->gunLightPart;
        if (self->gunOnOffFlag[j]) lightPart = -1;
        holsterPart = aGun->gunHolsterPart;
        if (j == 3 || j == 4) holsterPart = -1;
        stockPart = aGun->gunStockPartOn;
        if (j == 0) stockPart = aGun->gunStockPartOff;
        if (j == 6 && self->gunOnOffFlag[j]) stockPart = aGun->gunStockPartOff;
        flarePart = aGun->gunFlarePart;
        for (i = 0; i < aGun->gunPartCount; i++) {
            if (aGun->gunParts[lod][i].part == 0) continue;
            if (i == holsterPart) continue;
            if (i == lightPart) continue;
            if (i == stockPart) continue;
            if (i != flarePart) {
                dmaVif[0] = 0x10000001;
                dmaVif[1] = 0x6C01806800000000ULL | 0x01000404;
                dmaVif[2] = SPAD->gunTex0[j][i];
                dmaVif[3] = backclip;
                dmaVif[4] = (long long)(int)(aGun->gunParts[lod][i].qwc + 0x30000000) + ((U64)(unsigned int)aGun->gunParts[lod][i].part << 32);
                dmaVif[5] = 0;
                dmaVif += 6;
            } else if (!shadow) {
                if (gunGlow || (j == 0 && self->triggerPulled && self->triggerPulled < 3)) {
                    dmaVif[0] = 0x10000001;
                    dmaVif[1] = 0x6C01806800000000ULL | 0x01000404;
                    dmaVif[2] = SPAD->gunTex0[j][i];
                    dmaVif[3] = 0xBFC00000ULL;
                    dmaVif[4] = (long long)(int)(aGun->gunParts[lod][i].qwc + 0x30000000) + ((U64)(unsigned int)aGun->gunParts[lod][i].part << 32);
                    dmaVif[5] = 0;
                    dmaVif += 6;
                }
                if (gunGlow || (j == 1 && self->triggerPulled2 && self->triggerPulled2 < 3)) {
                    dmaVif[0] = 0x10000001;
                    dmaVif[1] = 0x6C01806800000000ULL | 0x01000404;
                    dmaVif[2] = SPAD->gunTex0[j][i];
                    dmaVif[3] = 0xBFC00000ULL;
                    dmaVif[4] = (long long)(int)(aGun->gunParts[lod][i].qwc + 0x30000000) + ((U64)(unsigned int)aGun->gunParts[lod][i].part << 32);
                    dmaVif[5] = 0;
                    dmaVif += 6;
                }
            }
        }
    }
    if (self->manGuns[0] && self->manGuns[0]->gunHolsterPart != -1) {
        U64 vifCode3 = 0x6C07008500000000ULL | 0x15000000;
        int holsterPart;
        *dmaVif++ = 0x10000007;
        *dmaVif++ = vifCode3;
        QMove(dmaVif, &SPAD->gunBoneData[3][0], 4);
        QMove(dmaVif + 8, &SPAD->gunLightData[3], 3);
        dmaVif += 14;
        holsterPart = self->manGuns[0]->gunHolsterPart;
        dmaVif[0] = 0x10000001;
        dmaVif[1] = 0x6C01806800000000ULL | 0x01000404;
        dmaVif[2] = SPAD->gunTex0[0][holsterPart];
        dmaVif[3] = backclip;
        dmaVif[4] = (long long)(int)(self->manGuns[0]->gunParts[lod][holsterPart].qwc + 0x30000000) + ((U64)(unsigned int)self->manGuns[0]->gunParts[lod][holsterPart].part << 32);
        dmaVif[5] = 0;
        dmaVif += 6;
    }
    if (self->manGuns[1] && self->manGuns[1]->gunHolsterPart != -1) {
        U64 vifCode3 = 0x6C07008500000000ULL | 0x15000000;
        int holsterPart;
        *dmaVif++ = 0x10000007;
        *dmaVif++ = vifCode3;
        QMove(dmaVif, &SPAD->gunBoneData[4][0], 4);
        QMove(dmaVif + 8, &SPAD->gunLightData[4], 3);
        dmaVif += 14;
        holsterPart = self->manGuns[1]->gunHolsterPart;
        dmaVif[0] = 0x10000001;
        dmaVif[1] = 0x6C01806800000000ULL | 0x01000404;
        dmaVif[2] = SPAD->gunTex0[1][holsterPart];
        dmaVif[3] = backclip;
        dmaVif[4] = (long long)(int)(self->manGuns[1]->gunParts[lod][holsterPart].qwc + 0x30000000) + ((U64)(unsigned int)self->manGuns[1]->gunParts[lod][holsterPart].part << 32);
        dmaVif[5] = 0;
        dmaVif += 6;
    }
    return dmaVif;
}
