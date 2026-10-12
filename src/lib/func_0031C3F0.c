typedef struct {
    void *in;
    int a4;
    void *out;
    unsigned short len;
    unsigned short posE;
    unsigned char b10;
    unsigned short pos12;
    unsigned char b14;
} Buf_c3f0;

typedef struct {
    long magic;
    char pad8[0x10];
    unsigned char b18;
    void *st;
} Ctx_c3f0;

typedef struct { float f[20]; } Tmp_c3f0;

extern int func_00323248(void);
extern void func_00323550(Ctx_c3f0 *c);
extern void func_003235B8(Ctx_c3f0 *c);
extern void func_003177D0(void *in, void *st, Tmp_c3f0 *t);
extern void func_003171A8(Tmp_c3f0 *o, void *st, Tmp_c3f0 *p);
extern void func_0031C728(Tmp_c3f0 *t, void *out, unsigned short *pos, unsigned char *bit, unsigned short len, int flag);

int func_0031C3F0(Ctx_c3f0 *c, Buf_c3f0 *b)
{
    Tmp_c3f0 t1, t2;

    if (b == 0) return 0x181A;
    if (b->out == 0) return 0x17F2;
    if (b->in == 0) return 0x17ED;
    if (b->posE >= b->len) return 0x1801;
    if (b->pos12 >= b->len) return 0x1806;
    if (b->b10 >= 8) return 0x17F7;
    if (b->b14 >= 8) return 0x17FC;
    if (c == 0 || c->magic != 0xFACE) return 0x17D4;
    if (c->b18 != 10) return 0x17DE;
    if (func_00323248() == 3) func_00323550(c);
    func_003177D0(b->in, c->st, &t1);
    func_003171A8(&t2, c->st, &t1);
    func_0031C728(&t2, b->out, &b->pos12, &b->b14, b->len, 0);
    if (func_00323248() == 3) func_003235B8(c);
    return 0;
}
