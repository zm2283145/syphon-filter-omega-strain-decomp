typedef struct { int a; } C;
extern unsigned char D_004908EC;
extern int func_002FE8B0(C *);
extern int func_00301988(void *, unsigned short);
extern int NetConn_BufferMessage(C *, int, int, void *, int, int);
int func_002FEDB0(C *c, unsigned short id)
{
    unsigned char buf[2];
    int n = 0;
    int type;
    void *p;
    int r;    if (D_004908EC != 1) return 5;
    if (func_002FE8B0(c) != 1) return 2;
    if (id != 0xFFFF) {
        if (id == 0xFFFE) {
            type = 0xF;
            p = 0;
        } else {
            type = 0x10;
            if (func_00301988(buf, id)) return 7;
            p = buf;
            n = 2;
        }
        r = NetConn_BufferMessage(c, type, 0xFFFF, p, n, 0);
        if (r) return r;
    }
    return 0;
}
