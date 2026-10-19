/*
 * lib/medius: 7 files, 002E5420-002E5770
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002E5420 */
typedef struct { int v[256]; } T2E5420;
extern int func_002E51B8(unsigned int, T2E5420 **);
extern void func_002DD328(int *);
int func_002E5420(unsigned int a, unsigned int b)
{
    T2E5420 *p = 0;
    int r;
    if (a >= 4) return 0x17;
    if (b >= 0x100) return 0x17;
    r = func_002E51B8(a, &p);
    if (r) return r;
    if (p) {
        if (p->v[b]) func_002DD328(&p->v[b]);
        p->v[b] = 0;
    }
    return 0;
}
/* merge_units: end func_002E5420 */

/* merge_units: begin func_002E54A0 */
#if 0 /* merge_units */
extern int func_002E51B8(unsigned int, void **);
#endif /* merge_units */
#define func_002E51B8(a0, a1) (func_002E51B8((a0), (T2E5420 * *)(a1))) /* merge_units */

void *func_002E54A0(unsigned int slot)
{
    void *p = 0;
    if (slot >= 4) return 0;
    if (func_002E51B8(slot, &p) == 0 && p != 0) return (char *)p + 0x408;
    return 0;
}
#undef func_002E51B8 /* merge_units */
/* merge_units: end func_002E54A0 */

/* merge_units: begin func_002E54E8 */
#if 0 /* merge_units */
extern int func_002E51B8(unsigned int, char **);
#endif /* merge_units */
#define func_002E51B8(a0, a1) (func_002E51B8((a0), (T2E5420 * *)(a1))) /* merge_units */

extern char *strncpy(char *, const char *, unsigned int);
int func_002E54E8(unsigned int a, const char *s)
{
    char *p = 0;
    int r;
    if (a >= 4) return 8;
    if (s == 0) return 0x17;
    r = func_002E51B8(a, &p);
    if (r) return r;
    if (p == 0) return r;
    strncpy(p + 0x408, s, 0x10);
    return 0;
}
#undef func_002E51B8 /* merge_units */
/* merge_units: end func_002E54E8 */

/* merge_units: begin func_002E5550 */
#if 0 /* merge_units */
extern int func_002E51B8(unsigned int, int *);
#endif /* merge_units */
#define func_002E51B8(a0, a1) (func_002E51B8((a0), (T2E5420 * *)(a1))) /* merge_units */

int func_002E5550(unsigned int a, int v)
{
    int p = 0;
    int r;
    if (a >= 4) return 8;
    r = func_002E51B8(a, &p);
    if (r) return r;
    if (p) *(int *)(p + 0x404) = v;
    return 0;
}
#undef func_002E51B8 /* merge_units */
/* merge_units: end func_002E5550 */

/* merge_units: begin func_002E55A0 */
typedef struct { int a; unsigned short id; short p; int type; void (*cb)(int, void *, int, int, int, int); int time; int x; int y; } E2E55A0;
typedef struct { int t[4]; } T2E55A0;
extern E2E55A0 D_0058D188[];
extern char D_005880A0[];
extern short D_0058D178;
extern int func_00306018(int *);
extern void Net_IpToString(void *, E2E55A0 *);
int func_002E55A0(void)
{
    T2E55A0 tmp;
    int now;
    unsigned int i;
    func_00306018(&now);
    for (i = 0; i < 127; i++) {
        if (D_0058D188[i].cb == 0) continue;
        if (now - D_0058D188[i].time - 30000 <= 0) continue;
        Net_IpToString(&tmp, &D_0058D188[i]);
        Net_IpToString(D_005880A0, &D_0058D188[i]);
        D_0058D178 = D_0058D188[i].id;
        if (D_0058D188[i].type == 1)
            D_0058D188[i].cb(0xE, &tmp, 0, 0, D_0058D188[i].x, D_0058D188[i].y);
        else
            ((void (*)(int, void *, int, int))D_0058D188[i].cb)(0xE, &tmp, 0, 0);
        D_0058D188[i].cb = 0;
    }
    return 0;
}
/* merge_units: end func_002E55A0 */

/* merge_units: begin func_002E56D0 */
extern int D_0048C4B0;
#if 0 /* merge_units */
extern int func_002E51B8(unsigned int, char **);
#endif /* merge_units */
#define func_002E51B8(a0, a1) (func_002E51B8((a0), (T2E5420 * *)(a1))) /* merge_units */

extern int func_00302B88(int, int *);
int func_002E56D0(unsigned char *out)
{
    char *p = 0;
    int st = -2;
    int r;
    if (out == 0) return 0x17;
    *out = 0;
    r = func_002E51B8(0, &p);
    if (r) return r;
    if (p == 0) return 0;
    if (func_00302B88(D_0048C4B0, &st)) return 0x25;
    if (*(int *)(p + 0x400) != 0x100 && st == *(int *)(p + 0x400)) *out = 1;
    return 0;
}
#undef func_002E51B8 /* merge_units */
/* merge_units: end func_002E56D0 */

/* merge_units: begin func_002E5770 */
typedef struct { unsigned char state; char name[0x11]; unsigned short port; int x14[2]; int x1C[2]; } E2E5770;
extern E2E5770 D_00520358[];
extern int String_CompareN(char *, char *, int);
extern void func_003060F0(int *, int *);
void func_002E5770(char *name, unsigned short port)
{
    unsigned int i;
    if (name == 0 || name[0] == 0) return;
    for (i = 0; i < 0x100; i++) {
        if (String_CompareN(name, D_00520358[i].name, 0x10) == 0 && D_00520358[i].state == 2 && port == D_00520358[i].port) {
            func_003060F0(D_00520358[i].x14, D_00520358[i].x1C);
            D_00520358[i].state = 3;
            return;
        }
    }
}
/* merge_units: end func_002E5770 */
