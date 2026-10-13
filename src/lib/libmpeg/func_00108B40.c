typedef struct {
    char pad0[0x18];
    long x18;
    long x20;
    int x28;
    int x2C;
    int x30;
    int x34;
    int x38;
    int x3C;
    int x40;
    int x44;
    int x48;
    int x4C;
    int x50;
    int x54;
    int x58;
    int x5C;
    int x60;
} MpegPic;

typedef struct {
    char pad0[0xB8];
    int xB8;
    int xBC;
    char pad1[0x100 - 0xC0];
    int x100;
    char pad2[0x154 - 0x104];
    int x154;
    char pad3[0x160 - 0x158];
    int x160;
    int x164;
    int x168;
    char pad4[0x18C - 0x16C];
    int x18C;
    int x190;
    char pad5[0x19C - 0x194];
    int x19C;
    int x1A0;
    int x1A4;
    int x1A8;
    int x1AC;
    int x1B0;
    int x1B4;
    int x1B8;
    int x1BC;
    int x1C0;
    char pad6[0x1D0 - 0x1C4];
    MpegPic *x1D0;
    MpegPic *x1D4;
    MpegPic *x1D8;
    MpegPic *x1DC;
    MpegPic *x1E0;
    MpegPic *x1E4;
    MpegPic *x1E8;
    MpegPic *x1EC;
    MpegPic *x1F0;
    MpegPic *x1F4;
    MpegPic *x1F8;
    MpegPic *x1FC;
    char pad7[0x840 - 0x200];
    long x840;
    long x848;
} MpegCtx;

int func_00108B40(MpegCtx *m, int second)
{
    MpegPic *tmp;
    register MpegPic *pic asm("$8");
    int n;
    int ret;

    pic = 0;
    ret = 0;
    n = m->x18C == 3 ? 2 : 4;
    if (m->x168 == 3) {
        m->x1D8 = m->x1DC;
        m->x1E8 = m->x1EC;
        m->x1F8 = m->x1FC;
        if (m->xB8 + m->xBC >= n) {
            m->x100 = 0;
            m->x1C0 = 0;
            m->x1BC = 0;
        }
        if ((m->x100 || m->x1C0) && !m->x1BC) {
            m->x1D0->x28 = 0;
            m->x1E0->x28 = 0;
            m->x1F0->x28 = 0;
        }
        m->x100 = 0;
        m->x1C0 = 0;
        if (m->x18C == 3) {
            if ((m->x1D0->x28 == 1 || m->x1BC) && m->x1D4->x28 == 1)
                ret = 1;
        } else {
            if ((m->x1E0->x28 == 1 && m->x1F0->x28 == 1) || m->x1BC) {
                if (m->x1E4->x28 == 1 && m->x1F4->x28 == 1)
                    ret = 1;
            }
        }
    } else {
        if (!second) {
            tmp = m->x1D0; m->x1D0 = m->x1D4; m->x1D4 = tmp;
            tmp = m->x1E0; m->x1E0 = m->x1E4; m->x1E4 = tmp;
            tmp = m->x1F0; m->x1F0 = m->x1F4; m->x1F4 = tmp;
        }
        m->x1D8 = m->x1D4;
        m->x1E8 = m->x1E4;
        m->x1F8 = m->x1F4;
        if (m->x18C == 3) {
            if (m->x168 != 2 || m->x1D0->x28 == 1)
                ret = 1;
        } else {
            MpegPic *o = m->x18C == 1 ? m->x1F4 : m->x1E4;
            if (m->x168 != 2 || (second && o->x28 == 1)
                || (m->x1E0->x28 == 1 && m->x1F0->x28 == 1))
                ret = 1;
        }
    }
    switch (m->x18C) {
    case 1:
        pic = m->x1E8;
        break;
    case 2:
        pic = m->x1F8;
        break;
    case 3:
        pic = m->x1D8;
        break;
    }
    pic->x28 = 0;
    pic->x18 = m->x840;
    pic->x20 = m->x848;
    pic->x2C = m->x168;
    pic->x30 = m->x18C;
    pic->x34 = m->x154;
    pic->x38 = m->x1A0;
    pic->x3C = m->x190;
    pic->x40 = m->x19C;
    pic->x44 = m->x1A4;
    pic->x48 = m->x1A8;
    pic->x4C = m->x1AC;
    pic->x50 = m->x1B0;
    pic->x54 = m->x1B4;
    pic->x58 = m->x1B8;
    pic->x5C = m->x160;
    pic->x60 = m->x164;
    return ret;
}
