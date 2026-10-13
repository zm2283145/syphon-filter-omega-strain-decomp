typedef struct {
    unsigned long buf;
    unsigned char *base;
    unsigned char *ptr;
    unsigned int bits;
    int pad14;
    long pos;
} BS;

typedef struct {
    long id;
    int len;
    int scramble;
    long pts;
    long dts;
    int x20;
    int x24;
    int x28;
} Hdr;

typedef struct { unsigned char c[16]; } Tbl;
extern Tbl D_00498658;
extern char D_00498668[];
extern int func_0010A008(BS *bs, int n);
extern int func_0010A058(BS *bs);
extern void func_0010A0A0(BS *bs, int n);
extern void func_0010BD90(void *ctx, char *msg);

int func_0010A998(void *ctx, BS *bs, Hdr *hdr)
{
    Tbl tbl;
    int ptsdts, escr, flags, ext, hdrlen, start;
    int priv, pack, seq, pstd, ext2;
    int rem, n;

    hdr->x28 = bs->pos;
    tbl = D_00498658;
    func_0010A008(bs, 24);
    hdr->id = (long)func_0010A008(bs, 8) << 32;
    hdr->len = func_0010A008(bs, 16);
    hdr->pts = hdr->dts = -1;
    if (hdr->id != 0xBCL << 32 && hdr->id != 0xBEL << 32 && hdr->id != 0xBFL << 32 && hdr->id != 0xF0L << 32
        && hdr->id != 0xF1L << 32 && hdr->id != 0xFFL << 32 && hdr->id != 0xF2L << 32 && hdr->id != 0xF8L << 32) {
        func_0010A008(bs, 2);
        hdr->scramble = func_0010A008(bs, 2);
        func_0010A008(bs, 4);
        ptsdts = func_0010A008(bs, 2);
        escr = func_0010A008(bs, 1);
        flags = func_0010A008(bs, 4);
        ext = func_0010A008(bs, 1);
        hdrlen = func_0010A008(bs, 8);
        start = bs->pos;
        if (ptsdts & 2) {
            unsigned int a, b, c;
            func_0010A008(bs, 4);
            a = func_0010A008(bs, 3);
            func_0010A058(bs);
            b = func_0010A008(bs, 15);
            func_0010A058(bs);
            c = func_0010A008(bs, 15);
            func_0010A058(bs);
            {
                unsigned int lo = (a << 30) | (b << 15) | c;
                hdr->pts = ((long)((a >> 2) & 1) << 32) | lo;
            }
        }
        if (ptsdts == 3) {
            unsigned int a, b, c;
            func_0010A008(bs, 4);
            a = func_0010A008(bs, 3);
            func_0010A058(bs);
            b = func_0010A008(bs, 15);
            func_0010A058(bs);
            c = func_0010A008(bs, 15);
            func_0010A058(bs);
            {
                unsigned int lo = (a << 30) | (b << 15) | c;
                hdr->dts = ((long)((a >> 2) & 1) << 32) | lo;
            }
        }
        if (escr == 1) func_0010A008(bs, 48);
        if (flags) func_0010A008(bs, tbl.c[flags]);
        if (ext == 1) {
            priv = func_0010A008(bs, 1);
            pack = func_0010A008(bs, 1);
            seq = func_0010A008(bs, 1);
            pstd = func_0010A008(bs, 1);
            func_0010A008(bs, 3);
            ext2 = func_0010A008(bs, 1);
            if (priv == 1) {
                func_0010A008(bs, 48);
                func_0010A008(bs, 48);
                func_0010A008(bs, 32);
            }
            if (pack == 1) {
                func_0010BD90(ctx, D_00498668);
                return 0;
            }
            if (seq == 1) func_0010A008(bs, 16);
            if (pstd == 1) func_0010A008(bs, 16);
            if (ext2 == 1) {
                unsigned int i, cnt;
                func_0010A058(bs);
                cnt = func_0010A008(bs, 7);
                for (i = 0; i < cnt; i++) func_0010A008(bs, 8);
            }
        }
        rem = hdrlen - (int)((bs->pos - start) >> 3);
        if (rem) func_0010A0A0(bs, rem);
        rem = hdr->len - hdrlen - 3;
        hdr->x24 = rem;
        hdr->x20 = bs->pos;
        if (hdr->id == 0xBDL << 32) {
            hdr->id |= (unsigned int)func_0010A008(bs, 32);
            rem -= 4;
        }
        if (rem) func_0010A0A0(bs, rem);
    } else if (hdr->id == 0xBCL << 32 || hdr->id == 0xBFL << 32 || hdr->id == 0xF0L << 32 || hdr->id == 0xF1L << 32
               || hdr->id == 0xFFL << 32 || hdr->id == 0xF2L << 32 || hdr->id == 0xF8L << 32) {
        n = hdr->len;
        if (hdr->id == 0xBFL << 32) {
            hdr->id |= (unsigned int)func_0010A008(bs, 32);
            n -= 4;
        }
        if (n) func_0010A0A0(bs, n);
    } else if (hdr->id == 0xBEL << 32) {
        if (hdr->len) func_0010A0A0(bs, hdr->len);
    }
    return 1;
}


