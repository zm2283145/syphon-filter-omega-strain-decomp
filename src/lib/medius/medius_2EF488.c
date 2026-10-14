/*
 * lib/medius: 4 files, 002EF488-002EF6E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002EF488 */
extern void func_002DA900(int, int *);
extern void func_002EDD08(char *, char *, int, int);
extern int func_002ED940(char *, int, char *, int, int);
int func_002EF488(char *s)
{
    char buf[16];
    int h = 0xFFFF;
    if (s == 0 || *(int *)(s + 0xC) == 0) return -1;
    func_002DA900(*(int *)(s + 8), &h);
    func_002EDD08(s, buf, 0xF, 0);
    return func_002ED940(s, h, buf, 0, 0);
}
/* merge_units: end func_002EF488 */

/* merge_units: begin func_002EF500 */
#if 0 /* merge_units */
extern void func_002DA900(void *, int *);
#endif /* merge_units */
#define func_002DA900(a0, a1) (func_002DA900((int)(a0), (a1))) /* merge_units */

extern void func_002F3450(char *);
extern void func_002ED620(char *);
void func_002EF500(char *s)
{
    char buf[16];
    int h = 0xFFFF;
    int i;
    func_002DA900(*(void **)(s + 8), &h);
    func_002EDD08(s, buf, 0x10, 0);
    func_002ED940(s, h, buf, 0, 0);
    func_002F3450(s + 0x50);
    for (i = 0; i < *(int *)(s + 0x5C); i++)
        func_002ED620(*(char **)(s + 0x60) + i * 0x14);
}
#undef func_002DA900 /* merge_units */
/* merge_units: end func_002EF500 */

/* merge_units: begin func_002EF5B0 */
#define F(p,T,o) (*(T *)((char *)(p) + (o)))
typedef struct { int w[8]; } S2EF5B0;
typedef struct { int key; char *obj; int type; int b; int c; } E2EF5B0;
extern int func_002F3220(char *);
int func_002EF5B0(void *s, int (*cb)(void *, int, S2EF5B0 *), int arg)
{
    int i;
    E2EF5B0 *e;
    S2EF5B0 tmp;
    for (i = 0; i < F(s, int, 0x5C); i++) {
        e = &F(s, E2EF5B0 *, 0x60)[i];
        if (e->type != 2) continue;
        if (e->obj == 0) continue;
        tmp = *(S2EF5B0 *)(e->obj + 0x20);
        if (func_002F3220(e->obj) & 0x4000) tmp.w[6] |= 0x8000;
        else tmp.w[6] &= ~0x8000;
        if (cb(F(s, void *, 8), arg, &tmp) == 0) break;
    }
    return 0;
}
/* merge_units: end func_002EF5B0 */

/* merge_units: begin func_002EF6E0 */
void func_002EF6E0(char *o)
{
    int i;
    for (i = 0; i < *(int *)(o + 0x5C); i++)
        func_002ED620(*(char **)(o + 0x60) + i * 0x14);
}
/* merge_units: end func_002EF6E0 */
