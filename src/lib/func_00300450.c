typedef struct {
    unsigned short h;
    char pad[0x92];
    void (*cb)(unsigned short h, unsigned char a, unsigned char b, unsigned char c, unsigned char d, unsigned short len, unsigned char *data);
} Obj0450;
extern unsigned char D_004908EC;
extern int func_002FE720(void);
extern void func_00301900(unsigned char *src, unsigned char *dst);
int func_00300450(Obj0450 *o, int unused, unsigned char *pkt, int len)
{
    unsigned char b[4];
    int st = D_004908EC;
    if (st != 1) return 5;
    if (func_002FE720() != st) return 2;
    if (pkt == 0) return 2;
    if (o->cb) {
        func_00301900(pkt, &b[0]);
        func_00301900(pkt + 1, &b[1]);
        func_00301900(pkt + 2, &b[2]);
        func_00301900(pkt + 3, &b[3]);
        o->cb(o->h, b[0], b[1], b[2], b[3], (unsigned short)len - 4, pkt + 4);
    }
    return 0;
}
