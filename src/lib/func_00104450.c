typedef struct { unsigned int *buf; int x4; int *tag; } Pkt4450;

unsigned int *func_00104450(Pkt4450 *p)
{
    unsigned int *a = p->buf;
    int *tag = p->tag;
    while ((unsigned int)a & 0xC) *a++ = 0;
    if (tag) { int n = (((char *)a - (char *)tag) >> 4) - 1; *tag += n; }
    p->buf = a;
    p->tag = 0;
    return a;
}