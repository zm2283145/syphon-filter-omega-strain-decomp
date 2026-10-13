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

extern void func_00109F70(BitStreamA0A0 *s, int n);

void func_0010A0A0(BitStreamA0A0 *s, int n)
{
    s->buf = 0;
    s->bits = 0;
    s->pos += n * 8;
    s->ptr = s->base + (int)(s->pos >> 3);
    if (s->ptr >= s->end) s->ptr -= s->size;
    func_00109F70(s, 0);
}
