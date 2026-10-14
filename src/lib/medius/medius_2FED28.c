typedef struct { unsigned char a; unsigned char pad; unsigned short b; } H2FED28;
extern unsigned char D_004908EC;
extern int func_002FE8B0(void);
extern int NetPacket_WritePrefix(char *, H2FED28 *, unsigned short *);
extern int func_00300AE8(int, char *, unsigned short, int);
int func_002FED28(int conn)
{
    char buf[16];
    H2FED28 h;
    unsigned short len = 0;
    unsigned char st = D_004908EC;
    int v, r;
    if (st != 1) return 5;
    v = func_002FE8B0();
    if (v != st) return 2;
    h.a = v;
    h.b = 0;
    r = NetPacket_WritePrefix(buf, &h, &len);
    if (r) return r;
    return func_00300AE8(conn, buf, len, 0x2710);
}
