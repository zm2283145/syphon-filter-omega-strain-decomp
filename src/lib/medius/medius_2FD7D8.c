/*
 * lib/medius: 3 files, 002FD7D8-002FD8F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002FD7D8 */
extern unsigned char D_004908EC;
extern int func_002FE860(unsigned short, char **);
int func_002FD7D8(unsigned short id, int v)
{
    char *p = 0;
    unsigned int i;
    char **pp;
    int r;
    if (D_004908EC != 1) return 5;
    r = func_002FE860(id, &p);
    if (r) return r;
    pp = (char **)(p + 0x78);
    for (i = 0; i < 2; i++, pp++)
        if (*pp) *(int *)(*pp + 0x40) = v;
    return 0;
}
/* merge_units: end func_002FD7D8 */

/* merge_units: begin func_002FD860 */
extern int func_00301988(char *, unsigned short);
extern int NetConn_BufferMessage(int, int, int, char *, int, int);
int func_002FD860(unsigned short id, int x)
{
    char buf[16];
    char *p = 0;
    int r;
    if (D_004908EC != 1) return 5;
    r = func_002FE860(id, &p);
    if (r) return r;
    if (func_00301988(buf, x)) return 7;
    return NetConn_BufferMessage(*(int *)(p + 0x80), 0xE, 0xFFFF, buf, 2, 0);
}
/* merge_units: end func_002FD860 */

/* merge_units: begin func_002FD8F0 */
extern void *memset(void *, int, unsigned long);
typedef struct { int x0; char p4[0x14]; short x18; short p1a; int p1c; int x20, x24, x28, x2C, x30; short x34; short p36; int p38; int x3C, x40, x44, x48; } S2FD8F0;
int func_002FD8F0(S2FD8F0 *s)
{
    if (s == 0) return 2;
    memset(s, 0, 0x4C);
    s->x0 = 0;
    s->x18 = 0x275B;
    s->x20 = 0x3A98;
    s->x24 = 0x1E;
    s->x30 = 0;
    s->x34 = 0;
    s->x3C = 0;
    s->x40 = 0;
    s->x44 = 0;
    s->x2C = 0x8000;
    s->x28 = 0x8000;
    return 0;
}
/* merge_units: end func_002FD8F0 */
