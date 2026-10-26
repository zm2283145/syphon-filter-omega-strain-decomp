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
extern int _sysbitGet(BS *bs, int n);
extern int _sysbitMarker(BS *bs);
extern void _sysbitJump(BS *bs, int n);
extern void func_0010BD90(void *ctx, char *msg);

int _PES_packet(void *ctx, BS *bs, Hdr *hdr)
{
    Tbl tbl;
    int ptsdts, escr, flags, ext, hdrlen, start;
    int priv, pack, seq, pstd, ext2;
    int rem, n;

    hdr->x28 = bs->pos;
    tbl = D_00498658;
    _sysbitGet(bs, 24);
    hdr->id = (long)_sysbitGet(bs, 8) << 32;
    hdr->len = _sysbitGet(bs, 16);
    hdr->pts = hdr->dts = -1;
    if (hdr->id != 0xBCL << 32 && hdr->id != 0xBEL << 32 && hdr->id != 0xBFL << 32 && hdr->id != 0xF0L << 32
        && hdr->id != 0xF1L << 32 && hdr->id != 0xFFL << 32 && hdr->id != 0xF2L << 32 && hdr->id != 0xF8L << 32) {
        _sysbitGet(bs, 2);
        hdr->scramble = _sysbitGet(bs, 2);
        _sysbitGet(bs, 4);
        ptsdts = _sysbitGet(bs, 2);
        escr = _sysbitGet(bs, 1);
        flags = _sysbitGet(bs, 4);
        ext = _sysbitGet(bs, 1);
        hdrlen = _sysbitGet(bs, 8);
        start = bs->pos;
        if (ptsdts & 2) {
            unsigned int a, b, c;
            _sysbitGet(bs, 4);
            a = _sysbitGet(bs, 3);
            _sysbitMarker(bs);
            b = _sysbitGet(bs, 15);
            _sysbitMarker(bs);
            c = _sysbitGet(bs, 15);
            _sysbitMarker(bs);
            {
                unsigned int lo = (a << 30) | (b << 15) | c;
                hdr->pts = ((long)((a >> 2) & 1) << 32) | lo;
            }
        }
        if (ptsdts == 3) {
            unsigned int a, b, c;
            _sysbitGet(bs, 4);
            a = _sysbitGet(bs, 3);
            _sysbitMarker(bs);
            b = _sysbitGet(bs, 15);
            _sysbitMarker(bs);
            c = _sysbitGet(bs, 15);
            _sysbitMarker(bs);
            {
                unsigned int lo = (a << 30) | (b << 15) | c;
                hdr->dts = ((long)((a >> 2) & 1) << 32) | lo;
            }
        }
        if (escr == 1) _sysbitGet(bs, 48);
        if (flags) _sysbitGet(bs, tbl.c[flags]);
        if (ext == 1) {
            priv = _sysbitGet(bs, 1);
            pack = _sysbitGet(bs, 1);
            seq = _sysbitGet(bs, 1);
            pstd = _sysbitGet(bs, 1);
            _sysbitGet(bs, 3);
            ext2 = _sysbitGet(bs, 1);
            if (priv == 1) {
                _sysbitGet(bs, 48);
                _sysbitGet(bs, 48);
                _sysbitGet(bs, 32);
            }
            if (pack == 1) {
                func_0010BD90(ctx, D_00498668);
                return 0;
            }
            if (seq == 1) _sysbitGet(bs, 16);
            if (pstd == 1) _sysbitGet(bs, 16);
            if (ext2 == 1) {
                unsigned int i, cnt;
                _sysbitMarker(bs);
                cnt = _sysbitGet(bs, 7);
                for (i = 0; i < cnt; i++) _sysbitGet(bs, 8);
            }
        }
        rem = hdrlen - (int)((bs->pos - start) >> 3);
        if (rem) _sysbitJump(bs, rem);
        rem = hdr->len - hdrlen - 3;
        hdr->x24 = rem;
        hdr->x20 = bs->pos;
        if (hdr->id == 0xBDL << 32) {
            hdr->id |= (unsigned int)_sysbitGet(bs, 32);
            rem -= 4;
        }
        if (rem) _sysbitJump(bs, rem);
    } else if (hdr->id == 0xBCL << 32 || hdr->id == 0xBFL << 32 || hdr->id == 0xF0L << 32 || hdr->id == 0xF1L << 32
               || hdr->id == 0xFFL << 32 || hdr->id == 0xF2L << 32 || hdr->id == 0xF8L << 32) {
        n = hdr->len;
        if (hdr->id == 0xBFL << 32) {
            hdr->id |= (unsigned int)_sysbitGet(bs, 32);
            n -= 4;
        }
        if (n) _sysbitJump(bs, n);
    } else if (hdr->id == 0xBEL << 32) {
        if (hdr->len) _sysbitJump(bs, hdr->len);
    }
    return 1;
}


