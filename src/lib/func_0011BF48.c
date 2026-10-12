typedef unsigned long fractype;
typedef unsigned int halffractype;
typedef double DFtype;
typedef enum { CLASS_SNAN, CLASS_QNAN, CLASS_ZERO, CLASS_NUMBER, CLASS_INFINITY } fp_class_type;
typedef struct {
    fp_class_type class;
    unsigned int sign;
    int normal_exp;
    union { fractype ll; halffractype l[2]; } fraction;
} fp_number_type;
typedef union {
    DFtype value;
    fractype value_raw;
    struct {
        fractype fraction:52 __attribute__((packed));
        unsigned int exp:11 __attribute__((packed));
        unsigned int sign:1 __attribute__((packed));
    } bits;
} FLO_union_type;
typedef long intfrac;
extern fp_number_type D_00499270;
#define fp_isnan(x) ((x)->class == CLASS_QNAN || (x)->class == CLASS_SNAN)
static __inline__ int fp_isinf(fp_number_type *x) { return x->class == CLASS_INFINITY; }
static __inline__ int fp_iszero(fp_number_type *x) { return x->class == CLASS_ZERO; }
#define LSHIFT(X) X = ((X) & 1) | ((X) >> 1)
fp_number_type *func_0011BF48(fp_number_type *a, fp_number_type *b, fp_number_type *tmp)
{
    intfrac tfraction;
    int a_normal_exp;
    int b_normal_exp;
    fractype a_fraction;
    fractype b_fraction;

    if (fp_isnan(a)) return a;
    if (fp_isnan(b)) return b;
    if (fp_isinf(a)) {
        if (fp_isinf(b) && a->sign != b->sign) return &D_00499270;
        return a;
    }
    if (fp_isinf(b)) return b;
    if (fp_iszero(b)) {
        if (fp_iszero(a)) {
            *tmp = *a;
            tmp->sign = a->sign & b->sign;
            return tmp;
        }
        return a;
    }
    if (fp_iszero(a)) return b;
    {
        int diff;
        a_normal_exp = a->normal_exp;
        b_normal_exp = b->normal_exp;
        a_fraction = a->fraction.ll;
        b_fraction = b->fraction.ll;
        diff = a_normal_exp - b_normal_exp;
        if (diff < 0) diff = -diff;
        if (diff < 64) {
            while (a_normal_exp > b_normal_exp) {
                b_normal_exp++;
                LSHIFT(b_fraction);
            }
            while (b_normal_exp > a_normal_exp) {
                a_normal_exp++;
                LSHIFT(a_fraction);
            }
        } else {
            if (a_normal_exp > b_normal_exp) {
                b_normal_exp = a_normal_exp;
                b_fraction = 0;
            } else {
                a_normal_exp = b_normal_exp;
                a_fraction = 0;
            }
        }
    }
    if (a->sign != b->sign) {
        if (a->sign) tfraction = -a_fraction + b_fraction;
        else tfraction = a_fraction - b_fraction;
        if (tfraction >= 0) {
            tmp->sign = 0;
            tmp->normal_exp = a_normal_exp;
            tmp->fraction.ll = tfraction;
        } else {
            tmp->sign = 1;
            tmp->normal_exp = a_normal_exp;
            tmp->fraction.ll = -tfraction;
        }
        while (tmp->fraction.ll < ((fractype)1 << 60) && tmp->fraction.ll) {
            tmp->fraction.ll <<= 1;
            tmp->normal_exp--;
        }
    } else {
        tmp->sign = a->sign;
        tmp->normal_exp = a_normal_exp;
        tmp->fraction.ll = a_fraction + b_fraction;
    }
    tmp->class = CLASS_NUMBER;
    if (tmp->fraction.ll >= ((fractype)1 << 61)) {
        LSHIFT(tmp->fraction.ll);
        tmp->normal_exp++;
    }
    return tmp;
}
