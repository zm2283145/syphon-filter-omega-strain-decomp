/* XLib::DrawDma (xdrawprim.cc). DMATAG3 packs the DMA tag with a CW asm volatile block; the GCC-style asm form misplaces the hoisted li 12/li 3. */
#pragma opt_rotateloops off
#pragma cplusplus on
#include "types.h"
enum eDmaTagIDs { _REFE, _CNT, _NEXT, _REF, _REFS, _CALL, _RET, _END };
struct cVector { float x, y, z, w; };
struct tIRGBA { int r, g, b, a; };
struct tXPrim { char p0[0x80]; int f80; int f84; char p88[0xB0 - 0x88]; unsigned long tag; unsigned long regs; };
struct tXPrimBuf { char p0[0x24]; tXPrim* prims; char p28[0x38 - 0x28]; };
struct XLib {
    char p0[8];
    unsigned long f8;
    char p10[0xFB0 - 0x10];
    tXPrimBuf bufs[2];
    int curBuf;
    char p1024[0x1030 - 0x1024];
    int f1030;
    int p1034;
    int f1038;
    int* f103C;
    int f1040;
    int p1044;
    int f1048;
};
extern "C" unsigned int D_00538080[];
extern "C" int D_005380F8[];
extern "C" int D_00538170;
extern "C" int D_005381C4;
extern "C" char D_00537F80[];
extern "C" int D_004932C0[];
extern "C" int D_004932E0[];
extern "C" void cDmaMan_InsertChain(void* dma, int ch, int start, int end);
extern "C" unsigned long* cDmaMan_BeginChain_eDmaChannel_int(void* dma, int ch, int qwc);
extern "C" void cDmaMan_EndChain_int_ulongP(void* dma, int ch, unsigned long* p);

inline unsigned long DMATAG3(int qwcnt, eDmaTagIDs tagid, int nxtaddr)
{
    unsigned long dmatag;
    unsigned long temp;
    asm volatile {
        dsll32 dmatag, nxtaddr, 0
        sll temp, tagid, 28
        or dmatag, dmatag, temp
        or dmatag, dmatag, qwcnt
    }
    return dmatag;
}

inline unsigned int GetMSCAL(int prog)
{
    return D_00538080[prog] | 0x14000000;
}

inline void NewProgBatch()
{
    D_005381C4 = 0;
}

inline void RequestProg(int prog)
{
    int p = D_005380F8[prog];
    if (p != D_00538170) {
        cDmaMan_InsertChain(D_00537F80, 1, D_004932C0[p], D_004932E0[p]);
        D_00538170 = p;
    }
    D_005381C4++;
}

inline unsigned long UNPACKV4(unsigned int addr, int num)
{
    unsigned int v = addr | 0x8000;
    return (unsigned long)(v | (num << 16) | 0x6C000000) << 32;
}

extern "C" void XLib_DrawDma(XLib* self, const cVector* verts, const tIRGBA* cols, const cVector* stqs, const cVector* norms, int elemSize, int prim, int reg, int nreg, unsigned int ucode)
{
    if (self->f1038 != 0) {
        NewProgBatch();
        RequestProg(ucode);
        tXPrimBuf& buf = self->bufs[self->curBuf];
        if (prim == 6 && nreg < 6) {
            for (int b = 1; b < self->f1038; b++) {
                unsigned int sidx = b + (self->f1030 - self->f1038);
                buf.prims[sidx].f80 = self->f1048 + self->f1048 - 1;
                buf.prims[sidx].f84 = self->f1048 - 1;
            }
        }
        long preg = prim;
        int maxDmaQwc = (elemSize + 2) * self->f1038;
        unsigned long* vif2 = cDmaMan_BeginChain_eDmaChannel_int(D_00537F80, 1, maxDmaQwc);
        for (int s = 0; s < self->f1038; s++) {
            unsigned int sidx = s + (self->f1030 - self->f1038);
            int nverts = self->f103C[sidx];
            if (nverts != 0) {
                buf.prims[sidx].tag = (unsigned long)nverts | 0x8000 | ((unsigned long)1 << 46) | ((unsigned long)(int)preg << 47) | ((unsigned long)nreg << 60);
                buf.prims[sidx].regs = self->f8 | reg;
                unsigned int addrOff = 0;
                *vif2++ = DMATAG3(12, _REF, (int)&buf.prims[sidx]);
                *vif2++ = UNPACKV4(addrOff, 12);
                addrOff += 12;
                *vif2++ = DMATAG3(nverts, _REF, (int)verts);
                *vif2++ = UNPACKV4(addrOff, nverts);
                addrOff += nverts;
                verts += nverts;
                if (cols) {
                    *vif2++ = DMATAG3(nverts, _REF, (int)cols);
                    *vif2++ = UNPACKV4(addrOff, nverts);
                    addrOff += nverts;
                    cols += nverts;
                }
                if (norms) {
                    *vif2++ = DMATAG3(nverts, _REF, (int)norms);
                    *vif2++ = UNPACKV4(addrOff, nverts);
                    addrOff += nverts;
                    norms += nverts;
                }
                if (stqs) {
                    *vif2++ = DMATAG3(nverts, _REF, (int)stqs);
                    *vif2++ = UNPACKV4(addrOff, nverts);
                    stqs += nverts;
                }
                *vif2++ = 0x10000000;
                *vif2++ = (unsigned long)GetMSCAL(ucode) << 32;
            }
        }
        cDmaMan_EndChain_int_ulongP(D_00537F80, 1, vif2);
    }
}

