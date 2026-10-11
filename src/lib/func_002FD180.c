#define F(p,T,o) (*(T *)((char *)(p) + (o)))
extern unsigned char D_004908EC;
extern int func_002FE860(int, void **);
extern int NetConn_BufferMessage(void *, int, int, int, int, int);
int func_002FD180(unsigned short a0, unsigned short id, int flags, int data, unsigned short len)
{
    void *c = 0;
    unsigned char st = D_004908EC;
    int r;
    void *dst;
    void *alt;
    int type;
    if (st != 1) return 5;
    if (data == 0) return 2;
    if (len > 0x200) return 2;
    r = func_002FE860(a0, &c);
    if (r != 0) return r;
    if (F(c, int, 8) != 8) return 0x17;
    dst = F(c, void *, 0x80);
    if (F(c, int, 4) == 1) {
        alt = F(c, void *, 0x7C);
        if (alt != 0 && F(alt, unsigned char, 5) == F(c, int, 4) && (flags & 0x50) == 0)
            dst = alt;
    }
    if (id == 0xFFFE) type = 2;
    else if (id == 0xFFFF) type = 0xB;
    else type = 3;
    return NetConn_BufferMessage(dst, type, id, data, len, (flags >> 7) & 1);
}