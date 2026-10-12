extern unsigned char D_004908EC;
extern int func_002FE720(void);
extern void func_00301AB8(unsigned char *src, unsigned int *out);
extern void *memcpy(void *d, const void *s, unsigned int n);
int func_00300918(int a, int b, int c, unsigned char *buf, unsigned int len)
{
    unsigned int h[2];
    int st = D_004908EC;
    if (st != 1) return 5;
    if (func_002FE720() != st) return 2;
    if (buf == 0) return 2;
    if (len < 9) return 0;
    func_00301AB8(buf, &h[0]);
    func_00301AB8(buf + 4, &h[1]);
    if (h[1] != len - 8) return 0;
    memcpy((void *)h[0], buf + 8, h[1]);
    return 0;
}
