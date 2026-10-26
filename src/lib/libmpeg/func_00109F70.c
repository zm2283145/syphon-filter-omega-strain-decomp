typedef struct {
    unsigned long buf;
    int pad8;
    unsigned char *ptr;
    unsigned int bits;
    int pad14;
    unsigned long pos;
    unsigned char *start;
    unsigned char *end;
} BitStream9f70;

void _sysbitFlush(BitStream9f70 *s, int n)
{
    s->buf <<= n;
    s->bits -= n;
    while (s->bits <= 56) {
        s->buf |= (unsigned long)*s->ptr++ << (56 - s->bits);
        if (s->ptr >= s->end) s->ptr = s->start;
        s->bits += 8;
    }
    s->pos += n;
}
