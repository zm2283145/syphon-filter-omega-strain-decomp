typedef struct {
    void *in;
    int a4;
    void *out;
    unsigned short len;
    unsigned short posE;
    unsigned char b10;
    unsigned short pos12;
    unsigned char b14;
} Buf_320688;

typedef struct {
    long magic;
    char pad8[0x10];
    unsigned char b18;
    void *st;
    char pad20[8];
    Buf_320688 *cur;
} Ctx_320688;

typedef struct {
    float f;
    float a[12];
    float b[12];
} Out_320688;

extern int func_00323248(void);
extern void func_00323550(Ctx_320688 *c);
extern void func_003235B8(Ctx_320688 *c);
extern void func_0031F3D8(void *st, void *in, int *a4, void *out, unsigned short len,
                          unsigned short *posE, unsigned char *b10, float *m1, float *m2, float *f);

int func_00320688(Ctx_320688 *c, Buf_320688 *b, Out_320688 *o)
{
    float m1[12];
    float m2[16];
    float f;
    int i;

    if (c == 0 || c->magic != 0xFACE) return 0x17D4;
    if (c->b18 != 11) return 0x17E3;
    if (b == 0) return 0x181A;
    if (b->out == 0) return 0x17F2;
    if (b->in == 0) return 0x17ED;
    if (b->posE >= b->len) return 0x1801;
    if (b->pos12 >= b->len) return 0x1806;
    if (b->b10 >= 8) return 0x17F7;
    if (b->b14 >= 8) return 0x17FC;
    c->cur = b;
    if (func_00323248() == 3) func_00323550(c);
    func_0031F3D8(c->st, b->in, &b->a4, b->out, b->len, &b->posE, &b->b10, m1, m2, &f);
    if (o != 0) {
        o->f = f;
        for (i = 0; i < 12; i++) o->a[i] = m2[i];
        for (i = 0; i < 12; i++) o->b[i] = m1[i];
    }
    if (func_00323248() == 3) func_003235B8(c);
    return 0;
}
