typedef struct _Bigint { struct _Bigint *_next; int _k, _maxwds, _sign, _wds; unsigned int _x[1]; } _Bigint;
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