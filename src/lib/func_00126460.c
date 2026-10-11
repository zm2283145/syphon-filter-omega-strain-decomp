typedef struct _Bigint { struct _Bigint *_next; int _k, _maxwds, _sign, _wds; unsigned int _x[1]; } _Bigint;
extern _Bigint *func_00126280(void *, int);
extern _Bigint *func_00126358(void *, _Bigint *, int, int);
_Bigint *func_00126460(void *ptr, const char *s, int nd0, int nd, unsigned int y9)
{
    _Bigint *b;
    int i, k;
    int x, y;

    x = (nd + 8) / 9;
    for (k = 0, y = 1; x > y; y <<= 1, k++);
    b = func_00126280(ptr, k);
    b->_x[0] = y9;
    b->_wds = 1;

    i = 9;
    if (9 < nd0) {
        s += 9;
        do
            b = func_00126358(ptr, b, 10, *s++ - '0');
        while (++i < nd0);
        s++;
    } else
        s += 10;
    for (; i < nd; i++)
        b = func_00126358(ptr, b, 10, *s++ - '0');
    return b;
}