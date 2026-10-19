/*
 * lib/libgraph: 5 files, 00103228-00103710
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00103228 */
typedef unsigned long u_long __attribute__((mode(DI)));
typedef unsigned int u_int;
typedef unsigned char u_char;

typedef struct {
    u_long testa;
    u_long testaaddr;
    u_long prim;
    u_long primaddr;
    u_long rgbaq;
    u_long rgbaqaddr;
    u_long xyz2a;
    u_long xyz2aaddr;
    u_long xyz2b;
    u_long xyz2baddr;
    u_long testb;
    u_long testbaddr;
} sceGsClear;

#define SCE_GS_SET_TEST(ate, atst, aref, afail, date, datm, zte, ztst) \
    ((u_long)(ate) | ((u_long)(atst) << 1) | ((u_long)(aref) << 4) | \
     ((u_long)(afail) << 12) | ((u_long)(date) << 14) | ((u_long)(datm) << 15) | \
     ((u_long)(zte) << 16) | ((u_long)(ztst) << 17))
#define SCE_GS_SET_PRIM(prim, iip, tme, fge, abe, aa1, fst, ctxt, fix) \
    ((u_long)(prim) | ((u_long)(iip) << 3) | ((u_long)(tme) << 4) | \
     ((u_long)(fge) << 5) | ((u_long)(abe) << 6) | ((u_long)(aa1) << 7) | \
     ((u_long)(fst) << 8) | ((u_long)(ctxt) << 9) | ((u_long)(fix) << 10))
#define SCE_GS_SET_RGBAQ(r, g, b, a, q) \
    ((u_long)(r) | ((u_long)(g) << 8) | ((u_long)(b) << 16) | \
     ((u_long)(a) << 24) | ((u_long)(q) << 32))
#define SCE_GS_SET_XYZ(x, y, z) \
    ((u_long)(x) | ((u_long)(y) << 16) | ((u_long)(z) << 32))

int func_00103228(sceGsClear *cp, short ztest, short x, short y, short w, short h,
                  u_char r, u_char g, u_char b, u_char a, u_int z)
{
    cp->testaaddr = 0x47;
    cp->testa = SCE_GS_SET_TEST(0, 0, 0, 0, 0, 0, 1, 1);
    cp->primaddr = 0;
    cp->prim = SCE_GS_SET_PRIM(6, 0, 0, 0, 0, 0, 0, 0, 0);
    cp->rgbaqaddr = 1;
    cp->rgbaq = SCE_GS_SET_RGBAQ(r, g, b, a, 0x3f800000);
    cp->xyz2aaddr = 5;
    cp->xyz2a = SCE_GS_SET_XYZ(x << 4, y << 4, z);
    cp->xyz2baddr = 5;
    cp->xyz2b = SCE_GS_SET_XYZ((x + w) << 4, (y + h) << 4, z);
    cp->testbaddr = 0x47;
    if (ztest)
        cp->testb = SCE_GS_SET_TEST(0, 0, 0, 0, 0, 0, 1, ztest & 3);
    else
        cp->testb = SCE_GS_SET_TEST(0, 0, 0, 0, 0, 0, 1, 1);
    __asm__ __volatile__("sync");
    return sizeof(sceGsClear) / 16;
}
/* merge_units: end func_00103228 */

/* merge_units: begin func_00103330 */
extern int scePrintf(const char *, ...);

int sceGsPutDrawEnv(unsigned long *tag)
{
    unsigned int i = 0;
    while (*(volatile int *)0x1000A000 & 0x100) {
        if (i++ > 0x1000000) {
            scePrintf("sceGsPutDrawEnv: DMA Ch.2 does not terminate\r\n");
            return -1;
        }
    }
    *(volatile int *)0x1000A020 = (int)(tag[0] & 0x7FFF) + 1;
    if (((unsigned int)tag & 0x70000000) == 0x70000000)
        *(volatile unsigned int *)0x1000A010 = ((unsigned int)tag & 0x0FFFFFFF) | 0x80000000;
    else
        *(volatile unsigned int *)0x1000A010 = (unsigned int)tag & 0x0FFFFFFF;
    *(volatile int *)0x1000A000 = 0x101;
    return 0;
}
/* merge_units: end func_00103330 */

/* merge_units: begin func_00103418 */
typedef int u_long128 __attribute__((mode(TI)));

typedef struct { u_long FBP:9; u_long FBW:6; u_long PSM:5; u_long pad:12; u_long DBX:11; u_long DBY:11; u_long pad2:10; } sceGsDispfb;
typedef struct { u_long FBP:9; u_long pad:7; u_long FBW:6; u_long pad2:2; u_long PSM:6; u_long pad3:2; u_long FBMSK:32; } sceGsFrame;

typedef struct {
    u_long pmode;
    u_long smode2;
    sceGsDispfb dispfb;
    u_long display;
    u_long bgcolor;
} sceGsDispEnv;

typedef struct {
    u_long NLOOP:15;
    u_long EOP:1;
    u_long pad16:16;
    u_long id:14;
    u_long PRE:1;
    u_long PRIM:11;
    u_long FLG:2;
    u_long NREG:4;
    u_long REGS0:4;
    u_long REGS1:4;
    u_long REGS2:4;
    u_long REGS3:4;
    u_long REGS4:4;
    u_long REGS5:4;
    u_long REGS6:4;
    u_long REGS7:4;
    u_long REGS8:4;
    u_long REGS9:4;
    u_long REGS10:4;
    u_long REGS11:4;
    u_long REGS12:4;
    u_long REGS13:4;
    u_long REGS14:4;
    u_long REGS15:4;
} sceGifTag __attribute__((aligned(16)));

typedef struct {
    sceGsFrame frame1;
    u_long rest[15];
} sceGsDrawEnv1;

typedef struct {
    u_long d[12];
} sceGsClear_00103418;

typedef struct {
    sceGsDispEnv disp[2];
    sceGifTag giftag0;
    sceGsDrawEnv1 draw0;
    sceGsClear_00103418 clear0;
    sceGifTag giftag1;
    sceGsDrawEnv1 draw1;
    sceGsClear_00103418 clear1;
} sceGsDBuffDc;

typedef struct { short sceGsInterMode; short sceGsOutMode; short sceGsFFMode; short sceGsVersion; } sceGsGParam;

extern sceGsGParam *sceGsGetGParam(void);
extern void sceGsSetDefDispEnv(sceGsDispEnv *disp, short psm, short w, short h, short dx, short dy);
extern int func_00103040(sceGsDrawEnv1 *draw, short psm, short w, short h, short ztest, short zpsm);
#if 0 /* merge_units */
extern int func_00103228(sceGsClear_00103418 *cp, short ztest, short x, short y, short w, short h,
                         unsigned char r, unsigned char g, unsigned char b, unsigned char a, unsigned int z);
#endif /* merge_units */
#define func_00103228(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10) (func_00103228((sceGsClear *)(a0), (a1), (a2), (a3), (a4), (a5), (u_char)(a6), (u_char)(a7), (u_char)(a8), (u_char)(a9), (u_int)(a10))) /* merge_units */

extern int func_00102F78(short psm, short w, short h);

void func_00103418(sceGsDBuffDc *db, short psm, short w, short h, short ztest, short zpsm, short clear)
{
    sceGsGParam *gp = sceGsGetGParam();
        int zbp;
    short half;

    sceGsSetDefDispEnv(&db->disp[0], psm, w, h, 0, 0);
    sceGsSetDefDispEnv(&db->disp[1], psm, w, h, 0, 0);
    func_00103040(&db->draw0, psm, w, h, ztest, zpsm);
    func_00103040(&db->draw1, psm, w, h, ztest, zpsm);
    if (clear) {
        func_00103228(&db->clear0, ztest, 2048 - (w >> 1), 2048 - (h >> 1), w, h, 0, 0, 0, 0, 0);
        func_00103228(&db->clear1, ztest, 2048 - (w >> 1), 2048 - (h >> 1), w, h, 0, 0, 0, 0, 0);
    }
    *(u_long128 *)&db->giftag0 = 0;
    *(u_long128 *)&db->giftag1 = 0;
    db->giftag0.NLOOP = clear ? 14 : 8;
    db->giftag0.EOP = 1;
    db->giftag0.NREG = 1;
    db->giftag0.REGS0 = 0xE;
    db->giftag1.NLOOP = clear ? 14 : 8;
    db->giftag1.EOP = 1;
    db->giftag1.NREG = 1;
    db->giftag1.REGS0 = 0xE;
    zbp = func_00102F78(psm, w, h);
    if ((*(u_long *)gp & 0x0000FFFF0000FFFFULL) == 0x0000000100000001ULL || gp->sceGsInterMode == 0) {
        half = zbp >> 1;
        db->disp[1].dispfb.FBP = half;
        db->draw0.frame1.FBP = zbp >> 1;
    }
}
#undef func_00103228 /* merge_units */
/* merge_units: end func_00103418 */

/* merge_units: begin func_001036B0 */
extern void func_00102EB8(void *);
#if 0 /* merge_units */
extern int sceGsPutDrawEnv(void *);
#endif /* merge_units */
#define sceGsPutDrawEnv(a0) (sceGsPutDrawEnv((unsigned long *)(a0))) /* merge_units */

int func_001036B0(char *db, int field)
{
    int odd = field & 1;
    int r;
    func_00102EB8(db + odd * 0x28);
    if (odd) r = sceGsPutDrawEnv(db + 0x140);
    else r = sceGsPutDrawEnv(db + 0x50);
    return r;
}
#undef sceGsPutDrawEnv /* merge_units */
/* merge_units: end func_001036B0 */

/* merge_units: begin func_00103710 */
typedef struct { short x0; short x2; int x4; int x8; } GsInfo3710;
#if 0 /* merge_units */
extern GsInfo3710 *sceGsGetGParam(void);
#endif /* merge_units */
#define sceGsGetGParam() ((GsInfo3710 *)sceGsGetGParam()) /* merge_units */

extern void func_0010D5F0(void);
extern long func_0010D680(void);

int sceGsSyncV(void)
{
    GsInfo3710 *g = sceGsGetGParam();
    long v;
    if (g->x8 == 0) {
        func_0010D5F0();
        if (g->x0 != 1) return 1;
        return (int)((*(volatile unsigned long *)0x12001000 >> 13) & 1);
    }
    v = (func_0010D680() >> 13) & 1;
    if (g->x0 != 1) return 1;
    return (int)v;
}
#undef sceGsGetGParam /* merge_units */
/* merge_units: end func_00103710 */
