/*
 * lib/medius: 4 files, 002D88C0-002D8A98
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002D88C0 */
typedef struct { int x; } A;
typedef struct { char p[0x18]; int f18; char p2[0x848 - 0x1C]; int f848; } B;
extern unsigned int func_002F3220(B *);
extern int func_003138C0(int, int *, char *, int);
extern int func_002D9EC8(A *, B *, int, char *, int);
extern int func_002D8AD8(A *);
extern int func_002F4180(int, int);
extern int func_002F3228(B *, int);
extern int func_002F3238(B *, int);
int func_002D88C0(A *a, B *b)
{
    char buf[0x800];
    int from[1];
    int total = 0;
    int n;
    unsigned int flags = func_002F3220(b);
    if (flags & 0x2000) {
        int sum = 0;
        from[0] = 0;
        do {
            n = func_003138C0(b->f848, from, buf, 0x800);
            sum += n;
            if (sum == 0 || n != 0) total += func_002D9EC8(a, b, from[0], buf, n);
        } while (n != 0);
        if (!(flags & 0x4000)) {
            func_002F4180(func_002D8AD8(a), b->f848);
            b->f848 = 0;
            func_002F3228(b, 0x1000);
        }
        func_002F3238(b, 0x2000);
    } else if (flags & 0x1000) func_002D9EC8(a, b, b->f18, buf, 0);
    return total;
}
/* merge_units: end func_002D88C0 */

/* merge_units: begin func_002D89E0 */
extern int func_002D8708(int, char *, int);
extern void func_002DA290(int, char *, int);
void func_002D89E0(int a)
{
    char buf[0x7E00];
    int n = func_002D8708(a, buf, 0x7E00);
    if (n > 0) func_002DA290(a, buf, n);
}
/* merge_units: end func_002D89E0 */

/* merge_units: begin func_002D8A28 */
typedef struct { char p0[0x74]; int x74; char p78[0x90 - 0x78]; int x90; int x94; char p98[0xBC - 0x98]; int xBC; char pC0[0xD4 - 0xC0]; int xD4; } T2D8A28;
extern void Net_AllocZeroed(void *, unsigned long);
extern void *memset(void *, int, unsigned int);
T2D8A28 *func_002D8A28(void)
{
    T2D8A28 *p = 0;
    Net_AllocZeroed(&p, sizeof(T2D8A28));
    if (p != 0) {
        memset(p, 0, sizeof(T2D8A28));
        p->x90 = 0;
        p->x94 = 0;
        p->xBC = 0;
        p->xD4 = 0;
        p->x74 = 0;
    }
    return p;
}
/* merge_units: end func_002D8A28 */

/* merge_units: begin func_002D8A98 */
extern void func_002F3F00(int, int);
extern void func_002D8E40(char *);
void func_002D8A98(char *o)
{
    int v = *(int *)(o + 0x60);
    if (v) {
        func_002F3F00(*(int *)(o + 0x5C), v);
        *(int *)(o + 0x60) = 0;
        *(int *)(o + 0x90) = 0;
    }
    func_002D8E40(o);
}
/* merge_units: end func_002D8A98 */
