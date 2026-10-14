/*
 * lib/medius: 2 files, 002E80D0-002E8228
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002E80D0 */
typedef struct { int v[256]; unsigned int cur; } Tab80D0;
typedef struct { unsigned char state, b1, active, slot, flag, ready; char pad[10]; int x10; int x14; char pad2[0x14]; char x2C[1]; } Ent80D0;
typedef struct { unsigned char id; } Src80D0;
typedef void (*Cb80D0)(int, unsigned int);
extern Cb80D0 D_00598398[];
extern int D_00590318[];
extern int D_0048C450;
extern int func_002DD9F8(unsigned int, Ent80D0 **);
extern int func_002E51B8(int, Tab80D0 **);
extern int func_002DDB30(unsigned int *, int);
extern int func_002DD328(void *);
extern int func_002F5348(void *);
int func_002E80D0(int a0, int a1, int a2, Src80D0 *src)
{
    Ent80D0 *p = 0;
    Tab80D0 *tab = 0;
    unsigned int n = 0x100;
    Cb80D0 cb;
    if (src == 0) return -1;
    if (func_002DD9F8(src->id, &p) == 0 && p != 0 && p->state == 2) {
        cb = D_00598398[p->slot];
        if (cb != 0) cb(a2, src->id);
        if (func_002E51B8(D_0048C450, &tab) == 0 && tab != 0) {
            func_002DDB30(&n, a0);
            if (tab->cur == n && p->ready != 0 && D_00590318[p->slot] != 0) {
                p->flag = 1;
            } else {
                p->state = 1;
                if (p->active != 0) {
                    func_002DD328(&p->x10);
                    func_002F5348(p->x2C);
                    p->x10 = 0;
                    p->x14 = 0;
                }
            }
        }
    }
    return 1;
}
/* merge_units: end func_002E80D0 */

/* merge_units: begin func_002E8228 */
#if 0 /* merge_units */
extern int func_002E51B8(unsigned int, char **);
#endif /* merge_units */
#define func_002E51B8(a0, a1) (func_002E51B8((int)(a0), (Tab80D0 * *)(a1))) /* merge_units */

extern int func_002E52D8(unsigned int, unsigned int, unsigned char **);
extern void func_002DCA70(unsigned int, unsigned int);
extern void func_002E8C50(unsigned int, unsigned int, unsigned int, unsigned int);
int func_002E8228(unsigned int port, int unused, unsigned int b, unsigned char *m)
{
    char *p = 0;
    unsigned char *q = 0;
    int ret = -1;
    unsigned int idx;
    if (m == 0) return ret;
    if (port >= 4) return ret;
    if (b >= 0x100) return ret;
    if (func_002E51B8(port, &p) != 0) return -1;
    if (p == 0) goto fail;
    if (func_002E52D8(port, m[1], &q) != 0) return -1;
    if (q == 0) {
fail:
        return -1;
    }
    if (q[0x28] != 1) return -1;
    *(int *)(q + 0x14) = m[0];
    idx = *(unsigned int *)(p + 0x400);
    if (idx >= 0x100) return ret;
    func_002DCA70(port, m[1]);
    if (*(int *)(*(char **)(p + (idx << 2)) + 0x14) == 5) func_002E8C50(port, m[1], m[2], m[3]);
    return 4;
}
#undef func_002E51B8 /* merge_units */
/* merge_units: end func_002E8228 */
