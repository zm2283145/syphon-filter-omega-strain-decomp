#define F(p,T,o) (*(T *)((char *)(p) + (o)))
extern unsigned char D_004908EC;
extern int func_002FE720(void);
extern int func_003019B0(int, unsigned short *);
extern int func_00301038(void *, int);
extern int func_002FE7C0(int);
int func_002FFD70(void *s, int kind, int addr, unsigned int len)
{
    unsigned short port;
    unsigned char st = D_004908EC;
    int r;
    void (*cb)(int, int, int, int, int);
    int id;
    if (st != 1) return 5;
    r = func_002FE720();
    if (r != st) return 2;
    if (addr == 0 || kind != 0x1A) return 2;
    if (r >= len) return r;
    if (func_003019B0(addr, &port) != 0) return 7;
    F(s, unsigned short, 0x5A) = port;
    r = func_00301038(s, 8);
    if (r != 0) return r;
    cb = F(s, void *, 0x84);
    if (cb != 0) {
        id = F(s, unsigned short, 0);
        cb(id, 1, F(s, unsigned short, 0x58), F(s, unsigned short, 0x5A), 0);
        if (func_002FE7C0(id) == 0) return 0xB;
    }
    return 0;
}