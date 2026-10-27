typedef unsigned long u64;
typedef long s64;

typedef struct Rt37A9F0 { char p0[0x14]; } Rt37A9F0;

typedef struct GsCtx37A9F0 {
    unsigned int flags;   /* 0x00 */
    char p4[0x18];
    unsigned int w;       /* 0x1C */
    unsigned int h;       /* 0x20 */
    char p24[0x8];
    unsigned int psm;     /* 0x2C */
    unsigned int zpsm;    /* 0x30 */
    char p34[0x30];
    unsigned char field;  /* 0x64 */
    char p65[0x2B];
    u64 frame;            /* 0x90 */
    u64 frame2;           /* 0x98 */
    u64 zbuf;             /* 0xA0 */
    u64 xyoffset;         /* 0xA8 */
    char pB0[0x20];
    unsigned char dirty;  /* 0xD0 */
    char pD1[0x27];
    unsigned int fbmsk;   /* 0xF8 */
    unsigned int zmsk;    /* 0xFC */
    char p100[0x2C];
    unsigned int fbp[2];  /* 0x12C */
    unsigned int zbp;     /* 0x134 */
    char p138[0x8];
    int buf;              /* 0x140 */
    char p144[0x8C];
    int clear0;           /* 0x1D0 */
    int clear1;           /* 0x1D4 */
    int frames;           /* 0x1D8 */
    char p1DC[0x4];
    float dt;             /* 0x1E0 */
    unsigned int maxRate; /* 0x1E4 */
    float rate;           /* 0x1E8 */
    char p1EC[0xA70 - 0x1EC];
    int slot;             /* 0xA70 */
    char pA74[0x1058 - 0xA74];
    int dev;              /* 0x1058 */
    void* listeners;      /* 0x105C */
    char p1060[0x8];
    Rt37A9F0 rt[6];       /* 0x1068 */
} GsCtx37A9F0;

extern void XLib_NextFrameSlave(GsCtx37A9F0*);
extern void cUserFrameEnv_ReleaseVram(Rt37A9F0*);
extern void XLib_ClearActiveBuffer(GsCtx37A9F0*, int, int, int*, int, int);
extern void XLib_DisplayLastFrame(GsCtx37A9F0*);
extern void cTexMan_TermTextureStream(int);
extern void cDmaMan_NextFrame(void*);
extern void XLib_DeferDeleteDmaData(GsCtx37A9F0*, int);
extern void XLib_NextPrimFrame(GsCtx37A9F0*);
extern void XLib_ClearScreen_void(GsCtx37A9F0*);
extern void cAnimTexMan_NextFrame(void*, float);
extern void cTexMan_StartFrame(int);
extern char D_00537F80[];
extern int g_TimerAccum;
extern s64 g_TickCounter64;

#define GS_CSR (*(volatile u64*)0x12001000)
#define T0_COUNT (*(volatile int*)0x10000800)
#define GS_FRAME(fbp, fbw, psm, fbmsk) ((u64)(fbp) | ((u64)(fbw) << 16) | ((u64)(psm) << 24) | ((u64)(fbmsk) << 32))
#define GS_ZBUF(zbp, psm, zmsk) ((u64)(zbp) | ((u64)(psm) << 24) | ((u64)(zmsk) << 32))
#define GS_XYOFFSET(ofx, ofy) ((u64)(ofx) | ((u64)(ofy) << 32))

static inline void GsCtx_SetBufferRegs(GsCtx37A9F0* c, unsigned int w, unsigned int h, unsigned int psm, unsigned int fbp, unsigned int fbmsk, unsigned int zpsm, unsigned int zbp, unsigned int zmsk, unsigned char field)
{
    unsigned int ofx;
    unsigned int ofy;
    ofx = (0x800 - (w >> 1)) << 4;
    ofy = (0x800 - (h >> 1)) << 4;
    if (field) {
        ofy += (unsigned char)!(int)((GS_CSR >> 13) & 1) << 3;
    }
    c->frame = GS_FRAME(fbp, w >> 6, psm, fbmsk);
    c->frame2 = GS_FRAME(fbp, w >> 6, psm, 0xFFFFFF);
    c->zbuf = GS_ZBUF(zbp, zpsm, zmsk);
    c->xyoffset = GS_XYOFFSET(ofx, ofy);
    c->dirty = 1;
}

void XLib_NextFrame(GsCtx37A9F0* c)
{
    int i;
    unsigned int t;
    if (c->flags & 8) {
        XLib_NextFrameSlave(c);
        return;
    }
    for (i = 0; i < 6; i++) {
        cUserFrameEnv_ReleaseVram(&c->rt[i]);
    }
    if (c->clear0) {
        int col[4];
        col[3] = c->clear0;
        col[0] = 0x80;
        col[1] = 0x80;
        col[2] = 0x80;
        XLib_ClearActiveBuffer(c, c->w, c->h, col, 0, 2);
    }
    if (c->clear1) {
        int col[4];
        col[3] = c->clear1;
        col[0] = 0x80;
        col[1] = 0x80;
        col[2] = 0x80;
        XLib_ClearActiveBuffer(c, c->w, c->h, col, 0, 3);
    }
    while ((*(volatile int*)0x10009000 & 0x100) || (*(volatile int*)0x10003C00 & 3) ||
           (*(volatile int*)0x10003C00 & 0x1F000000))
        ;
    while ((*(volatile int*)0x1000A000 & 0x100) || (*(volatile int*)0x10003020 & 0xC00))
        ;
    if (c->frames > 1) {
        unsigned char waited;
        c->rate = 576000.0f / (float)(int)(T0_COUNT + g_TimerAccum);
        waited = 0;
        if (c->maxRate) {
            while (576000.0f / (float)(int)(T0_COUNT + g_TimerAccum) > (float)c->maxRate) {
                waited = 1;
                GS_CSR = 8;
                while (!(GS_CSR & 8))
                    ;
            }
        }
        if ((c->clear0 || c->clear1) && !waited) {
            GS_CSR = 8;
            while (!(GS_CSR & 8))
                ;
        }
        c->dt = (float)(int)(T0_COUNT + g_TimerAccum) / 576000.0f;
        t = T0_COUNT + g_TimerAccum;
        g_TickCounter64 += (int)((float)t / 5.76f);
        T0_COUNT = 0;
        *(volatile int*)0x10000810 = 0x82;
        g_TimerAccum = 0;
        XLib_DisplayLastFrame(c);
    } else {
        t = T0_COUNT + g_TimerAccum;
        g_TickCounter64 += (int)((float)t / 5.76f);
        T0_COUNT = 0;
        *(volatile int*)0x10000810 = 0x82;
        g_TimerAccum = 0;
    }
    cTexMan_TermTextureStream(c->dev);
    cDmaMan_NextFrame(D_00537F80);
    XLib_DeferDeleteDmaData(c, 0);
    XLib_NextPrimFrame(c);
    c->buf ^= 1;
    c->frames++;
    GsCtx_SetBufferRegs(c, c->w, c->h, c->psm, c->fbp[c->buf], c->fbmsk, c->zpsm, c->zbp, c->zmsk, c->field);
    ((unsigned char*)c)[c->slot * 0x110 + 0x2F6] = 1;
    XLib_ClearScreen_void(c);
    cAnimTexMan_NextFrame(c->listeners, c->dt);
    cTexMan_StartFrame(c->dev);
}
