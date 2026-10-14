/*
 * lib/medius: 2 files, 002DA050-002DA290
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002DA050 */
typedef struct { unsigned char type; unsigned char x; unsigned short c; unsigned short port; unsigned short y; } M2DA050;
extern char *func_002DA338(char *);
extern unsigned char func_002ED938(char *);
extern unsigned short func_002D8B20(char *);
extern void func_002ED940(char *, int, M2DA050 *, char *, int);
extern void func_002D8AE0(char *);
extern void func_002F3F00(int, int);
extern int func_002EF920(char *);
extern int func_002F3C00(int, int, int);
extern int func_002DC298(int);
extern int func_002DC2A8(int, char *, int, char *, int);
int func_002DA050(char *s, int type, char *buf, int len)
{
    M2DA050 m;
    char data[0x1E0];
    int total = 0;
    int sz;
    int t;
    int n;
    int a;
    char *h = func_002DA338(s);
    if (h == 0) return 0;
    a = *(int *)(s + 0x60);
    if (len != 0) {
        if (*(int *)(s + 0x90) != type) {
            if (a != 0) {
                func_002F3F00(*(int *)(s + 0x5C), a);
                *(int *)(s + 0x60) = 0;
                a = 0;
            }
            *(int *)(s + 0x90) = 0;
        }
        if (a == 0) {
            int v = func_002F3C00(*(int *)(s + 0x5C), type, func_002EF920(h));
            *(int *)(s + 0x60) = v;
            if (v == 0) {
                *(int *)(s + 0x90) = 0;
                return 0;
            }
            *(int *)(s + 0x90) = type;
            func_002D8AE0(s);
            a = *(int *)(s + 0x60);
        }
    }
    sz = 0x88;
    if (a != 0) sz = func_002DC298(a) << 2;
    switch (type) {
    case 0x21: m.type = 0x20; sz = 0xF0; break;
    case 0x22: m.type = 0x21; break;
    case 0x24: m.type = 0x23; break;
    case 0x23: m.type = 0x22; break;
    case 0x3F:
    default: m.type = 0x2F; sz = 0x1E0; break;
    }
    m.type |= 0x80;
    *(volatile unsigned short *)&m.port = *(unsigned short *)(s + 0x78);
    m.x = func_002ED938(h);
    if (len == 0) {
        m.y = func_002D8B20(s);
        m.c = 0;
        func_002ED940(h, *(int *)(s + 0x78), &m, data, 0);
        a = *(int *)(s + 0x60);
        if (a != 0) {
            func_002F3F00(*(int *)(s + 0x5C), a);
            *(int *)(s + 0x60) = 0;
        }
        *(int *)(s + 0x90) = 0;
        return 0;
    }
    if (len == -1) len = 0;
loop:
        n = func_002DC2A8(*(int *)(s + 0x60), buf, len, data, sz);
        len = 0;
        if (n <= 0) return total;
        total += n;
        m.y = func_002D8B20(s);
        m.c = n;
        func_002ED940(h, *(int *)(s + 0x78), &m, data, m.c);
    goto loop;
}
/* merge_units: end func_002DA050 */

/* merge_units: begin func_002DA290 */
typedef struct { unsigned char type; unsigned char x; unsigned short c; unsigned short port; unsigned short y; } M2DA290;
extern char *func_002DA3A0(char *);
#if 0 /* merge_units */
extern void func_002ED940(char *, int, M2DA290 *, int, int);
#endif /* merge_units */
#define func_002ED940(a0, a1, a2, a3, a4) (func_002ED940((a0), (a1), (M2DA050 *)(a2), (char *)(a3), (a4))) /* merge_units */

extern void func_002D8AE8(char *);
int func_002DA290(char *s, int b, int c)
{
    M2DA290 m; int t;
    char *h = func_002DA3A0(s);
    if (h == 0) return 0;
    t = 0xB0; m.type = t;
    m.port = *(unsigned short *)(s + 0x78);
    m.x = func_002ED938(h);
    m.c = c;
    m.y = func_002D8B20(s);
    func_002ED940(h, *(int *)(s + 0x78), &m, b, m.c);
    if (c == 0) func_002D8AE8(s);
    return c;
}
#undef func_002ED940 /* merge_units */
/* merge_units: end func_002DA290 */
