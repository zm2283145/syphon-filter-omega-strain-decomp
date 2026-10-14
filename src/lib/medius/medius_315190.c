/*
 * lib/medius: 10 files, 00315190-00315768
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00315190 */
extern int func_00315028(int a, int** out);
int func_00315190(int a, int* out)
{
    int* p;
    int r;
    if (out == 0)
        return 0x17;
    r = func_00315028(a, &p);
    if (r == 0)
        *out = p[0xA4 / 4];
    return r;
}
/* merge_units: end func_00315190 */

/* merge_units: begin func_003151D8 */
typedef struct { int a; int b; } Ent51D8;
typedef struct { char pad[4]; int count; char pad2[0x204 - 8]; Ent51D8 *tbl; } Obj51D8;
extern int func_00314FE0(Obj51D8 *o);
int func_003151D8(Obj51D8 *o, int i, Ent51D8 **out)
{
    if (out == 0) return 0x17;
    if (func_00314FE0(o) != 1) return 0x17;
    if (o->tbl == 0) return 0x17;
    if (i >= o->count) return 0x17;
    *out = &o->tbl[i];
    return *out ? 0 : 0x29;
}
/* merge_units: end func_003151D8 */

/* merge_units: begin func_00315260 */
typedef struct { int addrB; int addrA; int portB; int portA; } Src5260;
typedef enum { T0, T1, T2 } Ty5260;
typedef struct { Ty5260 typeA; char addrA[0x10]; int portA; Ty5260 typeB; char addrB[0x10]; int portB; } Dst5260;
extern void *memset(void *d, int c, unsigned int n);
extern void func_002F4E20(int a, char *dst);
int func_00315260(Src5260 *s, Dst5260 *d)
{
    if (s == 0) return 0x17;
    if (d == 0) return 0x17;
    memset(d, 0, 0x30);
    d->typeA = 2;
    d->portA = s->portA;
    func_002F4E20(s->addrA, d->addrA);
    d->typeB = 1;
    d->portB = s->portB;
    func_002F4E20(s->addrB, d->addrB);
    return 0;
}
/* merge_units: end func_00315260 */

/* merge_units: begin func_003152E8 */
typedef struct { char pad[4]; unsigned char b4; unsigned char b5; unsigned char b6; } Ent52E8;
typedef struct {
    char pad[0xA];
    unsigned char mode;
    char pad1[0xA4 - 0xB];
    int sock;
    unsigned char bA8;
    unsigned char bA9;
    char pad2[2];
    char info[0x14];
} Obj52E8;
extern short D_00491432;
extern unsigned char D_00491430;
extern int func_002E6088(int h);
#if 0 /* merge_units */
extern int func_00315028(int id, Obj52E8 **out);
#endif /* merge_units */
#define func_00315028(a0, a1) (func_00315028((a0), (int * *)(a1))) /* merge_units */

extern int func_002F4F90(int sock, int *out);
extern int func_002F4FB0(int sock, int sz, char *info);
#if 0 /* merge_units */
extern int func_003151D8(Obj52E8 *o, int i, Ent52E8 **out);
#endif /* merge_units */
#define func_003151D8(a0, a1, a2) (func_003151D8((Obj51D8 *)(a0), (a1), (Ent51D8 * *)(a2))) /* merge_units */

extern int func_00315818(Obj52E8 *o, Ent52E8 *e);
extern int func_00315E28(int r, int code);
int func_003152E8(int id, int sz)
{
    Obj52E8 *o;
    int x;
    Ent52E8 *e;
    int ok, st, m, r;
    if (D_00491432 <= 0) return 0x11;
    ok = D_00491430;
    if (ok != 1) return 0x11;
    st = func_002E6088(sz);
    if (st != ok) return 0x17;
    r = func_00315028(id, &o);
    if (r != 0) return r;
    m = o->mode;
    if (m != st) return 0x29;
    r = func_00315E28(func_002F4F90(o->sock, &x), 0x2A);
    if (r != 0) return r;
    r = func_00315E28(func_002F4FB0(o->sock, x, o->info), 0x2A);
    if (r != 0) return r;
    r = func_003151D8(o, sz, &e);
    if (r != 0) return r;
    e->b4 = m;
    if (o->bA9 == m) {
        r = func_00315818(o, e);
        if (r != 0) return r;
    }
    return 0;
}
#undef func_00315028 /* merge_units */
#undef func_003151D8 /* merge_units */
/* merge_units: end func_003152E8 */

/* merge_units: begin func_00315410 */
typedef struct { char pad[4]; unsigned char b4; unsigned char b5; unsigned char b6; } Ent5410;
typedef struct { char pad[0xA4]; int sock; } Obj5410;
#if 0 /* merge_units */
extern int func_00315028(int id, Obj5410 **out);
#endif /* merge_units */
#define func_00315028(a0, a1) (func_00315028((a0), (int * *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern int func_003151D8(Obj5410 *o, int i, Ent5410 **out);
#endif /* merge_units */
#define func_003151D8(a0, a1, a2) (func_003151D8((Obj51D8 *)(a0), (a1), (Ent51D8 * *)(a2))) /* merge_units */

extern void func_002F4FF0(int sock, int sz);
int func_00315410(int id, int sz)
{
    Obj5410 *o;
    Ent5410 *e;
    int ok, st, r;
    if (D_00491432 <= 0) return 0x11;
    ok = D_00491430;
    if (ok != 1) return 0x11;
    st = func_002E6088(sz);
    if (st != ok) return 0x17;
    r = func_00315028(id, &o);
    if (r != 0) return r;
    r = func_003151D8(o, sz, &e);
    if (r != 0) return r;
    if (e->b5 == st) {
        func_002F4FF0(o->sock, sz);
        e->b5 = 0;
    }
    e->b4 = 0;
    e->b6 = 0;
    return 0;
}
#undef func_00315028 /* merge_units */
#undef func_003151D8 /* merge_units */
/* merge_units: end func_00315410 */

/* merge_units: begin func_003154F0 */
typedef struct { int a; int b; int c; int d; int e; int f; int g; int h; } Src54F0;
typedef struct { char b[0x30]; } Dst54F0;
typedef struct { int pad; int sz; int a; int b; int c; int d; int e; } Req54F0;
typedef struct { char pad[4]; unsigned char b4; unsigned char b5; } Ent54F0;
typedef struct { char pad[0xA4]; int sock; } Obj54F0;
#if 0 /* merge_units */
extern int func_00315028(int id, Obj54F0 **out);
#endif /* merge_units */
#define func_00315028(a0, a1) (func_00315028((a0), (int * *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern int func_003151D8(Obj54F0 *o, int i, Ent54F0 **out);
#endif /* merge_units */
#define func_003151D8(a0, a1, a2) (func_003151D8((Obj51D8 *)(a0), (a1), (Ent51D8 * *)(a2))) /* merge_units */

#if 0 /* merge_units */
extern int func_00315260(Src54F0 *s, Dst54F0 *d);
#endif /* merge_units */
#define func_00315260(a0, a1) (func_00315260((Src5260 *)(a0), (Dst5260 *)(a1))) /* merge_units */

extern int func_002F4FC8(int sock, Src54F0 *s);
int func_003154F0(int id, Req54F0 *q)
{
    Src54F0 s;
    Dst54F0 d;
    Obj54F0 *o;
    Ent54F0 *e;
    int ok, st, r;
    if (D_00491432 <= 0) return 0x11;
    ok = D_00491430;
    if (ok != 1) return 0x11;
    if (q == 0) return 0x17;
    r = func_00315028(id, &o);
    if (r != 0) return r;
    st = func_002E6088(q->sz);
    if (st != ok) return 0x29;
    r = func_003151D8(o, q->sz, &e);
    if (r != 0) return r;
    memset(&s, 0, 0x20);
    s.b = q->a;
    s.d = q->b;
    s.a = q->c;
    s.c = q->d;
    s.e = q->e;
    s.f = q->sz;
    s.g = 0;
    r = func_00315260(&s, &d);
    if (r != 0) return r;
    r = func_00315E28(func_002F4FC8(o->sock, &s), 0x2A);
    if (r != 0) return r;
    e->b5 = st;
    return r;
}
#undef func_00315028 /* merge_units */
#undef func_003151D8 /* merge_units */
#undef func_00315260 /* merge_units */
/* merge_units: end func_003154F0 */

/* merge_units: begin func_00315608 */
int func_00315608(int code, int *out)
{
    if (out == 0) return 0x17;
    switch (code) {
    case 0: *out = 0x21; break;
    case 1: *out = 0x3F; break;
    case 2: *out = 0x22; break;
    case 3: *out = 0x24; break;
    case 4: *out = 0x23; break;
    default: return 0x17;
    }
    return 0;
}
/* merge_units: end func_00315608 */

/* merge_units: begin func_003156A0 */
int func_003156A0(int code, int *out)
{
    if (out == 0) return 0x17;
    switch (code) {
    case 0x21: *out = 0; break;
    case 0x3F: *out = 1; break;
    case 0x22: *out = 2; break;
    case 0x24: *out = 3; break;
    case 0x23: *out = 4; break;
    default: return 0x17;
    }
    return 0;
}
/* merge_units: end func_003156A0 */

/* merge_units: begin func_00315730 */
int func_00315730(int a, int* out)
{
    if (out == 0)
        return 0x17;
    switch (a) {
    case 0: *out = 3; break;
    case 1: *out = 0; break;
    default: return 0x17;
    }
    return 0;
}
/* merge_units: end func_00315730 */

/* merge_units: begin func_00315768 */
typedef struct {
    char pad0[0x18];
    unsigned int count;
    char pad1[0xFC - 0x1C];
    int ids[1];
} Obj5768;
#if 0 /* merge_units */
extern int func_00314FE0(Obj5768 *o);
#endif /* merge_units */
#define func_00314FE0(a0) (func_00314FE0((Obj51D8 *)(a0))) /* merge_units */

int func_00315768(Obj5768 *o, int id, unsigned int *out)
{
    unsigned int i;
    if (func_00314FE0(o) != 1) return 0x17;
    if (out == 0) return 0x17;
    for (i = 0; i < o->count; i++) {
        if (id == o->ids[i]) {
            *out = i;
            return 0;
        }
    }
    return 0x29;
}
#undef func_00314FE0 /* merge_units */
/* merge_units: end func_00315768 */
