typedef unsigned long u_long __attribute__((mode(DI)));
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
} sceGsClear;

typedef struct {
    sceGsDispEnv disp[2];
    sceGifTag giftag0;
    sceGsDrawEnv1 draw0;
    sceGsClear clear0;
    sceGifTag giftag1;
    sceGsDrawEnv1 draw1;
    sceGsClear clear1;
} sceGsDBuffDc;

typedef struct { short sceGsInterMode; short sceGsOutMode; short sceGsFFMode; short sceGsVersion; } sceGsGParam;

extern sceGsGParam *func_00102A18(void);
extern void sceGsSetDefDispEnv(sceGsDispEnv *disp, short psm, short w, short h, short dx, short dy);
extern int func_00103040(sceGsDrawEnv1 *draw, short psm, short w, short h, short ztest, short zpsm);
extern int func_00103228(sceGsClear *cp, short ztest, short x, short y, short w, short h,
                         unsigned char r, unsigned char g, unsigned char b, unsigned char a, unsigned int z);
extern int func_00102F78(short psm, short w, short h);

void func_00103418(sceGsDBuffDc *db, short psm, short w, short h, short ztest, short zpsm, short clear)
{
    sceGsGParam *gp = func_00102A18();
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
