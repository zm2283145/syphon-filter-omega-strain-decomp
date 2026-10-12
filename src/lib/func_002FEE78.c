typedef struct { char b[16]; } K;
typedef struct { int f0; char p4; unsigned char f5; unsigned short f6; } S;
typedef struct {
    unsigned short id; char p2[2]; int f4; int f8; char pC[4]; K f10; unsigned short f20; unsigned short f22;
    char p24[0x34]; unsigned short f58; char p5A[0x16]; char f70[8];
} O;
extern unsigned char D_004908EC;
extern unsigned char D_005297C0[];
extern int func_002FE720(O *);
extern int func_002FE8B0(S *);
extern int func_002FED08(unsigned short *);
extern int func_003017F8(int, unsigned char *, unsigned char *, unsigned char *);
extern int func_003018E0(unsigned char *, unsigned char);
extern int func_00301988(unsigned char *, unsigned short);
extern void func_00301A80(unsigned char *, unsigned int);
extern unsigned int func_00476998(void);
extern int NetConn_BufferMessage(S *, int, int, unsigned char *, int, int);
extern int func_003060C0(void *);
int func_002FEE78(O *o, S *s)
{
    unsigned short len = 0;
    unsigned char a, b, c;
    unsigned char *p = D_005297C0;
    int r;
    if (D_004908EC != 1) return 5;
    if (func_002FE720(o) != 1) return 2;
    if (func_002FE8B0(s) != 1) return 2;
    if (s->f5 != 1) return 2;
    if (o->id != s->f6) return 2;
    r = func_002FED08(&len);
    if (r) return r;
    if (len != 0x1D) return 1;
    r = func_003017F8(o->f4, &a, &b, &c);
    if (r) return r;
    if (func_003018E0(p, a)) return 7;
    p++;
    if (func_003018E0(p, b)) return 7;
    p++;
    if (func_003018E0(p, c)) return 7;
    p++;
    if (func_00301988(p, o->f22)) return 7;
    p += 2;
    func_00301A80(p, func_00476998());
    p += 4;
    *(K *)p = o->f10;
    p += 16;
    if (func_00301988(p, o->f20)) return 7;
    p += 2;
    if (func_00301988(p, o->f58)) return 7;
    p += 2;
    r = NetConn_BufferMessage(s, 0x16, 0xFFFF, p - 0x1D, 0x1D, 1);
    if (r) return r;
    if (func_003060C0(o->f70)) return 0x18;
    return 0;
}


