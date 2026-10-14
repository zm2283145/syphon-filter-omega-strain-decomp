/*
 * lib/medius: 11 files, 002F5C10-002F6330
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002F5C10 */
extern int D_0049089C;
extern int func_002F7B60(void);
int func_002F5C10(void)
{
    int r;
    if (D_0049089C <= 0) return 4;
    if (--D_0049089C == 0 && (r = func_002F7B60()) != 0) return r;
    return 0;
}
/* merge_units: end func_002F5C10 */

/* merge_units: begin func_002F5C58 */
extern void *memset(void *, int, unsigned int);
int func_002F5C58(int *p)
{
    if (p == 0) return 2;
    memset(p, 0, 0xC);
    p[0] = 0;
    return 0;
}
/* merge_units: end func_002F5C58 */

/* merge_units: begin func_002F5C98 */
typedef struct { int a; int b; int c; } Opts;
typedef struct { unsigned char f0; unsigned char used; char pad2[2]; int f4; Opts opts; unsigned short port; char name[1]; } Ent;
extern int func_002F66B8(int *);
extern int func_002F6758(int, Ent **);
#if 0 /* merge_units */
extern int func_002F5C58(Opts *);
#endif /* merge_units */
#define func_002F5C58(a0) (func_002F5C58((int *)(a0))) /* merge_units */

extern int func_002F7B78(int *, char *, unsigned short *, Opts *, char *);
extern int func_002F6728(int);
int func_002F5C98(int *out, char *name, unsigned short port, Opts *opts)
{
    int id;
    Ent *e = 0;
    int r;
    if (out == 0) return 2;
    *out = 0;
    r = func_002F66B8(&id);
    if (r) return r;
    r = func_002F6758(id, &e);
    if (r) return r;
    if (e == 0) return 0xA;
    if (opts) {
        e->opts = *opts;
    } else {
        r = func_002F5C58(&e->opts);
        if (r) goto err;
    }
    r = func_002F7B78(&e->f4, name, &port, &e->opts, e->name);
    if (r) {
err:
        func_002F6728(id);
        return r;
    }
    e->port = port;
    e->used = 1;
    *out = id;
    return 0;
}
#undef func_002F5C58 /* merge_units */
/* merge_units: end func_002F5C98 */

/* merge_units: begin func_002F5DB0 */
extern int func_002F6770(int, char **);
extern void func_002F7B90(int);
int func_002F5DB0(int a)
{
    char *p = 0;
    int r = func_002F6770(a, &p);
    if (r) return r;
    if (p == 0) return 0xA;
    func_002F7B90(*(int *)(p + 4));
    p[1] = 0;
    p[0] = 0;
    return func_002F6728(a);
}
/* merge_units: end func_002F5DB0 */

/* merge_units: begin func_002F5E10 */
extern int func_002F6628(int, unsigned char *);
extern int func_002F7BA8(int, int, unsigned short, unsigned short *);
extern int func_002F6878(unsigned short, int, int);
int Socket_WriteConnected(int a, int b, unsigned short c, unsigned short *out)
{
    unsigned char ok;
    char *p = 0;
    int r, t;
    if (out == 0) return 2;
    *out = 0;
    if (b == 0) return 2;
    r = func_002F6770(a, &p);
    if (r) return r;
    if (p == 0) return 0xA;
    t = *(int *)(p + 8);
    if (t != 0 && t != 2) return 0xC;
    if (((unsigned char *)p)[0x16] == 0 && *(int *)(p + 8) == 0) {
        ok = 0;
        r = func_002F6628(a, &ok);
        if (r) return r;
        if (ok == 0) {
            *out = 0;
            return r;
        }
        p[0x16] = 1;
    }
    r = func_002F7BA8(*(int *)(p + 4), b, c, out);
    if (r) return r;
    return func_002F6878(*out, 0, 0x28);
}
/* merge_units: end func_002F5E10 */

/* merge_units: begin func_002F5F20 */
extern int func_002F7BC0(int, int, unsigned short, int, unsigned short, unsigned short *);
int Socket_WriteAddressed(int a, int b, unsigned short c, int d, unsigned short e, unsigned short *out)
{
    char *p = 0;
    int r;
    if (b == 0) return 2;
    if (out == 0) return 2;
    *out = 0;
    if (d == 0) return 2;
    r = func_002F6770(a, &p);
    if (r) return r;
    if (p == 0) return 0xA;
    if (*(int *)(p + 8) != 1) return 0xC;
    r = func_002F7BC0(*(int *)(p + 4), b, c, d, e, out);
    if (r) return r;
    return func_002F6878(*out, 0, 0x1C);
}
/* merge_units: end func_002F5F20 */

/* merge_units: begin func_002F5FE8 */
extern int func_002F7BE0(int, char *, int, unsigned short);
#if 0 /* merge_units */
extern int func_002F6878(int, int, int);
#endif /* merge_units */
#define func_002F6878(a0, a1, a2) (func_002F6878((unsigned short)(a0), (a1), (a2))) /* merge_units */

int func_002F5FE8(int a, char *b, int c, unsigned short d)
{
    char *p = 0;
    int r;
    if (b == 0) return 2;
    *b = 0;
    if (c == 0) return 2;
    r = func_002F6770(a, &p);
    if (r) return r;
    if (p == 0) return 0xA;
    if (*(int *)(p + 8) != 3) return 0xC;
    r = func_002F7BE0(*(int *)(p + 4), b, c, d);
    if (r) return r;
    return func_002F6878(0x1C, 0, 0);
}
#undef func_002F6878 /* merge_units */
/* merge_units: end func_002F5FE8 */

/* merge_units: begin func_002F6090 */
extern int func_002F7BF8(int, int, unsigned short, unsigned short *);
#if 0 /* merge_units */
extern int func_002F6878(int, unsigned short, int);
#endif /* merge_units */
#define func_002F6878(a0, a1, a2) (func_002F6878((unsigned short)(a0), (int)(a1), (a2))) /* merge_units */

int func_002F6090(int a, int b, unsigned short c, unsigned short *out)
{
    unsigned char ok;
    char *p = 0;
    int r, t;
    if (out == 0) return 2;
    *out = 0;
    if (b == 0) return 2;
    r = func_002F6770(a, &p);
    if (r) return r;
    if (p == 0) return 0xA;
    t = *(int *)(p + 8);
    if (t != 0 && t != 2) return 0xC;
    if (((unsigned char *)p)[0x16] == 0 && *(int *)(p + 8) == 0) {
        ok = 0;
        r = func_002F6628(a, &ok);
        if (r) return r;
        if (ok == 0) {
            *out = 0;
            return r;
        }
        p[0x16] = 1;
    }
    r = func_002F7BF8(*(int *)(p + 4), b, c, out);
    if (r) return r;
    return func_002F6878(0, *out, 0x28);
}
#undef func_002F6878 /* merge_units */
/* merge_units: end func_002F6090 */

/* merge_units: begin func_002F61A0 */
extern int func_002F7C10(int, int, int, int, unsigned short, unsigned short *);
#if 0 /* merge_units */
extern int func_002F6878(int, unsigned short, int);
#endif /* merge_units */
#define func_002F6878(a0, a1, a2) (func_002F6878((unsigned short)(a0), (int)(a1), (a2))) /* merge_units */

int func_002F61A0(int a, int b, int c, int d, unsigned short e, unsigned short *out)
{
    char *p = 0;
    int r;
    if (b == 0) return 2;
    if (out == 0) return 2;
    *out = 0;
    if (d == 0) return 2;
    r = func_002F6770(a, &p);
    if (r) return r;
    if (p == 0) return 0xA;
    if (*(int *)(p + 8) != 1) return 0xC;
    r = func_002F7C10(*(int *)(p + 4), b, c, d, e, out);
    if (r) return r;
    return func_002F6878(0, *out, 0x1C);
}
#undef func_002F6878 /* merge_units */
/* merge_units: end func_002F61A0 */

/* merge_units: begin func_002F6268 */
extern int func_002F7C28(int, unsigned char *, int, int);
#if 0 /* merge_units */
extern int func_002F6878(int, int, int);
#endif /* merge_units */
#define func_002F6878(a0, a1, a2) (func_002F6878((unsigned short)(a0), (a1), (a2))) /* merge_units */

int func_002F6268(int a, unsigned char *out, int c, int d)
{
    char *p = 0;
    int r;
    if (out == 0) return 2;
    *out = 0;
    if (c == 0) return 2;
    if (d == 0) return 2;
    r = func_002F6770(a, &p);
    if (r) return r;
    if (p == 0) return 0xA;
    if (*(int *)(p + 8) != 3) return 0xC;
    r = func_002F7C28(*(int *)(p + 4), out, c, d);
    if (r) return r;
    if (*out == 1) {
        r = func_002F6878(0, 0x1C, 0);
        if (r) return r;
    }
    return 0;
}
#undef func_002F6878 /* merge_units */
/* merge_units: end func_002F6268 */

/* merge_units: begin func_002F6330 */
extern int func_002F7C40(int, unsigned short *);
int func_002F6330(int a, unsigned short *out)
{
    unsigned char ok;
    char *p = 0;
    int r;
    if (out == 0) return 2;
    *out = 0;
    r = func_002F6770(a, &p);
    if (r) return r;
    if (p == 0) return 0xA;
    if (((unsigned char *)p)[0x16] == 0 && *(int *)(p + 8) == 0) {
        ok = 0;
        r = func_002F6628(a, &ok);
        if (r) return r;
        if (ok == 0) {
            *out = 0;
            return r;
        }
        p[0x16] = 1;
    }
    return func_002F7C40(*(int *)(p + 4), out);
}
/* merge_units: end func_002F6330 */
