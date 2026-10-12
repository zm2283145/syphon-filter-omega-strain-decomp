typedef struct {
    long magic;
    long a8;
    long a10;
    unsigned char b18;
    int sub[2];
    int a24;
    int pad28[2];
    void *buf30;
    void *buf34;
} Ctx_c530;

extern void *(*D_004E1D34)(int, int);
extern unsigned short D_004E1D4C;
extern int func_00322E60(int);
extern void func_00127358(char *);
extern int func_00323248(void);
extern int func_003179A8(int *sub, int v);
extern void func_0031C668(Ctx_c530 **out);

int func_0031C530(Ctx_c530 **out)
{
    Ctx_c530 *s;
    int r;

    if (out == 0) return 0x181A;
    *out = 0;
    r = func_00322E60(0);
    if (r == 1) {
        func_00127358("\nEvaluation period has expired.\nExiting...\n\n");
        return 0x1965;
    }
    if (r == -1) {
        func_00127358("\nClock incorrectly set.  Please adjust to correct date and time.\nExiting...\n\n");
        return 0x1965;
    }
    s = D_004E1D34(1, sizeof(Ctx_c530));
    if (s == 0) return 0x1770;
    *out = s;
    s->b18 = 10;
    s->magic = 0xFACE;
    s->a8 = 100;
    s->a10 = 3000;
    if (func_00323248() == 3) {
        s->buf30 = D_004E1D34(0x1000, 1);
        if (s->buf30 == 0) return 0x1770;
        s->buf34 = D_004E1D34(0x1000, 1);
        if (s->buf34 == 0) return 0x1770;
    }
    if (func_003179A8(s->sub, s->a24) != 0) {
        func_0031C668(out);
        return 0x1770;
    }
    D_004E1D4C++;
    return 0;
}
