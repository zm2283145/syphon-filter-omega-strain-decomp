/* emulates retail newlib's -g build: gas then skips delay-slot swapping */
__asm__(".set nomove");
typedef unsigned int __ULong;
typedef unsigned int __uint32_t;
typedef struct _Bigint {
    struct _Bigint *_next;
    int _k, _maxwds, _sign, _wds;
    __ULong _x[1];
} _Bigint;
struct _reent;
union double_union {
    double d;
    __uint32_t i[2];
};
#define word0(x) (x.i[1])
#define word1(x) (x.i[0])
#define Exp_shift 20
#define Exp_msk1 0x100000
#define Frac_mask 0xfffff
#define Bias 1023
#define P 53
extern _Bigint *Newlib_Balloc(struct _reent *ptr, int k);
extern int Newlib_Lo0bits(__ULong *y);
extern int Newlib_Hi0bits(__ULong x);
extern double Newlib_B2d(_Bigint *a, int *e);
extern double SoftFloat_DoubleDivide(double a, double b);

double Newlib_Ratio(_Bigint *a, _Bigint *b)
{
    union double_union da, db;
    int k, ka, kb;

    da.d = Newlib_B2d(a, &ka);
    db.d = Newlib_B2d(b, &kb);
    k = ka - kb + 32 * (a->_wds - b->_wds);
    if (k > 0)
        word0(da) += k * Exp_msk1;
    else {
        k = -k;
        word0(db) += k * Exp_msk1;
    }
    return SoftFloat_DoubleDivide(da.d, db.d);
}
