typedef struct B00126280 { struct B00126280 *_next; int _k, _maxwds, _sign, _wds; unsigned int _x[1]; } B00126280;
typedef struct { char p[0x4C]; B00126280 **_freelist; } R00126280;
extern void *func_00121D68(R00126280 *, int, int);
B00126280 *func_00126280(R00126280 *ptr, int k)
{
    int x;
    B00126280 *rv;
    if (ptr->_freelist == 0) {
        ptr->_freelist = (B00126280 **)func_00121D68(ptr, sizeof(B00126280 *), 16);
        if (ptr->_freelist == 0) return 0;
    }
    if ((rv = ptr->_freelist[k]) != 0) {
        ptr->_freelist[k] = rv->_next;
    } else {
        x = 1 << k;
        rv = (B00126280 *)func_00121D68(ptr, 1, sizeof(B00126280) + (x - 1) * sizeof(int));
        if (rv == 0) return 0;
        rv->_k = k;
        rv->_maxwds = x;
    }
    rv->_sign = rv->_wds = 0;
    return rv;
}
