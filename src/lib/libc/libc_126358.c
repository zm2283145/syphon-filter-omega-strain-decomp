/* same-unit callee stub: weak, in a section the link discards (the real function is defined elsewhere); restores retail delay-slot choices */
typedef struct _Bigint { struct _Bigint *_next; int _k, _maxwds, _sign, _wds; unsigned int _x[1]; } _Bigint;
_Bigint * __attribute__((weak, section(".dtors_drop"))) Newlib_Balloc(void * a0, int a1) { return 0; }
extern void Newlib_Bfree(void *, _Bigint *);
extern void *memcpy(void *, const void *, unsigned int);
_Bigint *Newlib_Multadd(void *ptr, _Bigint *b, int m, int a)
{
    int i, wds;
    unsigned int *x, y;
    unsigned int xi, z;
    _Bigint *b1;
    wds = b->_wds;
    x = b->_x;
    i = 0;
    do {
        xi = *x;
        y = (xi & 0xffff) * m + a;
        z = (xi >> 16) * m + (y >> 16);
        a = (int)(z >> 16);
        *x++ = (z << 16) + (y & 0xffff);
    } while (++i < wds);
    if (a) {
        if (wds >= b->_maxwds) {
            b1 = Newlib_Balloc(ptr, b->_k + 1);
            memcpy(&b1->_sign, &b->_sign, b->_wds * sizeof(int) + 2 * sizeof(int));
            Newlib_Bfree(ptr, b);
            b = b1;
        }
        b->_x[wds++] = a;
        b->_wds = wds;
    }
    return b;
}
