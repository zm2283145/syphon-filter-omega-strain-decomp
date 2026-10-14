/*
 * lib/medius: 3 files, 002D90C0-002D9190
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002D90C0 */
extern void func_002DA4E0(char *, int);
extern void func_002EF500(int);
void func_002D90C0(char *o)
{
    int n = *(int *)(o + 0x98);
    if (n > 0) func_002DA4E0(o, n);
    if (*(int *)(o + 0x64)) func_002EF500(*(int *)(o + 0x64));
    *(int *)(o + 0x70) &= ~2;
}
/* merge_units: end func_002D90C0 */

/* merge_units: begin func_002D9118 */
extern int func_002D9CE0(int, char *, int, int *, int *);
extern int func_002D96C8(int, int, int, char *, int);
int func_002D9118(int a)
{
    char buf[0x500];
    int len;
    int x = 0;
    int r = 0;
    int n;
    for (;;) {
        n = func_002D9CE0(a, buf, 0x500, &len, &x);
        if (n < 0) { r = -1; break; }
        if (n == 0) break;
        if (func_002D96C8(a, len, x, buf, n)) { r = -1; break; }
    }
    return r;
}
/* merge_units: end func_002D9118 */

/* merge_units: begin func_002D9190 */
typedef struct S S;
struct S {
    char p[0x48];
    int (*read)(S *, int *, char *, int);
    char p4c[0x58 - 0x4C];
    int f58;
    int f5c;
    int f60;
    char p64[0x90 - 0x64];
    int f90;
};
extern int func_002DA050(S *, int, char *, int);
int func_002D9190(S *s, int now)
{
    char buf[0x800];
    int from[1];
    int total = 0;
    int n;
    from[0] = 0;
    do {
        n = s->read(s, from, buf, 0x800);
        total += n;
        if (n > 0) {
            func_002DA050(s, from[0], buf, n);
            s->f58 = now;
        } else if (total == 0 && s->f60) {
            func_002DA050(s, from[0], buf, -1);
        }
        if (n < 0x800 && (n <= 0 || from[0] != 0x3F)) break;
    } while (n > 0);
    if (total == 0 && s->f60 && now - s->f58 >= 0x5DD) func_002DA050(s, s->f90, buf, 0);
    return total;
}
/* merge_units: end func_002D9190 */
