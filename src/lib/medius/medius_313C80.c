typedef struct {
    unsigned char buf[0x38];
    unsigned int lenHi;
    unsigned int lenLo;
    unsigned char state[0x14];
    int order;
    int bits;
    int bitsHi;
} Ctx3C80;
extern void *memset(void *d, int c, unsigned int n);
extern void longReverse(Ctx3C80 *c, int n, int order);
extern void SHSTransform(Ctx3C80 *c);
extern void SHAtoByte(unsigned char *dst, unsigned char *src, unsigned int n);
void SHAFinal(Ctx3C80 *c, unsigned char *digest, unsigned int len)
{
    int n;
    unsigned char *p;
    n = c->bits;
    n = (n >> 3) & 0x3F;
    p = c->buf + n;
    *p++ = 0x80;
    n = 63 - n;
    if (n < 8) {
        memset(p, 0, n);
        longReverse(c, 0x40, c->order);
        SHSTransform(c);
        memset(c, 0, 0x38);
    } else {
        memset(p, 0, n - 8);
    }
    c->lenHi = c->bitsHi;
    c->lenLo = c->bits;
    longReverse(c, 0x38, c->order);
    SHSTransform(c);
    if (len > 20) {
        memset(digest + 20, 0, len - 20);
        len = 20;
    }
    SHAtoByte(digest, c->state, len);
    *(int *)c->buf = 0;
}
