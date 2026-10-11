typedef struct { short a, b, c; unsigned short port; } C2FE958;
extern unsigned char D_004908EC;
extern int func_002FE8B0(C2FE958 *);
extern int func_002FECE8(int, unsigned short *);
extern int Net_AllocZeroed(void **, int);
extern int func_002FEA88(void *, int, int, int, int, int, int);
extern int NetConn_BufferMessage(void *, int, int, void *, int, int);
extern void func_002FB3C0(void *);
int func_002FE958(unsigned int kind, C2FE958 *c, unsigned short flags, int data, unsigned short len)
{
    unsigned short sz;
    void *buf;
    unsigned char st = D_004908EC;
    int r;
    buf = 0;
    sz = 0;
    if (st != 1) return 5;
    if (func_002FE8B0(c) != st) return 2;
    if (data == 0 && len != 0) return 2;
    if (kind >= 2) return 2;
    r = func_002FECE8(len, &sz);
    if (r != 0) return r;
    if (Net_AllocZeroed(&buf, sz) != 0) return 8;
    r = func_002FEA88(buf, sz, kind, c->port, flags, data, len);
    if (r == 0)
        r = NetConn_BufferMessage(c, kind ? 0x15 : 0, 0xFFFF, buf, sz, 1);
    if (buf) func_002FB3C0(&buf);
    return r;
}