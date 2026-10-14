/*
 * lib/medius: 3 files, 002E85B8-002E8730
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002E85B8 */
extern unsigned int D_0048C450;
extern int func_002E51B8(unsigned int, char **);
extern int func_002E52D8(unsigned int, unsigned int, char **);
extern int func_002DDB30(int *, unsigned int);
extern int func_002DCA70(unsigned int, int);
int func_002E85B8(unsigned int a, int b, unsigned int c, int *out)
{
    char *p = 0;
    char *q = 0;
    int n = 0x100;
    if (out == 0) return -1;
    if (a >= 4) return 4;
    if (c >= 0x100) return 4;
    if (D_0048C450 >= 4) return 4;
    if (func_002E51B8(D_0048C450, &p)) return 4;
    if (p) {
        if (func_002E52D8(D_0048C450, *(unsigned int *)(p + 0x400), &q)) return 4;
        if (q) {
            if (func_002DDB30(&n, D_0048C450)) return 4;
            if (n != 0x100) {
                register char *qq asm("$2") = q;
                register int m1 asm("$5") = -1;
                /* scheduling barrier: keeps the q reload after the a1 setup (fills the beq delay slot) */
                __asm__ volatile("" ::: "memory");
                {unsigned int g = D_0048C450;
                *(int *)(qq+0x24) = *out;
                func_002DCA70(g,m1);}
            }
        }
    }
    return 4;
}
/* merge_units: end func_002E85B8 */

/* merge_units: begin func_002E86A8 */
extern int func_002E6098(unsigned int);
extern int func_002E6088(unsigned int);
extern void func_003154F0(unsigned int, unsigned char *);

int func_002E86A8(unsigned int port, int unused, unsigned int b, unsigned char *m)
{
    if (m == 0) return -1;
    if (func_002E6098(port) != 1) return -1;
    if (func_002E6088(b) != 1) return -1;
    func_003154F0(port, m);
    return 0x1C;
}
/* merge_units: end func_002E86A8 */

/* merge_units: begin func_002E8730 */
typedef struct {
    char pad0[0x14];
    int state;
    int f18;
    int f1C;
    int pad20;
    int f24;
    unsigned char active;
} Player;

typedef struct {
    Player *pl[256];
    unsigned int host;
    char pad404[0x3C];
    int f440;
} Tbl;

typedef struct {
    char pad0[6];
    short f6;
    char pad8[2];
    short fA;
} Rec;

typedef struct {
    int type;
    int data;
    int pad[2];
} Ev;

extern char D_0048C454;
extern int D_0048C478;
extern void (*D_0058DF88)(Ev *);
extern int D_0058DF90;

#if 0 /* merge_units */
extern int func_002E51B8(unsigned int a, Tbl **out);
#endif /* merge_units */
#define func_002E51B8(a0, a1) (func_002E51B8((a0), (char * *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern int func_002E52D8(unsigned int a, unsigned int b, Player **out);
#endif /* merge_units */
#define func_002E52D8(a0, a1, a2) (func_002E52D8((a0), (a1), (char * *)(a2))) /* merge_units */

extern int func_002DB188(Rec **out, unsigned int a, unsigned int b);
#if 0 /* merge_units */
extern void func_002DCA70(unsigned int a, int b);
#endif /* merge_units */
#define func_002DCA70(a0, a1) ((void)func_002DCA70((a0), (a1))) /* merge_units */

extern void func_002E5550(unsigned int a, unsigned int b);
extern void func_002DB688(unsigned int a, unsigned int b);
extern void func_002E1470(unsigned int a, int b);
extern void func_002E8C50(unsigned int a, unsigned int b, int c, int d);

void func_002E8730(unsigned int a)
{
    Ev ev;
    Tbl *tbl;
    Player *pl;
    Rec *rec;
    unsigned int host = 0x100;
    int cnt = 0;
    unsigned int i;

    tbl = 0;
    pl = 0;
    if (a >= 4) return;
    if (func_002E51B8(a, &tbl) != 0) return;
    if (tbl == 0) return;
    if (tbl->f440 != 0) return;
    if (D_0058DF90 != 1 && D_0058DF90 != 2) return;
    for (i = 0; i < 256; i++) {
        if (func_002E52D8(a, i, &pl) != 0) return;
        if (pl != 0 && pl->active == 1) {
            if (pl->state == 0 || pl->state == 5) return;
            if (pl->state == 3 && host == 0x100) host = i;
            if (pl->state == 4) cnt++;
        }
    }
    if (cnt != 0) return;
    if (host != tbl->host) return;
    func_002DB188(&rec, a, host);
    if (rec == 0) {
        tbl->pl[host]->state = 2;
        func_002DCA70(a, -1);
        if (D_0058DF88 != 0) {
            ev.type = 0x16;
            ev.data = D_0048C478;
            D_0058DF88(&ev);
            D_0058DF88 = 0;
            D_0048C478 = 0;
            return;
        }
    }
    tbl->pl[host]->state = 5;
    tbl->pl[host]->f24 = 1;
    func_002E5550(a, host);
    func_002DCA70(a, -1);
    rec->f6 = 0;
    rec->fA = 0;
    D_0048C454 = 1;
    func_002DB688(a, host);
    func_002E1470(a, 1);
    if (D_0058DF88 != 0) {
        ev.type = 0;
        ev.data = D_0048C478;
        D_0058DF88(&ev);
        D_0058DF88 = 0;
        D_0048C478 = 0;
    }
    for (i = 0; i < 256; i++) {
        if (func_002E52D8(a, i, &pl) == 0 && pl != 0 && pl->active == 1 && pl->state == 3 && host != i)
            func_002E8C50(a, i, pl->f18, pl->f1C);
    }
}
#undef func_002E51B8 /* merge_units */
#undef func_002E52D8 /* merge_units */
#undef func_002DCA70 /* merge_units */
/* merge_units: end func_002E8730 */
