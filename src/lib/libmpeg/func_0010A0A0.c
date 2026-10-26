typedef struct {
    unsigned long buf;
    unsigned char *base;
    unsigned char *ptr;
    unsigned int bits;
    int pad14;
    long pos;
    unsigned char *start;
    unsigned char *end;
    int size;
} BitStreamA0A0;

extern void _sysbitFlush(BitStreamA0A0 *s, int n);

void _sysbitJump(BitStreamA0A0 *s, int n)
{
    s->buf = 0;
    s->bits = 0;
    s->pos += n * 8;
    s->ptr = s->base + (int)(s->pos >> 3);
    if (s->ptr >= s->end) s->ptr -= s->size;
    _sysbitFlush(s, 0);
}
