#include "types.h"

#pragma cplusplus on
typedef unsigned long long U64;
struct cMatrix { float m[4][4]; } __attribute__((aligned(16)));
struct cMatrixNxM { float m[4][3]; } __attribute__((aligned(16)));
struct cBoneRenderMatrices {
    cMatrix bone;
    cMatrixNxM lights;
} __attribute__((aligned(16)));
struct flagVect { unsigned int x; float y; unsigned int z; unsigned int w; };
struct shellRenderSPAD {
    cBoneRenderMatrices shells[16];
    __int128* part[16];
    unsigned short qwc[16];
    flagVect gflags;
    U64 tex0;
};
struct cMan {
    char pad0[0x2C12];
    signed char shellsEjected;
};

/* shell matrices quad copy loop (hand-written addi); GCC-style operands also put mwcc in the
   no-global-opt mode retail shows */
static inline void QMove(void* dd, void* ss, int nn) { int n = nn; __int128 q; void* s = ss; void* d = dd;
    __asm__ volatile(".set noreorder; 1: lq %0, 0(%2); addiu %1, %1, 0x10; addi %3, %3, -1; addiu %2, %2, 0x10; bgtz %3, 1b; sq %0, -0x10(%1); .set reorder" : "=&r"(q), "+r"(d), "+r"(s), "+r"(n) : : "memory");
}

extern "C" U64* cMan_ManDMAShells(cMan* self, U64* dmaVif, int transparency)
{
    shellRenderSPAD* SPAD2 = (shellRenderSPAD*)0x70000000;
    U64 backclip = 0;
    U64* gflags;
    int i;
    if (transparency != 128) backclip = 32;
    dmaVif[0] = 0x10000004;
    dmaVif[1] = 0x6C01007B00000000ULL | 0x15000000;
    gflags = (U64*)&SPAD2->gflags;
    dmaVif[2] = gflags[0];
    dmaVif[3] = gflags[1];
    dmaVif[4] = 0x6C01018000000000ULL | 0x01000404;
    dmaVif[5] = SPAD2->tex0;
    dmaVif[6] = backclip;
    dmaVif[7] = 0x6C0102F400000000ULL | 0x01000404;
    dmaVif[8] = SPAD2->tex0;
    dmaVif[9] = backclip;
    dmaVif += 10;
    for (i = 0; i < self->shellsEjected; i++) {
        dmaVif[0] = 0x10000007;
        dmaVif[1] = 0x6C07008500000000ULL | 0x15000000;
        QMove(&dmaVif[2], &SPAD2->shells[i], 7);
        dmaVif[16] = (long long)(int)(SPAD2->qwc[i] + 0x30000000) + ((U64)(unsigned int)SPAD2->part[i] << 32);
        dmaVif[17] = 0;
        dmaVif += 18;
    }
    return dmaVif;
}
