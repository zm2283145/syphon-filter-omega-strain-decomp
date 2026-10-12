typedef union { float value; unsigned int value_raw; struct { unsigned int fraction:23; unsigned int exp:8; unsigned int sign:1; } bits; } FLO_0011BC28;
typedef struct { int class; unsigned int sign; int normal_exp; union { unsigned int ll; } fraction; } fpn_0011BC28;
static __inline__ int fp_iszero(fpn_0011BC28 *x) { return x->class == 2; }
/* fp-bit pack_f (no NaN/Inf/denormal variant) */
float func_0011BC28(fpn_0011BC28 *src)
{
    FLO_0011BC28 dst;
    unsigned int fraction = src->fraction.ll;
    int sign = src->sign;
    int exp = 0;
    if (fp_iszero(src)) {
        exp = 0;
        fraction = 0;
    } else if (fraction == 0) {
        exp = 0;
    } else {
        if (src->normal_exp < -126) {
            exp = 0;
            fraction = 0;
        } else {
            if (src->normal_exp > 128 || (src->normal_exp == 128 && fraction >= 0x80000000)) {
                exp = 255;
                fraction = 0;
            } else {
                exp = src->normal_exp + 127;
                fraction >>= 7;
            }
        }
    }
    dst.bits.fraction = fraction;
    dst.bits.exp = exp;
    dst.bits.sign = sign;
    return dst.value;
}
