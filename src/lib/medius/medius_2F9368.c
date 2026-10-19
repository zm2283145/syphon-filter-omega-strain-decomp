/*
 * lib/medius: 4 files, 002F9368-002F95F8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002F9368 */
extern int func_002F7CE8(char *);
extern int func_002F7D68(int);
extern char *func_002F7ED8(int, int);
extern int func_002F7D28(int);
extern void Sha1_Digest(int, int, int *, int);
extern void func_002F4CD0(char *, int, int *, int);
int func_002F9368(int a, int b, char *c, int d)
{
    int buf[16];
    int buf2[16];
    int h;
    char *s;
    unsigned int i;
    if (d == 0) goto fail;
    if (func_002F7CE8(c)) return -1;
    h = func_002F7D68(a);
    if (h == 0) return -1;
    s = func_002F7ED8(h, b);
    if (s == 0) return -1;
    if (func_002F7D28(*(int *)(s + 0x18))) {
fail:
        return -1;
    }
    Sha1_Digest(*(int *)(s + 0x18), 4, buf, 0x40);
    func_002F4CD0(c, d, buf2, 0x40);
    i = 0;
    do {
        if (buf[i] != buf2[i]) goto fail;
    } while (++i < 16);
    return 0;
}
/* merge_units: end func_002F9368 */

/* merge_units: begin func_002F9460 */
#if 0 /* merge_units */
extern int func_002F7ED8(int, int);
#endif /* merge_units */
#define func_002F7ED8(a0, a1) ((int)func_002F7ED8((a0), (a1))) /* merge_units */

extern void func_002F7F10(int, int);
extern void func_002F7E20(int);
void func_002F9460(int a, int b)
{
    int l = func_002F7D68(a);
    int n = func_002F7ED8(l, b);
    if (n) {
        func_002F7F10(l, n);
        func_002F7E20(n);
    }
}
#undef func_002F7ED8 /* merge_units */
/* merge_units: end func_002F9460 */

/* merge_units: begin func_002F94D0 */
typedef struct L2F94D0 { struct L2F94D0 *next; struct L2F94D0 *prev; int a, sub; int b, c, d; void *h1C, *h20, *h24, *h28, *h2C; } L2F94D0;
extern L2F94D0 *D_004908D8;
#if 0 /* merge_units */
extern L2F94D0 *func_002F7D68(int);
#endif /* merge_units */
#define func_002F7D68(a0) ((L2F94D0 *)func_002F7D68((a0))) /* merge_units */

#if 0 /* merge_units */
extern void func_002F7F10(L2F94D0 *, int);
#endif /* merge_units */
#define func_002F7F10(a0, a1) (func_002F7F10((int)(a0), (a1))) /* merge_units */

extern void func_002FB3C0(void *);
void func_002F94D0(int id)
{
    L2F94D0 *p;
    int s;
    p = func_002F7D68(id);
    if (p == 0) return;
    while ((s = p->sub) != 0) {
        func_002F7F10(p, s);
        func_002F7E20(s);
    }
    if (p->h20) func_002FB3C0(&p->h20);
    if (p->h1C) func_002FB3C0(&p->h1C);
    if (p->h2C) func_002FB3C0(&p->h2C);
    if (p->h24) func_002FB3C0(&p->h24);
    if (p->h28) func_002FB3C0(&p->h28);
    if (D_004908D8 == p) D_004908D8 = p->prev;
    p->prev->next = p->next;
    p->next->prev = p->prev;
    if (D_004908D8 == p) D_004908D8 = 0;
    func_002FB3C0(&p);
}
#undef func_002F7D68 /* merge_units */
#undef func_002F7F10 /* merge_units */
/* merge_units: end func_002F94D0 */

/* merge_units: begin func_002F95F8 */
typedef struct N2F95F8 { int x0; struct N2F95F8 *next; int p8, pC; int key; } N2F95F8;
#if 0 /* merge_units */
extern N2F95F8 *D_004908D8;
#endif /* merge_units */
#define D_004908D8 (*(N2F95F8 **)&D_004908D8) /* merge_units */

#if 0 /* merge_units */
extern void func_002F94D0(int);
#endif /* merge_units */
#define func_002F94D0(a0) (func_002F94D0((a0))) /* merge_units */

void func_002F95F8(int key)
{
    N2F95F8 *n = D_004908D8;
    int k;
    if (n == 0) return;
    do {
        k = n->key;
        if ((key == -1 && k == key) || (key == (int)0x80000000 && k == (k & 0x7FFFFFFF) + key) || (key == 0 && k == (k & 0x7FFFFFFF))) {
            func_002F94D0(k);
            n = D_004908D8;
        } else {
            n = n->next;
            if (n == D_004908D8) n = 0;
        }
    } while (n);
}
#undef D_004908D8 /* merge_units */
#undef func_002F94D0 /* merge_units */
/* merge_units: end func_002F95F8 */
