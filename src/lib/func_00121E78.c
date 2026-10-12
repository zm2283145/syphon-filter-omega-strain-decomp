typedef unsigned int __ULong;
typedef int __Long;
typedef struct _Bigint {
    struct _Bigint *_next;
    int _k, _maxwds, _sign, _wds;
    __ULong _x[1];
} _Bigint;
extern int func_00126B70(_Bigint *a, _Bigint *b);
#define Storeinc(a,b,c) (((unsigned short *)a)[0] = (unsigned short)c, ((unsigned short *)a)[1] = (unsigned short)b, a++)
#define Sign_Extend(a,b)

int func_00121E78(_Bigint *b, _Bigint *S)
{
    int n;
    __Long borrow, y;
    __ULong carry, q, ys;
    __ULong *bx, *bxe, *sx, *sxe;
    __Long z;
    __ULong si, zs;

    n = S->_wds;
    if (b->_wds < n)
        return 0;
    sx = S->_x;
    sxe = sx + --n;
    bx = b->_x;
    bxe = bx + n;
    q = *bxe / (*sxe + 1);
    if (q) {
        borrow = 0;
        carry = 0;
        do {
            si = *sx++;
            ys = (si & 0xffff) * q + carry;
            zs = (si >> 16) * q + (ys >> 16);
            carry = zs >> 16;
            y = (*bx & 0xffff) - (ys & 0xffff) + borrow;
            borrow = y >> 16;
            Sign_Extend (borrow, y);
            z = (*bx >> 16) - (zs & 0xffff) + borrow;
            borrow = z >> 16;
            Sign_Extend (borrow, z);
            Storeinc (bx, z, y);
        } while (sx <= sxe);
        if (!*bxe) {
            bx = b->_x;
            while (--bxe > bx && !*bxe)
                --n;
            b->_wds = n;
        }
    }
    if (func_00126B70 (b, S) >= 0) {
        q++;
        borrow = 0;
        carry = 0;
        bx = b->_x;
        sx = S->_x;
        do {
            si = *sx++;
            ys = (si & 0xffff) + carry;
            zs = (si >> 16) + (ys >> 16);
            carry = zs >> 16;
            y = (*bx & 0xffff) - (ys & 0xffff) + borrow;
            borrow = y >> 16;
            Sign_Extend (borrow, y);
            z = (*bx >> 16) - (zs & 0xffff) + borrow;
            borrow = z >> 16;
            Sign_Extend (borrow, z);
            Storeinc (bx, z, y);
        } while (sx <= sxe);
        bx = b->_x;
        bxe = bx + n;
        if (!*bxe) {
            while (--bxe > bx && !*bxe)
                --n;
            b->_wds = n;
        }
    }
    return q;
}
