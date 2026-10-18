typedef struct { char b[64]; } K64;
extern unsigned char D_004908EC;
extern int func_002FECE8(int, unsigned short *);
extern int func_003017F8(int, unsigned char *, unsigned char *, unsigned char *);
extern int func_003018E0(unsigned char *, unsigned char);
extern int func_00301988(unsigned char *, unsigned short);
extern void func_00301A80(unsigned char *, unsigned int);
extern unsigned int func_00476998(void);
extern int func_00301758(unsigned short, unsigned char *);
extern void func_004769A4(char *a, char *b);
extern int func_002F9278(int a, int b, char *c, char *d, char *e);
extern void *memset(void *, int, unsigned int);
extern void *memcpy(void *, const void *, unsigned int);
int func_002FEA88(unsigned char *out, unsigned short type, int addr, unsigned short key, unsigned short port,
                  void *data, unsigned short len)
{
    char k1[64];
    char k2[64];
    unsigned char flag = 0;
    unsigned short chk = 0;
    unsigned char a, b, c;
    unsigned char *p;
    int r;
    if (D_004908EC != 1) return 5;
    if (!data && len) return 2;
    if (!out) return 2;
    r = func_002FECE8(len, &chk);
    if (r) return r;
    if (type != chk) return 2;
    p = out;
    r = func_003017F8(addr, &a, &b, &c);
    if (r) return r;
    if (func_003018E0(p, a)) return 7;
    p++;
    if (func_003018E0(p, b)) return 7;
    p++;
    if (func_003018E0(p, c)) return 7;
    p++;
    if (func_00301988(p, port)) return 7;
    p += 2;
    func_00301A80(p, func_00476998());
    p += 4;
    r = func_00301758(key, &flag);
    if (r) return r;
    if (flag == 1) {
        K64 sig;
        func_004769A4(k1, k2);
        if (func_002F9278(key, 0xFFFF, k1, k2, (char *)&sig)) return 27;
        *(K64 *)p = sig;
    } else {
        memset(p, 0, 64);
    }
    p += 64;
    if (data && len)
        memcpy(p, data, len);
    return 0;
}
