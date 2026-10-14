/*
 * lib/medius: 4 files, 002DD488-002DD8A8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002DD488 */
extern void *memset(void *, int, unsigned int);
extern char *strncpy(char *, const char *, unsigned int);
extern int D_0048C458;
extern char D_00588074[];
int func_002DD488(char *p)
{
    if (p == 0) return 0x17;
    memset(p, 0, 0x10);
    if (D_0048C458 == 0) return 0x11;
    strncpy(p, D_00588074, 0x10);
    return 0;
}
/* merge_units: end func_002DD488 */

/* merge_units: begin func_002DD4E8 */
extern int func_002E51B8(unsigned int, char **);
extern int func_002E52D8(unsigned int, unsigned int, unsigned char **);
int func_002DD4E8(char *dst, unsigned int a, unsigned int b)
{
    char *p = 0;
    unsigned char *q = 0;
    int r;
    if (dst == 0) return 0x17;
    memset(dst, 0, 0x10);
    if (b >= 0x100) return 0x17;
    if (a >= 4) return 0x17;
    r = func_002E51B8(a, &p);
    if (r) return r;
    if (p == 0) return 0xF;
    r = func_002E52D8(a, b, &q);
    if (r) return r;
    if (q == 0) return 8;
    if (q[0x28] == 0) return 8;
    strncpy(dst, (char *)q, 0x10);
    return 0;
}
/* merge_units: end func_002DD4E8 */

/* merge_units: begin func_002DD5B8 */
#define F(p,T,o) (*(T *)((char *)(p) + (o)))
typedef struct { unsigned char b0, b1; char x2[6]; char x8[0x40]; } M2DD5B8;
typedef struct { int slot; int id; int q; int x14; int zero; int x42C; } S2DD5B8;
extern int D_00598414;
#if 0 /* merge_units */
extern int func_002E51B8(unsigned int, void **);
#endif /* merge_units */
#define func_002E51B8(a0, a1) (func_002E51B8((a0), (char * *)(a1))) /* merge_units */

extern int func_002E5360(unsigned int, unsigned int, void **);
#if 0 /* merge_units */
extern int func_002E52D8(unsigned int, unsigned int, void **);
#endif /* merge_units */
#define func_002E52D8(a0, a1, a2) (func_002E52D8((a0), (a1), (unsigned char * *)(a2))) /* merge_units */

extern void func_002DCA70(unsigned int, int);
extern int func_00314CB0(unsigned int);
extern int func_003152E8(unsigned int, unsigned int);
extern unsigned char func_002E6090(unsigned int);
extern void func_002DD380(char *, void *);
extern int func_002F8908(int, char *);
extern void func_002DE880(int, unsigned int, int, int, int, M2DD5B8 *);
extern void func_002DDB30(int *, unsigned int);
extern void func_002E50C8(unsigned int, void **);
extern void func_003060D8(char *);
void func_002DD5B8(unsigned int slot, unsigned int id, char *name, unsigned short port)
{
    void *x7C;
    int x78 = 0x100;
    void *p = 0;
    void *q = 0;
    M2DD5B8 m;
    S2DD5B8 st;
    if (id >= 0x100) return;
    if (slot >= 4) return;
    if (func_002E51B8(slot, &p) != 0) return;
    if (p == 0) return;
    if (func_002E5360(slot, id, &q) != 0) return;
    if (q == 0) return;
    if (F(q, unsigned char, 0x28) == 1) {
        if (F(p, int, 0x44C) == 4) return;
        func_002DCA70(slot, id);
        return;
    }
    if (F(p, int, 0x440) != 0) F(p, int, 0x440)--;
    strncpy((char *)q, name, 0x10);
    F(q, unsigned short, 0x10) = port;
    F(q, unsigned char, 0x28) = 1;
    if (func_002E52D8(slot, F(p, int, 0x400), &q) != 0) return;
    if (q == 0) return;
    if (F(q, unsigned char, 0x28) != 0) {
        if (func_00314CB0(slot) == 1) {
            if (func_003152E8(slot, id) != 0) return;
        }
        if (F(p, int, 0x44C) == 4) {
            if (func_002E52D8(slot, id, &q) != 0) return;
            if (q == 0) return;
            F(q, int, 0x14) = 2;
            F(q, int, 0x18) = 0;
            F(q, int, 0x1C) = 0;
            F(q, int, 0x24) = 0;
            memset(&st, 0, 0x18);
            st.slot = slot;
            st.id = id;
            st.q = (int)q;
            st.x14 = (int)F(q, void *, 0x14);
            st.zero = 0;
            st.x42C = (int)F(p, void *, 0x42C);
            ((void (*)(S2DD5B8 *))F(p, int, 0x428))(&st);
            F(q, unsigned char, 0x2A) = 1;
        }
    }
    if (F(p, int, 0x438) != 1) return;
    if (F(p, int, 0x44C) == 4) return;
    m.b1 = func_002E6090(F(p, int, 0x400));
    if (func_002E52D8(slot, m.b1, &q) != 0) return;
    if (q == 0) return;
    func_002DD380(m.x2, q);
    m.b0 = slot;
    func_002F8908(0, m.x8);
    func_002DE880(0x50, slot, id, D_00598414, 0x48, &m);
    func_002DCA70(slot, id);
    func_002DDB30(&x78, slot);
    if (slot != 0) return;
    if (F(p, int, 0x400) != x78) return;
    x7C = 0;
    func_002E50C8(id, &x7C);
    if (x7C == 0) return;
    func_003060D8((char *)x7C + 0x198);
}
#undef func_002E51B8 /* merge_units */
#undef func_002E52D8 /* merge_units */
/* merge_units: end func_002DD5B8 */

/* merge_units: begin func_002DD8A8 */
#if 0 /* merge_units */
extern int func_002E52D8(unsigned int, unsigned int, char **);
#endif /* merge_units */
#define func_002E52D8(a0, a1, a2) (func_002E52D8((a0), (a1), (unsigned char * *)(a2))) /* merge_units */

void func_002DD8A8(unsigned int a, unsigned int b)
{
    char *p = 0;
    char *q = 0;
    if (a >= 4) return;
    if (b >= 0x100) return;
    if (func_002E51B8(a, &p)) return;
    if (p == 0) return;
    if (func_002E52D8(a, b, &q)) return;
    if (q) memset(q, 0, 0x2C);
}
#undef func_002E52D8 /* merge_units */
/* merge_units: end func_002DD8A8 */
