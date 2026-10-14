/*
 * lib/medius: 6 files, 002F2FA8-002F3198
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002F2FA8 */
typedef struct N2FA8 { int pad; struct N2FA8 *next; char pad2[0x2C]; int id; } N2FA8;
N2FA8 *func_002F2FA8(N2FA8 *head, int id)
{
    N2FA8 *n = head;
    while (n && n->id != id) {
        n = n->next;
        if (n == head) n = 0;
    }
    return n;
}
/* merge_units: end func_002F2FA8 */

/* merge_units: begin func_002F2FD8 */
typedef struct N2FD8 { int pad; struct N2FD8 *next; } N2FD8;
int func_002F2FD8(N2FD8 *head)
{
    N2FD8 *n;
    int c = 0;
    for (n = head; n; c++) {
        n = n->next;
        if (n == head) n = 0;
    }
    return c;
}
/* merge_units: end func_002F2FD8 */

/* merge_units: begin func_002F3010 */
typedef struct S3010 { struct S3010 *a, *b; int c; int d[3]; int x18; } S3010;
extern void Net_AllocZeroed(void *, int);
S3010 *func_002F3010(int c)
{
    S3010 *p = 0;
    Net_AllocZeroed(&p, 0x860);
    if (p) {
        p->b = p->a = p;
        p->c = c;
        p->x18 = 0;
    }
    return p;
}
/* merge_units: end func_002F3010 */

/* merge_units: begin func_002F3068 */
typedef struct { char b[32]; } Blk2F3068;
typedef struct S2F3068 { struct S2F3068 *a, *b; int c; int d; int pad[4]; Blk2F3068 key; } S2F3068;
#if 0 /* merge_units */
extern S2F3068 *func_002F3010(int c);
#endif /* merge_units */
#define func_002F3010(a0) ((S2F3068 *)func_002F3010((a0))) /* merge_units */

S2F3068 *func_002F3068(int c, Blk2F3068 *key)
{
    S2F3068 *p = func_002F3010(c);
    if (p) {
        p->key = *key;
        p->d = 0;
    }
    return p;
}
#undef func_002F3010 /* merge_units */
/* merge_units: end func_002F3068 */

/* merge_units: begin func_002F30E0 */
extern void func_002D7768(int);
extern void func_00315EB0(int);
extern int func_002D8AD8(int);
extern void func_002F4180(int, int);
extern void func_002F3F00(int, int);
extern void func_002FB3C0(void *);
void func_002F30E0(char *s)
{
    if (s == 0) return;
    if (*(int *)(s + 0x840)) {
        func_002D7768(*(int *)(s + 0x840));
        *(int *)(s + 0x840) = 0;
    }
    if (*(int *)(s + 0x844)) {
        func_00315EB0(*(int *)(s + 0x844));
        *(int *)(s + 0x844) = 0;
    }
    if (*(int *)(s + 0x848)) {
        func_002F4180(func_002D8AD8(*(int *)(s + 8)), *(int *)(s + 0x848));
        *(int *)(s + 0x848) = 0;
    }
    if (*(int *)(s + 0x84C)) {
        func_002F3F00(func_002D8AD8(*(int *)(s + 8)), *(int *)(s + 0x84C));
        *(int *)(s + 0x84C) = 0;
    }
    func_002FB3C0(&s);
}
/* merge_units: end func_002F30E0 */

/* merge_units: begin func_002F3198 */
extern char *func_002D9E18(int, int);
extern void func_002EF878(char *, int);
extern void func_002EF748(char *, char *);
void func_002F3198(char *s, int v)
{
    if (*(int *)(s + 0x30) == v) return;
    if (*(int *)(s + 0x30) > 0) func_002EF878(func_002D9E18(*(int *)(s + 8), *(int *)(s + 0x30)), *(int *)(s + 0x34));
    *(int *)(s + 0x30) = v;
    if (v <= 0) return;
    func_002EF748(func_002D9E18(*(int *)(s + 8), v), s);
}
/* merge_units: end func_002F3198 */
