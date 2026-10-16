#define F(p,T,o) (*(T *)((char *)(p) + (o)))
extern int func_002FE720(void);
extern int func_003019B0(int, unsigned short *);
extern int func_002FE7C0(int);
int func_00300068(void *s, int kind, int addr, unsigned int len)
{
    /* gcc296 allocation tie: pin a copy of s to $s2 (retail register choice). */
    register char *ps asm("$18");
    unsigned short port = 0;
    int r;
    int hdr;
    void (*cb)(int, int, int, int);
    int id;
    ps = s;
    r = func_002FE720();
    hdr = 0;
    if (r != 1 || addr == 0 || (kind != 2 && kind != 3 && kind != 10)) return 2;
    if (kind == 10) {
        port = 0xFFFF;
    } else {
        if (r >= len) return r;
        if (func_003019B0(addr, &port) != 0) return 7;
        addr += 2;
        hdr = 2;
    }
    cb = F(ps, void *, 0x88);
    if (cb != 0) {
        id = F(ps, unsigned short, 0);
        cb(id, port, addr, (unsigned short)(len - hdr));
        if (func_002FE7C0(id) == 0) return 0xB;
    }
    return 0;
}


