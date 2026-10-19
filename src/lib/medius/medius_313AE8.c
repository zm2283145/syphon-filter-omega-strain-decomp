typedef struct {
    unsigned char buf[0x40];
    unsigned char state[0x14];
    int order;
    unsigned int bits;
    unsigned int bitsHi;
} Ctx3AE8;
extern void *memcpy(void *d, const void *s, unsigned int n);
extern void Sha1_ByteSwapWords(Ctx3AE8 *c, int n, int order);
extern void Sha1_Transform(Ctx3AE8 *c);
void Sha1_Update(Ctx3AE8 *c, unsigned char *data, unsigned int len)
{
    unsigned int tmp;
    unsigned int n;
    tmp = c->bits;
    if ((c->bits = tmp + (len << 3)) < tmp)
        c->bitsHi++;
    c->bitsHi += len >> 29;
    n = (tmp >> 3) & 0x3F;
    if (n) {
        unsigned char *p = c->buf + n;
        n = 0x40 - n;
        if (len < n) {
            memcpy(p, data, len);
            return;
        }
        memcpy(p, data, n);
        Sha1_ByteSwapWords(c, 0x40, c->order);
        Sha1_Transform(c);
        data += n;
        len -= n;
    }
    while (len >= 0x40) {
        memcpy(c->buf, data, 0x40);
        Sha1_ByteSwapWords(c, 0x40, c->order);
        Sha1_Transform(c);
        data += 0x40;
        len -= 0x40;
    }
    memcpy(c->buf, data, len);
}