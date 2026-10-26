typedef struct {
    unsigned long buf;
    unsigned char *base;
    unsigned char *ptr;
    unsigned int bits;
    int pad14;
    unsigned long pos;
    unsigned char *start;
    unsigned char *end;
    int size;
} BitStream9f18;

extern void _sysbitFlush(BitStream9f18 *s, int n);

void _sysbitInit(BitStream9f18 *s, unsigned char *p, unsigned char *start, int size)
{
    s->base = p;
    s->ptr = p;
    s->buf = 0;
    s->bits = 0;
    s->pos = 0;
    s->start = start;
    s->end = start + size;
    s->size = size;
    _sysbitFlush(s, 0);
}
