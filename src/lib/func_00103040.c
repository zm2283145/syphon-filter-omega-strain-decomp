typedef unsigned long u_long __attribute__((mode(DI)));

typedef struct { u_long AC:1; u_long pad01:63; } sceGsPrmodecont;
typedef struct { u_long CLAMP:1; u_long pad01:63; } sceGsColclamp;
typedef struct { u_long DTHE:1; u_long pad01:63; } sceGsDthe;

typedef struct {
    u_long frame1;
    u_long frame1addr;
    u_long zbuf1;
    u_long zbuf1addr;
    u_long xyoffset1;
    u_long xyoffset1addr;
    u_long scissor1;
    u_long scissor1addr;
    sceGsPrmodecont prmodecont;
    u_long prmodecontaddr;
    sceGsColclamp colclamp;
    u_long colclampaddr;
    sceGsDthe dthe;
    u_long dtheaddr;
    u_long test1;
    u_long test1addr;
} sceGsDrawEnv1;

#define SCE_GS_SET_FRAME(fbp, fbw, psm, fbmsk) \
    ((u_long)(fbp) | ((u_long)(fbw) << 16) | ((u_long)(psm) << 24) | ((u_long)(fbmsk) << 32))
#define SCE_GS_SET_ZBUF(zbp, psm, zmsk) \
    ((u_long)(zbp) | ((u_long)(psm) << 24) | ((u_long)(zmsk) << 32))
#define SCE_GS_SET_XYOFFSET(ofx, ofy) ((u_long)(ofx) | ((u_long)(ofy) << 32))
#define SCE_GS_SET_SCISSOR(scax0, scax1, scay0, scay1) \
    ((u_long)(scax0) | ((u_long)(scax1) << 16) | ((u_long)(scay0) << 32) | ((u_long)(scay1) << 48))
#define SCE_GS_SET_TEST(ate, atst, aref, afail, date, datm, zte, ztst) \
    ((u_long)(ate) | ((u_long)(atst) << 1) | ((u_long)(aref) << 4) | \
     ((u_long)(afail) << 12) | ((u_long)(date) << 14) | ((u_long)(datm) << 15) | \
     ((u_long)(zte) << 16) | ((u_long)(ztst) << 17))

extern short func_00102F78(short psm, short w, short h);

int func_00103040(sceGsDrawEnv1 *draw, short psm, short w, short h, short ztest, short zpsm)
{
    draw->frame1addr = 0x4C;
    draw->frame1 = SCE_GS_SET_FRAME(0, (w + 63) >> 6 & 0x3f, psm & 0xf, 0);
    draw->zbuf1addr = 0x4E;
    if (ztest == 0)
        draw->zbuf1 = SCE_GS_SET_ZBUF(func_00102F78(psm, w, h), zpsm & 0xf, 1);
    else
        draw->zbuf1 = SCE_GS_SET_ZBUF(func_00102F78(psm, w, h), zpsm & 0xf, 0);
    draw->xyoffset1addr = 0x18;
    draw->xyoffset1 = SCE_GS_SET_XYOFFSET(((u_long)2048 - (short)(w >> 1)) << 4, ((u_long)2048 - (short)(h >> 1)) << 4);
    draw->scissor1addr = 0x40;
    draw->scissor1 = SCE_GS_SET_SCISSOR(0, w - 1, 0, h - 1);
    draw->prmodecontaddr = 0x1A;
    draw->prmodecont.AC = 1;
    draw->colclampaddr = 0x46;
    draw->colclamp.CLAMP = 1;
    draw->dtheaddr = 0x45;
    if (psm & 2)
        draw->dthe.DTHE = 1;
    else
        draw->dthe.DTHE = 0;
    draw->test1addr = 0x47;
    if (ztest)
        draw->test1 = SCE_GS_SET_TEST(0, 0, 0, 0, 0, 0, 1, ztest & 3);
    else
        draw->test1 = SCE_GS_SET_TEST(0, 0, 0, 0, 0, 0, 1, 1);
    __asm__ __volatile__("sync");
    return sizeof(sceGsDrawEnv1) / 16;
}

