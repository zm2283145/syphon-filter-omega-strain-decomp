/*
 * lib/medius: 3 files, 002E4A30-002E4CA8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002E4A30 */
typedef struct { char pad[0x400]; int f400; char p404[0x34]; int f438; char p43C[8]; int f444; } Obj2E4A30;
typedef struct { char pad[0x28]; unsigned char f28; } Ent2E4A30;
extern int D_0048C450;
extern unsigned char D_0048C454;
extern int D_0048C458;
extern unsigned int D_0048C45C;
extern int D_0048C498;
extern unsigned int D_0058806C;
extern void func_00306018(int *t);
extern int func_002E6010(void);
extern int func_002E47B0(int a);
extern int func_002E51B8(int a, Obj2E4A30 **out);
extern int func_002E52D8(int a, int i, Ent2E4A30 **out);
extern void func_002E1D50(int i);
extern void func_002E4550(void);
extern void func_002E4228(void);
extern int func_002E55A0(void);
extern int func_002E5860(int a);
extern int func_002E5D68(void);
extern int func_002E9200(void);
extern int func_002E5ED8(void);
int func_002E4A30(void)
{
    int t0;
    int t1;
    Obj2E4A30 *obj;
    Ent2E4A30 *ent;
    int i;
    if (!D_0048C458)
        return 0x11;
    func_00306018(&t0);
    { int e = func_002E6010(); if (e) return e; }
    { int e = func_002E47B0(1); if (e) return e; }
    func_00306018(&t1);
    D_0058806C += t1 - D_0048C498;
    D_0048C498 = t1;
    if (D_0048C450 < 4) {
        obj = 0;
        ent = 0;
        { int e = func_002E51B8(D_0048C450, &obj); if (e) return e; }
        if (!obj)
            return 0;
        if (D_0048C45C + 3000 < D_0058806C) {
            if (obj->f438 != 1)
                goto tail;
            if (obj->f400 < obj->f444) {
                for (i = 0; i < obj->f444; i++) {
                    { int e = func_002E52D8(D_0048C450, i, &ent); if (e) return e; }
                    if (ent && i != obj->f400 && ent->f28 == 1)
                        func_002E1D50(i);
                }
                D_0048C45C = D_0058806C;
            }
        }
        if (obj->f438 == 1 && obj->f400 < obj->f444 && D_0048C454 == 1) {
            func_002E4550();
            func_002E4228();
        }
    }
tail:
    { int e = func_002E55A0(); if (e) return e; }
    { int e = func_002E5860(1); if (e) return e; }
    { int e = func_002E5D68(); if (e) return e; }
    { int e = func_002E9200(); if (e) return e; }
    return func_002E5ED8();
}
/* merge_units: end func_002E4A30 */

/* merge_units: begin func_002E4C48 */
typedef struct { unsigned char b[24]; } B2E4C48;
extern B2E4C48 D_00520340;
int func_002E4C48(B2E4C48* p)
{
    if (p == 0) return 10;
    if (*(int*)p != 0x18) return 0x27;
    *p = D_00520340;
    return 0;
}
/* merge_units: end func_002E4C48 */

/* merge_units: begin func_002E4CA8 */
#define F(p,T,o) (*(T *)((char *)(p) + (o)))
typedef struct { unsigned int slot; int a, b, c; int d; } R2E4CA8;
extern void (*D_0048C470)(R2E4CA8 *);
extern int D_0048C474;
extern unsigned char D_0048C4AC;
extern int D_0048C4B0;
extern unsigned char D_0048C4B4;
extern char D_00522758[];
extern int D_0058D17C;
extern char D_0058DF80[];
extern void *memset(void *, int, unsigned int);
#if 0 /* merge_units */
extern int func_002E51B8(unsigned int, void **);
#endif /* merge_units */
#define func_002E51B8(a0, a1) (func_002E51B8((int)(a0), (Obj2E4A30 * *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern int func_002E52D8(unsigned int, unsigned int, void **);
#endif /* merge_units */
#define func_002E52D8(a0, a1, a2) (func_002E52D8((int)(a0), (int)(a1), (Ent2E4A30 * *)(a2))) /* merge_units */

extern int func_00314CB0(unsigned int);
/* callees return int (value ignored): keeps $v0 busy after each call, as in retail */
extern int func_00314A98(unsigned int);
extern int func_00303598(int);
extern int func_00303688(int);
extern int func_003060C0(void *);
extern int func_003060F0(void *, unsigned int *);
extern int func_002DCD00(unsigned int);
extern int func_002FBA98(int);
int func_002E4CA8(unsigned int slot)
{
    R2E4CA8 r;
    void *p = 0;
    unsigned int t;
    void *q = 0;
    unsigned int i;
    int ret;
    if (slot >= 4) return 0x17;
    ret = func_002E51B8(slot, &p);
    if (ret != 0) return ret;
    if (p != 0) {
        memset(&r, 0, sizeof r);
        r.slot = slot;
        r.d = D_0048C474;
        r.a = 0;
        r.b = 0;
        r.c = 0;
        if (func_00314CB0(slot) == 1) func_00314A98(slot);
        if (F(p, int, 0x438) - 1U < 3) {
            if (D_0048C4AC && slot == 0) {
                func_00303598(D_0048C4B0);
                if (D_0048C470 == 0) {
                    func_003060C0(D_00522758);
                    do {
                        func_00303688(D_0048C4B0);
                        func_003060F0(D_00522758, &t);
                    } while (t < 500);
                } else {
                    func_003060C0(D_00522758);
                    D_0048C4B4 = 1;
                }
            }
            if (slot != 0) {
                func_002FBA98(func_002DCD00(slot));
                if (D_0048C470) D_0048C470(&r);
            }
        }
        for (i = 0; i < 0x100; i++) {
            func_002E52D8(slot, i, &q);
            if (q) memset(q, 0, 0x2C);
        }
        {
            char *s = p;
            F(s, int, 0x400) = 0x100;
            F(s, int, 0x404) = 0x100;
            F(s, int, 0x428) = 0;
            F(s, int, 0x42C) = 0;
            F(s, int, 0x430) = 0;
            F(s, int, 0x434) = 0;
            F(s, int, 0x43C) = -1;
            F(s, int, 0x440) = 0;
            F(s, int, 0x438) = 0;
        }
        memset(D_0058DF80, 0, 4);
        D_0058D17C = 0;
        return 0;
    }
    return ret;
}
#undef func_002E51B8 /* merge_units */
#undef func_002E52D8 /* merge_units */
/* merge_units: end func_002E4CA8 */
