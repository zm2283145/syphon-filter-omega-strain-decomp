#pragma cplusplus on
#include "types.h"

typedef unsigned long U64;
typedef long long S64;
typedef unsigned int u_int;

struct manRefs { unsigned char qwc; unsigned char vertCount; };
struct Parts { U64* part; unsigned short qwc; unsigned char type; unsigned char patchCount; manRefs* Refs; u_int* blends; };
struct _manHands { float destAmt; float sourceAmt; int source; int dest; };
struct cMan {
    char pad0[0x1EC0];
    Parts parts[0x48];
    u_int bloodTex[32];
    unsigned short partCount;
    char pad23C2[0x23D0 - 0x23C2];
    _manHands hands[2];
    float faceBlends[8];
    void* manGuns[10];
    char pad2438[0x2BC1 - 0x2438];
    unsigned char faceBlendCount;
    unsigned char faceBlendNumbers[8];
    char pad2BCA[0x2C0E - 0x2BCA];
    signed char mouthPart;
    signed char strapPart;
};

struct manRenderSPAD { char header[0xA50]; U64 manTex0[32]; };
static inline manRenderSPAD* SpadP() { manRenderSPAD* SPAD = (manRenderSPAD*)0x70000000; return SPAD; }
#define SPAD SpadP()

extern "C" U64* cMan_ManDMA(cMan* self, U64* dmaVif, int lod, int shadow, int transparency)
{
    Parts* PARTS = &self->parts[lod * 32];
    U64 backclip = 0;
    U64 partCount = self->partCount;
    Parts* bloodParts = &self->parts[0];
    int strapOff;
    int mouthOff;
    int result;
    int one;
    int two;
    u_int i;

    if (shadow) {
        dmaVif[0] = 0x10000002;
        dmaVif[1] = (U64)0x50000002 << 32;
        dmaVif[2] = 0x8001 | ((U64)0x24000000 << 32);
        dmaVif[3] = 0x12;
        dmaVif[4] = 0x3E000000 | ((U64)0x3E000000 << 32);
        dmaVif[5] = (S64)shadow + ((U64)0x3F800000 << 32 | (U64)0x80 << 24) + (shadow << 8) + (shadow << 16);
        dmaVif += 6;
    }
    strapOff = -1;
    if (!self->manGuns[2] && !self->manGuns[5]) strapOff = self->strapPart;
    mouthOff = -1;
    if (transparency != 0x80) {
        mouthOff = self->mouthPart;
        backclip = 0x20;
    }
    while (*(volatile u_int*)0x1000D400 & 0x100) {
        one = 7;
        two = 7;
        /* busy-wait delay: an integer divide the compiler would fold away */
        __asm__ volatile("div %1, %2; nop; nop; mflo %0" : "=r"(result) : "r"(one), "r"(two));
    }
    for (i = 0; i < partCount; i++) {
        U64 type;
        U64 partType;
        S64 blood128;
        U64 vifBlood;
        U64 bloodPtr;
        if (PARTS[i].part == 0) continue;
        if (i == strapOff) continue;
        type = PARTS[i].type;
        partType = type & 3;
        vifBlood = 0x5000001 | ((U64)0x6D04C000 << 32);
        blood128 = self->bloodTex[i];
        bloodPtr = ((U64)blood128 << 32) + 0x30000002;
        if (blood128) blood128 = 0xBF000000;
        if (partType == 0) {
            dmaVif[0] = 0x10000002;
            dmaVif[1] = 0x1000404 | ((U64)0x6C028068 << 32);
            dmaVif[2] = SPAD->manTex0[i];
            if (blood128 == 0) {
                dmaVif[3] = backclip;
                dmaVif[4] = 0;
                dmaVif[5] = 0;
                dmaVif[6] = (S64)(int)(PARTS[i].qwc + 0x30000000) + ((U64)(u_int)PARTS[i].part << 32);
                dmaVif[7] = 0;
                dmaVif += 8;
            } else {
                manRefs* refSource;
                U64 refSourceRef;
                int refCount;
                dmaVif[3] = blood128 + backclip;
                dmaVif[4] = 0;
                dmaVif[5] = 0;
                dmaVif += 6;
                refSource = bloodParts[i].Refs;
                refSourceRef = (u_int)bloodParts[i].part;
                refCount = bloodParts[i].patchCount;
                refSource++;
                while (refCount > 0) {
                    U64 sourceQwc;
                    sourceQwc = refSource->qwc;
                    dmaVif[0] = bloodPtr;
                    dmaVif[1] = vifBlood;
                    dmaVif[2] = (refSourceRef << 32) + 0x30000000 + sourceQwc;
                    dmaVif[3] = 0x5000000;
                    dmaVif += 4;
                    bloodPtr += (U64)0x20 << 32;
                    sourceQwc <<= 4;
                    refSourceRef += sourceQwc;
                    refSource++;
                    refCount--;
                }
            }
        } else if (partType == 3) {
            U64* faceBlend = (U64*)self->faceBlends;
            S64 realBlendCount;
            u_int blendCount;
            u_int patchCount;
            u_int* blends;
            int patchPointer;
            u_int* blend1flagPtr;
            u_int* blend2flagPtr;
            u_int* blend3flagPtr;
            u_int* blend4flagPtr;
            u_int* blend5flagPtr;
            u_int* blend6flagPtr;
            u_int* blend7flagPtr;
            u_int* blend8flagPtr;
            S64 blendBase;
            U64 blend1;
            U64 blend2;
            U64 blend3;
            U64 blend4;
            U64 blend5;
            U64 blend6;
            U64 blend7;
            U64 blend8;
            manRefs* refData;
            U64 refDataRef;
            U64 blendEight;
            U64 vifCode;
            U64 vifNull;
            u_int blend1flag;
            u_int blend2flag;
            u_int blend3flag;
            u_int blend4flag;
            u_int blend5flag;
            u_int blend6flag;
            u_int blend7flag;
            u_int blend8flag;
            u_int blendMask;
            u_int refCount;
            if (PARTS[i].part == 0) continue;
            if (i == mouthOff) continue;
            realBlendCount = self->faceBlendCount;
            if (realBlendCount == 1 && self->faceBlends[0] == 0.0f) realBlendCount = 0;
            if (PARTS[i].blends == 0) realBlendCount = 0;
            dmaVif[0] = 0x10000003;
            dmaVif[1] = 0x1000404 | ((U64)0x6C038068 << 32);
            dmaVif[2] = SPAD->manTex0[i];
            dmaVif[3] = backclip + (((U64)realBlendCount << 32) + blood128);
            dmaVif[4] = *faceBlend;
            dmaVif[5] = *(U64*)&self->faceBlends[2];
            dmaVif[6] = *(U64*)&self->faceBlends[4];
            dmaVif[7] = *(U64*)&self->faceBlends[6];
            dmaVif += 8;
            if (realBlendCount == 0 && blood128 == 0) {
                *dmaVif++ = (S64)(int)(PARTS[i].qwc + 0x30000000) + ((U64)(u_int)PARTS[i].part << 32);
                *dmaVif++ = 0;
                continue;
            }
            blendCount = self->faceBlendCount;
            patchCount = PARTS[i].patchCount;
            blends = PARTS[i].blends;
            patchPointer = ((patchCount + 31) >> 5) + 1;
            blend1flagPtr = blends + self->faceBlendNumbers[0] * patchPointer;
            blend2flagPtr = blends + self->faceBlendNumbers[1] * patchPointer;
            blend3flagPtr = blends + self->faceBlendNumbers[2] * patchPointer;
            blend4flagPtr = blends + self->faceBlendNumbers[3] * patchPointer;
            blend5flagPtr = blends + self->faceBlendNumbers[4] * patchPointer;
            blend6flagPtr = blends + self->faceBlendNumbers[5] * patchPointer;
            blend7flagPtr = blends + self->faceBlendNumbers[6] * patchPointer;
            blend8flagPtr = blends + self->faceBlendNumbers[7] * patchPointer;
            blendBase = (u_int)blends;
            blendBase <<= 32;
            blendBase += 0x30000002;
            blend1 = blendBase + ((U64)*blend1flagPtr++ << 32);
            blend2 = blendBase + ((U64)*blend2flagPtr++ << 32);
            blend3 = blendBase + ((U64)*blend3flagPtr++ << 32);
            blend4 = blendBase + ((U64)*blend4flagPtr++ << 32);
            blend5 = blendBase + ((U64)*blend5flagPtr++ << 32);
            blend6 = blendBase + ((U64)*blend6flagPtr++ << 32);
            blend7 = blendBase + ((U64)*blend7flagPtr++ << 32);
            blend8 = blendBase + ((U64)*blend8flagPtr++ << 32);
            refData = PARTS[i].Refs;
            refData++;
            refDataRef = (u_int)PARTS[i].part;
            blendEight = blendCount * 8;
            vifCode = 0x1000404 | ((U64)0x6E08C000 << 32);
            vifNull = (0x1000001 | ((U64)0x6200C024 << 32)) + (blendEight << 48) + (blendEight << 8);
            blendMask = 0;
            for (refCount = 0; refCount < patchCount; refCount++) {
                int refDataQwc;
                if (blood128) {
                    *dmaVif++ = bloodPtr;
                    bloodPtr += (U64)0x20 << 32;
                    *dmaVif++ = vifBlood;
                }
                if (blendCount) {
                    if (blendMask == 0) {
                        blend1flag = *blend1flagPtr++;
                        blend2flag = *blend2flagPtr++;
                        blend3flag = *blend3flagPtr++;
                        blend4flag = *blend4flagPtr++;
                        blend5flag = *blend5flagPtr++;
                        blend6flag = *blend6flagPtr++;
                        blend7flag = *blend7flagPtr++;
                        blend8flag = *blend8flagPtr++;
                        blendMask = 1;
                    }
                    dmaVif[0] = 0x10000001;
                    dmaVif[1] = 0x5000001;
                    dmaVif[2] = vifNull;
                    dmaVif[3] = 0x80808080 | ((U64)0x1000404 << 32);
                    dmaVif += 4;
                    if (blend1flag & blendMask) {
                        *dmaVif++ = blend1;
                        blend1 += (U64)0x20 << 32;
                        *dmaVif++ = vifCode + ((U64)0x24 << 32);
                    }
                    if (blendCount >= 2) {
                    if (blend2flag & blendMask) {
                        *dmaVif++ = blend2;
                        blend2 += (U64)0x20 << 32;
                        *dmaVif++ = vifCode + ((U64)0x2C << 32);
                    }
                    if (blendCount >= 3) {
                    if (blend3flag & blendMask) {
                        *dmaVif++ = blend3;
                        blend3 += (U64)0x20 << 32;
                        *dmaVif++ = vifCode + ((U64)0x34 << 32);
                    }
                    if (blendCount >= 4) {
                    if (blend4flag & blendMask) {
                        *dmaVif++ = blend4;
                        blend4 += (U64)0x20 << 32;
                        *dmaVif++ = vifCode + ((U64)0x3C << 32);
                    }
                    if (blendCount >= 5) {
                    if (blend5flag & blendMask) {
                        *dmaVif++ = blend5;
                        blend5 += (U64)0x20 << 32;
                        *dmaVif++ = vifCode + ((U64)0x44 << 32);
                    }
                    if (blendCount >= 6) {
                    if (blend6flag & blendMask) {
                        *dmaVif++ = blend6;
                        blend6 += (U64)0x20 << 32;
                        *dmaVif++ = vifCode + ((U64)0x4C << 32);
                    }
                    if (blendCount >= 7) {
                    if (blend7flag & blendMask) {
                        *dmaVif++ = blend7;
                        blend7 += (U64)0x20 << 32;
                        *dmaVif++ = vifCode + ((U64)0x54 << 32);
                    }
                    if (blendCount >= 8) {
                    if (blend8flag & blendMask) {
                        *dmaVif++ = blend8;
                        blend8 += (U64)0x20 << 32;
                        *dmaVif++ = vifCode + ((U64)0x5C << 32);
                    }
                    }
                    }
                    }
                    }
                    }
                    }
                    }
                }
                refDataQwc = refData[refCount].qwc;
                *dmaVif++ = (S64)(int)(refDataQwc + 0x30000000) + (refDataRef << 32);
                *dmaVif++ = 0x1000404 | ((U64)0x5000000 << 32);
                refDataQwc <<= 4;
                refDataRef += refDataQwc;
                blendMask <<= 1;
            }
        } else {
            u_int leftRight;
            u_int source;
            u_int dest;
            int isSource;
            int isDest;
            manRefs* refSource;
            U64 refSourceRef;
            U64 vifCode1;
            U64 vifCode2;
            U64 vifCode3;
            U64* mix;
            u_int patchCount;
            U64 sourceBlend;
            U64 destBlend;
            int refCount;
            U64 sourceQwc;
            if (PARTS[i].part == 0) continue;
            leftRight = partType - 1;
            source = self->hands[leftRight].source;
            dest = self->hands[leftRight].dest;
            isSource = self->hands[leftRight].sourceAmt != 0.0f;
            isDest = self->hands[leftRight].destAmt != 0.0f;
            if (!isSource && !isDest && !blood128) {
                dmaVif[0] = 0x10000002;
                dmaVif[1] = 0x1000404 | ((U64)0x6C028068 << 32);
                dmaVif[2] = SPAD->manTex0[i];
                dmaVif[3] = 0x20;
                dmaVif[4] = 0;
                dmaVif[5] = 0;
                dmaVif[6] = (S64)(int)(PARTS[i].qwc + 0x30000000) + ((U64)(u_int)PARTS[i].part << 32);
                dmaVif[7] = 0;
                dmaVif += 8;
                continue;
            }
            if (PARTS[i].blends == 0) continue;
            refSource = PARTS[i].Refs;
            refSource++;
            refSourceRef = (u_int)PARTS[i].part;
            vifCode3 = 0x5000001;
            vifCode1 = vifCode3 | ((U64)0x6A10C045 << 32);
            vifCode2 = vifCode3 | ((U64)0x6A10C055 << 32);
            mix = (U64*)&self->hands[partType - 1];
            dmaVif[0] = 0x10000002;
            dmaVif[1] = 0x1000404 | ((U64)0x6C028068 << 32);
            dmaVif[2] = SPAD->manTex0[i];
            dmaVif[3] = blood128 + 0x20;
            dmaVif[4] = 0;
            dmaVif[5] = *mix;
            dmaVif += 6;
            patchCount = PARTS[i].patchCount;
            sourceBlend = (u_int)PARTS[i].blends;
            sourceBlend += (u_int)(self->hands[leftRight].source * patchCount * 48);
            sourceBlend <<= 32;
            destBlend = (u_int)PARTS[i].blends;
            destBlend += (u_int)(self->hands[leftRight].dest * patchCount * 48);
            destBlend <<= 32;
            destBlend += 0x30000003;
            sourceBlend += 0x30000003;
            refCount = patchCount;
            while (refCount > 0) {
                if (blood128) {
                    *dmaVif++ = bloodPtr;
                    bloodPtr += (U64)0x20 << 32;
                    *dmaVif++ = vifBlood;
                }
                if (isSource) {
                    dmaVif[0] = sourceBlend;
                    dmaVif[1] = vifCode1;
                    dmaVif += 2;
                    sourceBlend += (U64)0x30 << 32;
                }
                if (isDest) {
                    dmaVif[0] = destBlend;
                    dmaVif[1] = vifCode2;
                    dmaVif += 2;
                    destBlend += (U64)0x30 << 32;
                }
                sourceQwc = refSource->qwc;
                dmaVif[0] = (refSourceRef << 32) + 0x30000000 + sourceQwc;
                dmaVif[1] = 0x5000000;
                dmaVif += 2;
                sourceQwc <<= 4;
                refSourceRef += sourceQwc;
                refSource++;
                refCount--;
            }
        }
    }
    return dmaVif;
}
