/*
 * lib/medius: 5 files, 002DA4E0-002DA880
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002DA4E0 */
extern void func_002EDD08(int, char *, int, int);
extern int func_002ED940(int, int, char *, unsigned short *, int);
extern char *func_002D9E18(char *, int);
extern void func_002EF878(char *, int);
extern void func_002EF6E0(char *);
extern void func_002F3198(int, int);
extern void func_002D9EB0(char *, int);
int func_002DA4E0(char *s, int id)
{
    char buf[16];
    unsigned short v;
    int r;
    char *n;
    if (id == 0 || id != *(int *)(s + 0x98)) return -1;
    v = id;
    func_002EDD08(*(int *)(s + 0x64), buf, 0xA, 2);
    r = func_002ED940(*(int *)(s + 0x64), *(int *)(s + 0x78), buf, &v, 2);
    n = func_002D9E18(s, *(int *)(s + 0x98));
    if (n) {
        func_002EF878(n, *(int *)(s + 0x78));
        func_002EF6E0(n);
    }
    *(int *)(s + 0x98) = 0;
    func_002F3198(*(int *)(s + 0x68), 0);
    func_002D9EB0(s, 4);
    return r;
}
/* merge_units: end func_002DA4E0 */

/* merge_units: begin func_002DA5A8 */
extern void func_002EDCB0(char *, char *);
extern char *func_002ED898(char *);
int func_002DA5A8(char *s, int (*cb)(char *, int, char *), int arg)
{
    char buf[0x40];
    char *n = *(char **)(s + 0x64);
    if (cb == 0) return -1;
    while (n) {
        func_002EDCB0(n, buf);
        if (!cb(s, arg, buf)) break;
        n = func_002ED898(n);
        if (n == *(char **)(s + 0x64)) n = 0;
    }
    return 0;
}
/* merge_units: end func_002DA5A8 */

/* merge_units: begin func_002DA640 */
typedef struct { char b[0x18]; unsigned int flags; char c[4]; } I2DA640;
extern int func_002F3220(char *);
int func_002DA640(char *s, int (*cb)(char *, int, I2DA640 *), int arg)
{
    I2DA640 info;
    char *n, *head;
    if (cb == 0 || *(int *)(s + 0x64) == 0) return -1;
    n = *(char **)(s + 0x6C);
    head = n;
    while (n) {
        info = *(I2DA640 *)(n + 0x20);
        if (func_002F3220(n) & 0x4000) info.flags |= 0x8000;
        else info.flags &= ~0x8000;
        if (!cb(s, arg, &info)) break;
        n = *(char **)(n + 4);
        if (n == head) n = 0;
    }
    return 0;
}
/* merge_units: end func_002DA640 */

/* merge_units: begin func_002DA750 */
typedef struct { unsigned char b[32]; } S2DA750;
typedef struct N2DA750 { int a; struct N2DA750 *next; char *obj; } N2DA750;
#if 0 /* merge_units */
extern int func_002D9E18(int, int);
#endif /* merge_units */
#define func_002D9E18(a0, a1) ((int)func_002D9E18((char *)(a0), (a1))) /* merge_units */

extern N2DA750 *func_002ED8F8(int);
int func_002DA750(int a, int (*cb)(int, int, S2DA750 *), int arg, int key)
{
    int v = func_002D9E18(a, key);
    N2DA750 *n, *head;
    S2DA750 tmp;
    if (cb == 0 || v == 0) return -1;
    n = head = func_002ED8F8(v);
    while (n) {
        tmp = *(S2DA750 *)(n->obj + 0x20);
        if (func_002F3220(n->obj) & 0x4000) ((int *)&tmp)[6] |= 0x8000;
        else ((int *)&tmp)[6] &= ~0x8000;
        if (cb(a, arg, &tmp) == 0) break;
        n = n->next;
        if (n == head) n = 0;
    }
    return 0;
}
#undef func_002D9E18 /* merge_units */
/* merge_units: end func_002DA750 */

/* merge_units: begin func_002DA880 */
#if 0 /* merge_units */
extern int func_002D9E18(int, int);
#endif /* merge_units */
#define func_002D9E18(a0, a1) ((int)func_002D9E18((char *)(a0), (a1))) /* merge_units */

extern int func_002EF5B0(int, int, int);
int func_002DA880(int a, int b, int c, int d)
{
    int h = func_002D9E18(a, d);
    if (b == 0 || h == 0) return -1;
    return func_002EF5B0(h, b, c);
}
#undef func_002D9E18 /* merge_units */
/* merge_units: end func_002DA880 */
