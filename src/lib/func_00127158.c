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
extern _Bigint *func_00126280(struct _reent *ptr, int k);
extern int func_00126610(__ULong *y);
extern int func_00126590(__ULong x);
extern double func_00126E38(_Bigint *a, int *e);
extern double func_0011C4F0(double a, double b);

double func_00127158(_Bigint *a, _Bigint *b)
{
    union double_union da, db;
    int k, ka, kb;

    da.d = func_00126E38(a, &ka);
    db.d = func_00126E38(b, &kb);
    k = ka - kb + 32 * (a->_wds - b->_wds);
    if (k > 0)
        word0(da) += k * Exp_msk1;
    else {
        k = -k;
        word0(db) += k * Exp_msk1;
    }
    return func_0011C4F0(da.d, db.d);
}
