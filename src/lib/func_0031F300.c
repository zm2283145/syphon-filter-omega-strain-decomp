typedef struct {
    unsigned char *buf;
    unsigned short size;
    unsigned short pad6;
    unsigned short *pos;
    unsigned char *bit;
} BitRd_0031F300;
void func_0031F300(BitRd_0031F300 *r, unsigned char *out, int n)
{
    unsigned char *bitp = r->bit;
    unsigned short *pos = r->pos;
    int mask = (1 << n) - 1;
    int sh = *bitp;
    int total = sh + n;
    unsigned short size = r->size;
    unsigned char *p = r->buf + *pos;
    if (total >> 3) {
        int s2;
        *out = *p++ >> sh;
        s2 = 8 - sh;
        mask >>= s2;
        if (++*pos >= size) {
            *pos = 0;
            p = r->buf;
        }
        total -= 8;
        *out |= (*p & mask) << s2;
    } else {
        *out = (*p >> sh) & mask;
        if (total == 8) {
            total = 0;
            if (++*pos >= size)
                *pos = 0;
        }
    }
    *bitp = total;
}
