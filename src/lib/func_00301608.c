typedef struct { int x0; int p4; char x8[0x10]; unsigned short x18; short p1A; int x1C; } Sock;
extern int func_002FE8B0(void);
extern int Socket_WriteConnected(int a, int b, unsigned short c, unsigned short *out);
extern int Socket_WriteAddressed(int a, int b, unsigned short c, int d, unsigned short e, unsigned short *out);
int __attribute__((weak, section(".dtors_drop"))) func_00301518(int p0, unsigned int p1, int p2, unsigned int * p3) { return 0; }
extern int func_003010C8(int);
int Socket_Write(Sock *s, int buf, unsigned int len, unsigned short *out)
{
    unsigned int n = 0;
    int r;
    int w;
    if (out == 0) return 2;
    __asm__ volatile("" :: "r"(len));
    *out = 0;
    r = func_002FE8B0();
    if (r != 1) return 2;
    if (buf == 0) return 2;
    if (s->x0 == 0) {
        n = len;
        if (len > 0x1000) n = 0x1000;
        w = Socket_WriteConnected(s->x1C, buf, n, out);
    } else if (s->x0 == r) {
        r = func_00301518(buf, len, 0x248, &n);
        if (r != 0) return r;
        if (n == 0) goto ok;
        w = Socket_WriteAddressed(s->x1C, (int)s->x8, s->x18, buf, n, out);
        __asm__ volatile("" :: "r"(s));
    } else {
        return 3;
    }
    r = func_003010C8(w);
    if (r != 0) return r;
ok:
    return 0;
}





