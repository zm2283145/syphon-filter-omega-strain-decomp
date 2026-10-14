/*
 * lib/medius: 17 files, 002F7040-002F7AB0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002F7040 */
extern unsigned char D_004908A0;
extern char D_00525600[];
extern int D_00525640[];
extern int func_0034C168(void *cd, int *buf, int p, int x);
int func_002F7040(int x)
{
    if (D_004908A0 != 1) return 5;
    if (x < 0) return 2;
    return func_0034C168(D_00525600, D_00525640, x, 500) != 0;
}
/* merge_units: end func_002F7040 */

/* merge_units: begin func_002F7090 */
#if 0 /* merge_units */
extern char D_00525640[];
#endif /* merge_units */
#define D_00525640 ((char*)&D_00525640) /* merge_units */

extern int func_0034C440(char *, char *, int, int, unsigned short, int *, int);
int func_002F7090(int a, int b, unsigned short c, short *out)
{
    int x = 0;
    int r;
    if (D_004908A0 != 1) return 5;
    if (a < 0) return 2;
    if (b == 0) return 2;
    if (out == 0) return 2;
    r = func_0034C440(D_00525600, D_00525640, a, b, c, &x, 0);
    if (r < 0) return 1;
    *out = r;
    return 0;
}
#undef D_00525640 /* merge_units */
/* merge_units: end func_002F7090 */

/* merge_units: begin func_002F7128 */
#if 0 /* merge_units */
extern char D_00525640[];
#endif /* merge_units */
#define D_00525640 ((char*)&D_00525640) /* merge_units */

extern int func_0034C7A8(char *, int);
extern int func_0034C590(char *, char *, int, int, unsigned short, int *, char *, unsigned short, int);
int func_002F7128(int a, int name, unsigned short x, int y, unsigned short z, short *out)
{
    char buf[16];
    int w = 0;
    int r;
    if (D_004908A0 != 1) return 5;
    if (a < 0) return 2;
    if (name == 0) return 2;
    if (x == 0) return 2;
    if (y == 0) return 2;
    if (out == 0) return 2;
    *out = 0;
    if (func_0034C7A8(buf, name) < 0) return 1;
    r = func_0034C590(D_00525600, D_00525640, a, y, z, &w, buf, x, 0);
    if (r < 0) return 1;
    *out = r;
    return 0;
}
#undef D_00525640 /* merge_units */
/* merge_units: end func_002F7128 */

/* merge_units: begin func_002F7218 */
#if 0 /* merge_units */
extern char D_00525640[];
#endif /* merge_units */
#define D_00525640 ((char*)&D_00525640) /* merge_units */

extern int func_0034C628(char *, char *, int, unsigned short, char *);
int func_002F7218(int a, unsigned char *out, int name, unsigned short port)
{
    char buf[16];
    unsigned char st;
    int r;
    if (out == 0) return 2;
    *out = 0;
    st = D_004908A0;
    if (st != 1) return 5;
    if (a < 0) return 2;
    if (name == 0) return 2;
    if (func_0034C7A8(buf, name) < 0) return 1;
    r = func_0034C628(D_00525600, D_00525640, a, port, buf);
    if (r < 0) return 1;
    if (r > 0) *out = st;
    return 0;
}
#undef D_00525640 /* merge_units */
/* merge_units: end func_002F7218 */

/* merge_units: begin func_002F72D8 */
#if 0 /* merge_units */
extern char D_00525640[];
#endif /* merge_units */
#define D_00525640 ((char*)&D_00525640) /* merge_units */

extern int func_0034C200(char *, char *, int, void *, unsigned short, int *, int);
int func_002F72D8(int a, void *buf, unsigned short len, short *out)
{
    int flags;
    unsigned char st;
    int r;
    flags = 0;
    st = D_004908A0;
    if (st != 1) return 5;
    if (a < 0) return 2;
    if (buf == 0) return 2;
    if (out == 0) return 2;
    r = func_0034C200(D_00525600, D_00525640, a, buf, len > 0x1000 ? 0x1000 : len, &flags, 2);
    if (r < 0) {
        if (flags & 4) return 13;
        return 1;
    }
    if (flags & 4) return 13;
    *out = r;
    return 0;
}
#undef D_00525640 /* merge_units */
/* merge_units: end func_002F72D8 */

/* merge_units: begin func_002F73A8 */
typedef struct { char b[16]; } Addr;
#if 0 /* merge_units */
extern char D_00525640[];
#endif /* merge_units */
#define D_00525640 ((char*)&D_00525640) /* merge_units */

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
#undef D_00525640 /* merge_units */
/* merge_units: end func_002F73A8 */

/* merge_units: begin func_002F74C0 */
#if 0 /* merge_units */
extern char D_00525640[];
#endif /* merge_units */
#define D_00525640 ((char*)&D_00525640) /* merge_units */

extern int func_0034C3D8(char *, char *, int, unsigned short *, char *);
#if 0 /* merge_units */
extern int func_0034C840(char *, char *);
#endif /* merge_units */
#define func_0034C840(a0, a1) (func_0034C840((void *)(a0), (Addr *)(a1))) /* merge_units */

int func_002F74C0(int a, unsigned char *out, char *name, unsigned short *port)
{
    char buf[16];
    unsigned short p;
    int r;
    if (out == 0) return 2;
    *out = 0;
    if (D_004908A0 != 1) return 5;
    if (a < 0) return 2;
    if (name == 0) return 2;
    r = func_0034C3D8(D_00525600, D_00525640, a, &p, buf);
    if (r < 0) {
        if (r != -500) return 1;
        r = 0;
    }
    if (r > 0) {
        *out = 1;
        *port = p;
        if (func_0034C840(name, buf)) return 1;
    }
    return 0;
}
#undef D_00525640 /* merge_units */
#undef func_0034C840 /* merge_units */
/* merge_units: end func_002F74C0 */

/* merge_units: begin func_002F7590 */
extern int func_0034C6C0(int, int *);
int func_002F7590(int a, short *out)
{
    int fl = 0;
    unsigned char st = D_004908A0;
    int r;
    if (st != 1) return 5;
    if (a < 0) return 2;
    if (out == 0) return 2;
    *out = 0;
    r = func_0034C6C0(a, &fl);
    if (r < 0) {
        if (r == -0x1FE || r == -0x1FD || r == -0x1FC) return 0xD;
        return 1;
    }
    if (fl & 4) return 0xD;
    *out = r;
    return 0;
}
/* merge_units: end func_002F7590 */

/* merge_units: begin func_002F7628 */
extern char D_004908A8[];
extern void String_Copy(char *d, const char *s);
int func_002F7628(char *out)
{
    if (D_004908A0 != 1) return 5;
    if (out == 0) return 2;
    String_Copy(out, D_004908A8);
    return 0;
}
/* merge_units: end func_002F7628 */

/* merge_units: begin func_002F7670 */
extern char D_004908C0[];
int func_002F7670(char *out)
{
    if (D_004908A0 != 1) return 5;
    if (out == 0) return 2;
    String_Copy(out, D_004908C0);
    return 0;
}
/* merge_units: end func_002F7670 */

/* merge_units: begin func_002F76B8 */
#if 0 /* merge_units */
extern char D_00525640[];
#endif /* merge_units */
#define D_00525640 ((char*)&D_00525640) /* merge_units */

extern int func_0034AA50(char *, char *, int, char *, int, int, int);
extern int func_0034AB38(char *, char *, char *, int, char *);
int func_002F76B8(int a, char *out)
{
    char buf[16];
    if (D_004908A0 != 1) return 5;
    if (a == 0) return 2;
    if (out == 0) return 2;
    if (func_0034AA50(D_00525600, D_00525640, 0, buf, a, 0, 0) < 0) return 1;
    if (func_0034AB38(D_00525600, D_00525640, out, 0x10, buf) < 0) return 1;
    return 0;
}
#undef D_00525640 /* merge_units */
/* merge_units: end func_002F76B8 */

/* merge_units: begin func_002F7768 */
#if 0 /* merge_units */
extern char D_00525640[];
#endif /* merge_units */
#define D_00525640 ((char*)&D_00525640) /* merge_units */

extern int func_0034C690(char *, char *, int, int, char *, int);
int func_002F7768(int a, char *out)
{
    char buf[0x4C];
    unsigned char st = D_004908A0;
    if (st != 1) return 5;
    if (a < 0) return 2;
    if (out == 0) return 2;
    if (func_0034C690(D_00525600, D_00525640, a, 1, buf, 0x4C) != st) return 1;
    return func_0034AB38(D_00525600, D_00525640, out, 0x10, buf + 0x24) != 0;
}
#undef D_00525640 /* merge_units */
/* merge_units: end func_002F7768 */

/* merge_units: begin func_002F7818 */
extern int func_0034C890(char* p);
int func_002F7818(void)
{
    if (D_004908A0 != 1)
        return 5;
    return func_0034C890(D_00525600) != 0;
}
/* merge_units: end func_002F7818 */

/* merge_units: begin func_002F7850 */
extern int func_0034C8E0(int, int *);
int func_002F7850(int a, unsigned char *out)
{
    int v = 0;
    unsigned char st = D_004908A0;
    if (st != 1) return 5;
    if (a < 0) return 2;
    if (out == 0) return 2;
    *out = 0;
    if (func_0034C8E0(a, &v)) return 1;
    if (v) *out = st;
    return 0;
}
/* merge_units: end func_002F7850 */

/* merge_units: begin func_002F78D0 */
#if 0 /* merge_units */
extern char D_00525640[];
#endif /* merge_units */
#define D_00525640 ((char*)&D_00525640) /* merge_units */

extern int D_00525580[];
extern int D_004908D4;
extern int func_0034B230(void *a, void *b, int *list, int max);
extern int func_0034B2C0(void *a, void *b, int sock, int opt, int *out, int len);
extern int func_003060C0(void *t);
extern int func_003060F0(void *t, unsigned int *elapsed);
extern int func_003061F8(int ms);

/* Polls the socket list until one reports state 3 (stores it in D_004908D4) or ~95 s pass. */
int func_002F78D0(void)
{
    int timer[4];
    int info;
    unsigned int elapsed = 0;
    int found = 0;
    int n;
    int i;

    n = func_0034B230(D_00525600, D_00525640, D_00525580, 0x20);
    if (n <= 0) return 1;
    if (func_003060C0(timer)) return 1;
    for (;;) {
        for (i = 0; i < n; i++) {
            int sock = D_00525580[i];
            if (func_0034B2C0(D_00525600, D_00525640, sock, 8, &info, 4)) return 1;
            if ((info & 3) == 3) {
                found = 1;
                D_004908D4 = sock;
                break;
            }
        }
        if (found) break;
        if (func_003060F0(timer, &elapsed)) return 1;
        if (elapsed > 0x17318) return 1;
        if (func_003061F8(2)) return 1;
    }
    return 0;
}
#undef D_00525640 /* merge_units */
/* merge_units: end func_002F78D0 */

/* merge_units: begin func_002F7A30 */
extern void *memset(void *, int, unsigned int);
#if 0 /* merge_units */
extern char D_00525640[];
#endif /* merge_units */
#define D_00525640 ((char*)&D_00525640) /* merge_units */

extern int func_0034BCE0(char *, char *, int *, int, char *, int);
#if 0 /* merge_units */
extern int func_0034C840(char *, char *);
#endif /* merge_units */
#define func_0034C840(a0, a1) (func_0034C840((void *)(a0), (Addr *)(a1))) /* merge_units */

int func_002F7A30(char *out)
{
    char buf[16];
    int x;
    if (out == 0) return 2;
    memset(buf, 0, 0x10);
    if (func_0034BCE0(D_00525600, D_00525640, &x, 1, buf, 2) < 0) return 1;
    return func_0034C840(out, buf) != 0;
}
#undef D_00525640 /* merge_units */
#undef func_0034C840 /* merge_units */
/* merge_units: end func_002F7A30 */

/* merge_units: begin func_002F7AB0 */
#if 0 /* merge_units */
extern char D_00525640[];
#endif /* merge_units */
#define D_00525640 ((char*)&D_00525640) /* merge_units */

#if 0 /* merge_units */
extern int func_0034B2C0(char *, char *, int, int, char *, int);
#endif /* merge_units */
#define func_0034B2C0(a0, a1, a2, a3, a4, a5) (func_0034B2C0((void *)(a0), (void *)(a1), (a2), (a3), (int *)(a4), (a5))) /* merge_units */

#if 0 /* merge_units */
extern int func_0034C840(char *, char *);
#endif /* merge_units */
#define func_0034C840(a0, a1) (func_0034C840((void *)(a0), (Addr *)(a1))) /* merge_units */

int func_002F7AB0(char *out)
{
    char buf[16];
    if (out == 0) return 2;
    if (D_004908D4 < 0) return 1;
    memset(buf, 0, 0x10);
    if (func_0034B2C0(D_00525600, D_00525640, D_004908D4, 0xB, buf, 0x10)) return 1;
    return func_0034C840(out, buf) != 0;
}
#undef D_00525640 /* merge_units */
#undef func_0034B2C0 /* merge_units */
#undef func_0034C840 /* merge_units */
/* merge_units: end func_002F7AB0 */
