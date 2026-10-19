/*
 * lib/libc: 2 files, 001266D0-00126708
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001266D0 */
#include "types.h"

extern int Newlib_Balloc(int, int);

int Newlib_I2b(int a0, int a1) {
    int tmp0;

    tmp0 = Newlib_Balloc(a0, 1);
    *(int*)((char*)tmp0 + 20) = a1;
    *(int*)((char*)tmp0 + 16) = 1;
    return tmp0;
}
/* merge_units: end func_001266D0 */

/* merge_units: begin func_00126708 */
typedef unsigned int __ULong;
typedef int __Long;
typedef struct _Bigint {
    struct _Bigint *_next;
    int _k, _maxwds, _sign, _wds;
    __ULong _x[1];
} _Bigint;
struct _reent;
#if 0 /* merge_units */
extern _Bigint *Newlib_Balloc(struct _reent *ptr, int k);
#endif /* merge_units */
#define Newlib_Balloc(a0, a1) ((_Bigint *)Newlib_Balloc((int)(a0), (a1))) /* merge_units */

#define Storeinc(a,b,c) (((unsigned short *)a)[0] = (unsigned short)c, ((unsigned short *)a)[1] = (unsigned short)b, a++)

_Bigint *Newlib_Multiply(struct _reent *ptr, _Bigint *a, _Bigint *b)
{
    _Bigint *c;
    int k, wa, wb, wc;
    __ULong carry, y, z;
    __ULong *x, *xa, *xae, *xb, *xbe, *xc, *xc0;
    __ULong z2;

    if (a->_wds < b->_wds) {
        c = a;
        a = b;
        b = c;
    }
    k = a->_k;
    wa = a->_wds;
    wb = b->_wds;
    wc = wa + wb;
    if (wc > a->_maxwds)
        k++;
    c = Newlib_Balloc(ptr, k);
    for (x = c->_x, xa = x + wc; x < xa; x++)
        *x = 0;
    xa = a->_x;
    xae = xa + wa;
    xb = b->_x;
    xbe = xb + wb;
    xc0 = c->_x;
    for (; xb < xbe; xb++, xc0++) {
        if ((y = *xb & 0xffff) != 0) {
            x = xa;
            xc = xc0;
            carry = 0;
            do {
                z = (*x & 0xffff) * y + (*xc & 0xffff) + carry;
                carry = z >> 16;
                z2 = (*x++ >> 16) * y + (*xc >> 16) + carry;
                carry = z2 >> 16;
                Storeinc (xc, z2, z);
            } while (x < xae);
            *xc = carry;
        }
        if ((y = *xb >> 16) != 0) {
            x = xa;
            xc = xc0;
            carry = 0;
            z2 = *xc;
            do {
                z = (*x & 0xffff) * y + (*xc >> 16) + carry;
                carry = z >> 16;
                Storeinc (xc, z, z2);
                z2 = (*x++ >> 16) * y + (*xc & 0xffff) + carry;
                carry = z2 >> 16;
            } while (x < xae);
            *xc = z2;
        }
    }
    for (xc0 = c->_x, xc = xc0 + wc; wc > 0 && !*--xc; --wc);
    c->_wds = wc;
    return c;
}
#undef Newlib_Balloc /* merge_units */
/* merge_units: end func_00126708 */
