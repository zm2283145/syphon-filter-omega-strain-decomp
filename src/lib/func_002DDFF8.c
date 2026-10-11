typedef struct { unsigned char c, d; char data[0x1FE]; } P2DDFF8;
extern unsigned char D_0048C4AC;
extern int D_0048C4B0;
extern unsigned short D_0058C0B0;
extern P2DDFF8 D_0051F0D8;
extern int func_002DF708(void);
extern void *memcpy(void *, const void *, unsigned int);
extern int func_002DD440(char *, int);
extern int func_00303930(int, char *, unsigned short, P2DDFF8 *, unsigned short);
int func_002DDFF8(int a, int b, unsigned int c, unsigned int d, int len, void *data)
{
    char buf[16];
    int r;
    if (!D_0048C4AC) {
        r = func_002DF708();
        if (r) return r;
    }
    if (c >= 6) return 0x17;
    if (d >= 0x100) return 0x17;
    if (len <= 0) return 0x17;
    if (len >= 0x1FF) return 0x1F;
    if (data == 0) return 0x17;
    if (b == 0) return 0x17;
    D_0051F0D8.c = c;
    D_0051F0D8.d = d;
    memcpy(D_0051F0D8.data, data, len);
    func_002DD440(buf, b);
    return func_00303930(D_0048C4B0, buf, D_0058C0B0, &D_0051F0D8, len + 2) ? 0x25 : 0;
}
