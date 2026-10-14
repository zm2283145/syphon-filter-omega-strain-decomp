typedef struct _Bigint { struct _Bigint *_next; int _k, _maxwds, _sign, _wds; unsigned int _x[1]; } _Bigint;
extern _Bigint *func_00126280(void *, int);
extern void func_00126328(void *, _Bigint *);
_Bigint *func_00126A18(void *ptr, _Bigint *b, int k)
{
    int i, k1, n, n1;
    _Bigint *b1;
    unsigned int *x, *x1, *xe, z;

    n = k >> 5;
    k1 = b->_k;
    n1 = n + b->_wds + 1;
    for (i = b->_maxwds; n1 > i; i <<= 1)
        k1++;
    b1 = func_00126280(ptr, k1);
    x1 = b1->_x;
    for (i = 0; i < n; i++)
        *x1++ = 0;
    x = b->_x;
    xe = x + b->_wds;
    if (k &= 0x1f) {
        k1 = 32 - k;
        z = 0;
        do {
            *x1++ = *x << k | z;
            z = *x++ >> k1;
        } while (x < xe);
        if ((*x1 = z) != 0)
            ++n1;
    } else
        do
            *x1++ = *x++;
        while (x < xe);
    b1->_wds = n1 - 1;
    func_00126328(ptr, b);
    return b1;
}