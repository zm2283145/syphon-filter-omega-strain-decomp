/*
 * lib/medius: 2 files, 002FEDB0-002FEE78
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002FEDB0 */
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
/* merge_units: end func_002FEDB0 */

/* merge_units: begin func_002FEE78 */
typedef struct { char b[16]; } K;
typedef struct { int f0; char p4; unsigned char f5; unsigned short f6; } S;
typedef struct {
    unsigned short id; char p2[2]; int f4; int f8; char pC[4]; K f10; unsigned short f20; unsigned short f22;
    char p24[0x34]; unsigned short f58; char p5A[0x16]; char f70[8];
} O;
extern unsigned char D_005297C0[];
extern int func_002FE720(O *);
#if 0 /* merge_units */
extern int func_002FE8B0(S *);
#endif /* merge_units */
#define func_002FE8B0(a0) (func_002FE8B0((C *)(a0))) /* merge_units */

extern int func_002FED08(unsigned short *);
extern int func_003017F8(int, unsigned char *, unsigned char *, unsigned char *);
extern int func_003018E0(unsigned char *, unsigned char);
#if 0 /* merge_units */
extern int func_00301988(unsigned char *, unsigned short);
#endif /* merge_units */
#define func_00301988(a0, a1) (func_00301988((void *)(a0), (a1))) /* merge_units */

extern void func_00301A80(unsigned char *, unsigned int);
extern unsigned int func_00476998(void);
#if 0 /* merge_units */
extern int NetConn_BufferMessage(S *, int, int, unsigned char *, int, int);
#endif /* merge_units */
#define NetConn_BufferMessage(a0, a1, a2, a3, a4, a5) (NetConn_BufferMessage((C *)(a0), (a1), (a2), (void *)(a3), (a4), (a5))) /* merge_units */

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
#undef func_002FE8B0 /* merge_units */
#undef func_00301988 /* merge_units */
#undef NetConn_BufferMessage /* merge_units */
/* merge_units: end func_002FEE78 */
