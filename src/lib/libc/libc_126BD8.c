/*
 * lib/libc: 3 files, 00126BD8-00126E38
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00126BD8 */
typedef struct _Bigint { struct _Bigint *_next; int _k, _maxwds, _sign, _wds; unsigned int _x[1]; } _Bigint;
extern int func_00126B70(_Bigint *, _Bigint *);
extern _Bigint *func_00126280(void *, int);
#define Sign_Extend(a,b) /*no-op*/
#define Storeinc(a,b,c) (((unsigned short *)a)[1] = (unsigned short)b, ((unsigned short *)a)[0] = (unsigned short)c, a++)
_Bigint *func_00126BD8(void *ptr, _Bigint *a, _Bigint *b)
{
    _Bigint *c;
    int i, wa, wb;
    int borrow, y;
    unsigned int *xa, *xae, *xb, *xbe, *xc;
    int z;

    i = func_00126B70(a, b);
    if (!i) {
        c = func_00126280(ptr, 0);
        c->_wds = 1;
        c->_x[0] = 0;
        return c;
    }
    if (i < 0) {
        c = a;
        a = b;
        b = c;
        i = 1;
    } else
        i = 0;
    c = func_00126280(ptr, a->_k);
    c->_sign = i;
    wa = a->_wds;
    xa = a->_x;
    xae = xa + wa;
    wb = b->_wds;
    xb = b->_x;
    xbe = xb + wb;
    xc = c->_x;
    borrow = 0;
    do {
        y = (*xa & 0xffff) - (*xb & 0xffff) + borrow;
        borrow = y >> 16;
        Sign_Extend(borrow, y);
        z = (*xa++ >> 16) - (*xb++ >> 16) + borrow;
        borrow = z >> 16;
        Sign_Extend(borrow, z);
        Storeinc(xc, z, y);
    } while (xb < xbe);
    while (xa < xae) {
        y = (*xa & 0xffff) + borrow;
        borrow = y >> 16;
        Sign_Extend(borrow, y);
        z = (*xa++ >> 16) + borrow;
        borrow = z >> 16;
        Sign_Extend(borrow, z);
        Storeinc(xc, z, y);
    }
    while (!*--xc)
        wa--;
    c->_wds = wa;
    return c;
}
/* merge_units: end func_00126BD8 */

/* merge_units: begin func_00126D68 */
union double_union { double d; unsigned int i[2]; };
#define word0(x) (x.i[1])
#define word1(x) (x.i[0])
double func_00126D68(double _x)
{
    int L;
    union double_union x, a;
    x.d = _x;
    L = (word0(x) & 0x7ff00000) - (53 - 1) * 0x100000;
    if (L > 0) {
        word0(a) = L;
        word1(a) = 0;
    } else {
        L = -L >> 20;
        if (L < 20) {
            word0(a) = 0x80000 >> L;
            word1(a) = 0;
        } else {
            word0(a) = 0;
            L -= 20;
            word1(a) = L >= 31 ? 1 : 1 << (31 - L);
        }
    }
    {
        /* asm label only (no instruction): stops delay-slot filling of the return move, as retail line notes did */
        register double r __asm__("$2") = a.d;
        __asm__ __volatile__("1:" : "+r"(r));
        return r;
    }
}
/* merge_units: end func_00126D68 */

/* merge_units: begin func_00126E38 */
typedef union { double d; unsigned int i[2]; } DU;
extern int func_00126590(unsigned int);
#define Ebits 11
#define Exp_1 0x3ff00000
double func_00126E38(_Bigint *a, int *e)
{
    unsigned int *xa, *xa0, w, y, z;
    int k;
    DU d;
#define d0 d.i[1]
#define d1 d.i[0]
    xa0 = a->_x;
    xa = xa0 + a->_wds;
    y = *--xa;
    k = func_00126590(y);
    *e = 32 - k;
    if (k < Ebits) {
        d0 = Exp_1 | y >> (Ebits - k);
        w = xa > xa0 ? *--xa : 0;
        d1 = y << (32 - Ebits + k) | w >> (Ebits - k);
        goto ret_d;
    }
    z = xa > xa0 ? *--xa : 0;
    if (k -= Ebits) {
        d0 = Exp_1 | y << k | z >> (32 - k);
        y = xa > xa0 ? *--xa : 0;
        d1 = z << k | y >> (32 - k);
    } else {
        d0 = Exp_1 | y;
        d1 = z;
    }
ret_d:
    return d.d;
}
/* merge_units: end func_00126E38 */
