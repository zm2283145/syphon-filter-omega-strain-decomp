typedef unsigned long u64;
typedef long s64;

typedef struct GsCtx37A750 {
    char p0[0x1C];
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
    char p144[0x94];
    int frames;           /* 0x1D8 */
    char p1DC[0xA70 - 0x1DC];
    int slot;             /* 0xA70 */
    char pA74[0x1058 - 0xA74];
    int dev;              /* 0x1058 */
} GsCtx37A750;

typedef struct Slot37A750 { char p0[0x110]; } Slot37A750;

extern void func_00382060(int);
extern void func_00375650(void*);
extern void func_0037B0C0(GsCtx37A750*, int);
extern void func_0037B000(GsCtx37A750*);
extern void func_003820C0(int);
extern char D_00537F80[];
extern int D_00533870;
extern s64 D_00533878;

#define GS_FRAME(fbp, fbw, psm, fbmsk) ((u64)(fbp) | ((u64)(fbw) << 16) | ((u64)(psm) << 24) | ((u64)(fbmsk) << 32))
#define GS_ZBUF(zbp, psm, zmsk) ((u64)(zbp) | ((u64)(psm) << 24) | ((u64)(zmsk) << 32))
#define GS_XYOFFSET(ofx, ofy) ((u64)(ofx) | ((u64)(ofy) << 32))

static inline void GsCtx_SetBufferRegs(GsCtx37A750* c, unsigned int w, unsigned int h, unsigned int psm, unsigned int fbp, unsigned int fbmsk, unsigned int zpsm, unsigned int zbp, unsigned int zmsk, unsigned char field)
{
    unsigned int ofx;
    unsigned int ofy;
    ofx = (0x800 - (w >> 1)) << 4;
    ofy = (0x800 - (h >> 1)) << 4;
    if (field) {
        ofy += (unsigned char)!(int)((*(volatile u64*)0x12001000 >> 13) & 1) << 3;
    }
    c->frame = GS_FRAME(fbp, w >> 6, psm, fbmsk);
    c->frame2 = GS_FRAME(fbp, w >> 6, psm, 0xFFFFFF);
    c->zbuf = GS_ZBUF(zbp, zpsm, zmsk);
    c->xyoffset = GS_XYOFFSET(ofx, ofy);
    c->dirty = 1;
}
void func_0037A750(GsCtx37A750* c)
{
    unsigned int t;
    while ((*(volatile int*)0x10009000 & 0x100) || (*(volatile int*)0x10003C00 & 3) ||
           (*(volatile int*)0x10003C00 & 0x1F000000))
        ;
    while ((*(volatile int*)0x1000A000 & 0x100) || (*(volatile int*)0x10003020 & 0xC00))
        ;
    func_00382060(c->dev);
    func_00375650(D_00537F80);
    func_0037B0C0(c, 0);
    c->buf ^= 1;
    func_0037B000(c);
    c->frames++;
    GsCtx_SetBufferRegs(c, c->w, c->h, c->psm, c->fbp[c->buf], c->fbmsk, c->zpsm, c->zbp, c->zmsk, c->field);
    ((unsigned char*)c)[c->slot * 0x110 + 0x2F6] = 1;
    func_003820C0(c->dev);
    t = *(volatile int*)0x10000800 + D_00533870;
    D_00533878 += (int)((float)t / 5.76f);
    *(volatile int*)0x10000800 = 0;
    *(volatile int*)0x10000810 = 0x82;
    D_00533870 = 0;
}

