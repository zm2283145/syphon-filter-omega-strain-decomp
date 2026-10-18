#define F(p,T,o) (*(T *)((char *)(p) + (o)))
typedef struct { char b[16]; } K16;
typedef struct { char b[64]; } K64;
extern void *memcpy(void *, const void *, unsigned int);
extern int func_002FE720(void);
extern int func_003019B0(unsigned char *, unsigned short *);
extern int func_002F84D0(int, int, char *);
extern int func_002FE7C0(int);
int func_002FFE80(void *s, int kind, unsigned char *buf, unsigned int len)
{
    K16 k;
    K64 k2;
    unsigned short port = 0;
    int big = 0;
    unsigned char *p;
    int r;
    void (*cb)(int, int, char *, int);
    int id;
    p = buf;
    if (func_002FE720() != 1) return 2;
    if (p == 0) return 2;
    if (kind == 8)
        big = 1;
    else if (kind != 9)
        return 2;
    r = 1; /* the state value checked above; comparing through a variable keeps retail's li/sltu */
    if (r >= len) return r;
    if (func_003019B0(buf, &port) != 0) return 7;
    p = buf + 2;
    if (big) {
        if ((int)(len - 2) != 80) return 1; /* cast keeps fold() from merging the -2 into the constant */
    } else {
        if ((int)(len - 2) != 16) return 1;
    }
    memcpy(&k, p, 16);
    p += 16;
    if (big) {
        memcpy(&k2, p, 64);
        func_002F84D0(F(s, unsigned short, 0), port, k2.b);
    }
    cb = F(s, void *, 0x8C);
    if (cb != 0) {
        id = F(s, unsigned short, 0);
        cb(id, port, k.b, big);
        if (func_002FE7C0(id) == 0) return 0xB;
    }
    return 0;
}
