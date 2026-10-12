typedef struct { unsigned char f0; char pad; unsigned short f2; } H;
extern int func_00300A58(unsigned char *, H *, unsigned short *);
int func_00301518(unsigned char *buf, unsigned int len, unsigned int max, unsigned int *out)
{
    H h;
    unsigned short x = 0;
    unsigned char *end;
    unsigned short sz;
    unsigned int v;
    int r;
    if (out == 0) return 2;
    *out = 0;
    if (buf == 0) return 2;
    end = buf + len;
    if (len <= max) {
        *out = len;
        return 0;
    }
    while (buf < end) {
        r = func_00300A58(buf, &h, &x);
        if (r != 0) return r;
        sz = x + h.f2;
        if (h.f2 != 0 && (h.f0 & 0x80)) sz += 4;
        v = *out + sz;
        if (max < v) return 0;
        buf += sz;
        *out = v;
    }
    return 0;
}
