extern void *memset(void *, int, unsigned int);
extern unsigned char D_0048C740[];
extern void func_002F2C68(unsigned int *, unsigned char *, unsigned int);
extern void func_004AEF70(void *, void *, int);
void func_002F2DC8(unsigned char *digest, unsigned int *ctx)
{
    unsigned char bits[8];
    unsigned int cnt[2];
    unsigned int idx, pad, t0, t1;
    cnt[0] = ctx[4];
    cnt[1] = ctx[5];
    idx = cnt[0] & 0x3F;
    pad = (idx < 0x38) ? (0x38 - idx) : (0x78 - idx);
    func_002F2C68(ctx, D_0048C740, pad);
    t0 = cnt[0];
    t1 = cnt[1];
    cnt[0] = t0 << 3;
    cnt[1] = (t1 << 3) + (t0 >> 29);
    func_004AEF70(bits, cnt, 8);
    func_002F2C68(ctx, bits, 8);
    func_004AEF70(digest, ctx, 0x10);
    memset(ctx, 0, 0x58);
}
