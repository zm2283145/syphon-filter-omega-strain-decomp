#pragma cplusplus on
#include "types.h"
typedef unsigned long u_long;

class cVector {
public:
    float x, y, z, w;
    cVector() {}
    cVector(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    cVector& operator=(const cVector& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));

class cMatrix {
public:
    float m[4][4];
    void Identity() { void* xx = this; int t; __asm__ volatile("sqc2 vf0, 0x30(%1); qmfc2.ni %0, vf0; pcpyud %0, %0, zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(this) : "memory"); }
} __attribute__((aligned(16)));

struct tIRGBA { int r, g, b, a; };
struct tRGBA { float r, g, b, a; };
struct tRECT { float x, y, w, h; };

struct tScrEnv {
    int width, height, depth, buffWidth, buffHeight, buffDepth, buffZDepth, psm, zpsm;
    float zmin, zmax, xoff, yoff, xscl, yscl, buffScaleX, buffScaleY, buffOffsetX, buffOffsetY, orthoScaleX, orthoScaleY;
    unsigned char ishalf;
    float gbScaleX[4];
    float gbScaleY[4];
    int gbScaleNum;
    u_long frame1, frame2, zbuf, xyoffset, scissor, dthe, dimx, bgColor;
    unsigned char frameEnvChanged;
};

struct tPixelEnv {
    unsigned int ate, atst, aref, afail, date, datm, zte, ztst, fbmsk, zmsk, iip, tme, fge, abe, aa1, fst, ctxt, fix, prmodecont, colClamp, texClamp;
};

struct tVramMap { int frameBuffAddr[2]; int zBuffAddr; int frameFxBuffAddr; int txtrBuffAddr; int currFrameBuf; };

struct tFogEnv {
    float min, max, near, far;
    tIRGBA color;
    tRGBA colorf;
    float aval;
    float bval __attribute__((aligned(16)));
    cVector coeff, tnear, tfar;
};

struct cXViewport {
    tRECT win;
    cMatrix orthoMat, perspMat;
    cVector scale, offset, orthoClipMin, orthoClipMax, perspClipMin, perspClipMax;
    float ominz, pminz, omaxz, pmaxz, fov;
    unsigned char isOrtho, isOnScreen, isDirty;
    u_long scissorReg;
};

struct tVU1InputBuffHeader {
    cVector drawParms[2];
    u_long ctxtGifTag[2];
    u_long ctxt[6];
    cVector minPt, maxPt;
    int adcInds[12];
    u_long inputGifTag[2];
};

struct tXPrimBuf {
    char* vertsMem; char* normsMem; char* colsMem; char* stqsMem; char* stripsMem;
    cVector* frameVerts; cVector* frameNorms; tIRGBA* frameCols; cVector* frameSTQs; tVU1InputBuffHeader* frameStrips;
    cVector* batchVerts; cVector* batchNorms; tIRGBA* batchCols; cVector* batchSTQs;
};

struct cUserFrameEnv { int fbuffTID, zbuffTID; unsigned int fpsm, zpsm; unsigned char isZBuff; };
struct cTexMan;
struct cAnimTexMan;
struct cLList { int a, b, c; };

struct XLib {
    unsigned int displayFlags;
    u_long gifTagFlags;
    tScrEnv screen;
    tPixelEnv pixenv;
    tVramMap vram;
    tFogEnv fog;
    unsigned int gammaVal, blackVal;
    int frame, timerHID;
    float frameTime;
    unsigned int frameRateCap;
    float fps;
    cXViewport viewportStack[8];
    int viewportNum, viewNum;
    unsigned char compMatDirty;
    cMatrix viewStack[16];
    cMatrix flipMat, compMat, compMatNoGB, unitMat;
    tRECT fullscreenViewport;
    float defaultAspectRatio, aspectRatio;
    cVector lookatVec;
    tXPrimBuf primBuf[2];
    unsigned int currPrimBuf;
    int maxFrameVerts, maxFrameStrips, numFrameVerts, numFrameStrips, numBatchVerts, numBatchStrips;
    int* numStripVerts;
    int currStripVerts, currStripBreaks, batchElemSize, maxStripVerts, maxUsedFrameVerts, maxUsedFrameStrips;
    cTexMan* texMan;
    cAnimTexMan* animTexMan;
    int activeTID, userEnv;
    cUserFrameEnv userFrameEnvs[6];
    unsigned int context, lastContext;
    u_long alphaReg;
    cVector colOff;
    int scrBlendTID, scrBlendAlpha;
    cLList dmaDelDataList;
};

extern "C" {
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
extern char D_004BC200[];
extern char D_004BC208[], D_004BC218[], D_004BC228[], D_004BC238[], D_004BC248[], D_004BC258[];
extern u_long D_004BC1B0;
void Renderer_Teardown(XLib* x);
void sceGsResetPath(void);
void sceGsResetGraph(short mode, short inter, short omode, short ffmode);
void FlushCache(int);
int sceGsSyncV(int);
int sceGsSyncPath(int, int);
void XLib_InitScreenSpace(XLib* x);
void XLib_CalcVramAddrs(XLib* x);
void Alloc_Lock(int);
void EnableIntc(int);
void* cMemMan_Allocate(int, unsigned int, char*, int);
cTexMan* cTexMan_ctor(void*, int, int);
cAnimTexMan* cAnimTexMan_ctor(void*);
void cUserFrameEnv_Init(cUserFrameEnv*, char*, int, int, int, int);
void* memset(void*, int, unsigned int);
void XLib_NextPrimFrame(XLib* x);
void XLib_ClearVram(XLib* x, int, int, int, int);
}

static inline void* XNew(unsigned int sz, int line)
{
    void* p;
    if (g_ProfileLockEnabled) Alloc_Lock(9);
    g_ProfileLockDepth++;
    p = cMemMan_Allocate(0, sz, D_004BC200, line);
    if (g_ProfileLockEnabled) EnableIntc(9);
    g_ProfileLockDepth--;
    return p;
}

static inline void SetFogColor(XLib* self, const tRGBA& c)
{
    self->fog.colorf.r = c.r * 256.0f;
    self->fog.colorf.g = c.g * 256.0f;
    self->fog.colorf.b = c.b * 256.0f;
    self->fog.colorf.a = 256.0f;
    self->fog.color.r = (int)self->fog.colorf.r;
    self->fog.color.g = (int)self->fog.colorf.g;
    self->fog.color.b = (int)self->fog.colorf.b;
    self->fog.color.a = 0x80;
}

static inline void SetBGColor(XLib* self, float r, float g, float b)
{
    self->screen.bgColor = (u_long)(long)(int)r | ((u_long)(long)(int)g << 8) | ((u_long)(long)(int)b << 16) | ((u_long)0x3F800000 << 32);
}

static inline void SetBuffers(XLib* self, unsigned int fbp, unsigned int fbw, unsigned int fbh, unsigned int psm, unsigned int fbmsk, unsigned int zbp, unsigned int zpsm, unsigned int zmsk, unsigned char half)
{
    unsigned int xoff = (2048 - (fbw >> 1)) << 4;
    unsigned int yoff = (2048 - (fbh >> 1)) << 4;
    if (half)
        yoff += (unsigned char)!(int)((*(volatile u_long*)0x12001000 >> 13) & 1) << 3;
    self->screen.frame1 = (u_long)fbp | ((u_long)(fbw >> 6) << 16) | ((u_long)psm << 24) | ((u_long)fbmsk << 32);
    self->screen.frame2 = (u_long)fbp | ((u_long)(fbw >> 6) << 16) | ((u_long)psm << 24) | ((u_long)0xFFFFFF << 32);
    self->screen.zbuf = (u_long)zbp | ((u_long)zpsm << 24) | ((u_long)zmsk << 32);
    self->screen.xyoffset = (u_long)xoff | ((u_long)yoff << 32);
}

extern "C" void XLib_Init(XLib* self, int scrWidth, int scrHeight, int scrDepth, int zDepth,
               unsigned int modeFlags, int maxVerts, int maxStrips)
{
    int dimx[16];
    unsigned int kVertBuffByteSize;
    unsigned int kStripBuffByteSize;
    int b;
    int s;
    int i;

    if (self->displayFlags != -1)
        Renderer_Teardown(self);
    self->displayFlags = modeFlags;
    self->screen.width = scrWidth;
    self->screen.height = scrHeight;
    self->screen.depth = scrDepth;
    self->screen.buffWidth = scrWidth;
    self->screen.buffHeight = (self->displayFlags & 1) ? scrHeight / 2 : scrHeight;
    self->screen.buffDepth = scrDepth;
    self->screen.buffZDepth = zDepth;
    self->screen.ishalf = (self->displayFlags & 1) != 0;
    if (scrDepth == 16)
        self->screen.psm = (scrDepth == zDepth) ? 2 : 10;
    else if (scrDepth == 24)
        self->screen.psm = 1;
    else
        self->screen.psm = 0;
    if (zDepth == 16) {
        self->screen.zpsm = (zDepth == scrDepth) ? 50 : 58;
        self->screen.zmin = 0.0f;
        self->screen.zmax = 65535.0f;
    } else if (zDepth == 24) {
        self->screen.zpsm = 49;
        self->screen.zmin = 0.0f;
        self->screen.zmax = 16777215.0f;
    } else {
        self->screen.zpsm = 48;
        self->screen.zmin = 0.0f;
        self->screen.zmax = 4294967296.0f;
    }
    self->screen.gbScaleNum = 0;
    self->screen.gbScaleX[self->screen.gbScaleNum] = 4095.0f / (float)self->screen.buffWidth;
    self->screen.gbScaleY[self->screen.gbScaleNum] = 4095.0f / (float)self->screen.buffHeight;
    self->viewportStack[self->viewportNum].isDirty = 1;
    sceGsResetPath();
    if (self->displayFlags & 4)
        sceGsResetGraph(0, 0, 0x50, 1);
    else if (self->displayFlags & 2)
        sceGsResetGraph(0, 1, 3, 1);
    else
        sceGsResetGraph(0, 1, 2, 1);
    FlushCache(0);
    while (!sceGsSyncV(0)) ;
    sceGsSyncPath(0, 0);
    self->viewportNum = 0;
    self->viewStack[0].Identity();
    self->viewNum = 0;
    self->compMat.Identity();
    self->unitMat.Identity();
    self->compMatDirty = 1;
    self->lookatVec = cVector(0.0f, 0.0f, 0.0f, 0.0f);
    XLib_InitScreenSpace(self);
    SetBuffers(self, self->vram.frameBuffAddr[self->vram.currFrameBuf], self->screen.buffWidth, self->screen.buffHeight, self->screen.psm, self->pixenv.fbmsk, self->vram.zBuffAddr, self->screen.zpsm, self->pixenv.zmsk, self->screen.ishalf);
    self->screen.frameEnvChanged = 1;
    self->viewportStack[self->viewportNum].isDirty = 1;
    self->flipMat.m[0][0] = 1.0f; self->flipMat.m[1][0] = 0.0f; self->flipMat.m[2][0] = 0.0f; self->flipMat.m[3][0] = 0.0f;
    self->flipMat.m[0][1] = 0.0f; self->flipMat.m[1][1] = 0.0f; self->flipMat.m[2][1] = 1.0f; self->flipMat.m[3][1] = 0.0f;
    self->flipMat.m[0][2] = 0.0f; self->flipMat.m[1][2] = 1.0f; self->flipMat.m[2][2] = 0.0f; self->flipMat.m[3][2] = 0.0f;
    self->flipMat.m[0][3] = 0.0f; self->flipMat.m[1][3] = 0.0f; self->flipMat.m[2][3] = 0.0f; self->flipMat.m[3][3] = 1.0f;
    XLib_CalcVramAddrs(self);
    {
        void* p = XNew(0x494, 0x14B);
        if (p) p = cTexMan_ctor(p, self->vram.txtrBuffAddr, 0x800);
        self->texMan = (cTexMan*)p;
    }
    {
        void* p = XNew(0x14, 0x14D);
        if (p) p = cAnimTexMan_ctor(p);
        self->animTexMan = (cAnimTexMan*)p;
    }
    if (!(self->displayFlags & 8)) {
        cUserFrameEnv_Init(&self->userFrameEnvs[0], D_004BC208, 0x80, 0x80, 0x20, 0x10);
        cUserFrameEnv_Init(&self->userFrameEnvs[1], D_004BC218, 0x80, 0x80, 0x20, 0x10);
        cUserFrameEnv_Init(&self->userFrameEnvs[2], D_004BC228, 0x80, 0x80, 0x20, 0x10);
        cUserFrameEnv_Init(&self->userFrameEnvs[3], D_004BC238, 0x80, 0x80, 0x20, 0x10);
        cUserFrameEnv_Init(&self->userFrameEnvs[4], D_004BC248, 0x80, 0x80, 0x20, 0x10);
        cUserFrameEnv_Init(&self->userFrameEnvs[5], D_004BC258, 0x100, 0x100, self->screen.buffDepth, 0);
    }
    self->userEnv = -1;
    self->context = 0;
    self->lastContext = 0;
    self->pixenv.ate = 1;
    self->pixenv.atst = 6;
    self->pixenv.aref = 0;
    self->pixenv.afail = 0;
    self->pixenv.date = 0;
    self->pixenv.datm = 0;
    self->pixenv.zte = 1;
    self->pixenv.ztst = 2;
    self->pixenv.fbmsk = 0xFF000000;
    self->pixenv.zmsk = 0;
    self->pixenv.iip = 1;
    self->pixenv.tme = 1;
    self->pixenv.fge = 0;
    self->pixenv.abe = 1;
    self->pixenv.aa1 = 0;
    self->pixenv.fst = 0;
    self->pixenv.ctxt = 0;
    self->pixenv.fix = 0;
    self->pixenv.prmodecont = 0;
    self->pixenv.colClamp = 1;
    self->pixenv.texClamp = 0;
    self->alphaReg = D_004BC1B0;
    { tRGBA c = {0.0f, 0.0f, 0.0f, 1.0f}; SetFogColor(self, c); }
    {
        char* d = (char*)dimx;
        int n = 64;
        if (d) do { *d++ = 0; } while (--n);
    }
    self->screen.dthe = 0;
    self->screen.frameEnvChanged = 1;
    self->frame = 0;
    self->activeTID = -1;
    self->scrBlendTID = -1;
    self->gammaVal = 0;
    self->blackVal = 0;
    self->frameRateCap = 60;
    self->fps = 0;
    if (maxVerts == -1) maxVerts = 3500;
    if (maxStrips == -1) maxStrips = 350;
    self->maxFrameVerts = maxVerts;
    self->maxFrameStrips = maxStrips;
    kVertBuffByteSize = self->maxFrameVerts * sizeof(cVector) + 16;
    kStripBuffByteSize = self->maxFrameStrips * sizeof(tVU1InputBuffHeader) + 16;
    for (b = 0; b < 2; b++) {
        tXPrimBuf& buf = self->primBuf[b];
        buf.vertsMem = (char*)XNew(kVertBuffByteSize, 0x1A8);
        memset(buf.vertsMem, 0, kVertBuffByteSize);
        buf.normsMem = 0;
        buf.colsMem = (char*)XNew(kVertBuffByteSize, 0x1AE);
        memset(buf.colsMem, 0, kVertBuffByteSize);
        buf.stqsMem = (char*)XNew(kVertBuffByteSize, 0x1AF);
        memset(buf.stqsMem, 0, kVertBuffByteSize);
        buf.stripsMem = (char*)XNew(kStripBuffByteSize, 0x1B0);
        memset(buf.stripsMem, 0, kStripBuffByteSize);
        buf.frameVerts = (cVector*)(((unsigned int)buf.vertsMem + 15) & ~15);
        buf.frameNorms = 0;
        buf.frameCols = (tIRGBA*)(((unsigned int)buf.colsMem + 15) & ~15);
        buf.frameSTQs = (cVector*)(((unsigned int)buf.stqsMem + 15) & ~15);
        buf.frameStrips = (tVU1InputBuffHeader*)(((unsigned int)buf.stripsMem + 15) & ~15);
        for (s = 0; s < self->maxFrameStrips; s++) {
            buf.frameStrips[s].drawParms[0] = cVector(0.0f, 0.0f, 0.0f, 0.0f);
            buf.frameStrips[s].drawParms[1] = cVector(0.0f, 0.0f, 0.0f, 0.0f);
            buf.frameStrips[s].ctxtGifTag[0] = 3 | ((u_long)1 << 60);
            buf.frameStrips[s].ctxtGifTag[1] = 0xE;
            buf.frameStrips[s].ctxt[0] = 0;
            buf.frameStrips[s].ctxt[1] = 0x7F;
            buf.frameStrips[s].ctxt[2] = 0;
            buf.frameStrips[s].ctxt[3] = 0x7F;
            buf.frameStrips[s].ctxt[4] = 0;
            buf.frameStrips[s].ctxt[5] = 0x7F;
            buf.frameStrips[s].minPt = cVector(0.0f, 0.0f, 0.0f, 0.0f);
            buf.frameStrips[s].maxPt = cVector(0.0f, 0.0f, 0.0f, 0.0f);
            for (i = 0; i < 12; i++)
                buf.frameStrips[s].adcInds[i] = 0;
            buf.frameStrips[s].inputGifTag[0] = (u_long)1 << 60;
            buf.frameStrips[s].inputGifTag[1] = 0xE;
        }
    }
    self->numStripVerts = (int*)XNew(self->maxFrameStrips * sizeof(int), 0x1D0);
    self->currPrimBuf = 0;
    self->maxUsedFrameVerts = 0;
    self->maxUsedFrameStrips = 0;
    XLib_NextPrimFrame(self);
    XLib_NextPrimFrame(self);
    self->alphaReg = D_004BC1B0;
    SetBGColor(self, 0.0f, 0.0f, 0.0f);
    self->frameTime = 0.0f;
    if (!(self->displayFlags & 8)) {
        XLib_ClearVram(self, 0, 0, 0, 0x80);
        *(volatile unsigned int*)0x10003820 = 6;
        *(volatile unsigned int*)0x10003C20 = 6;
    }
}
