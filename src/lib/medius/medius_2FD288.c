/*
 * lib/medius: 7 files, 002FD288-002FD670
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002FD288 */
typedef struct { unsigned char flag; char pad[3]; int x4; int x8; } S2FD288;
extern unsigned char D_004908EC;
extern S2FD288 D_005297E0;
extern unsigned int strlen(const char *);
extern int func_002F5FE8(int, unsigned char *, char *, unsigned short);
extern int func_003010C8(int);
int func_002FD288(unsigned char *out, char *name, unsigned short x)
{
    int r;
    if (out == 0) return 2;
    *out = 0;
    if (D_004908EC != 1) return 5;
    if (D_005297E0.flag != 1) return 5;
    if (name == 0) return 2;
    if (strlen(name) >= 0x10) return 2;
    r = func_003010C8(func_002F5FE8(D_005297E0.x4, out, name, x));
    __asm__ __volatile__("");
    return r;
}
/* merge_units: end func_002FD288 */

/* merge_units: begin func_002FD338 */
typedef struct { char pad[0x48]; unsigned int f48; unsigned int f4C; char q50[0x18]; char q68[4]; } S;
typedef struct { char pad[0x78]; S *sub[2]; } O;
extern int func_002FE860(unsigned short, O **);
extern int func_002F5818(void *, unsigned int *);
int func_002FD338(unsigned short id, unsigned int *a, unsigned int *b, unsigned int *pa, unsigned int *pb)
{
    unsigned int x = 0; unsigned int y = 0;
    O *o = 0;
    unsigned int s4c = 0;
    unsigned int s48 = 0;
    unsigned int sx = 0;
    unsigned int sy = 0;
    unsigned int i;
    int r;
    S *s;
    if (D_004908EC != 1) return 5;
    r = func_002FE860(id, &o);
    if (r) return r;
    for (i = 0; i < 2; i++) {
        s = o->sub[i];
        if (s) {
            if (func_002F5818(s->q68, &x)) return 0x15;
            sx += x;
            s48 += s->f48;
            if (func_002F5818(s->q50, &y)) return 0x15;
            s4c += s->f4C;
            sy += y;
        }
    }
    if (a) *a = sx;
    if (b) *b = sy;
    if (pa) {
        if (s48 == 0) return 1;
        *pa = sx * 100 / s48;
        if (*pa > 100) *pa = 100;
    }
    if (pb) {
        if (s4c != 0) {
            *pb = sy * 100 / s4c;
            if (*pb > 100) *pb = 100;
        } else return 1;
    }
    return 0;
}
/* merge_units: end func_002FD338 */

/* merge_units: begin func_002FD518 */
extern int func_002F63E8(void *p);
int func_002FD518(void *p)
{
    int r;
    if (D_004908EC != 1) return 5;
    if (p == 0) return 2;
    r = func_003010C8(func_002F63E8(p));
    __asm__ __volatile__(""); /* barrier: retail keeps jal + return, no sibling call */
    return r;
}
/* merge_units: end func_002FD518 */

/* merge_units: begin func_002FD560 */
extern int func_002F6400(void *p);
int func_002FD560(void *p)
{
    int r;
    if (D_004908EC != 1) return 5;
    if (p == 0) return 2;
    r = func_003010C8(func_002F6400(p));
    __asm__ __volatile__(""); /* barrier: retail keeps jal + return, no sibling call */
    return r;
}
/* merge_units: end func_002FD560 */

/* merge_units: begin func_002FD5A8 */
extern int func_002F6418(int, int);
int func_002FD5A8(int a, int b)
{
    if (D_004908EC != 1) return 5;
    if (a == 0) return 2;
    if (b == 0) return 2;
    {
        int r = func_003010C8(func_002F6418(a, b));
        __asm__ __volatile__("");
        return r;
    }
}
/* merge_units: end func_002FD5A8 */

/* merge_units: begin func_002FD5F8 */
#if 0 /* merge_units */
extern int func_002FE860(unsigned short, char **);
#endif /* merge_units */
#define func_002FE860(a0, a1) (func_002FE860((a0), (O * *)(a1))) /* merge_units */

extern void String_Copy(char *, char *);
int func_002FD5F8(unsigned short id, char *dst)
{
    char *p = 0;
    int r;
    if (D_004908EC != 1) return 5;
    if (dst == 0) return 2;
    r = func_002FE860(id, &p);
    if (r) return r;
    if (*(int *)(p + 8) != 8) return 0x17;
    String_Copy(dst, p + 0x5C);
    return 0;
}
#undef func_002FE860 /* merge_units */
/* merge_units: end func_002FD5F8 */

/* merge_units: begin func_002FD670 */
#if 0 /* merge_units */
extern int func_002FE860(unsigned short, char **);
#endif /* merge_units */
#define func_002FE860(a0, a1) (func_002FE860((a0), (O * *)(a1))) /* merge_units */

extern int func_003018E0(char *, int);
extern int NetConn_BufferMessage(int, int, int, char *, int, int);
int func_002FD670(unsigned short id, unsigned char f)
{
    char buf[16];
    char *p = 0;
    int r;
    if (D_004908EC != 1) return 5;
    r = func_002FE860(id, &p);
    if (r) return r;
    if (func_003018E0(buf, 2) || func_003018E0(buf + 1, f == 1)) return 7;
    return NetConn_BufferMessage(*(int *)(p + 0x80), 0xD, 0xFFFF, buf, 2, 0);
}
#undef func_002FE860 /* merge_units */
/* merge_units: end func_002FD670 */
