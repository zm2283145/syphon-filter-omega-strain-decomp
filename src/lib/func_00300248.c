#define F(p,T,o) (*(T *)((char *)(p) + (o)))
extern unsigned char D_004908EC;
extern int func_003019B0(unsigned char *, unsigned short *);
extern void func_002F8C50(int, int, unsigned char *);
/* weak stub: the callee was defined in the same original unit (restores the retail branch choice) */
int __attribute__((weak, section(".dtors_drop"))) func_002FE958(int a, int b, int c, int d, int e) { return 0; }
extern int func_00301038(void *, int);
int func_00300248(void *s, int kind, unsigned char *data, int len)
{
    unsigned short port = 0xFFFF;
    int r;
    if (D_004908EC != 1) return 5;
    if (s == 0) return 2;
    if (data == 0) return 2;
    if (kind == 0x1B) {
        func_003019B0(data, &port);
        data += 2;
        len -= 2;
    }
    if (len != 0x40) return 2;
    func_002F8C50(F(s, unsigned short, 0), port, data);
    if (F(s, int, 8) == 3) {
        r = func_002FE958(F(s, int, 4), F(s, int, 0x80), F(s, unsigned short, 0x22), F(s, int, 0x3C), F(s, unsigned short, 0x40));
        if (r != 0) return r;
        r = func_00301038(s, 4);
        if (r != 0) return r;
    }
    return 0;
}
