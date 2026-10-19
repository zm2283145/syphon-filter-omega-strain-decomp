/*
 * lib/libc: 3 files, 001261B0-00126280
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001261B0 */
int D_00489BA0 = -1;
int D_00489BA4 = 0;
extern int D_004868D0;
extern int func_0010D050(void);
extern void WaitSema(int);
void func_001261B0(void)
{
    int self = func_0010D050();
    if (D_00489BA0 == self) {
        D_00489BA4++;
        return;
    }
    WaitSema(D_004868D0);
    D_00489BA0 = self;
    D_00489BA4++;
}
/* merge_units: end func_001261B0 */

/* merge_units: begin func_00126230 */
extern int D_00489BA4;
extern int D_00489BA0;
extern void SignalSema(int);
void func_00126230(void)
{
    if (--D_00489BA4 == 0) {
        D_00489BA0 = -1;
        SignalSema(D_004868D0);
    }
}
/* merge_units: end func_00126230 */

/* merge_units: begin func_00126280 */
typedef struct B00126280 { struct B00126280 *_next; int _k, _maxwds, _sign, _wds; unsigned int _x[1]; } B00126280;
typedef struct { char p[0x4C]; B00126280 **_freelist; } R00126280;
extern void *Newlib_CallocR(R00126280 *, int, int);
B00126280 *func_00126280(R00126280 *ptr, int k)
{
    int x;
    B00126280 *rv;
    if (ptr->_freelist == 0) {
        ptr->_freelist = (B00126280 **)Newlib_CallocR(ptr, sizeof(B00126280 *), 16);
        if (ptr->_freelist == 0) return 0;
    }
    if ((rv = ptr->_freelist[k]) != 0) {
        ptr->_freelist[k] = rv->_next;
    } else {
        x = 1 << k;
        rv = (B00126280 *)Newlib_CallocR(ptr, 1, sizeof(B00126280) + (x - 1) * sizeof(int));
        if (rv == 0) return 0;
        rv->_k = k;
        rv->_maxwds = x;
    }
    rv->_sign = rv->_wds = 0;
    return rv;
}
/* merge_units: end func_00126280 */
