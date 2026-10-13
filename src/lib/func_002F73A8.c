typedef struct { char b[16]; } Addr;
extern unsigned char D_004908A0;
extern char D_00525600[];
extern char D_00525640[];
extern int func_0034C348(char *, char *, int, char *, int, int *, Addr *, int *, int);
extern int func_0034C840(void *, Addr *);
int func_002F73A8(int s, void *from, unsigned short *port, char *buf, unsigned short size, short *nread)
{
    Addr addr;
    int flags = 0;
    int p;
    int n;
    unsigned short len;
    int r;
    if (D_004908A0 != 1) return 5;
    if (s < 0) return 2;
    if (from == 0) return 2;
    if (port == 0) return 2;
    if (buf == 0) return 2;
    if (nread == 0) return 2;
    *nread = 0;
    len = size <= 0x1000 ? size : 0x1000;
    r = func_0034C348(D_00525600, D_00525640, s, buf, len, &flags, &addr, &p, 2);
    if (r < 0) {
        if (r != -500) return 1;
        r = 0;
    }
    n = r;
    if (n > 0) {
        *port = p;
        r = func_0034C840(from, &addr);
        if (r != 0) return 1;
    }
    *nread = n;
    return 0;
}
